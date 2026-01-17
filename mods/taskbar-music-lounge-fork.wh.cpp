// ==WindhawkMod==
// @id              taskbar-music-lounge-fork
// @name            Taskbar Music Lounge - Fork
// @description     A native-style music ticker with media controls and custom Action Triggers.
// @version         4.8.0
// @author          Hashah2311 | Cinabutts
// @github          https://github.com/Hashah2311
// @include         explorer.exe
// @compilerOptions -lole32 -ldwmapi -lgdi32 -luser32 -lwindowsapp -lshcore -lgdiplus -lshell32 -lpsapi -lcomctl32 -loleaut32 -lversion -lpropsys
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Music Lounge (v4.8.0)

A media controller that uses Windows 11 native DWM styling for a seamless look.

##                                                 ✨ Features
* **Universal Support:** Works with any media player via GSMTC.
* **Album Art:** Displays current track cover art.
* **Native Look:** Uses Windows 11 hardware-accelerated rounding and acrylic blur.
* **Auto Theme** Automatically sets Background/Text color to match System Light/Dark mode.
* **--------------------------------- Cinabutts Enhancements: ---------------------------------**
* **High-DPI Support:** Automatically scales UI elements to look perfect on 4K/1440p monitors.
* **Smart Game Detection:** Automatically hides when playing Fullscreen games.
* **Whitelist:** Keep the widget visible in specific Fullscreen apps (e.g., Firefox).
* **Slide Animations:** Smoothly slides in/out when entering/exiting games.
* **Smart Docking:** Sits unobtrusively at the screen edge on boot/shutdown or if Explorer crashes.
* **Fully Customizable:** Override Background/Text RGB - Invert Light/Dark mode - Adjust Size/Position - Rounded or Square Corners.
* **Rainbow RGB:** Optional flowing rainbow border effect beneath the widget

----

&nbsp;

##                                                 🔧 Mouse Action Engine
Trigger custom Actions via Mouse Clicks + optional Modifiers.

Available `Mouse Triggers`:
- Left Click
- Right Click
- Double Click
- Scroll Up
- Scroll Down

Available `Actions`:
- Switch to Audible Window
- Volume Controls(Up/Down & Mute)
- Media Controls(Prev/Next/Play/Pause)
- Send Keystrokes (macro)
- Open App / Run File
- Show Desktop
- Hide Desktop Icons
- Toggle Taskbar Auto-Hide
- Toggle Taskbar Alignment
- Combine Taskbar Buttons
- Win+Tab
- Ctrl+Alt+Tab
- Open Start Menu
- Open Task Manager

                                      **`Work In Progress!` Some actions may not work as expected.**

Use AdditionalArgs with the Combine Taskbar Buttons action to provide the COMBINE_* states that should be applied (see the settings description).

###                         🚧 Volume Note: You **TYPICALLY** need to Left Click the widget first to focus it before scrolling.
                        **Tip:** Avoid assigning "Left Click" as a trigger if you use volume scrolling, as it will prevent the widget from gaining focus.

----

&nbsp;

## ⚠️ Requirements
* **Disable Widgets:** Taskbar Settings -> Widgets -> Off.
* **Windows 11:** Required for rounded corners.

&nbsp;


                                                                                                                        🧪 Tested on Windows 11 25H2 (26220.7535) - 4096x2160 125% Scale
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- PanelWidth: 400
  $name: Panel Width
- PanelHeight: 35
  $name: Panel Height
- FontSize: 13
  $name: Font Size
- OffsetX: 140
  $name: X Offset
- OffsetY: 0
  $name: Y Offset
- AutoTheme: true
  $name: Auto Theme
  $description: >-
    ✓ System | B/W Text & Icons based on System Light/Dark mode.
    
    ✕ Custom | Use Custom theme below ↓
- InvertTheme: false
  $name: Invert System Light/Dark (Background)
  $description: >-
    ✓  Enabled | Dark Background.
    
    ✕ Disabled | Light Background. (Auto Theme must be OFF)
- EnableRoundedCorners: true
  $name: Enable Rounded Corners
  $description: >-
    ✓ Rounded | Native Windows 11 rounded corners.
    
    ✕ Square | Traditional square corners.
- _Separator_: ""
  $name: " "
- BgColor: "0, 0, 0"
  $name: Manual Background Color Override (R, G, B)
  $description: Set to 0,0,0 to not override. Enter RGB values separated by commas (e.g; "102, 255, 255"). Alpha controlled below ↓
- BgOpacity: 0
  $name: Acrylic Tint Opacity (0-255)
  $description: Keep 0 for pure glass. Controls Alpha for Manual Background Color.
- TextColor: "255, 255, 255"
  $name: Manual Text Color (R, G, B, [A])
  $description: Enter RGB or RGBA values separated by commas (e.g; "102, 255, 255" or "255, 0, 0, 128")
- IdleTimeout: 0
  $name: Auto-hide when paused (Seconds)
  $description: Automatically hide the widget when music is paused for the specified number of seconds. Set 0 to disable.
- EnableTextScroll: true
  $name: Enable Text Scroll
  $description: Allow the text to scroll if the text is cut off.
- EnableSlide: true
  $name: Enable Slide Animations
  $description: >-
    ✓ Smooth | Widget slides smoothly in/out place.
    
    ✕ Static | Widget snaps in/out instantly.
- EnableGameDetection: true
  $name: Enable Game Detection
  $description: >-
    ✓ Detect | Widget hides on game detection.
    
    ✕ Ignore | The widget will NEVER hide for games. (overrides all below ↓)
- FullscreenCheckInterval: 2
  $name: Fullscreen Check Interval (Seconds)
  $description: How often to check for borderless games.
- IgnoredApps: firefox.exe;chrome.exe;msedge.exe;vlc.exe
  $name: Fullscreen Whitelist
  $description: Semicolon-separated list of executables to IGNORE (keep widget visible).
- EnableRainbow: false
  $name: Enable Rainbow RGB Effect
  $description: >-
    ✓ Enabled | Adds a flowing rainbow gradient border beneath the widget.
    
    ✕ Disabled | No rainbow effect.
- RainbowSpeed: 3
  $name: Rainbow Speed (1-10)
  $description: Controls how fast the rainbow colors flow. Higher = faster.
- RainbowBrightness: 80
  $name: Rainbow Brightness (0-100)
  $description: Controls the brightness/intensity of the rainbow colors.
- RainbowThickness: 1
  $name: Rainbow Border Thickness (1-10 pixels)
  $description: Controls how thick the rainbow border appears.
- RainbowBorderOffset: 0
  $name: Rainbow Border Offset (0-10 pixels)
  $description: Distance between main widget and rainbow border.
