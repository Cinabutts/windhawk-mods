#pragma region Windhawk

// ==WindhawkMod==
// @id              taskbar-music-lounge-pro
// @name            Taskbar Music Lounge Pro
// @description     A native-style music ticker with media controls and custom Action Triggers with delay support.
// @version         4.9.2
// @author          Cinabutts
// @github          https://github.com/Cinabutts
// @include         explorer.exe
// @compilerOptions -lole32 -ldwmapi -lgdi32 -luser32 -lwindowsapp -lshcore -lgdiplus -lshell32 -lpsapi -lcomctl32 -loleaut32 -lversion -lpropsys -ladvapi32
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Music Lounge Pro (v4.9.2)

A media controller that uses Windows 11 native DWM styling for a seamless look.

##                                                                 ✨ Features
              [@Hashah2311](https://github.com/Hashah2311)'s OG [Taskbar Music Lounge](https://github.com/ramensoftware/windhawk-mods/blob/53d96781b3215f0a082908a2539cafe178e8895a/mods/taskbar-music-lounge.wh.cpp):
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

##                                                             🔧 Mouse Action Engine

                                                                  **`Work In Progress!` Some actions may not work as expected.**

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


###                                       🚧 Volume Note: You **TYPICALLY** need to Left Click the widget first to focus it before scrolling. 🚧
                                         **Tips:** Avoid assigning "Left Click" as a trigger if you use volume scrolling, as it will prevent the widget from gaining focus.

            Use AdditionalArgs with the Combine Taskbar Buttons action to provide the COMBINE_* states that should be applied (see the settings description).

                                                            Use the Open-Source Firefox/Chrome extension [Switch to audible tab](https://github.com/klntsky/switch-to-audible-tab)
for best experience!

----

&nbsp;

## ⚠️ Requirements
* **Disable Widgets:** Taskbar Settings -> Widgets -> Off.
* **Windows 11:** Required for rounded corners.

&nbsp;

###                                                                  📌*Maintained with the help of AI and careful babysitting* 💩🤖

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
      - - Action: ACTION_SWITCH_TO_AUDIBLE_WINDOW
          $name: Action
          $description: The command to execute.
          $options:
          - ACTION_SWITCH_TO_AUDIBLE_WINDOW: Switch to Audible Window
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
          - ACTION_TOGGLE_ADVANCED_DEBUG_LOG: Toggle Advanced Debug Logging
        - AdditionalArgs: ""
          $name: Arguments
          $description: >-
                    Syntax: xINSTANCE:yDELAY:zARGUMENT   (e.g. 1:4.5:Firefox | 5.5:Calc.exe | Chrome | Direct paths )

                     • x: 1=Force New | 0=Prevent Duplicates (Default | Doesn't need to be present)
                     • y: Seconds to wait (0=Default - Has Presedence e.g., `##:arg` = Delay whilst `##:##:` = xINSTANCE:yDELAY)
                     • z: Command/App + Params (e.g. firefox --new-window)

                    - Arguments by action:
                            •       Open App / Run File:            calc.exe | notepad | Direct paths | "C:\Scripts\Mycoolscript.py" | Quotes optional
                             May include additional Args ie `firefox --new-window` | Checks if running unless prefixed with `1:` | .type Optional

                            •   Switch to Audible Window:       Firefox | Chrome | Spotify, etc
                        Fallback App/File if `No Media` Present - Uses same logic as above  ▲

                            •     Send Keystrokes (macro):        0.5:Alt+Shift+A | Win+Tab (use + or ;)
                            •     Combine Taskbar Buttons:       1:COMBINE_ALWAYS;COMBINE_NEVER (2 or 4 states)
                        States Available: COMBINE_ALWAYS, COMBINE_WHEN_FULL, COMBINE_NEVER

                                    •   Volume/Media/Desktop/Taskbar: Delay only, No args needed
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
//      ~-- Windows Core
#include <windows.h>
#include <windef.h>
#include <cstddef>
#include <minwindef.h>
// #include <winerror.h>       // * Possibly unnecessary *
// #include <winuser.h>        // * Possibly unnecessary *
//      ~-- Windows Shell & UI
#include <shlobj.h>
#include <dwmapi.h>
#include <shcore.h>
// #include <shellapi.h>       // * Possibly unnecessary *
// #include <shobjidl.h>       // * Possibly unnecessary *
// #include <commctrl.h>       // * Possibly unnecessary * 
//      ~-- Windows Media & Audio
#include <mmdeviceapi.h>
#include <endpointvolume.h>
// #include <propsys.h>        // * Possibly unnecessary *
// #include <propkey.h>        // * Possibly unnecessary *
//      ~-- Graphics
#include <gdiplus.h>
//      ~-- Process & System
#include <psapi.h>
//      ~-- C++ Standard Library
#include <atomic>
#include <memory>
#include <functional>
#include <limits>
#include <mutex>
// #include <algorithm>         // * Possibly unnecessary *
// #include <cstdio>            // * Possibly unnecessary *
// #include <cwctype>           // * Possibly unnecessary *
// #include <sstream>           // * Possibly unnecessary *
// #include <string>            // * Possibly unnecessary *
// #include <string_view>       // * Possibly unnecessary *
// #include <thread>            // * Possibly unnecessary *
// #include <tuple>             // * Possibly unnecessary *
// #include <unordered_map>     // * Possibly unnecessary *
// #include <vector>            // * Possibly unnecessary *
//      ~-- WinRT (Windows Runtime for GSMTC media control)
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
//      ~-- Windhawk
#include <windhawk_utils.h>
#include <windhawk_api.h>

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
void LoadPersistentState();
void SaveWindowState(int x, int y, int w, int h);
void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist);
void ApplyPersistedMediaFallback();

// Action Engine
void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds);
bool OnMouseClick(const std::wstring& detectedTriggerName, int zDelta = 0);

// --- Timer IDs ---
#define IDT_POLL_MEDIA      1001  // Media state polling
#define IDT_TEXT_ANIM       1002  // Text scroll animation
#define IDT_VIS_ANIM        1003  // Visibility/slide animation
#define IDT_RAINBOW_ANIM    1004  // Rainbow border animation
#define IDT_DELAYED_ACTIONS 1005  // Delayed action execution

// --- Timer Intervals (milliseconds) ---
#define TIMER_ANIMATION_MS       16   // ~60 FPS for smooth animations
#define TIMER_MEDIA_POLL_MS      200  // 200ms media state poll (event-driven updates more important)
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
    bool enableAdvancedDebugLog = false; // Toggle advanced debug logging
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
// Registry configuration for advanced debug logging
constexpr wchar_t kAdvancedLogValueName[] = L"DebugLoggingEnabled";

// Check if advanced debug logging is enabled via registry
// Logic: Checks both local (dev) and official registry paths for the debug flag.
BOOL CheckRegistryDebugLog() {
    const wchar_t* registryPaths[] = {
        L"SOFTWARE\\Windhawk\\Engine\\Mods\\local@" WH_MOD_ID,
        L"SOFTWARE\\Windhawk\\Engine\\Mods\\" WH_MOD_ID
    };

    for (const auto& path : registryPaths) {
        HKEY key = nullptr;
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, path, 0, KEY_READ, &key) == ERROR_SUCCESS) {
            Wh_Log(L"[INIT] Checking Registry Path: HKLM\\%s", path);
            
            DWORD value = 0;
            DWORD size = sizeof(value);
            LONG status = RegQueryValueExW(key, kAdvancedLogValueName, nullptr, nullptr, 
                                     reinterpret_cast<LPBYTE>(&value), &size);
            RegCloseKey(key);

            if (status == ERROR_SUCCESS) {
                Wh_Log(L"[INIT] Registry Value found: %d", value);
                return (value != 0);
            }
        }
    }
    
    return FALSE;
}

#define Wh_LogAdvanced(fmt, ...) \
    if (g_Settings.enableAdvancedDebugLog) { \
        Wh_Log(fmt, ##__VA_ARGS__); \
    }

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
    wstring lastValidSourceId = L""; // Cache for transient empty IDs
    mutex lock;
} g_MediaState;

struct PersistedState {
    int lastX = std::numeric_limits<int>::min();
    int lastY = std::numeric_limits<int>::min();
    int lastW = 0;
    int lastH = 0;
    std::wstring lastTitle;
    std::wstring lastArtist;
} g_PersistedState;

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

