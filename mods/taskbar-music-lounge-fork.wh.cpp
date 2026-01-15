// ==WindhawkMod==
// @id              taskbar-music-lounge-fork
// @name            Taskbar Music Lounge - Fork
// @description     A native-style music ticker with media controls.
// @version         4.6.3
// @author          Hashah2311 | Cinabutts
// @github          https://github.com/Hashah2311
// @include         explorer.exe
// @compilerOptions -lole32 -ldwmapi -lgdi32 -luser32 -lwindowsapp -lshcore -lgdiplus -lshell32 -lpsapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Music Lounge (v4.6.3)

A media controller that uses Windows 11 native DWM styling for a seamless look.

## ✨ Features
* **Universal Support:** Works with any media player via GSMTC.
* **Album Art:** Displays current track cover art.
* **Native Look:** Uses Windows 11 hardware-accelerated rounding and acrylic blur.
* **Controls:** Play/Pause, Next, Previous.
* **Volume:** Scroll over widget to adjust volume.
* **--------------------------------- Cinabutts Enhancements: ---------------------------------**
* **True High-DPI Support:** Automatically scales UI elements to look perfect on 4K/1440p monitors.
* **Smart Game Detection:** Automatically hides when playing Fullscreen games.
* **Whitelist:** Keep the widget visible in specific Fullscreen apps (e.g., Firefox).
* **Slide Animations:** Smoothly slides out AND back in when entering/exiting games.
* **Smart Docking:** Sits unobtrusively at the screen edge on boot/shutdown or if Explorer crashes.
* **Advanced Background Control:** Manually override Background RGB - Toggle Auto/Invert themes, etc.
* **Click to switch:** Clicking the empty space or track text switches focus to the current music source application.

## ⚠️ Requirements
* **Disable Widgets:** Taskbar Settings -> Widgets -> Off.
* **Windows 11:** Required for rounded corners.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- PanelWidth: 300
  $name: Panel Width
- PanelHeight: 35
  $name: Panel Height
- FontSize: 11
  $name: Font Size
- OffsetX: 140
  $name: X Offset
- OffsetY: 0
  $name: Y Offset
- AutoTheme: true
  $name: Auto Theme
  $description: ✓ Enabled | B/W  Text & Icons based on System Light/Dark mode. ✕ Disabled | Use Custom theme below ↓
- InvertTheme: false
  $name: Invert System Light/Dark (Background)
  $description: ✓ Enabled | Dark Background. ✕ Disabled | Light Background. (Auto Theme must be OFF)
- BgColor: "0, 0, 0"
  $name: Manual Background Color Override (R, G, B)
  $description: Set to 0,0,0 to not override. Enter RGB values separated by commas (e.g; "102, 255, 255"). Alpha controlled below ↓
- BgOpacity: 0
  $name: Acrylic Tint Opacity (0-255).
  $description: Keep 0 for pure glass. Controls Alpha for Manual Background Color.
- TextColor: "255, 255, 255"
  $name: Manual Text Color (R, G, B, [A])
  $description: Enter RGB or RGBA values separated by commas (e.g; "102, 255, 255" or "255, 0, 0, 128")
- IdleTimeout: 0
  $name: Auto-hide when paused (Seconds). Set 0 to disable.
  $description: Automatically hide the widget when music is paused for the specified number of seconds.
- EnableSlide: true
  $name: Enable Slide Animations
  $description: ✓ Enabled | the widget slides down/up for games. ✕ Disabled | Instantly hides.
- EnableGameDetection: true
  $name: Enable Game Detection
  $description: ✓ Enabled | Widget hides on game detection. ✕ Disabled | The widget will NEVER hide for games. (overrides all below ↓)
- EnableAppSwitch: true
  $name: Click Background to Open App
  $description: Clicking the empty space/text switches to the music source app.
- FullscreenCheckInterval: 2
  $name: Fullscreen Check Interval (Seconds)
  $description: How often to check for borderless games.
- IgnoredApps: firefox.exe;chrome.exe;msedge.exe;vlc.exe
  $name: Fullscreen Whitelist
  $description: Semicolon-separated list of executables to IGNORE (keep widget visible).
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <shellapi.h>
#include <dwmapi.h>
#include <gdiplus.h>
#include <shcore.h> 
#include <string>
#include <thread>
#include <mutex>
#include <cstdio>
#include <psapi.h>
#include <shobjidl.h>

// WinRT
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>

using namespace Gdiplus;
using namespace std;
using namespace winrt;
using namespace Windows::Media::Control;
using namespace Windows::Storage::Streams;

// --- Constants ---
const WCHAR* FONT_NAME = L"Segoe UI Variable Display"; 

// --- DWM API ---
typedef enum _WINDOWCOMPOSITIONATTRIB { WCA_ACCENT_POLICY = 19 } WINDOWCOMPOSITIONATTRIB;
typedef enum _ACCENT_STATE {
    ACCENT_DISABLED = 0,
    ACCENT_ENABLE_BLURBEHIND = 3,
    ACCENT_ENABLE_ACRYLICBLURBEHIND = 4, 
    ACCENT_INVALID_STATE = 5
} ACCENT_STATE;
typedef struct _ACCENT_POLICY {
    ACCENT_STATE AccentState;
    DWORD AccentFlags;
    DWORD GradientColor;
    DWORD AnimationId;
} ACCENT_POLICY;
typedef struct _WINDOWCOMPOSITIONATTRIBDATA {
    WINDOWCOMPOSITIONATTRIB Attribute;
    PVOID Data;
    SIZE_T SizeOfData;
} WINDOWCOMPOSITIONATTRIBDATA;
typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINDOWCOMPOSITIONATTRIBDATA*);

// --- Z-Band API ---
typedef HWND(WINAPI* pCreateWindowInBand)(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID, DWORD);
enum ZBID { ZBID_IMMERSIVE_NOTIFICATION = 4 };