- TriggerActionOptions:
  - - MouseTrigger: Double
      $name: Mouse Trigger
      $description: The mouse button or wheel action to detect on the empty space.
      $options:
      - Left: Left Click
      - Right: Right Click
      - Middle: Middle Click
      - Double: Double Click
      - ScrollUp: Scroll Up
      - ScrollDown: Scroll Down
    - KeyboardTriggers: [none]
      $name: Required Modifiers
      $description: Hold these keys while clicking. Select 'None' if no modifiers are needed.
      $options:
      - none: None
      - lctrl: Left Ctrl
      - rctrl: Right Ctrl
      - lshift: Left Shift
      - rshift: Right Shift
      - lalt: Left Alt
      - ralt: Right Alt
      - win: Win Key
    - Action: ACTION_ACTIVATE_SOURCE_APP
      $name: Action
      $description: The command to execute.
      $options:
      - ACTION_ACTIVATE_SOURCE_APP: Switch to Audible Window
      - ACTION_VOLUME_UP: Volume Up
      - ACTION_VOLUME_DOWN: Volume Down
      - ACTION_START_PROCESS: Open App / Run File
      - ACTION_SEND_KEYPRESS: Send Keystrokes (Macro)
      - ACTION_MUTE: Toggle Mute
      - ACTION_MEDIA_PLAY_PAUSE: Media Play/Pause
      - ACTION_MEDIA_NEXT: Media Next Track
      - ACTION_MEDIA_PREV: Media Prev Track
      - ACTION_SHOW_DESKTOP: Show Desktop
      - ACTION_TOGGLE_DESKTOP_ICONS: Toggle Desktop Icons
      - ACTION_TOGGLE_TASKBAR_AUTOHIDE: Toggle Taskbar Auto-Hide
      - ACTION_TOGGLE_TASKBAR_ALIGNMENT: Toggle Taskbar Alignment
      - ACTION_COMBINE_TASKBAR_BUTTONS: Combine Taskbar Buttons
      - ACTION_WIN_TAB: Win+Tab
      - ACTION_CTRL_ALT_TAB: Ctrl+Alt+Tab
      - ACTION_OPEN_START_MENU: Open Start Menu
      - ACTION_TASK_MANAGER: Open Task Manager
    - AdditionalArgs: ""
      $name: Arguments
      $description: >-
        For 'Open App': Path to exe or URL (e.g. calc.exe).
        For 'Send Keystrokes': Key combo (e.g. Ctrl+C).
                For 'Combine Taskbar Buttons': Specify 2 or 4 COMBINE_* states separated by semicolons (e.g. COMBINE_ALWAYS;COMBINE_NEVER or COMBINE_ALWAYS;COMBINE_NEVER;COMBINE_WHEN_FULL;COMBINE_ALWAYS).
  - - MouseTrigger: ScrollUp
    - KeyboardTriggers: [none]
    - Action: ACTION_VOLUME_UP
    - AdditionalArgs: ""
  - - MouseTrigger: ScrollDown
    - KeyboardTriggers: [none]
    - Action: ACTION_VOLUME_DOWN
    - AdditionalArgs: ""
  $name: Custom Mouse Actions
  $description: Configure what happens when you click the widget background.
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <shellapi.h>
#include <dwmapi.h>
#include <gdiplus.h>
#include <shcore.h> 
#include <propsys.h>
#include <propkey.h>
#include <string>
#include <thread>
#include <mutex>
#include <cstdio>
#include <psapi.h>
#include <shobjidl.h>
#include <windhawk_utils.h>
#include <sstream>

// Action Engine Includes
#include <commctrl.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>
#include <windef.h>
#include <winerror.h>
#include <winuser.h>
#include <algorithm>
#include <cwctype>
#include <functional>
#include <string_view>
#include <unordered_map>
#include <vector>

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
    int width = 400;
    int height = 35;
    int fontSize = 13;
    int offsetX = 140;
    int offsetY = 0;
    bool autoTheme = true;
    bool invertTheme = false;
    DWORD manualTextColor = 0xFFFFFFFF; 
    DWORD manualBgColorRGB = 0; // Stores BGR for DWM
    int bgOpacity = 0;
    int fsInterval = 2;
    int idleTimeout = 0;
    bool EnableTextScroll = true;
    bool enableSlide = true;
    bool enableGameDetect = true;
    wstring ignoredApps;
    bool enableRainbow = false;
    int rainbowSpeed = 3;
    int rainbowBrightness = 80;
    int rainbowThickness = 1;
    int rainbowBorderOffset = 0;
    bool enableRoundedCorners = true;
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

// Rainbow Feature State
HWND g_hRainbowWindow = NULL;
float g_RainbowHue = 0.0f; // 0-360 for HSV color wheel
int g_RainbowAnimState = 0; // Mirror of main window anim state
int g_CurrentRainbowAnimY = 0;

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

// --- ACTION ENGINE LIBRARY ---

using winrt::com_ptr;

namespace stringtools {
    std::wstring trim(const std::wstring& s) {
        auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::iswspace(c); });
        auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::iswspace(c); }).base();
        return (wsback <= wsfront) ? std::wstring() : std::wstring(wsfront, wsback);
    }
    std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter) {
        std::vector<std::wstring> tokens;
        std::wstring token;
        std::wstringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(trim(token));
        }
        return tokens;
    }
    std::wstring toLower(const std::wstring& s) {
        std::wstring result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::towlower);
        return result;
    }
}

class AudioCOMAPI {
 public:
    AudioCOMAPI() : m_isInitialized(false), m_isCOMInitialized(false), m_pDeviceEnumerator(nullptr) {}
    bool Init() {
        if (!m_isCOMInitialized) {
            if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED))) m_isCOMInitialized = true;
            else return false;
        }
        if (!m_isInitialized && m_isCOMInitialized) {
            const GUID XIID_IMMDeviceEnumerator = {0xA95664D2, 0x9614, 0x4F35, {0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6}};
            const GUID XIID_MMDeviceEnumerator = {0xBCDE0395, 0xE52F, 0x467C, {0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E}};
            if (FAILED(CoCreateInstance(XIID_MMDeviceEnumerator, NULL, CLSCTX_INPROC_SERVER, XIID_IMMDeviceEnumerator, m_pDeviceEnumerator.put_void())) || !m_pDeviceEnumerator) return false;
            m_isInitialized = true;
        }
        return m_isInitialized;
    }
    void Uninit() {
        if (m_isInitialized) { m_pDeviceEnumerator = nullptr; m_isInitialized = false; }
        if (m_isCOMInitialized) { CoUninitialize(); m_isCOMInitialized = false; }
    }
    bool IsInitialized() { return m_isInitialized; }
    const com_ptr<IMMDeviceEnumerator> GetDeviceEnumerator() { return m_pDeviceEnumerator; }
 private:
    bool m_isInitialized;
    bool m_isCOMInitialized;
    com_ptr<IMMDeviceEnumerator> m_pDeviceEnumerator;
};
static AudioCOMAPI g_audioCOM;

enum KeyModifier {
    KEY_MODIFIER_LCTRL = 0, KEY_MODIFIER_RCTRL, KEY_MODIFIER_LALT, KEY_MODIFIER_RALT,
    KEY_MODIFIER_LSHIFT, KEY_MODIFIER_RSHIFT, KEY_MODIFIER_LWIN, KEY_MODIFIER_INVALID
};

void SetBit(uint32_t &value, uint32_t bit) { value |= (1U << bit); }

static uint32_t GetKeyModifiersState() {
    BYTE keyState[256] = {0};
    if (!GetKeyboardState(keyState)) return 0U;
    uint32_t currentKeyModifiersState = 0U;
    if (keyState[VK_LCONTROL] & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_LCTRL);
    if (keyState[VK_LSHIFT]   & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_LSHIFT);
    if (keyState[VK_LMENU]    & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_LALT);
    if (keyState[VK_LWIN]     & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_LWIN);
    if (keyState[VK_RCONTROL] & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_RCTRL);
    if (keyState[VK_RSHIFT]   & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_RSHIFT);
    if (keyState[VK_RMENU]    & 0x80) SetBit(currentKeyModifiersState, KEY_MODIFIER_RALT);
    return currentKeyModifiersState;
}

KeyModifier GetKeyModifierFromName(const std::wstring &keyName) {
    if (keyName == L"lctrl") return KEY_MODIFIER_LCTRL;
    if (keyName == L"rctrl") return KEY_MODIFIER_RCTRL;
    if (keyName == L"lshift") return KEY_MODIFIER_LSHIFT;
    if (keyName == L"rshift") return KEY_MODIFIER_RSHIFT;
    if (keyName == L"lalt") return KEY_MODIFIER_LALT;
    if (keyName == L"ralt") return KEY_MODIFIER_RALT;
    if (keyName == L"win") return KEY_MODIFIER_LWIN;
    return KEY_MODIFIER_INVALID;
}

