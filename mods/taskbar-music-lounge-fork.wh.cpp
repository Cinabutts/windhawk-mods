#pragma region Windhawk

// ==WindhawkMod==
// @id              taskbar-music-lounge-fork
// @name            Taskbar Music Lounge - Fork
// @description     A native-style music ticker with media controls and custom Action Triggers with delay support.
// @version         4.9.1
// @author          Hashah2311 | Cinabutts
// @github          https://github.com/Hashah2311
// @include         explorer.exe
// @compilerOptions -lole32 -ldwmapi -lgdi32 -luser32 -lwindowsapp -lshcore -lgdiplus -lshell32 -lpsapi -lcomctl32 -loleaut32 -lversion -lpropsys
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Music Lounge (v4.9.1)

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
Inspired by [@m1lhaus](https://github.com/m1lhaus)'s mod [taskbar-empty-space-clicks](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/taskbar-empty-space-clicks.wh.cpp)
as well as [@m417z](https://github.com/m417z)'s mod [keyboard-shortcut-actions](https://github.com/ramensoftware/windhawk-mods/blob/f016abc733a47b45faa02a0d8501a95304d96587/mods/keyboard-shortcut-actions.wh.cpp)

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

###                                                                  *Maintained with the help of AI and careful babysitting*

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
- AutoTheme: false
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
- BgColor: "0, 0, 0"
  $name: Manual Background Color Override (R, G, B)
  $description: Set to 0,0,0 to not override. Enter RGB values separated by commas (e.g; "102, 255, 255"). Alpha controlled below ↓
- BgOpacity: 20
  $name: Acrylic Tint Opacity (0-255)
  $description: Keep 0 for pure glass. Controls Alpha for Manual Background Color.
- TextColor: "240, 220, 240, 255"
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
- EnableRainbow: true
  $name: Enable Rainbow RGB Effect
  $description: >-
    ✓ Enabled | Adds a flowing rainbow gradient border beneath the widget.
    
    ✕ Disabled | No rainbow effect.
- RainbowAboveWidget: false
  $name: Rainbow Above Widget (Debug)
  $description: >-
      ✓ On | Draws rainbow above the main widget.
  
      ✕ Off | Draws rainbow below the main widget.
- RainbowSpeed: 4
  $name: Rainbow Speed (1-10)
  $description: Controls how fast the rainbow colors flow. Higher = faster.
- RainbowBrightness: 80
  $name: Rainbow Brightness (0-100)
  $description: Controls the brightness/intensity of the rainbow colors.
- RainbowThickness: 6
  $name: Rainbow Border Thickness (1-10 pixels)
  $description: Controls how thick the rainbow border appears.
- RainbowBorderOffset: 3
  $name: Rainbow Border Offset (0-10 pixels)
  $description: Distance between main widget and rainbow border.
- EnableAudioReactive: true
  $name: Audio Reactive Rainbow                        🚧    WORK IN PROGRESS    🚧
  $description: >-

    ✓ Enabled | Rainbow effect reacts to system audio levels.

    ✕ Disabled | Rainbow animates at fixed speed.
- AudioResponsiveness: 20
  $name: Audio Responsiveness (Smoothing)
  $description: Controls how quickly the effect reacts to audio changes (0 - 20). Higher values mean smoother but slower response.
- AudioThreshold: 80
  $name: Audio Threshold (0 - 100)
  $description: Minimum volume level required to trigger the effect.
- AudioRamp: 90
  $name: Audio Ramp (0 - 100)
  $description: Audio level treated as the lowest point in the spectrum.
- AudioBinary: false
  $name: Binary Animation
  $description: >-
    ✓ On | Audio over threshold sets value to maximum.
    
    ✕ Off | Audio scales continuously.
- AudioFlicker: 0
  $name: Min Result (Flicker Control) 0-100
  $description: Result values below this ratio will trigger the range minimum.
- AudioDynamicRange: false
  $name: Dynamic Range / Advanced Mode
  $description: >-
    ✓ On | Map audio to full range using these advanced settings.
    
    ✕ Off | Use legacy simple smoothing logic.
- AudioMinValue: 99
  $name: Min Value (0 - 100)
  $description: The minimum output value % when audio is low.
- AudioMaxValue: 100
  $name: Max Value (0 - 100)
  $description: The maximum output value % when audio is high.
- AudioHueReactiveMode: 2
  $name: Audio Hue Reactive Mode
  $description: >-
    Audio-driven hue effects for rainbow border
     0:   Off
     1:   Speed Boost
     2:   Pulse (Color Jump)
     3:   Bounce (Direction Reverse)
     4:   Speed Boost + Pulse
     5:   Speed Boost + Bounce
     6:   Pulse + Bounce
     7:   All Effects

- Triggers:
  - - MouseTrigger: Double
      $name: Mouse Trigger
      $description: The mouse button or wheel action to detect.
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
    - Actions:
      - - Action: ACTION_ACTIVATE_SOURCE_APP
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
          - ACTION_OPEN_START_MENU: Open Start Menu
          - ACTION_TASK_MANAGER: Open Task Manager
          - ACTION_TOGGLE_AUDIO_REACTIVE: Toggle Audio Reactive Rainbow
          - ACTION_TOGGLE_RAINBOW_ZORDER: Toggle Rainbow Z-Order (Above/Below)
        - AdditionalArgs: ""
          $name: Arguments
          $description: >-
                    Delay (optional): Prefix with seconds followed by colon (max 9999 seconds)
                        2:calc.exe → waits 2 seconds  |  calc.exe → instant
                        Syntax: SECONDS:argument (e.g., "5.5:calc.exe" or "10:Ctrl+V")
                    
                    Arguments by action:
                        Open App: 2:calc.exe or notepad.exe
                        Keystrokes: 0.5:Ctrl+C or Win+Tab (use + or ;)
                        Combine Buttons: 1:COMBINE_ALWAYS;COMBINE_NEVER (2 or 4 states)
                        Volume/Media/Desktop/Taskbar: 3: (delay only, no args needed)
      $name: Actions
      $description: Add multiple actions to execute when this trigger fires. Actions run in order.
  - - MouseTrigger: ScrollUp
    - KeyboardTriggers: [none]
    - Actions:
      - - Action: ACTION_VOLUME_UP
        - AdditionalArgs: ""
  - - MouseTrigger: ScrollDown
    - KeyboardTriggers: [none]
    - Actions:
      - - Action: ACTION_VOLUME_DOWN
        - AdditionalArgs: ""
  $name: Triggers
  $description: Configure mouse/keyboard triggers and the actions they execute.
*/
// ==/WindhawkModSettings==

#pragma endregion Windhawk // ^Windhawk Readme/Metadata/Settings

//! =====================================================================

#pragma region includes
// Windows Core
#include <windows.h>
#include <windef.h>
#include <winerror.h>
#include <winuser.h>
// Windows Shell & UI
#include <shellapi.h>
#include <shlobj.h>
#include <shobjidl.h>
#include <commctrl.h>
#include <dwmapi.h>
#include <shcore.h>
// Windows Media & Audio
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <propsys.h>
#include <propkey.h>
// Graphics
#include <gdiplus.h>
// Process & System
#include <psapi.h>
// C++ Standard Library
#include <algorithm>
#include <cstdio>
#include <cwctype>
#include <functional>
#include <mutex>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <vector>
// WinRT (Windows Runtime for GSMTC media control)
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
// Windhawk
#include <windhawk_utils.h>

// Standard Library (common types used throughout)
using namespace std;
// Graphics (GDI+)
using namespace Gdiplus;
// WinRT namespaces (required for media control)
using namespace winrt;
using namespace Windows::Media::Control;
using namespace Windows::Storage::Streams;
using winrt::com_ptr;

#pragma endregion  //^ includes

//! =====================================================================

#pragma region types_and_globals

// --- Forward Declarations ---
HWND EnsureTaskbarHandle();
HWND GetMediaZOrderInsertAfter();
HWND GetRainbowZOrderInsertAfter();
void UpdateScaleFactor();
void SyncPositionWithTaskbar();
void ForceDockedState();

// Settings & Appearance
void LoadSettings();
void ValidateSettings();
void UpdateAppearance(HWND hwnd);

// Action Engine
void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds);
bool OnMouseClick(const std::wstring& detectedTriggerName);

// --- Timer IDs ---
#define IDT_POLL_MEDIA      1001  // Media state polling
#define IDT_TEXT_ANIM       1002  // Text scroll animation
#define IDT_VIS_ANIM        1003  // Visibility/slide animation
#define IDT_RAINBOW_ANIM    1004  // Rainbow border animation
#define IDT_DELAYED_ACTIONS 1005  // Delayed action execution

// --- Timer Intervals (milliseconds) ---
#define TIMER_ANIMATION_MS       16   // ~60 FPS for smooth animations
#define TIMER_MEDIA_POLL_MS      1000 // 1 second media state poll
#define TIMER_TEXT_ANIM_MS       16   // ~60 FPS text scroll
#define TIMER_DELAYED_ACTIONS_MS 50   // Delayed action check interval

// --- Custom Window Messages ---
#define APP_WM_CLOSE WM_APP  // Custom close message for cleanup

// --- Audio Reactive Mode Flags ---
#define kAudioReactiveMode     3  // 1=Brightness, 2=Thickness, 3=Both
#define kAudioHueReactiveMode  0  // 0=Off, 1-7=Various combos (see settings)

// --- UI Constants ---
static const WCHAR* kFontName = L"Segoe UI Variable Display";

// --- Audio Reactive Tuning ---
static const float kAudioSensitivity       = 1.5f;   // Overall sensitivity multiplier
static const float kAudioSmoothing         = 0.25f;  // Lerp factor for smoothing
static const float kAudioHueSpeedBoost     = 2.5f;   // Rainbow speed multiplier during audio
static const float kAudioHuePulseAmount    = 180.0f; // Degrees of hue shift per peak
static const float kAudioHueBounceThreshold = 0.65f; // Peak threshold for direction bounce

// --- Template Utilities ---

/// Clamps value v between min and max bounds
template<typename T>
T Clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

/// Linear interpolation: returns a + f * (b - a)
template<typename T>
T Lerp(T a, T b, T f) {
    return a + f * (b - a);
}

// --- Audio Metering Interface (Windows Core Audio) ---
// Used for real-time audio peak level detection for reactive effects
static const GUID IID_IAudioMeterInformation = {
    0xC02216F6, 0x8C67, 0x4B5B,
    {0x9D, 0x00, 0xD0, 0x08, 0xE7, 0x3E, 0x00, 0x64}
};

interface IAudioMeterInformation : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetPeakValue(float *pfPeak) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetMeteringChannelCount(UINT *pnChannelCount) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetChannelsPeakValues(UINT u32ChannelCount, float *afPeakValues) = 0;
    virtual HRESULT STDMETHODCALLTYPE QueryHardwareSupport(DWORD *pdwHardwareSupportMask) = 0;
};

