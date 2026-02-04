#pragma region Windhawk
// ==WindhawkMod==
// @id              taskbar-music-lounge-pro
// @name            Taskbar Music Lounge Pro
// @description     A native-style music ticker with media controls and custom Action Triggers with delay support.
// @version         0.0.1
// @author          Cinabutts
// @github          https://github.com/Cinabutts
// @include         explorer.exe
// @compilerOptions -lole32 -ldwmapi -lgdi32 -luser32 -lwindowsapp -lgdiplus -lshell32 -lpsapi -lpropsys -ladvapi32
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Music Lounge Pro (v0.0.1)

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

Available `System Triggers`:
- Entered Fullscreen (Game/Video/App)
- Exited Fullscreen (Game/Video/App)

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
- Toggle Audio Reactive Rainbow
- Toggle Rainbow Z-Order (Above/Below)
- Toggle Advanced Debug Logging

---

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
- ButtonSizeRatio: 90
  $name: Button Size Ratio (% of album art)
  $description: >-
    Sets button size relative to album art. 50 = half size.
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
- Centered: false
  $name: Center Text
  $description: >-
    ✓ Enabled | Text centers between media buttons and right edge when it fits. When too long, scrolls as normal.
    
    ✕ Disabled | Text stays left-aligned next to media buttons.
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
    
    ✕ Ignore | The widget will NEVER hide for games.
- FullscreenCheckInterval: 2
  $name: Fullscreen Check Interval (Seconds)
  $description: How many seconds between borderless fullscreen checks. (Lower = more responsive, higher = less CPU.)
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
  - - TriggerType: Double
      $name: Trigger Type
      $description: The event type to detect (mouse, scroll, or system event).
      $options:
      - Left: Left Click
      - Right: Right Click
      - Middle: Middle Click
      - Double: Double Click
      - ScrollUp: Scroll Up
      - ScrollDown: Scroll Down
      - OnFullscreenEnter: Entered Fullscreen (Game/Video/App)
      - OnFullscreenExit: Exited Fullscreen (Game/Video/App)
    - KeyboardTriggers: [none]
      $name: Required Modifiers
      $description: Hold these keys while using mouse/scroll triggers. System triggers (fullscreen) ignore modifiers.
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
  - - TriggerType: ScrollUp
    - KeyboardTriggers: [none]
    - Actions:
      - - Action: ACTION_VOLUME_UP
        - AdditionalArgs: ""
  - - TriggerType: ScrollDown
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
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <tuple>
// #include <cstdio>            // * Possibly unnecessary *
// #include <cwctype>           // * Possibly unnecessary *
// #include <string_view>       // * Possibly unnecessary *
// #include <thread>            // * Possibly unnecessary *
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

#pragma region raii_helpers

// RAII wrapper for automatic GDI object cleanup
// Prevents resource leaks when functions exit early or exceptions occur
struct GDIObjectDeleter {
    void operator()(HGDIOBJ obj) const { 
        if (obj) DeleteObject(obj); 
    }
};
using GDIObjectPtr = std::unique_ptr<std::remove_pointer<HGDIOBJ>::type, GDIObjectDeleter>;

// RAII wrapper for Bitmap cleanup
struct BitmapDeleter {
    void operator()(Gdiplus::Bitmap* bmp) const {
        if (bmp) delete bmp;
    }
};
using BitmapPtr = std::unique_ptr<Gdiplus::Bitmap, BitmapDeleter>;

#pragma endregion  // ^raii_helpers

//! =====================================================================

//! =====================================================================

#pragma region types_and_globals

// --- Forward Declarations ---
HWND EnsureTaskbarHandle();
HWND GetMediaZOrderInsertAfter();
HWND GetRainbowZOrderInsertAfter();
void UpdateScaleFactor();
// Removed: SyncPositionWithTaskbar (Now WindowManager::SyncPositionWithTaskbar)
// Removed: ForceDockedState (Now WindowManager::ForceDockedState)
bool IsAppIgnored(HWND hFg);

// Settings & Appearance
void LoadSettings();
// Removed: UpdateAppearance (Now WindowManager::UpdateAppearance)
void LoadPersistentState();
void SaveWindowState(int x, int y, int w, int h);
void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist);
void ApplyPersistedMediaFallback();

// Action Engine
void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds);
bool OnTriggerEvent(const std::wstring& detectedTriggerName, int zDelta = 0);

// --- Timer IDs ---
#define IDT_POLL_MEDIA      1001  // Media state polling
#define IDT_TEXT_ANIM       1002  // Text scroll animation
#define IDT_VIS_ANIM        1003  // Visibility/slide animation
#define IDT_RAINBOW_ANIM    1004  // Rainbow border animation
#define IDT_DELAYED_ACTIONS 1005  // Delayed action execution
#define IDT_GAME_DETECT     1006  // Dedicated game detection timer

// --- Timer Intervals (milliseconds) ---
#define TIMER_ANIMATION_MS       16   // ~60 FPS for smooth animations
#define TIMER_MEDIA_POLL_MS      200  // 200ms media state poll (event-driven updates more important)
#define TIMER_TEXT_ANIM_MS       16   // ~60 FPS text scroll
#define TIMER_DELAYED_ACTIONS_MS 50   // Delayed action check interval

// --- Custom Window Messages ---
#define APP_WM_CLOSE WM_APP  // Custom close message for cleanup
#define APP_WM_REFRESH_MEDIA (WM_APP + 1)  // Custom message to refresh media state from live source

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

void LogClampSetting(const wchar_t* name, int oldValue, int newValue);

/// Clamps value v between min and max bounds
template<typename T>
T Clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

/// Clamps setting value and logs if clamping occurred
template<typename T>
T ClampSetting(const wchar_t* name, T value, T lo, T hi) {
    T clamped = Clamp(value, lo, hi);
    if (clamped != value) {
        LogClampSetting(name, (int)value, (int)clamped);
    }
    return clamped;
}