bool FromStringHotKey(std::wstring_view hotkeyString, UINT* modifiersOut, UINT* vkOut) {
    static const std::unordered_map<std::wstring_view, UINT> modifiersMap = {
        {L"ALT", MOD_ALT}, {L"CTRL", MOD_CONTROL}, {L"SHIFT", MOD_SHIFT}, {L"WIN", MOD_WIN},
    };
    static const std::unordered_map<std::wstring_view, UINT> vkMap = {
        {L"A", 0x41}, {L"B", 0x42}, {L"C", 0x43}, {L"D", 0x44}, {L"E", 0x45}, {L"F", 0x46}, {L"G", 0x47}, {L"H", 0x48},
        {L"I", 0x49}, {L"J", 0x4A}, {L"K", 0x4B}, {L"L", 0x4C}, {L"M", 0x4D}, {L"N", 0x4E}, {L"O", 0x4F}, {L"P", 0x50},
        {L"Q", 0x51}, {L"R", 0x52}, {L"S", 0x53}, {L"T", 0x54}, {L"U", 0x55}, {L"V", 0x56}, {L"W", 0x57}, {L"X", 0x58},
        {L"Y", 0x59}, {L"Z", 0x5A}, {L"0", 0x30}, {L"1", 0x31}, {L"2", 0x32}, {L"3", 0x33}, {L"4", 0x34}, {L"5", 0x35},
        {L"6", 0x36}, {L"7", 0x37}, {L"8", 0x38}, {L"9", 0x39}, {L"F1", 0x70}, {L"F2", 0x71}, {L"F3", 0x72}, {L"F4", 0x73},
        {L"F5", 0x74}, {L"F6", 0x75}, {L"F7", 0x76}, {L"F8", 0x77}, {L"F9", 0x78}, {L"F10", 0x79}, {L"F11", 0x7A}, {L"F12", 0x7B},
        {L"BACKSPACE", 0x08}, {L"TAB", 0x09}, {L"ENTER", 0x0D}, {L"RETURN", 0x0D}, {L"PAUSE", 0x13}, {L"CAPSLOCK", 0x14},
        {L"ESCAPE", 0x1B}, {L"ESC", 0x1B}, {L"SPACE", 0x20}, {L"SPACEBAR", 0x20}, {L"PAGEUP", 0x21}, {L"PAGEDOWN", 0x22},
        {L"END", 0x23}, {L"HOME", 0x24}, {L"LEFT", 0x25}, {L"UP", 0x26}, {L"RIGHT", 0x27}, {L"DOWN", 0x28}, {L"INSERT", 0x2D}, {L"DELETE", 0x2E},
        {L"VOLUMEMUTE", 0xAD}, {L"VOLUMEDOWN", 0xAE}, {L"VOLUMEUP", 0xAF}, {L"MEDIANEXT", 0xB0}, {L"MEDIAPREV", 0xB1}, 
        {L"MEDIASTOP", 0xB2}, {L"MEDIAPLAYPAUSE", 0xB3}
    };
    UINT vk = 0;
    std::wstring partStr(hotkeyString);
    std::transform(partStr.begin(), partStr.end(), partStr.begin(), ::toupper);
    if (auto it = modifiersMap.find(partStr); it != modifiersMap.end()) { *modifiersOut = it->second; *vkOut = 0; return true; }
    if (auto it = vkMap.find(partStr); it != vkMap.end()) { vk = it->second; } 
    else { try { vk = std::stoi(partStr, 0, 0); } catch(...) {} }
    *modifiersOut = 0; *vkOut = vk;
    return (vk != 0);
}

static const int kMaxKeypressRetryCount = 50; 
static const UINT kKeypressRetryIntervalMs = 10;
static std::vector<int> g_pendingKeypressKeys;
static int g_pendingKeypressRetryCount = 0;
static UINT_PTR g_keypressTimerId = 0;

bool AreModifierKeysPressed() {
    return (GetAsyncKeyState(VK_CONTROL) & 0x8000) || (GetAsyncKeyState(VK_MENU) & 0x8000) || 
           (GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetAsyncKeyState(VK_LWIN) & 0x8000) || (GetAsyncKeyState(VK_RWIN) & 0x8000);
}

void SendKeypressInternal(const std::vector<int>& keys) {
    if (keys.empty()) return;
    const int NUM_KEYS = static_cast<int>(keys.size());
    std::unique_ptr<INPUT[]> input(new INPUT[NUM_KEYS * 2]);
    for (int i = 0; i < NUM_KEYS; i++) {
        input[i].type = INPUT_KEYBOARD; input[i].ki.wVk = static_cast<WORD>(keys[i]); input[i].ki.dwFlags = 0;
    }
    for (int i = 0; i < NUM_KEYS; i++) {
        input[NUM_KEYS + i].type = INPUT_KEYBOARD; input[NUM_KEYS + i].ki.wVk = static_cast<WORD>(keys[i]);
        input[NUM_KEYS + i].ki.dwFlags = KEYEVENTF_KEYUP;
    }
    SendInput(NUM_KEYS * 2, input.get(), sizeof(input[0]));
}

void CALLBACK KeypressRetryTimerProc(HWND, UINT, UINT_PTR timerId, DWORD) {
    if (!AreModifierKeysPressed()) {
        KillTimer(nullptr, timerId); g_keypressTimerId = 0;
        SendKeypressInternal(g_pendingKeypressKeys); g_pendingKeypressKeys.clear();
    } else if (++g_pendingKeypressRetryCount >= kMaxKeypressRetryCount) {
        KillTimer(nullptr, timerId); g_keypressTimerId = 0;
        SendKeypressInternal(g_pendingKeypressKeys); g_pendingKeypressKeys.clear();
    }
}

void SendKeypress(const std::vector<int>& keys) {
    if (keys.empty()) return;
    if (g_keypressTimerId) { KillTimer(nullptr, g_keypressTimerId); g_keypressTimerId = 0; }
    if (AreModifierKeysPressed()) {
        g_pendingKeypressKeys = keys; g_pendingKeypressRetryCount = 0;
        g_keypressTimerId = SetTimer(nullptr, 0, kKeypressRetryIntervalMs, KeypressRetryTimerProc);
        return;
    }
    SendKeypressInternal(keys);
}

void StartProcess(std::wstring command) {
    if (command.empty()) return;
    std::thread([command](){
        std::wstring cmd = command;
        auto args = stringtools::split(cmd, L';');
        std::wstring verb = L"open";
        if (!args.empty() && stringtools::toLower(args[0]) == L"uac") { verb = L"runas"; cmd = cmd.substr(4); }
        std::wstring executable = cmd, parameters;
        if (cmd.size() > 0 && (cmd[0] == L'"' || cmd[0] == L'\'')) {
            size_t close = cmd.find(cmd[0], 1);
            if (close != std::wstring::npos) { executable = cmd.substr(1, close - 1); if (cmd.length() > close + 1) parameters = cmd.substr(close + 1); }
        } else {
            auto parts = stringtools::split(cmd, L' ');
            if (parts.size() > 1) { executable = parts[0]; parameters = cmd.substr(executable.length()); }
        }
        SHELLEXECUTEINFO sei = {sizeof(sei)};
        sei.fMask = SEE_MASK_NOASYNC | SEE_MASK_FLAG_NO_UI; sei.lpVerb = verb.c_str(); sei.lpFile = executable.c_str();
        sei.lpParameters = parameters.empty() ? nullptr : parameters.c_str(); sei.nShow = SW_SHOWNORMAL;
        ShellExecuteEx(&sei);
    }).detach();
}

BOOL IsAudioMuted(com_ptr<IMMDeviceEnumerator> pDeviceEnumerator) {
    const GUID XIID_IAudioEndpointVolume = { 0x5CDF2C82, 0x841E, 0x4546, {0x97, 0x22, 0x0C, 0xF7, 0x40, 0x78, 0x22, 0x9A} };
    BOOL isMuted = FALSE;
    com_ptr<IMMDevice> defaultAudioDevice;
    if (SUCCEEDED(pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, defaultAudioDevice.put()))) {
        com_ptr<IAudioEndpointVolume> endpointVolume;
        if (SUCCEEDED(defaultAudioDevice->Activate(XIID_IAudioEndpointVolume, CLSCTX_INPROC_SERVER, NULL, endpointVolume.put_void()))) {
            endpointVolume->GetMute(&isMuted);
        }
    }
    return isMuted;
}