// --- DWM Composition Attribute API ---
// Used for acrylic blur and window composition effects
typedef enum _WINDOWCOMPOSITIONATTRIB { 
    WCA_ACCENT_POLICY = 19 
} WINDOWCOMPOSITIONATTRIB;

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
// Used for creating windows in special z-order bands
typedef HWND(WINAPI* pCreateWindowInBand)(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID, DWORD);
enum ZBID { ZBID_IMMERSIVE_NOTIFICATION = 4 };

//! ============================================================================
//^ SETTINGS STRUCTURE
//! ============================================================================

/// User-configurable mod settings loaded from Windhawk UI
struct ModSettings {
    // --- Dimensions & Position ---
    int width = 400;              // Widget width in pixels
    int height = 35;              // Widget height in pixels
    int fontSize = 13;            // Text font size
    int offsetX = 140;            // Horizontal offset from taskbar edge
    int offsetY = 0;              // Vertical offset from taskbar center
    
    // --- Theme & Colors ---
    bool autoTheme = true;        // Auto-detect light/dark theme
    bool invertTheme = false;     // Invert detected theme
    DWORD manualTextColor = 0xFFFFFFFF;  // Manual text color (ARGB)
    DWORD manualBgColorRGB = 0;   // Manual background color (BGR for DWM)
    int bgOpacity = 0;            // Background opacity (0-255)
    
    // --- Behavior ---
    int fsInterval = 2;           // Fullscreen check interval (seconds)
    int idleTimeout = 0;          // Hide after N seconds idle (0=disabled)
    bool EnableTextScroll = true; // Enable text scrolling for long titles
    bool enableSlide = true;      // Enable slide animation
    bool enableGameDetect = true; // Detect fullscreen apps
    wstring ignoredApps;          // Comma-separated list of ignored apps
    
    // --- Rainbow Border ---
    bool enableRainbow = false;         // Enable rainbow border effect
    bool rainbowAboveWidget = false;    // Render rainbow above media widget
    bool enableAudioReactive = false;   // Audio-reactive rainbow effects
    int rainbowSpeed = 3;               // Rainbow hue rotation speed
    int rainbowBrightness = 80;         // Rainbow brightness (0-100)
    int rainbowThickness = 1;           // Border thickness in pixels
    int rainbowBorderOffset = 0;        // Border position offset
    bool enableRoundedCorners = true;   // Rounded corners on border
    
    // Internal state (not user-configurable)
    bool storedRainbowAboveWidget = false;

    // --- Advanced Audio Processing ---
    int audioResponsiveness = 20;       // How quickly audio reacts
    int audioThreshold = 80;            // Audio activation threshold
    int audioRamp = 50;                 // Ramp-up speed
    bool audioBinary = false;           // Binary on/off mode
    int audioFlicker = 99;              // Anti-flicker setting
    bool audioDynamicRange = true;      // Use dynamic range processing
    int audioMinValue = 100;            // Min output value
    int audioMaxValue = 100;            // Max output value
    int audioHueReactiveMode = 0;       // Hue reactive mode (0-7)
} g_Settings;

//! ============================================================================
//^ GLOBAL STATE
//! ============================================================================

// --- Window Handles ---
HWND g_hMediaWindow = NULL;      // Main media widget window
HWND g_hTaskbar = NULL;          // Windows taskbar handle
HWND g_hRainbowWindow = NULL;    // Rainbow border overlay window
HWINEVENTHOOK g_hVisibilityHook = NULL;  // Taskbar visibility hook

// --- Runtime Flags ---
bool g_Running = true;           // Main loop control flag
bool g_ShutdownMode = false;     // Graceful shutdown in progress

// --- UI State ---
int g_HoverState = 0;            // Current hover/click state (0=none, 1-3=buttons)
float g_ScaleFactor = 1.0f;      // DPI scaling factor

// --- Visibility & Animation State ---
bool g_IsGameDetected = false;   // Fullscreen game/app detected
int g_FsCheckTick = 0;           // Fullscreen check counter
int g_AnimState = 0;             // 0=Sync, 1=Hiding, 2=Showing, 3=Shutdown/Docked
int g_CurrentAnimY = 0;          // Current Y position during animation
int g_IdleSecondsCounter = 0;    // Seconds since last activity
bool g_IsHiddenByIdle = false;   // Hidden due to idle timeout

// --- Rainbow Effect State ---
float g_RainbowHue = 0.0f;       // Current hue angle (0-360)
int g_RainbowAnimState = 0;      // Rainbow window animation state
int g_CurrentRainbowAnimY = 0;   // Rainbow Y position during animation
ULONG_PTR g_gdiplusToken = 0;    // GDI+ initialization token
bool g_RainbowDirectionReverse = false;  // Direction for bounce effect

// --- Audio Reactive State ---
float g_AudioPeakLevel = 0.0f;          // Current audio peak (0.0-1.0)
float g_AudioPeakSmoothed = 0.0f;       // Smoothed audio peak
bool g_AudioReactiveRuntimeEnabled = true;  // Runtime enable flag

// --- Media State ---
struct MediaState {
    wstring title = L"Waiting for media...";
    wstring artist = L"";
    bool isPlaying = false;
    bool hasMedia = false;
    Bitmap* albumArt = nullptr;
    wstring sourceId = L"";
    mutex lock;
} g_MediaState;

// --- Text Scrolling State ---
int g_ScrollOffset = 0;          // Current scroll position
int g_TextWidth = 0;             // Measured text width
bool g_IsScrolling = false;      // Currently scrolling
int g_ScrollWait = 60;           // Pause frames at scroll start

// --- String Utilities ---

namespace stringtools {
    /// Trim leading and trailing whitespace from string
    std::wstring trim(const std::wstring& s) {
        auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::iswspace(c); });
        auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::iswspace(c); }).base();
        return (wsback <= wsfront) ? std::wstring() : std::wstring(wsfront, wsback);
    }
    
    /// Split string by delimiter and trim each token
    std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter) {
        std::vector<std::wstring> tokens;
        std::wstring token;
        std::wstringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            std::wstring trimmed = trim(token);
            if (!trimmed.empty()) {
                tokens.push_back(trimmed);
            }
        }
        return tokens;
    }
    
    /// Convert string to lowercase
    std::wstring toLower(const std::wstring& s) {
        std::wstring result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::towlower);
        return result;
    }
}

// --- Audio COM API Wrapper ---

/// Manages COM-based audio metering for reactive effects
class AudioCOMAPI {
public:
    AudioCOMAPI() 
        : m_isInitialized(false)
        , m_isCOMInitialized(false)
        , m_pDeviceEnumerator(nullptr)
        , m_pAudioMeter(nullptr)
        , m_meterInitialized(false) 
    {}
    
    /// Initialize COM and device enumerator
    bool Init() {
        if (!m_isCOMInitialized) {
            if (SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED))) {
                m_isCOMInitialized = true;
            } else {
                return false;
            }
        }
        
        if (!m_isInitialized && m_isCOMInitialized) {
            const GUID XIID_IMMDeviceEnumerator = {
                0xA95664D2, 0x9614, 0x4F35, 
                {0xA7, 0x46, 0xDE, 0x8D, 0xB6, 0x36, 0x17, 0xE6}
            };
            const GUID XIID_MMDeviceEnumerator = {
                0xBCDE0395, 0xE52F, 0x467C, 
                {0x8E, 0x3D, 0xC4, 0x57, 0x92, 0x91, 0x69, 0x2E}
            };
            
            if (FAILED(CoCreateInstance(
                    XIID_MMDeviceEnumerator, NULL, CLSCTX_INPROC_SERVER, 
                    XIID_IMMDeviceEnumerator, m_pDeviceEnumerator.put_void())) 
                || !m_pDeviceEnumerator) {
                return false;
            }
            m_isInitialized = true;
        }
        return m_isInitialized;
    }
    bool InitMeter() {
        if (m_meterInitialized) return true;
        if (!m_isInitialized) return false;
        
        com_ptr<IMMDevice> pDevice;
        if (FAILED(m_pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, pDevice.put()))) {
            Wh_Log(L"[Audio Meter] Failed to get default audio endpoint");
            return false;
        }
        
        if (FAILED(pDevice->Activate(IID_IAudioMeterInformation, CLSCTX_INPROC_SERVER, NULL, m_pAudioMeter.put_void()))) {
            Wh_Log(L"[Audio Meter] Failed to activate IAudioMeterInformation");
            return false;
        }
        
        m_meterInitialized = true;
        Wh_Log(L"[Audio Meter] Successfully initialized");
        return true;
    }
    
    /// Get current audio peak level (0.0-1.0)
    float GetPeakLevel() {
        if (!m_meterInitialized || !m_pAudioMeter) return 0.0f;
        float peak = 0.0f;
        if (SUCCEEDED(m_pAudioMeter->GetPeakValue(&peak))) {
            return peak;
        }
        return 0.0f;
    }
    
    /// Release all COM resources
    void Uninit() {
        if (m_pAudioMeter) {
            m_pAudioMeter = nullptr;
            m_meterInitialized = false;
            Wh_Log(L"[Audio Meter] Released IAudioMeterInformation");
        }
        if (m_isInitialized) {
            m_pDeviceEnumerator = nullptr;
            m_isInitialized = false;
            Wh_Log(L"[Audio Meter] Released IMMDeviceEnumerator");
        }
        if (m_isCOMInitialized) {
            CoUninitialize();
            m_isCOMInitialized = false;
            Wh_Log(L"[Audio Meter] COM uninitialized");
        }
    }
    
    bool IsInitialized() const { return m_isInitialized; }
    const com_ptr<IMMDeviceEnumerator>& GetDeviceEnumerator() const { return m_pDeviceEnumerator; }

private:
    bool m_isInitialized;
    bool m_isCOMInitialized;
    com_ptr<IMMDeviceEnumerator> m_pDeviceEnumerator;
    com_ptr<IAudioMeterInformation> m_pAudioMeter;
    bool m_meterInitialized;
};