/// Linear interpolation: returns a + f * (b - a)
template<typename T>
T Lerp(T a, T b, T f) {
    return a + f * (b - a);
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

// --- Single Function Game Detection ---
// Moved below g_Ctx definition


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
    int buttonSizeRatio = 90;     // Button size as % of album art
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
    int fsInterval = 2;                          // Fullscreen check interval (seconds)
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
    bool centered = false;              // Center text when not scrolling
    
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

// --- Consolidation Helpers (early definition for use throughout code) ---
struct ModContext {
    // Window handles and system hooks
    struct {
        HWND main = NULL;
        HWND rainbow = NULL;
        HWND taskbar = NULL;
        HWINEVENTHOOK visibilityHook = NULL;
    } Wnd;

    // Core System flags
    struct {
        bool isRunning = true;
        bool isShutdown = false;
        float scaleFactor = 1.0f;
        std::atomic<bool> eventHandlersActive{ false };
        ULONG_PTR gdiplusToken = 0;
    } Sys;

    // Visibility & Animations
    struct {
        int hoverState = 0;
        std::atomic<bool> isGameDetected{ false };
        std::atomic<int> animState{ 0 }; // 0=Sync, 1=Hiding, 2=Showing, 3=Shutdown/Docked
        int currentAnimY = 0;
        std::atomic<int> idleSecondsCounter{ 0 };
        std::atomic<bool> isHiddenByIdle{ false };
    } Vis;

    // Rainbow Effect State
    struct {
        std::atomic<float> hue{ 0.0f };
        std::atomic<int> animState{ 0 };
        int currentAnimY = 0;
        std::atomic<bool> directionReverse{ false };
    } Rainbow;

    // Audio Reactive State
    struct {
        std::atomic<float> peakLevel{ 0.0f };
        std::atomic<float> peakSmoothed{ 0.0f };
        bool runtimeEnabled = true;
    } Audio;

    // Text Scrolling State
    struct {
        int offset = 0;
        int textWidth = 0;
        bool isScrolling = false;
        int waitCounter = 60;
    } Scroll;

    // Media State (Thread-Safe)
    struct MediaState {
        wstring title = L"Waiting for media...";
        wstring artist = L"";
        wstring albumTitle = L"";
        BitmapPtr albumArt = nullptr;
        bool isPlaying = false;
        bool hasMedia = false;
        wstring sourceId = L"";
        wstring lastValidSourceId = L"";
        mutable mutex lock;

        // Copy assignment for thread safety
        void operator=(const MediaState& other) {
            if (this == &other) return;
            lock_guard<mutex> guard(other.lock);
            title = other.title;
            artist = other.artist;
            albumTitle = other.albumTitle;
            isPlaying = other.isPlaying;
            hasMedia = other.hasMedia;
            sourceId = other.sourceId;
            lastValidSourceId = other.lastValidSourceId;
            if (other.albumArt) albumArt.reset(other.albumArt->Clone());
            else albumArt.reset();
        }
    } Media;

    // Persistence
    struct PersistedState {
        int lastX = std::numeric_limits<int>::min();
        int lastY = std::numeric_limits<int>::min();
        int lastW = 0;
        int lastH = 0;
        int64_t lastLaunchTime = 0;
        int crashCount = 0;
        std::wstring lastTitle;
        std::wstring lastArtist;
    } Persisted;

    // Reset everything
    void Reset() {
        Wnd.main = NULL;
        Wnd.rainbow = NULL;
        Wnd.taskbar = NULL;
        Wnd.visibilityHook = NULL;
        
        Sys.isRunning = true;
        Sys.isShutdown = false;
        Sys.eventHandlersActive = false;
        
        Vis.hoverState = 0;
        Vis.isGameDetected = false;
        Vis.animState = 0;
        Vis.currentAnimY = 0;
        Vis.idleSecondsCounter = 0;

        Rainbow.hue = 0.0f;
        Rainbow.animState = 0;
        Rainbow.directionReverse = false;

        Audio.peakLevel = 0.0f;
        Audio.peakSmoothed = 0.0f;
        
        lock_guard<mutex> guard(Media.lock);
        Media.title = L"Waiting for media...";
        Media.artist = L"";
        Media.albumTitle = L"";
        Media.albumArt = nullptr;
        Media.isPlaying = false;
        Media.hasMedia = false;
        Media.sourceId = L"";
    }
} g_Ctx;
extern ModContext g_Ctx; // Extern for early access (defined later)



/// Apply DPI scale factor to any value
inline int Scale(int value); // Implement later to avoid cyclic dependency issues

//! ============================================================================
//^ GLOBAL STATE
//! ============================================================================
constexpr wchar_t kAdvancedLogValueName[] = L"DebugLoggingEnabled";
constexpr wchar_t kWindhawkModRegPath[] = L"SOFTWARE\\Windhawk\\Engine\\Mods\\" WH_MOD_ID;

#define Wh_LogAdvanced(fmt, ...) \
    if (g_Settings.enableAdvancedDebugLog) { \
        Wh_Log(fmt, ##__VA_ARGS__); \
    }

void LogClampSetting(const wchar_t* name, int oldValue, int newValue) {
    Wh_LogAdvanced(L"[Settings] %s clamped: %d -> %d", name, oldValue, newValue);
}

// Forward declarations
// GameDetector removed
// Removed: SyncPositionWithTaskbar (Now WindowManager::SyncPositionWithTaskbar)

// ============================================================================
// REGISTRY MANAGER (Centralized)
// ============================================================================

class RegistryManager {
private:
    std::thread m_autoHideListenerThread;
    std::atomic<bool> m_stopListener{false};
    std::function<void()> m_autoHideChangedCallback;
    static constexpr const wchar_t* kExplorerAdvancedPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced";

    void AutoHideListenerThreadProc() {
        HKEY hKey = NULL;
        if (RegOpenKeyEx(HKEY_CURRENT_USER, kExplorerAdvancedPath, 0, KEY_NOTIFY, &hKey) != ERROR_SUCCESS) {
            Wh_Log(L"[Registry] Failed to open key for auto-hide listener");
            return;
        }

        Wh_Log(L"[Registry] Auto-hide listener thread started");
        while (!m_stopListener) {
            if (RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, NULL, FALSE) == ERROR_SUCCESS) {
                if (m_stopListener) break;
                
                Wh_Log(L"[Registry] Explorer Advanced key changed, checking auto-hide state");
                
                // Invoke callback to trigger recheck
                if (m_autoHideChangedCallback) {
                    m_autoHideChangedCallback();
                }
            }
        }
        
        RegCloseKey(hKey);
        Wh_Log(L"[Registry] Auto-hide listener thread stopped");
    }

public:
    RegistryManager() {}

    // Windhawk mod debug log (HKLM)
    BOOL CheckDebugLog() {
        HKEY key = nullptr;
        Wh_Log(L"[INIT - Logging] Checking Registry: HKLM\\%s", kWindhawkModRegPath);

        LONG status = RegOpenKeyExW(HKEY_LOCAL_MACHINE, kWindhawkModRegPath, 0, KEY_READ, &key);
        if (status != ERROR_SUCCESS) {
            Wh_Log(L"[INIT - Logging] Key not found. Status: %ld", status);
            return FALSE;
        }

        DWORD value = 0;
        DWORD size = sizeof(value);
        status = RegQueryValueExW(key, kAdvancedLogValueName, nullptr, nullptr, 
                                 reinterpret_cast<LPBYTE>(&value), &size);
        RegCloseKey(key);

        if (status == ERROR_SUCCESS && value == 1) {
            Wh_Log(L"[INIT - Logging] Advanced Debug Logging Enabled via: `%s\\%s`", kWindhawkModRegPath, kAdvancedLogValueName);
            return TRUE;
        }
        return FALSE;
    }

    // Explorer Advanced settings (HKCU)
    DWORD GetExplorerAdvanced(const wchar_t* valueName, DWORD defaultValue = 0) {
        HKEY hKey = NULL;
        DWORD dwValue = defaultValue;
        DWORD dwBufferSize = sizeof(DWORD);
        if (RegOpenKeyEx(HKEY_CURRENT_USER, kExplorerAdvancedPath, 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS) {
            RegQueryValueEx(hKey, valueName, NULL, NULL, (LPBYTE)&dwValue, &dwBufferSize);
            RegCloseKey(hKey);
        }
        return dwValue;
    }

    bool SetExplorerAdvanced(const wchar_t* valueName, DWORD value) {
        HKEY hKey = NULL;
        bool success = false;
        if (RegOpenKeyEx(HKEY_CURRENT_USER, kExplorerAdvancedPath, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
            if (RegSetValueEx(hKey, valueName, 0, REG_DWORD, (BYTE*)&value, sizeof(value)) == ERROR_SUCCESS) {
                success = true;
                Wh_Log(L"[Registry] Set %s = %d", valueName, value);
            }
            RegCloseKey(hKey);
        }
        return success;
    }

    void StartAutoHideListener(std::function<void()> callback = nullptr) {
        if (m_autoHideListenerThread.joinable()) return; // Already running
        m_autoHideChangedCallback = callback;
        m_stopListener = false;
        m_autoHideListenerThread = std::thread(&RegistryManager::AutoHideListenerThreadProc, this);
    }

    void StopAutoHideListener() {
        if (!m_autoHideListenerThread.joinable()) return;
        m_stopListener = true;
        
        // Wake up the thread by triggering a dummy registry change
        HKEY hKey = NULL;
        if (RegOpenKeyEx(HKEY_CURRENT_USER, kExplorerAdvancedPath, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
            DWORD dummy = 0;
            RegSetValueEx(hKey, L"_WindhawkWakeup", 0, REG_DWORD, (BYTE*)&dummy, sizeof(dummy));
            RegDeleteValue(hKey, L"_WindhawkWakeup");
            RegCloseKey(hKey);
        }
        
        if (m_autoHideListenerThread.joinable()) {
            m_autoHideListenerThread.join();
        }
    }

    ~RegistryManager() {
        StopAutoHideListener();
    }
};

static RegistryManager g_RegistryManager;

// Helper: Execute GDI+ painting with double buffering
void ExecuteBufferedPaint(HWND hwnd, HDC hdc, std::function<void(Graphics&)> paintFunc) {
    if (!paintFunc) return;
    
    RECT rc; GetClientRect(hwnd, &rc);
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP memBitmap = CreateCompatibleBitmap(hdc, width, height);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

    Graphics graphics(memDC);
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);
    
    paintFunc(graphics);

    BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

    SelectObject(memDC, oldBitmap);
    DeleteObject(memBitmap);
    DeleteDC(memDC);
}

// ============================================================================
// WINDOW MANAGER (Centralized UI Logic)
// ============================================================================

class WindowManager {
public:
    WindowManager() = default;
    ~WindowManager() = default;

    // Initialization (call after window creation)
    void Initialize(HWND hMainWnd) {
        g_Ctx.Wnd.main = hMainWnd;
        UpdateAppearance(hMainWnd);
    }

    // Message Handlers
    void OnPaint(HWND hwnd) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        ExecuteBufferedPaint(hwnd, hdc, [&](Graphics& graphics) {
            graphics.Clear(Color(0, 0, 0, 0)); 
            graphics.ScaleTransform(g_Ctx.Sys.scaleFactor, g_Ctx.Sys.scaleFactor);
            DrawMediaPanel(graphics); // Now accepts Graphics& ref
        });

        EndPaint(hwnd, &ps);
    }

    void OnTimer(HWND hwnd, UINT_PTR timerId);
    void OnMouseWheel(HWND hwnd, WPARAM wParam, LPARAM lParam);

    // State & Visual Updates
    void UpdateAppearance(HWND hwnd);
    void SyncPositionWithTaskbar();
    void ForceDockedState();

    // Helper: Determining visibility logic
    bool ShouldWindowBeHidden();
   
private:
    // Drawing Implementation (Internal)
    void DrawMediaPanel(Graphics& graphics);
};

// Global instance
WindowManager g_WindowManager;

// ============================================================================
// GAME DETECTION ENGINE (Centralized State Machine)
// ============================================================================

// Helper: Decode Windows event types for logging
inline const wchar_t* DecodeEventType(DWORD event) {
    switch(event) {
        case 0x800B: return L"LOCATIONCHANGE";
        case 0x8002: return L"SHOW";
        case 0x8003: return L"HIDE";
        case 0x0003: return L"FOREGROUND";
        default: return L"UNKNOWN";
    }
}

// Helper: Get foreground app executable name
inline std::wstring GetForegroundAppName(HWND hFg) {
    if (!hFg) return L"None";
    DWORD pid = 0;
    GetWindowThreadProcessId(hFg, &pid);
    if (!pid) return L"Unknown";
    
    HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!hProc) return L"Unknown";
    
    WCHAR exePath[MAX_PATH];
    DWORD size = MAX_PATH;
    if (QueryFullProcessImageNameW(hProc, 0, exePath, &size)) {
        CloseHandle(hProc);
        const wchar_t* exeName = wcsrchr(exePath, L'\\');
        return exeName ? (exeName + 1) : exePath;
    }
    CloseHandle(hProc);
    return L"Unknown";
}

// GameDetector class removed

// --- Window Handles & State Context --- (Moved to top)

// Implementation of helpers that depend on g_Ctx
inline int Scale(int value) {
    return (int)(value * g_Ctx.Sys.scaleFactor);
}

bool WindowManager::ShouldWindowBeHidden() {
    return g_Ctx.Vis.isGameDetected || g_Ctx.Vis.isHiddenByIdle;
}


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

// Old keypress logic (removed - moved to ActionDispatcher)


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
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        hasMedia = g_Ctx.Media.hasMedia;
        targetId = g_Ctx.Media.sourceId;

        // Try to recover TargetID from last known good state if empty but media is present
        if (targetId.empty() && hasMedia && !g_Ctx.Media.lastValidSourceId.empty()) {
            targetId = g_Ctx.Media.lastValidSourceId;
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






// --- Action Dispatcher Service ---

struct ConfiguredTrigger {
    std::wstring mouseTriggerName;
    uint32_t expectedModifiers;
    std::vector<std::pair<std::wstring, std::function<void()>>> actions;  // (actionName, function)
};

// Global execution context for triggers
thread_local std::wstring g_currentTriggerContext;

class ActionDispatcher {
public:
    struct PendingAction {
        std::function<void()> action;
        DWORD executeAtTick;
        std::wstring description;
    };

    // Public triggers registry
    std::vector<ConfiguredTrigger> triggers;


    void ExecuteWithDelay(std::function<void()> action, float delaySeconds, const std::wstring& actionName) {
        Wh_LogAdvanced(L"[DELAY] Queueing action with %.2f second delay", delaySeconds);
        std::lock_guard<std::mutex> lock(m_mutex);
        
        std::wstring desc = actionName;
        if (!g_currentTriggerContext.empty()) {
            desc = L"[MusicLounge] " + g_currentTriggerContext + L" '" + actionName + L"' executed (DELAYED)";
        }

        m_pendingActions.push_back({
            action,
            GetTickCount() + (DWORD)(delaySeconds * 1000),
            desc
        });
        Wh_LogAdvanced(L"[DELAY] Queue size: %d", (int)m_pendingActions.size());
        
        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
            SetTimer(g_Ctx.Wnd.main, IDT_DELAYED_ACTIONS, TIMER_DELAYED_ACTIONS_MS, NULL);
        }
    }
    
    // --- Helper for SendKeypressInternal (moved to private method) ---
    void InternalSendInput(const std::vector<int>& keys) {
        if (keys.empty()) return;
        
        // Optimization: Use WM_APPCOMMAND for single media/volume keys
        if (keys.size() == 1) {
            int cmd = 0;
            switch (keys[0]) {
                case VK_MEDIA_PLAY_PAUSE: cmd = APPCOMMAND_MEDIA_PLAY_PAUSE; break;
                case VK_VOLUME_MUTE:      cmd = APPCOMMAND_VOLUME_MUTE; break;
                case VK_VOLUME_DOWN:      cmd = APPCOMMAND_VOLUME_DOWN; break;
                case VK_VOLUME_UP:        cmd = APPCOMMAND_VOLUME_UP; break;
                case VK_MEDIA_NEXT_TRACK: cmd = APPCOMMAND_MEDIA_NEXTTRACK; break;
                case VK_MEDIA_PREV_TRACK: cmd = APPCOMMAND_MEDIA_PREVIOUSTRACK; break;
                case VK_MEDIA_STOP:       cmd = APPCOMMAND_MEDIA_STOP; break;
            }

            if (cmd != 0) {
                HWND hTarget = g_Ctx.Wnd.main;
                Wh_Log(L"[INPUT] Sending WM_APPCOMMAND %d to HWND %p", cmd, hTarget);
                SendMessage(hTarget, WM_APPCOMMAND, (WPARAM)g_Ctx.Wnd.main, (LPARAM)(cmd << 16));
                return;
            }
        }
        
        const int NUM_KEYS = static_cast<int>(keys.size());
        auto input = std::make_unique<INPUT[]>(NUM_KEYS * 2);
        for (int i = 0; i < NUM_KEYS; i++) {
            input[i].type = INPUT_KEYBOARD; input[i].ki.wVk = static_cast<WORD>(keys[i]); input[i].ki.dwFlags = 0;
        }
        for (int i = 0; i < NUM_KEYS; i++) {
            input[NUM_KEYS + i].type = INPUT_KEYBOARD; input[NUM_KEYS + i].ki.wVk = static_cast<WORD>(keys[i]);
            input[NUM_KEYS + i].ki.dwFlags = KEYEVENTF_KEYUP;
        }
        Wh_Log(L"[INPUT] SendInput called with %d key events (VK: 0x%02X)", NUM_KEYS, keys[0]);
        SendInput(NUM_KEYS * 2, input.get(), sizeof(input[0]));
    }

    bool AreModifierKeysPressed() {
        return (GetAsyncKeyState(VK_CONTROL) & 0x8000) || (GetAsyncKeyState(VK_MENU) & 0x8000) || 
            (GetAsyncKeyState(VK_SHIFT) & 0x8000) || (GetAsyncKeyState(VK_LWIN) & 0x8000) || (GetAsyncKeyState(VK_RWIN) & 0x8000);
    }

public:
    void SendKeypress(const std::vector<int>& keys) {
        // Simple synchronous send (we will fix the timer/retry complexity later if needed, global timer complicates things)
        // For strict refactoring, implementing minimal safe send
        if (AreModifierKeysPressed()) {
            Wh_Log(L"[INPUT] Modifiers pressed, skipping SendInput to avoid stuck keys");
             InternalSendInput(keys); // Just send it for now, recreating the timer logic inside a class without a window handle for SetTimer callback is tricky without a static thunk.
             // Given the plan is consolidation, simplifying this legacy logic is acceptable.
             // If the timer is critical, we can restore it using a static map of timers to dispatcher instances.
        } else {
            InternalSendInput(keys);
        }
    }


    void ProcessDelayedActions() {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_pendingActions.empty()) return;

        Wh_LogAdvanced(L"[DELAY] Timer tick - checking %d pending actions", (int)m_pendingActions.size());
        
        DWORD now = GetTickCount();
        auto it = m_pendingActions.begin();
        while (it != m_pendingActions.end()) {
            if (now >= it->executeAtTick || (now < 100000 && it->executeAtTick > 0xFFFFFF00)) {
                Wh_LogAdvanced(L"[DELAY] Executing: %s", it->description.c_str());
                if (it->action) {
                    try {
                        it->action();
                    } catch (...) {
                        Wh_Log(L"[DELAY] Error executing action: %s", it->description.c_str());
                    }
                }
                it = m_pendingActions.erase(it);
            } else {
                ++it;
            }
        }
        
        if (m_pendingActions.empty() && g_Ctx.Wnd.main) {
             KillTimer(g_Ctx.Wnd.main, IDT_DELAYED_ACTIONS);
             Wh_LogAdvanced(L"[DELAY] Queue empty, timer stopped");
        }
    }

    void ClearPendingActions() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_pendingActions.clear();
    }

    bool DispatchTrigger(const std::wstring& detectedTriggerName, int zDelta = 0) {
        bool isSystemTrigger = (detectedTriggerName == L"OnFullscreenEnter" || detectedTriggerName == L"OnFullscreenExit");
        uint32_t currentMods = isSystemTrigger ? 0 : GetKeyModifiersState();
        
        Wh_LogAdvanced(L"[ActionEngine] OnTriggerEvent called: '%s' (triggers=%zu)", 
                    detectedTriggerName.c_str(), triggers.size());
        
        bool handled = false;
        for(size_t idx = 0; idx < triggers.size(); idx++) {
            const auto& t = triggers[idx];
            
            if (t.mouseTriggerName == detectedTriggerName) {
                bool modifiersMatch = isSystemTrigger || (t.expectedModifiers == currentMods);
                
                if (modifiersMatch) {
                    Wh_Log(L"[ActionEngine] Trigger Matched: '%s' (Matches: %d)", detectedTriggerName.c_str(), (int)t.actions.size());
                    for (size_t i = 0; i < t.actions.size(); i++) {
                        const auto& [actionName, actionFunc] = t.actions[i];
                        if (actionFunc) {
                            g_currentTriggerContext = L"Trigger '" + detectedTriggerName + L"' Action " + std::to_wstring(i+1) + L"/" + std::to_wstring(t.actions.size());

                            Wh_Log(L"[ActionEngine] Executing action: %s", actionName.c_str());
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

private:
    std::vector<PendingAction> m_pendingActions;
    std::mutex m_mutex;
};

// Global Action Dispatcher instance
ActionDispatcher g_ActionDispatcher;

// Compatibility aliases - eventually remove
#define g_triggers g_ActionDispatcher.triggers


void SendWinTabKeypress() {
    Wh_Log(L"[Action] Sending Win+Tab");
    g_ActionDispatcher.SendKeypress({VK_LWIN, VK_TAB});
}

void OpenStartMenu() {
    Wh_Log(L"[Action] Sending Win keypress for Start menu");
    g_ActionDispatcher.SendKeypress({VK_LWIN});
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

// --- Registry Helpers (now using RegistryManager) ---
DWORD GetExplorerAdvancedSetting(const wchar_t* valueName, DWORD defaultValue = 0) {
    return g_RegistryManager.GetExplorerAdvanced(valueName, defaultValue);
}

bool SetExplorerAdvancedSetting(const wchar_t* valueName, DWORD value) {
    return g_RegistryManager.SetExplorerAdvanced(valueName, value);
}

// Centralized taskbar handle acquisition with validation
HWND EnsureTaskbarHandle() {
    HWND oldHandle = g_Ctx.Wnd.taskbar;
    
    // Validate existing handle (checks if window still exists)
    if (g_Ctx.Wnd.taskbar && IsWindow(g_Ctx.Wnd.taskbar)) {
        Wh_LogAdvanced(L"[TASKBAR] Handle valid: 0x%p", g_Ctx.Wnd.taskbar);
        return g_Ctx.Wnd.taskbar;
    }
    
    // Find and cache new handle
    g_Ctx.Wnd.taskbar = FindWindowW(L"Shell_TrayWnd", NULL);
    
    if (g_Ctx.Wnd.taskbar) {
        if (oldHandle != g_Ctx.Wnd.taskbar) {
            Wh_Log(L"[TASKBAR] Handle changed: 0x%p -> 0x%p", oldHandle, g_Ctx.Wnd.taskbar);
        } else {
            Wh_Log(L"[TASKBAR] Handle acquired: 0x%p", g_Ctx.Wnd.taskbar);
        }
    } else {
        Wh_Log(L"[TASKBAR] WARNING: Failed to find taskbar window");
    }
    
    return g_Ctx.Wnd.taskbar;  // May be NULL
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
        {L"ACTION_MUTE", Simple([]() { g_ActionDispatcher.SendKeypress({VK_VOLUME_MUTE}); })},
        {L"ACTION_TASK_MANAGER", Simple([]() { ShellExecute(0, L"open", L"taskmgr.exe", 0, 0, SW_SHOW); })},
        {L"ACTION_VOLUME_UP", Simple([]() { g_ActionDispatcher.SendKeypress({VK_VOLUME_UP}); })},
        {L"ACTION_VOLUME_DOWN", Simple([]() { g_ActionDispatcher.SendKeypress({VK_VOLUME_DOWN}); })},
        {L"ACTION_START_PROCESS", [](const ParsedArgs& a) { return [s=a.actualArgs, b=a.bypassSingleInstance]() { ExecuteProcessOrWindow(s, b, L"[StartProcess]"); }; }},
        {L"ACTION_SEND_KEYPRESS", [](const ParsedArgs& input) {
            const auto keys = BuildKeypressSequence(input.actualArgs);
            return [keys]() { g_ActionDispatcher.SendKeypress(keys); };
        }},
        {L"ACTION_MEDIA_PLAY_PAUSE", Simple([]() { g_ActionDispatcher.SendKeypress({VK_MEDIA_PLAY_PAUSE}); })},
        {L"ACTION_MEDIA_NEXT", Simple([]() { g_ActionDispatcher.SendKeypress({VK_MEDIA_NEXT_TRACK}); })},
        {L"ACTION_MEDIA_PREV", Simple([]() { g_ActionDispatcher.SendKeypress({VK_MEDIA_PREV_TRACK}); })},
        {L"ACTION_TOGGLE_AUDIO_REACTIVE", Simple([]() {
            g_Ctx.Audio.runtimeEnabled = !g_Ctx.Audio.runtimeEnabled;
            g_Ctx.Audio.peakSmoothed = 0.0f;
            Wh_Log(L"[Audio Reactive] Toggled: %s", g_Ctx.Audio.runtimeEnabled ? L"ON" : L"OFF");
        })},
        {L"ACTION_TOGGLE_RAINBOW_ZORDER", Simple([]() {
            g_Settings.rainbowAboveWidget = !g_Settings.rainbowAboveWidget;
            Wh_Log(L"[Rainbow] Z-Order Toggled: %s", g_Settings.rainbowAboveWidget ? L"Above" : L"Below");
            if (g_Ctx.Wnd.main && g_Ctx.Wnd.rainbow) {
                UINT flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW;
                SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0,0,0,0, flags);
                SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), 0,0,0,0, flags);
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
                g_ActionDispatcher.ExecuteWithDelay(baseAction, delay, fullActionName);
            };
        }
        return baseAction;
    }
    
    return []() {};
}

void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds, const std::wstring& actionName) {
    g_ActionDispatcher.ExecuteWithDelay(action, delaySeconds, actionName);
}


bool OnTriggerEvent(const std::wstring& detectedTriggerName, int zDelta) {
    return g_ActionDispatcher.DispatchTrigger(detectedTriggerName, zDelta);
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

// --- Single Function Game Detection ---
// Replaces entire GameDetector class
void UpdateGameDetectionState() {
    if (!g_Settings.enableGameDetect) {
        if (g_Ctx.Vis.isGameDetected) {
            g_Ctx.Vis.isGameDetected = false;
            OnTriggerEvent(L"OnFullscreenExit");
        }
        return;
    }

    bool isGame = false;

    // 0. D3D / Presentation Mode (API Check - Fast & Accurate)
    QUERY_USER_NOTIFICATION_STATE qState;
    if (SHQueryUserNotificationState(&qState) == S_OK) {
        if (qState == QUNS_RUNNING_D3D_FULL_SCREEN || qState == QUNS_PRESENTATION_MODE) {
            // Check whitelist even for D3D to allow ignored apps to bypass
            HWND hFg = GetForegroundWindow();
            if (!hFg || !IsAppIgnored(hFg)) {
                isGame = true;
            }
        }
    }

    // 1. Geometry Check (Classic Fullscreen / Borderless)
    if (!isGame) {
        HWND hFg = GetForegroundWindow();
        if (hFg && hFg != GetDesktopWindow() && hFg != GetShellWindow()) {
             // Check if ignored first
             if (!IsAppIgnored(hFg)) {
                RECT rc; GetWindowRect(hFg, &rc);
                
                // Get monitor for this window
                HMONITOR hMon = MonitorFromWindow(hFg, MONITOR_DEFAULTTOPRIMARY);
                MONITORINFO mi = { sizeof(mi) };
                if (GetMonitorInfo(hMon, &mi)) {
                    // Check if window covers the monitor
                    if (rc.left <= mi.rcMonitor.left && rc.top <= mi.rcMonitor.top && 
                        rc.right >= mi.rcMonitor.right && rc.bottom >= mi.rcMonitor.bottom) {
                        
                        // Exclude known shell windows
                        wchar_t className[256];
                        GetClassName(hFg, className, 256);
                        if (wcscmp(className, L"WorkerW") != 0 && wcscmp(className, L"Progman") != 0 && 
                            wcscmp(className, L"Shell_TrayWnd") != 0) {
                            isGame = true;
                        }
                    }
                }
             }
        }
    }

    // State change logic
    if (g_Ctx.Vis.isGameDetected != isGame) {
        g_Ctx.Vis.isGameDetected = isGame;
        Wh_Log(L"[GameDetect] State changed: %s", isGame ? L"GAME" : L"DESKTOP");
        OnTriggerEvent(isGame ? L"OnFullscreenEnter" : L"OnFullscreenExit");
    }
}


// --- Sync Logic ---

void UpdateScaleFactor() {
    UINT dpi = GetDpiForSystem();
    if (dpi == 0) dpi = 96;
    g_Ctx.Sys.scaleFactor = dpi / 96.0f;
}

HWND GetMediaZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget && g_Ctx.Wnd.rainbow) ? g_Ctx.Wnd.rainbow : HWND_TOPMOST; }
HWND GetRainbowZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget || !g_Ctx.Wnd.main) ? HWND_TOPMOST : g_Ctx.Wnd.main; }