void ToggleVolMuted() {
    if (!g_audioCOM.IsInitialized()) { if (!g_audioCOM.Init()) return; }
    auto pDeviceEnumerator = g_audioCOM.GetDeviceEnumerator(); if (!pDeviceEnumerator) return;
    const GUID XIID_IAudioEndpointVolume = { 0x5CDF2C82, 0x841E, 0x4546, {0x97, 0x22, 0x0C, 0xF7, 0x40, 0x78, 0x22, 0x9A} };
    const BOOL isMuted = IsAudioMuted(pDeviceEnumerator);
    com_ptr<IMMDeviceCollection> pDeviceCollection;
    if (FAILED(pDeviceEnumerator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, pDeviceCollection.put()))) return;
    UINT deviceCount = 0; if (FAILED(pDeviceCollection->GetCount(&deviceCount))) return;
    for (UINT i = 0; i < deviceCount; i++) {
        com_ptr<IMMDevice> pDevice;
        if (SUCCEEDED(pDeviceCollection->Item(i, pDevice.put()))) {
            com_ptr<IAudioEndpointVolume> endpointVolume;
            if (SUCCEEDED(pDevice->Activate(XIID_IAudioEndpointVolume, CLSCTX_INPROC_SERVER, NULL, endpointVolume.put_void()))) {
                endpointVolume->SetMute(!isMuted, NULL);
            }
        }
    }
}

// Helper: get AUMID from a window
std::wstring GetWindowAUMID(HWND hwnd) {
    IPropertyStore* pps = nullptr;
    if (FAILED(SHGetPropertyStoreForWindow(hwnd, IID_PPV_ARGS(&pps)))) return L"";
    
    PROPVARIANT var;
    PropVariantInit(&var);
    std::wstring aumid;

    // Local PROPERTYKEY for AppUserModelID to avoid linking issues with PKEY_AppUserModel_ID
    static const PROPERTYKEY kPKEY_AppUserModel_ID = { { 0x9F4C2855, 0x9F79, 0x4B39, { 0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3 } }, 5 };
    
    if (SUCCEEDED(pps->GetValue(kPKEY_AppUserModel_ID, &var)) && var.vt == VT_LPWSTR && var.pwszVal) {
        aumid = var.pwszVal;
    }
    
    PropVariantClear(&var);
    pps->Release();
    return aumid;
}

struct WinSearchData {
    std::wstring targetAUMID;
    HWND foundHwnd;
};

BOOL CALLBACK FindMusicWindowEnum(HWND hwnd, LPARAM lParam) {
    WinSearchData* search = (WinSearchData*)lParam;
    
    // Skip invisible windows
    if (!IsWindowVisible(hwnd)) return TRUE;
    
    // Skip windows that have owners (we want top-level apps)
    if (GetWindow(hwnd, GW_OWNER) != NULL) return TRUE;

    // Check if this window belongs to the Music Source
    std::wstring winId = GetWindowAUMID(hwnd);
    if (!winId.empty() && winId == search->targetAUMID) {
        // Found it!
        search->foundHwnd = hwnd;
        return FALSE; // Stop searching
    }
    return TRUE;
}

// Reworked ActivateSourceApp: hunt for an existing window for the AUMID, focus/restore it; fallback to ShellExecute
void ActivateSourceApp() {
    std::wstring targetId;
    {
        lock_guard<mutex> guard(g_MediaState.lock);
        targetId = g_MediaState.sourceId;
    }
    
    if (targetId.empty()) return;

    // Phase 1: Try to find the existing window
    WinSearchData search = { targetId, NULL };
    EnumWindows(FindMusicWindowEnum, (LPARAM)&search);

    if (search.foundHwnd) {
        // Window found! Restore and Focus.
        if (IsIconic(search.foundHwnd)) {
            ShowWindow(search.foundHwnd, SW_RESTORE);
        }
        SetForegroundWindow(search.foundHwnd);
    } else {
        // Phase 2: Window not found (maybe minimized to tray), fallback to Shell Activation
        std::wstring cmd = L"shell:AppsFolder\\" + targetId;
        ShellExecute(NULL, L"open", cmd.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
}

struct ConfiguredTrigger {
    std::wstring mouseTriggerName;
    uint32_t expectedModifiers;
    std::function<void()> action;
};

std::vector<ConfiguredTrigger> g_triggers;

// --- Additional Actions: Taskbar & Desktop Helpers ---

// Simple Key-Based Actions
void SendCtrlAltTabKeypress() {
    Wh_Log(L"Sending Ctrl+Alt+Tab");
    SendKeypress({VK_LCONTROL, VK_LMENU, VK_TAB});
}

void SendWinTabKeypress() {
    Wh_Log(L"Sending Win+Tab");
    SendKeypress({VK_LWIN, VK_TAB});
}

void OpenStartMenu() {
    Wh_Log(L"Sending Win keypress for Start menu");
    SendKeypress({VK_LWIN});
}

// Taskbar Auto-Hide
bool GetTaskbarAutohideState() {
    HWND hTaskbar = g_hTaskbar ? g_hTaskbar : FindWindow(L"Shell_TrayWnd", NULL);
    if (hTaskbar != NULL) {
        APPBARDATA msgData{};
        msgData.cbSize = sizeof(msgData);
        msgData.hWnd = hTaskbar;
        LPARAM state = SHAppBarMessage(ABM_GETSTATE, &msgData);
        return (state & ABS_AUTOHIDE) != 0;
    }
    return false;
}

void SetTaskbarAutohide(bool enabled) {
    HWND hTaskbar = g_hTaskbar ? g_hTaskbar : FindWindow(L"Shell_TrayWnd", NULL);
    if (hTaskbar != NULL) {
        APPBARDATA msgData{};
        msgData.cbSize = sizeof(msgData);
        msgData.hWnd = hTaskbar;
        msgData.lParam = enabled ? ABS_AUTOHIDE : ABS_ALWAYSONTOP;
        SHAppBarMessage(ABM_SETSTATE, &msgData);
    }
}

void ToggleTaskbarAutohide() {
    HWND hTaskbar = g_hTaskbar ? g_hTaskbar : FindWindow(L"Shell_TrayWnd", NULL);
    if (hTaskbar != NULL) {
        const bool isEnabled = GetTaskbarAutohideState();
        Wh_Log(L"Setting taskbar autohide to %s", isEnabled ? L"disabled" : L"enabled");
        SetTaskbarAutohide(!isEnabled);
    } else {
        Wh_Log(L"Failed to toggle taskbar autohide - taskbar not found");
    }
}

// Show Desktop & Hide Icons
void ShowDesktopViaTaskbar() {
    HWND hTaskbar = g_hTaskbar ? g_hTaskbar : FindWindow(L"Shell_TrayWnd", NULL);
    if (hTaskbar) {
        Wh_Log(L"Sending ShowDesktop message");
        SendMessage(hTaskbar, WM_COMMAND, MAKELONG(407, 0), 0);
    } else {
        Wh_Log(L"Failed to show desktop - taskbar not found");
    }
}

HWND FindDesktopShellView() {
    HWND hParentWnd = FindWindow(L"Progman", NULL);
    if (!hParentWnd) return NULL;
    HWND hChildWnd = FindWindowEx(hParentWnd, NULL, L"SHELLDLL_DefView", NULL);
    if (hChildWnd) return hChildWnd;
    HWND hWorker = NULL;
    while ((hWorker = FindWindowEx(NULL, hWorker, L"WorkerW", NULL)) != NULL) {
        HWND hDef = FindWindowEx(hWorker, NULL, L"SHELLDLL_DefView", NULL);
        if (hDef) return hDef;
    }
    return NULL;
}

void ToggleDesktopIcons() {
    HWND hDesktopWnd = FindDesktopShellView();
    if (hDesktopWnd != NULL) {
        Wh_Log(L"Toggling desktop icons");
        PostMessage(hDesktopWnd, WM_COMMAND, 0x7402, 0);
    } else {
        Wh_Log(L"Failed to find desktop window");
    }
}

// Taskbar Alignment (Windows 11)
DWORD GetTaskbarAlignment() {
    HKEY hKey = NULL;
    DWORD dwValue = 1; // Default to center
    DWORD dwBufferSize = sizeof(DWORD);

    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                     0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS) {
        RegQueryValueEx(hKey, TEXT("TaskbarAl"), NULL, NULL, (LPBYTE)&dwValue, &dwBufferSize);
        RegCloseKey(hKey);
    }
    return dwValue;
}

bool SetTaskbarAlignment(DWORD alignment) {
    HKEY hKey = NULL;
    bool success = false;

    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                     0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, TEXT("TaskbarAl"), 0, REG_DWORD, (BYTE*)&alignment, sizeof(alignment)) == ERROR_SUCCESS) {
            success = true;
        }
        RegCloseKey(hKey);
    }
    return success;
}