static AudioCOMAPI g_audioCOM;

#pragma endregion  // ^types_and_globals

//! =====================================================================

#pragma region action_engine

/// Keyboard modifier key identifiers
enum KeyModifier {
    KEY_MODIFIER_LCTRL = 0,
    KEY_MODIFIER_RCTRL,
    KEY_MODIFIER_LALT,
    KEY_MODIFIER_RALT,
    KEY_MODIFIER_LSHIFT,
    KEY_MODIFIER_RSHIFT,
    KEY_MODIFIER_LWIN,
    KEY_MODIFIER_INVALID
};

/// Set a specific bit in a value (for modifier bitmask)
inline void SetBit(uint32_t& value, uint32_t bit) { 
    value |= (1U << bit); 
}

/// Get current state of all modifier keys as bitmask
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

/// Convert modifier name string to enum value
KeyModifier GetKeyModifierFromName(const std::wstring& keyName) {
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
    if (!g_audioCOM.IsInitialized()) {
        if (!g_audioCOM.Init()) {
            Wh_Log(L"WARNING: Audio COM not initialized, cannot toggle mute");
            return;
        }
    }
    auto pDeviceEnumerator = g_audioCOM.GetDeviceEnumerator();
    if (!pDeviceEnumerator) {
        Wh_Log(L"WARNING: Device enumerator not available");
        return;
    }
    
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

// Helper: get AUMID from a window  - used to identify source app
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
    std::vector<std::function<void()>> actions;  // Multiple actions per trigger
};

std::vector<ConfiguredTrigger> g_triggers;

// --- Delayed Action Execution ---

/// Pending action for deferred execution
struct PendingAction {
    std::function<void()> action;
    DWORD executeAtTick;
};

std::vector<PendingAction> g_pendingActions;
std::mutex g_pendingActionsMutex;

// --- Taskbar & Desktop Helpers ---

void SendWinTabKeypress() {
    Wh_Log(L"Sending Win+Tab");
    SendKeypress({VK_LWIN, VK_TAB});
}

void OpenStartMenu() {
    Wh_Log(L"Sending Win keypress for Start menu");
    SendKeypress({VK_LWIN});
}

// Forward declaration - defined later
HWND EnsureTaskbarHandle();

// Taskbar Auto-Hide
bool GetTaskbarAutohideState() {
    HWND hTaskbar = EnsureTaskbarHandle();
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
    HWND hTaskbar = EnsureTaskbarHandle();
    if (hTaskbar != NULL) {
        APPBARDATA msgData{};
        msgData.cbSize = sizeof(msgData);
        msgData.hWnd = hTaskbar;
        msgData.lParam = enabled ? ABS_AUTOHIDE : ABS_ALWAYSONTOP;
        SHAppBarMessage(ABM_SETSTATE, &msgData);
    }
}

void ToggleTaskbarAutohide() {
    HWND hTaskbar = EnsureTaskbarHandle();
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
    HWND hTaskbar = EnsureTaskbarHandle();
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

// --- Registry Helpers ---
DWORD GetExplorerAdvancedSetting(const wchar_t* valueName, DWORD defaultValue = 0) {
    HKEY hKey = NULL;
    DWORD dwValue = defaultValue;
    DWORD dwBufferSize = sizeof(DWORD);
    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                     0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegQueryValueEx(hKey, valueName, NULL, NULL, (LPBYTE)&dwValue, &dwBufferSize) != ERROR_SUCCESS) {
             // Use default if value missing
        }
        RegCloseKey(hKey);
    }
    return dwValue;
}

bool SetExplorerAdvancedSetting(const wchar_t* valueName, DWORD value) {
    HKEY hKey = NULL;
    bool success = false;
    if (RegOpenKeyEx(HKEY_CURRENT_USER,
                     TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"),
                     0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueEx(hKey, valueName, 0, REG_DWORD, (BYTE*)&value, sizeof(value)) == ERROR_SUCCESS) {
            success = true;
        }
        RegCloseKey(hKey);
    }
    return success;
}

// Centralized taskbar handle acquisition with validation
HWND EnsureTaskbarHandle() {
    // Validate existing handle (checks if window still exists)
    if (g_hTaskbar && IsWindow(g_hTaskbar)) {
        return g_hTaskbar;
    }
    
    // Find and cache new handle
    g_hTaskbar = FindWindowW(L"Shell_TrayWnd", NULL);
    
    if (g_hTaskbar) {
        Wh_Log(L"Taskbar handle acquired: 0x%p", g_hTaskbar);
    } else {
        Wh_Log(L"WARNING: Failed to find taskbar window");
    }
    
    return g_hTaskbar;  // May be NULL
}

// Taskbar Alignment (Windows 11)
void ToggleTaskbarAlignment() {
    DWORD current = GetExplorerAdvancedSetting(L"TaskbarAl", 1);
    DWORD newAlign = (current == 0) ? 1 : 0;
    Wh_Log(L"Toggling taskbar alignment from %d to %d", current, newAlign);
    if (SetExplorerAdvancedSetting(L"TaskbarAl", newAlign)) {
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    }
}

// Combine Taskbar Buttons
enum TaskBarButtonsState {
    COMBINE_ALWAYS = 0,
    COMBINE_WHEN_FULL,
    COMBINE_NEVER,
    COMBINE_INVALID
};

std::tuple<TaskBarButtonsState, TaskBarButtonsState, TaskBarButtonsState, TaskBarButtonsState> ParseTaskbarButtonsState(const std::wstring& args) {
    TaskBarButtonsState primary1 = COMBINE_INVALID;
    TaskBarButtonsState primary2 = COMBINE_INVALID;
    TaskBarButtonsState secondary1 = COMBINE_INVALID;
    TaskBarButtonsState secondary2 = COMBINE_INVALID;

    const auto argsSplit = stringtools::split(args, L';');
    if (!(argsSplit.size() == 2 || argsSplit.size() == 4)) {
        Wh_Log(L"CombineTaskbarButtons expects 2 or 4 COMBINE_* states; got %u", (unsigned)argsSplit.size());
    }

    auto parseState = [](const std::wstring& arg) -> TaskBarButtonsState {
        if (arg == L"COMBINE_ALWAYS") return COMBINE_ALWAYS;
        if (arg == L"COMBINE_WHEN_FULL") return COMBINE_WHEN_FULL;
        if (arg == L"COMBINE_NEVER") return COMBINE_NEVER;
        Wh_Log(L"Unknown taskbar combine state '%s'", arg.c_str());
        return COMBINE_INVALID;
    };

    if (argsSplit.size() >= 1) primary1 = parseState(argsSplit[0]);
    if (argsSplit.size() >= 2) primary2 = parseState(argsSplit[1]);
    if (argsSplit.size() >= 3) secondary1 = parseState(argsSplit[2]);
    if (argsSplit.size() >= 4) secondary2 = parseState(argsSplit[3]);

    return std::make_tuple(primary1, primary2, secondary1, secondary2);
}

void CombineTaskbarButtonsInternal(const TaskBarButtonsState primary1, const TaskBarButtonsState primary2,
                                   const TaskBarButtonsState secondary1, const TaskBarButtonsState secondary2) {
    bool notify = false;

    if ((primary1 != COMBINE_INVALID) && (primary2 != COMBINE_INVALID)) {
        static bool zigzagPrimary = (GetExplorerAdvancedSetting(L"TaskbarGlomLevel") == (DWORD)primary1);
        zigzagPrimary = !zigzagPrimary;
        notify |= SetExplorerAdvancedSetting(L"TaskbarGlomLevel", zigzagPrimary ? (unsigned)primary1 : (unsigned)primary2);
    }
    if ((secondary1 != COMBINE_INVALID) && (secondary2 != COMBINE_INVALID)) {
        static bool zigzagSecondary = (GetExplorerAdvancedSetting(L"MMTaskbarGlomLevel") == (DWORD)secondary1);
        zigzagSecondary = !zigzagSecondary;
        notify |= SetExplorerAdvancedSetting(L"MMTaskbarGlomLevel", zigzagSecondary ? (unsigned)secondary1 : (unsigned)secondary2);
    }

    if (notify) {
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    }
}

void CombineTaskbarButtons(const std::wstring& args) {
    const auto [primary1, primary2, secondary1, secondary2] = ParseTaskbarButtonsState(args);
    CombineTaskbarButtonsInternal(primary1, primary2, secondary1, secondary2);
}

// --- Argument Parsing with Delay Support ---
struct ParsedArgs {
    float delaySeconds;
    std::wstring actualArgs;
};

ParsedArgs ParseArgumentsWithDelay(const std::wstring& rawArgs) {
    ParsedArgs result{0.0f, rawArgs};
    if (rawArgs.empty()) return result;

    // Only split if colon appears within first 5 characters (prevents accidental splits)
    // e.g. "2.5:..." or "9999:..." are valid, but "path:file:with:colons" is not
    size_t colonPos = rawArgs.find(L':');
    if (colonPos == std::wstring::npos || colonPos > 5) return result;

    std::wstring prefix = stringtools::trim(rawArgs.substr(0, colonPos));
    
    // Quick validation: prefix should only contain digits and optional decimal point
    if (prefix.find_first_not_of(L"0123456789.") != std::wstring::npos) {
        return result; // Not a clean number, treat as normal arg
    }

    try {
        size_t processed = 0;
        float delay = std::stof(prefix, &processed);
        // Ensure the entire prefix was consumed (valid number)
        if (processed == prefix.length()) {
            result.delaySeconds = std::max(0.0f, delay);
            result.actualArgs = rawArgs.substr(colonPos + 1);
        }
    } catch (...) {
        // Conversion failed, fallback: treat entire string as argument
    }
    return result;
}

void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds);

// Forward Declarations for Z-Order Helpers
HWND GetMediaZOrderInsertAfter();
HWND GetRainbowZOrderInsertAfter();

std::vector<int> BuildKeypressSequence(const std::wstring& args) {
    std::vector<int> keys;
    const bool useSemicolonDelimiter = args.find(L';') != std::wstring::npos;
    const auto parts = useSemicolonDelimiter ? stringtools::split(args, L';') : stringtools::split(args, L'+');

    for (const auto& part : parts) {
        UINT mod = 0;
        UINT vk = 0;
        if (FromStringHotKey(part, &mod, &vk)) {
            if (mod & MOD_CONTROL) keys.push_back(VK_CONTROL);
            if (mod & MOD_SHIFT) keys.push_back(VK_SHIFT);
            if (mod & MOD_ALT) keys.push_back(VK_MENU);
            if (mod & MOD_WIN) keys.push_back(VK_LWIN);
            if (vk) keys.push_back(static_cast<int>(vk));
        }
    }

    return keys;
}