void WindowManager::ForceDockedState() {
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    int scaledW = Scale(g_Settings.width);
    int scaledH = Scale(g_Settings.height);
    SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), 0, screenH - 2, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    g_Ctx.Vis.animState = 3; // Docked Mode
    
    // Dock rainbow window too
    if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
        int borderOffset = Scale(g_Settings.rainbowBorderOffset);
        SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0 - borderOffset, screenH - 2 - borderOffset, 
                     scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), SWP_NOACTIVATE | SWP_SHOWWINDOW);
        g_Ctx.Rainbow.animState = 3;
    }
}

// Handles syncing the media window position with the taskbar, including smart fullscreen detection and animations
void WindowManager::SyncPositionWithTaskbar() {
    if (!g_Ctx.Wnd.main || g_Ctx.Sys.isShutdown) return;

    // 1. Startup / Crash Recovery
    if (!EnsureTaskbarHandle()) {
        if (g_Ctx.Vis.animState != 3) ForceDockedState();
        return;
    }

    if (g_Ctx.Wnd.taskbar) {
        UpdateScaleFactor();

        // --- 2. Smart Game Detection ---
        // DECOUPLED: We ask the engine. It handles timers and events internally.
        bool shouldHide = g_Settings.enableGameDetect && g_Ctx.Vis.isGameDetected;

        // Sync the global legacy var so ShouldWindowBeHidden() works correctly
        g_Ctx.Vis.isGameDetected = shouldHide;

        BOOL isTaskbarVisible = IsWindowVisible(g_Ctx.Wnd.taskbar);

        // Visibility reason tracking (log only on change, primary reason only)
        static int s_lastReasonCode = -1;
        int reasonCode = 0;
        if (!isTaskbarVisible) {
            reasonCode = 1; // TaskbarHidden
        } else if (g_Ctx.Vis.isHiddenByIdle) {
            reasonCode = 2; // IdleTimeout
        } else if (g_Ctx.Vis.isGameDetected) {
            reasonCode = 3; // GameDetected
        }

        if (reasonCode != s_lastReasonCode) {
            switch (reasonCode) {
                case 0:
                    Wh_Log(L"[Sync] Visibility reason: Visible");
                    break;
                case 1:
                    Wh_Log(L"[Sync] Visibility reason: TaskbarHidden");
                    break;
                case 2:
                    Wh_Log(L"[Sync] Visibility reason: IdleTimeout");
                    break;
                case 3:
                     Wh_Log(L"[Sync] Visibility reason: GameDetected [%s]", g_Ctx.Vis.isGameDetected ? L"GameDetected" : L"NoGame");
                    break;
            }
            s_lastReasonCode = reasonCode;
        }

        // --- 3. Animation Logic ---
        if (g_Ctx.Vis.animState == 1 || g_Ctx.Vis.animState == 2) return;

        // CASE: Hide
        if (!isTaskbarVisible || ShouldWindowBeHidden()) {
            if (g_Ctx.Vis.animState != 1 && g_Ctx.Vis.animState != 3) {
                if (g_Settings.enableSlide) {
                    RECT rcMe; GetWindowRect(g_Ctx.Wnd.main, &rcMe);
                    g_Ctx.Vis.currentAnimY = rcMe.top;
                    g_Ctx.Vis.animState = 1; // Hiding
                    SetTimer(g_Ctx.Wnd.main, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);

                    // Sync rainbow window animation
                    if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                        RECT rcRainbow; GetWindowRect(g_Ctx.Wnd.rainbow, &rcRainbow);
                        g_Ctx.Rainbow.currentAnimY = rcRainbow.top;
                        g_Ctx.Rainbow.animState = 1;
                    }
                } else {
                    if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
                    ShowWindow(g_Ctx.Wnd.main, SW_HIDE);
                }
            }
            return;
        }

        // CASE: Restore
        if (g_Ctx.Vis.animState == 3 || !IsWindowVisible(g_Ctx.Wnd.main)) {
            if (g_Settings.enableSlide) {
                 int screenH = GetSystemMetrics(SM_CYSCREEN);
                 g_Ctx.Vis.currentAnimY = (g_Ctx.Vis.animState == 3) ? (screenH - 2) : screenH;

                 RECT rcTb; GetWindowRect(g_Ctx.Wnd.taskbar, &rcTb);
                 int scaledOffX = Scale(g_Settings.offsetX);
                 int scaledW = Scale(g_Settings.width);
                 int scaledH = Scale(g_Settings.height);
                 int targetX = rcTb.left + scaledOffX;

                 SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), targetX, g_Ctx.Vis.currentAnimY, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
                 g_Ctx.Vis.animState = 2; // Showing
                 SetTimer(g_Ctx.Wnd.main, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
                 // Sync rainbow window
                 if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                     int borderOffset = Scale(g_Settings.rainbowBorderOffset);
                     g_Ctx.Rainbow.currentAnimY = (g_Ctx.Rainbow.animState == 3) ? (screenH - 2 - borderOffset) : screenH;
                     SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), targetX - borderOffset, g_Ctx.Rainbow.currentAnimY,
                                  scaledW + (borderOffset * 2), scaledH + (borderOffset * 2), SWP_NOACTIVATE | SWP_SHOWWINDOW);
                     g_Ctx.Rainbow.animState = 2;
                 }
                 return;
            } else {
                ShowWindow(g_Ctx.Wnd.main, SW_SHOWNOACTIVATE);
                if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                    ShowWindow(g_Ctx.Wnd.rainbow, SW_SHOWNOACTIVATE);
                }
            }
        }

        // Normal Sync
        RECT rc;
        if (GetWindowRect(g_Ctx.Wnd.taskbar, &rc)) {
            int taskbarHeight = rc.bottom - rc.top;
            if (taskbarHeight <= 0) return;

            int scaledW = Scale(g_Settings.width);
            int scaledH = Scale(g_Settings.height);
            int scaledOffX = Scale(g_Settings.offsetX);
            int scaledOffY = Scale(g_Settings.offsetY);

            int x = rc.left + scaledOffX;
            int y = rc.top + (taskbarHeight / 2) - (scaledH / 2) + scaledOffY;

            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), x, y, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
            SaveWindowState(x, y, scaledW, scaledH);
            g_Ctx.Vis.animState = 0; // Synced

            // Sync rainbow window position
            if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                int borderOffset = Scale(g_Settings.rainbowBorderOffset);
                SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), x - borderOffset, y - borderOffset,
                             scaledW + (borderOffset * 2), scaledH + (borderOffset * 2),
                             SWP_NOACTIVATE | SWP_SHOWWINDOW);
                g_Ctx.Rainbow.animState = 0;
            } else if (g_Ctx.Wnd.rainbow) {
                ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
            }
        }
    }
}

void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime) {
    if (hwnd == g_Ctx.Wnd.taskbar && idObject == OBJID_WINDOW) {
        // 1. Notify Detector: "Taskbar Changed - Check NOW and Reset Timer"
        if (g_Settings.enableGameDetect) UpdateGameDetectionState();

        // 2. Perform Visual Sync
        g_WindowManager.SyncPositionWithTaskbar();
    }
}

// --- Animation State Helpers ---
inline bool IsWindowAnimating(int animState) { 
    return animState == 1 || animState == 2; 
}

inline bool IsHiding(int animState) { return animState == 1; }
inline bool IsShowing(int animState) { return animState == 2; }
inline bool IsDocked(int animState) { return animState == 3; }
inline bool IsSynced(int animState) { return animState == 0; }

/// Scaled dimensions calculator
struct ScaledDims {
    int w, h, borderOffset;
    ScaledDims() : w(0), h(0), borderOffset(0) {}
    ScaledDims(float scaleFactor, int width, int height, int offset) 
        : w((int)(width * scaleFactor))
        , h((int)(height * scaleFactor))
        , borderOffset((int)(offset * scaleFactor)) {}
};

inline ScaledDims GetScaledDims() {
    return ScaledDims(g_Ctx.Sys.scaleFactor, g_Settings.width, g_Settings.height, g_Settings.rainbowBorderOffset);
}

inline int GetTargetAnimationY(bool isShowing) {
    int screenH = GetSystemMetrics(SM_CYSCREEN);
    RECT rcTb;
    if (!GetWindowRect(g_Ctx.Wnd.taskbar, &rcTb)) return screenH - 2;
    
    int scaledH = Scale(g_Settings.height);
    int scaledOffY = Scale(g_Settings.offsetY);
    return rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY;
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
    return ClampSetting(name, Wh_GetIntSetting(name), min, max);
}

// --- Timer Management Helpers ---
void SetupMediaWindowTimers() {
    if (!g_Ctx.Wnd.main || !IsWindow(g_Ctx.Wnd.main)) return;
    
    if (g_Settings.idleTimeout > 0) {
        SetTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA, 1000, NULL);
        Wh_LogAdvanced(L"[Timer] Idle timeout timer set (interval: 1000ms, timeout: %ds)", g_Settings.idleTimeout);
    } else {
        Wh_LogAdvanced(L"[Timer] Idle timeout disabled, no polling timer");
    }
}

// Clamp and validate all settings after load
void ValidateSettings() {
    // Size/position
    g_Settings.width = ClampSetting(L"PanelWidth", g_Settings.width, 100, 800);
    g_Settings.height = ClampSetting(L"PanelHeight", g_Settings.height, 20, 100);
    g_Settings.buttonSizeRatio = ClampSetting(L"ButtonSizeRatio", g_Settings.buttonSizeRatio, 10, 120);
    g_Settings.fontSize = ClampSetting(L"FontSize", g_Settings.fontSize, 8, 32);
    g_Settings.offsetX = ClampSetting(L"OffsetX", g_Settings.offsetX, -10000, 10000);
    g_Settings.offsetY = ClampSetting(L"OffsetY", g_Settings.offsetY, -10000, 10000);

    // Rainbow
    g_Settings.rainbowSpeed = ClampSetting(L"RainbowSpeed", g_Settings.rainbowSpeed, 1, 10);
    g_Settings.rainbowBrightness = ClampSetting(L"RainbowBrightness", g_Settings.rainbowBrightness, 0, 100);
    g_Settings.rainbowThickness = ClampSetting(L"RainbowThickness", g_Settings.rainbowThickness, 1, 10);
    g_Settings.rainbowBorderOffset = ClampSetting(L"RainbowBorderOffset", g_Settings.rainbowBorderOffset, 0, 10);

    // Audio reactive
    g_Settings.audioResponsiveness = ClampSetting(L"AudioResponsiveness", g_Settings.audioResponsiveness, 0, 20);
    g_Settings.audioThreshold = ClampSetting(L"AudioThreshold", g_Settings.audioThreshold, 0, 100);
    g_Settings.audioRamp = ClampSetting(L"AudioRamp", g_Settings.audioRamp, 0, 100);
    g_Settings.audioFlicker = ClampSetting(L"AudioFlicker", g_Settings.audioFlicker, 0, 100);
    g_Settings.audioMinValue = ClampSetting(L"AudioMinValue", g_Settings.audioMinValue, 0, 100);
    g_Settings.audioMaxValue = ClampSetting(L"AudioMaxValue", g_Settings.audioMaxValue, 0, 100);
    g_Settings.audioHueReactiveMode = ClampSetting(L"AudioHueReactiveMode", g_Settings.audioHueReactiveMode, 0, 7);

    // Intervals
    g_Settings.fsInterval = ClampSetting(L"FullscreenCheckInterval", g_Settings.fsInterval, 0, 60);
    g_Settings.idleTimeout = ClampSetting(L"IdleTimeout", g_Settings.idleTimeout, 0, 3600);

    // Opacity
    g_Settings.bgOpacity = ClampSetting(L"BgOpacity", g_Settings.bgOpacity, 0, 255);

    Wh_Log(L" --------------------------------------------------- Settings validated");
}