// --- Scoped helpers for settings strings ---
class ScopedSettingString {
public:
    explicit ScopedSettingString(PCWSTR name) : m_value(Wh_GetStringSetting(name)) {}
    ~ScopedSettingString() {
        if (m_value) {
            Wh_FreeStringSetting(m_value);
        }
    }

    bool empty() const { return !m_value || m_value[0] == L'\0'; }
    PCWSTR get() const { return m_value; }
    std::wstring str() const { return m_value ? std::wstring(m_value) : std::wstring(); }

private:
    PCWSTR m_value;
};

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
        if (!args.empty() && stringtools::toLower(args[0]) == L"uac") { 
            verb = L"runas"; 
            cmd = cmd.length() > 4 ? cmd.substr(4) : L""; 
        }
        
        std::wstring executable, parameters;
        
        if (cmd.size() > 0 && (cmd[0] == L'"' || cmd[0] == L'\'')) {
            wchar_t quote = cmd[0];
            size_t close = cmd.find(quote, 1);
            if (close != std::wstring::npos) {
                executable = cmd.substr(1, close - 1);
                if (cmd.length() > close + 1) {
                    parameters = cmd.substr(close + 1);
                }
            } else {
                executable = cmd.substr(1); 
            }
        } else {
            size_t space = cmd.find(L' ');
            if (space != std::wstring::npos) {
                executable = cmd.substr(0, space);
                parameters = cmd.substr(space + 1);
            } else {
                executable = cmd;
            }
        }

        size_t firstParamChar = parameters.find_first_not_of(L" ");
        if (firstParamChar != std::wstring::npos) {
            parameters = parameters.substr(firstParamChar);
        } else {
            parameters.clear();
        }
        
        Wh_Log(L"[StartProcess] Launching: Exec='%s' Params='%s' (Raw='%s')", 
               executable.c_str(), parameters.c_str(), command.c_str());

        SHELLEXECUTEINFO sei = {sizeof(sei)};
        sei.fMask = SEE_MASK_NOASYNC | SEE_MASK_FLAG_NO_UI; 
        sei.lpVerb = verb.c_str(); 
        sei.lpFile = executable.c_str();
        sei.lpParameters = parameters.empty() ? nullptr : parameters.c_str(); 
        sei.nShow = SW_SHOWNORMAL;
        
        if (!ShellExecuteEx(&sei)) {
            Wh_Log(L"[StartProcess] Failed to execute: %s (Error: %d)", executable.c_str(), GetLastError());
        }
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
    IPropertyStore* pps;
    if (FAILED(SHGetPropertyStoreForWindow(hwnd, IID_PPV_ARGS(&pps)))) return L"";
    
    std::wstring aumid; PROPVARIANT var; PropVariantInit(&var);
    static const PROPERTYKEY kKey = { { 0x9F4C2855, 0x9F79, 0x4B39, { 0xA8, 0xD0, 0xE1, 0xD4, 0x2D, 0xE1, 0xD5, 0xF3 } }, 5 };
    if (SUCCEEDED(pps->GetValue(kKey, &var)) && var.vt == VT_LPWSTR && var.pwszVal) aumid = var.pwszVal;
    
    PropVariantClear(&var); pps->Release();
    return aumid;
}

struct WinSearchData {
    std::wstring targetAUMID;   // For AUMID-based search
    std::wstring targetExe;     // For exe name search (lowercase)
    HWND foundHwnd;             // Found window handle used for switch-to-audible-window - NULL if not found
    bool foundProcess;          // Found process flag used for switch-to-audible-window -exe search
    std::wstring targetTitle;   // New: Search for substring in window title (lowercase)
    bool checkHidden;           // New: If true, checks hidden windows too
};

BOOL CALLBACK FindWindowByAUMIDOrExe(HWND hwnd, LPARAM lParam) {
    WinSearchData* search = (WinSearchData*)lParam;
    
    // Visibility check - skipped if explicitly checking hidden windows (e.g. for scripts)
    if (!search->checkHidden) {
        if (!IsWindowVisible(hwnd)) return TRUE;
        if (GetWindow(hwnd, GW_OWNER) != NULL) return TRUE;
    }

    // AUMID search mode
    if (!search->targetAUMID.empty()) {
        std::wstring winId = GetWindowAUMID(hwnd);
        if (!winId.empty() && winId == search->targetAUMID) {
            search->foundHwnd = hwnd;
            return FALSE;
        }
    }

    // Title search mode (Scripts/Hidden windows)
    if (!search->targetTitle.empty()) {
        int length = GetWindowTextLength(hwnd);
        if (length > 0) {
            std::wstring title(length + 1, L'\0');
            GetWindowText(hwnd, &title[0], length + 1);
            // Case-insensitive substring search
            if (stringtools::toLower(title).find(search->targetTitle) != std::wstring::npos) {
                search->foundHwnd = hwnd;
                search->foundProcess = true;
                return FALSE;
            }
        }
    }

    // Exe name search mode
    if (!search->targetExe.empty()) {
        DWORD pid = 0;
        GetWindowThreadProcessId(hwnd, &pid);
        if (pid) {
            HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
            if (hProc) {
                WCHAR path[MAX_PATH] = {0};
                DWORD size = MAX_PATH;
                if (QueryFullProcessImageNameW(hProc, 0, path, &size)) {
                    std::wstring fullPath(path);
                    size_t pos = fullPath.find_last_of(L"\\/");
                    std::wstring exe = (pos != std::wstring::npos) ? fullPath.substr(pos + 1) : fullPath;
                    if (stringtools::toLower(exe) == search->targetExe) {
                        search->foundProcess = true;
                        search->foundHwnd = hwnd;
                        CloseHandle(hProc);
                        return FALSE;
                    }
                }
                CloseHandle(hProc);
            }
        }
    }
    return TRUE;
}

// Forward declaration
void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds, const std::wstring& actionName);

// Helper to execute a command (find existing or launch new) with custom logging
void ExecuteProcessOrWindow(const std::wstring& cmd, bool bypassSingleInstanceCheck, const std::wstring& logPrefix) {
     if (cmd.empty()) return;

    if (bypassSingleInstanceCheck) {
            Wh_Log(L"%s Bypassing instance check - Launching: %s", logPrefix.c_str(), cmd.c_str());
            StartProcess(cmd);
            return;
    }

    // Parsing: Isolate the executable/script path from arguments (quotes or spaces)
    std::wstring executable = cmd;
    if (executable.size() > 0 && (executable[0] == L'"' || executable[0] == L'\'')) {
        size_t close = executable.find(executable[0], 1);
        if (close != std::wstring::npos) executable = executable.substr(1, close - 1);
    } else {
        size_t space = executable.find(L' ');
        if (space != std::wstring::npos) executable = executable.substr(0, space);
    }
    
    // Prepare comparison strings
    std::wstring exeName = executable;
    size_t slash = exeName.find_last_of(L"\\/");
    std::wstring filenameOnly = (slash != std::wstring::npos) ? exeName.substr(slash + 1) : exeName;
    
    std::wstring filenameLower = stringtools::toLower(filenameOnly);
    std::wstring fullPathLower = stringtools::toLower(executable);

    WinSearchData exeSearch = { L"", L"", NULL, false, L"", false }; // targetAUMID, targetExe, foundHwnd, foundProcess, targetTitle, checkHidden

    // Determine search strategy
    if (filenameLower.find(L".exe") != std::wstring::npos || filenameLower.find(L".") == std::wstring::npos) {
            // Strategy 1: Standard Executable
            // If no extension, append .exe
            if (filenameLower.find(L".") == std::wstring::npos) filenameLower += L".exe";
            
            exeSearch.targetExe = filenameLower;
            Wh_Log(L"%s Checking process: %s (Raw: %s)", logPrefix.c_str(), filenameLower.c_str(), cmd.c_str());
    } else {
            // Strategy 2: Script/File
            // If input looks like a path, search for the full path in window titles.
            // Otherwise, search for just the filename.
            if (fullPathLower.find(L"\\") != std::wstring::npos) {
                exeSearch.targetTitle = fullPathLower;   // Strict: "C:\Scripts\MyScript.ahk"
            } else {
                exeSearch.targetTitle = filenameLower;   // Loose: "MyScript.ahk"
            }
            exeSearch.checkHidden = true; // Essential for scripts (AHK, etc)
            Wh_Log(L"%s Checking script/title: %s (Raw: %s)", logPrefix.c_str(), exeSearch.targetTitle.c_str(), cmd.c_str());
    }
    
    EnumWindows(FindWindowByAUMIDOrExe, (LPARAM)&exeSearch);
    
    if (exeSearch.foundHwnd) {
        // Already running - focus it
        if (IsIconic(exeSearch.foundHwnd)) ShowWindow(exeSearch.foundHwnd, SW_RESTORE);
        SetForegroundWindow(exeSearch.foundHwnd);
        Wh_Log(L"%s %s already running - focused", logPrefix.c_str(), cmd.c_str());
    } else {
        StartProcess(cmd);
        Wh_Log(L"%s Launched: %s", logPrefix.c_str(), cmd.c_str());
    }
}