// --- Configurable State ---
struct ModSettings {
    int width = 300;
    int height = 35;
    int fontSize = 11;
    int offsetX = 140;
    int offsetY = 0;
    bool autoTheme = true;
    bool invertTheme = false;
    DWORD manualTextColor = 0xFFFFFFFF; 
    DWORD manualBgColorRGB = 0; // Stores BGR for DWM
    int bgOpacity = 0;
    int fsInterval = 2;
    int idleTimeout = 0;
    bool enableSlide = true;
    bool enableGameDetect = true;
    bool enableAppSwitch = true;
    wstring ignoredApps;
} g_Settings;

// --- Global State ---
HWND g_hMediaWindow = NULL;
HWND g_hTaskbar = NULL;
HWINEVENTHOOK g_hVisibilityHook = NULL;
bool g_Running = true; 
int g_HoverState = 0; 
float g_ScaleFactor = 1.0f; // DPI Scale

// Detection & Animation State
bool g_IsGameDetected = false;
int g_FsCheckTick = 0;
int g_AnimState = 0; // 0=Sync, 1=Hiding, 2=Showing, 3=Shutdown/Parked
int g_CurrentAnimY = 0;
bool g_ShutdownMode = false;
int g_IdleSecondsCounter = 0;
bool g_IsHiddenByIdle = false;

struct MediaState {
    wstring title = L"Waiting for media...";
    wstring artist = L"";
    bool isPlaying = false;
    bool hasMedia = false;
    Bitmap* albumArt = nullptr;
    wstring sourceId = L"";
    mutex lock;
} g_MediaState;

int g_ScrollOffset = 0;
int g_TextWidth = 0;
bool g_IsScrolling = false;
int g_ScrollWait = 60;

// --- Helper: Whitelist Check ---
bool IsAppIgnored(HWND hFg) {
    if (!hFg) return false;
    DWORD pid = 0;
    GetWindowThreadProcessId(hFg, &pid);
    if (pid == 0) return false;

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!hProcess) return false;

    WCHAR buffer[MAX_PATH];
    bool match = false;
    if (GetModuleFileNameExW(hProcess, NULL, buffer, MAX_PATH)) {
        wstring fullPath = buffer;
        size_t lastSlash = fullPath.find_last_of(L"\\");
        wstring exeName = (lastSlash == wstring::npos) ? fullPath : fullPath.substr(lastSlash + 1);
        
        for (auto & c: exeName) c = tolower(c);
        wstring list = g_Settings.ignoredApps;
        for (auto & c: list) c = tolower(c);
        
        if (list.find(exeName) != wstring::npos) match = true;
    }
    CloseHandle(hProcess);
    return match;
}

// --- Sync Logic ---