std::function<void()> ParseAction(const std::wstring& actionName, const std::wstring& rawArgs) {
    ParsedArgs parsed = ParseArgumentsWithDelay(rawArgs);
    const std::wstring& args = parsed.actualArgs;
    const float delay = parsed.delaySeconds;
    using ActionFactory = std::function<std::function<void()>(const std::wstring&)>;

    static const std::unordered_map<std::wstring_view, ActionFactory> kActionFactories = {
        {L"ACTION_SHOW_DESKTOP", [](const std::wstring&) { return []() { ShowDesktopViaTaskbar(); }; }},
        {L"ACTION_TOGGLE_DESKTOP_ICONS", [](const std::wstring&) { return []() { ToggleDesktopIcons(); }; }},
        {L"ACTION_TOGGLE_TASKBAR_AUTOHIDE", [](const std::wstring&) { return []() { ToggleTaskbarAutohide(); }; }},
        {L"ACTION_TOGGLE_TASKBAR_ALIGNMENT", [](const std::wstring&) { return []() { ToggleTaskbarAlignment(); }; }},
        {L"ACTION_WIN_TAB", [](const std::wstring&) { return []() { SendWinTabKeypress(); }; }},
        {L"ACTION_OPEN_START_MENU", [](const std::wstring&) { return []() { OpenStartMenu(); }; }},
        {L"ACTION_COMBINE_TASKBAR_BUTTONS", [](const std::wstring& input) { return [input]() { CombineTaskbarButtons(input); }; }},
        {L"ACTION_MUTE", [](const std::wstring&) { return []() { ToggleVolMuted(); }; }},
        {L"ACTION_TASK_MANAGER", [](const std::wstring&) { return []() { ShellExecute(0, L"open", L"taskmgr.exe", 0, 0, SW_SHOW); }; }},
        {L"ACTION_ACTIVATE_SOURCE_APP", [](const std::wstring&) { return []() { ActivateSourceApp(); }; }},
        {L"ACTION_VOLUME_UP", [](const std::wstring&) { return []() { SendKeypress({VK_VOLUME_UP}); }; }},
        {L"ACTION_VOLUME_DOWN", [](const std::wstring&) { return []() { SendKeypress({VK_VOLUME_DOWN}); }; }},
        {L"ACTION_START_PROCESS", [](const std::wstring& input) { return [input]() { StartProcess(input); }; }},
        {L"ACTION_SEND_KEYPRESS", [](const std::wstring& input) {
            const auto keys = BuildKeypressSequence(input);
            return [keys]() { SendKeypress(keys); };
        }},
        {L"ACTION_MEDIA_PLAY_PAUSE", [](const std::wstring&) { return []() { SendKeypress({VK_MEDIA_PLAY_PAUSE}); }; }},
        {L"ACTION_MEDIA_NEXT", [](const std::wstring&) { return []() { SendKeypress({VK_MEDIA_NEXT_TRACK}); }; }},
        {L"ACTION_MEDIA_PREV", [](const std::wstring&) { return []() { SendKeypress({VK_MEDIA_PREV_TRACK}); }; }},
        {L"ACTION_TOGGLE_AUDIO_REACTIVE", [](const std::wstring&) { return []() {
            g_AudioReactiveRuntimeEnabled = !g_AudioReactiveRuntimeEnabled;
            g_AudioPeakSmoothed = 0.0f;
            Wh_Log(L"[Audio Reactive] Toggled: %s", g_AudioReactiveRuntimeEnabled ? L"ON" : L"OFF");
        }; }},
        {L"ACTION_TOGGLE_RAINBOW_ZORDER", [](const std::wstring&) { return []() {
            g_Settings.rainbowAboveWidget = !g_Settings.rainbowAboveWidget;
            Wh_Log(L"[Rainbow] Z-Order Toggled: %s", g_Settings.rainbowAboveWidget ? L"Above" : L"Below");
            if (g_hMediaWindow && g_hRainbowWindow) {
                HWND mediaInsert = GetMediaZOrderInsertAfter();
                HWND rainbowInsert = GetRainbowZOrderInsertAfter();
                UINT flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW;
                // Force update both
                SetWindowPos(g_hRainbowWindow, rainbowInsert, 0,0,0,0, flags);
                SetWindowPos(g_hMediaWindow, mediaInsert, 0,0,0,0, flags);
            }
        }; }}
    };

    const std::wstring_view actionView = actionName;
    if (const auto it = kActionFactories.find(actionView); it != kActionFactories.end()) {
        auto baseAction = it->second(args);

        // Wrap with delay if specified
        if (delay > 0) {
            return [baseAction, delay]() {
                ExecuteActionWithDelay(baseAction, delay);
            };
        }

        return baseAction;
    }

    return []() {};
}

void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds) {
    Wh_Log(L"[DELAY] Queueing action with %.2f second delay", delaySeconds);
    std::lock_guard<std::mutex> lock(g_pendingActionsMutex);
    g_pendingActions.push_back({
        action,
        GetTickCount() + (DWORD)(delaySeconds * 1000)
    });
    Wh_Log(L"[DELAY] Queue size: %d", (int)g_pendingActions.size());
    SetTimer(g_hMediaWindow, IDT_DELAYED_ACTIONS, TIMER_DELAYED_ACTIONS_MS, NULL);
}

bool OnMouseClick(const std::wstring& detectedTriggerName) {
    uint32_t currentMods = GetKeyModifiersState();
    bool handled = false;
    for(const auto& t : g_triggers) {
        if (t.mouseTriggerName == detectedTriggerName) {
            if (t.expectedModifiers == currentMods) {
                // Execute all actions for this trigger in order
                for (size_t i = 0; i < t.actions.size(); i++) {
                    if (t.actions[i]) {
                        t.actions[i]();
                        Wh_Log(L"[MusicLounge] Trigger '%s' Action %d/%d executed", 
                               detectedTriggerName.c_str(), (int)(i+1), (int)t.actions.size());
                    }
                }
                if (!t.actions.empty()) {
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
    
    static DWORD s_lastPid = 0;
    static bool s_lastResult = false;

    DWORD pid = 0;
    GetWindowThreadProcessId(hFg, &pid);
    if (pid == 0) return false;

    // Cache hit: same PID as last check, return cached result
    if (pid == s_lastPid) return s_lastResult;

    HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!hProcess) {
        s_lastPid = pid;
        s_lastResult = false;
        return false;
    }

    WCHAR buffer[MAX_PATH];
    bool match = false;
    if (GetModuleFileNameExW(hProcess, NULL, buffer, MAX_PATH)) {
        buffer[MAX_PATH - 1] = L'\0';
        wstring fullPath = buffer;
        size_t lastSlash = fullPath.find_last_of(L"\\");
        wstring exeName = (lastSlash == wstring::npos) ? fullPath : fullPath.substr(lastSlash + 1);
        
        exeName = stringtools::toLower(exeName);
        wstring list = stringtools::toLower(g_Settings.ignoredApps);
        
        if (list.find(exeName) != wstring::npos) match = true;
    }
    CloseHandle(hProcess);
    
    // Update cache
    s_lastPid = pid;
    s_lastResult = match;
    return match;
}

// --- Sync Logic ---

bool CheckBorderlessFullscreen() {
    HWND hFg = GetForegroundWindow();
    if (!hFg || hFg == GetDesktopWindow() || hFg == GetShellWindow()) return false;
    if (IsAppIgnored(hFg)) return false;

    WCHAR clsName[256];
    GetClassNameW(hFg, clsName, 256);
    clsName[255] = L'\0';
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

void UpdateScaleFactor() {
    UINT dpi = GetDpiForSystem();  // No window needed, system-wide DPI
    if (dpi == 0) dpi = 96;
    g_ScaleFactor = dpi / 96.0f;
}

HWND GetMediaZOrderInsertAfter() {
    if (g_Settings.rainbowAboveWidget && g_hRainbowWindow) return g_hRainbowWindow;
    return HWND_TOPMOST;
}

HWND GetRainbowZOrderInsertAfter() {
    if (g_Settings.rainbowAboveWidget) return HWND_TOPMOST;
    if (g_hMediaWindow) return g_hMediaWindow;
    return HWND_TOPMOST;
}

void ForceDockedState() {
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int scaledW = (int)(g_Settings.width * g_ScaleFactor);
    int scaledH = (int)(g_Settings.height * g_ScaleFactor);
    SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), 0, screenH - 2, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_AnimState = 3; // Docked Mode
    
    // Dock rainbow window too
    if (g_hRainbowWindow && g_Settings.enableRainbow) {
        int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
        SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), 0 - borderOffset, screenH - 2 - borderOffset, 
                     scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), SWP_NOACTIVATE | SWP_SHOWWINDOW);
        g_RainbowAnimState = 3;
    }
}