// Reworked SwitchToAudibleWindow: hunt for an existing window for the AUMID, focus/restore it; fallback to ShellExecute
void SwitchToAudibleWindow(const std::wstring& fallbackCmd = L"", bool bypassSingleInstanceCheck = false, float delaySeconds = 0.0f) {
    bool hasMedia;
    std::wstring targetId;
    {
        lock_guard<mutex> guard(g_MediaState.lock);
        hasMedia = g_MediaState.hasMedia;
        targetId = g_MediaState.sourceId;

        // Try to recover TargetID from last known good state if empty but media is present
        if (targetId.empty() && hasMedia && !g_MediaState.lastValidSourceId.empty()) {
            targetId = g_MediaState.lastValidSourceId;
            Wh_Log(L"[SwitchToAudibleWindow] Recovered TargetID from cache: '%s'", targetId.c_str());
        }
    }

    Wh_Log(L"[ActionEngine] SwitchToAudibleWindow: Media=%d, TargetID='%s', Fallback='%s', Bypass=%d, Delay=%.2f", 
           hasMedia, targetId.c_str(), fallbackCmd.c_str(), bypassSingleInstanceCheck, delaySeconds);
    
    // No media playing - use fallback command if provided
    if (!hasMedia) {
        if (!fallbackCmd.empty()) {
            if (delaySeconds > 0) {
                // Execute fallback with delay
                ExecuteActionWithDelay([=]() { 
                    ExecuteProcessOrWindow(fallbackCmd, bypassSingleInstanceCheck, L"[SwitchToAudibleWindow]"); 
                }, delaySeconds, L"Fallback Command: " + fallbackCmd);
            } else {
                ExecuteProcessOrWindow(fallbackCmd, bypassSingleInstanceCheck, L"[SwitchToAudibleWindow]");
            }
        } else {
            Wh_Log(L"[SwitchToAudibleWindow] ERROR: No media playing and no Fallback Command configured. Nothing to do.");
        }
        return;
    }
    
    // Explicitly log that we are ignoring the fallback because media is active
    if (!fallbackCmd.empty()) {
        Wh_Log(L"[SwitchToAudibleWindow] Media Source Present - Opening `%s` instead", targetId.c_str());
    }

    // Media is active, but we requested a delay?
    if (delaySeconds > 0.0f) {
         Wh_Log(L"[SwitchToAudibleWindow] Deferring - switching to Media Source in: %.2f seconds", delaySeconds);
         // Recurse with delay=0 to execute the switch execution phase
         ExecuteActionWithDelay([=]() { 
            SwitchToAudibleWindow(fallbackCmd, bypassSingleInstanceCheck, 0.0f); 
         }, delaySeconds, L"Delayed SwitchToAudibleWindow");
         return;
    }

    if (targetId.empty()) {
         Wh_Log(L"[SwitchToAudibleWindow] ERROR: Media active but TargetID is empty. Cannot switch.");
         return;
    }

    // Phase 1: Try to find the existing window
    WinSearchData search = { targetId, L"", NULL, false, L"", false };
    EnumWindows(FindWindowByAUMIDOrExe, (LPARAM)&search);

    if (search.foundHwnd) {
        // Window found! Restore and Focus.
        if (IsIconic(search.foundHwnd)) {
            ShowWindow(search.foundHwnd, SW_RESTORE);
        }
        SetForegroundWindow(search.foundHwnd);
    } else {
        // Phase 2: Window not found (maybe minimized to tray), fallback to Shell Activation
        Wh_Log(L"[SwitchToAudibleWindow] Window not found for AUMID: %s. Attempting Shell Activation...", targetId.c_str());
        std::wstring cmd = L"shell:AppsFolder\\" + targetId;
        
        SHELLEXECUTEINFO sei = {sizeof(sei)};
        sei.fMask = SEE_MASK_NOASYNC | SEE_MASK_FLAG_NO_UI; 
        sei.lpVerb = L"open"; 
        sei.lpFile = cmd.c_str();
        sei.nShow = SW_SHOWNORMAL;
        
        try {
            if (!ShellExecuteEx(&sei)) {
                Wh_Log(L"[SwitchToAudibleWindow] Shell activation failed: %s (Error: %d)", cmd.c_str(), GetLastError());
            }
        } catch (...) {
            Wh_Log(L"[SwitchToAudibleWindow] Exception during shell activation: %s", targetId.c_str());
        }
    }
}





struct ConfiguredTrigger {
    std::wstring mouseTriggerName;
    uint32_t expectedModifiers;
    std::vector<std::pair<std::wstring, std::function<void()>>> actions;  // (actionName, function)
};

std::vector<ConfiguredTrigger> g_triggers;

// --- Delayed Action Execution ---

/// Pending action for deferred execution
struct PendingAction {
    std::function<void()> action;
    DWORD executeAtTick;
    std::wstring description; // Metadata for logging
};

std::vector<PendingAction> g_pendingActions;
std::mutex g_pendingActionsMutex;

// --- Taskbar & Desktop Helpers ---

// Global execution context for triggers
thread_local std::wstring g_currentTriggerContext;

void SendWinTabKeypress() {
    Wh_Log(L"[Action] Sending Win+Tab");
    SendKeypress({VK_LWIN, VK_TAB});
}

void OpenStartMenu() {
    Wh_Log(L"[Action] Sending Win keypress for Start menu");
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
        Wh_Log(L"[Action] Setting taskbar autohide to %s", isEnabled ? L"disabled" : L"enabled");
        SetTaskbarAutohide(!isEnabled);
    } else {
        Wh_Log(L"[Action] Failed to toggle taskbar autohide - taskbar not found");
    }
}

// Show Desktop & Hide Icons
void ShowDesktopViaTaskbar() {
    HWND hTaskbar = EnsureTaskbarHandle();
    if (hTaskbar) {
        Wh_Log(L"[Action] Sending ShowDesktop message");
        SendMessage(hTaskbar, WM_COMMAND, MAKELONG(407, 0), 0);
    } else {
        Wh_Log(L"[Action] Failed to show desktop - taskbar not found");
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
        Wh_Log(L"[Action] Toggling desktop icons");
        PostMessage(hDesktopWnd, WM_COMMAND, 0x7402, 0);
    } else {
        Wh_Log(L"[Action] Failed to find desktop window");
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
        Wh_Log(L"[Action] Taskbar handle acquired: 0x%p", g_hTaskbar);
    } else {
        Wh_Log(L"[Action] WARNING: Failed to find taskbar window");
    }
    
    return g_hTaskbar;  // May be NULL
}

// Taskbar Alignment (Windows 11)
void ToggleTaskbarAlignment() {
    DWORD current = GetExplorerAdvancedSetting(L"TaskbarAl", 1);
    DWORD newAlign = (current == 0) ? 1 : 0;
    Wh_Log(L"[Action] Toggling taskbar alignment from %d to %d", current, newAlign);
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
    bool bypassSingleInstance;
    std::wstring actualArgs;
};