bool CheckBorderlessFullscreen() {
    HWND hFg = GetForegroundWindow();
    if (!hFg || hFg == GetDesktopWindow() || hFg == GetShellWindow()) return false;
    if (IsAppIgnored(hFg)) return false;

    WCHAR clsName[256];
    GetClassNameW(hFg, clsName, 256);
    if (wcscmp(clsName, L"WorkerW") == 0 || wcscmp(clsName, L"Progman") == 0) return false;

    HMONITOR hMon = MonitorFromWindow(hFg, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO mi = { sizeof(mi) };
    if (!GetMonitorInfo(hMon, &mi)) return false;

    RECT rcWin;
    GetWindowRect(hFg, &rcWin);

    return (rcWin.left <= mi.rcMonitor.left && 
            rcWin.top <= mi.rcMonitor.top && 
            rcWin.right >= mi.rcMonitor.right && 
            rcWin.bottom >= mi.rcMonitor.bottom);
}

#define IDT_VIS_ANIM 1003

void UpdateScaleFactor() {
    if (g_hTaskbar) {
        UINT dpi = GetDpiForWindow(g_hTaskbar);
        if (dpi == 0) dpi = 96;
        g_ScaleFactor = dpi / 96.0f;
    }
}

void ForceParkedState() {
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    SetWindowPos(g_hMediaWindow, HWND_TOPMOST, 0, screenH - 2, g_Settings.width, g_Settings.height, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_AnimState = 3; // Parked Mode
}

void SyncPositionWithTaskbar() {
    if (!g_hMediaWindow || g_ShutdownMode) return;
    
    // 1. Startup / Crash Recovery
    if (!g_hTaskbar || !IsWindow(g_hTaskbar)) {
        g_hTaskbar = FindWindowW(L"Shell_TrayWnd", NULL);
        if (!g_hTaskbar) {
            if (g_AnimState != 3) ForceParkedState();
            return;
        }
    }

    if (g_hTaskbar) {
        UpdateScaleFactor(); 

        // --- 2. Smart Fullscreen Detection ---
        bool shouldHide = false;
        
        if (g_Settings.enableGameDetect) {
            if (IsAppIgnored(GetForegroundWindow())) {
                shouldHide = false;
                g_FsCheckTick = 0;
            } else {
                QUERY_USER_NOTIFICATION_STATE qState;
                if (SHQueryUserNotificationState(&qState) == S_OK) {
                    if (qState == QUNS_RUNNING_D3D_FULL_SCREEN || 
                        qState == QUNS_PRESENTATION_MODE) {
                        shouldHide = true;
                        g_FsCheckTick = 0;
                    }
                }
                if (!shouldHide) {
                    g_FsCheckTick++;
                    if (g_FsCheckTick >= g_Settings.fsInterval) {
                        g_FsCheckTick = 0;
                        if (CheckBorderlessFullscreen()) shouldHide = true;
                    } else {
                        if (g_IsGameDetected) shouldHide = true;
                    }
                }
            }
        }

        g_IsGameDetected = shouldHide;

        // --- 3. Animation Logic ---
        if (g_AnimState == 1 || g_AnimState == 2) return; 

        BOOL isTaskbarVisible = IsWindowVisible(g_hTaskbar);
        
        // CASE: Hide
        if (!isTaskbarVisible || g_IsGameDetected || g_IsHiddenByIdle) {
            if (g_AnimState != 1 && g_AnimState != 3) {
                if (g_Settings.enableSlide) {
                    RECT rcMe; GetWindowRect(g_hMediaWindow, &rcMe);
                    g_CurrentAnimY = rcMe.top;
                    g_AnimState = 1; // Hiding
                    SetTimer(g_hMediaWindow, IDT_VIS_ANIM, 16, NULL);
                } else {
                    ShowWindow(g_hMediaWindow, SW_HIDE);
                }
            }
            return;
        }

        // CASE: Restore
        if (g_AnimState == 3 || !IsWindowVisible(g_hMediaWindow)) {
            if (g_Settings.enableSlide) {
                 int screenH = GetSystemMetrics(SM_CYSCREEN);
                 g_CurrentAnimY = (g_AnimState == 3) ? (screenH - 2) : screenH; 
                 
                 RECT rcTb; GetWindowRect(g_hTaskbar, &rcTb);
                 int scaledOffX = (int)(g_Settings.offsetX * g_ScaleFactor);
                 int scaledW = (int)(g_Settings.width * g_ScaleFactor);
                 int scaledH = (int)(g_Settings.height * g_ScaleFactor);
                 int targetX = rcTb.left + scaledOffX;

                 SetWindowPos(g_hMediaWindow, HWND_TOPMOST, targetX, g_CurrentAnimY, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
                 g_AnimState = 2; // Showing
                 SetTimer(g_hMediaWindow, IDT_VIS_ANIM, 16, NULL);
                 return;
            } else {
                ShowWindow(g_hMediaWindow, SW_SHOWNOACTIVATE);
            }
        }

        // Normal Sync
        RECT rc;
        if (GetWindowRect(g_hTaskbar, &rc)) {
            int taskbarHeight = rc.bottom - rc.top;
            if (taskbarHeight <= 0) return; 

            int scaledW = (int)(g_Settings.width * g_ScaleFactor);
            int scaledH = (int)(g_Settings.height * g_ScaleFactor);
            int scaledOffX = (int)(g_Settings.offsetX * g_ScaleFactor);
            int scaledOffY = (int)(g_Settings.offsetY * g_ScaleFactor);

            int x = rc.left + scaledOffX; 
            int y = rc.top + (taskbarHeight / 2) - (scaledH / 2) + scaledOffY;

            SetWindowPos(g_hMediaWindow, HWND_TOPMOST, x, y, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
            g_AnimState = 0; // Synced
        }
    }
}

void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime) {
    if (hwnd == g_hTaskbar && idObject == OBJID_WINDOW) {
        SyncPositionWithTaskbar();
    }
}

// --- Settings ---
void LoadSettings() {
    g_Settings.width = Wh_GetIntSetting(L"PanelWidth");
    g_Settings.height = Wh_GetIntSetting(L"PanelHeight");
    g_Settings.fontSize = Wh_GetIntSetting(L"FontSize");
    g_Settings.offsetX = Wh_GetIntSetting(L"OffsetX");
    g_Settings.offsetY = Wh_GetIntSetting(L"OffsetY");
    g_Settings.autoTheme = Wh_GetIntSetting(L"AutoTheme") != 0;
    g_Settings.invertTheme = Wh_GetIntSetting(L"InvertTheme") != 0;
    g_Settings.bgOpacity = Wh_GetIntSetting(L"BgOpacity");

    // Text Color (RGB/RGBA) -> GDI uses ARGB
    PCWSTR textColorStr = Wh_GetStringSetting(L"TextColor");
    if (textColorStr) {
        int r = 255, g = 255, b = 255, a = 255;
        int count = swscanf_s(textColorStr, L"%d,%d,%d,%d", &r, &g, &b, &a);
        if(r>255) r=255; if(g>255) g=255; if(b>255) b=255; if(a>255) a=255;
        if(r<0) r=0; if(g<0) g=0; if(b<0) b=0; if(a<0) a=0;
        
        if (count >= 3) {
            g_Settings.manualTextColor = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b;
        } else {
            g_Settings.manualTextColor = 0xFFFFFFFF;
        }
        Wh_FreeStringSetting(textColorStr);
    } else {
        g_Settings.manualTextColor = 0xFFFFFFFF;
    }

    // Bg Color (RGB Only) -> DWM uses ABGR (Swap R/B)
    PCWSTR bgColorStr = Wh_GetStringSetting(L"BgColor");
    if (bgColorStr) {
        int r = 0, g = 0, b = 0, a = 0;
        int count = swscanf_s(bgColorStr, L"%d,%d,%d,%d", &r, &g, &b, &a);
        
        if(r>255) r=255; if(g>255) g=255; if(b>255) b=255;
        if(r<0) r=0; if(g<0) g=0; if(b<0) b=0;

        if (count >= 3 && !(r==0 && g==0 && b==0)) {
            // FIX: SWAP RED AND BLUE for DWM API
            // BGR Format: 0x00BBGGRR
            g_Settings.manualBgColorRGB = ((DWORD)b << 16) | ((DWORD)g << 8) | (DWORD)r;
        } else {
            g_Settings.manualBgColorRGB = 0; 
        }
        Wh_FreeStringSetting(bgColorStr);
    } else {
        g_Settings.manualBgColorRGB = 0;
    }
    
    g_Settings.fsInterval = Wh_GetIntSetting(L"FullscreenCheckInterval");
    if (g_Settings.fsInterval < 1) g_Settings.fsInterval = 1;

    g_Settings.idleTimeout = Wh_GetIntSetting(L"IdleTimeout");
    if (g_Settings.idleTimeout < 0) g_Settings.idleTimeout = 0;

    // reset idle counters on settings load
    g_IdleSecondsCounter = 0;
    g_IsHiddenByIdle = false;

    g_Settings.enableSlide = Wh_GetIntSetting(L"EnableSlide") != 0;
    g_Settings.enableGameDetect = Wh_GetIntSetting(L"EnableGameDetection") != 0;
    g_Settings.enableAppSwitch = Wh_GetIntSetting(L"EnableAppSwitch") != 0;

    PCWSTR apps = Wh_GetStringSetting(L"IgnoredApps");
    if (apps) {
        g_Settings.ignoredApps = apps;
        Wh_FreeStringSetting(apps);
    } else {
        g_Settings.ignoredApps = L"firefox.exe;chrome.exe;msedge.exe";
    }

    if (g_Settings.bgOpacity < 0) g_Settings.bgOpacity = 0;
    if (g_Settings.bgOpacity > 255) g_Settings.bgOpacity = 255;
    if (g_Settings.width < 100) g_Settings.width = 300;
    if (g_Settings.height < 24) g_Settings.height = 48;
}

// --- WinRT / GSMTC ---
GlobalSystemMediaTransportControlsSessionManager g_SessionManager = nullptr;

Bitmap* StreamToBitmap(IRandomAccessStreamWithContentType const& stream) {
    if (!stream) return nullptr;
    IStream* nativeStream = nullptr;
    if (SUCCEEDED(CreateStreamOverRandomAccessStream(reinterpret_cast<IUnknown*>(winrt::get_abi(stream)), IID_PPV_ARGS(&nativeStream)))) {
        Bitmap* bmp = Bitmap::FromStream(nativeStream);
        nativeStream->Release();
        if (bmp && bmp->GetLastStatus() == Ok) return bmp;
        delete bmp;
    }
    return nullptr;
}

void UpdateMediaInfo() {
    try {
        if (!g_SessionManager) {
            g_SessionManager = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
        }
        if (!g_SessionManager) return;

        auto session = g_SessionManager.GetCurrentSession();
        if (session) {
            auto props = session.TryGetMediaPropertiesAsync().get();
            auto info = session.GetPlaybackInfo();

            lock_guard<mutex> guard(g_MediaState.lock);
            
            wstring newId = session.SourceAppUserModelId().c_str();
            if (newId != g_MediaState.sourceId) {
                Wh_Log(L"[MusicLounge] New Source: %s", newId.c_str());
                g_MediaState.sourceId = newId;
            }
            
            wstring newTitle = props.Title().c_str();
            if (newTitle != g_MediaState.title || g_MediaState.albumArt == nullptr) {
                if (g_MediaState.albumArt) { delete g_MediaState.albumArt; g_MediaState.albumArt = nullptr; }
                auto thumbRef = props.Thumbnail();
                if (thumbRef) {
                    auto stream = thumbRef.OpenReadAsync().get();
                    g_MediaState.albumArt = StreamToBitmap(stream);
                }
            }
            g_MediaState.title = newTitle;
            g_MediaState.artist = props.Artist().c_str();
            g_MediaState.isPlaying = (info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
            g_MediaState.hasMedia = true;
        } else {
            lock_guard<mutex> guard(g_MediaState.lock);
            g_MediaState.hasMedia = false;
            g_MediaState.title = L"No Media";
            g_MediaState.artist = L"";
            g_MediaState.sourceId = L"";
            if (g_MediaState.albumArt) { delete g_MediaState.albumArt; g_MediaState.albumArt = nullptr; }
        }
    } catch (...) {
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.sourceId = L"";
    }
}

void SendMediaCommand(int cmd) {
    try {
        if (!g_SessionManager) return;
        auto session = g_SessionManager.GetCurrentSession();
        if (session) {
            if (cmd == 1) session.TrySkipPreviousAsync();
            else if (cmd == 2) session.TryTogglePlayPauseAsync();
            else if (cmd == 3) session.TrySkipNextAsync();
        }
    } catch (...) {}
}

// --- ACTIVATION LOGIC ---

#include <mmdeviceapi.h>
#include <audiopolicy.h>
#include <tlhelp32.h>

// Manually define GUIDs for Audio & Activation
const CLSID CLSID_MMDeviceEnumerator = { 0xBCDE0395, 0xE52F, 0x467C, { 0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E } };
const IID IID_IMMDeviceEnumerator    = { 0xA95664D2, 0x9614, 0x4F35, { 0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6 } };
const IID IID_IAudioSessionManager2  = { 0x77AA99A0, 0x1BD6, 0x484F, { 0x8B, 0xC7, 0x2C, 0x65, 0x4C, 0x9A, 0x9B, 0x6F } };
const GUID CLSID_ApplicationActivationManager = { 0x4ce576fa, 0x83dc, 0x4f88, { 0x95, 0x1c, 0x9d, 0x07, 0x82, 0xb4, 0xa3, 0x19 } };
const IID IID_IApplicationActivationManager   = { 0x2e941141, 0x7f97, 0x4756, { 0xba, 0x1d, 0x9d, 0xec, 0xde, 0x89, 0x4a, 0x3d } };

// 1. Audio Session Hunter (WASAPI)
// Returns the Process ID (PID) of the app currently playing sound.
DWORD GetAudioPlayingPID() {
    DWORD targetPid = 0;
    IMMDeviceEnumerator* pEnumerator = NULL;
    IMMDevice* pDevice = NULL;
    IAudioSessionManager2* pSessionManager = NULL;
    IAudioSessionEnumerator* pSessionEnum = NULL;

    HRESULT hr = CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, (void**)&pEnumerator);
    if (FAILED(hr)) return 0;

    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
    if (SUCCEEDED(hr)) {
        hr = pDevice->Activate(IID_IAudioSessionManager2, CLSCTX_ALL, NULL, (void**)&pSessionManager);
        if (SUCCEEDED(hr)) {
            hr = pSessionManager->GetSessionEnumerator(&pSessionEnum);
            if (SUCCEEDED(hr)) {
                int count = 0;
                pSessionEnum->GetCount(&count);
                for (int i = 0; i < count; i++) {
                    IAudioSessionControl* pSessionCtrl = NULL;
                    IAudioSessionControl2* pSessionCtrl2 = NULL;
                    if (SUCCEEDED(pSessionEnum->GetSession(i, &pSessionCtrl))) {
                        if (SUCCEEDED(pSessionCtrl->QueryInterface(__uuidof(IAudioSessionControl2), (void**)&pSessionCtrl2))) {
                            AudioSessionState state;
                            if (SUCCEEDED(pSessionCtrl->GetState(&state)) && state == AudioSessionStateActive) {
                                // Found a session making noise!
                                pSessionCtrl2->GetProcessId(&targetPid);
                                // If pid is 0, it's system sounds, ignore.
                                if (targetPid != 0) {
                                    pSessionCtrl2->Release();
                                    pSessionCtrl->Release();
                                    break; 
                                }
                            }
                            pSessionCtrl2->Release();
                        }
                        pSessionCtrl->Release();
                    }
                }
                pSessionEnum->Release();
            }
            pSessionManager->Release();
        }
        pDevice->Release();
    }
    pEnumerator->Release();
    return targetPid;
}

// 2. Helper: Get Exe Name from PID
wstring GetProcessName(DWORD pid) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return L"";
    
    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);
    wstring name = L"";
    
    if (Process32FirstW(hSnapshot, &pe32)) {
        do {
            if (pe32.th32ProcessID == pid) {
                name = pe32.szExeFile;
                break;
            }
        } while (Process32NextW(hSnapshot, &pe32));
    }
    CloseHandle(hSnapshot);
    return name;
}

// 3. Window Finder
HWND g_FoundSourceWnd = NULL;
wstring g_TargetExeName = L"";
DWORD g_TargetPID = 0;

BOOL CALLBACK EnumSourceWindowsProc(HWND hwnd, LPARAM lParam) {
    if (!IsWindowVisible(hwnd)) return TRUE;
    
    // Check PID Match First (Most Accurate)
    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    
    // Check if this window belongs to the target PID
    // OR if it belongs to the same executable name (Browser multi-process handling)
    bool match = (pid == g_TargetPID);
    
    if (!match && !g_TargetExeName.empty()) {
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
        if (hProcess) {
            WCHAR path[MAX_PATH];
            DWORD size = MAX_PATH;
            if (QueryFullProcessImageNameW(hProcess, 0, path, &size)) {
                wstring exeName = wstring(path).substr(wstring(path).find_last_of(L"\\") + 1);
                if (_wcsicmp(exeName.c_str(), g_TargetExeName.c_str()) == 0) {
                    match = true;
                }
            }
            CloseHandle(hProcess);
        }
    }

    if (match) {
        // Must be a main window (no owner, has title)
        if (GetWindow(hwnd, GW_OWNER) == NULL && GetWindowTextLength(hwnd) > 0) {
            WCHAR clsName[256];
            GetClassNameW(hwnd, clsName, 256);
            if (wcscmp(clsName, L"Shell_TrayWnd") != 0 && wcscmp(clsName, L"Progman") != 0) {
                g_FoundSourceWnd = hwnd;
                return FALSE; // Stop found
            }
        }
    }
    return TRUE;
}

// 4. Fallback: Modern App Activation
bool ActivateModernApp(LPCWSTR aumid) {
    if (!aumid || !*aumid) return false;
    IApplicationActivationManager* pActivator = nullptr;
    HRESULT hr = CoCreateInstance(CLSID_ApplicationActivationManager, nullptr, CLSCTX_LOCAL_SERVER, IID_IApplicationActivationManager, (void**)&pActivator);
    if (SUCCEEDED(hr)) {
        DWORD pid = 0;
        hr = pActivator->ActivateApplication(aumid, nullptr, AO_NONE, &pid);
        pActivator->Release();
        return SUCCEEDED(hr);
    }
    return false;
}

bool ActivateViaShell(LPCWSTR aumid) {
    wstring cmd = L"shell:AppsFolder\\";
    cmd += aumid;
    return ((INT_PTR)ShellExecuteW(NULL, NULL, cmd.c_str(), NULL, NULL, SW_SHOWNORMAL) > 32);
}

void ActivateMediaSource(wstring sourceId) {
    Wh_Log(L"[MusicLounge] Clicked. SourceID: %s", sourceId.c_str());

    // STRATEGY A: AUDIO SESSION HUNTER (The "Nuclear Option")
    // Ask Windows: "What PID is making noise right now?"
    DWORD audioPid = GetAudioPlayingPID();
    
    if (audioPid != 0) {
        Wh_Log(L"[MusicLounge] Found Active Audio PID: %d", audioPid);
        g_TargetPID = audioPid;
        g_TargetExeName = GetProcessName(audioPid);
        g_FoundSourceWnd = NULL;
        
        EnumWindows(EnumSourceWindowsProc, 0);
        
        if (g_FoundSourceWnd) {
             Wh_Log(L"[MusicLounge] Found Window for Audio Process!");
             if (IsIconic(g_FoundSourceWnd)) ShowWindow(g_FoundSourceWnd, SW_RESTORE);
             SetForegroundWindow(g_FoundSourceWnd);
             return;
        }
    }

    // STRATEGY B: Fallback to ID (If audio is paused or undetectable)
    Wh_Log(L"[MusicLounge] No Audio Process found. Using ID Fallback.");
    
    // Try Modern/Shell Activation
    if (ActivateModernApp(sourceId.c_str())) return;
    ActivateViaShell(sourceId.c_str());
}

// --- Visuals ---
bool IsSystemLightMode() {
    DWORD value = 0; DWORD size = sizeof(value);
    if (RegGetValueW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"SystemUsesLightTheme", RRF_RT_DWORD, nullptr, &value, &size) == ERROR_SUCCESS) {
        return value != 0;
    }
    return false;
}