void ToggleTaskbarAlignment() {
    DWORD current = GetTaskbarAlignment();
    DWORD newAlign = (current == 0) ? 1 : 0;
    Wh_Log(L"Toggling taskbar alignment from %d to %d", current, newAlign);
    if (SetTaskbarAlignment(newAlign)) {
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    }
}

// Combine Taskbar Buttons
DWORD GetCombineTaskbarButtons(const wchar_t* optionName) {
    HKEY hKey = NULL;
    DWORD dwValue = 0;
    DWORD dwBufferSize = sizeof(DWORD);
    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                     0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS) {
        RegQueryValueEx(hKey, optionName, NULL, NULL, (LPBYTE)&dwValue, &dwBufferSize);
        RegCloseKey(hKey);
    }
    return dwValue;
}

bool SetCombineTaskbarButtons(const wchar_t* optionName, unsigned int option) {
    bool success = false;
    if (option <= 2) {
        HKEY hKey = NULL;
        if (RegOpenKeyEx(HKEY_CURRENT_USER,
                         TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                         0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
            DWORD dwValue = option;
            if (RegSetValueEx(hKey, optionName, 0, REG_DWORD, (BYTE*)&dwValue, sizeof(dwValue)) == ERROR_SUCCESS) {
                success = true;
            }
            RegCloseKey(hKey);
        }
    }
    return success;
}

void CombineTaskbarButtons(const std::wstring& args) {
    auto argsSplit = stringtools::split(args, L';');
    auto parseState = [](const std::wstring& arg) -> int {
        if (arg == L"COMBINE_ALWAYS") return 0;
        if (arg == L"COMBINE_WHEN_FULL") return 1;
        if (arg == L"COMBINE_NEVER") return 2;
        return -1;
    };
    int p1 = -1, p2 = -1, s1 = -1, s2 = -1;
    if (argsSplit.size() >= 1) p1 = parseState(argsSplit[0]);
    if (argsSplit.size() >= 2) p2 = parseState(argsSplit[1]);
    if (argsSplit.size() >= 3) s1 = parseState(argsSplit[2]);
    if (argsSplit.size() >= 4) s2 = parseState(argsSplit[3]);

    bool notify = false;

    if (p1 != -1 && p2 != -1) {
        static bool zigzag = (GetCombineTaskbarButtons(L"TaskbarGlomLevel") == (DWORD)p1);
        zigzag = !zigzag;
        notify |= SetCombineTaskbarButtons(L"TaskbarGlomLevel", zigzag ? p1 : p2);
    }
    if (s1 != -1 && s2 != -1) {
        static bool zigzag2 = (GetCombineTaskbarButtons(L"MMTaskbarGlomLevel") == (DWORD)s1);
        zigzag2 = !zigzag2;
        notify |= SetCombineTaskbarButtons(L"MMTaskbarGlomLevel", zigzag2 ? s1 : s2);
    }
    if (notify) {
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    }
}

std::function<void()> ParseAction(const std::wstring& actionName, const std::wstring& args) {
    if (actionName == L"ACTION_SHOW_DESKTOP") return [](){ ShowDesktopViaTaskbar(); };
    if (actionName == L"ACTION_TOGGLE_DESKTOP_ICONS") return [](){ ToggleDesktopIcons(); };
    if (actionName == L"ACTION_TOGGLE_TASKBAR_AUTOHIDE") return [](){ ToggleTaskbarAutohide(); };
    if (actionName == L"ACTION_TOGGLE_TASKBAR_ALIGNMENT") return [](){ ToggleTaskbarAlignment(); };
    if (actionName == L"ACTION_WIN_TAB") return [](){ SendWinTabKeypress(); };
    if (actionName == L"ACTION_CTRL_ALT_TAB") return [](){ SendCtrlAltTabKeypress(); };
    if (actionName == L"ACTION_OPEN_START_MENU") return [](){ OpenStartMenu(); };
    if (actionName == L"ACTION_COMBINE_TASKBAR_BUTTONS") return [args](){ CombineTaskbarButtons(args); };
    if (actionName == L"ACTION_MUTE") return [](){ ToggleVolMuted(); };
    if (actionName == L"ACTION_TASK_MANAGER") return [](){ ShellExecute(0, L"open", L"taskmgr.exe", 0, 0, SW_SHOW); };
    if (actionName == L"ACTION_ACTIVATE_SOURCE_APP") return [](){ ActivateSourceApp(); };
    if (actionName == L"ACTION_VOLUME_UP") return [](){ SendKeypress({VK_VOLUME_UP}); };
    if (actionName == L"ACTION_VOLUME_DOWN") return [](){ SendKeypress({VK_VOLUME_DOWN}); };
    if (actionName == L"ACTION_START_PROCESS") return [args](){ StartProcess(args); };
    if (actionName == L"ACTION_SEND_KEYPRESS") {
        std::vector<int> keys; 
        std::vector<std::wstring> parts;
        if (args.find(L';') != std::wstring::npos) parts = stringtools::split(args, L';');
        else parts = stringtools::split(args, L'+');
        
        for(auto& part : parts) {
            UINT mod, vk;
            if(FromStringHotKey(part, &mod, &vk)) {
                if(mod & MOD_CONTROL) keys.push_back(VK_CONTROL); if(mod & MOD_SHIFT) keys.push_back(VK_SHIFT);
                if(mod & MOD_ALT) keys.push_back(VK_MENU); if(mod & MOD_WIN) keys.push_back(VK_LWIN);
                if (vk) keys.push_back(vk);
            }
        }
        return [keys](){ SendKeypress(keys); };
    }
    if (actionName == L"ACTION_MEDIA_PLAY_PAUSE") return [](){ SendKeypress({VK_MEDIA_PLAY_PAUSE}); };
    if (actionName == L"ACTION_MEDIA_NEXT") return [](){ SendKeypress({VK_MEDIA_NEXT_TRACK}); };
    if (actionName == L"ACTION_MEDIA_PREV") return [](){ SendKeypress({VK_MEDIA_PREV_TRACK}); };
    return [](){};
}

bool OnMouseClick(const std::wstring& detectedTriggerName) {
    uint32_t currentMods = GetKeyModifiersState();
    bool handled = false;
    for(const auto& t : g_triggers) {
        if (t.mouseTriggerName == detectedTriggerName) {
            if (t.expectedModifiers == currentMods) {
                if (t.action) {
                    t.action();
                    Wh_Log(L"[MusicLounge] Trigger Executed: %s", detectedTriggerName.c_str());
                    handled = true;
                }
            }
        }
    }
    return handled;
}

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
#define IDT_RAINBOW_ANIM 1004

void UpdateScaleFactor() {
    if (g_hTaskbar) {
        UINT dpi = GetDpiForWindow(g_hTaskbar);
        if (dpi == 0) dpi = 96;
        g_ScaleFactor = dpi / 96.0f;
    }
}

void ForceParkedState() {
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int scaledW = (int)(g_Settings.width * g_ScaleFactor);
    int scaledH = (int)(g_Settings.height * g_ScaleFactor);
    SetWindowPos(g_hMediaWindow, HWND_TOPMOST, 0, screenH - 2, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_AnimState = 3; // Parked Mode
    
    // Park rainbow window too
    if (g_hRainbowWindow && g_Settings.enableRainbow) {
        int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
        SetWindowPos(g_hRainbowWindow, g_hMediaWindow, 0 - borderOffset, screenH - 2 - borderOffset, 
                     scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), SWP_NOACTIVATE | SWP_SHOWWINDOW);
        g_RainbowAnimState = 3;
    }
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
                    // Sync rainbow window animation
                    if (g_hRainbowWindow && g_Settings.enableRainbow) {
                        RECT rcRainbow; GetWindowRect(g_hRainbowWindow, &rcRainbow);
                        g_CurrentRainbowAnimY = rcRainbow.top;
                        g_RainbowAnimState = 1;
                    }
                } else {
                    ShowWindow(g_hMediaWindow, SW_HIDE);
                    if (g_hRainbowWindow && g_Settings.enableRainbow) {
                        ShowWindow(g_hRainbowWindow, SW_HIDE);
                    }
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
                 // Sync rainbow window
                 if (g_hRainbowWindow && g_Settings.enableRainbow) {
                     int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                     g_CurrentRainbowAnimY = (g_RainbowAnimState == 3) ? (screenH - 2 - borderOffset) : screenH;
                     SetWindowPos(g_hRainbowWindow, g_hMediaWindow, targetX - borderOffset, g_CurrentRainbowAnimY, 
                                  scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), SWP_NOACTIVATE | SWP_SHOWWINDOW);
                     g_RainbowAnimState = 2;
                 }
                 return;
            } else {
                ShowWindow(g_hMediaWindow, SW_SHOWNOACTIVATE);
                if (g_hRainbowWindow && g_Settings.enableRainbow) {
                    ShowWindow(g_hRainbowWindow, SW_SHOWNOACTIVATE);
                }
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
            // Sync rainbow window position
            if (g_hRainbowWindow && g_Settings.enableRainbow) {
                int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                SetWindowPos(g_hRainbowWindow, g_hMediaWindow, x - borderOffset, y - borderOffset,
                             scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), 
                             SWP_NOACTIVATE | SWP_SHOWWINDOW);
                g_RainbowAnimState = 0;
            } else if (g_hRainbowWindow) {
                ShowWindow(g_hRainbowWindow, SW_HIDE);
            }
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

    PCWSTR bgColorStr = Wh_GetStringSetting(L"BgColor");
    if (bgColorStr) {
        int r = 0, g = 0, b = 0, a = 0;
        int count = swscanf_s(bgColorStr, L"%d,%d,%d,%d", &r, &g, &b, &a);
        if(r>255) r=255; if(g>255) g=255; if(b>255) b=255;
        if(r<0) r=0; if(g<0) g=0; if(b<0) b=0;

        if (count >= 3 && !(r==0 && g==0 && b==0)) {
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

    g_IdleSecondsCounter = 0;
    g_IsHiddenByIdle = false;

    g_Settings.EnableTextScroll = Wh_GetIntSetting(L"EnableTextScroll") !=0;
    g_Settings.enableSlide = Wh_GetIntSetting(L"EnableSlide") != 0;
    g_Settings.enableGameDetect = Wh_GetIntSetting(L"EnableGameDetection") != 0;

    PCWSTR apps = Wh_GetStringSetting(L"IgnoredApps");
    if (apps) {
        g_Settings.ignoredApps = apps;
        Wh_FreeStringSetting(apps);
    } else {
        g_Settings.ignoredApps = L"firefox.exe;chrome.exe;msedge.exe";
    }

    g_Settings.enableRainbow = Wh_GetIntSetting(L"EnableRainbow") != 0;
    g_Settings.rainbowSpeed = Wh_GetIntSetting(L"RainbowSpeed");
    if (g_Settings.rainbowSpeed < 1) g_Settings.rainbowSpeed = 1;
    if (g_Settings.rainbowSpeed > 10) g_Settings.rainbowSpeed = 10;

    g_Settings.rainbowBrightness = Wh_GetIntSetting(L"RainbowBrightness");
    if (g_Settings.rainbowBrightness < 0) g_Settings.rainbowBrightness = 0;
    if (g_Settings.rainbowBrightness > 100) g_Settings.rainbowBrightness = 100;

    g_Settings.rainbowThickness = Wh_GetIntSetting(L"RainbowThickness");
    if (g_Settings.rainbowThickness < 1) g_Settings.rainbowThickness = 1;
    if (g_Settings.rainbowThickness > 10) g_Settings.rainbowThickness = 10;

    g_Settings.rainbowBorderOffset = Wh_GetIntSetting(L"RainbowBorderOffset");
    if (g_Settings.rainbowBorderOffset < 0) g_Settings.rainbowBorderOffset = 0;
    if (g_Settings.rainbowBorderOffset > 10) g_Settings.rainbowBorderOffset = 10;

    g_Settings.enableRoundedCorners = Wh_GetIntSetting(L"EnableRoundedCorners") != 0;

    if (g_Settings.bgOpacity < 0) g_Settings.bgOpacity = 0;
    if (g_Settings.bgOpacity > 255) g_Settings.bgOpacity = 255;
    if (g_Settings.width < 100) g_Settings.width = 400;
    if (g_Settings.height < 24) g_Settings.height = 48;

    // --- Load Action Engine Triggers ---
    using WindhawkUtils::StringSetting;
    g_triggers.clear();
    for (int i = 0; i < 50; i++) {
        auto mouseTriggerStr = std::wstring(StringSetting::make(L"TriggerActionOptions[%d].MouseTrigger", i).get());
        uint32_t mods = 0;
        for (int j = 0; j < 8; j++) {
            auto modStr = std::wstring(StringSetting::make(L"TriggerActionOptions[%d].KeyboardTriggers[%d]", i, j).get());
            if (modStr.empty()) break;
            if (modStr == L"none") continue;
            KeyModifier km = GetKeyModifierFromName(modStr);
            if (km != KEY_MODIFIER_INVALID) SetBit(mods, km);
        }
        auto actionStr = std::wstring(StringSetting::make(L"TriggerActionOptions[%d].Action", i).get());
        auto argsStr = std::wstring(StringSetting::make(L"TriggerActionOptions[%d].AdditionalArgs", i).get());
        if (mouseTriggerStr.empty() || actionStr.empty()) continue;
        ConfiguredTrigger ct;
        ct.mouseTriggerName = mouseTriggerStr;
        ct.expectedModifiers = mods;
        ct.action = ParseAction(actionStr, argsStr);
        g_triggers.push_back(ct);
    }
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
    DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));

    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (hUser) {
        auto SetComp = (pSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
        if (SetComp) {
            DWORD tint = 0; 
            if (g_Settings.manualBgColorRGB != 0) {
                tint = ((DWORD)g_Settings.bgOpacity << 24) | g_Settings.manualBgColorRGB;
            } else if (g_Settings.autoTheme) {
                tint = IsSystemLightMode() ? 0x40FFFFFF : 0x40000000; 
            } else {
                DWORD baseColor = g_Settings.invertTheme ? 0x000000 : 0xFFFFFF; 
                tint = ((DWORD)g_Settings.bgOpacity << 24) | baseColor;
            }
            ACCENT_POLICY policy = { ACCENT_ENABLE_ACRYLICBLURBEHIND, 0, tint, 0 };
            WINDOWCOMPOSITIONATTRIBDATA data = { WCA_ACCENT_POLICY, &policy, sizeof(ACCENT_POLICY) };
            SetComp(hwnd, &data);
        }
    }
}