ParsedArgs ParseArgumentsWithDelay(const std::wstring& rawArgs) {
    ParsedArgs res{0.0f, false, rawArgs};
    if (rawArgs.empty()) return res;

    auto isF = [](const std::wstring& s) { try { size_t i; std::stof(s, &i); return i == s.length(); } catch(...) { return false; } };
    size_t c1 = rawArgs.find(L':');

    if (c1 != std::wstring::npos && c1 <= 1) { // 1:2.5:arg
        std::wstring p1 = rawArgs.substr(0, c1);
        if (p1 == L"0" || p1 == L"1") {
            size_t c2 = rawArgs.find(L':', c1 + 1);
            if (c2 != std::wstring::npos) {
                std::wstring p2 = rawArgs.substr(c1 + 1, c2 - c1 - 1);
                if (isF(p2)) {
                    res.bypassSingleInstance = (p1 == L"1");
                    res.delaySeconds = std::max(0.0f, std::stof(p2));
                    res.actualArgs = (c2 + 1 < rawArgs.length()) ? rawArgs.substr(c2 + 1) : L"";
                    return res;
                }
            }
        }
    }

    if (c1 != std::wstring::npos && c1 < 10) { // 2.5:arg
        std::wstring p = rawArgs.substr(0, c1);
        if (isF(p)) {
             res.delaySeconds = std::max(0.0f, std::stof(p));
             res.actualArgs = (c1 + 1 < rawArgs.length()) ? rawArgs.substr(c1 + 1) : L"";
        }
    }
    return res;
}

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
    // SPECIAL HANDLING for SwitchToAudibleWindow:
    // It consumes the delay internally during FALLBACK ONLY.
    // If we wrap it in ExecuteActionWithDelay here, it delays the PRIMARY check too.
    if (actionName == L"ACTION_SWITCH_TO_AUDIBLE_WINDOW") {
         ParsedArgs parsed = ParseArgumentsWithDelay(rawArgs);
         return [parsed]() { 
            SwitchToAudibleWindow(parsed.actualArgs, parsed.bypassSingleInstance, parsed.delaySeconds); 
         };
    }

    ParsedArgs parsed = ParseArgumentsWithDelay(rawArgs);
    const std::wstring& args = parsed.actualArgs;
    const float delay = parsed.delaySeconds;
    using ActionFactory = std::function<std::function<void()>(const ParsedArgs&)>;
    auto Simple = [](auto f) -> ActionFactory { return [f](const ParsedArgs&) { return f; }; };
    auto ArgAction = [](auto f) -> ActionFactory { return [f](const ParsedArgs& a) { return [f, s=a.actualArgs](){ f(s); }; }; };
    
    static const std::unordered_map<std::wstring_view, ActionFactory> kActionFactories = {
        {L"ACTION_SHOW_DESKTOP", Simple(ShowDesktopViaTaskbar)},
        {L"ACTION_TOGGLE_DESKTOP_ICONS", Simple(ToggleDesktopIcons)},
        {L"ACTION_TOGGLE_TASKBAR_AUTOHIDE", Simple(ToggleTaskbarAutohide)},
        {L"ACTION_TOGGLE_TASKBAR_ALIGNMENT", Simple(ToggleTaskbarAlignment)},
        {L"ACTION_WIN_TAB", Simple(SendWinTabKeypress)},
        {L"ACTION_OPEN_START_MENU", Simple(OpenStartMenu)},
        {L"ACTION_COMBINE_TASKBAR_BUTTONS", ArgAction(CombineTaskbarButtons)},
        {L"ACTION_MUTE", Simple(ToggleVolMuted)},
        {L"ACTION_TASK_MANAGER", Simple([]() { ShellExecute(0, L"open", L"taskmgr.exe", 0, 0, SW_SHOW); })},
        {L"ACTION_VOLUME_UP", Simple([]() { SendKeypress({VK_VOLUME_UP}); })},
        {L"ACTION_VOLUME_DOWN", Simple([]() { SendKeypress({VK_VOLUME_DOWN}); })},
        {L"ACTION_START_PROCESS", [](const ParsedArgs& a) { return [s=a.actualArgs, b=a.bypassSingleInstance]() { ExecuteProcessOrWindow(s, b, L"[StartProcess]"); }; }},
        {L"ACTION_SEND_KEYPRESS", [](const ParsedArgs& input) {
            const auto keys = BuildKeypressSequence(input.actualArgs);
            return [keys]() { SendKeypress(keys); };
        }},
        {L"ACTION_MEDIA_PLAY_PAUSE", Simple([]() { SendKeypress({VK_MEDIA_PLAY_PAUSE}); })},
        {L"ACTION_MEDIA_NEXT", Simple([]() { SendKeypress({VK_MEDIA_NEXT_TRACK}); })},
        {L"ACTION_MEDIA_PREV", Simple([]() { SendKeypress({VK_MEDIA_PREV_TRACK}); })},
        {L"ACTION_TOGGLE_AUDIO_REACTIVE", Simple([]() {
            g_AudioReactiveRuntimeEnabled = !g_AudioReactiveRuntimeEnabled;
            g_AudioPeakSmoothed = 0.0f;
            Wh_Log(L"[Audio Reactive] Toggled: %s", g_AudioReactiveRuntimeEnabled ? L"ON" : L"OFF");
        })},
        {L"ACTION_TOGGLE_RAINBOW_ZORDER", Simple([]() {
            g_Settings.rainbowAboveWidget = !g_Settings.rainbowAboveWidget;
            Wh_Log(L"[Rainbow] Z-Order Toggled: %s", g_Settings.rainbowAboveWidget ? L"Above" : L"Below");
            if (g_hMediaWindow && g_hRainbowWindow) {
                UINT flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW;
                SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), 0,0,0,0, flags);
                SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), 0,0,0,0, flags);
            }
        })},
        {L"ACTION_TOGGLE_ADVANCED_DEBUG_LOG", Simple([]() { 
            g_Settings.enableAdvancedDebugLog = !g_Settings.enableAdvancedDebugLog;
            Wh_Log(L"[Action] Advanced Debug Logging Toggled: %s", g_Settings.enableAdvancedDebugLog ? L"ENABLED" : L"DISABLED");
        })}
    };

    const std::wstring_view actionView = actionName;
    if (const auto it = kActionFactories.find(actionView); it != kActionFactories.end()) {
        auto baseAction = it->second(parsed);
        if (delay > 0) {
            std::wstring fullActionName = std::wstring(actionName) + (args.empty() ? L"" : L" " + args);
            return [baseAction, delay, fullActionName]() {
                ExecuteActionWithDelay(baseAction, delay, fullActionName);
            };
        }
        return baseAction;
    }

    return []() {};
}

void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds, const std::wstring& actionName) {
    Wh_LogAdvanced(L"[DELAY] Queueing action with %.2f second delay", delaySeconds);
    std::lock_guard<std::mutex> lock(g_pendingActionsMutex);
    
    // Construct description for logging
    std::wstring desc = actionName;
    if (!g_currentTriggerContext.empty()) {
        desc = L"[MusicLounge] " + g_currentTriggerContext + L" '" + actionName + L"' executed (DELAYED)";
    }

    g_pendingActions.push_back({
        action,
        GetTickCount() + (DWORD)(delaySeconds * 1000),
        desc
    });
    Wh_LogAdvanced(L"[DELAY] Queue size: %d", (int)g_pendingActions.size());
    SetTimer(g_hMediaWindow, IDT_DELAYED_ACTIONS, TIMER_DELAYED_ACTIONS_MS, NULL);
}