DWORD GetCurrentTextColor() {
    if (g_Settings.autoTheme) return IsSystemLightMode() ? 0xFF000000 : 0xFFFFFFFF;
    return g_Settings.manualTextColor;
}

void UpdateAppearance(HWND hwnd) {
    DWM_WINDOW_CORNER_PREFERENCE preference = DWMWCP_ROUND;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));

    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (hUser) {
        auto SetComp = (pSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
        if (SetComp) {
            DWORD tint = 0; 

            // LOGIC:
            if (g_Settings.manualBgColorRGB != 0) {
                // Manual Background Color is Active: Use its RGB + BgOpacity for Alpha
                tint = ((DWORD)g_Settings.bgOpacity << 24) | g_Settings.manualBgColorRGB;
            } else if (g_Settings.autoTheme) {
                // Auto Theme is Active: Use system light/dark
                tint = IsSystemLightMode() ? 0x40FFFFFF : 0x40000000; 
            } else {
                // Auto Theme is OFF, Manual BgColor is OFF: Use InvertTheme + BgOpacity
                DWORD baseColor = g_Settings.invertTheme ? 0x000000 : 0xFFFFFF; 
                tint = ((DWORD)g_Settings.bgOpacity << 24) | baseColor;
            }
            
            ACCENT_POLICY policy = { ACCENT_ENABLE_ACRYLICBLURBEHIND, 0, tint, 0 };
            WINDOWCOMPOSITIONATTRIBDATA data = { WCA_ACCENT_POLICY, &policy, sizeof(ACCENT_POLICY) };
            SetComp(hwnd, &data);
        }
    }
}