void SyncPositionWithTaskbar() {
    if (!g_hMediaWindow || g_ShutdownMode) return;
    
    // 1. Startup / Crash Recovery - centralized handle validation
    if (!EnsureTaskbarHandle()) {
        if (g_AnimState != 3) ForceDockedState();
        return;
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
                    SetTimer(g_hMediaWindow, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
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

                 SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), targetX, g_CurrentAnimY, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
                 g_AnimState = 2; // Showing
                 SetTimer(g_hMediaWindow, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
                 // Sync rainbow window
                 if (g_hRainbowWindow && g_Settings.enableRainbow) {
                     int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                     g_CurrentRainbowAnimY = (g_RainbowAnimState == 3) ? (screenH - 2 - borderOffset) : screenH;
                     SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), targetX - borderOffset, g_CurrentRainbowAnimY, 
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

            SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), x, y, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
            g_AnimState = 0; // Synced
            // Sync rainbow window position
            if (g_hRainbowWindow && g_Settings.enableRainbow) {
                int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), x - borderOffset, y - borderOffset,
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

// --- Color Parsing Helper ---
bool ParseColorComponents(const wchar_t* str, int& r, int& g, int& b, int& a) {
    if (!str) return false;
    int ri = 0, gi = 0, bi = 0, ai = 255;
    int count = swscanf_s(str, L"%d,%d,%d,%d", &ri, &gi, &bi, &ai);
    if (count < 3) return false;
    
    // Clamp values
    if (ri > 255) ri = 255; if (ri < 0) ri = 0;
    if (gi > 255) gi = 255; if (gi < 0) gi = 0;
    if (bi > 255) bi = 255; if (bi < 0) bi = 0;
    if (ai > 255) ai = 255; if (ai < 0) ai = 0;

    r = Clamp(ri, 0, 255);
    g = Clamp(gi, 0, 255);
    b = Clamp(bi, 0, 255);
    a = Clamp(ai, 0, 255);
    return true;
}

int GetClampedSetting(PCWSTR name, int min, int max) {
    return Clamp(Wh_GetIntSetting(name), min, max);
}

// Clamp and validate all settings after load
void ValidateSettings() {
    // Size/position
    g_Settings.width = Clamp(g_Settings.width, 100, 800);
    g_Settings.height = Clamp(g_Settings.height, 20, 100);
    g_Settings.fontSize = Clamp(g_Settings.fontSize, 8, 32);
    
    // Rainbow
    g_Settings.rainbowSpeed = Clamp(g_Settings.rainbowSpeed, 1, 10);
    g_Settings.rainbowBrightness = Clamp(g_Settings.rainbowBrightness, 0, 100);
    g_Settings.rainbowThickness = Clamp(g_Settings.rainbowThickness, 1, 10);
    g_Settings.rainbowBorderOffset = Clamp(g_Settings.rainbowBorderOffset, 0, 10);
    
    // Audio reactive
    g_Settings.audioResponsiveness = Clamp(g_Settings.audioResponsiveness, 0, 20);
    g_Settings.audioThreshold = Clamp(g_Settings.audioThreshold, 0, 100);
    g_Settings.audioRamp = Clamp(g_Settings.audioRamp, 0, 100);
    g_Settings.audioFlicker = Clamp(g_Settings.audioFlicker, 0, 100);
    g_Settings.audioMinValue = Clamp(g_Settings.audioMinValue, 0, 100);
    g_Settings.audioMaxValue = Clamp(g_Settings.audioMaxValue, 0, 100);
    g_Settings.audioHueReactiveMode = Clamp(g_Settings.audioHueReactiveMode, 0, 7);
    
    // Intervals
    g_Settings.fsInterval = Clamp(g_Settings.fsInterval, 1, 10);
    g_Settings.idleTimeout = Clamp(g_Settings.idleTimeout, 0, 300);
    
    // Opacity
    g_Settings.bgOpacity = Clamp(g_Settings.bgOpacity, 0, 255);
    
    Wh_Log(L"Settings validated");
}

#pragma endregion  // ^action_engine

//! =====================================================================

#pragma region settings

/// Load all settings from Windhawk configuration
void LoadSettings() {
    // --- Dimensions & Position ---
    g_Settings.width = Wh_GetIntSetting(L"PanelWidth");
    g_Settings.height = Wh_GetIntSetting(L"PanelHeight");
    g_Settings.fontSize = Wh_GetIntSetting(L"FontSize");
    g_Settings.offsetX = Wh_GetIntSetting(L"OffsetX");
    g_Settings.offsetY = Wh_GetIntSetting(L"OffsetY");
    
    // --- Theme Settings ---
    g_Settings.autoTheme = Wh_GetIntSetting(L"AutoTheme") != 0;
    g_Settings.invertTheme = Wh_GetIntSetting(L"InvertTheme") != 0;
    g_Settings.bgOpacity = Wh_GetIntSetting(L"BgOpacity");

    // --- Manual Text Color ---
    PCWSTR textColorStr = Wh_GetStringSetting(L"TextColor");
    if (textColorStr) {
        int r, g, b, a;
        if (ParseColorComponents(textColorStr, r, g, b, a)) {
             g_Settings.manualTextColor = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b;
        } else {
             g_Settings.manualTextColor = 0xFFFFFFFF;
        }
        Wh_FreeStringSetting(textColorStr);
    } else {
        g_Settings.manualTextColor = 0xFFFFFFFF;
    }

    // --- Manual Background Color ---
    PCWSTR bgColorStr = Wh_GetStringSetting(L"BgColor");
    if (bgColorStr) {
        int r, g, b, a;
        if (ParseColorComponents(bgColorStr, r, g, b, a) && !(r==0 && g==0 && b==0)) {
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
    
    // Logic to preserve runtime toggle unless setting specifically changes
    bool newRainbowAboveWidget = Wh_GetIntSetting(L"RainbowAboveWidget") != 0;
    static bool isFirstLoad = true;

    if (isFirstLoad) {
        g_Settings.rainbowAboveWidget = newRainbowAboveWidget;
        g_Settings.storedRainbowAboveWidget = newRainbowAboveWidget;
        isFirstLoad = false;
    } else {
        // If the configuration changed effectively (user modified it in settings), update runtime.
        if (newRainbowAboveWidget != g_Settings.storedRainbowAboveWidget) {
            g_Settings.rainbowAboveWidget = newRainbowAboveWidget;
            g_Settings.storedRainbowAboveWidget = newRainbowAboveWidget;
        }
        // Else: Configuration is same as last known file state, but runtime (g_Settings.rainbowAboveWidget)
        // might have been toggled by user action. Keep the runtime value.
    }

    g_Settings.enableAudioReactive = Wh_GetIntSetting(L"EnableAudioReactive") != 0;
    
    g_Settings.rainbowSpeed = GetClampedSetting(L"RainbowSpeed", 1, 10);
    g_Settings.rainbowBrightness = GetClampedSetting(L"RainbowBrightness", 0, 100);
    g_Settings.rainbowThickness = GetClampedSetting(L"RainbowThickness", 1, 10);
    g_Settings.rainbowBorderOffset = GetClampedSetting(L"RainbowBorderOffset", 0, 10);

    g_Settings.enableRoundedCorners = Wh_GetIntSetting(L"EnableRoundedCorners") != 0;

    // Load Audio Processing Settings
    g_Settings.audioResponsiveness = GetClampedSetting(L"AudioResponsiveness", 0, 20);
    g_Settings.audioThreshold = GetClampedSetting(L"AudioThreshold", 0, 100);
    g_Settings.audioRamp = GetClampedSetting(L"AudioRamp", 0, 100);
    g_Settings.audioBinary = Wh_GetIntSetting(L"AudioBinary") != 0;
    g_Settings.audioFlicker = GetClampedSetting(L"AudioFlicker", 0, 100);
    g_Settings.audioDynamicRange = Wh_GetIntSetting(L"AudioDynamicRange") != 0;
    
    g_Settings.audioMinValue = GetClampedSetting(L"AudioMinValue", 0, 100);
    g_Settings.audioMaxValue = GetClampedSetting(L"AudioMaxValue", 0, 100);
    g_Settings.audioHueReactiveMode = GetClampedSetting(L"AudioHueReactiveMode", 0, 7);

    g_Settings.bgOpacity = GetClampedSetting(L"BgOpacity", 0, 255);

    // Validate Dimensions with Defaults
    if (g_Settings.width < 100) g_Settings.width = 400;
    if (g_Settings.height < 24) g_Settings.height = 48;

    // Initialize audio meter if audio reactive is enabled
    if (g_Settings.enableAudioReactive && g_audioCOM.IsInitialized()) {
        g_audioCOM.InitMeter();
    }

    // Reset audio state on settings load
    g_AudioPeakLevel = 0.0f;
    g_AudioPeakSmoothed = 0.0f;
    g_AudioReactiveRuntimeEnabled = true;

    // --- Load Action Engine Triggers ---
    using WindhawkUtils::StringSetting;
    g_triggers.clear();
    for (int i = 0; i < 50; i++) {
        auto mouseTriggerStr = std::wstring(StringSetting::make(L"Triggers[%d].MouseTrigger", i).get());
        if (mouseTriggerStr.empty()) continue;
        
        uint32_t mods = 0;
        for (int j = 0; j < 8; j++) {
            auto modStr = std::wstring(StringSetting::make(L"Triggers[%d].KeyboardTriggers[%d]", i, j).get());
            if (modStr.empty()) break;
            if (modStr == L"none") continue;
            KeyModifier km = GetKeyModifierFromName(modStr);
            if (km != KEY_MODIFIER_INVALID) SetBit(mods, km);
        }
        
        ConfiguredTrigger ct;
        ct.mouseTriggerName = mouseTriggerStr;
        ct.expectedModifiers = mods;
        
        // Load multiple actions per trigger
        for (int k = 0; k < 20; k++) {  // Up to 20 actions per trigger
            auto actionStr = std::wstring(StringSetting::make(L"Triggers[%d].Actions[%d].Action", i, k).get());
            if (actionStr.empty()) break;
            auto argsStr = std::wstring(StringSetting::make(L"Triggers[%d].Actions[%d].AdditionalArgs", i, k).get());
            auto parsedAction = ParseAction(actionStr, argsStr);
            if (parsedAction) {
                ct.actions.push_back(parsedAction);
            }
        }
        
        if (!ct.actions.empty()) {
            g_triggers.push_back(ct);
            Wh_Log(L"[MusicLounge] Loaded Trigger '%s' with %d action(s)", 
                   ct.mouseTriggerName.c_str(), (int)ct.actions.size());
        }
    }
    
    ValidateSettings();  // Clamp and validate all loaded values
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
    if (!g_SessionManager) {
        try {
            g_SessionManager = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
            if (!g_SessionManager) {
                Wh_Log(L"WARNING: Failed to acquire GSMTC manager");
                return;
            }
        } catch (const std::exception& e) {
            Wh_Log(L"ERROR: Exception acquiring GSMTC manager");
            return;
        } catch (...) {
            Wh_Log(L"ERROR: Unknown exception acquiring GSMTC manager");
            return;
        }
    }
    
    try {
        auto session = g_SessionManager.GetCurrentSession();
        if (!session) {
            lock_guard<mutex> guard(g_MediaState.lock);
            g_MediaState.hasMedia = false;
            g_MediaState.title = L"No Media";
            g_MediaState.artist = L"";
            g_MediaState.sourceId = L"";
            if (g_MediaState.albumArt) { delete g_MediaState.albumArt; g_MediaState.albumArt = nullptr; }
            return;
        }
        
        auto props = session.TryGetMediaPropertiesAsync().get();
        if (!props) {
            Wh_Log(L"WARNING: Failed to get media properties");
            lock_guard<mutex> guard(g_MediaState.lock);
            g_MediaState.hasMedia = false;
            return;
        }
        
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
    } catch (const std::exception& e) {
        Wh_Log(L"ERROR: Exception in UpdateMediaInfo");
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.sourceId = L"";
    } catch (...) {
        Wh_Log(L"ERROR: Unknown exception in UpdateMediaInfo");
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.sourceId = L"";
    }
}

void SendMediaCommand(int cmd) {
    try {
        if (!g_SessionManager) {
            Wh_Log(L"WARNING: GSMTC manager not available for media command");
            return;
        }
        auto session = g_SessionManager.GetCurrentSession();
        if (!session) {
            Wh_Log(L"WARNING: No active media session for command");
            return;
        }
        
        if (cmd == 1) session.TrySkipPreviousAsync();
        else if (cmd == 2) session.TryTogglePlayPauseAsync();
        else if (cmd == 3) session.TrySkipNextAsync();
    } catch (const std::exception& e) {
        Wh_Log(L"ERROR: Exception sending media command %d", cmd);
    } catch (...) {
        Wh_Log(L"ERROR: Unknown exception sending media command %d", cmd);
    }
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
    
    float baseHue = g_RainbowHue;
    float brightness = g_Settings.rainbowBrightness / 100.0f;
    float thickness = (float)g_Settings.rainbowThickness;
    
    // Apply audio reactivity if enabled and running
    if (g_Settings.enableAudioReactive && g_AudioReactiveRuntimeEnabled) {
        if (kAudioReactiveMode == 1 || kAudioReactiveMode == 3) {
            if (g_Settings.audioDynamicRange) {
                // When audio is 0 (g_AudioPeakLevel=0), we return to Base Brightness.
                // When audio is 1, we go to Max Brightness (100%).
                // Formula: Base + (Audio * (1.0 - Base))
                float audioBoost = g_AudioPeakLevel * (1.0f - brightness);
                brightness += audioBoost;
            } else {
                brightness += (g_AudioPeakLevel * kAudioSensitivity * 0.15f);
            }
            if (brightness > 1.0f) brightness = 1.0f;
        }
        if (kAudioReactiveMode == 2 || kAudioReactiveMode == 3) {
            thickness += (g_AudioPeakLevel * kAudioSensitivity * 2.5f);
        }
    }
    
    // Check if rounding is enabled for drawing paths
    bool rounded = g_Settings.enableRoundedCorners; 
    float radius = rounded ? 8.0f : 0.0f; 
    
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
    GraphicsPath path;
    if (rounded) {
        float d = radius * 2.0f;
        RectF rect(0, 0, (float)logicalW, (float)logicalH);
        
        // Inset slightly so the thick border doesn't get clipped by the DWM window region
        float inset = thickness / 2.0f;
        rect.Inflate(-inset, -inset);
        
        path.AddArc(rect.X, rect.Y, d, d, 180, 90); // Top-Left
        path.AddArc(rect.X + rect.Width - d, rect.Y, d, d, 270, 90); // Top-Right
        path.AddArc(rect.X + rect.Width - d, rect.Y + rect.Height - d, d, d, 0, 90); // Bottom-Right
        path.AddArc(rect.X, rect.Y + rect.Height - d, d, d, 90, 90); // Bottom-Left
        path.CloseFigure();
    } else {
         float inset = thickness / 2.0f;
         path.AddRectangle(RectF(inset, inset, logicalW - thickness, logicalH - thickness));
    }

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
    
    int logicalH = g_Settings.height;
    int logicalW = g_Settings.width;

    int artSize = logicalH - 12;
    int artX = 6, artY = 6;
    
    // Hold lock only while drawing the image, then immediately release
    {
        lock_guard<mutex> guard(g_MediaState.lock);
        if (g_MediaState.albumArt && g_MediaState.albumArt->GetLastStatus() == Ok) {
            graphics.DrawImage(g_MediaState.albumArt, artX, artY, artSize, artSize);
        } else {
            SolidBrush placeBrush{Color(40, 128, 128, 128)};
            graphics.FillRectangle(&placeBrush, artX, artY, artSize, artSize);
        }
    }
    
    // Copy scalar state outside the lock for text rendering
    wstring title, artist;
    bool isPlaying;
    {
        lock_guard<mutex> guard(g_MediaState.lock);
        title = g_MediaState.title;
        artist = g_MediaState.artist;
        isPlaying = g_MediaState.isPlaying;
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
    if (isPlaying) {
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
    wstring fullText = title;
    if (!artist.empty()) fullText += L" • " + artist;

    FontFamily fontFamily(kFontName, nullptr);
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

#pragma endregion  // ^settings

//! =====================================================================

#pragma region rendering

//! ============================================================================
// AUDIO PROCESSING
//! ============================================================================

/// Calculate smoothed audio peak level with optional dynamic range processing
float CalculateAudioPeak(float rawPeak) {
    if (!g_Settings.audioDynamicRange) {
        // Simple Lerp-based smoothing
        g_AudioPeakSmoothed = Lerp(g_AudioPeakSmoothed, rawPeak, kAudioSmoothing);
        return g_AudioPeakSmoothed;
    }

    // Advanced Processing (Script Port)
    float sMin = (float)g_Settings.audioMinValue / 100.0f;
    float sMax = (float)g_Settings.audioMaxValue / 100.0f;
    float sRamp = (float)g_Settings.audioRamp / 100.0f;
    float sThresh = (float)g_Settings.audioThreshold / 100.0f;
    float sFlicker = (float)g_Settings.audioFlicker / 100.0f;
    
    float valDelta = sMax + sRamp - sMin;
    
    // Normalize responsiveness to a lerp factor (higher responsiveness = faster response)
    // Responsiveness range 0-20, map to lerp range [0.01, 1.0]
    float lerpFactor = Clamp((float)g_Settings.audioResponsiveness / 20.0f, 0.01f, 1.0f);
    
    // Apply smoothing via Lerp
    g_AudioPeakSmoothed = Lerp(g_AudioPeakSmoothed, rawPeak, lerpFactor);
    g_AudioPeakSmoothed = Clamp(g_AudioPeakSmoothed, 0.0f, 1.0f);
    
    float audioValue = (g_AudioPeakSmoothed * valDelta) + sMin;
    
    float finalValue = 0.0f;
    if (audioValue >= sThresh) {
        finalValue = audioValue - sRamp;
        if (g_Settings.audioBinary) finalValue = 1.0f;
    } else {
        finalValue = 0.0f;
    }
    
    if (finalValue <= sFlicker) finalValue = 0.0f;
    
    return Clamp(finalValue, 0.0f, 1.0f);
}

#pragma endregion  // ^rendering

//! =====================================================================

#pragma region window_procedures

/// Rainbow border window procedure
LRESULT CALLBACK RainbowWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            // Make window transparent to mouse events
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
            if (g_Settings.enableRainbow) {
                SetTimer(hwnd, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
            }
            // Apply corner rounding to match main window
            DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
            DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));
            return 0;
        }
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY:
            Wh_Log(L"RainbowWndProc WM_DESTROY");
            KillTimer(hwnd, IDT_RAINBOW_ANIM);
            Wh_Log(L"Rainbow timer killed");
            return 0;
        case WM_TIMER:
            if (wParam == IDT_RAINBOW_ANIM) {
                // Sample audio peak if audio reactive enabled
                if (g_Settings.enableAudioReactive && g_AudioReactiveRuntimeEnabled) {
                    float peak = g_audioCOM.GetPeakLevel();
                    g_AudioPeakLevel = CalculateAudioPeak(peak);
                }
                
                // === Audio Hue Reactive Feature ===
                if (g_Settings.audioHueReactiveMode > 0 && g_Settings.enableAudioReactive && 
                    g_Settings.enableRainbow && g_AudioReactiveRuntimeEnabled) {
                    
                    // Speed boost (modes 1, 4, 5, 7)
                    if (g_Settings.audioHueReactiveMode == 1 || g_Settings.audioHueReactiveMode == 4 || 
                        g_Settings.audioHueReactiveMode == 5 || g_Settings.audioHueReactiveMode == 7) {
                        float speedMult = 1.0f + (g_AudioPeakLevel * kAudioSensitivity * kAudioHueSpeedBoost);
                        g_RainbowHue += (g_Settings.rainbowSpeed * 0.6f * speedMult);
                    } else {
                        g_RainbowHue += (g_Settings.rainbowSpeed * 0.6f);
                    }
                    
                    // Pulse effect (modes 2, 4, 6, 7)
                    if (g_Settings.audioHueReactiveMode == 2 || g_Settings.audioHueReactiveMode == 4 || 
                        g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                        g_RainbowHue += (g_AudioPeakLevel * kAudioHuePulseAmount * 0.1f);
                    }
                    
                    // Bounce effect (modes 3, 5, 6, 7)
                    if (g_Settings.audioHueReactiveMode == 3 || g_Settings.audioHueReactiveMode == 5 || 
                        g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                        if (g_AudioPeakLevel > kAudioHueBounceThreshold && !g_RainbowDirectionReverse) {
                            g_RainbowDirectionReverse = true;
                        } else if (g_AudioPeakLevel <= kAudioHueBounceThreshold && g_RainbowDirectionReverse) {
                            g_RainbowDirectionReverse = false;
                        }
                        
                        if (g_RainbowDirectionReverse) {
                            g_RainbowHue -= (g_Settings.rainbowSpeed * 0.6f * 0.5f);
                        }
                    }
                    
                } else {
                    // Standard audio reactive (existing behavior)
                    float speedMult = 1.0f;
                    if (g_Settings.enableAudioReactive && g_AudioReactiveRuntimeEnabled && 
                        (kAudioReactiveMode == 0 || kAudioReactiveMode == 3)) {
                        speedMult = 1.0f + (g_AudioPeakLevel * kAudioSensitivity * 2.0f);
                    }
                    
                    g_RainbowHue += (g_Settings.rainbowSpeed * 0.6f * speedMult);
                }
                
                // Wrap hue to 0-360 range
                if (g_RainbowHue >= 360.0f) g_RainbowHue -= 360.0f;
                if (g_RainbowHue < 0.0f) g_RainbowHue += 360.0f;
                
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
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                else if (g_RainbowAnimState == 2) { // Show
                    if (g_IsGameDetected || g_IsHiddenByIdle) { g_RainbowAnimState = 1; return 0; }
                    g_CurrentRainbowAnimY -= 8;
                    if (g_CurrentRainbowAnimY <= targetY) {
                        g_CurrentRainbowAnimY = targetY;
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_RainbowAnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_CurrentRainbowAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
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

/// Helper: Check if click is in the "background" area (right of the art/controls)
bool IsClickOnBackground(LPARAM lParam) {
    int x = (int)(LOWORD(lParam) / g_ScaleFactor);
    int artSize = g_Settings.height - 12;
    int artRightEdge = 6 + artSize + 5;
    return (x > artRightEdge);
}

/// Media widget window procedure
LRESULT CALLBACK MediaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_CREATE: 
            UpdateAppearance(hwnd);
            SetTimer(hwnd, IDT_POLL_MEDIA, TIMER_MEDIA_POLL_MS, NULL); 
            return 0;
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY:
            Wh_Log(L"MediaWndProc WM_DESTROY");
            KillTimer(hwnd, IDT_VIS_ANIM);
            KillTimer(hwnd, IDT_TEXT_ANIM);
            KillTimer(hwnd, IDT_POLL_MEDIA);
            KillTimer(hwnd, IDT_DELAYED_ACTIONS);
            Wh_Log(L"All timers killed");
            // NOTE: g_SessionManager cleanup moved to MediaThread cleanup lambda
            // to ensure proper shutdown order (before winrt::uninit_apartment)
            PostQuitMessage(0);
            return 0;
        case WM_SETTINGCHANGE: UpdateAppearance(hwnd); InvalidateRect(hwnd, NULL, TRUE); return 0;
        case WM_DPICHANGED: {
            // Centralized DPI refresh - use UpdateScaleFactor instead of manual calculation
            UpdateScaleFactor();
            Wh_Log(L"WM_DPICHANGED: Scale factor updated to %.2f", g_ScaleFactor);

            // Use suggested rect from system if provided
            RECT* prcNew = reinterpret_cast<RECT*>(lParam);
            if (prcNew) {
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), prcNew->left, prcNew->top,
                             prcNew->right - prcNew->left, prcNew->bottom - prcNew->top,
                             SWP_NOZORDER | SWP_NOACTIVATE);
            }

            // Recalculate and refresh everything with new DPI
            SyncPositionWithTaskbar();
            UpdateAppearance(hwnd);
            InvalidateRect(hwnd, NULL, TRUE);

            // Update rainbow window with new scaled dimensions
            if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
                int scaledW = (int)(g_Settings.width * g_ScaleFactor);
                int scaledH = (int)(g_Settings.height * g_ScaleFactor);
                int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
                SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), 0, 0,
                             scaledW + (borderOffset * 2),
                             scaledH + (borderOffset * 2),
                             SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
                InvalidateRect(g_hRainbowWindow, NULL, TRUE);
            }
            return 0;
        }
        case WM_QUERYENDSESSION:
            g_ShutdownMode = true;
            ForceDockedState();
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
                        SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                else if (g_AnimState == 2) { // Show
                    if (g_IsGameDetected || g_IsHiddenByIdle) { g_AnimState = 1; return 0; }
                    g_CurrentAnimY -= 8;
                    if (g_CurrentAnimY <= targetY) {
                        g_CurrentAnimY = targetY;
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_AnimState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_CurrentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                // Sync rainbow animation timer
                if (g_hRainbowWindow && g_Settings.enableRainbow && (g_RainbowAnimState == 1 || g_RainbowAnimState == 2)) {
                    SetTimer(g_hRainbowWindow, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
                }
            }
            else if (wParam == IDT_DELAYED_ACTIONS) {
                std::lock_guard<std::mutex> lock(g_pendingActionsMutex);
                DWORD now = GetTickCount();
                
                Wh_Log(L"[DELAY] Timer tick - checking %d pending actions", (int)g_pendingActions.size());

                // Execute ready actions
                auto it = g_pendingActions.begin();
                while (it != g_pendingActions.end()) {
                    if (now >= it->executeAtTick) {
                        Wh_Log(L"[DELAY] Executing delayed action");
                        it->action();
                        it = g_pendingActions.erase(it);
                    } else {
                        ++it;
                    }
                }

                // Stop timer if no pending actions
                if (g_pendingActions.empty()) {
                    Wh_Log(L"[DELAY] Queue empty - stopping timer");
                    KillTimer(hwnd, IDT_DELAYED_ACTIONS);
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
            } else if (IsClickOnBackground(lParam)) {
                OnMouseClick(L"Left");
            }
            return 0;
        case WM_RBUTTONUP:
            if (IsClickOnBackground(lParam)) OnMouseClick(L"Right");
            return 0;
        case WM_MBUTTONUP:
            if (IsClickOnBackground(lParam)) OnMouseClick(L"Middle");
            return 0;
        case WM_LBUTTONDBLCLK:
            if (IsClickOnBackground(lParam)) OnMouseClick(L"Double");
            return 0;
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
                SetTimer(hwnd, IDT_TEXT_ANIM, TIMER_TEXT_ANIM_MS, NULL);
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

#pragma endregion  // ^window_procedures

//! =====================================================================

#pragma region main_thread

/// Main media widget thread - runs in dedicated process via tool mod
void MediaThread() {
    Wh_Log(L"MediaThread started");

    // --- DPI Awareness ---
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    Wh_Log(L"DPI awareness set");

    // --- WinRT Initialization (required for GSMTC media control) ---
    bool winrtInitialized = false;
    try {
        winrt::init_apartment();
        winrtInitialized = true;
        Wh_Log(L"WinRT apartment initialized");
    } catch (...) {
        Wh_Log(L"ERROR: Failed to initialize WinRT apartment");
        return;
    }

    // --- GDI+ Initialization (required for rendering) ---
    GdiplusStartupInput gdiplusStartupInput;
    if (GdiplusStartup(&g_gdiplusToken, &gdiplusStartupInput, NULL) != Ok) {
        Wh_Log(L"ERROR: GDI+ initialization failed");
        if (winrtInitialized) {
            winrt::uninit_apartment();
            Wh_Log(L"WinRT apartment uninitialized");
        }
        return;
    }
    Wh_Log(L"GDI+ initialized");

    // UPDATE DPI FIRST (independent from any window)
    UpdateScaleFactor();
    Wh_Log(L"Scale factor updated to %.2f", g_ScaleFactor);
    
    // ENSURE TASKBAR HANDLE is available
    EnsureTaskbarHandle();
    Wh_Log(L"Taskbar handle ensured");
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

    // Pre-calculate scaled dimensions
    int scaledW = (int)(g_Settings.width * g_ScaleFactor);
    int scaledH = (int)(g_Settings.height * g_ScaleFactor);
    int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);

    auto cleanup = [&]() {
        if (g_hVisibilityHook) {
            UnhookWinEvent(g_hVisibilityHook);
            Wh_Log(L"WinEvent hook unhooked");
            g_hVisibilityHook = NULL;
        }
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        UnregisterClass(wcRainbow.lpszClassName, wcRainbow.hInstance);
        if (g_gdiplusToken) {
            GdiplusShutdown(g_gdiplusToken);
            Wh_Log(L"GDI+ shutdown completed");
            g_gdiplusToken = 0;
        }
        // CRITICAL: Release GSMTC session manager BEFORE uninit_apartment
        // to properly terminate RPC connections and avoid "RPC server unavailable" errors
        if (g_SessionManager) {
            try {
                // Setting to nullptr releases the WinRT COM reference
                g_SessionManager = nullptr;
                Wh_Log(L"GSMTC session manager released");
            } catch (...) {
                Wh_Log(L"WARNING: Exception releasing GSMTC session manager");
                g_SessionManager = nullptr;
            }
        }
        if (winrtInitialized) {
            winrt::uninit_apartment();
            Wh_Log(L"WinRT apartment uninitialized");
        }
        Wh_Log(L"MediaThread exiting");
    };

    // Create media window hidden with scaled size
    if (CreateWindowInBand) {
        g_hMediaWindow = CreateWindowInBand(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
            wc.lpszClassName,
            TEXT("MusicLounge"),
            WS_POPUP,
            0, 0,
            scaledW,
            scaledH,
            NULL, NULL, wc.hInstance, NULL,
            ZBID_IMMERSIVE_NOTIFICATION);
    } else {
        g_hMediaWindow = CreateWindowEx(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
            wc.lpszClassName,
            TEXT("MusicLounge"),
            WS_POPUP,
            0, 0,
            scaledW,
            scaledH,
            NULL, NULL, wc.hInstance, NULL);
    }

    if (!g_hMediaWindow) {
        Wh_Log(L"ERROR: Failed to create media window");
        cleanup();
        return;
    }

    // Create rainbow window hidden with scaled size
    if (CreateWindowInBand) {
        g_hRainbowWindow = CreateWindowInBand(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            wcRainbow.lpszClassName,
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            scaledW + (borderOffset * 2),
            scaledH + (borderOffset * 2),
            NULL, NULL, wcRainbow.hInstance, NULL,
            ZBID_IMMERSIVE_NOTIFICATION);
    } else {
        g_hRainbowWindow = CreateWindowEx(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            wcRainbow.lpszClassName,
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            scaledW + (borderOffset * 2),
            scaledH + (borderOffset * 2),
            NULL, NULL, wcRainbow.hInstance, NULL);
    }

    // Apply appearance and transparency while hidden
    SetLayeredWindowAttributes(g_hMediaWindow, 0, 255, LWA_ALPHA);
    UpdateAppearance(g_hMediaWindow);
    if (g_hRainbowWindow) {
        SetLayeredWindowAttributes(g_hRainbowWindow, 0, 255, LWA_ALPHA);
    }

    // Position while hidden
    g_AnimState = 3; // Docked
    SyncPositionWithTaskbar();

    // Show after setup is complete
    ShowWindow(g_hMediaWindow, SW_SHOWNOACTIVATE);
    if (g_Settings.enableRainbow && g_hRainbowWindow) {
        ShowWindow(g_hRainbowWindow, SW_SHOWNOACTIVATE);
    }

    g_hVisibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    if (g_hVisibilityHook) {
        Wh_Log(L"WinEvent hook installed: 0x%p", g_hVisibilityHook);
    } else {
        Wh_Log(L"WARNING: Failed to install WinEvent hook");
    }

    Wh_Log(L"MediaThread entering message loop");

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) { TranslateMessage(&msg); DispatchMessage(&msg); }

    Wh_Log(L"MediaThread exiting message loop");

    cleanup();
}

std::thread* g_pMediaThread = nullptr;

BOOL WhTool_ModInit() {
    Wh_Log(L"Init " WH_MOD_ID L" version " WH_MOD_VERSION);
    
    // Reset all global state to ensure clean initialization
    g_RainbowDirectionReverse = false;
    g_AudioPeakLevel = 0.0f;
    g_AudioPeakSmoothed = 0.0f;
    g_RainbowHue = 0.0f;
    g_RainbowAnimState = 0;
    g_AnimState = 0;
    g_IsGameDetected = false;
    g_IsHiddenByIdle = false;
    g_IdleSecondsCounter = 0;
    Wh_Log(L"Global state reset");

    if (FAILED(SetCurrentProcessExplicitAppUserModelID(L"taskbar-music-lounge-fork"))) {
        Wh_Log(L"WARNING: SetCurrentProcessExplicitAppUserModelID failed");
    }
    
    // CRITICAL: Initialize DPI scaling FIRST (independent of taskbar)
    UpdateScaleFactor();
    Wh_Log(L"Scale factor initialized to %.2f", g_ScaleFactor);
    
    // CRITICAL: Initialize taskbar handle FIRST (before thread spawn)
    EnsureTaskbarHandle();
    
    // Initialize Audio COM first so LoadSettings can enable the meter if needed
    if (!g_audioCOM.Init()) {
        Wh_Log(L"ERROR: Failed to initialize audio COM");
        return FALSE;
    }
    Wh_Log(L"Audio COM initialized");

    LoadSettings();
    Wh_Log(L"Settings loaded");

    g_Running = true;
    if (!g_pMediaThread) {
        g_pMediaThread = new std::thread(MediaThread);
        Wh_Log(L"Media thread spawned");
    } else {
        Wh_Log(L"WARNING: Media thread already exists");
    }

    Wh_Log(L"Init complete");
    return TRUE;
}

void WhTool_ModUninit() {
    Wh_Log(L"Uninit " WH_MOD_ID L" starting");

    // Clear pending actions
    {
        std::lock_guard<std::mutex> lock(g_pendingActionsMutex);
        g_pendingActions.clear();
    }
    
    g_triggers.clear();

    g_Running = false;
    Wh_Log(L"Signaled media thread to stop");

    if (g_hRainbowWindow) {
        SendMessage(g_hRainbowWindow, APP_WM_CLOSE, 0, 0);
        Wh_Log(L"Sent close to rainbow window");
    }
    if (g_hMediaWindow) {
        SendMessage(g_hMediaWindow, APP_WM_CLOSE, 0, 0);
        Wh_Log(L"Sent close to media window");
    }

    if (g_pMediaThread) {
        Wh_Log(L"Waiting for media thread to exit...");
        if (g_pMediaThread->joinable()) g_pMediaThread->join();
        delete g_pMediaThread;
        g_pMediaThread = nullptr;
        Wh_Log(L"Media thread joined and cleaned up");
    }

    {
        std::lock_guard<std::mutex> guard(g_MediaState.lock);
        if (g_MediaState.albumArt) {
            delete g_MediaState.albumArt;
            g_MediaState.albumArt = nullptr;
            Wh_Log(L"Album art freed during shutdown");
        }
    }
    
    // Reset audio reactive state
    g_AudioPeakLevel = 0.0f;
    g_AudioPeakSmoothed = 0.0f;
    g_RainbowDirectionReverse = false;
    Wh_Log(L"Audio reactive state reset");

    g_audioCOM.Uninit();
    Wh_Log(L"Audio COM uninitialized");

    Wh_Log(L"Uninit complete");
}

void WhTool_ModSettingsChanged() {
    Wh_Log(L"Settings changed, reloading...");
    
    // CRITICAL: Pause any live animation timers
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        KillTimer(g_hMediaWindow, IDT_VIS_ANIM);
        KillTimer(g_hMediaWindow, IDT_TEXT_ANIM);
        KillTimer(g_hMediaWindow, IDT_POLL_MEDIA);
        KillTimer(g_hMediaWindow, IDT_DELAYED_ACTIONS);
        Wh_Log(L"Paused media window timers");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        KillTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM);
        Wh_Log(L"Paused rainbow window timer");
    }
    
    // Reload settings with validation
    LoadSettings();  // Calls ValidateSettings() at end
    
    // Refresh DPI scaling in case system DPI changed
    UpdateScaleFactor();
    
    // Reapply appearance
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        UpdateAppearance(g_hMediaWindow);
        SyncPositionWithTaskbar();
        // Trigger repaint
        InvalidateRect(g_hMediaWindow, NULL, FALSE);
        Wh_Log(L"Applied new appearance to media window");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        // Apply corner rounding update
        DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
        DwmSetWindowAttribute(g_hRainbowWindow, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));

        if (g_hMediaWindow && g_Settings.enableRainbow) {
            SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
        
        // Reset audio reactive state on settings change
        g_AudioPeakLevel = 0.0f;
        g_AudioPeakSmoothed = 0.0f;
        g_RainbowDirectionReverse = false;
        if (g_Settings.enableAudioReactive && g_audioCOM.IsInitialized()) {
            g_audioCOM.InitMeter();
        }
        
        InvalidateRect(g_hRainbowWindow, NULL, TRUE);
    }
    
    // Restart timers with new settings
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        SetTimer(g_hMediaWindow, IDT_POLL_MEDIA, TIMER_MEDIA_POLL_MS, NULL);
        Wh_Log(L"Restarted media window timers");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        if (g_Settings.enableRainbow) {
            SetTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
            ShowWindow(g_hRainbowWindow, SW_SHOWNOACTIVATE);
            Wh_Log(L"Restarted rainbow timer");
        } else {
            ShowWindow(g_hRainbowWindow, SW_HIDE);
            Wh_Log(L"Rainbow disabled, window hidden");
        }
    }
    
    Wh_Log(L"Settings reload complete");
}

#pragma endregion  // ^main_thread

//! =====================================================================

#pragma region windhawk_exports

////////////////////////////////////////////////////////////////////////////////
// Windhawk tool mod implementation for mods which don't need to inject to other
// processes or hook other functions. Context:
// https://github.com/ramensoftware/windhawk-mods/pull/1916
//
// The mod will load and run in a dedicated windhawk.exe process.

bool g_isToolModProcessLauncher;
HANDLE g_toolModProcessMutex;

void WINAPI EntryPoint_Hook() {
    Wh_Log(L">");
    ExitThread(0);
}

BOOL Wh_ModInit() {
    bool isService = false;
    bool isToolModProcess = false;
    bool isCurrentToolModProcess = false;
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
    if (!argv) {
        Wh_Log(L"CommandLineToArgvW failed");
        return FALSE;
    }

    for (int i = 1; i < argc; i++) {
        if (wcscmp(argv[i], L"-service") == 0) {
            isService = true;
            break;
        }
    }

    for (int i = 1; i < argc - 1; i++) {
        if (wcscmp(argv[i], L"-tool-mod") == 0) {
            isToolModProcess = true;
            if (wcscmp(argv[i + 1], WH_MOD_ID) == 0) {
                isCurrentToolModProcess = true;
            }
            break;
        }
    }

    LocalFree(argv);

    if (isService) {
        return FALSE;
    }

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex =
            CreateMutex(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex) {
            Wh_Log(L"CreateMutex failed");
            ExitProcess(1);
        }

        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            Wh_Log(L"Tool mod already running (%s)", WH_MOD_ID);
            ExitProcess(1);
        }

        if (!WhTool_ModInit()) {
            ExitProcess(1);
        }

        IMAGE_DOS_HEADER* dosHeader =
            (IMAGE_DOS_HEADER*)GetModuleHandle(nullptr);
        IMAGE_NT_HEADERS* ntHeaders =
            (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);

        DWORD entryPointRVA = ntHeaders->OptionalHeader.AddressOfEntryPoint;
        void* entryPoint = (BYTE*)dosHeader + entryPointRVA;

        Wh_SetFunctionHook(entryPoint, (void*)EntryPoint_Hook, nullptr);
        return TRUE;
    }

    if (isToolModProcess) {
        return FALSE;
    }

    g_isToolModProcessLauncher = true;
    return TRUE;
}