// HSV to RGB conversion helper
void HSVtoRGB(float h, float s, float v, BYTE& r, BYTE& g, BYTE& b) {
    int hi = (int)(h / 60.0f) % 6;
    float f = (h / 60.0f) - hi;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);
    
    float rf, gf, bf;
    switch(hi) {
        case 0: rf = v; gf = t; bf = p; break;
        case 1: rf = q; gf = v; bf = p; break;
        case 2: rf = p; gf = v; bf = t; break;
        case 3: rf = p; gf = q; bf = v; break;
        case 4: rf = t; gf = p; bf = v; break;
        case 5: rf = v; gf = p; bf = q; break;
        default: rf = gf = bf = 0; break;
    }
    
    r = (BYTE)(rf * 255);
    g = (BYTE)(gf * 255);
    b = (BYTE)(bf * 255);
}

void DrawRainbowBorder(HDC hdc, int width, int height) {
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.Clear(Color(0, 0, 0, 0));
    graphics.ScaleTransform(g_ScaleFactor, g_ScaleFactor);
    
    int logicalW = (int)(width / g_ScaleFactor);
    int logicalH = (int)(height / g_ScaleFactor);
    
    // Draw flowing gradient on all 4 corners
    float baseHue = g_RainbowHue;
    float brightness = g_Settings.rainbowBrightness / 100.0f;
    float thickness = (float)g_Settings.rainbowThickness;
    
    // Create 4 corner gradients with offset hues
    for (int corner = 0; corner < 4; corner++) {
        float cornerHue = fmodf(baseHue + (corner * 90.0f), 360.0f);
        BYTE r, g, b;
        HSVtoRGB(cornerHue, 1.0f, brightness, r, g, b);
        Color cornerColor(r, g, b);
        
        // Calculate gradient positions based on corner
        PointF pt1, pt2;
        RectF gradRect;
        
        switch(corner) {
            case 0: // Top-left
                pt1 = PointF(0, 0);
                pt2 = PointF((float)logicalW / 2.0f, (float)logicalH / 2.0f);
                gradRect = RectF(0, 0, (float)logicalW / 2.0f, (float)logicalH / 2.0f);
                break;
            case 1: // Top-right
                pt1 = PointF((float)logicalW, 0);
                pt2 = PointF((float)logicalW / 2.0f, (float)logicalH / 2.0f);
                gradRect = RectF((float)logicalW / 2.0f, 0, (float)logicalW / 2.0f, (float)logicalH / 2.0f);
                break;
            case 2: // Bottom-left
                pt1 = PointF(0, (float)logicalH);
                pt2 = PointF((float)logicalW / 2.0f, (float)logicalH / 2.0f);
                gradRect = RectF(0, (float)logicalH / 2.0f, (float)logicalW / 2.0f, (float)logicalH / 2.0f);
                break;
            case 3: // Bottom-right
                pt1 = PointF((float)logicalW, (float)logicalH);
                pt2 = PointF((float)logicalW / 2.0f, (float)logicalH / 2.0f);
                gradRect = RectF((float)logicalW / 2.0f, (float)logicalH / 2.0f, (float)logicalW / 2.0f, (float)logicalH / 2.0f);
                break;
        }
        
        LinearGradientBrush gradBrush(pt1, pt2, cornerColor, Color(0, r, g, b));
        graphics.FillRectangle(&gradBrush, gradRect);
    }
    
    // Draw border outline with flowing gradient
    int stepSize = max(2, g_Settings.rainbowSpeed / 2); // Faster = fewer segments needed
    for (int i = 0; i < 360; i += stepSize) {
        float segmentHue = fmodf(baseHue + i, 360.0f);
        BYTE r, g, b;
        HSVtoRGB(segmentHue, 1.0f, brightness, r, g, b);
        
        Pen pen(Color(r, g, b), thickness);
        
        // Determine which edge this segment belongs to
        if (i < 90) {
            // Top edge
            float progress = i / 90.0f;
            float x1 = progress * logicalW;
            float x2 = (i + stepSize) / 90.0f * logicalW;
            graphics.DrawLine(&pen, PointF(x1, thickness/2), PointF(x2, thickness/2));
        } else if (i < 180) {
            // Right edge
            float progress = (i - 90) / 90.0f;
            float y1 = progress * logicalH;
            float y2 = (i + stepSize - 90) / 90.0f * logicalH;
            graphics.DrawLine(&pen, PointF(logicalW - thickness/2, y1), PointF(logicalW - thickness/2, y2));
        } else if (i < 270) {
            // Bottom edge
            float progress = (i - 180) / 90.0f;
            float x1 = logicalW - (progress * logicalW);
            float x2 = logicalW - ((i + stepSize - 180) / 90.0f * logicalW);
            graphics.DrawLine(&pen, PointF(x1, logicalH - thickness/2), PointF(x2, logicalH - thickness/2));
        } else {
            // Left edge
            float progress = (i - 270) / 90.0f;
            float y1 = logicalH - (progress * logicalH);
            float y2 = logicalH - ((i + stepSize - 270) / 90.0f * logicalH);
            graphics.DrawLine(&pen, PointF(thickness/2, y1), PointF(thickness/2, y2));
        }
    }
}