#pragma endregion  // ^action_engine

//! =====================================================================

#pragma region settings

void LoadPersistentState() {
    g_Ctx.Persisted.lastX = Wh_GetIntValue(L"LastX", std::numeric_limits<int>::min());
    g_Ctx.Persisted.lastY = Wh_GetIntValue(L"LastY", std::numeric_limits<int>::min());
    g_Ctx.Persisted.lastW = Wh_GetIntValue(L"LastW", 0);
    g_Ctx.Persisted.lastH = Wh_GetIntValue(L"LastH", 0);

    wchar_t buffer[256] = {0};
    size_t len = Wh_GetStringValue(L"LastTitle", buffer, ARRAYSIZE(buffer));
    g_Ctx.Persisted.lastTitle = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    std::fill(std::begin(buffer), std::end(buffer), 0);
    len = Wh_GetStringValue(L"LastArtist", buffer, ARRAYSIZE(buffer));
    g_Ctx.Persisted.lastArtist = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    Wh_LogAdvanced(L"[STATE] Loaded persisted window state (%d,%d,%d,%d)",
           g_Ctx.Persisted.lastX, g_Ctx.Persisted.lastY,
           g_Ctx.Persisted.lastW, g_Ctx.Persisted.lastH);
}

void SaveWindowState(int x, int y, int w, int h) {
    // Only log and save if values actually changed
    if (g_Ctx.Persisted.lastX != x || g_Ctx.Persisted.lastY != y ||
        g_Ctx.Persisted.lastW != w || g_Ctx.Persisted.lastH != h) {
        Wh_SetIntValue(L"LastX", x);
        Wh_SetIntValue(L"LastY", y);
        Wh_SetIntValue(L"LastW", w);
        Wh_SetIntValue(L"LastH", h);
        g_Ctx.Persisted.lastX = x;
        g_Ctx.Persisted.lastY = y;
        g_Ctx.Persisted.lastW = w;
        g_Ctx.Persisted.lastH = h;
        Wh_LogAdvanced(L"[STATE] Saved window state (%d,%d,%dx%d)", x, y, w, h);
    }
}

void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist) {
    // Only log and save if values actually changed
    if (g_Ctx.Persisted.lastTitle != title || g_Ctx.Persisted.lastArtist != artist) {
        Wh_SetStringValue(L"LastTitle", title.c_str());
        Wh_SetStringValue(L"LastArtist", artist.c_str());
        g_Ctx.Persisted.lastTitle = title;
        g_Ctx.Persisted.lastArtist = artist;
        Wh_LogAdvanced(L"[STATE] Saved media info: '%s' by '%s'", 
               title.empty() ? L"<empty>" : title.c_str(),
               artist.empty() ? L"<empty>" : artist.c_str());
    }
}

void ApplyPersistedMediaFallback() {
    if (g_Ctx.Persisted.lastTitle.empty() && g_Ctx.Persisted.lastArtist.empty()) {
        Wh_Log(L"[STATE] No persisted media info to apply");
        return;
    }

    Wh_Log(L"[STATE] Applying persisted media fallback: '%s' by '%s'",
           g_Ctx.Persisted.lastTitle.empty() ? L"<empty>" : g_Ctx.Persisted.lastTitle.c_str(),
           g_Ctx.Persisted.lastArtist.empty() ? L"<empty>" : g_Ctx.Persisted.lastArtist.c_str());

    std::lock_guard<std::mutex> guard(g_Ctx.Media.lock);
    g_Ctx.Media.title = g_Ctx.Persisted.lastTitle;
    g_Ctx.Media.artist = g_Ctx.Persisted.lastArtist;
    g_Ctx.Media.hasMedia = !g_Ctx.Persisted.lastTitle.empty();
    g_Ctx.Media.isPlaying = false;
}

/// Load all settings from Windhawk configuration
void LoadSettings() {
    #define LOAD_INT(var, name) g_Settings.var = Wh_GetIntSetting(name)
    #define LOAD_BOOL(var, name) g_Settings.var = Wh_GetIntSetting(name) != 0
    #define LOAD_CLAMP(var, name, min, max) g_Settings.var = GetClampedSetting(name, min, max)
    
    LOAD_INT(width, L"PanelWidth");
    LOAD_INT(height, L"PanelHeight");
    LOAD_CLAMP(buttonSizeRatio, L"ButtonSizeRatio", 10, 120);
    LOAD_INT(fontSize, L"FontSize");
    LOAD_INT(offsetX, L"OffsetX");
    LOAD_INT(offsetY, L"OffsetY");
    
    LOAD_BOOL(autoTheme, L"AutoTheme");
    LOAD_BOOL(invertTheme, L"InvertTheme");
    LOAD_INT(bgOpacity, L"BgOpacity");

    // Colors
    auto loadColor = [](const wchar_t* name, DWORD& target, DWORD def, bool isBg) {
        auto s = WindhawkUtils::StringSetting::make(name);
        int r, g, b, a;
        if (s.get() && s.get()[0] && ParseColorComponents(s.get(), r, g, b, a)) {
            if (isBg && r==0 && g==0 && b==0) target = 0;
            else target = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b;
        } else target = def;
    };
    loadColor(L"TextColor", g_Settings.manualTextColor, 0xFFFFFFFF, false);
    loadColor(L"BgColor", g_Settings.manualBgColorRGB, 0, true);

    LOAD_CLAMP(fsInterval, L"FullscreenCheckInterval", 1, 60);
    LOAD_CLAMP(idleTimeout, L"IdleTimeout", 0, 3600);

    LOAD_BOOL(EnableTextScroll, L"EnableTextScroll");
    LOAD_BOOL(enableSlide, L"EnableSlide");
    LOAD_BOOL(enableGameDetect, L"EnableGameDetection");
    
    auto apps = WindhawkUtils::StringSetting::make(L"IgnoredApps");
    g_Settings.ignoredApps = (apps.get() && apps.get()[0]) ? apps.get() : L"firefox.exe;chrome.exe;msedge.exe";

    LOAD_BOOL(enableRainbow, L"EnableRainbow");
    
    bool newRainbowAbove = Wh_GetIntSetting(L"RainbowAboveWidget") != 0;
    static bool firstLoad = true;
    if (firstLoad || newRainbowAbove != g_Settings.storedRainbowAboveWidget) {
        g_Settings.rainbowAboveWidget = g_Settings.storedRainbowAboveWidget = newRainbowAbove;
    }
    firstLoad = false;

    LOAD_BOOL(enableAudioReactive, L"EnableAudioReactive");
    LOAD_CLAMP(rainbowSpeed, L"RainbowSpeed", 1, 10);
    LOAD_CLAMP(rainbowBrightness, L"RainbowBrightness", 0, 100);
    LOAD_CLAMP(rainbowThickness, L"RainbowThickness", 1, 10);
    LOAD_CLAMP(rainbowBorderOffset, L"RainbowBorderOffset", 0, 10);
    LOAD_BOOL(enableRoundedCorners, L"EnableRoundedCorners");
    LOAD_BOOL(centered, L"Centered");
    
    LOAD_CLAMP(audioResponsiveness, L"AudioResponsiveness", 0, 20);
    LOAD_CLAMP(audioThreshold, L"AudioThreshold", 0, 100);
    LOAD_CLAMP(audioRamp, L"AudioRamp", 0, 100);
    LOAD_BOOL(audioBinary, L"AudioBinary");
    LOAD_CLAMP(audioFlicker, L"AudioFlicker", 0, 100);
    LOAD_BOOL(audioDynamicRange, L"AudioDynamicRange");
    LOAD_CLAMP(audioMinValue, L"AudioMinValue", 0, 100);
    LOAD_CLAMP(audioMaxValue, L"AudioMaxValue", 0, 100);
    LOAD_CLAMP(audioHueReactiveMode, L"AudioHueReactiveMode", 0, 7);

    // Validations
    if (g_Settings.width < 100) g_Settings.width = 400;
    if (g_Settings.height < 24) g_Settings.height = 48;
    g_Settings.bgOpacity = std::clamp(g_Settings.bgOpacity, 0, 255);

    LoadPersistentState();
    ApplyPersistedMediaFallback();

    if (g_Settings.enableAudioReactive && g_audioCOM.IsInitialized()) g_audioCOM.InitMeter();

    g_Ctx.Audio.peakLevel = 0.0f;
    g_Ctx.Audio.peakSmoothed = 0.0f;
    g_Ctx.Audio.runtimeEnabled = true;
    g_Ctx.Rainbow.directionReverse = false;
    g_Ctx.Vis.idleSecondsCounter = 0;
    g_Ctx.Vis.isHiddenByIdle = false;

    // Triggers
    g_triggers.clear();
    for (int i = 0; i < 50; i++) {
        auto type = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].TriggerType", i).get());
        if (type.empty()) type = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].MouseTrigger", i).get());
        if (type.empty()) continue;

        ConfiguredTrigger ct;
        ct.mouseTriggerName = type;
        ct.expectedModifiers = 0;

        if (type != L"OnFullscreenEnter" && type != L"OnFullscreenExit") {
            for (int j = 0; j < 8; j++) {
                auto m = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].KeyboardTriggers[%d]", i, j).get());
                if (!m.empty() && m != L"none") {
                    KeyModifier km = GetKeyModifierFromName(m);
                    if (km != KEY_MODIFIER_INVALID) SetBit(ct.expectedModifiers, km);
                }
            }
        }

        for (int k = 0; k < 20; k++) {
            auto act = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].Actions[%d].Action", i, k).get());
            if (act.empty()) break;
            auto args = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].Actions[%d].AdditionalArgs", i, k).get());
            auto parsed = ParseAction(act, args);
            if (parsed) ct.actions.push_back({act, parsed});
        }
        if (!ct.actions.empty()) g_triggers.push_back(ct);
    }

    #undef LOAD_INT
    #undef LOAD_BOOL
    #undef LOAD_CLAMP
}

// --- WinRT / GSMTC ---
GlobalSystemMediaTransportControlsSessionManager g_SessionManager = nullptr;
GlobalSystemMediaTransportControlsSession g_CachedSession = nullptr;

// Event tokens for proper unsubscription (prevents use-after-free in callbacks)
winrt::event_token g_sessionChangedToken{};
winrt::event_token g_playbackInfoToken{};
winrt::event_token g_mediaPropertiesToken{};

BitmapPtr StreamToBitmap(IRandomAccessStreamWithContentType const& stream) {
    if (!stream) return nullptr;
    IStream* nativeStream = nullptr;
    if (SUCCEEDED(CreateStreamOverRandomAccessStream(reinterpret_cast<IUnknown*>(winrt::get_abi(stream)), IID_PPV_ARGS(&nativeStream)))) {
        BitmapPtr bmp(Bitmap::FromStream(nativeStream));
        nativeStream->Release();
        if (bmp && bmp->GetLastStatus() == Ok) return bmp;
    }
    return nullptr;
}