void Wh_ModAfterInit() {
    if (!g_isToolModProcessLauncher) {
        return;
    }

    WCHAR currentProcessPath[MAX_PATH];
    switch (GetModuleFileName(nullptr, currentProcessPath,
                              ARRAYSIZE(currentProcessPath))) {
        case 0:
        case ARRAYSIZE(currentProcessPath):
            Wh_Log(L"GetModuleFileName failed");
            return;
    }

    WCHAR commandLine[MAX_PATH + 2 +
                (sizeof(L" -tool-mod \"" WH_MOD_ID "\"") / sizeof(WCHAR)) - 1];
    swprintf_s(commandLine, L"\"%s\" -tool-mod \"%s\"", currentProcessPath,
               WH_MOD_ID);

    HMODULE kernelModule = GetModuleHandle(L"kernelbase.dll");
    if (!kernelModule) {
        kernelModule = GetModuleHandle(L"kernel32.dll");
        if (!kernelModule) {
            Wh_Log(L"No kernelbase.dll/kernel32.dll");
            return;
        }
    }

    using CreateProcessInternalW_t = BOOL(WINAPI*)(
        HANDLE hUserToken, LPCWSTR lpApplicationName, LPWSTR lpCommandLine,
        LPSECURITY_ATTRIBUTES lpProcessAttributes,
        LPSECURITY_ATTRIBUTES lpThreadAttributes, WINBOOL bInheritHandles,
        DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory,
        LPSTARTUPINFOW lpStartupInfo,
        LPPROCESS_INFORMATION lpProcessInformation,
        PHANDLE hRestrictedUserToken);
    CreateProcessInternalW_t pCreateProcessInternalW =
        (CreateProcessInternalW_t)GetProcAddress(kernelModule,
                                                 "CreateProcessInternalW");
    if (!pCreateProcessInternalW) {
        Wh_Log(L"No CreateProcessInternalW");
        return;
    }

    STARTUPINFO si{
        .cb = sizeof(STARTUPINFO),
        .dwFlags = STARTF_FORCEOFFFEEDBACK,
    };
    PROCESS_INFORMATION pi;
    if (!pCreateProcessInternalW(nullptr, currentProcessPath, commandLine,
                                 nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS,
                                 nullptr, nullptr, &si, &pi, nullptr)) {
        Wh_Log(L"CreateProcess failed");
        return;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void Wh_ModSettingsChanged() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModSettingsChanged();
}

void Wh_ModUninit() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModUninit();
    ExitProcess(0);
}

#pragma endregion  // ^windhawk_exports