bool OnMouseClick(const std::wstring& detectedTriggerName, int zDelta) {
    uint32_t currentMods = GetKeyModifiersState();
    bool handled = false;
    for(const auto& t : g_triggers) {
        if (t.mouseTriggerName == detectedTriggerName) {
            if (t.expectedModifiers == currentMods) {
                Wh_Log(L"[ActionEngine] Trigger Matched: '%s' (Action Count: %d)", detectedTriggerName.c_str(), (int)t.actions.size());
                // Execute all actions for this trigger in order
                for (size_t i = 0; i < t.actions.size(); i++) {
                    const auto& [actionName, actionFunc] = t.actions[i];
                    if (actionFunc) {
                        // Set context for delayed actions
                        g_currentTriggerContext = L"Trigger '" + detectedTriggerName + L"' Action " + std::to_wstring(i+1) + L"/" + std::to_wstring(t.actions.size());

                        actionFunc();
                        
                        Wh_LogAdvanced(L"[MusicLounge] %s '%s' executed", g_currentTriggerContext.c_str(), actionName.c_str());
                        
                        if (zDelta != 0 && actionName.find(L"VOLUME") != std::wstring::npos) {
                            Wh_LogAdvanced(L"[INPUT] Sending volume command, zDelta=%d", zDelta);
                        }

                        g_currentTriggerContext.clear();
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
    static DWORD s_lPid = 0; static bool s_lRes = false;
    DWORD pid = 0; GetWindowThreadProcessId(hFg, &pid);
    if (!pid) return false;
    if (pid == s_lPid) return s_lRes;

    bool match = false;
    if (HANDLE hP = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid)) {
        WCHAR buf[MAX_PATH];
        if (GetModuleFileNameExW(hP, NULL, buf, MAX_PATH)) {
            std::wstring path = buf;
            size_t idx = path.find_last_of(L"\\");
            std::wstring name = stringtools::toLower(idx == std::wstring::npos ? path : path.substr(idx + 1));
            match = stringtools::toLower(g_Settings.ignoredApps).find(name) != std::wstring::npos;
        }
        CloseHandle(hP);
    }
    return (s_lPid = pid, s_lRes = match);
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

HWND GetMediaZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget && g_hRainbowWindow) ? g_hRainbowWindow : HWND_TOPMOST; }
HWND GetRainbowZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget || !g_hMediaWindow) ? HWND_TOPMOST : g_hMediaWindow; }

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
            SaveWindowState(x, y, scaledW, scaledH);
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

void LoadPersistentState() {
    g_PersistedState.lastX = Wh_GetIntValue(L"LastX", std::numeric_limits<int>::min());
    g_PersistedState.lastY = Wh_GetIntValue(L"LastY", std::numeric_limits<int>::min());
    g_PersistedState.lastW = Wh_GetIntValue(L"LastW", 0);
    g_PersistedState.lastH = Wh_GetIntValue(L"LastH", 0);

    wchar_t buffer[256] = {0};
    size_t len = Wh_GetStringValue(L"LastTitle", buffer, ARRAYSIZE(buffer));
    g_PersistedState.lastTitle = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    std::fill(std::begin(buffer), std::end(buffer), 0);
    len = Wh_GetStringValue(L"LastArtist", buffer, ARRAYSIZE(buffer));
    g_PersistedState.lastArtist = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    Wh_LogAdvanced(L"[STATE] Loaded persisted window state (%d,%d,%d,%d)",
           g_PersistedState.lastX, g_PersistedState.lastY,
           g_PersistedState.lastW, g_PersistedState.lastH);
}

void SaveWindowState(int x, int y, int w, int h) {
    // Only log and save if values actually changed
    if (g_PersistedState.lastX != x || g_PersistedState.lastY != y ||
        g_PersistedState.lastW != w || g_PersistedState.lastH != h) {
        Wh_SetIntValue(L"LastX", x);
        Wh_SetIntValue(L"LastY", y);
        Wh_SetIntValue(L"LastW", w);
        Wh_SetIntValue(L"LastH", h);
        g_PersistedState.lastX = x;
        g_PersistedState.lastY = y;
        g_PersistedState.lastW = w;
        g_PersistedState.lastH = h;
        Wh_LogAdvanced(L"[STATE] Saved window state (%d,%d,%dx%d)", x, y, w, h);
    }
}

void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist) {
    // Only log and save if values actually changed
    if (g_PersistedState.lastTitle != title || g_PersistedState.lastArtist != artist) {
        Wh_SetStringValue(L"LastTitle", title.c_str());
        Wh_SetStringValue(L"LastArtist", artist.c_str());
        g_PersistedState.lastTitle = title;
        g_PersistedState.lastArtist = artist;
        Wh_LogAdvanced(L"[STATE] Saved media info: '%s' by '%s'", 
               title.empty() ? L"<empty>" : title.c_str(),
               artist.empty() ? L"<empty>" : artist.c_str());
    }
}

void ApplyPersistedMediaFallback() {
    if (g_PersistedState.lastTitle.empty() && g_PersistedState.lastArtist.empty()) {
        Wh_Log(L"[STATE] No persisted media info to apply");
        return;
    }

    Wh_Log(L"[STATE] Applying persisted media fallback: '%s' by '%s'",
           g_PersistedState.lastTitle.empty() ? L"<empty>" : g_PersistedState.lastTitle.c_str(),
           g_PersistedState.lastArtist.empty() ? L"<empty>" : g_PersistedState.lastArtist.c_str());

    std::lock_guard<std::mutex> guard(g_MediaState.lock);
    g_MediaState.title = g_PersistedState.lastTitle;
    g_MediaState.artist = g_PersistedState.lastArtist;
    g_MediaState.hasMedia = !g_PersistedState.lastTitle.empty();
    g_MediaState.isPlaying = false;
}

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
    ScopedSettingString textColor(L"TextColor");
    Wh_Log(L"[SETTINGS] Text color string: '%s'", textColor.empty() ? L"<empty>" : textColor.get());
    if (!textColor.empty()) {
        int r, g, b, a;
        if (ParseColorComponents(textColor.get(), r, g, b, a)) {
            g_Settings.manualTextColor = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b;
        } else {
            g_Settings.manualTextColor = 0xFFFFFFFF;
        }
    } else {
        g_Settings.manualTextColor = 0xFFFFFFFF;
    }

    // --- Manual Background Color ---
    ScopedSettingString bgColor(L"BgColor");
    Wh_Log(L"[SETTINGS] Background color string: '%s'", bgColor.empty() ? L"<empty>" : bgColor.get());
    if (!bgColor.empty()) {
        int r, g, b, a;
        if (ParseColorComponents(bgColor.get(), r, g, b, a) && !(r==0 && g==0 && b==0)) {
            g_Settings.manualBgColorRGB = ((DWORD)b << 16) | ((DWORD)g << 8) | (DWORD)r;
        } else {
            g_Settings.manualBgColorRGB = 0; 
        }
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

    ScopedSettingString apps(L"IgnoredApps");
    Wh_Log(L"[SETTINGS] Ignored apps string: '%s'", apps.empty() ? L"<default>" : apps.get());
    if (!apps.empty()) {
        g_Settings.ignoredApps = apps.get();
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

    // Load persisted state after settings (so we know scaling and ranges)
    LoadPersistentState();
    ApplyPersistedMediaFallback();
    Wh_LogAdvanced(L"[STATE] Persistent state loaded and applied");

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
                ct.actions.push_back({actionStr, parsedAction});
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
GlobalSystemMediaTransportControlsSession g_CachedSession = nullptr;

// Custom message for async media info results
#define WM_MEDIA_INFO_READY (WM_APP + 1)

// Struct to pass async results back to UI thread
struct MediaInfoResult {
    wstring title;
    wstring artist;
    wstring sourceId;
    bool isPlaying;
    bool hasMedia;
    Bitmap* albumArt;
};
static std::shared_ptr<MediaInfoResult> g_PendingMediaInfo;

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

/// Async fire-and-forget media info update - does NOT block UI thread
void UpdateMediaInfoAsync() {
    static int s_NoSessionRetryCount = 0;

    // Early exit if no session available
    if (!g_CachedSession) {
        // Grace Period: Don't clear immediately to allow for transient session loss
        bool wasHavingMedia = false;
        {
            lock_guard<mutex> guard(g_MediaState.lock);
            wasHavingMedia = g_MediaState.hasMedia;
        }

        if (wasHavingMedia && s_NoSessionRetryCount < 8) { // ~1.5 second grace (200ms * 8)
            s_NoSessionRetryCount++;
            return; 
        }

        s_NoSessionRetryCount = 0;
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.title = L"No Media";
        g_MediaState.artist = L"";
        g_MediaState.sourceId = L"";
        if (g_MediaState.albumArt) { 
            delete g_MediaState.albumArt; 
            g_MediaState.albumArt = nullptr; 
        }
        return;
    }

    s_NoSessionRetryCount = 0;
    
    try {
        // Get source ID and playback state synchronously (fast operations)
        wstring sourceId = g_CachedSession.SourceAppUserModelId().c_str();
        auto info = g_CachedSession.GetPlaybackInfo();
        bool isPlaying = (info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
        
        // Fire off async media properties chain - does NOT block
        g_CachedSession.TryGetMediaPropertiesAsync().Completed(
            [sourceId, isPlaying](auto const& propsOp, Windows::Foundation::AsyncStatus status) {
                if (status != Windows::Foundation::AsyncStatus::Completed) {
                    Wh_Log(L"WARNING: Media properties async failed");
                    return;
                }
                
                auto props = propsOp.GetResults();
                if (!props) {
                    Wh_Log(L"WARNING: No media properties returned");
                    return;
                }
                
                // Build result on background thread
                auto* result = new MediaInfoResult();
                result->title = props.Title().c_str();
                result->artist = props.Artist().c_str();
                result->sourceId = sourceId;
                result->isPlaying = isPlaying;
                result->hasMedia = true;
                result->albumArt = nullptr;
                
                // Log source changes
                if (sourceId != g_MediaState.sourceId) {
                    Wh_Log(L"[MusicLounge] New Source: %s", sourceId.c_str());
                }
                
                // Chain: fetch thumbnail async
                auto thumbRef = props.Thumbnail();
                if (thumbRef) {
                    thumbRef.OpenReadAsync().Completed(
                        [result](auto const& streamOp, Windows::Foundation::AsyncStatus status) {
                            if (status == Windows::Foundation::AsyncStatus::Completed) {
                                result->albumArt = StreamToBitmap(streamOp.GetResults());
                            }
                            // Post to UI thread with result
                            auto resultPtr = std::shared_ptr<MediaInfoResult>(result);
                            if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
                                std::atomic_store_explicit(&g_PendingMediaInfo, resultPtr, std::memory_order_release);
                                PostMessage(g_hMediaWindow, WM_MEDIA_INFO_READY, 0, 0);
                            } else {
                                // Cleanup if window destroyed - shared_ptr handles deletion
                                resultPtr.reset();
                            }
                        });
                } else {
                    // No thumbnail - post result immediately
                    auto resultPtr = std::shared_ptr<MediaInfoResult>(result);
                    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
                        std::atomic_store_explicit(&g_PendingMediaInfo, resultPtr, std::memory_order_release);
                        PostMessage(g_hMediaWindow, WM_MEDIA_INFO_READY, 0, 0);
                    } else {
                        // Cleanup if window destroyed - shared_ptr handles deletion
                        resultPtr.reset();
                    }
                }
            });
    } catch (const std::exception& e) {
        Wh_Log(L"ERROR: Exception in UpdateMediaInfoAsync");
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.sourceId = L"";
    } catch (...) {
        Wh_Log(L"ERROR: Unknown exception in UpdateMediaInfoAsync");
        lock_guard<mutex> guard(g_MediaState.lock);
        g_MediaState.hasMedia = false;
        g_MediaState.sourceId = L"";
    }
}

void SendMediaCommand(int cmd) {
    try {
        // Use cached session - no blocking GetCurrentSession() call
        if (!g_CachedSession) {
            Wh_Log(L"WARNING: No cached media session for command");
            return;
        }
        
        // OPTIMIZATION: Optimistic UI update for play/pause - instant visual feedback
        if (cmd == 2) {
            lock_guard<mutex> guard(g_MediaState.lock);
            g_MediaState.isPlaying = !g_MediaState.isPlaying;
            if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
                InvalidateRect(g_hMediaWindow, NULL, FALSE);
            }
        }
        
        if (cmd == 1) g_CachedSession.TrySkipPreviousAsync();
        else if (cmd == 2) g_CachedSession.TryTogglePlayPauseAsync();
        else if (cmd == 3) g_CachedSession.TrySkipNextAsync();
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
            Wh_Log(L"-- WM_CREATE received - initializing RainbowWndProc");
            // Make window transparent to mouse events
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
            if (g_Settings.enableRainbow) {
                SetTimer(hwnd, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
                Wh_Log(L"Rainbow animation timer started (ID: %d, interval: %dms)", IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS);
            }
            // Apply corner rounding to match main window
            DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
            DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));
            Wh_Log(L"Window corner rounding: %s", g_Settings.enableRoundedCorners ? L"enabled" : L"disabled");
            return 0;
        }
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY:
            Wh_Log(L"-- RainbowWndProc WM_DESTROY");
            KillTimer(hwnd, IDT_RAINBOW_ANIM);
            Wh_Log(L"-- Rainbow timer killed");
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