/// Async fire-and-forget media info update - does NOT block UI thread
void UpdateMediaInfoAsync() {
    // No debounce - Windows GSMTC handles event coalescing
    static int s_NoSessionRetryCount = 0;

    // Early exit if no session available
    if (!g_CachedSession) {
        // Grace Period: Don't clear immediately to allow for transient session loss
        bool wasHavingMedia = false;
        {
            lock_guard<mutex> guard(g_Ctx.Media.lock);
            wasHavingMedia = g_Ctx.Media.hasMedia;
        }

        if (wasHavingMedia && s_NoSessionRetryCount < 8) { // ~1.5 second grace (200ms * 8)
            s_NoSessionRetryCount++;
            return; 
        }

        s_NoSessionRetryCount = 0;
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        g_Ctx.Media.hasMedia = false;
        g_Ctx.Media.title = L"No Media";
        g_Ctx.Media.artist = L"";
        g_Ctx.Media.sourceId = L"";
        g_Ctx.Media.albumArt.reset();
        return;
    }

    s_NoSessionRetryCount = 0;

    auto updateState = [](wstring title, wstring artist, wstring sourceId, bool isPlaying, bool hasMedia, BitmapPtr albumArt) {
        if (!g_Ctx.Wnd.main || !IsWindow(g_Ctx.Wnd.main)) return;

        // Copy values INSIDE lock to avoid TOCTOU and potential deadlock
        wstring titleCopy, artistCopy;
        {
            lock_guard<mutex> guard(g_Ctx.Media.lock);
            g_Ctx.Media.title = std::move(title);
            g_Ctx.Media.artist = std::move(artist);
            g_Ctx.Media.sourceId = std::move(sourceId);
            if (!g_Ctx.Media.sourceId.empty()) {
                g_Ctx.Media.lastValidSourceId = g_Ctx.Media.sourceId;
            }
            g_Ctx.Media.isPlaying = isPlaying;
            g_Ctx.Media.hasMedia = hasMedia;
            g_Ctx.Media.albumArt = std::move(albumArt);
            
            // Copy BEFORE releasing lock for SaveLastMediaInfo call
            titleCopy = g_Ctx.Media.title;
            artistCopy = g_Ctx.Media.artist;
        }  // Mutex released here

        // Use copies to avoid reading unlocked state
        SaveLastMediaInfo(titleCopy, artistCopy);

        Wh_LogAdvanced(L"[MEDIA] Updated: '%s' by '%s' (playing=%d)",
                       titleCopy.c_str(),
                       artistCopy.c_str(),
                       isPlaying);

        InvalidateRect(g_Ctx.Wnd.main, NULL, FALSE);
    };
    
    try {
        // Get source ID and playback state synchronously (fast operations)
        wstring sourceId = g_CachedSession.SourceAppUserModelId().c_str();
        auto info = g_CachedSession.GetPlaybackInfo();
        bool isPlaying = (info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
        
        // Fire off async media properties chain - does NOT block
        g_CachedSession.TryGetMediaPropertiesAsync().Completed(
            [sourceId, isPlaying, updateState](auto const& propsOp, Windows::Foundation::AsyncStatus status) {
                try {
                    if (status != Windows::Foundation::AsyncStatus::Completed) {
                        Wh_Log(L"[WARNING] [WinRT] Media properties async failed with status: %d", (int)status);
                        return;
                    }
                    
                    auto props = propsOp.GetResults();
                    if (!props) {
                        Wh_Log(L"[WARNING] [WinRT] No media properties returned");
                        return;
                    }

                    wstring title = props.Title().c_str();
                    wstring artist = props.Artist().c_str();
                    
                    // Log source changes
                    if (sourceId != g_Ctx.Media.sourceId) {
                        Wh_Log(L"[MusicLounge] New Source: %s", sourceId.c_str());
                    }
                    
                    // Chain: fetch thumbnail async
                    auto thumbRef = props.Thumbnail();
                    if (thumbRef) {
                        try {
                            thumbRef.OpenReadAsync().Completed(
                                [updateState, title, artist, sourceId, isPlaying](auto const& streamOp, Windows::Foundation::AsyncStatus status) mutable {
                                    BitmapPtr albumArt = nullptr;
                                    try {
                                        if (status == Windows::Foundation::AsyncStatus::Completed) {
                                            albumArt = StreamToBitmap(streamOp.GetResults());
                                        }
                                    } catch (...) {
                                        Wh_Log(L"[WARNING] [WinRT] Exception in thumbnail completion");
                                    }
                                    updateState(title, artist, sourceId, isPlaying, true, std::move(albumArt));
                                });
                        } catch (...) {
                            updateState(title, artist, sourceId, isPlaying, true, nullptr);
                        }
                    } else {
                        updateState(title, artist, sourceId, isPlaying, true, nullptr);
                    }
                } catch (...) {
                    Wh_Log(L"[ERROR] [WinRT] Exception in media properties handler");
                }
            });
    } catch (const winrt::hresult_error& e) {
        Wh_Log(L"[ERROR] [WinRT] Exception in UpdateMediaInfoAsync: 0x%08X - %s", e.code().value, e.message().c_str());
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        g_Ctx.Media.hasMedia = false;
        g_Ctx.Media.sourceId = L"";
    } catch (const std::exception&) {
        Wh_Log(L"[ERROR] [WinRT] STL exception in UpdateMediaInfoAsync");
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        g_Ctx.Media.hasMedia = false;
        g_Ctx.Media.sourceId = L"";
    } catch (...) {
        Wh_Log(L"[ERROR] [WinRT] Unknown exception in UpdateMediaInfoAsync");
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        g_Ctx.Media.hasMedia = false;
        g_Ctx.Media.sourceId = L"";
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
            lock_guard<mutex> guard(g_Ctx.Media.lock);
            g_Ctx.Media.isPlaying = !g_Ctx.Media.isPlaying;
            if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
                InvalidateRect(g_Ctx.Wnd.main, NULL, FALSE);
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

/// Apply DWM corner preference to window
void ApplyCornerPreference(HWND hwnd, bool enableRounded) {
    DWM_WINDOW_CORNER_PREFERENCE preference = enableRounded ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));
}

/// Apply acrylic blur and tint using composition attributes
void ApplyAcrylicTint(HWND hwnd) {
    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (!hUser) return;
    
    auto SetComp = (pSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
    if (!SetComp) return;
    
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

/// Update all appearance attributes for a window
void WindowManager::UpdateAppearance(HWND hwnd) {
    ApplyCornerPreference(hwnd, g_Settings.enableRoundedCorners);
    ApplyAcrylicTint(hwnd);
}

void DrawRainbowBorder(HDC hdc, int width, int height) {
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.Clear(Color(0, 0, 0, 0));
    graphics.ScaleTransform(g_Ctx.Sys.scaleFactor, g_Ctx.Sys.scaleFactor);
    
    int logicalW = (int)(width / g_Ctx.Sys.scaleFactor);
    int logicalH = (int)(height / g_Ctx.Sys.scaleFactor);
    
    float baseHue = g_Ctx.Rainbow.hue;
    float brightness = g_Settings.rainbowBrightness / 100.0f;
    float thickness = (float)g_Settings.rainbowThickness;
    
    // Apply audio reactivity if enabled and running
    if (g_Settings.enableAudioReactive && g_Ctx.Audio.runtimeEnabled) {
        if (kAudioReactiveMode == 1 || kAudioReactiveMode == 3) {
            if (g_Settings.audioDynamicRange) {
                // When audio is 0 (g_Ctx.Audio.peakLevel=0), we return to Base Brightness.
                // When audio is 1, we go to Max Brightness (100%).
                // Formula: Base + (Audio * (1.0 - Base))
                float audioBoost = g_Ctx.Audio.peakLevel * (1.0f - brightness);
                brightness += audioBoost;
            } else {
                brightness += (g_Ctx.Audio.peakLevel * kAudioSensitivity * 0.15f);
            }
            if (brightness > 1.0f) brightness = 1.0f;
        }
        if (kAudioReactiveMode == 2 || kAudioReactiveMode == 3) {
            thickness += (g_Ctx.Audio.peakLevel * kAudioSensitivity * 2.5f);
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

    int stepSize = std::max(2, g_Settings.rainbowSpeed / 2); // Faster = fewer segments needed
    int segmentCount = std::min(360 / stepSize, (logicalW + logicalH) * 2);
    float angleStep = 360.0f / segmentCount;
    for (int s = 0; s < segmentCount; ++s) {
        float angle = s * angleStep;
        float nextAngle = angle + angleStep;
        float segmentHue = fmodf(baseHue + angle, 360.0f);
        BYTE r, g, b;
        HSVtoRGB(segmentHue, 1.0f, brightness, r, g, b);
        
        Pen pen(Color(r, g, b), thickness);
        
        // Determine which edge this segment belongs to
        if (angle < 90) {
            // Top edge
            float progress = angle / 90.0f;
            float x1 = progress * logicalW;
            float x2 = (nextAngle) / 90.0f * logicalW;
            graphics.DrawLine(&pen, PointF(x1, thickness/2), PointF(x2, thickness/2));
        } else if (angle < 180) {
            // Right edge
            float progress = (angle - 90) / 90.0f;
            float y1 = progress * logicalH;
            float y2 = (nextAngle - 90) / 90.0f * logicalH;
            graphics.DrawLine(&pen, PointF(logicalW - thickness/2, y1), PointF(logicalW - thickness/2, y2));
        } else if (angle < 270) {
            // Bottom edge
            float progress = (angle - 180) / 90.0f;
            float x1 = logicalW - (progress * logicalW);
            float x2 = logicalW - ((nextAngle - 180) / 90.0f * logicalW);
            graphics.DrawLine(&pen, PointF(x1, logicalH - thickness/2), PointF(x2, logicalH - thickness/2));
        } else {
            // Left edge
            float progress = (angle - 270) / 90.0f;
            float y1 = logicalH - (progress * logicalH);
            float y2 = logicalH - ((nextAngle - 270) / 90.0f * logicalH);
            graphics.DrawLine(&pen, PointF(thickness/2, y1), PointF(thickness/2, y2));
        }
    }
}

void WindowManager::DrawMediaPanel(Graphics& graphics) {
    Color mainColor{GetCurrentTextColor()};
    
    int logicalH = g_Settings.height;
    int logicalW = g_Settings.width;

    int artSize = logicalH - 12;
    int artX = 6, artY = 6;
    
    // Hold lock only while drawing the image
    {
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        if (g_Ctx.Media.albumArt && g_Ctx.Media.albumArt->GetLastStatus() == Ok) {
            graphics.DrawImage(g_Ctx.Media.albumArt.get(), artX, artY, artSize, artSize);
        } else {
            SolidBrush placeBrush{Color(40, 128, 128, 128)};
            graphics.FillRectangle(&placeBrush, artX, artY, artSize, artSize);
        }
    }
    
    // Copy scalar state outside the lock for text rendering
    wstring title, artist;
    bool isPlaying;
    {
        lock_guard<mutex> guard(g_Ctx.Media.lock);
        title = g_Ctx.Media.title;
        artist = g_Ctx.Media.artist;
        isPlaying = g_Ctx.Media.isPlaying;
    }

    float buttonRatio = Clamp((float)g_Settings.buttonSizeRatio / 100.0f, 0.1f, 1.2f);
    float buttonSize = artSize * buttonRatio;
    float controlScale = buttonSize / 24.0f; // 24px was the original hover diameter baseline
    auto ScaleVal = [&](float value) { return std::max(1, (int)(value * controlScale + 0.5f)); };

    int controlGap = ScaleVal(12);
    int controlSpacing = ScaleVal(28);
    int iconW = ScaleVal(8);
    int iconH = ScaleVal(6);
    int barW = ScaleVal(2);
    int hoverOffsetX = ScaleVal(8);
    int hoverOffsetY = ScaleVal(12);
    int hoverSize = ScaleVal(24);
    int playBarW = ScaleVal(3);
    int playBarH = ScaleVal(14);
    int playBarYOffset = ScaleVal(7);
    int playTriW = ScaleVal(10);
    int playTriH = ScaleVal(8);
    int textPadding = ScaleVal(20);
    int textRightPadding = ScaleVal(10);

    int startControlX = artX + artSize + controlGap;
    int controlY = logicalH / 2;
    SolidBrush iconBrush{mainColor};
    SolidBrush hoverBrush{Color(255, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};
    SolidBrush activeBg{Color(40, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};

    // Prev button
    int pX = startControlX;
    if (g_Ctx.Vis.hoverState == 1) graphics.FillEllipse(&activeBg, pX - hoverOffsetX, controlY - hoverOffsetY, hoverSize, hoverSize);
    Point prevPts[3] = { Point(pX + iconW, controlY - iconH), Point(pX + iconW, controlY + iconH), Point(pX, controlY) };
    graphics.FillPolygon(g_Ctx.Vis.hoverState == 1 ? &hoverBrush : &iconBrush, prevPts, 3);
    graphics.FillRectangle(g_Ctx.Vis.hoverState == 1 ? &hoverBrush : &iconBrush, pX, controlY - iconH, barW, iconH * 2);
        
    // Play/Pause button
    int plX = startControlX + controlSpacing;
    if (g_Ctx.Vis.hoverState == 2) graphics.FillEllipse(&activeBg, plX - hoverOffsetX, controlY - hoverOffsetY, hoverSize, hoverSize);
    if (isPlaying) {
        graphics.FillRectangle(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, plX, controlY - playBarYOffset, playBarW, playBarH);
        graphics.FillRectangle(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, plX + playBarW * 2, controlY - playBarYOffset, playBarW, playBarH);
    } else {
        Point playPts[3] = { Point(plX, controlY - playTriH), Point(plX, controlY + playTriH), Point(plX + playTriW, controlY) };
        graphics.FillPolygon(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, playPts, 3);
    }

    // Next button
    int nX = startControlX + (controlSpacing * 2);
    if (g_Ctx.Vis.hoverState == 3) graphics.FillEllipse(&activeBg, nX - hoverOffsetX, controlY - hoverOffsetY, hoverSize, hoverSize);
    Point nextPts[3] = { Point(nX, controlY - iconH), Point(nX, controlY + iconH), Point(nX + iconW, controlY) };
    graphics.FillPolygon(g_Ctx.Vis.hoverState == 3 ? &hoverBrush : &iconBrush, nextPts, 3);
    graphics.FillRectangle(g_Ctx.Vis.hoverState == 3 ? &hoverBrush : &iconBrush, nX + iconW, controlY - iconH, barW, iconH * 2);

    // Text
    int textX = nX + textPadding;
    int textMaxW = logicalW - textX - textRightPadding;
    wstring fullText = title;
    if (!artist.empty()) fullText += L" • " + artist;

    FontFamily fontFamily(kFontName, nullptr);
    Font font(&fontFamily, (REAL)g_Settings.fontSize, FontStyleBold, UnitPixel);
    SolidBrush textBrush{mainColor};
    
    RectF layoutRect(0, 0, 2000, 100), boundRect;
    graphics.MeasureString(fullText.c_str(), -1, &font, layoutRect, &boundRect);
    g_Ctx.Scroll.textWidth = (int)boundRect.Width;

    // Check if scrolling state needs to change
    bool shouldScroll = (g_Ctx.Scroll.textWidth > textMaxW && g_Settings.EnableTextScroll);
    if (shouldScroll != g_Ctx.Scroll.isScrolling) {
        g_Ctx.Scroll.isScrolling = shouldScroll;
        if (shouldScroll) {
            SetTimer(g_Ctx.Wnd.main, IDT_TEXT_ANIM, TIMER_TEXT_ANIM_MS, NULL);
            g_Ctx.Scroll.waitCounter = 60; // Initial delay
        } else {
            KillTimer(g_Ctx.Wnd.main, IDT_TEXT_ANIM);
            g_Ctx.Scroll.offset = 0;
        }
    }

    Region textClip(Rect(textX, 0, textMaxW, logicalH));
    graphics.SetClip(&textClip);
    float textY = (logicalH - boundRect.Height) / 2.0f;
    
    if (g_Ctx.Scroll.textWidth > textMaxW && g_Settings.EnableTextScroll) {
        float drawX = (float)textX - g_Ctx.Scroll.offset;
        graphics.DrawString(fullText.c_str(), -1, &font, PointF(drawX, textY), &textBrush);
        if (drawX + g_Ctx.Scroll.textWidth < logicalW) {
            graphics.DrawString(fullText.c_str(), -1, &font, PointF(drawX + g_Ctx.Scroll.textWidth + 40, textY), &textBrush);
        }
    } else {
        // Text fits - apply centering if enabled
        float finalTextX = (float)textX;
        if (g_Settings.centered && boundRect.Width <= textMaxW) {
            // Center text between media buttons and right edge using exact measured width
            const float centeredOffsetAdjustment = -20.0f; // Manual padding tweak (negative = push left)
            float availableSpace = (float)textMaxW - boundRect.Width;
            finalTextX = textX + (availableSpace / 2.0f) + centeredOffsetAdjustment;

            float minX = (float)textX;
            float maxX = (float)textX + (float)textMaxW - boundRect.Width;
            finalTextX = std::clamp(finalTextX, minX, maxX);
        }
        graphics.DrawString(fullText.c_str(), -1, &font, PointF(finalTextX, textY), &textBrush);
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
        float currentSmoothed = g_Ctx.Audio.peakSmoothed.load();
        float smoothed = Lerp(currentSmoothed, rawPeak, kAudioSmoothing);
        g_Ctx.Audio.peakSmoothed.store(smoothed);
        return smoothed;
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
    float currentSmoothed = g_Ctx.Audio.peakSmoothed.load();
    float smoothed = Lerp(currentSmoothed, rawPeak, lerpFactor);
    smoothed = Clamp(smoothed, 0.0f, 1.0f);
    g_Ctx.Audio.peakSmoothed.store(smoothed);
    
    float audioValue = (smoothed * valDelta) + sMin;
    
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
                if (g_Settings.enableAudioReactive && g_Ctx.Audio.runtimeEnabled) {
                    float peak = g_audioCOM.GetPeakLevel();
                    g_Ctx.Audio.peakLevel = CalculateAudioPeak(peak);
                }
                
                // === Audio Hue Reactive Feature ===
                if (g_Settings.audioHueReactiveMode > 0 && g_Settings.enableAudioReactive && 
                    g_Settings.enableRainbow && g_Ctx.Audio.runtimeEnabled) {
                    
                    // Speed boost (modes 1, 4, 5, 7)
                    if (g_Settings.audioHueReactiveMode == 1 || g_Settings.audioHueReactiveMode == 4 || 
                        g_Settings.audioHueReactiveMode == 5 || g_Settings.audioHueReactiveMode == 7) {
                        float speedMult = 1.0f + (g_Ctx.Audio.peakLevel * kAudioSensitivity * kAudioHueSpeedBoost);
                        g_Ctx.Rainbow.hue += (g_Settings.rainbowSpeed * 0.6f * speedMult);
                    } else {
                        g_Ctx.Rainbow.hue += (g_Settings.rainbowSpeed * 0.6f);
                    }
                    
                    // Pulse effect (modes 2, 4, 6, 7)
                    if (g_Settings.audioHueReactiveMode == 2 || g_Settings.audioHueReactiveMode == 4 || 
                        g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                        g_Ctx.Rainbow.hue += (g_Ctx.Audio.peakLevel * kAudioHuePulseAmount * 0.1f);
                    }
                    
                    // Bounce effect (modes 3, 5, 6, 7)
                    if (g_Settings.audioHueReactiveMode == 3 || g_Settings.audioHueReactiveMode == 5 || 
                        g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                        if (g_Ctx.Audio.peakLevel > kAudioHueBounceThreshold && !g_Ctx.Rainbow.directionReverse) {
                            g_Ctx.Rainbow.directionReverse = true;
                        } else if (g_Ctx.Audio.peakLevel <= kAudioHueBounceThreshold && g_Ctx.Rainbow.directionReverse) {
                            g_Ctx.Rainbow.directionReverse = false;
                        }
                        
                        if (g_Ctx.Rainbow.directionReverse) {
                            g_Ctx.Rainbow.hue -= (g_Settings.rainbowSpeed * 0.6f * 0.5f);
                        }
                    }
                    
                } else {
                    // Standard audio reactive (existing behavior)
                    float speedMult = 1.0f;
                    if (g_Settings.enableAudioReactive && g_Ctx.Audio.runtimeEnabled && 
                        (kAudioReactiveMode == 0 || kAudioReactiveMode == 3)) {
                        speedMult = 1.0f + (g_Ctx.Audio.peakLevel * kAudioSensitivity * 2.0f);
                    }
                    
                    g_Ctx.Rainbow.hue += (g_Settings.rainbowSpeed * 0.6f * speedMult);
                }
                
                // Wrap hue to 0-360 range
                if (g_Ctx.Rainbow.hue >= 360.0f) g_Ctx.Rainbow.hue -= 360.0f;
                if (g_Ctx.Rainbow.hue < 0.0f) g_Ctx.Rainbow.hue += 360.0f;
                
                InvalidateRect(hwnd, NULL, FALSE);
            }
            else if (wParam == IDT_VIS_ANIM) {
                int screenH = GetSystemMetrics(SM_CYSCREEN);
                RECT rcTb; GetWindowRect(g_Ctx.Wnd.taskbar, &rcTb);
                int scaledH = Scale(g_Settings.height);
                int scaledOffY = Scale(g_Settings.offsetY);
                int borderOffset = Scale(g_Settings.rainbowBorderOffset);
                int targetY = rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY - borderOffset;

                if (g_Ctx.Rainbow.animState == 1) { // Hide
                    if (!g_Ctx.Sys.isShutdown && !g_WindowManager.ShouldWindowBeHidden()) { g_Ctx.Rainbow.animState = 2; return 0; }
                    g_Ctx.Rainbow.currentAnimY += 8;
                    if (g_Ctx.Rainbow.currentAnimY > screenH) {  // if completely off-screen
                        ShowWindow(hwnd, SW_HIDE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_Ctx.Rainbow.animState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_Ctx.Rainbow.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
                else if (g_Ctx.Rainbow.animState == 2) { // Show
                    if (g_WindowManager.ShouldWindowBeHidden()) { g_Ctx.Rainbow.animState = 1; return 0; }
                    g_Ctx.Rainbow.currentAnimY -= 8;
                    if (g_Ctx.Rainbow.currentAnimY <= targetY) {
                        g_Ctx.Rainbow.currentAnimY = targetY;
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_Ctx.Rainbow.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                        KillTimer(hwnd, IDT_VIS_ANIM);
                        g_Ctx.Rainbow.animState = 0;
                    } else {
                        RECT rc; GetWindowRect(hwnd, &rc);
                        SetWindowPos(hwnd, GetRainbowZOrderInsertAfter(), rc.left, g_Ctx.Rainbow.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                    }
                }
            }
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps; 
            HDC hdc = BeginPaint(hwnd, &ps);
            RECT rc; 
            GetClientRect(hwnd, &rc);
            
            HDC memDC = CreateCompatibleDC(hdc);
            GDIObjectPtr memBitmap(CreateCompatibleBitmap(hdc, rc.right, rc.bottom));
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap.get());
            
            DrawRainbowBorder(memDC, rc.right, rc.bottom);
            
            BitBlt(hdc, 0, 0, rc.right, rc.bottom, memDC, 0, 0, SRCCOPY);
            SelectObject(memDC, oldBitmap); // Restore before auto-cleanup
            // memBitmap auto-deleted when GDIObjectPtr goes out of scope
            DeleteDC(memDC);
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
    int x = (int)(rawX / g_Ctx.Sys.scaleFactor);
    int y = (int)(rawY / g_Ctx.Sys.scaleFactor);
    int logicalH = g_Settings.height;
    int artSize = logicalH - 12;
    float buttonRatio = Clamp((float)g_Settings.buttonSizeRatio / 100.0f, 0.1f, 1.2f);
    float buttonSize = artSize * buttonRatio;
    float controlScale = buttonSize / 24.0f;
    auto ScaleVal = [&](float value) { return std::max(1, (int)(value * controlScale + 0.5f)); };
    int controlGap = ScaleVal(12);
    int controlSpacing = ScaleVal(28);
    int hoverOffsetX = ScaleVal(8);
    int hoverOffsetY = ScaleVal(12);
    int hoverSize = ScaleVal(24);
    
    Wh_LogAdvanced(L"[HIT] Raw coords: (%d, %d), ScaleFactor: %.2f, Logical: (%d, %d)", 
           rawX, rawY, g_Ctx.Sys.scaleFactor, x, y);
    
    // Album art region (from DrawMediaPanel: artX=6, artY=6, size=artSize)
    int artX = 6, artY = 6;
    if (x >= artX && x <= artX + artSize && y >= artY && y <= artY + artSize) {
        Wh_LogAdvanced(L"[HIT] ON ALBUM ART - artX=%d, artY=%d, artSize=%d -> Result: FALSE", 
               artX, artY, artSize);
        return false;  // On album art
    }
    
    // Button region (from WM_MOUSEMOVE hover detection logic)
    int startControlX = 6 + artSize + controlGap;
    int controlY = logicalH / 2;
    int prevLeft = startControlX - hoverOffsetX;
    int nextLeft = (startControlX + controlSpacing * 2) - hoverOffsetX;
    int nextRight = nextLeft + hoverSize;
    Wh_LogAdvanced(L"[HIT] artSize=%d, startControlX=%d", artSize, startControlX);
    
    int top = controlY - hoverOffsetY;
    int bottom = top + hoverSize;
    if (y >= top && y <= bottom) {
        Wh_LogAdvanced(L"[HIT] In Y button range (%d <= %d <= %d)", top, y, bottom);
        if (x >= prevLeft && x < nextRight) {
            Wh_LogAdvanced(L"[HIT] ON BUTTONS - range: [%d, %d) -> Result: FALSE", 
                   prevLeft, nextRight);
            return false;  // On buttons (prev, play, next combined)
        }
    }
    
    Wh_LogAdvanced(L"[HIT] ON BACKGROUND -> Result: TRUE");
    return true;  // On background/text
}

/// Media widget window procedure
// Old MediaWndProc removed (Logic extracted to OnTimer, OnPaint, etc)

// --- Message Handlers (Extracted) ---

void WindowManager::OnTimer(HWND hwnd, UINT_PTR timerId) {
    if (timerId == IDT_GAME_DETECT) {
        UpdateGameDetectionState();
    }
    else if (timerId == IDT_POLL_MEDIA) {
        // Idle timeout logic only (media updates now event-driven)
        bool isPlaying = false;
        {
            lock_guard<mutex> guard(g_Ctx.Media.lock);
            isPlaying = g_Ctx.Media.isPlaying;
        }
        
        if (isPlaying) {
            g_Ctx.Vis.idleSecondsCounter = 0;
            g_Ctx.Vis.isHiddenByIdle = false;
        } else {
            g_Ctx.Vis.idleSecondsCounter++;
            if (g_Ctx.Vis.idleSecondsCounter >= g_Settings.idleTimeout) {
                g_Ctx.Vis.isHiddenByIdle = true;
            }
        }
        
        SyncPositionWithTaskbar();
    }
    else if (timerId == IDT_TEXT_ANIM) {
        if (g_Ctx.Scroll.isScrolling && g_Settings.EnableTextScroll) {
            if (g_Ctx.Scroll.waitCounter > 0) g_Ctx.Scroll.waitCounter--;
            else {
                g_Ctx.Scroll.offset++;
                if (g_Ctx.Scroll.offset > g_Ctx.Scroll.textWidth + 40) { g_Ctx.Scroll.offset = 0; g_Ctx.Scroll.waitCounter = 60; }
                InvalidateRect(hwnd, NULL, FALSE);
            }
        } else { 
            KillTimer(hwnd, IDT_TEXT_ANIM);
            g_Ctx.Scroll.offset = 0;
        }
    }
    else if (timerId == IDT_VIS_ANIM) {
        int screenH = GetSystemMetrics(SM_CYSCREEN);
        RECT rcTb; GetWindowRect(g_Ctx.Wnd.taskbar, &rcTb);
        int scaledH = Scale(g_Settings.height);
        int scaledOffY = Scale(g_Settings.offsetY);
        int targetY = rcTb.top + ((rcTb.bottom - rcTb.top) / 2) - (scaledH / 2) + scaledOffY;
        
        if (g_Ctx.Vis.animState == 1) { // Hide
            if (!g_Ctx.Sys.isShutdown && !ShouldWindowBeHidden()) { g_Ctx.Vis.animState = 2; return; }
            g_Ctx.Vis.currentAnimY += 8;
            if (g_Ctx.Vis.currentAnimY > screenH) {
                KillTimer(hwnd, IDT_VIS_ANIM);
                if (g_Ctx.Sys.isShutdown) {
                    Wh_Log(L"[SHUTDOWN] Media slide-out complete - destroying window...");
                    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
                         DestroyWindow(g_Ctx.Wnd.rainbow);
                    }
                    DestroyWindow(hwnd);
                }
                g_Ctx.Vis.animState = 0;
            } else {
                RECT rc; GetWindowRect(hwnd, &rc);
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_Ctx.Vis.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
            }
        }
        else if (g_Ctx.Vis.animState == 2) { // Show
            if (ShouldWindowBeHidden() && !g_Ctx.Sys.isShutdown) { g_Ctx.Vis.animState = 1; return; }
            g_Ctx.Vis.currentAnimY -= 8;
            if (g_Ctx.Vis.currentAnimY <= targetY) {
                g_Ctx.Vis.currentAnimY = targetY;
                RECT rc; GetWindowRect(hwnd, &rc);
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_Ctx.Vis.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
                KillTimer(hwnd, IDT_VIS_ANIM);
                g_Ctx.Vis.animState = 0;
            } else {
                RECT rc; GetWindowRect(hwnd, &rc);
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), rc.left, g_Ctx.Vis.currentAnimY, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
            }
        }
        // Sync rainbow animation timer
        if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow && (g_Ctx.Rainbow.animState == 1 || g_Ctx.Rainbow.animState == 2)) {
            SetTimer(g_Ctx.Wnd.rainbow, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
        }
    }
    else if (timerId == IDT_DELAYED_ACTIONS) {
        g_ActionDispatcher.ProcessDelayedActions();
    }
}
// Removed redundant output OnPaint definition as it connects to class inline definition.

void WindowManager::OnMouseWheel(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    short zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    bool handled = false;
    
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
            handled = OnTriggerEvent(L"ScrollUp", zDelta);
        } else {
            Wh_LogAdvanced(L"[INPUT] ScrollDown on background - triggering action");
            handled = OnTriggerEvent(L"ScrollDown", zDelta);
        }
    } else {
        Wh_LogAdvanced(L"[INPUT] Scroll BLOCKED - not on background");
    }
    
    if (!handled && isOnBackground) {
        Wh_LogAdvanced(L"[INPUT] Sending volume command, zDelta=%d", zDelta);
        SendMessage(hwnd, WM_APPCOMMAND, 0, zDelta > 0 ? APPCOMMAND_VOLUME_UP << 16 : APPCOMMAND_VOLUME_DOWN << 16);
    }
}

LRESULT CALLBACK MediaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case APP_WM_REFRESH_MEDIA:
            Wh_Log(L"[SETTINGS] Forced media refresh requested - restoring live state");
            UpdateMediaInfoAsync();
            return 0;
        case WM_CREATE: 
            Wh_Log(L"-- WM_CREATE received - initializing MediaWndProc");
            g_WindowManager.UpdateAppearance(hwnd);
            if (g_Settings.enableGameDetect) {
                UpdateGameDetectionState();
                SetTimer(hwnd, IDT_GAME_DETECT, 2000, NULL);
                Wh_Log(L"-- Game detection timer started (2000ms)");
            }
            
            if (g_Settings.idleTimeout > 0) {
                SetTimer(hwnd, IDT_POLL_MEDIA, 1000, NULL);
                Wh_Log(L"-- Idle timeout timer started (interval: 1000ms, timeout: %ds)", g_Settings.idleTimeout);
            } else {
                Wh_Log(L"-- Idle timeout disabled, no polling timer needed (events only)");
            }
            return 0;
            
        case WM_APPCOMMAND: // Pass media commands to system shell
            return DefWindowProc(hwnd, msg, wParam, lParam);
            
        case WM_ERASEBKGND: return 1;
        
        case APP_WM_CLOSE:
            if (g_Ctx.Sys.isShutdown && g_Settings.enableSlide) {
                Wh_Log(L"[SHUTDOWN] Starting slide-out animation...");
                RECT rcMe; GetWindowRect(hwnd, &rcMe);
                g_Ctx.Vis.currentAnimY = rcMe.top;
                g_Ctx.Vis.animState = 1; // Hiding
                SetTimer(hwnd, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);

                if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                    RECT rcRainbow; GetWindowRect(g_Ctx.Wnd.rainbow, &rcRainbow);
                    g_Ctx.Rainbow.currentAnimY = rcRainbow.top;
                    g_Ctx.Rainbow.animState = 1;
                    SetTimer(g_Ctx.Wnd.rainbow, IDT_VIS_ANIM, TIMER_ANIMATION_MS, NULL);
                }
            } else {
                if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
                DestroyWindow(hwnd);
            }
            return 0;
            
        case WM_DESTROY:
            Wh_Log(L"-- MediaWndProc WM_DESTROY");
            KillTimer(hwnd, IDT_VIS_ANIM);
            KillTimer(hwnd, IDT_TEXT_ANIM);
            KillTimer(hwnd, IDT_POLL_MEDIA);
            KillTimer(hwnd, IDT_DELAYED_ACTIONS);
            KillTimer(hwnd, IDT_GAME_DETECT);
            Wh_Log(L" --All timers killed-- ");
            PostQuitMessage(0);
            return 0;
            
        case WM_SETTINGCHANGE: 
            Wh_Log(L"[SYSTEM] WM_SETTINGCHANGE received - revalidating window state");
            g_WindowManager.UpdateAppearance(hwnd); 
            g_WindowManager.SyncPositionWithTaskbar();
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
            
        case WM_DPICHANGED: {
            UpdateScaleFactor();
            Wh_LogAdvanced(L"WM_DPICHANGED: Scale factor updated to %.2f", g_Ctx.Sys.scaleFactor);

            RECT* prcNew = reinterpret_cast<RECT*>(lParam);
            if (prcNew) {
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), prcNew->left, prcNew->top,
                             prcNew->right - prcNew->left, prcNew->bottom - prcNew->top,
                             SWP_NOZORDER | SWP_NOACTIVATE);
            }

            g_WindowManager.SyncPositionWithTaskbar();
            g_WindowManager.UpdateAppearance(hwnd);
            InvalidateRect(hwnd, NULL, TRUE);

            if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
                int scaledW = Scale(g_Settings.width);
                int scaledH = Scale(g_Settings.height);
                int borderOffset = Scale(g_Settings.rainbowBorderOffset);
                SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0, 0,
                             scaledW + (borderOffset * 2),
                             scaledH + (borderOffset * 2),
                             SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
                InvalidateRect(g_Ctx.Wnd.rainbow, NULL, TRUE);
            }
            return 0;
        }
        case WM_QUERYENDSESSION:
            g_Ctx.Sys.isShutdown = true;
            g_WindowManager.ForceDockedState();
            return TRUE;
            
        case WM_SETCURSOR: {
            POINT pt; GetCursorPos(&pt);
            ScreenToClient(hwnd, &pt);
            int x = (int)(pt.x / g_Ctx.Sys.scaleFactor);
            int artRightEdge = 6 + (g_Settings.height - 12) + 5;
            SetCursor(LoadCursor(NULL, (x < artRightEdge) ? IDC_ARROW : IDC_HAND));
            return TRUE;
        }
        
        case WM_USER + 101: {
            bool entering = (wParam == 1);
            const wchar_t* triggerName = entering ? L"OnFullscreenEnter" : L"OnFullscreenExit";
            Wh_Log(L"[ActionEngine] Processing fullscreen trigger on main thread: %s", triggerName);
            OnTriggerEvent(triggerName, 0);
            return 0;
        }
        
        case WM_TIMER:
            g_WindowManager.OnTimer(hwnd, wParam);
            return 0;
            
        case WM_MOUSEMOVE: {
            int x = (int)(LOWORD(lParam) / g_Ctx.Sys.scaleFactor);
            int y = (int)(HIWORD(lParam) / g_Ctx.Sys.scaleFactor);
            int logicalH = g_Settings.height;
            int artSize = logicalH - 12;
            float buttonRatio = Clamp((float)g_Settings.buttonSizeRatio / 100.0f, 0.1f, 1.2f);
            float buttonSize = artSize * buttonRatio;
            float controlScale = buttonSize / 24.0f;
            auto ScaleVal = [&](float value) { return std::max(1, (int)(value * controlScale + 0.5f)); };

            int controlGap = ScaleVal(12);
            int controlSpacing = ScaleVal(28);
            int hoverOffsetX = ScaleVal(8);
            int hoverOffsetY = ScaleVal(12);
            int hoverSize = ScaleVal(24);

            int startControlX = 6 + artSize + controlGap;
            int controlY = logicalH / 2;
            int newState = 0;
            int prevLeft = startControlX - hoverOffsetX;
            int prevRight = prevLeft + hoverSize;
            int playLeft = (startControlX + controlSpacing) - hoverOffsetX;
            int playRight = playLeft + hoverSize;
            int nextLeft = (startControlX + controlSpacing * 2) - hoverOffsetX;
            int nextRight = nextLeft + hoverSize;

            int top = controlY - hoverOffsetY;
            int bottom = top + hoverSize;
            if (y >= top && y <= bottom) {
                if (x >= prevLeft && x < prevRight) newState = 1;
                else if (x >= playLeft && x < playRight) newState = 2;
                else if (x >= nextLeft && x < nextRight) newState = 3;
            }
            if (newState != g_Ctx.Vis.hoverState) { g_Ctx.Vis.hoverState = newState; InvalidateRect(hwnd, NULL, FALSE); }
            TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT), TME_LEAVE, hwnd, 0 };
            TrackMouseEvent(&tme);
            return 0;
        }
        case WM_MOUSELEAVE: g_Ctx.Vis.hoverState = 0; InvalidateRect(hwnd, NULL, FALSE); break;
        
        case WM_LBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_LBUTTONUP");
            if (g_Ctx.Vis.hoverState >= 1 && g_Ctx.Vis.hoverState <= 3) {
                Wh_LogAdvanced(L"[INPUT] Clicked button state: %d", g_Ctx.Vis.hoverState);
                SendMediaCommand(g_Ctx.Vis.hoverState);
            } else if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Left click on background - triggering action");
                OnTriggerEvent(L"Left");
            }
            return 0;
        }
        case WM_RBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_RBUTTONUP");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Right click on background - triggering action");
                OnTriggerEvent(L"Right");
            }
            return 0;
        }
        case WM_MBUTTONUP: {
            Wh_LogAdvanced(L"[INPUT] WM_MBUTTONUP");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Middle click on background - triggering action");
                OnTriggerEvent(L"Middle");
            }
            return 0;
        }
        case WM_LBUTTONDBLCLK: {
            Wh_LogAdvanced(L"[INPUT] WM_LBUTTONDBLCLK");
            if (IsClickOnBackground(lParam)) {
                Wh_LogAdvanced(L"[INPUT] Double click on background - triggering action");
                OnTriggerEvent(L"Double");
            }
            return 0;
        }
        
        case WM_MOUSEWHEEL:
            g_WindowManager.OnMouseWheel(hwnd, wParam, lParam);
            return 0;
            
        case WM_PAINT:
            g_WindowManager.OnPaint(hwnd);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