void DrawMediaPanel(HDC hdc, int width, int height) {
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);
    graphics.Clear(Color(0, 0, 0, 0)); 
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

        //Prev button
    int pX = startControlX;
    if (g_HoverState == 1) graphics.FillEllipse(&activeBg, pX - 8, controlY - 12, 24, 24);
    Point prevPts[3] = { Point(pX + 8, controlY - 6), Point(pX + 8, controlY + 6), Point(pX, controlY) };
    graphics.FillPolygon(g_HoverState == 1 ? &hoverBrush : &iconBrush, prevPts, 3);
    graphics.FillRectangle(g_HoverState == 1 ? &hoverBrush : &iconBrush, pX, controlY - 6, 2, 12);
        // Pause button
    int plX = startControlX + 28;
    if (g_HoverState == 2) graphics.FillEllipse(&activeBg, plX - 8, controlY - 12, 24, 24);
    if (state.isPlaying) {
        graphics.FillRectangle(g_HoverState == 2 ? &hoverBrush : &iconBrush, plX, controlY - 7, 3, 14);
        graphics.FillRectangle(g_HoverState == 2 ? &hoverBrush : &iconBrush, plX + 6, controlY - 7, 3, 14);
    } else {
        // Play button
        Point playPts[3] = { Point(plX, controlY - 8), Point(plX, controlY + 8), Point(plX + 10, controlY) };
        graphics.FillPolygon(g_HoverState == 2 ? &hoverBrush : &iconBrush, playPts, 3);
    }
        // Next button
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

    if (g_Settings.EnableTextScroll && g_TextWidth > textMaxW) {
        g_IsScrolling = true;
        float drawX = (float)(textX - g_ScrollOffset);
        graphics.DrawString(fullText.c_str(), -1, &font, PointF(drawX, textY), &textBrush);
        if (drawX + g_TextWidth < textX + textMaxW) {
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

LRESULT CALLBACK RainbowWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            // Make window transparent to mouse events
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
            if (g_Settings.enableRainbow) {
                SetTimer(hwnd, IDT_RAINBOW_ANIM, 16, NULL); // 60 FPS
            }
            // Apply corner rounding to match main window
            DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
            DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));
            return 0;
        }
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY: return 0;
        case WM_TIMER:
            if (wParam == IDT_RAINBOW_ANIM) {
                g_RainbowHue += (g_Settings.rainbowSpeed * 0.6f);
                if (g_RainbowHue >= 360.0f) g_RainbowHue -= 360.0f;
                InvalidateRect(hwnd, NULL, FALSE);
            }
            else if (wParam == IDT_VIS_ANIM) {
                int screenH = GetSystemMetrics(SM_CYSCREEN);
                RECT rcTb; GetWindowRect(g_hTaskbar, &rcTb);
                int scaledH = (int)(g_Settings.height * g_ScaleFactor);
                int scaledOffY = (int)(g_Settings.offsetY * g_ScaleFactor);
                int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                int targetY = rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY - borderOffset;
                
                if (g_RainbowAnimState == 1) { // Hide
                    if (!g_IsGameDetected && !g_IsHiddenByIdle) { g_RainbowAnimState = 2; return 0; }
                    g_CurrentRainbowAnimY += 8;
                    if (g_CurrentRainbowAnimY > screenH) {
                        ShowWindow(hwnd, SW_HIDE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_RainbowAnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_BOTTOM, rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        SetWindowPos(hwnd, g_hMediaWindow, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                else if (g_RainbowAnimState == 2) { // Show
                    if (g_IsGameDetected || g_IsHiddenByIdle) { g_RainbowAnimState = 1; return 0; }
                    g_CurrentRainbowAnimY -= 8;
                    if (g_CurrentRainbowAnimY <= targetY) {
                        g_CurrentRainbowAnimY = targetY;
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_BOTTOM, rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        SetWindowPos(hwnd, g_hMediaWindow, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_RainbowAnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, HWND_BOTTOM, rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        SetWindowPos(hwnd, g_hMediaWindow, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
            }
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps; HDC hdc = BeginPaint(hwnd, &ps);
            RECT rc; GetClientRect(hwnd, &rc);
            HDC memDC = CreateCompatibleDC(hdc);
            HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
            DrawRainbowBorder(memDC, rc.right, rc.bottom);
            BitBlt(hdc, 0, 0, rc.right, rc.bottom, memDC, 0, 0, SRCCOPY);
            SelectObject(memDC, oldBitmap); DeleteObject(memBitmap); DeleteDC(memDC);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

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
                UpdateMediaInfo();
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
                SyncPositionWithTaskbar();
                InvalidateRect(hwnd, NULL, FALSE);
            }
            else if (wParam == IDT_TEXT_ANIM) {
                if (g_IsScrolling && g_Settings.EnableTextScroll) {
                    if (g_ScrollWait > 0) g_ScrollWait--;
                    else {
                        g_ScrollOffset++;
                        if (g_ScrollOffset > g_TextWidth + 40) { g_ScrollOffset = 0; g_ScrollWait = 60; }
                        InvalidateRect(hwnd, NULL, FALSE);
                    }
                } else { 
                    KillTimer(hwnd, IDT_TEXT_ANIM);
                    g_ScrollOffset = 0;
                }
            }
            else if (wParam == IDT_VIS_ANIM) {
                int screenH = GetSystemMetrics(SM_CYSCREEN);
                RECT rcTb; GetWindowRect(g_hTaskbar, &rcTb);
                int scaledH = (int)(g_Settings.height * g_ScaleFactor);
                int scaledOffY = (int)(g_Settings.offsetY * g_ScaleFactor);
                int targetY = rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY;
                
                if (g_AnimState == 1) { // Hide
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
                // Sync rainbow animation timer
                if (g_hRainbowWindow && g_Settings.enableRainbow && (g_RainbowAnimState == 1 || g_RainbowAnimState == 2)) {
                    SetTimer(g_hRainbowWindow, IDT_VIS_ANIM, 16, NULL);
                }
            }
            return 0;
        case WM_MOUSEMOVE: {
            int x = (int)(LOWORD(lParam) / g_ScaleFactor);
            int y = (int)(HIWORD(lParam) / g_ScaleFactor);
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
                int x = (int)(LOWORD(lParam) / g_ScaleFactor);
                int artSize = g_Settings.height - 12;
                int artRightEdge = 6 + artSize + 5;
                if (x > artRightEdge) {
                    OnMouseClick(L"Left");
                }
            }
            return 0;
        case WM_RBUTTONUP: {
            int x = (int)(LOWORD(lParam) / g_ScaleFactor);
            int artSize = g_Settings.height - 12;
            int artRightEdge = 6 + artSize + 5;
            if (x > artRightEdge) { OnMouseClick(L"Right"); }
            return 0;
        }
        case WM_MBUTTONUP: {
            int x = (int)(LOWORD(lParam) / g_ScaleFactor);
            int artSize = g_Settings.height - 12;
            int artRightEdge = 6 + artSize + 5;
            if (x > artRightEdge) { OnMouseClick(L"Middle"); }
            return 0;
        }
        case WM_LBUTTONDBLCLK: {
            int x = (int)(LOWORD(lParam) / g_ScaleFactor);
            int artSize = g_Settings.height - 12;
            int artRightEdge = 6 + artSize + 5;
            if (x > artRightEdge) { OnMouseClick(L"Double"); }
            return 0;
        }
        case WM_MOUSEWHEEL: {
            short zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            bool handled = false;
            if (zDelta > 0) handled = OnMouseClick(L"ScrollUp");
            else handled = OnMouseClick(L"ScrollDown");
            
            if (!handled) {
                // Fallback to System Volume Control
                SendMessage(hwnd, WM_APPCOMMAND, 0, zDelta > 0 ? APPCOMMAND_VOLUME_UP << 16 : APPCOMMAND_VOLUME_DOWN << 16);
            }
            return 0;
        }
        case WM_PAINT: {
            PAINTSTRUCT ps; HDC hdc = BeginPaint(hwnd, &ps);
            RECT rc; GetClientRect(hwnd, &rc);
            HDC memDC = CreateCompatibleDC(hdc);
            HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
            DrawMediaPanel(memDC, rc.right, rc.bottom);
            if (g_IsScrolling && g_Settings.EnableTextScroll) {
                SetTimer(hwnd, IDT_TEXT_ANIM, 16, NULL);
            } else {
                KillTimer(hwnd, IDT_TEXT_ANIM);
            }
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
    winrt::init_apartment();
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    WNDCLASS wc = {0};
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = MediaWndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("WindhawkMusicLounge_GSMTC");
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    RegisterClass(&wc);

    // Register rainbow window class
    WNDCLASS wcRainbow = {0};
    wcRainbow.lpfnWndProc = RainbowWndProc;
    wcRainbow.hInstance = GetModuleHandle(NULL);
    wcRainbow.lpszClassName = TEXT("WindhawkMusicLounge_Rainbow");
    wcRainbow.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wcRainbow);

    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
    pCreateWindowInBand CreateWindowInBand = (pCreateWindowInBand)GetProcAddress(hUser32, "CreateWindowInBand");

    if (CreateWindowInBand) {
        g_hMediaWindow = CreateWindowInBand(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST, wc.lpszClassName, TEXT("MusicLounge"), WS_POPUP | WS_VISIBLE, 0, 0, g_Settings.width, g_Settings.height, NULL, NULL, wc.hInstance, NULL, ZBID_IMMERSIVE_NOTIFICATION);
    } else {
        g_hMediaWindow = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST, wc.lpszClassName, TEXT("MusicLounge"), WS_POPUP | WS_VISIBLE, 0, 0, g_Settings.width, g_Settings.height, NULL, NULL, wc.hInstance, NULL);
    }

    SetLayeredWindowAttributes(g_hMediaWindow, 0, 255, LWA_ALPHA);

    int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);

    // Create rainbow window
    if (CreateWindowInBand) {
        g_hRainbowWindow = CreateWindowInBand(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            wcRainbow.lpszClassName,
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            g_Settings.width + (borderOffset * 2),
            g_Settings.height + (borderOffset * 2),
            NULL, NULL, wcRainbow.hInstance, NULL,
            ZBID_IMMERSIVE_NOTIFICATION
        );
    } else {
        g_hRainbowWindow = CreateWindowEx(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            wcRainbow.lpszClassName,
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            g_Settings.width + (borderOffset * 2),
            g_Settings.height + (borderOffset * 2),
            NULL, NULL, wcRainbow.hInstance, NULL
        );
    }

    if (g_hRainbowWindow) {
        SetLayeredWindowAttributes(g_hRainbowWindow, 0, 255, LWA_ALPHA);
    }

    UpdateScaleFactor();
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int scaledW = (int)(g_Settings.width * g_ScaleFactor);
    int scaledH = (int)(g_Settings.height * g_ScaleFactor);
    SetWindowPos(g_hMediaWindow, HWND_TOPMOST, 0, screenH - 2, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_AnimState = 3; // Parked

    g_hVisibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) { TranslateMessage(&msg); DispatchMessage(&msg); }

    if (g_hVisibilityHook) UnhookWinEvent(g_hVisibilityHook);
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    if (g_hRainbowWindow) {
        UnregisterClass(wcRainbow.lpszClassName, wcRainbow.hInstance);
    }
    GdiplusShutdown(gdiplusToken);
    winrt::uninit_apartment();
}

std::thread* g_pMediaThread = nullptr;

BOOL WhTool_ModInit() {
    SetCurrentProcessExplicitAppUserModelID(L"taskbar-mouse-actions");
    LoadSettings();
    g_audioCOM.Init();
    g_Running = true;
    g_pMediaThread = new std::thread(MediaThread);
    return TRUE;
}

void WhTool_ModUninit() {
    g_audioCOM.Uninit();
    g_triggers.clear();

    g_Running = false;
    if (g_hRainbowWindow) SendMessage(g_hRainbowWindow, APP_WM_CLOSE, 0, 0);
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
    if (g_hRainbowWindow) {
        if (g_Settings.enableRainbow) {
            SetTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM, 16, NULL);
        } else {
            KillTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM);
            ShowWindow(g_hRainbowWindow, SW_HIDE);
        }
        InvalidateRect(g_hRainbowWindow, NULL, TRUE);
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