/// Helper: Check if click is on album art or buttons (returns true if on background/text area)
bool IsClickOnBackground(LPARAM lParam) {
    int rawX = (int)LOWORD(lParam);
    int rawY = (int)HIWORD(lParam);
    int x = (int)(rawX / g_ScaleFactor);
    int y = (int)(rawY / g_ScaleFactor);
    int logicalH = g_Settings.height;
    int artSize = logicalH - 12;
    
    Wh_LogAdvanced(L"[HIT] Raw coords: (%d, %d), ScaleFactor: %.2f, Logical: (%d, %d)", 
           rawX, rawY, g_ScaleFactor, x, y);
    
    // Album art region (from DrawMediaPanel: artX=6, artY=6, size=artSize)
    int artX = 6, artY = 6;
    if (x >= artX && x <= artX + artSize && y >= artY && y <= artY + artSize) {
        Wh_LogAdvanced(L"[HIT] ON ALBUM ART - artX=%d, artY=%d, artSize=%d -> Result: FALSE", 
               artX, artY, artSize);
        return false;  // On album art
    }
    
    // Button region (from WM_MOUSEMOVE hover detection logic)
    int startControlX = 6 + artSize + 12;
    Wh_LogAdvanced(L"[HIT] artSize=%d, startControlX=%d", artSize, startControlX);
    
    if (y > 10 && y < logicalH - 10) {
        Wh_LogAdvanced(L"[HIT] In Y button range (10 < %d < %d)", y, logicalH - 10);
        if (x >= startControlX - 10 && x < startControlX + 66) {
            Wh_LogAdvanced(L"[HIT] ON BUTTONS - range: [%d, %d) -> Result: FALSE", 
                   startControlX - 10, startControlX + 66);
            return false;  // On buttons (prev, play, next combined)
        }
    }
    
    Wh_LogAdvanced(L"[HIT] ON BACKGROUND -> Result: TRUE");
    return true;  // On background/text
}