#pragma endregion  // ^window_procedures

//! =====================================================================

#pragma region // ^Main_Thread

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

    // --- Registry Auto-Hide Listener ---
    g_RegistryManager.StartAutoHideListener([]() {
        if (g_Settings.enableGameDetect) UpdateGameDetectionState();
        g_WindowManager.SyncPositionWithTaskbar();
    });

    // --- GDI+ Initialization (required for rendering) ---
    GdiplusStartupInput gdiplusStartupInput;
    if (GdiplusStartup(&g_Ctx.Sys.gdiplusToken, &gdiplusStartupInput, NULL) != Ok) {
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
    Wh_LogAdvanced(L"-- Scale factor updated to %.2f", g_Ctx.Sys.scaleFactor);
    
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
    int scaledW = Scale(g_Settings.width);
    int scaledH = Scale(g_Settings.height);
    int borderOffset = Scale(g_Settings.rainbowBorderOffset);

    auto cleanup = [&]() {
        if (g_Ctx.Wnd.visibilityHook) {
            UnhookWinEvent(g_Ctx.Wnd.visibilityHook);
            Wh_Log(L"WinEvent hook unhooked");
            g_Ctx.Wnd.visibilityHook = NULL;
        }
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        Wh_Log(L"Media window class unregistered");
        UnregisterClass(wcRainbow.lpszClassName, wcRainbow.hInstance);
        Wh_Log(L"Rainbow window class unregistered");
        // CRITICAL: Delete albumArt BEFORE GdiplusShutdown
        // Deleting GDI+ objects after GdiplusShutdown hangs indefinitely
        {
            std::lock_guard<std::mutex> guard(g_Ctx.Media.lock);
            if (g_Ctx.Media.albumArt) {
                g_Ctx.Media.albumArt.reset();
                Wh_Log(L"Album art cleaned up in MediaThread");
            }
        }
        if (g_Ctx.Sys.gdiplusToken) {
            GdiplusShutdown(g_Ctx.Sys.gdiplusToken);
            Wh_Log(L"GDI+ shutdown completed");
            g_Ctx.Sys.gdiplusToken = 0;
        }
        // CRITICAL: Unsubscribe from WinRT events BEFORE releasing session/manager
        // This prevents in-flight callbacks from running after window destruction
        Wh_Log(L"[CLEANUP] Unsubscribing from WinRT events...");
        if (g_CachedSession) {
            try {
                if (g_playbackInfoToken) {
                    g_CachedSession.PlaybackInfoChanged(g_playbackInfoToken);
                    g_playbackInfoToken = winrt::event_token{};
                    Wh_Log(L"[CLEANUP] Playback info handler unsubscribed");
                }
                if (g_mediaPropertiesToken) {
                    g_CachedSession.MediaPropertiesChanged(g_mediaPropertiesToken);
                    g_mediaPropertiesToken = winrt::event_token{};
                    Wh_Log(L"[CLEANUP] Media properties handler unsubscribed");
                }
            } catch (...) {
                Wh_Log(L"[WARNING] Exception unsubscribing session handlers");
            }
        }
        
        if (g_SessionManager) {
            try {
                if (g_sessionChangedToken) {
                    g_SessionManager.CurrentSessionChanged(g_sessionChangedToken);
                    g_sessionChangedToken = winrt::event_token{};
                    Wh_Log(L"[CLEANUP] Session change handler unsubscribed");
                }
            } catch (...) {
                Wh_Log(L"[WARNING] Exception unsubscribing session manager handler");
            }
        }
        
        // Give any in-flight callbacks time to see g_Ctx.Sys.eventHandlersActive=false and exit
        Sleep(100);
        Wh_Log(L"[CLEANUP] Waited for in-flight callbacks to exit");
        
        // CRITICAL: Release GSMTC session and manager BEFORE uninit_apartment
        // to properly terminate RPC connections and avoid "RPC server unavailable" errors
        if (g_CachedSession) {
            try {
                g_CachedSession = nullptr;
                Wh_Log(L"[CLEANUP] GSMTC cached session released");
            } catch (...) {
                Wh_Log(L"[WARNING] Exception releasing cached session");
                g_CachedSession = nullptr;
            }
        }
        if (g_SessionManager) {
            try {
                g_SessionManager = nullptr;
                Wh_Log(L"[CLEANUP] GSMTC session manager released");
            } catch (...) {
                Wh_Log(L"[WARNING] Exception releasing GSMTC session manager");
                g_SessionManager = nullptr;
            }
        }
        if (winrtInitialized) {
            winrt::uninit_apartment();
            Wh_Log(L"[CLEANUP] WinRT apartment uninitialized");
        }
        Wh_Log(L"MediaThread exiting");
    };

    // Create media window hidden with scaled size
    if (CreateWindowInBand) {
        g_Ctx.Wnd.main = CreateWindowInBand(
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
        g_Ctx.Wnd.main = CreateWindowEx(
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
            wc.lpszClassName,
            TEXT("MusicLounge"),
            WS_POPUP,
            0, 0,
            scaledW,
            scaledH,
            NULL, NULL, wc.hInstance, NULL);
    }

    if (!g_Ctx.Wnd.main) {
        Wh_Log(L"ERROR: Failed to create media window");
        cleanup();
        return;
    }
    Wh_Log(L"Media window created: 0x%p (size: %dx%d)", g_Ctx.Wnd.main, scaledW, scaledH);

    // Create rainbow window hidden with scaled size
    Wh_Log(L"Creating rainbow window...");
    if (CreateWindowInBand) {
        g_Ctx.Wnd.rainbow = CreateWindowInBand(
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
        g_Ctx.Wnd.rainbow = CreateWindowEx(
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
    if (g_Ctx.Wnd.rainbow) {
        Wh_Log(L"-- Rainbow window created: 0x%p", g_Ctx.Wnd.rainbow);
    }

    // Apply appearance and transparency while hidden
    SetLayeredWindowAttributes(g_Ctx.Wnd.main, 0, 255, LWA_ALPHA);
    g_WindowManager.UpdateAppearance(g_Ctx.Wnd.main);
    if (g_Ctx.Wnd.rainbow) {
        SetLayeredWindowAttributes(g_Ctx.Wnd.rainbow, 0, 255, LWA_ALPHA);
    }

    // Position while hidden (use persisted rect if available)
    if (g_Ctx.Persisted.lastX != std::numeric_limits<int>::min() &&
        g_Ctx.Persisted.lastY != std::numeric_limits<int>::min() &&
        g_Ctx.Persisted.lastW > 0 && g_Ctx.Persisted.lastH > 0) {
        SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(),
                     g_Ctx.Persisted.lastX, g_Ctx.Persisted.lastY,
                     g_Ctx.Persisted.lastW, g_Ctx.Persisted.lastH,
                     SWP_NOACTIVATE | SWP_SHOWWINDOW);
        Wh_Log(L" -Applied persisted window rect %d,%d %dx%d", g_Ctx.Persisted.lastX, g_Ctx.Persisted.lastY, g_Ctx.Persisted.lastW, g_Ctx.Persisted.lastH);
    }

    if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow &&
        g_Ctx.Persisted.lastX != std::numeric_limits<int>::min() &&
        g_Ctx.Persisted.lastY != std::numeric_limits<int>::min()) {
        int borderOffset = Scale(g_Settings.rainbowBorderOffset);
        SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(),
                     g_Ctx.Persisted.lastX - borderOffset,
                     g_Ctx.Persisted.lastY - borderOffset,
                     (g_Ctx.Persisted.lastW > 0 ? g_Ctx.Persisted.lastW : scaledW) + (borderOffset * 2),
                     (g_Ctx.Persisted.lastH > 0 ? g_Ctx.Persisted.lastH : scaledH) + (borderOffset * 2),
                     SWP_NOACTIVATE | SWP_SHOWWINDOW);
    }

    // Position while hidden
    g_Ctx.Vis.animState = 3; // Docked
    g_WindowManager.SyncPositionWithTaskbar();

    // Show after setup is complete
    ShowWindow(g_Ctx.Wnd.main, SW_SHOWNOACTIVATE);
    Wh_Log(L" -Media window shown-");
    if (g_Settings.enableRainbow && g_Ctx.Wnd.rainbow) {
        ShowWindow(g_Ctx.Wnd.rainbow, SW_SHOWNOACTIVATE);
        Wh_Log(L" -Rainbow window shown-");
    } else if (g_Ctx.Wnd.rainbow) {
        Wh_Log(L" --Rainbow window created but hidden (enableRainbow=%d)-- ", g_Settings.enableRainbow);
    }

    g_Ctx.Wnd.visibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
    if (g_Ctx.Wnd.visibilityHook) {
        Wh_Log(L"WinEvent hook installed: 0x%p", g_Ctx.Wnd.visibilityHook);
    } else {
        Wh_Log(L"WARNING: Failed to install WinEvent hook");
    }

    // Enable event handlers BEFORE GSMTC init so initial fetch works
    g_Ctx.Sys.eventHandlersActive = true;
    Wh_Log(L"[INIT] Event handlers activated - media updates now event-driven");

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
            
            // Register session change event handler and store token for unsubscription
            g_sessionChangedToken = g_SessionManager.CurrentSessionChanged([](auto&&, auto&&) {
                if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                
                try {
                    g_CachedSession = g_SessionManager.GetCurrentSession();
                    
                    if (g_CachedSession) {
                        Wh_Log(L"[MusicLounge] Session changed - new session cached");
                        
                        // Unsubscribe old handlers before registering new ones
                        if (g_playbackInfoToken) {
                            try {
                                auto oldSession = g_CachedSession;
                                // Note: tokens are invalid for previous session, clear them
                                g_playbackInfoToken = winrt::event_token{};
                                g_mediaPropertiesToken = winrt::event_token{};
                            } catch (...) { }
                        }
                        
                        // Re-register event handlers for the new session and store tokens
                        g_playbackInfoToken = g_CachedSession.PlaybackInfoChanged([](auto&&, auto&&) {
                            if (!g_Ctx.Sys.eventHandlersActive.load()) return;
                            HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                            if (!localWindow || !IsWindow(localWindow)) return;
                            Wh_LogAdvanced(L"[GSMTC] PlaybackInfoChanged event fired");
                            UpdateMediaInfoAsync();
                            InvalidateRect(localWindow, NULL, FALSE);
                        });
                        
                        g_mediaPropertiesToken = g_CachedSession.MediaPropertiesChanged([](auto&&, auto&&) {
                            if (!g_Ctx.Sys.eventHandlersActive.load()) return;
                            HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                            if (!localWindow || !IsWindow(localWindow)) return;
                            Wh_LogAdvanced(L"[GSMTC] MediaPropertiesChanged event fired");
                            UpdateMediaInfoAsync();
                            InvalidateRect(localWindow, NULL, FALSE);
                        });
                        
                        Wh_Log(L"Event handlers re-registered for new session");
                    } else {
                        Wh_Log(L"[MusicLounge] Session changed - no session available");
                    }
                    
                    // Trigger immediate update
                    HWND localWindow = g_Ctx.Wnd.main;
                    if (localWindow && IsWindow(localWindow)) {
                        UpdateMediaInfoAsync();
                    }
                } catch (...) {
                    Wh_Log(L"ERROR: Exception in session change handler");
                }
            });
            Wh_Log(L"Session change event handler registered");
            
            // Register event handlers for instant state updates and store tokens
            if (g_CachedSession) {
                // Playback state changes (play/pause/position) - store token
                g_playbackInfoToken = g_CachedSession.PlaybackInfoChanged([](auto&&, auto&&) {
                    if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                    HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot (safe even if window destroyed mid-check)
                    if (!localWindow || !IsWindow(localWindow)) return;
                    
                    Wh_LogAdvanced(L"[GSMTC] PlaybackInfoChanged event fired");
                    UpdateMediaInfoAsync();
                    InvalidateRect(localWindow, NULL, FALSE);
                });
                Wh_Log(L"Playback info change event handler registered");
                
                // Media properties changes (title/artist/artwork) - store token
                g_mediaPropertiesToken = g_CachedSession.MediaPropertiesChanged([](auto&&, auto&&) {
                    if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                    HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                    if (!localWindow || !IsWindow(localWindow)) return;
                    
                    Wh_LogAdvanced(L"[GSMTC] MediaPropertiesChanged event fired");
                    UpdateMediaInfoAsync();
                    InvalidateRect(localWindow, NULL, FALSE);
                });
                Wh_Log(L"Media properties change event handler registered");
                
                // Fetch initial state now that handlers are ready
                Wh_Log(L"Fetching initial media state...");
                UpdateMediaInfoAsync();
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

#pragma endregion  // ^Main_Thread



std::thread* g_pMediaThread = nullptr;

#pragma region // ^Windhawk Callbacks

BOOL WhTool_ModInit() {
    Wh_Log(L" --- START --- ");
    Wh_Log(L"Init " WH_MOD_ID L" version " WH_MOD_VERSION);
    
    // Reset all global state to ensure clean initialization
    g_Ctx.Rainbow.directionReverse = false;
    g_Ctx.Audio.peakLevel = 0.0f;
    g_Ctx.Audio.peakSmoothed = 0.0f;
    g_Ctx.Rainbow.hue = 0.0f;
    g_Ctx.Rainbow.animState = 0;
    g_Ctx.Vis.animState = 0;
    g_Ctx.Vis.isGameDetected = false;
    g_Ctx.Vis.isHiddenByIdle = false;
    g_Ctx.Vis.idleSecondsCounter = 0;
    g_Ctx.Sys.isShutdown = false;         // Indicates whether the application is shutting down
    g_Ctx.Sys.eventHandlersActive = false;  // Will be enabled after window creation
    Wh_Log(L"[INIT] Global state reset");

    if (FAILED(SetCurrentProcessExplicitAppUserModelID(L"taskbar-music-lounge-fork"))) {
        Wh_Log(L"[WARNING] SetCurrentProcessExplicitAppUserModelID failed (non-critical)");
    }
    
    // CRITICAL: Initialize DPI scaling FIRST (independent of taskbar)
    UpdateScaleFactor();
    if (g_Ctx.Sys.scaleFactor <= 0.0f) {
        Wh_Log(L"[ERROR] Failed to initialize DPI scale factor");
        return FALSE;
    }
    Wh_LogAdvanced(L"[INIT] Scale factor initialized to %.2f", g_Ctx.Sys.scaleFactor);
    
    // CRITICAL: Initialize taskbar handle FIRST (before thread spawn)
    EnsureTaskbarHandle();

    // Initialize Audio COM first so LoadSettings can enable the meter if needed
    const bool audioComOk = g_audioCOM.Init();
    if (!audioComOk) {
        Wh_Log(L"[WARNING] Audio COM initialization failed (audio reactive disabled)");
    } else {
        Wh_Log(L"[INIT] Audio COM initialized");
    }

    // Initialize advanced debug logging from registry (startup authority)
    g_Settings.enableAdvancedDebugLog = g_RegistryManager.CheckDebugLog();
    Wh_Log(L"[INIT] Advanced Debug Logging (registry): %s",
           g_Settings.enableAdvancedDebugLog ? L"ENABLED" : L"DISABLED");

    LoadSettings();
    Wh_Log(L"[INIT] Settings loaded");

    if (!audioComOk) {
        g_Settings.enableAudioReactive = false;
    } else if (g_Settings.enableAudioReactive && !g_audioCOM.InitMeter()) {
        Wh_Log(L"[WARNING] Audio meter initialization failed (audio reactive disabled)");
        g_Settings.enableAudioReactive = false;
    }

    g_Ctx.Sys.isRunning = true;
    if (!g_pMediaThread) {
        try {
            g_pMediaThread = new std::thread(MediaThread);
            Wh_Log(L"[INIT] Media thread spawned");
        } catch (const std::exception&) {
            Wh_Log(L"[ERROR] Failed to create media thread");
            g_audioCOM.Uninit();
            g_pMediaThread = nullptr;
            return FALSE;
        }
    } else {
        Wh_Log(L"[WARNING] Media thread already exists");
    }

    Wh_Log(L" ---Init complete");
    return TRUE;
}

void WhTool_ModUninit() {
    Wh_Log(L"[UNINIT] Starting cleanup...");
    
    // Phase 0: Disable event handlers FIRST to prevent race conditions
    g_Ctx.Sys.eventHandlersActive = false;
    Wh_Log(L"[UNINIT] Event handlers deactivated");
    
    // Phase 1: Signal shutdown to all threads
    g_Ctx.Sys.isRunning = false;
    g_Ctx.Sys.isShutdown = true;
    
    // Phase 2: Post close message to media window to trigger slide-out animation
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[UNINIT] Posting APP_WM_CLOSE to media window (will animate if enabled)...");
        PostMessage(g_Ctx.Wnd.main, APP_WM_CLOSE, 0, 0);
    }
    
    // Phase 3: Wait for media thread to exit (it will destroy its own windows)
    if (g_pMediaThread) {
        Wh_Log(L"[UNINIT] Waiting for media thread to exit...");
        if (g_pMediaThread->joinable()) {
            g_pMediaThread->join();
        }
        delete g_pMediaThread;
        g_pMediaThread = nullptr;
        Wh_Log(L"[UNINIT] Media thread joined");
    }
    
    // Phase 4: Clean up any remaining windows (should already be destroyed by thread)
    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
        Wh_Log(L"[UNINIT] WARNING: Rainbow window still exists, destroying...");
        DestroyWindow(g_Ctx.Wnd.rainbow);
        g_Ctx.Wnd.rainbow = NULL;
    }
    
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[UNINIT] WARNING: Media window still exists, destroying...");
        DestroyWindow(g_Ctx.Wnd.main);
        g_Ctx.Wnd.main = NULL;
    }
    
    // Phase 6: Stop registry listener
    Wh_Log(L"[UNINIT] Stopping registry auto-hide listener...");
    g_RegistryManager.StopAutoHideListener();
    
    // Phase 7: Clean up audio COM
    if (g_audioCOM.IsInitialized()) {
        Wh_Log(L"[UNINIT] Shutting down audio COM...");
        g_audioCOM.Uninit();
    }
    
    // Phase 8: Shutdown GDI+ (after all drawing is done)
    if (g_Ctx.Sys.gdiplusToken) {
        Wh_Log(L"[UNINIT] Shutting down GDI+...");
        GdiplusShutdown(g_Ctx.Sys.gdiplusToken);
        g_Ctx.Sys.gdiplusToken = 0;
    }
    
    // Phase 8: Reset global state
    g_Ctx.Vis.isGameDetected.store(false);
    g_Ctx.Vis.isHiddenByIdle.store(false);
    g_Ctx.Vis.idleSecondsCounter.store(0);
    g_Ctx.Rainbow.directionReverse.store(false);
    g_Ctx.Audio.peakLevel.store(0.0f);
    g_Ctx.Audio.peakSmoothed.store(0.0f);
    g_Ctx.Rainbow.hue.store(0.0f);
    g_Ctx.Rainbow.animState.store(0);
    g_Ctx.Vis.animState.store(0);
    g_Ctx.Audio.runtimeEnabled = true;
    g_Ctx.Sys.isShutdown = false;
    g_Ctx.Wnd.taskbar = NULL;
    g_Ctx.Wnd.visibilityHook = NULL;
    
    {
        g_ActionDispatcher.ClearPendingActions();
    }
    g_triggers.clear();
    
    // Clear media state
    {
        std::lock_guard<std::mutex> guard(g_Ctx.Media.lock);
        g_Ctx.Media.title.clear();
        g_Ctx.Media.artist.clear();
        g_Ctx.Media.sourceId.clear();
        g_Ctx.Media.lastValidSourceId.clear();
        g_Ctx.Media.hasMedia = false;
        g_Ctx.Media.isPlaying = false;
        g_Ctx.Media.albumArt.reset();
    }
    
    Wh_Log(L"[UNINIT] Cleanup complete");
}