void DrawMediaPanel(HDC hdc, int width, int height) {
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);
    graphics.Clear(Color(0, 0, 0, 0)); 

    // APPLY DPI SCALING
    graphics.ScaleTransform(g_ScaleFactor, g_ScaleFactor);

    Color mainColor{GetCurrentTextColor()};
    
    MediaState state;
    {
        lock_guard<mutex> guard(g_MediaState.lock);
        state.title = g_MediaState.title;
        state.artist = g_MediaState.artist;
        state.albumArt = g_MediaState.albumArt ? g_MediaState.albumArt->Clone() : nullptr;
        state.hasMedia = g_MediaState.hasMedia;
        state.isPlaying = g_MediaState.isPlaying;
    }

    // USE LOGICAL DIMENSIONS
    int logicalH = g_Settings.height;
    int logicalW = g_Settings.width;

    int artSize = logicalH - 12;
    int artX = 6, artY = 6;
    
    if (state.albumArt) {
        graphics.DrawImage(state.albumArt, artX, artY, artSize, artSize);
        delete state.albumArt;
    } else {
        SolidBrush placeBrush{Color(40, 128, 128, 128)};
        graphics.FillRectangle(&placeBrush, artX, artY, artSize, artSize);
    }

    int startControlX = artX + artSize + 12;
    int controlY = logicalH / 2;
    SolidBrush iconBrush{mainColor};
    SolidBrush hoverBrush{Color(255, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};
    SolidBrush activeBg{Color(40, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};

    int pX = startControlX;
    if (g_HoverState == 1) graphics.FillEllipse(&activeBg, pX - 8, controlY - 12, 24, 24);
    Point prevPts[3] = { Point(pX + 8, controlY - 6), Point(pX + 8, controlY + 6), Point(pX, controlY) };
    graphics.FillPolygon(g_HoverState == 1 ? &hoverBrush : &iconBrush, prevPts, 3);
    graphics.FillRectangle(g_HoverState == 1 ? &hoverBrush : &iconBrush, pX, controlY - 6, 2, 12);

    int plX = startControlX + 28;
    if (g_HoverState == 2) graphics.FillEllipse(&activeBg, plX - 8, controlY - 12, 24, 24);
    if (state.isPlaying) {
        graphics.FillRectangle(g_HoverState == 2 ? &hoverBrush : &iconBrush, plX, controlY - 7, 3, 14);
        graphics.FillRectangle(g_HoverState == 2 ? &hoverBrush : &iconBrush, plX + 6, controlY - 7, 3, 14);
    } else {
        Point playPts[3] = { Point(plX, controlY - 8), Point(plX, controlY + 8), Point(plX + 10, controlY) };
        graphics.FillPolygon(g_HoverState == 2 ? &hoverBrush : &iconBrush, playPts, 3);
    }

    int nX = startControlX + 56;
    if (g_HoverState == 3) graphics.FillEllipse(&activeBg, nX - 8, controlY - 12, 24, 24);
    Point nextPts[3] = { Point(nX, controlY - 6), Point(nX, controlY + 6), Point(nX + 8, controlY) };
    graphics.FillPolygon(g_HoverState == 3 ? &hoverBrush : &iconBrush, nextPts, 3);
    graphics.FillRectangle(g_HoverState == 3 ? &hoverBrush : &iconBrush, nX + 8, controlY - 6, 2, 12);

    int textX = nX + 20;
    int textMaxW = logicalW - textX - 10;
    wstring fullText = state.title;
    if (!state.artist.empty()) fullText += L" • " + state.artist;

    FontFamily fontFamily(FONT_NAME, nullptr);
    Font font(&fontFamily, (REAL)g_Settings.fontSize, FontStyleBold, UnitPixel);
    SolidBrush textBrush{mainColor};
    
    RectF layoutRect(0, 0, 2000, 100), boundRect;
    graphics.MeasureString(fullText.c_str(), -1, &font, layoutRect, &boundRect);
    g_TextWidth = (int)boundRect.Width;

    Region textClip(Rect(textX, 0, textMaxW, logicalH));
    graphics.SetClip(&textClip);
    float textY = (logicalH - boundRect.Height) / 2.0f;

    if (g_TextWidth > textMaxW) {
        g_IsScrolling = true;
        float drawX = (float)(textX - g_ScrollOffset);
        graphics.DrawString(fullText.c_str(), -1, &font, PointF(drawX, textY), &textBrush);
        if (drawX + g_TextWidth < logicalW) {
             graphics.DrawString(fullText.c_str(), -1, &font, PointF(drawX + g_TextWidth + 40, textY), &textBrush);
        }
    } else {
        g_IsScrolling = false;
        g_ScrollOffset = 0;
        graphics.DrawString(fullText.c_str(), -1, &font, PointF((float)textX, textY), &textBrush);
    }
}

// --- Window Procedure ---
#define IDT_POLL_MEDIA 1001
#define IDT_TEXT_ANIM  1002
#define APP_WM_CLOSE   WM_APP

LRESULT CALLBACK MediaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: 
            UpdateAppearance(hwnd);
            SetTimer(hwnd, IDT_POLL_MEDIA, 1000, NULL); 
            return 0;
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY: g_SessionManager = nullptr; PostQuitMessage(0); return 0;
        case WM_SETTINGCHANGE: UpdateAppearance(hwnd); InvalidateRect(hwnd, NULL, TRUE); return 0;
        case WM_QUERYENDSESSION:
            g_ShutdownMode = true;
            ForceParkedState();
            return TRUE;
        case WM_SETCURSOR: {
            POINT pt; GetCursorPos(&pt);
            ScreenToClient(hwnd, &pt);
            int x = (int)(pt.x / g_ScaleFactor);
            int artRightEdge = 6 + (g_Settings.height - 12) + 5;
            if (x < artRightEdge) {
                SetCursor(LoadCursor(NULL, IDC_ARROW));
            } else {
                SetCursor(LoadCursor(NULL, IDC_HAND));
            }
            return TRUE;
        }
        case WM_TIMER:
            if (wParam == IDT_POLL_MEDIA) {
                // Refresh media state first
                UpdateMediaInfo();

                // Idle / paused hide logic
                bool isPlaying = false;
                {
                    lock_guard<mutex> guard(g_MediaState.lock);
                    isPlaying = g_MediaState.isPlaying;
                }

                if (g_Settings.idleTimeout > 0) {
                    if (isPlaying) {
                        g_IdleSecondsCounter = 0;
                        g_IsHiddenByIdle = false;
                    } else {
                        g_IdleSecondsCounter++;
                        if (g_IdleSecondsCounter >= g_Settings.idleTimeout) {
                            g_IsHiddenByIdle = true;
                        }
                    }
                } else {
                    g_IsHiddenByIdle = false;
                    g_IdleSecondsCounter = 0;
                }

                // Apply positioning and animation (respects both game detection and idle timeout)
                SyncPositionWithTaskbar();
                InvalidateRect(hwnd, NULL, FALSE);
            }
            else if (wParam == IDT_TEXT_ANIM) {
                if (g_IsScrolling) {
                    if (g_ScrollWait > 0) g_ScrollWait--;
                    else {
                        g_ScrollOffset++;
                        if (g_ScrollOffset > g_TextWidth + 40) { g_ScrollOffset = 0; g_ScrollWait = 60; }
                        InvalidateRect(hwnd, NULL, FALSE);
                    }
                } else KillTimer(hwnd, IDT_TEXT_ANIM);
            }
            else if (wParam == IDT_VIS_ANIM) {
                int screenH = GetSystemMetrics(SM_CYSCREEN);
                RECT rcTb; GetWindowRect(g_hTaskbar, &rcTb);
                int scaledH = (int)(g_Settings.height * g_ScaleFactor);
                int scaledOffY = (int)(g_Settings.offsetY * g_ScaleFactor);
                int targetY = rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY;
                
                if (g_AnimState == 1) { // Hide
                    // Continue hiding if either game is detected OR idle timeout active
                    if (!g_IsGameDetected && !g_IsHiddenByIdle) { g_AnimState = 2; return 0; }
                    g_CurrentAnimY += 8;
                    if (g_CurrentAnimY > screenH) {
                        ShowWindow(hwnd, SW_HIDE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_AnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_TOPMOST, rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                else if (g_AnimState == 2) { // Show
                    // Resume hiding if game detected OR idle timeout active again
                    if (g_IsGameDetected || g_IsHiddenByIdle) { g_AnimState = 1; return 0; }
                    g_CurrentAnimY -= 8;
                    if (g_CurrentAnimY <= targetY) {
                        g_CurrentAnimY = targetY;
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_TOPMOST, rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_AnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_TOPMOST, rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
            }
            return 0;
        case WM_MOUSEMOVE: {
            // UNSCALE INPUT COORDINATES
            int x = (int)(LOWORD(lParam) / g_ScaleFactor);
            int y = (int)(HIWORD(lParam) / g_ScaleFactor);
            
            // USE LOGICAL HEIGHT
            int logicalH = g_Settings.height;
            int artSize = logicalH - 12;
            int startControlX = 6 + artSize + 12;
            int newState = 0;
            if (y > 10 && y < logicalH - 10) {
                if (x >= startControlX - 10 && x < startControlX + 14) newState = 1;
                else if (x >= startControlX + 14 && x < startControlX + 42) newState = 2;
                else if (x >= startControlX + 42 && x < startControlX + 66) newState = 3;
            }
            if (newState != g_HoverState) { g_HoverState = newState; InvalidateRect(hwnd, NULL, FALSE); }
            TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT), TME_LEAVE, hwnd, 0 };
            TrackMouseEvent(&tme);
            return 0;
        }
        case WM_MOUSELEAVE: g_HoverState = 0; InvalidateRect(hwnd, NULL, FALSE); break;
        case WM_LBUTTONUP:
            if (g_HoverState > 0) {
                SendMediaCommand(g_HoverState);
            } else {
                if (g_Settings.enableAppSwitch) {
                    int x = (int)(LOWORD(lParam) / g_ScaleFactor);
                    int artSize = g_Settings.height - 12;
                    int artRightEdge = 6 + artSize + 5;

                    if (x > artRightEdge) {
                        wstring targetId;
                        {
                            lock_guard<mutex> guard(g_MediaState.lock);
                            targetId = g_MediaState.sourceId;
                        }
                        ActivateMediaSource(targetId);
                    }
                }
            }
            return 0;
        case WM_MOUSEWHEEL: {
            short zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            keybd_event(zDelta > 0 ? VK_VOLUME_UP : VK_VOLUME_DOWN, 0, 0, 0);
            keybd_event(zDelta > 0 ? VK_VOLUME_UP : VK_VOLUME_DOWN, 0, KEYEVENTF_KEYUP, 0);
            return 0;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps; HDC hdc = BeginPaint(hwnd, &ps);
            RECT rc; GetClientRect(hwnd, &rc);
            HDC memDC = CreateCompatibleDC(hdc);
            HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
            DrawMediaPanel(memDC, rc.right, rc.bottom);
            if (g_IsScrolling) SetTimer(hwnd, IDT_TEXT_ANIM, 16, NULL);
            BitBlt(hdc, 0, 0, rc.right, rc.bottom, memDC, 0, 0, SRCCOPY);
            SelectObject(memDC, oldBitmap); DeleteObject(memBitmap); DeleteDC(memDC);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void MediaThread() {
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

    // Revert to MTA to prevent UpdateMediaInfo from deadlocking/crashing
    winrt::init_apartment();
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    WNDCLASS wc = {0};
    wc.lpfnWndProc = MediaWndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("WindhawkMusicLounge_GSMTC");
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    RegisterClass(&wc);

    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
    pCreateWindowInBand CreateWindowInBand = (pCreateWindowInBand)GetProcAddress(hUser32, "CreateWindowInBand");

    if (CreateWindowInBand) {
        g_hMediaWindow = CreateWindowInBand(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST, wc.lpszClassName, TEXT("MusicLounge"), WS_POPUP | WS_VISIBLE, 0, 0, g_Settings.width, g_Settings.height, NULL, NULL, wc.hInstance, NULL, ZBID_IMMERSIVE_NOTIFICATION);
    } else {
        g_hMediaWindow = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST, wc.lpszClassName, TEXT("MusicLounge"), WS_POPUP | WS_VISIBLE, 0, 0, g_Settings.width, g_Settings.height, NULL, NULL, wc.hInstance, NULL);
    }

    SetLayeredWindowAttributes(g_hMediaWindow, 0, 255, LWA_ALPHA);

    // Initial State: PARKED (2px visible at bottom)
    UpdateScaleFactor();
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int scaledW = (int)(g_Settings.width * g_ScaleFactor);
    int scaledH = (int)(g_Settings.height * g_ScaleFactor);
    SetWindowPos(g_hMediaWindow, HWND_TOPMOST, 0, screenH - 2, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_AnimState = 3; // Parked

    // Setup Visibility Hook
    g_hVisibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) { TranslateMessage(&msg); DispatchMessage(&msg); }

    if (g_hVisibilityHook) UnhookWinEvent(g_hVisibilityHook);
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    GdiplusShutdown(gdiplusToken);
    winrt::uninit_apartment();
}

std::thread* g_pMediaThread = nullptr;

BOOL WhTool_ModInit() {
    SetCurrentProcessExplicitAppUserModelID(L"taskbar-music-lounge");
    LoadSettings(); 
    g_Running = true;
    g_pMediaThread = new std::thread(MediaThread);
    return TRUE;
}

void WhTool_ModUninit() {
    g_Running = false;
    if (g_hMediaWindow) SendMessage(g_hMediaWindow, APP_WM_CLOSE, 0, 0);
    if (g_pMediaThread) {
        if (g_pMediaThread->joinable()) g_pMediaThread->join();
        delete g_pMediaThread;
        g_pMediaThread = nullptr;
    }
}

void WhTool_ModSettingsChanged() {
    LoadSettings();
    if (g_hMediaWindow) {
         SyncPositionWithTaskbar();
         SendMessage(g_hMediaWindow, WM_SETTINGCHANGE, 0, 0); 
    }
}

// --- Launcher Boilerplate ---
bool g_isToolModProcessLauncher;
HANDLE g_toolModProcessMutex;
void WINAPI EntryPoint_Hook() { ExitThread(0); }

BOOL Wh_ModInit() {
    bool isService = false, isCurrentToolModProcess = false;
    int argc; LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
    if (!argv) return FALSE;
    for (int i = 1; i < argc; i++) { if (wcscmp(argv[i], L"-service") == 0) isService = true; }
    for (int i = 1; i < argc - 1; i++) { if (wcscmp(argv[i], L"-tool-mod") == 0 && wcscmp(argv[i + 1], WH_MOD_ID) == 0) isCurrentToolModProcess = true; }
    LocalFree(argv);
    if (isService) return FALSE;

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex = CreateMutex(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex || GetLastError() == ERROR_ALREADY_EXISTS) ExitProcess(1);
        if (!WhTool_ModInit()) ExitProcess(1);
        IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)GetModuleHandle(nullptr);
        IMAGE_NT_HEADERS* ntHeaders = (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);
        Wh_SetFunctionHook((BYTE*)dosHeader + ntHeaders->OptionalHeader.AddressOfEntryPoint, (void*)EntryPoint_Hook, nullptr);
        return TRUE;
    }
    g_isToolModProcessLauncher = true; return TRUE;
}

void Wh_ModAfterInit() {
    if (!g_isToolModProcessLauncher) return;
    WCHAR path[MAX_PATH], cmd[MAX_PATH + 100];
    GetModuleFileName(nullptr, path, MAX_PATH);
    swprintf_s(cmd, L"\"%s\" -tool-mod \"%s\"", path, WH_MOD_ID);
    STARTUPINFO si = { sizeof(si) }; PROCESS_INFORMATION pi;
    if (CreateProcess(nullptr, cmd, nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS, nullptr, nullptr, &si, &pi)) {
        CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
    }
}

void Wh_ModSettingsChanged() { if (!g_isToolModProcessLauncher) WhTool_ModSettingsChanged(); }
void Wh_ModUninit() { if (!g_isToolModProcessLauncher) { WhTool_ModUninit(); ExitProcess(0); } }