/// Media widget window procedure
LRESULT CALLBACK MediaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_CREATE: 
            Wh_Log(L"-- WM_CREATE received - initializing MediaWndProc");
            UpdateAppearance(hwnd);
            SetTimer(hwnd, IDT_POLL_MEDIA, TIMER_MEDIA_POLL_MS, NULL);
            Wh_Log(L"-- Media poll timer started (ID: %d, interval: %dms)", IDT_POLL_MEDIA, TIMER_MEDIA_POLL_MS);
            return 0;
        case WM_MEDIA_INFO_READY: {
            // Process async media info result on UI thread
            auto result = std::atomic_exchange_explicit(
                &g_PendingMediaInfo,
                std::shared_ptr<MediaInfoResult>{},
                std::memory_order_acquire);
            if (result) {
                lock_guard<mutex> guard(g_MediaState.lock);
                
                // Clean up old album art
                if (g_MediaState.albumArt) {
                    delete g_MediaState.albumArt;
                }
                
                // Update state with new data
                g_MediaState.title = result->title;
                g_MediaState.artist = result->artist;
                g_MediaState.sourceId = result->sourceId;

                if (!g_MediaState.sourceId.empty()) {
                    g_MediaState.lastValidSourceId = g_MediaState.sourceId;
                }

                g_MediaState.isPlaying = result->isPlaying;
                g_MediaState.hasMedia = result->hasMedia;
                g_MediaState.albumArt = result->albumArt;

                SaveLastMediaInfo(g_MediaState.title, g_MediaState.artist);
                
                // Trigger redraw with new media info
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
        }
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE: DestroyWindow(hwnd); return 0;
        case WM_DESTROY:
            Wh_Log(L"-- MediaWndProc WM_DESTROY");
            KillTimer(hwnd, IDT_VIS_ANIM);
            KillTimer(hwnd, IDT_TEXT_ANIM);
            KillTimer(hwnd, IDT_POLL_MEDIA);
            KillTimer(hwnd, IDT_DELAYED_ACTIONS);
            Wh_Log(L" --All timers killed-- ");
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
                UpdateMediaInfoAsync();
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
                
                Wh_LogAdvanced(L"[DELAY] Timer tick - checking %d pending actions", (int)g_pendingActions.size());

                // Execute ready actions
                auto it = g_pendingActions.begin();
                while (it != g_pendingActions.end()) {
                    if (now >= it->executeAtTick) {
                        // Log the specific action description instead of generic message
                        if (!it->description.empty()) {
                            Wh_Log(L"%s", it->description.c_str());
                        } else {
                            Wh_LogAdvanced(L"[DELAY] Executing delayed action (no desc)");
                        }
                        
                        it->action();
                        it = g_pendingActions.erase(it);
                    } else {
                        ++it;
                    }
                }

                // Stop timer if no pending actions
                if (g_pendingActions.empty()) {
                    Wh_LogAdvanced(L"[DELAY] Queue empty - stopping timer");
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
        case WM_LBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_LBUTTONUP");
            if (g_HoverState >= 1 && g_HoverState <= 3) {
                Wh_LogAdvanced(L"[INPUT] Clicked button state: %d", g_HoverState);
                SendMediaCommand(g_HoverState);
            } else if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Left click on background - triggering action");
                OnMouseClick(L"Left");
            }
            return 0;
        }
        case WM_RBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_RBUTTONUP");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Right click on background - triggering action");
                OnMouseClick(L"Right");
            }
            return 0;
        }
        case WM_MBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_MBUTTONUP");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Middle click on background - triggering action");
                OnMouseClick(L"Middle");
            }
            return 0;
        }
        case WM_LBUTTONDBLCLK: {
            Wh_LogAdvanced(L"[INPUT] WM_LBUTTONDBLCLK");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Double click on background - triggering action");
                OnMouseClick(L"Double");
            }
            return 0;
        }
        case WM_MOUSEWHEEL: {
            short zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
            bool handled = false;
            
            // WM_MOUSEWHEEL sends screen coordinates, convert to client-relative
            POINT pt;
            pt.x = (int)(short)LOWORD(lParam);
            pt.y = (int)(short)HIWORD(lParam);
            ScreenToClient(hwnd, &pt);
            LPARAM clientLParam = MAKELPARAM(pt.x, pt.y);
            
            bool isOnBackground = IsClickOnBackground(clientLParam);

            if (isOnBackground) {
                Wh_LogAdvanced(L"[INPUT] WM_MOUSEWHEEL at client coords (%d, %d), delta=%d", pt.x, pt.y, zDelta);

                if (zDelta > 0) {
                    Wh_LogAdvanced(L"[INPUT] ScrollUp on background - triggering action");
                    handled = OnMouseClick(L"ScrollUp", zDelta);
                } else {
                    Wh_LogAdvanced(L"[INPUT] ScrollDown on background - triggering action");
                    handled = OnMouseClick(L"ScrollDown", zDelta);
                }
            } else {
                Wh_LogAdvanced(L"[INPUT] Scroll BLOCKED - not on background");
            }
            
            if (!handled && isOnBackground) {
                // Fallback to System Volume Control
                Wh_LogAdvanced(L"[INPUT] Sending volume command, zDelta=%d", zDelta);
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
    Wh_Log(L"---- MediaThread started");

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
    Wh_Log(L"-- Scale factor updated to %.2f", g_ScaleFactor);
    
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
    Wh_Log(L"Media window class registered");

    // Register rainbow window class
    WNDCLASS wcRainbow = {0};
    wcRainbow.lpfnWndProc = RainbowWndProc;
    wcRainbow.hInstance = GetModuleHandle(NULL);
    wcRainbow.lpszClassName = TEXT("WindhawkMusicLounge_Rainbow");
    wcRainbow.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wcRainbow);
    Wh_Log(L"Rainbow window class registered");

    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
    pCreateWindowInBand CreateWindowInBand = (pCreateWindowInBand)GetProcAddress(hUser32, "CreateWindowInBand");
    if (CreateWindowInBand) {
        Wh_Log(L"-- CreateWindowInBand API available (Windows 10+)");
    } else {
        Wh_Log(L"-- CreateWindowInBand API not available, will use CreateWindowEx");
    }

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
        Wh_Log(L"Media window class unregistered");
        UnregisterClass(wcRainbow.lpszClassName, wcRainbow.hInstance);
        Wh_Log(L"Rainbow window class unregistered");
        // CRITICAL: Delete albumArt BEFORE GdiplusShutdown
        // Deleting GDI+ objects after GdiplusShutdown hangs indefinitely
        {
            std::lock_guard<std::mutex> guard(g_MediaState.lock);
            if (g_MediaState.albumArt) {
                delete g_MediaState.albumArt;
                g_MediaState.albumArt = nullptr;
                Wh_Log(L"Album art cleaned up in MediaThread");
            }
        }
        if (g_gdiplusToken) {
            GdiplusShutdown(g_gdiplusToken);
            Wh_Log(L"GDI+ shutdown completed");
            g_gdiplusToken = 0;
        }
        // CRITICAL: Release GSMTC session and manager BEFORE uninit_apartment
        // to properly terminate RPC connections and avoid "RPC server unavailable" errors
        if (g_CachedSession) {
            try {
                g_CachedSession = nullptr;
                Wh_Log(L"GSMTC cached session released");
            } catch (...) {
                Wh_Log(L"WARNING: Exception releasing cached session");
                g_CachedSession = nullptr;
            }
        }
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
    Wh_Log(L"Media window created: 0x%p (size: %dx%d)", g_hMediaWindow, scaledW, scaledH);

    // Create rainbow window hidden with scaled size
    Wh_Log(L"Creating rainbow window...");
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
        Wh_Log(L"CreateWindowInBand used for rainbow window");
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
        Wh_Log(L"-- CreateWindowEx used for rainbow window (CreateWindowInBand not available)");
    }
    if (g_hRainbowWindow) {
        Wh_Log(L"-- Rainbow window created: 0x%p", g_hRainbowWindow);
    }

    // Apply appearance and transparency while hidden
    SetLayeredWindowAttributes(g_hMediaWindow, 0, 255, LWA_ALPHA);
    UpdateAppearance(g_hMediaWindow);
    if (g_hRainbowWindow) {
        SetLayeredWindowAttributes(g_hRainbowWindow, 0, 255, LWA_ALPHA);
    }

    // Position while hidden (use persisted rect if available)
    if (g_PersistedState.lastX != std::numeric_limits<int>::min() &&
        g_PersistedState.lastY != std::numeric_limits<int>::min() &&
        g_PersistedState.lastW > 0 && g_PersistedState.lastH > 0) {
        SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(),
                     g_PersistedState.lastX, g_PersistedState.lastY,
                     g_PersistedState.lastW, g_PersistedState.lastH,
                     SWP_NOACTIVATE | SWP_SHOWWINDOW);
        Wh_Log(L" -Applied persisted window rect %d,%d %dx%d", g_PersistedState.lastX, g_PersistedState.lastY, g_PersistedState.lastW, g_PersistedState.lastH);
    }

    if (g_hRainbowWindow && g_Settings.enableRainbow &&
        g_PersistedState.lastX != std::numeric_limits<int>::min() &&
        g_PersistedState.lastY != std::numeric_limits<int>::min()) {
        int borderOffset = (int)(g_Settings.rainbowBorderOffset * g_ScaleFactor);
        SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(),
                     g_PersistedState.lastX - borderOffset,
                     g_PersistedState.lastY - borderOffset,
                     (g_PersistedState.lastW > 0 ? g_PersistedState.lastW : scaledW) + (borderOffset * 2),
                     (g_PersistedState.lastH > 0 ? g_PersistedState.lastH : scaledH) + (borderOffset * 2),
                     SWP_NOACTIVATE | SWP_SHOWWINDOW);
    }

    // Position while hidden
    g_AnimState = 3; // Docked
    SyncPositionWithTaskbar();

    // Show after setup is complete
    ShowWindow(g_hMediaWindow, SW_SHOWNOACTIVATE);
    Wh_Log(L" -Media window shown-");
    if (g_Settings.enableRainbow && g_hRainbowWindow) {
        ShowWindow(g_hRainbowWindow, SW_SHOWNOACTIVATE);
        Wh_Log(L" -Rainbow window shown-");
    } else if (g_hRainbowWindow) {
        Wh_Log(L" --Rainbow window created but hidden (enableRainbow=%d)-- ", g_Settings.enableRainbow);
    }

    g_hVisibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    if (g_hVisibilityHook) {
        Wh_Log(L"WinEvent hook installed: 0x%p", g_hVisibilityHook);
    } else {
        Wh_Log(L"WARNING: Failed to install WinEvent hook");
    }

    // Initialize GSMTC session manager and cache current session
    try {
        g_SessionManager = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
        if (g_SessionManager) {
            Wh_Log(L"GSMTC session manager acquired");
            
            // Cache initial session
            g_CachedSession = g_SessionManager.GetCurrentSession();
            if (g_CachedSession) {
                Wh_Log(L"Initial session cached");
            } else {
                Wh_Log(L"No initial session available");
            }
            
            // Register session change event handler
            g_SessionManager.CurrentSessionChanged([](auto&&, auto&&) {
                try {
                    g_CachedSession = g_SessionManager.GetCurrentSession();
                    if (g_CachedSession) {
                        Wh_Log(L"[MusicLounge] Session changed - new session cached");
                    } else {
                        Wh_Log(L"[MusicLounge] Session changed - no session available");
                    }
                    // Trigger immediate update with new session
                    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
                        UpdateMediaInfoAsync();
                    }
                } catch (...) {
                    Wh_Log(L"ERROR: Exception in session change handler");
                }
            });
            Wh_Log(L"Session change event handler registered");
            
            // OPTIMIZATION: Register playback info change event for instant state updates
            if (g_CachedSession) {
                g_CachedSession.PlaybackInfoChanged([](auto&&, auto&&) {
                    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
                        UpdateMediaInfoAsync();
                        InvalidateRect(g_hMediaWindow, NULL, FALSE);
                    }
                });
                Wh_Log(L"Playback info change event handler registered");
            }
        } else {
            Wh_Log(L"WARNING: Failed to acquire GSMTC session manager");
        }
    } catch (const std::exception& e) {
        Wh_Log(L"ERROR: Exception during GSMTC initialization");
    } catch (...) {
        Wh_Log(L"ERROR: Unknown exception during GSMTC initialization");
    }

    Wh_Log(L"MediaThread entering message loop");

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    Wh_Log(L" --MediaThread exiting message loop--");
    cleanup();
}