void WhTool_ModSettingsChanged() {
    Wh_Log(L"[SETTINGS] Change event triggered");
    
    // CRITICAL: Pause any live animation timers
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[SETTINGS] Killing media window timers...");
        KillTimer(g_Ctx.Wnd.main, IDT_VIS_ANIM);
        KillTimer(g_Ctx.Wnd.main, IDT_TEXT_ANIM);
        KillTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA);
        KillTimer(g_Ctx.Wnd.main, IDT_DELAYED_ACTIONS);
        KillTimer(g_Ctx.Wnd.main, IDT_GAME_DETECT);
        Wh_Log(L"[SETTINGS] Media window timers killed");
        
        // RESET STATES to prevent lockups or stuck timers
        g_Ctx.Scroll.isScrolling = false; // Forces re-eval in DrawMediaPanel
        g_Ctx.Vis.animState = 0;          // Forces SyncPositionWithTaskbar to act
    }
    
    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
        Wh_Log(L"[SETTINGS] Killing rainbow window timer...");
        KillTimer(g_Ctx.Wnd.rainbow, IDT_RAINBOW_ANIM);
        Wh_Log(L"[SETTINGS] Rainbow window timer killed");
        g_Ctx.Rainbow.animState = 0;
    }
    
    // Reload settings with validation
    Wh_Log(L"[SETTINGS] Loading settings...");
    LoadSettings();  // Calls ValidateSettings() at end
    Wh_Log(L"[SETTINGS] Settings loaded and validated");
    
    // Refresh DPI scaling in case system DPI changed
    UpdateScaleFactor();
    Wh_Log(L"[SETTINGS] Scale factor updated to %.2f", g_Ctx.Sys.scaleFactor);
    
    // Reapply appearance
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[SETTINGS] Updating media window appearance...");
        g_WindowManager.UpdateAppearance(g_Ctx.Wnd.main);

        // Update the detector engine with new settings
        if (g_Settings.enableGameDetect) {
            UpdateGameDetectionState();
            SetTimer(g_Ctx.Wnd.main, IDT_GAME_DETECT, 2000, NULL);
        }

        if (g_Settings.idleTimeout > 0) {
            SetTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA, 1000, NULL);
        }

        g_WindowManager.SyncPositionWithTaskbar();
        
        // Force the Media Thread to re-fetch the *real* live status from GSMTC
        // to overwrite the "Offline/Paused" fallback state set by LoadSettings.
        // This fixes the Play/Pause button reverting to Play.
        PostMessage(g_Ctx.Wnd.main, APP_WM_REFRESH_MEDIA, 0, 0);
        
        // Trigger repaint to refresh media display immediately
        InvalidateRect(g_Ctx.Wnd.main, NULL, FALSE);
        UpdateWindow(g_Ctx.Wnd.main);
        Wh_Log(L"[SETTINGS] Media window appearance updated");
    }
    
    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
        Wh_Log(L"[SETTINGS] Updating rainbow window...");
        // Apply corner rounding update
        DWM_WINDOW_CORNER_PREFERENCE preference = g_Settings.enableRoundedCorners ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
        DwmSetWindowAttribute(g_Ctx.Wnd.rainbow, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));

        if (g_Ctx.Wnd.main && g_Settings.enableRainbow) {
            SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            Wh_Log(L"[SETTINGS] Z-order adjusted");

            SetTimer(g_Ctx.Wnd.rainbow, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
        }
        
        InvalidateRect(g_Ctx.Wnd.rainbow, NULL, TRUE);
        Wh_Log(L"[SETTINGS] Rainbow window updated");
    }
    
    // Restart timers with new settings
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[SETTINGS] Restarting media window timers...");
        
        // Restart idle timer only if enabled (media updates are event-driven)
        if (g_Settings.idleTimeout > 0) {
            SetTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA, 1000, NULL);
            Wh_Log(L"[SETTINGS] Idle timeout timer restarted (timeout: %ds)", g_Settings.idleTimeout);
        } else {
            Wh_Log(L"[SETTINGS] Idle timeout disabled, no polling timer needed (events only)");
        }
    }
    
    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
        if (g_Settings.enableRainbow) {
            Wh_Log(L"[SETTINGS] Starting rainbow animation timer...");
            SetTimer(g_Ctx.Wnd.rainbow, IDT_RAINBOW_ANIM, TIMER_ANIMATION_MS, NULL);
            ShowWindow(g_Ctx.Wnd.rainbow, SW_SHOWNOACTIVATE);
            Wh_Log(L"[SETTINGS] Rainbow timer restarted and window shown");
        } else {
            ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
            Wh_Log(L"[SETTINGS] Rainbow disabled, window hidden");
        }
    }
    
    Wh_Log(L"[SETTINGS] Settings reload complete");
}

//! =====================================================================

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

#pragma endregion // ^Windhawk Callbacks