std::thread* g_pMediaThread = nullptr;

BOOL WhTool_ModInit() {
    Wh_Log(L" --- START --- ");
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
    Wh_Log(L"[UNINIT] Uninit " WH_MOD_ID L" starting");

    // Clear pending actions
    {
        std::lock_guard<std::mutex> lock(g_pendingActionsMutex);
        Wh_Log(L"[UNINIT] Clearing %d pending actions", (int)g_pendingActions.size());
        g_pendingActions.clear();
        Wh_Log(L"[UNINIT] Pending actions cleared");
    }
    
    Wh_Log(L"[UNINIT] Clearing triggers");
    g_triggers.clear();
    Wh_Log(L"[UNINIT] Triggers cleared");

    g_Running = false;
    Wh_Log(L"[UNINIT] Signaled media thread to stop");

    if (g_hRainbowWindow) {
        Wh_Log(L"[UNINIT] Sending APP_WM_CLOSE to rainbow window 0x%p", g_hRainbowWindow);
        SendMessage(g_hRainbowWindow, APP_WM_CLOSE, 0, 0);
        Wh_Log(L"[UNINIT] Close sent to rainbow window");
    }
    if (g_hMediaWindow) {
        Wh_Log(L"[UNINIT] Sending APP_WM_CLOSE to media window 0x%p", g_hMediaWindow);
        SendMessage(g_hMediaWindow, APP_WM_CLOSE, 0, 0);
        Wh_Log(L"[UNINIT] Close sent to media window");
    }

    if (g_pMediaThread) {
        Wh_Log(L"[UNINIT] Waiting for media thread to exit...");
        if (g_pMediaThread->joinable()) {
            g_pMediaThread->join();
            Wh_Log(L"[UNINIT] Media thread joined successfully");
        }
        delete g_pMediaThread;
        g_pMediaThread = nullptr;
        Wh_Log(L"[UNINIT] Media thread cleaned up");
    } else {
        Wh_Log(L"[UNINIT] WARNING: g_pMediaThread is nullptr");
    }

    // Album art cleanup already handled in MediaThread cleanup lambda
    // (must be deleted BEFORE GdiplusShutdown, not after)
    
    // Reset audio reactive state
    Wh_Log(L"[UNINIT] Resetting audio reactive state");
    g_AudioPeakLevel = 0.0f;
    g_AudioPeakSmoothed = 0.0f;
    g_RainbowDirectionReverse = false;
    Wh_Log(L"[UNINIT] Audio reactive state reset");

    Wh_Log(L"[UNINIT] Uninitializing audio COM");
    g_audioCOM.Uninit();
    Wh_Log(L"[UNINIT] Audio COM uninitialized");

    Wh_Log(L"[UNINIT] Uninit complete");
    Wh_Log(L" --- END --- ");
}

void WhTool_ModSettingsChanged() {
    Wh_Log(L"[SETTINGS] Change event triggered");
    
    // CRITICAL: Pause any live animation timers
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        Wh_Log(L"[SETTINGS] Killing media window timers...");
        KillTimer(g_hMediaWindow, IDT_VIS_ANIM);
        KillTimer(g_hMediaWindow, IDT_TEXT_ANIM);
        KillTimer(g_hMediaWindow, IDT_POLL_MEDIA);
        KillTimer(g_hMediaWindow, IDT_DELAYED_ACTIONS);
        Wh_Log(L"[SETTINGS] Media window timers killed");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        Wh_Log(L"[SETTINGS] Killing rainbow window timer...");
        KillTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM);
        Wh_Log(L"[SETTINGS] Rainbow window timer killed");
    }
    
    // Reload settings with validation
    Wh_Log(L"[SETTINGS] Loading settings...");
    LoadSettings();  // Calls ValidateSettings() at end
    Wh_Log(L"[SETTINGS] Settings loaded and validated");
    
    // Refresh DPI scaling in case system DPI changed
    Wh_Log(L"[SETTINGS] Updating scale factor...");
    UpdateScaleFactor();
    Wh_Log(L"[SETTINGS] Scale factor updated to %.2f", g_ScaleFactor);
    
    // Reapply appearance
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        Wh_Log(L"[SETTINGS] Updating media window appearance...");
        UpdateAppearance(g_hMediaWindow);
        SyncPositionWithTaskbar();
        // Trigger repaint
        InvalidateRect(g_hMediaWindow, NULL, FALSE);
        Wh_Log(L"[SETTINGS] Media window appearance updated");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        Wh_Log(L"[SETTINGS] Updating rainbow window...");
        // Apply corner rounding update
        DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
        DwmSetWindowAttribute(g_hRainbowWindow, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));

        if (g_hMediaWindow && g_Settings.enableRainbow) {
            SetWindowPos(g_hRainbowWindow, GetRainbowZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            SetWindowPos(g_hMediaWindow, GetMediaZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            Wh_Log(L"[SETTINGS] Z-order adjusted");
        }
        
        // Reset audio reactive state on settings change
        g_AudioPeakLevel = 0.0f;
        g_AudioPeakSmoothed = 0.0f;
        g_RainbowDirectionReverse = false;
        if (g_Settings.enableAudioReactive && g_audioCOM.IsInitialized()) {
            g_audioCOM.InitMeter();
            Wh_Log(L"[SETTINGS] Audio reactive enabled");
        }
        
        InvalidateRect(g_hRainbowWindow, NULL, TRUE);
        Wh_Log(L"[SETTINGS] Rainbow window updated");
    }
    
    // Restart timers with new settings
    if (g_hMediaWindow && IsWindow(g_hMediaWindow)) {
        Wh_Log(L"[SETTINGS] Restarting media window timers...");
        SetTimer(g_hMediaWindow, IDT_POLL_MEDIA, TIMER_MEDIA_POLL_MS, NULL);
        Wh_Log(L"[SETTINGS] Media window timers restarted");
    }
    
    if (g_hRainbowWindow && IsWindow(g_hRainbowWindow)) {
        if (g_Settings.enableRainbow) {
            Wh_Log(L"[SETTINGS] Starting rainbow animation timer...");
            SetTimer(g_hRainbowWindow, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
            ShowWindow(g_hRainbowWindow, SW_SHOWNOACTIVATE);
            Wh_Log(L"[SETTINGS] Rainbow timer restarted and window shown");
        } else {
            ShowWindow(g_hRainbowWindow, SW_HIDE);
            Wh_Log(L"[SETTINGS] Rainbow disabled, window hidden");
        }
    }
    
    Wh_Log(L"[SETTINGS] Settings reload complete");
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
    Wh_Log(L"Tool mod process entry point hooked. Starting message loop.");


    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    Wh_Log(L"Tool mod message loop exited. Process will terminate.");
}

BOOL Wh_ModInit() {
    // Initialize Debug Log from Registry immediately
    g_Settings.enableAdvancedDebugLog = CheckRegistryDebugLog();
    if (g_Settings.enableAdvancedDebugLog) {
        Wh_Log(L"[INIT] Advanced Debug Logging Enabled via Registry Override");
    }

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

    WCHAR
    commandLine[MAX_PATH + 2 +
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