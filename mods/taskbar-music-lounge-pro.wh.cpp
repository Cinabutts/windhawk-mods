#pragma region // ^ Windhawk
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

###                                                 The Native Windows 11 Swiss-Army knife of Taskbar Media Players.


##                                                                 ✨ Features
   Based on the work of [@Hashah2311](https://github.com/Hashah2311)'s OG [Taskbar Music Lounge](https://github.com/ramensoftware/windhawk-mods/blob/53d96781b3215f0a082908a2539cafe178e8895a/mods/taskbar-music-lounge.wh.cpp):
* **Wide Support:** Works with most media players via GSMTC.
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
* **Audio Reactive Rainbow:** Choose from 7 predefined Audio Hue Reactive Mode Presets (e.g., Pulse, Bounce, Speed Boost etc) ⚠️W.I.P⚠️
* **Advanced Audio Processing:** Fine-tune responsiveness, thresholds, and dynamic range for audio reactive vfx.

![Audio-FX Example](https://raw.githubusercontent.com/Cinabutts/windhawk-mods/refs/heads/Testing/Resources/audio_fx-example.gif)

&nbsp;

----

&nbsp;

##                                                             🔧 Mouse Action Engine

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
- PanelWidth: 600
  $name: Panel Width
- PanelHeight: 35
  $name: Panel Height
- MaxArtSize: 300
  $name: Max Album Art Size
  $description: >-
    Maximum album art height in pixels. Art scales with window height but won't exceed this.
- ButtonSize: 75
  $name: Button Size
  $description: Sets button size (5-120).
- TextScale: 100
  $name: Text Scale %
  $description: Scales the text size relative to album art (50-200).
- OffsetX: 140
  $name: X Offset
- OffsetY: 0
  $name: Y Offset
- ColorTheme: System Colors (Auto Light/Dark)
  $name: Color Theme
  $description: Choose color source for widget appearance
  $options:
    - system: System Colors (Auto Light/Dark)
    - custom: Custom Colors
    - artwork: Artwork Background (Future)
- InvertColors: false
  $name: Invert Colors
  $description: >-
    Flip RGB values (255-R, 255-G, 255-B) for both interface and background colors.
    
    Works with any ColorTheme setting and applies to all chosen colors.
- ScaleEasing: 5
  $name: Button Scale Easing (x10)
  $description: >-
      Controls the button scaling aggression.
    
    Default: 10 (2.0). Range: (-5 - 50) (-0.5 - 5.0).
- EnableSlide: true
  $name: Enable Slide Animations
  $description: >-
    ✓ Smooth | Widget slides smoothly in/out place.

    ✕ Static | Widget snaps in/out instantly.
- EnableRoundedCorners: true
  $name: Enable Rounded Corners
  $description: >-
    ✓ Rounded | Native Windows 11 rounded corners.

    ✕ Square | Traditional square corners.
- BgColor: "0, 0, 0, 0"
  $name: Background Color (R, G, B, [A])
  $description: >-
       Set 0,0,0,A to keep default/System color.

    AutoTheme OFF: Full custom color used. | AutoTheme ON: Only 'Alpha' is used (RGB Ignored).
- TextColor: "240, 220, 240, 255"
  $name: Interface Color (R, G, B, [A])
  $description: >-
       Color for ALL text and media buttons.
    
    Enter RGB or RGBA values separated by commas (e.g; "102, 255, 255" or "255, 0, 0, 128")
- Centered: false
  $name: Center Text
  $description: >-
    ✓ Enabled | Text centers between media buttons and right edge when it fits - Otherwise, Scrolls if enabled.

    ✕ Disabled | Text stays left-aligned next to media buttons.
- EnableTextScroll: true
  $name: Enable Text Scroll
  $description: Allow the text to scroll if the text is cut off.
- IdleTimeout: 0
  $name: Auto-hide when paused (Seconds)
  $description: Automatically hide the widget when music is paused for the specified number of seconds. Set 0 to disable.
- EnableRainbow: true
  $name: 🔹 Enable Rainbow RGB Effect 🔹
  $description: >-
    ✓ Enabled | Adds a flowing rainbow gradient border beneath the widget.

    ✕ Disabled | No rainbow effect.
- RainbowSpeed: 4
  $name: Rainbow Speed (1-10)
  $description: Controls how fast the rainbow colors flow. Higher = faster.
- RainbowBrightness: 80
  $name: Rainbow Brightness (0-100)
  $description: Controls the brightness/intensity of the rainbow colors.
- RainbowThickness: 6
  $name: Rainbow Border Thickness (1-100 pixels)
  $description: Controls how thick the rainbow border appears.
- RainbowBorderOffset: 3
  $name: Rainbow Border Offset (0-7 pixels)
  $description: Distance between main widget and rainbow border.
- kAudioHueReactiveMode: Pulse (Color Jump)
  $name: 🎵 Audio Reactive Rainbow 🪄
  $description: >-
    Audio-driven hue effects for rainbow border

    ✓ Speedboost | Rainbow animates faster when audio is louder.

    ✓ Pulse | Rainbow colors jump when audio exceeds threshold.

    ✓ Bounce | Rainbow direction reverses when audio exceeds threshold.

    ✓ Speedboost + Pulse | Combines both effects for maximum audio reactivity.

    ✓ Speedboost + Bounce | Combines Speedboost and Bounce effects.

    ✓ PulseBounce | Combines Pulse and Bounce effects.

    ✓ All Effects | Combines all available audio reactive effects.

    ✕ Disabled | Rainbow animates at fixed speed.

  $options:
  - off: Disabled
  - speedboost: Speed Boost
  - pulse: Pulse (Color Jump)
  - bounce: Bounce (Direction Reverse)
  - speedboost_pulse: Speed Boost + Pulse
  - speedboost_bounce: Speed Boost + Bounce
  - pulse_bounce: Pulse + Bounce
  - all: All Effects
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
          - ACTION_TOGGLE_VOLUME_TARGET: Toggle Volume Target (System/App)
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
          - ACTION_OPACITY_INCREASE: Opacity Increase
          - ACTION_OPACITY_DECREASE: Opacity Decrease
          - ACTION_FORCE_DOCKED: Force Docked State (Test)
          - ACTION_PALETTE_SAVE: Save Current Palette
          - ACTION_PALETTE_CYCLE_NEXT: Cycle Palette Forward
          - ACTION_PALETTE_CYCLE_PREV: Cycle Palette Backward
        - AdditionalArgs: ""
          $name: Arguments
          $description: Read Description Above ▲
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
  $description: >- 
                Configure mouse + optional modifier key(s) triggers and the Actions they execute.

                You can create multiple triggers with the same event type but different required modifiers (e.g., Left Click + Ctrl vs Left Click + Shift).

                When a trigger event is detected, the mod checks all triggers for a matching event type and required modifiers, then executes their actions in order.


                Action Arguments:

                Syntax: xINSTANCE:yDELAY:zARGUMENT   (e.g. 1:4.5:Firefox | 5.5:Calc.exe | Chrome | Direct paths )

                    • x: 1=Force New | 0=Prevent Duplicates (Default | Doesn't need to be present)
                    • y: Seconds to wait (0=Default - Has Presedence e.g., `##:arg` = Delay whilst `##:##:` = xINSTANCE:yDELAY)
                    • z: Command/App + Params (e.g. firefox --new-window)

                                                       Arguments by action:
                        •     Opacity Increase/Decrease:    "5": Increment value to increase/decrease opacity (0-255)

                        •     Open App / Run File:            calc.exe | notepad | Direct paths | "C:\Scripts\Mycoolscript.py" | Quotes optional
                         May include additional Args ie `firefox --new-window` | Checks if running unless prefixed with `1:` | .type Optional

                        •   Switch to Audible Window:       Firefox | Chrome | Spotify, etc
                    Fallback App/File if `No Media` Present - Uses same logic as above  ▲

                        •     Send Keystrokes (macro):        0.5:Alt+Shift+A | Win+Tab (use + or ;)
                        •     Combine Taskbar Buttons:        1:COMBINE_ALWAYS;COMBINE_NEVER (2 or 4 states)
                    States Available: COMBINE_ALWAYS, COMBINE_WHEN_FULL, COMBINE_NEVER

                                   •     Save Currrent palette (Max: 15):
                                In the case of a full Color palette list - Do this:
                                   "0": Warn & Overwrite First slot in color palette list       - Default
                                   "1": Remove last - Shift list and place new palette First
                                   "2": Just warn - Do NOT overwrite, Save nothing

                           Cycle Palette Forward/Backward: Delay only, No args needed
                           Volume/Media/Desktop/Taskbar: Delay only, No args needed
                           Toggle Audio Reactive Rainbow: Delay only, No args needed
*/
// ==/WindhawkModSettings==

#pragma endregion // Windhawk

// ! ==============================================================================

#pragma region // ^ Includes

//      ~-- Windows Core
#include <windows.h>
#include <windef.h>
#include <cstddef>
#include <minwindef.h>
//      ~-- Windows Shell & UI
#include <shlobj.h>
#include <dwmapi.h>
#include <shcore.h>
//      ~-- Windows Media & Audio
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
//      ~-- Graphics
#include <gdiplus.h>
//      ~-- Process & System
#include <psapi.h>
//      ~-- C++ Standard Library
#include <atomic>
#include <memory>
#include <functional>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>
// #include <fstream>           // * Used in [DIAGNOSTIC] Logging *
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

#pragma endregion   // Includes

// ! ==============================================================================

#pragma region // ~ RAII-Helpers

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

#pragma endregion // RAII-Helpers

// ! ==============================================================================

#pragma region // .. Declarations\Definitions

// --- Forward Declarations ---
HWND GetMediaZOrderInsertAfter();
HWND GetRainbowZOrderInsertAfter();
void UpdateScaleFactor();
// Game detection removed

// Settings & Appearance

/* /-- Load all settings from Windhawk configuration   | FOR USE ON INITIALIZATION AND SETTINGS UPDATE (NOT PER-FRAME) 
/-- ensures all settings are applied consistently and efficiently without redundant calls */
void LoadSettings();
void LoadPersistentState();
void SaveWindowState(int x, int y, int w, int h, bool saveOpacity = false);
void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist);
void ApplyPersistedMediaFallback();
void SetWindowOpacity(HWND hwnd, BYTE opacity);

// Action Engine
void ExecuteActionWithDelay(std::function<void()> action, float delaySeconds);
bool OnTriggerEvent(const std::wstring& detectedTriggerName, int zDelta = 0);

// --- Timer IDs ---
#define IDT_POLL_MEDIA      1001  // ~ Media state polling (1000ms)
#define IDT_MASTER_TICK     1002  // .. Unified 60fps Game Loop timer

// --- Timer Intervals (milliseconds) ---
#define TIMER_ANIMATION_MS       16   // ~ 60 FPS for smooth animations   -   FOR `MASTER_TICK`
#define ANIMATION_SMOOTH_FACTOR  0.5f // Animation speed: 0.1=slow, 0.5=medium, 0.9=fast                 // ! UNUSED - DEAD CODE
#define TIMER_MEDIA_POLL_MS      200  // 200ms media state poll (event-driven updates more important)    // ! UNUSED - DEAD CODE
#define TIMER_TEXT_ANIM_MS       16   // 60 FPS text scroll                                              // ! UNUSED - DEAD CODE
#define TIMER_DELAYED_ACTIONS_MS 50   // Delayed action check interval                                   // ! UNUSED - DEAD CODE

// --- Docking Configuration ---
#define DOCK_PEEK_PIXELS         2    // ~ Pixels visible when docked at edge

// --- Custom Window Messages ---
#define APP_WM_CLOSE WM_APP  // Custom close message for cleanup
#define APP_WM_REFRESH_MEDIA (WM_APP + 1)  // Custom message to refresh media state from live source

// --- Audio Reactive Mode Flags ---
#define kAudioReactiveMode     3  // 1=Brightness, 2=Thickness, 3=Both
#define kAudioHueReactiveMode  0  // 0=Off, 1-7=Various combos (see settings)                           // ! UNUSED - DEAD CODE

// --- UI Constants ---
static const WCHAR* kFontName = L"Segoe UI Variable Display";

// --- Position Sentinel ---
constexpr int kInvalidCoordinate = std::numeric_limits<int>::min();  // Sentinel for "no saved position"

// --- Audio Reactive Tuning ---
static const float kAudioSensitivity       = 1.5f;   // Overall sensitivity multiplier
static const float kAudioSmoothing         = 0.25f;  // Lerp factor for smoothing
static const float kAudioHueSpeedBoost     = 2.5f;   // Rainbow speed multiplier during audio
static const float kAudioHuePulseAmount    = 180.0f; // Degrees of hue shift per peak
static const float kAudioHueBounceThreshold = 0.25f; // Peak threshold for direction bounce

#pragma endregion // .. Declarations\Definitions

// * ==============================================================================

#pragma region // ~ Helper Functions

void LogClampSetting(const wchar_t* name, int oldValue, int newValue);

// | Clamps value v between min and max bounds
template<typename T>
T Clamp(T v, T lo, T hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

// | Clamps setting value and logs if clamping occurred
template<typename T>
T ClampSetting(const wchar_t* name, T value, T lo, T hi) {
    T clamped = Clamp(value, lo, hi);
    if (clamped != value) {
        LogClampSetting(name, (int)value, (int)clamped);
    }
    return clamped;
}

int CalculateElementOpacity(int bgOpacity, int knee) {
    if (bgOpacity >= knee) return 255;  // TODO: SHOULD RETURN DEFAULT, NOT HARDCODED VALUE!
    if (bgOpacity <= 10) return 1;

    // Exponential Ease-Out curve: Drops rapidly right after the knee, 
    // then slows down dramatically to glide smoothly into 10.
    float progress = (knee - bgOpacity) / (float)(knee - 10);
    int element = 10 + (int)(245.0f * std::pow(1.0f - progress, 3.0f));
    
    return Clamp(element, 1, 255);  // NOTE: Keep 255 max | 1 min as to prevent mod breakage
}

// | Converts an integer percentage (0-100) to a float ratio (0.0-1.0)
// | Optionally clamps the input percentage before conversion
template<typename T = float>
T PercentToRatio(int percent, int minPercent = 0, int maxPercent = 100) {
    // Clamp the percentage to valid range
    if (percent < minPercent) percent = minPercent;
    if (percent > maxPercent) percent = maxPercent;
    
    // Convert to ratio
    return static_cast<T>(percent) / static_cast<T>(100);
}

// | Converts an integer percentage to a float ratio with custom output range
// Example: PercentToRatioScaled(50, 0.5f, 2.0f) = 1.25f (50% between 0.5 and 2.0)
template<typename T = float>
T PercentToRatioScaled(int percent, T minValue, T maxValue, int minPercent = 0, int maxPercent = 100) {
    // Clamp percentage
    if (percent < minPercent) percent = minPercent;
    if (percent > maxPercent) percent = maxPercent;
    
    // Normalize to 0.0-1.0
    T normalized = static_cast<T>(percent - minPercent) / static_cast<T>(maxPercent - minPercent);
    
    // Scale to desired range
    return minValue + (normalized * (maxValue - minValue));
}

// | Linear interpolation: returns a + f * (b - a)
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

// Extract and clamp(0-255) RGBA from color string. Returns true if valid, false if invalid string format & Default colors will be used instead.
bool ParseColorComponents(const wchar_t* str, int& r, int& g, int& b, int& a) {
    if (!str) return false;
    int ri = 0, gi = 0, bi = 0, ai = 255;
    int count = swscanf_s(str, L"%d,%d,%d,%d", &ri, &gi, &bi, &ai);
    if (count < 3) return false;
    
    r = Clamp(ri, 0, 255);
    g = Clamp(gi, 0, 255);
    b = Clamp(bi, 0, 255);
    a = Clamp(ai, 0, 255);
    return true;
}


enum class ScreenEdge { BOTTOM = 0, TOP = 1, LEFT = 2, RIGHT = 3 };

// .. COLOR THEME ENUM
enum class ColorTheme { System = 0, Custom = 1, Artwork = 2 };

// .. RESET MOD FLAGS (For ModContext aka g_Ctx)
enum ResetFlags : uint32_t {
    RESET_MEDIA   = 1 << 0,  // title, artist, albumTitle, sourceId, hasMedia, isPlaying, albumArt
    RESET_VISUAL  = 1 << 1,  // Vis + Rainbow animation state
    RESET_AUDIO   = 1 << 2,  // peak levels
    RESET_ART     = 1 << 3,  // ArtCache bitmaps, palette, transition
    RESET_HANDLES = 1 << 4,  // Wnd handles
    RESET_SYS     = 1 << 5,  // isRunning, isShutdown, eventHandlersActive
    RESET_ALL     = ~0u,
};

namespace stringtools {
    // | Trim leading and trailing whitespace from string
    inline std::wstring trim(const std::wstring& s) {
        auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::iswspace(c); });
        auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::iswspace(c); }).base();
        return (wsback <= wsfront) ? std::wstring() : std::wstring(wsfront, wsback);
    }
    
    // | Split string by delimiter and trim each token
    inline std::vector<std::wstring> split(const std::wstring& s, wchar_t delimiter) {
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
    
    // | Convert string to lowercase
    inline std::wstring toLower(const std::wstring& s) {
        std::wstring result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::towlower);
        return result;
    }
}

int GetClampedSetting(PCWSTR name, int min, int max) {
    return ClampSetting(name, Wh_GetIntSetting(name), min, max);
}

#pragma endregion // Helper Functions

// * ==============================================================================

#pragma region // ? Palette & Transition Helpers

// Smooths a color palette using a simple box blur. Modifies the palette in place. Kernel radius controls how many neighboring colors influence each entry (default 4). Handles circular palettes by wrapping around the ends.
void SmoothPalette(std::vector<Gdiplus::Color>& palette, int kernelRadius = 4) {
    int n = (int)palette.size();
    if (n < 3) return;

    std::vector<Gdiplus::Color> smoothed(n);
    int kernelSize = 2 * kernelRadius + 1;

    for (int i = 0; i < n; i++) {
        float sumR = 0, sumG = 0, sumB = 0;
        for (int k = -kernelRadius; k <= kernelRadius; k++) {
            int idx = ((i + k) % n + n) % n;  // circular wrap
            sumR += palette[idx].GetR();
            sumG += palette[idx].GetG();
            sumB += palette[idx].GetB();
        }
        smoothed[i] = Gdiplus::Color(255,
            (BYTE)(sumR / kernelSize),
            (BYTE)(sumG / kernelSize),
            (BYTE)(sumB / kernelSize));
    }
    palette = std::move(smoothed);
}

// Lerp between 2 Color Palette entries for smooth gradient sampling. Index can be fractional and wraps around the palette size.
Gdiplus::Color SamplePaletteSmooth(const std::vector<Gdiplus::Color>& palette, float index) {
    int n = (int)palette.size();
    if (n == 0) return Gdiplus::Color(255, 255, 255);
    if (n == 1) return palette[0];

    // Wrap to valid range
    index = fmodf(index, (float)n);
    if (index < 0) index += n;

    int i0 = (int)index;
    int i1 = (i0 + 1) % n;
    float frac = index - i0;

    return Gdiplus::Color(255,
        (BYTE)Lerp((float)palette[i0].GetR(), (float)palette[i1].GetR(), frac),
        (BYTE)Lerp((float)palette[i0].GetG(), (float)palette[i1].GetG(), frac),
        (BYTE)Lerp((float)palette[i0].GetB(), (float)palette[i1].GetB(), frac));
}

// | Transition from a source color toward a target color with distance-aware easing.
// | progress: 0.0 = full source, 1.0 = full target.
// | Reusable for any palette type (artwork, custom, embedded, etc).
Gdiplus::Color TransitionToTargetColor(
    BYTE srcR, BYTE srcG, BYTE srcB,
    const Gdiplus::Color& target,
    float progress)
{
    if (progress <= 0.0f) return Gdiplus::Color(255, srcR, srcG, srcB);
    if (progress >= 1.0f) return target;

    // Distance-aware easing: large color jumps fade more gradually
    float dr = (float)srcR - target.GetR();
    float dg = (float)srcG - target.GetG();
    float db = (float)srcB - target.GetB();
    float distNorm = sqrtf(dr*dr + dg*dg + db*db) / 441.67f;  // max RGB distance

    // Close colors snap faster, distant colors ease in
    float easedProgress = std::min(1.0f, progress / std::max(0.01f, distNorm + 0.1f));
    easedProgress = 1.0f - powf(1.0f - easedProgress, 2.0f);  // quadratic ease-out

    return Gdiplus::Color(255,
        (BYTE)Lerp((float)srcR, (float)target.GetR(), easedProgress),
        (BYTE)Lerp((float)srcG, (float)target.GetG(), easedProgress),
        (BYTE)Lerp((float)srcB, (float)target.GetB(), easedProgress));
}

// | Snapshots a palette into the previous-palette slot for cross-fade transitions.
// | Called before overwriting with new colors (e.g., on media change, palette switch).
// | Single-threaded — MediaThread owns ArtCache; no synchronization required.
void SnapshotPalette(std::vector<Gdiplus::Color>& dest, const std::vector<Gdiplus::Color>& src) {
    if (!src.empty()) {
        dest = src;
    }
}

#pragma endregion // Palette & Transition Helpers

// ! ==============================================================================

#pragma region // ^ Windows API Extensions

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
    ACCENT_STATE AccentState;   // ← ACCENT_ENABLE_ACRYLICBLURBEHIND
    DWORD AccentFlags;           // ← Always 0 in your code
    DWORD GradientColor;         // ← Your tint (calculated from settings)
    DWORD AnimationId;           // ← Always 0 in your code
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

static pCreateWindowInBand s_CreateWindowInBand = nullptr;

// --- DPI Awareness Context API ---
typedef BOOL(WINAPI* pLogicalToPhysical)(HWND, LPPOINT);
typedef BOOL(WINAPI* pPhysicalToLogical)(HWND, LPPOINT);

static pLogicalToPhysical s_LogicalToPhysical = nullptr;
static pPhysicalToLogical s_PhysicalToLogical = nullptr;

#pragma endregion // Windows API Extensions

// * ==============================================================================

#pragma region // ^ Settings Structure

// .. LIVE SETTINGS - Values are read from Windhawk settings and stored here for easy access throughout the code.
// Changes to settings at runtime should update this struct and apply changes immediately where possible. (Default values set above^ in `WindhawkModSettings` struct definition)
struct ModSettings {
    // --- Dimensions & Position ---
    int width;              // Widget width in pixels
    int height;             // Widget height in pixels
    int maxArtSize;         // Max album art height cap
    int buttonSize;         // Button size % relative to Art (10-120)
    int textScale;          // Text scale % (50-200)
    int offsetX;            // Horizontal offset from taskbar edge
    int offsetY;            // Vertical offset from taskbar center
    
    // --- Theme & Colors ---
    ColorTheme colorTheme;  // Color theme: System/Custom/Artwork
    bool invertColors;      // Invert RGB values for background
    DWORD interfaceColor;   // Interface color (ARGB) - controls Text & Buttons
    DWORD manualBgColorRGB; // Manual background color (BGR for DWM)
    int currentOpacity;     // Current opacity value (0-255)
    
    // --- Behavior ---
    // Game detection removed
    int idleTimeout;        // Hide after N seconds idle (0=disabled)
    bool EnableTextScroll;  // Enable text scrolling for long titles
    int scaleEasing;        // Button scaling aggression
    bool enableSlide;       // Enable slide animation
    // Game detection removed
    // Game detection removed
    
    // --- Rainbow Border ---
    bool enableRainbow;         // Enable rainbow border effect
    bool rainbowAboveWidget;    // Render rainbow above media widget    // !  Removed - This setting is now controlled by a trigger action for dynamic toggling
    int rainbowSpeed;           // Rainbow hue rotation speed
    int rainbowBrightness;      // Rainbow brightness (0-100)
    int rainbowThickness;       // Border thickness in pixels
    int rainbowBorderOffset;    // Border position offset
    bool enableRoundedCorners;  // Rounded corners on border
    bool centered;              // Center text when not scrolling
    
    // Internal state (not user-configurable)
    bool storedRainbowAboveWidget = false;      // For the Rainbow Z-Order Action

    // --- Advanced Audio Processing ---
    int audioResponsiveness;    // How quickly audio reacts
    int audioThreshold;         // Audio activation threshold
    int audioRamp;              // Ramp-up speed
    bool audioBinary;           // Binary on/off mode
    int audioFlicker;           // Anti-flicker setting
    bool audioDynamicRange;     // Use dynamic range processing
    int audioMinValue;          // Min output value
    int audioMaxValue;          // Max output value
    int audioHueReactiveMode;   // Hue reactive mode (0-7)
} g_Settings;

// .. Main mod context struct holding all global state and handles in an organized manner. This is passed to functions that need access to the mod's state.
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
        UINT lastSysDPI = 0;            // cache of GetDpiForSystem() for SETTINGS broadcasts
        std::atomic<bool> eventHandlersActive{ false };
        ULONG_PTR gdiplusToken = 0;
    } Sys;

    // Visibility & Animations
    struct {
        int hoverState = 0;
        // Game detection removed
        std::atomic<int> animState{ 0 }; // 0=Sync, 1=Hiding, 2=Showing, 3=Shutdown/Docked
        int currentAnimX = 0;            // Current X during animation frames
        int currentAnimY = 0;
        ScreenEdge animEdge{ ScreenEdge::BOTTOM }; // Which edge this animation uses
        int normalX = 0;                 // Saved X position before docking
        int normalY = 0;                 // Saved Y position before docking
        int dockedMode = 0;              // 0=normal, 1=edge-docked, 2=off-screen
        std::atomic<int> idleSecondsCounter{ 0 };
        std::atomic<bool> isHiddenByIdle{ false };
        std::atomic<bool> mediaStateInitialized{ false }; // Track if we've gotten initial GSMTC state
        int currentOpacity = 255;        // Window opacity (0-255, 255=fully opaque)
    } Vis;

    // Rainbow Effect State
    struct {
        std::atomic<float> hue{ 0.0f };
        std::atomic<int> animState{ 0 };    // 0=Sync, 1=Hiding, 2=Showing, 3=Shutdown/Docked
        int currentAnimY = 0;
        std::atomic<bool> directionReverse{ false };
        std::atomic<float> flashProgress{ 0.0f };  // 0=idle, 0→1=double-pulse error alert
    } Rainbow;

    // Audio Reactive State
    struct {
        std::atomic<float> peakLevel{ 0.0f };
        std::atomic<float> peakSmoothed{ 0.0f };
        bool runtimeEnabled = true;
        bool appVolumeMode = false; // false = system-wide, true = current media app
    } Audio;

    // Text State (scroll + cache)
    struct {
        int offset = 0;
        int textWidth = 0;
        bool isScrolling = false;
        int waitCounter = 60;
        std::wstring textSignature;
        unsigned long long fontSignature = 0;
        unsigned long long colorSignature = 0;
        int stripHeight = 0;
        BitmapPtr stripBitmap = nullptr;
        bool dirty = true;
    } Text;

    // Media State (MediaThread owns wstring/bitmap fields; hasMedia is atomic for WinRT-thread reads)
    struct MediaState {
        wstring title = L"No Media";
        wstring artist = L"";
        wstring albumTitle = L"";
        BitmapPtr albumArt = nullptr;
        bool isPlaying = false;
        std::atomic<bool> hasMedia{ false };
        wstring sourceId = L"";
        wstring lastValidSourceId = L"";
    } Media;

    // Artwork Cache (pre-computed palette + scaled bg for Artwork theme)
    struct {
        std::atomic<bool> dirty{ false };         // Set from media thread, cleared after regen
        std::atomic<float> transitionProgress{ 0.0f }; // 0=full previous, 1=full current palette
        BitmapPtr bgBitmap;                        // Pre-rendered art (viewport, full alpha, RAII — must free before GdiplusShutdown)
        BitmapPtr previousBgBitmap;                // Snapshot of old bg for cross-fade
        std::vector<Gdiplus::Color> palette;       // Perimeter-sampled colors (1:1 with segments)
        std::vector<Gdiplus::Color> previousPalette; // Snapshot of old palette for cross-fade (empty = fall back to rainbow)
        BitmapPtr previousAlbumArt;                // Snapshot of old album art for cross-fade
    } ArtCache;

    // Persistence
    struct PersistedState {
        int lastX = kInvalidCoordinate;
        int lastY = kInvalidCoordinate;
        int lastW = 0;
        int lastH = 0;
        int lastSettingsW = 0;   // PanelWidth when LastW was saved
        int lastSettingsH = 0;   // PanelHeight when LastH was saved
        int lastOffsetX = 0;     // OffsetX when LastX was saved
        int lastOffsetY = 0;     // OffsetY when LastY was saved
        int lastOpacity = 255; // Persisted opacity for consistency across sessions (updated on change, used on load aka default for EffectiveOpacity)
        int64_t lastLaunchTime = 0;
        int crashCount = 0;
        std::wstring lastTitle;
        std::wstring lastArtist;
    } Persisted;

    // Palette Engine State
    struct {
        int activeMode = -1; // -1 = Live Media Art, 0+ = index of saved palette
        std::vector<std::vector<Gdiplus::Color>> savedPalettes;
    } PaletteEngine;

    void Reset(uint32_t flags = RESET_ALL) {
    if (flags & RESET_HANDLES) {
        Wnd.main = NULL;
        Wnd.rainbow = NULL;
        Wnd.taskbar = NULL;
        Wnd.visibilityHook = NULL;
    }

    if (flags & RESET_SYS) {
        Sys.isRunning = true;
        Sys.isShutdown = false;
        Sys.eventHandlersActive = false;
    }

    if (flags & RESET_VISUAL) {
        Vis.hoverState = 0;
        Vis.animState = 0;
        Vis.currentAnimX = 0;
        Vis.currentAnimY = 0;
        Vis.animEdge = ScreenEdge::BOTTOM;
        Vis.idleSecondsCounter = 0;
        Vis.isHiddenByIdle = false;
        Vis.mediaStateInitialized = false;
        Vis.currentOpacity = 255;
        Rainbow.hue = 0.0f;
        Rainbow.animState = 0;
        Rainbow.currentAnimY = 0;
        Rainbow.directionReverse = false;
        Rainbow.flashProgress = 0.0f;
        Text.offset = 0;
        Text.textWidth = 0;
        Text.isScrolling = false;
        Text.waitCounter = 60;
        Text.textSignature.clear();
        Text.fontSignature = 0;
        Text.colorSignature = 0;
        Text.stripHeight = 0;
        Text.stripBitmap.reset();
        Text.dirty = true;
    }

    if (flags & RESET_ART) {
        PaletteEngine.activeMode = -1;
        ArtCache.dirty = false;
        ArtCache.transitionProgress = 0.0f;
        ArtCache.bgBitmap.reset();
        ArtCache.previousBgBitmap.reset();
        ArtCache.palette.clear();
        ArtCache.previousPalette.clear();
        ArtCache.previousAlbumArt.reset();
    }

    if (flags & RESET_AUDIO) {
        Audio.peakLevel = 0.0f;
        Audio.peakSmoothed = 0.0f;
    }

    if (flags & RESET_MEDIA) {
        Media.title = L"No Media";
        Media.artist = L"";
        Media.albumTitle = L"";
        Media.sourceId = L"";
        Media.lastValidSourceId = L"";
        Media.hasMedia = false;
        Media.isPlaying = false;
        Media.albumArt.reset();
    }
}
} g_Ctx;

#pragma endregion // Settings Structure

// * ==============================================================================

#pragma region // ^ Inline Utility Helpers
// ! These helpers are CONTEXT-DEPENDENT, They depend on g_Ctx/g_Settings being defined above^

// | Apply DPI scale factor to any value
inline int Scale(int value) {
    return (int)(value * g_Ctx.Sys.scaleFactor);
}

// | Effective dimensions: persisted override (AltSnap'd) if valid AND settings unchanged, else scaled settings
inline int EffectiveW() {
    // Check if width setting has changed since position was saved
    bool widthChanged = (g_Ctx.Persisted.lastSettingsW != g_Settings.width);
    bool hasSavedWidth = (g_Ctx.Persisted.lastW > 0);
    
    // Use saved width only if setting hasn't changed
    if (hasSavedWidth && !widthChanged) {
        return g_Ctx.Persisted.lastW;
    }
    
    // Default: use current scaled setting
    return Scale(g_Settings.width);
}

// Effective H with additional logic to prevent excessive height if user manually resized to a very short height (e.g., for a thin taskbar) - Clamps to either persisted height or scaled setting, whichever is smaller
inline int EffectiveH() {
    // Check if height setting has changed since position was saved
    bool heightChanged = (g_Ctx.Persisted.lastSettingsH != g_Settings.height);
    bool hasSavedHeight = (g_Ctx.Persisted.lastH > 0);
    
    // Use saved height only if setting hasn't changed
    if (hasSavedHeight && !heightChanged) {
        return g_Ctx.Persisted.lastH;
    }
    
    // Default: use current scaled setting
    return Scale(g_Settings.height);
}

// Helper for inline functions to avoid dependency on global WindowManager instance
inline HWND InlineGetTaskbar() {
    if (g_Ctx.Wnd.taskbar && IsWindow(g_Ctx.Wnd.taskbar)) {
        return g_Ctx.Wnd.taskbar;
    }

    HWND taskbar = FindWindowW(L"Shell_TrayWnd", NULL);
    if (taskbar) {
        g_Ctx.Wnd.taskbar = taskbar;
        return taskbar;
    }

    return GetDesktopWindow();
}

inline int EffectiveOpacity() {
    // Prefer a valid persisted opacity (>0); otherwise fall back to current settings value.
    if (g_Ctx.Persisted.lastOpacity > 0) return g_Ctx.Persisted.lastOpacity;
    return g_Settings.currentOpacity;
}

static int g_opacityElementThreshold = 50;  // Opacity knee: below this, UI elements begin fading
// | Opacity knee: returns alpha for UI elements, fading linearly below threshold
inline BYTE GetElementAlpha() {
    int opacity = EffectiveOpacity();
    if (opacity >= g_opacityElementThreshold) return 255;  // Fully opaque above threshold
    // Linear fade from threshold to 0: at threshold=255, at 0=0
    return (BYTE)((opacity * 255) / g_opacityElementThreshold);
}

inline int EffectiveX() {
    // Check if offsets have changed since position was saved
    bool offsetsChanged = (g_Ctx.Persisted.lastOffsetX != g_Settings.offsetX || 
                          g_Ctx.Persisted.lastOffsetY != g_Settings.offsetY);
    bool hasSavedPosition = (g_Ctx.Persisted.lastX != kInvalidCoordinate && 
                            g_Ctx.Persisted.lastY != kInvalidCoordinate);
    
    // Use saved position only if offsets haven't changed
    if (hasSavedPosition && !offsetsChanged) {
        return g_Ctx.Persisted.lastX;
    }
    
    // Default: taskbar-relative positioning with current offsets
    RECT taskbarRect;
    GetWindowRect(InlineGetTaskbar(), &taskbarRect);
    return taskbarRect.left + Scale(g_Settings.offsetX);
}

inline int EffectiveY() {
    // Check if offsets have changed since position was saved
    bool offsetsChanged = (g_Ctx.Persisted.lastOffsetX != g_Settings.offsetX || 
                          g_Ctx.Persisted.lastOffsetY != g_Settings.offsetY);
    bool hasSavedPosition = (g_Ctx.Persisted.lastX != kInvalidCoordinate && 
                            g_Ctx.Persisted.lastY != kInvalidCoordinate);
    
    // Use saved position only if offsets haven't changed
    if (hasSavedPosition && !offsetsChanged) {
        return g_Ctx.Persisted.lastY;
    }
    
    // Default: taskbar-relative positioning with current offsets
    RECT taskbarRect;
    HWND hTaskbar = InlineGetTaskbar();
    GetWindowRect(hTaskbar, &taskbarRect);
    int taskbarHeight = taskbarRect.bottom - taskbarRect.top;
    int taskbarCenterY = taskbarRect.top + (taskbarHeight / 2);
    return taskbarCenterY - (EffectiveH() / 2) + Scale(g_Settings.offsetY);
}

// | Decode Windows event types for logging
inline const wchar_t* DecodeEventType(DWORD event) {
    switch(event) {
        case 0x800B: return L"LOCATIONCHANGE";
        case 0x8002: return L"SHOW";
        case 0x8003: return L"HIDE";
        case 0x0003: return L"FOREGROUND";
        default: return L"UNKNOWN";
    }
}

// | Get foreground app executable name
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

//  Log when a setting value is clamped to inform users of invalid config values in registry or UI
void LogClampSetting(const wchar_t* name, int oldValue, int newValue) {
    if (oldValue > newValue) {
    Wh_Log(L"[Settings] %s ---- CLAMPED: %d -> %d", name, oldValue, newValue);
    } else {
    Wh_Log(L"[Settings] WARNING: %s ---- CLAMPED: %d -> %d", name, oldValue, newValue);
    }
}

// | Pulses the entire rainbow border red twice as a visual error alert.
// | Safe to call anytime — works across all color modes, interrupts nothing.
void TriggerErrorFlash() {
    g_Ctx.Rainbow.flashProgress = 0.001f;  // non-zero kicks off the tick
    if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow))
        InvalidateRect(g_Ctx.Wnd.rainbow, NULL, FALSE);
}

#pragma endregion // ^ Inline Utility Helpers

// * ==============================================================================

#pragma region // ^ Registry Management

// ~ Palette compression/persistence helpers — depend on g_Ctx and SamplePaletteSmooth.
namespace PaletteStorage {
    // Convert 1 color to 6-char hex (e.g., "FF00AA")
    std::wstring ColorToHex(const Gdiplus::Color& c) {
        wchar_t buf[8];
        swprintf_s(buf, L"%02X%02X%02X", c.GetR(), c.GetG(), c.GetB());
        return std::wstring(buf);
    }

    // Convert 6-char hex string to Color
    Gdiplus::Color HexToColor(const std::wstring& hex) {
        if (hex.length() < 6) return Gdiplus::Color(255, 255, 255, 255);
        int r = 0, g = 0, b = 0;
        swscanf_s(hex.c_str(), L"%02x%02x%02x", &r, &g, &b);
        return Gdiplus::Color(255, (BYTE)r, (BYTE)g, (BYTE)b);
    }

    // Downsample live palette to targetSamples via smooth interpolation, encode as CSV hex
    std::wstring EncodePalette(const std::vector<Gdiplus::Color>& palette, int targetSamples = 36) {
        if (palette.empty()) return L"FFFFFF";
        std::wstring result;
        for (int i = 0; i < targetSamples; ++i) {
            float index = (float)i / targetSamples * (float)palette.size();
            Gdiplus::Color c = SamplePaletteSmooth(palette, index);
            result += ColorToHex(c);
            if (i < targetSamples - 1) result += L",";
        }
        return result;
    }

    // Decode CSV hex string back to a color vector
    std::vector<Gdiplus::Color> DecodePalette(const std::wstring& csv) {
        std::vector<Gdiplus::Color> result;
        for (const auto& tok : stringtools::split(csv, L','))
            result.push_back(HexToColor(tok));
        if (result.empty()) result.push_back(Gdiplus::Color(255, 255, 255, 255));
        return result;
    }

    void SavePaletteToRegistry(int index, const std::vector<Gdiplus::Color>& palette) {
        std::wstring key = L"SavedPalette_" + std::to_wstring(index);
        Wh_SetStringValue(key.c_str(), EncodePalette(palette).c_str());
    }

    void LoadPalettesFromRegistry() {
        g_Ctx.PaletteEngine.savedPalettes.clear();
        int count = Wh_GetIntValue(L"SavedPaletteCount", 0);
        for (int i = 0; i < count; ++i) {
            std::wstring key = L"SavedPalette_" + std::to_wstring(i);
            wchar_t buffer[2048] = {0};
            if (Wh_GetStringValue(key.c_str(), buffer, ARRAYSIZE(buffer)) > 0)
                g_Ctx.PaletteEngine.savedPalettes.push_back(DecodePalette(buffer));
        }
        Wh_Log(L"[Palette] Loaded %d saved palette(s)", (int)g_Ctx.PaletteEngine.savedPalettes.size());
    }
}

class RegistryManager {
private:
    std::thread m_autoHideListenerThread;
    std::atomic<bool> m_stopListener{false};
    std::function<void()> m_autoHideChangedCallback;
    static constexpr const wchar_t* kExplorerAdvancedPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced";

    void AutoHideListenerThreadProc() {
        HKEY hKey = NULL;
        if (RegOpenKeyEx(HKEY_CURRENT_USER, kExplorerAdvancedPath, 0, KEY_NOTIFY, &hKey) != ERROR_SUCCESS) {
            Wh_Log(L"[Registry] ERROR: Failed to open key for auto-hide listener");
            return;
        }

        Wh_Log(L"[Registry] Auto-hide listener thread started");
        while (!m_stopListener) {       // Wait for changes to the Explorer Advanced key | Unless stop signal is set
            if (RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, NULL, FALSE) == ERROR_SUCCESS) {
                if (m_stopListener) break;
                
                Wh_Log(L"[Registry] Explorer Advanced key changed, checking auto-hide state");
                
                // Invoke callback to trigger recheck   LEAVE ALONE
                if (m_autoHideChangedCallback) {
                    m_autoHideChangedCallback();
                }
            }
        }
        
        RegCloseKey(hKey);
        Wh_Log(L"[CLEANUP] Auto-hide listener thread stopped");
    }

public:
        RegistryManager() {}
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
#pragma endregion // ^ Registry Management

// ! ====================================================================================================================================================================================================

#pragma region // ^ -- Window Manager

// Manages the main media widget window, including creation, painting, and state updates
class WindowManager {
public:
    WindowManager() = default;
    
    // NEW: Cleanup cached memory when the mod unloads
    ~WindowManager() {
        if (m_memBitmap) DeleteObject(m_memBitmap);
        if (m_memDC) DeleteDC(m_memDC);
    }

    // Centralized taskbar handle acquisition
    HWND GetTaskbar();

    // Initialization (call after window creation)
    void Initialize(HWND hMainWnd) {
        g_Ctx.Wnd.main = hMainWnd;
        UpdateAppearance(hMainWnd);
    }

    // Message Handlers
    void OnPaint(HWND hwnd) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        // NEW: Uses the cached paint method
        ExecuteCachedBufferedPaint(hwnd, hdc, [&](Graphics& graphics) {
            graphics.Clear(Color(0, 0, 0, 0)); 
            graphics.ScaleTransform(g_Ctx.Sys.scaleFactor, g_Ctx.Sys.scaleFactor);
            DrawMediaPanel(graphics); 
        });

        EndPaint(hwnd, &ps);
    }

    void OnTimer(HWND hwnd, UINT_PTR timerId);
    void OnMasterTick(HWND hwnd); // Unified 60fps game loop
    void OnMouseWheel(HWND hwnd, WPARAM wParam, LPARAM lParam);

    // State & Visual Updates
    void UpdateAppearance(HWND hwnd);
    void SyncPositionWithTaskbar();
    void ToggleDockedMode(bool offScreen = false, int targetX = kInvalidCoordinate, int targetY = kInvalidCoordinate, int targetW = 0, int targetH = 0);
    void ApplyRainbowPos(int x, int y, int w, int h);

    // Helper: Determining visibility logic
    bool ShouldWindowBeHidden();
   
private:
    // Drawing Implementation (Internal)
    void DrawMediaPanel(Graphics& graphics);

    // NEW: Cached GDI Buffers
    HDC m_memDC = NULL;
    HBITMAP m_memBitmap = NULL;
    int m_cachedWidth = 0;
    int m_cachedHeight = 0;

    // NEW: The Cached Paint Engine (fully contained inside the class!)
    void ExecuteCachedBufferedPaint(HWND hwnd, HDC hdc, std::function<void(Graphics&)> paintFunc) {
        if (!paintFunc) return;

        RECT rc; GetClientRect(hwnd, &rc);
        int width = rc.right - rc.left;
        int height = rc.bottom - rc.top;

        // Recreate only if the window size changes
        if (!m_memDC || !m_memBitmap || m_cachedWidth != width || m_cachedHeight != height) {
            if (m_memBitmap) DeleteObject(m_memBitmap);
            if (m_memDC) DeleteDC(m_memDC);

            m_memDC = CreateCompatibleDC(hdc);
            m_memBitmap = CreateCompatibleBitmap(hdc, width, height);
            m_cachedWidth = width;
            m_cachedHeight = height;
        }

        HBITMAP oldBitmap = (HBITMAP)SelectObject(m_memDC, m_memBitmap);

        Graphics graphics(m_memDC);
        graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
        graphics.SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);
        
        paintFunc(graphics);

        BitBlt(hdc, 0, 0, width, height, m_memDC, 0, 0, SRCCOPY);

        SelectObject(m_memDC, oldBitmap);
    }
};

// Global instance
WindowManager g_WindowManager;

#pragma endregion // -- Window Manager

//& ====================================================================================================================================================================================================

#pragma region  // ^ Audio COM API Wrapper

// | Manages COM-based audio metering for reactive effects
class AudioCOMAPI {
public:
    AudioCOMAPI() 
        : m_isInitialized(false)
        , m_isCOMInitialized(false)
        , m_pDeviceEnumerator(nullptr)
        , m_pAudioMeter(nullptr)
        , m_meterInitialized(false) 
    {}
    
    // | Initialize COM and device enumerator
    bool Init() {
        if (!m_isCOMInitialized) {
            HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
            if (hr == S_OK || hr == S_FALSE) {
                m_isCOMInitialized = true;  // COM initialized (S_OK) or already initialized on this thread (S_FALSE) — balance with CoUninitialize
                Wh_Log(L"[Audio COM] CoInitializeEx: %s", hr == S_OK ? L"S_OK" : L"S_FALSE (already initialized on thread; will balance with CoUninitialize)");
            } else if (hr == RPC_E_CHANGED_MODE) {
                // COM already initialized by WinRT with different apartment model.
                // COM is usable, but we didn't init it — don't CoUninitialize later.
                Wh_Log(L"[Audio COM] COM already initialized (different apartment mode) - using existing");
            } else {
                Wh_Log(L"[Audio COM] CoInitializeEx failed: 0x%08X", (unsigned)hr);
                return false;
            }
        }
        
        if (!m_isInitialized) {
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
    
    // | Get current audio peak level (0.0-1.0)
    float GetPeakLevel() {
        if (!m_meterInitialized || !m_pAudioMeter) return 0.0f;
        float peak = 0.0f;
        if (SUCCEEDED(m_pAudioMeter->GetPeakValue(&peak))) {
            return peak;
        }
        return 0.0f;
    }
    
    // | Release all COM resources
    void Uninit() {
        if (m_pAudioMeter) {
            m_pAudioMeter = nullptr;
            m_meterInitialized = false;
            Wh_Log(L"[CLEANUP] IAudioMeterInformation Released");
        }
        if (m_isInitialized) {
            m_pDeviceEnumerator = nullptr;
            m_isInitialized = false;
            Wh_Log(L"[CLEANUP] IMMDeviceEnumerator Released");
        }
        if (m_isCOMInitialized) {
            CoUninitialize();
            m_isCOMInitialized = false;
            Wh_Log(L"[CLEANUP] COM uninitialized");
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

#pragma endregion  // ^ Audio COM API Wrapper

// ! ============================================================================

#pragma region // ^ Action Engine
// ~ Centralized input handling and trigger execution

// | Keyboard modifier key identifiers
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

// ~~~ CENTRALIZED MODIFIER MAPPING (MODULE-LEVEL) ~~~
// ! Single source of truth for all modifier name conversions and enum mappings
namespace ModifierMapping {
    // Display names (enum index must match KeyModifier order)
    static constexpr const wchar_t* kModifierDisplayNames[] = {
        L"LCtrl",   // KEY_MODIFIER_LCTRL = 0
        L"RCtrl",   // KEY_MODIFIER_RCTRL = 1
        L"LAlt",    // KEY_MODIFIER_LALT = 2
        L"RAlt",    // KEY_MODIFIER_RALT = 3
        L"LShift",  // KEY_MODIFIER_LSHIFT = 4
        L"RShift",  // KEY_MODIFIER_RSHIFT = 5
        L"LWin",    // KEY_MODIFIER_LWIN = 6
    };

    // Parser names for hotkey parsing (enum index must match KeyModifier order)
    static constexpr const wchar_t* kModifierParserNames[] = {
        L"lctrl",   // KEY_MODIFIER_LCTRL = 0
        L"rctrl",   // KEY_MODIFIER_RCTRL = 1
        L"lalt",    // KEY_MODIFIER_LALT = 2
        L"ralt",    // KEY_MODIFIER_RALT = 3
        L"lshift",  // KEY_MODIFIER_LSHIFT = 4
        L"rshift",  // KEY_MODIFIER_RSHIFT = 5
        L"win",     // KEY_MODIFIER_LWIN = 6
    };

    // Generic modifier mapping for FromStringHotKey (ALT, CTRL, SHIFT, WIN → MOD_* constants)
    static const std::unordered_map<std::wstring_view, UINT> kGenericModifiersMap = {
        {L"ALT", MOD_ALT}, {L"CTRL", MOD_CONTROL}, {L"SHIFT", MOD_SHIFT}, {L"WIN", MOD_WIN},
    };
}

// | Set a specific bit in a value (for modifier bitmask)
inline void SetBit(uint32_t& value, uint32_t bit) { 
    value |= (1U << bit); 
}

// | Get current state of all modifier keys as bitmask
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

// | Get modifier name from KeyModifier enum
const wchar_t* GetModifierName(KeyModifier mod) {
    if (mod >= 0 && mod < KEY_MODIFIER_INVALID) {
        return ModifierMapping::kModifierDisplayNames[mod];
    }
    return L"?";
}

// | Convert modifier bitmask to readable string (e.g. "LCtrl(0x1) + LShift(0x10)")
std::wstring GetModifierNamesFromBitmask(uint32_t modMask) {
    std::vector<std::wstring> names;
    for (int i = 0; i < KEY_MODIFIER_INVALID; i++) {
        if (modMask & (1U << i)) {
            KeyModifier mod = static_cast<KeyModifier>(i);
            uint32_t bitValue = (1U << i);
            wchar_t buf[32];
            swprintf_s(buf, 32, L"%s(0x%X)", GetModifierName(mod), bitValue);
            names.push_back(buf);
        }
    }
    
    if (names.empty()) return L"None";
    std::wstring result = names[0];
    for (size_t i = 1; i < names.size(); i++) {
        result += L" + " + names[i];
    }
    return result;
}

// | Convert modifier name string to enum value
KeyModifier GetKeyModifierFromName(const std::wstring& keyName) {
    for (int i = 0; i < KEY_MODIFIER_INVALID; i++) {
        if (keyName == ModifierMapping::kModifierParserNames[i]) {
            return static_cast<KeyModifier>(i);
        }
    }
    return KEY_MODIFIER_INVALID;
}

// | Parse hotkey string (e.g. "Ctrl+Shift+P") into modifiers bitmask and virtual key code
bool FromStringHotKey(std::wstring_view hotkeyString, UINT* modifiersOut, UINT* vkOut) {
    // Use centralized modifier mapping
    const auto& modifiersMap = ModifierMapping::kGenericModifiersMap;
    
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

// | Parse and start a process with the given command string - Likely will move to Action Engine if possible BUT kept here for now since it's used by the switch-to-audible-window feature which is closely tied to window management
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


// | Helper: get AUMID from a window  - used to identify source app
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

// | Responsible for finding windows based on AUMID, executable name, or title substring. Used by the switch-to-audible-window feature and script targeting. Returns FALSE to stop enumeration when a match is found.
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

// Resolves the current GSMTC media source AUMID to its window + PID.
// Accepts an optional sourceId override; defaults to g_Ctx.Media.sourceId.
// Must only be called from MediaThread.
struct MediaSourceWindow { HWND hwnd = NULL; DWORD pid = 0; std::wstring exeName; };

// NEW: Enhanced window resolver that can find windows by AUMID, executable name, or title substring (for scripts). Also captures PID and executable name for logging.
MediaSourceWindow ResolveMediaSourceWindow(const std::wstring& sourceId = L"") {
    const std::wstring& id = sourceId.empty() ? g_Ctx.Media.sourceId : sourceId;
    MediaSourceWindow result;
    if (id.empty()) return result;
    WinSearchData search = { id, L"", NULL, false, L"", false };
    EnumWindows(FindWindowByAUMIDOrExe, (LPARAM)&search);
    if (!search.foundHwnd) return result;
    result.hwnd = search.foundHwnd;
    GetWindowThreadProcessId(search.foundHwnd, &result.pid);
    // also capture executable name for logging
    if (result.pid) {
        HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, result.pid);
        if (hProc) {
            WCHAR path[MAX_PATH] = {0};
            DWORD size = MAX_PATH;
            if (QueryFullProcessImageNameW(hProc, 0, path, &size)) {
                std::wstring full(path);
                size_t pos = full.find_last_of(L"\\/");
                result.exeName = (pos != std::wstring::npos) ? full.substr(pos + 1) : full;
            }
            CloseHandle(hProc);
        }
    }
    return result;
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
            Wh_Log(L"[ACTION] %s Checking process: %s (Raw: %s)", logPrefix.c_str(), filenameLower.c_str(), cmd.c_str());
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
            Wh_Log(L"[ACTION] %s Checking script/title: %s (Raw: %s)", logPrefix.c_str(), exeSearch.targetTitle.c_str(), cmd.c_str());
    }
    
    EnumWindows(FindWindowByAUMIDOrExe, (LPARAM)&exeSearch);
    
    if (exeSearch.foundHwnd) {
        // Already running - focus it
        if (IsIconic(exeSearch.foundHwnd)) ShowWindow(exeSearch.foundHwnd, SW_RESTORE);
        SetForegroundWindow(exeSearch.foundHwnd);
        Wh_Log(L"[ACTION] %s %s already running - focused", logPrefix.c_str(), cmd.c_str());
    } else {
        StartProcess(cmd);
        Wh_Log(L"[ACTION] %s Launched: %s", logPrefix.c_str(), cmd.c_str());
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

// Keypress retry constants (for handling stuck modifiers while sending keys)
static const int kMaxKeypressRetryCount = 50;     // Max retry attempts before forced send
static constexpr int kMaxPendingActions = 5;       // Max queued delayed actions (0 = unlimited)

class ActionDispatcher {
public:     // |-- ActionDispatcher | Responsible for executing actions with optional delays and managing triggers
    struct PendingAction {
        std::function<void()> action;
        DWORD executeAtTick;
        std::wstring description;
    };

    // Public triggers registry
    std::vector<ConfiguredTrigger> triggers;


    void ExecuteWithDelay(std::function<void()> action, float delaySeconds, const std::wstring& actionName) {
        Wh_Log(L"[DELAY] Queueing action with %.2f second delay", delaySeconds);
        
        std::wstring desc = actionName;
        if (!g_currentTriggerContext.empty()) {
            desc = L"[MusicLounge] " + g_currentTriggerContext + L" '" + actionName + L"' executed (DELAYED)";
        }

        // Evict oldest if at capacity
        if (kMaxPendingActions > 0 && (int)m_pendingActions.size() >= kMaxPendingActions) {
            Wh_Log(L"[DELAY] Queue full (%d/%d), evicting oldest: %s",
                (int)m_pendingActions.size(), kMaxPendingActions, m_pendingActions.front().description.c_str());
            m_pendingActions.erase(m_pendingActions.begin());
        }

        m_pendingActions.push_back({action, GetTickCount() + (DWORD)(delaySeconds * 1000), desc});
        Wh_Log(L"[DELAY] Queue size: %d/%d", (int)m_pendingActions.size(), kMaxPendingActions);
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

    void SendKeypress(const std::vector<int>& keys) {
        if (keys.empty()) return;
        if (AreModifierKeysPressed()) {
            m_pendingKeypressKeys = keys;
            m_keypressRetryCount = 0;
            Wh_Log(L"[INPUT] Modifiers held, deferring keypress until release");
        } else {
            InternalSendInput(keys);
        }
    }

    void ProcessDelayedActions() {
        // Check pending keypress retry (waits for modifier release or timeout)
        if (!m_pendingKeypressKeys.empty()) {
            if (!AreModifierKeysPressed() || ++m_keypressRetryCount >= kMaxKeypressRetryCount) {
                Wh_Log(L"[INPUT] Modifiers released, sending deferred keypress");
                InternalSendInput(m_pendingKeypressKeys);
                m_pendingKeypressKeys.clear();
                m_keypressRetryCount = 0;
            }
        }
        
        if (m_pendingActions.empty()) return;

        Wh_Log(L"[DELAY] Timer tick - checking %d pending actions", (int)m_pendingActions.size());
        
        DWORD now = GetTickCount();
        auto it = m_pendingActions.begin();
        while (it != m_pendingActions.end()) {
            if (now >= it->executeAtTick || (now < 100000 && it->executeAtTick > 0xFFFFFF00)) {
                Wh_Log(L"[DELAY] Executing: %s", it->description.c_str());
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
        
    }

    void ClearPendingActions() {
        m_pendingActions.clear();
    }

    bool DispatchTrigger(const std::wstring& detectedTriggerName, int zDelta = 0) {
        // Game detection removed - only input triggers now
        
        // Log entry
        uint32_t currentMods = GetKeyModifiersState();
        if (currentMods != 0) {
            Wh_Log(L"[ActionEngine] Dispatching INPUT Trigger: '%s' (Active Total Triggers: %zu, Modifiers: %s)", detectedTriggerName.c_str(), triggers.size(), GetModifierNamesFromBitmask(currentMods).c_str());
        } else {
            Wh_Log(L"[ActionEngine] Dispatching INPUT Trigger: '%s' (Active Total Triggers: %zu)", detectedTriggerName.c_str(), triggers.size());
        }
        
        bool handled = false;
        for(const auto& t : triggers) {
            // 1. Strict Name Match
            if (t.mouseTriggerName != detectedTriggerName) continue;

            // 2. Isolation Logic: Modifiers — must match held modifiers exactly
            if (t.expectedModifiers != currentMods) continue;

            // 3. Execution Phase
            if (!t.actions.empty()) {
                Wh_Log(L"[ActionEngine] >> MATCH MATCHED: '%s' (%zu actions)", detectedTriggerName.c_str(), t.actions.size());
                
                for (size_t i = 0; i < t.actions.size(); i++) {
                    const auto& [actionName, actionFunc] = t.actions[i];
                    if (!actionFunc) continue;

                    g_currentTriggerContext = L"TriggerCtx: " + detectedTriggerName;

                    // Log execution
                    Wh_Log(L"[ActionEngine]    Invoking: %s", actionName.c_str());

                    // Contextual log for scroll/volume operations
                    if (zDelta != 0 && actionName.find(L"VOLUME") != std::wstring::npos) {
                        Wh_Log(L"[ActionEngine]    (Context: Scroll/Volume Delta: %+d)", zDelta);
                    }

                    actionFunc();
                    g_currentTriggerContext.clear();
                }
                handled = true;
            }
        }
        return handled;
    }

private:
    std::vector<int> m_pendingKeypressKeys;  // Keys deferred while modifiers held
    int m_keypressRetryCount = 0;            // Current retry attempt count
    
    std::vector<PendingAction> m_pendingActions;
};

#pragma region // * Action Implementations
// * --------------------------------------------------------------------------- Action Implementations ---------------------------------------------------------------------------

// Global Action Dispatcher instance
ActionDispatcher g_ActionDispatcher;

// Reworked SwitchToAudibleWindow: hunt for an existing window for the AUMID, focus/restore it; fallback to ShellExecute
void SwitchToAudibleWindow(const std::wstring& fallbackCmd = L"", bool bypassSingleInstanceCheck = false, float delaySeconds = 0.0f) {
    bool hasMedia;
    std::wstring targetId;
    {
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
    
    // No media playing OR ghost session (empty ID) - use fallback command if provided
    if (!hasMedia || targetId.empty()) {
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
         }, delaySeconds, L"[SwitchToAudibleWindow] Delayed SwitchToAudibleWindow");
         return;
    }

    if (targetId.empty()) {
         Wh_Log(L"[SwitchToAudibleWindow] ERROR: Media active but TargetID is empty. Cannot switch.");
         return;
    }

    // Phase 1: Try to find the existing window
    auto mw = ResolveMediaSourceWindow(targetId);

    if (mw.hwnd) {
        // Window found! Restore and Focus.
        if (IsIconic(mw.hwnd)) {
            ShowWindow(mw.hwnd, SW_RESTORE);
        }
        SetForegroundWindow(mw.hwnd);
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


void SendWinTabKeypress() {
    Wh_Log(L"[Action] Sending Win+Tab");
    g_ActionDispatcher.SendKeypress({VK_LWIN, VK_TAB});
}

void OpenStartMenu() {
    Wh_Log(L"[Action] Sending Win keypress for Start menu");
    g_ActionDispatcher.SendKeypress({VK_LWIN});
}

// Taskbar Auto-Hide
bool GetTaskbarAutohideState() {
    HWND hTaskbar = g_WindowManager.GetTaskbar();
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
    HWND hTaskbar = g_WindowManager.GetTaskbar();
    if (hTaskbar != NULL) {
        APPBARDATA msgData{};
        msgData.cbSize = sizeof(msgData);
        msgData.hWnd = hTaskbar;
        msgData.lParam = enabled ? ABS_AUTOHIDE : ABS_ALWAYSONTOP;
        SHAppBarMessage(ABM_SETSTATE, &msgData);
    }
}

void ToggleTaskbarAutohide() {
    HWND hTaskbar = g_WindowManager.GetTaskbar();
    if (hTaskbar != NULL) {
        const bool isEnabled = GetTaskbarAutohideState();
        Wh_Log(L"[Action] Setting taskbar autohide to %s", isEnabled ? L"disabled" : L"enabled");
        SetTaskbarAutohide(!isEnabled);
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    } else {
        Wh_Log(L"[Action] ERROR: Failed to toggle taskbar autohide - Taskbar not found");
    }
}

// Show Desktop (Simulates Win+D by sending the command to the taskbar)
void ToggleShowDesktop() {
    HWND hTaskbar = g_WindowManager.GetTaskbar();
    if (hTaskbar) {
        Wh_Log(L"[Action] Sending ShowDesktop message");
        SendMessage(hTaskbar, WM_COMMAND, MAKELONG(407, 0), 0);
    } else {
        Wh_Log(L"[Action] ERROR: Failed to show desktop - Taskbar not found");
    }
}

// Grabs the SHELLDLL_DefView window which is the parent of desktop icons - Used for toggling desktop icons visibility.
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
        Wh_Log(L"[Action] ERROR: Failed to find desktop window");
    }
}

// --- Registry Helpers (now using RegistryManager) --- DEAD CODE
DWORD GetExplorerAdvancedSetting(const wchar_t* valueName, DWORD defaultValue = 0) {
    Wh_Log(L" | DIRECT | TESTING - Running: `GetExplorerAdvancedSetting(%s, %d)`", valueName, defaultValue);
    return g_RegistryManager.GetExplorerAdvanced(valueName, defaultValue);
}

bool SetExplorerAdvancedSetting(const wchar_t* valueName, DWORD value) {
    return g_RegistryManager.SetExplorerAdvanced(valueName, value);
}

// Centralized taskbar handle acquisition (Consolidated into WindowManager)
HWND WindowManager::GetTaskbar() {
    // Return cached if valid
    if (g_Ctx.Wnd.taskbar && IsWindow(g_Ctx.Wnd.taskbar)) {
        return g_Ctx.Wnd.taskbar;
    }
    
    // Cache invalid or lost - find new one
    g_Ctx.Wnd.taskbar = FindWindowW(L"Shell_TrayWnd", NULL);
    if (g_Ctx.Wnd.taskbar) {
        Wh_Log(L"[WindowManager] Taskbar handle acquired: 0x%p", g_Ctx.Wnd.taskbar);
        return g_Ctx.Wnd.taskbar;
    } else {
        Wh_Log(L"[WindowManager] ERROR: Failed to find taskbar window, Possibly finding a new one on next attempt. Error: %d", GetLastError());
        return NULL;
    }
}

// Taskbar Alignment (Windows 11)
void ToggleTaskbarAlignment() {
    Wh_Log(L"TESTING - CALLING `GetExplorerAdvancedSetting(LTaskbarAl, 1)`");
    DWORD current = g_RegistryManager.GetExplorerAdvanced(L"TaskbarAl", 1);
    DWORD newAlign = (current == 0) ? 1 : 0;    // Compare current state and toggle | Default to centered (1) if not set
    if (SetExplorerAdvancedSetting(L"TaskbarAl", newAlign)) {
        Wh_Log(L"[Action] Toggling taskbar alignment from %d to %d", current, newAlign);
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
        Wh_Log(L"[CombineTaskbarButtons] ERROR: Expects 2 or 4 COMBINE_* states; got %u", (unsigned)argsSplit.size());
    }

    auto parseState = [](const std::wstring& arg) -> TaskBarButtonsState {
        if (arg == L"COMBINE_ALWAYS") return COMBINE_ALWAYS;
        if (arg == L"COMBINE_WHEN_FULL") return COMBINE_WHEN_FULL;
        if (arg == L"COMBINE_NEVER") return COMBINE_NEVER;
        Wh_Log(L"[CombineTaskbarButtons] ERROR: Unknown taskbar combine state '%s'", arg.c_str());
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
    Wh_Log(L"[CombineTaskbarButtons] TESTING - CALLING `GetExplorerAdvancedSetting(TaskbarGlomLevel) == (DWORD)primary1)`");
        static bool zigzagPrimary = (g_RegistryManager.GetExplorerAdvanced(L"TaskbarGlomLevel") == (DWORD)primary1);
        zigzagPrimary = !zigzagPrimary;
        notify |= g_RegistryManager.SetExplorerAdvanced(L"TaskbarGlomLevel", zigzagPrimary ? (unsigned)primary1 : (unsigned)primary2);
    }
    if ((secondary1 != COMBINE_INVALID) && (secondary2 != COMBINE_INVALID)) {
    Wh_Log(L"[CombineTaskbarButtons] TESTING - CALLING `GetExplorerAdvancedSetting(MMTaskbarGlomLevel) == (DWORD)secondary1)`");
        static bool zigzagSecondary = (g_RegistryManager.GetExplorerAdvanced(L"MMTaskbarGlomLevel") == (DWORD)secondary1);
        zigzagSecondary = !zigzagSecondary;
        notify |= g_RegistryManager.SetExplorerAdvanced(L"MMTaskbarGlomLevel", zigzagSecondary ? (unsigned)secondary1 : (unsigned)secondary2);
    }

    if (notify) {
        SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("TraySettings"), SMTO_ABORTIFHUNG, 100, NULL);
    }
}

void CombineTaskbarButtons(const std::wstring& args) {
    const auto [primary1, primary2, secondary1, secondary2] = ParseTaskbarButtonsState(args);
    CombineTaskbarButtonsInternal(primary1, primary2, secondary1, secondary2);
}

void Action_PaletteSave(const std::wstring& args) {
    static const int kMaxUserPalettes = 15;
    auto& saved = g_Ctx.PaletteEngine.savedPalettes;

    if (g_Ctx.ArtCache.palette.empty()) {
        Wh_Log(L"[Palette] Nothing to save — no active artwork palette");
        TriggerErrorFlash();
        return;
    }

    // Duplicate guard: reject if current palette is byte-exact match of any saved slot
    for (int i = 0; i < (int)saved.size(); i++) {
        const auto& s = saved[i];
        if (s.size() == g_Ctx.ArtCache.palette.size()) {
            bool match = true;
            for (size_t j = 0; j < s.size() && match; j++)
                match = (s[j].GetR() == g_Ctx.ArtCache.palette[j].GetR() &&
                         s[j].GetG() == g_Ctx.ArtCache.palette[j].GetG() &&
                         s[j].GetB() == g_Ctx.ArtCache.palette[j].GetB());
            if (match) {
                Wh_Log(L"[Palette] Duplicate detected — already saved in slot %d, ignoring", i + 1);
                TriggerErrorFlash();
                return;
            }
        }
    }

    // Parse overwrite mode. Default (empty/invalid) = 0.
    // 0 = overwrite slot 1 (first/oldest) directly
    // 1 = shift all down by 1 (drop last), new palette lands in slot 1
    // 2 = warn only, do not save
    int overwriteMode = 0;
    if (!args.empty()) {
        try { overwriteMode = Clamp(std::stoi(args), 0, 2); } catch(...) {}
    }

    if ((int)saved.size() >= kMaxUserPalettes) {
        if (overwriteMode == 2) {
            Wh_Log(L"[Palette] Full (%d/%d) — overwrite suppressed (mode 2), doing nothing", kMaxUserPalettes, kMaxUserPalettes);
            TriggerErrorFlash();
            return;
        }
        if (overwriteMode == 1) {
            // Shift all entries right: last slot wraps to front, then overwrite front with new palette
            Wh_Log(L"[Palette] Full (%d/%d) — shifting all down, dropping last (mode 1)", kMaxUserPalettes, kMaxUserPalettes);
            TriggerErrorFlash();
            std::rotate(saved.begin(), saved.end() - 1, saved.end());
            saved[0] = g_Ctx.ArtCache.palette;
            for (int i = 0; i < (int)saved.size(); i++)
                PaletteStorage::SavePaletteToRegistry(i, saved[i]);
        } else {
            // mode 0: overwrite index 0 directly
            Wh_Log(L"[Palette] Full (%d/%d) — overwriting slot 1 (mode 0)", kMaxUserPalettes, kMaxUserPalettes);
            TriggerErrorFlash();
            saved[0] = g_Ctx.ArtCache.palette;
            PaletteStorage::SavePaletteToRegistry(0, saved[0]);
        }
        g_Ctx.PaletteEngine.activeMode = 1;
        return;
    }

    // Normal path: append
    saved.push_back(g_Ctx.ArtCache.palette);
    int newCount = (int)saved.size();
    Wh_SetIntValue(L"SavedPaletteCount", newCount);
    PaletteStorage::SavePaletteToRegistry(newCount - 1, g_Ctx.ArtCache.palette);
    g_Ctx.PaletteEngine.activeMode = newCount;  // 1-based: slot 1 = savedPalettes[0]
    Wh_Log(L"[Palette] Saved to slot %d / %d", newCount, kMaxUserPalettes);
}

void TriggerPaletteCrossfade(int targetMode) {
    if (!g_Ctx.Wnd.main || !IsWindow(g_Ctx.Wnd.main)) return;
    if (g_Settings.enableRainbow && g_Settings.colorTheme != ColorTheme::Artwork) {
        Wh_Log(L"[Palette] WARNING: Color theme not Artwork or Rainbow FX disabled - ignoring");
        return;
    }
    if (targetMode == g_Ctx.PaletteEngine.activeMode) {
        Wh_Log(L"[Palette] WARNING: Target mode %d is already active, ignoring crossfade trigger", targetMode);
        return;
    }
    // Snapshot current colors for smooth cross-fade
    std::vector<Gdiplus::Color> currentColors;
    if (g_Ctx.PaletteEngine.activeMode == -1 || g_Ctx.PaletteEngine.savedPalettes.empty()) {    // If no saved palettes or currently in art mode, snapshot from current palette (could be mid-transition)
        currentColors = g_Ctx.ArtCache.palette;
    } else if (g_Ctx.PaletteEngine.activeMode > 0) {  // 0=rainbow: no palette to snapshot
        int safeIdx = Clamp(g_Ctx.PaletteEngine.activeMode - 1, 0, (int)g_Ctx.PaletteEngine.savedPalettes.size() - 1);
        currentColors = g_Ctx.PaletteEngine.savedPalettes[safeIdx];
    }
    SnapshotPalette(g_Ctx.ArtCache.previousPalette, currentColors);
    g_Ctx.PaletteEngine.activeMode = targetMode;
    if (targetMode == -1) { // ^ ONLY reset dirty flag when switching back to art mode, to allow smooth crossfade out of rainbow/user palette modes without abrupt resets
        g_Ctx.ArtCache.transitionProgress = 0.0f;
        g_Ctx.ArtCache.dirty = true;
    }
    // The Master Tick will instantly pick this up!
    Wh_Log(L"[Palette] Crossfade to mode %d", targetMode);
}

// .. Cycle order: -1 (art) → 0 (rainbow) → 1..total (user saved) → wrap back to -1
void Action_PaletteCycleNext() {
    int total = (int)g_Ctx.PaletteEngine.savedPalettes.size();
    int next = g_Ctx.PaletteEngine.activeMode + 1;
    if (next > total) next = -1;
    TriggerPaletteCrossfade(next);
}

void Action_PaletteCyclePrev() {
    int total = (int)g_Ctx.PaletteEngine.savedPalettes.size();
    int prev = g_Ctx.PaletteEngine.activeMode - 1;
    if (prev < -1) prev = total;
    TriggerPaletteCrossfade(prev);
}

#pragma endregion  // ^ Action Implementations

// Must only be called from MediaThread — uses IMMDeviceEnumerator owned by that apartment.
// Applies delta or mute toggle to ALL audio sessions belonging to targetPid (e.g. multi-tab Chrome).
bool AdjustAppVolume(DWORD targetPid, float delta, bool isMute) {
    if (!g_audioCOM.IsInitialized() || !targetPid) {
        Wh_Log(L"[Volume] [AdjustAppVolume] WARNING: Not ready (init=%d pid=%u)", g_audioCOM.IsInitialized(), targetPid);
        return false;
    }
    com_ptr<IMMDevice> pDevice;
    if (FAILED(g_audioCOM.GetDeviceEnumerator()->GetDefaultAudioEndpoint(eRender, eConsole, pDevice.put()))) {
        Wh_Log(L"[Volume] [AdjustAppVolume] ERROR: Failed to get audio endpoint");
        return false;
    }
    com_ptr<IAudioSessionManager2> pSessionManager;
    if (FAILED(pDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_INPROC_SERVER, nullptr, pSessionManager.put_void()))) {
        Wh_Log(L"[Volume] [AdjustAppVolume] ERROR: Failed to activate SessionManager2");
        return false;
    }
    com_ptr<IAudioSessionEnumerator> pEnumerator;
    if (FAILED(pSessionManager->GetSessionEnumerator(pEnumerator.put()))) {
        Wh_Log(L"[Volume] [AdjustAppVolume] ERROR: Failed to get session enumerator");
        return false;
    }
    int sessionCount = 0;
    pEnumerator->GetCount(&sessionCount);
    bool found = false;
    for (int i = 0; i < sessionCount; i++) {
        com_ptr<IAudioSessionControl> pControl;
        if (FAILED(pEnumerator->GetSession(i, pControl.put()))) continue;
        com_ptr<IAudioSessionControl2> pControl2;
        if (FAILED(pControl->QueryInterface(pControl2.put()))) continue;
        DWORD pid = 0;
        pControl2->GetProcessId(&pid);
        if (pid != targetPid) continue;
        com_ptr<ISimpleAudioVolume> pVolume;
        if (FAILED(pControl->QueryInterface(pVolume.put()))) continue;
        if (isMute) {
            BOOL muted = FALSE;
            pVolume->GetMute(&muted);
            pVolume->SetMute(!muted, nullptr);
        } else {
            float current = 0.0f;
            pVolume->GetMasterVolume(&current);
            pVolume->SetMasterVolume(std::clamp(current + delta, 0.0f, 1.0f), nullptr);
        }
        found = true;
        // No break — apply to ALL sessions for this PID (multi-tab browsers etc.)
    }
    Wh_Log(L"[Volume] AdjustAppVolume: PID %u %s (%s)", targetPid, found ? L"adjusted" : L"no session found", isMute ? L"mute" : (delta > 0 ? L"up" : L"down"));
    return found;
}

void DoVolumeUp() {
    if (g_Ctx.Audio.appVolumeMode) {
        auto mw = ResolveMediaSourceWindow();
        if (mw.pid && AdjustAppVolume(mw.pid, +0.05f, false)) return;
        Wh_Log(L"[Volume] INFO: App-specific Volume Up failed, falling back to system");
    }
    g_ActionDispatcher.SendKeypress({VK_VOLUME_UP});
    Wh_Log(L"[Volume] System-Wide Volume Up");
}

void DoVolumeDown() {
    if (g_Ctx.Audio.appVolumeMode) {
        auto mw = ResolveMediaSourceWindow();
        if (mw.pid && AdjustAppVolume(mw.pid, -0.05f, false)) return;
        Wh_Log(L"[Volume] INFO: App-specific Volume Down failed, falling back to System-Wide");
    }
    g_ActionDispatcher.SendKeypress({VK_VOLUME_DOWN});
    Wh_Log(L"[Volume] System-Wide Volume Down");
}

// Called from the Mute Action | Responsible for toggling mute state for target app sessions, or system-wide if app-specific fails or is disabled.
void DoMute() {
    if (g_Ctx.Audio.appVolumeMode) {
        auto mw = ResolveMediaSourceWindow();   // Determine the media source window |
        if (mw.pid && AdjustAppVolume(mw.pid, 0.0f, true)) return;
        Wh_Log(L"[Volume] INFO: App-specific Mute failed, falling back to System-Wide");
    }
    g_ActionDispatcher.SendKeypress({VK_VOLUME_MUTE});
    Wh_Log(L"[Volume] System-Wide Mute Toggle");
}

#pragma region // ^ ------ Action-Dispatch-Factory ------

// --- Action Parsing and Factory ---
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

std::function<void()> ParseAction(const std::wstring& actionName, const std::wstring& rawArgs) {
    // SPECIAL HANDLING for SwitchToAudibleWindow:
    if (actionName == L"ACTION_SWITCH_TO_AUDIBLE_WINDOW") {
         ParsedArgs parsed = ParseArgumentsWithDelay(rawArgs);
         return [parsed]() { 
            SwitchToAudibleWindow(parsed.actualArgs, parsed.bypassSingleInstance, parsed.delaySeconds); 
         };
    }

// SPECIAL HANDLING for Opacity: "10:100" means increment:knee
    if (actionName == L"ACTION_OPACITY_INCREASE" || actionName == L"ACTION_OPACITY_DECREASE") {
        int increment = 10; // Default scroll increment
        int knee = 100;     // Default knee point for element opacity curve (0-255, where lower = more aggressive dimming of elements as BG gets darker)
        
        size_t colon = rawArgs.find(L':');
        if (colon != std::wstring::npos) {
            try {
                increment = std::stoi(rawArgs.substr(0, colon));
                knee = std::stoi(rawArgs.substr(colon + 1));
            } catch(...) {}
        }

        bool isIncrease = (actionName == L"ACTION_OPACITY_INCREASE");

        return [increment, knee, isIncrease]() {
            int currentBg = g_Ctx.Vis.currentOpacity;
            
            // Gear 1 (≤30): hard snap to 1 for precision.
            // Knee zone: smooth ease — closer to knee → increment fades toward 1.
            int activeIncrement = increment;
            if (currentBg <= 30 && !isIncrease) {
                activeIncrement = 1;
            } else if (currentBg < 30 && isIncrease) {
                activeIncrement = 1;
            } else {
                // Ease window: increment-widths on each side of knee
                int kneeBand = increment * 3;
                int distToKnee = abs(currentBg - knee);
                if (distToKnee < kneeBand) {
                    // t=0 at knee (increment→1), t=1 at band edge (increment→full)
                    float t = (float)distToKnee / (float)kneeBand;
                    activeIncrement = std::max(1, (int)(1.0f + (increment - 1) * t));
                }
            }

            int nextBg = isIncrease ? (currentBg + activeIncrement) : (currentBg - activeIncrement);
            
            // Snap cleanly to 30 when crossing the boundary going up
            if (isIncrease && currentBg < 30 && nextBg > 30) {
                nextBg = 30;
            }

            nextBg = Clamp(nextBg, 1, 255);

            g_Ctx.Vis.currentOpacity = nextBg;
            g_Settings.currentOpacity = nextBg;

            // Calculate the curved Elements Opacity
            int elementOp = CalculateElementOpacity(nextBg, knee);

            // Set physical limit to elements so they stay solid
            SetWindowOpacity(g_Ctx.Wnd.main, static_cast<BYTE>(elementOp));

            // Force updates to Acrylic tint and Rainbow to reflect the new BG state
            g_WindowManager.UpdateAppearance(g_Ctx.Wnd.main);
            if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
                InvalidateRect(g_Ctx.Wnd.rainbow, NULL, FALSE);
            }
            InvalidateRect(g_Ctx.Wnd.main, NULL, FALSE);

            Wh_Log(L"[Opacity] BG: %d (Step: %d) | Elements: %d (Knee: %d)", 
                   nextBg, activeIncrement, elementOp, knee);
                   
            SaveWindowState(kInvalidCoordinate, kInvalidCoordinate, 0, 0, true);
        };
    }

    ParsedArgs parsed = ParseArgumentsWithDelay(rawArgs);
    const std::wstring& args = parsed.actualArgs;
    const float delay = parsed.delaySeconds;
    using ActionFactory = std::function<std::function<void()>(const ParsedArgs&)>;
    auto Simple = [](auto f) -> ActionFactory { return [f](const ParsedArgs&) { return f; }; };     // | For simple actions with no arguments, we ignore the input and return the function directly.
    auto ArgAction = [](auto f) -> ActionFactory { return [f](const ParsedArgs& a) { return [f, s=a.actualArgs](){ f(s); }; }; };   // | For actions that require arguments, we pass the raw argument string to the factory, which can parse it as needed.
    
    // NOTE: For actions that require arguments, the factory will receive the raw argument string and is responsible for parsing it.
    // This allows for maximum flexibility in argument formats (e.g. delimiters, multiple parameters, etc.) without complicating the central dispatch logic.
    static const std::unordered_map<std::wstring_view, ActionFactory> kActionFactories = {
        {L"ACTION_SHOW_DESKTOP", Simple(ToggleShowDesktop)},
        {L"ACTION_TOGGLE_DESKTOP_ICONS", Simple(ToggleDesktopIcons)},
        {L"ACTION_TOGGLE_TASKBAR_AUTOHIDE", Simple(ToggleTaskbarAutohide)},
        {L"ACTION_TOGGLE_TASKBAR_ALIGNMENT", Simple(ToggleTaskbarAlignment)},
        {L"ACTION_WIN_TAB", Simple(SendWinTabKeypress)},
        {L"ACTION_OPEN_START_MENU", Simple(OpenStartMenu)},
        {L"ACTION_COMBINE_TASKBAR_BUTTONS", ArgAction(CombineTaskbarButtons)},
        {L"ACTION_MUTE", Simple(DoMute)},
        {L"ACTION_TASK_MANAGER", Simple([]() { ShellExecute(0, L"open", L"taskmgr.exe", 0, 0, SW_SHOW); })},
        {L"ACTION_VOLUME_UP", Simple(DoVolumeUp)},
        {L"ACTION_VOLUME_DOWN", Simple(DoVolumeDown)},
        {L"ACTION_TOGGLE_VOLUME_TARGET", Simple([]() {
            g_Ctx.Audio.appVolumeMode = !g_Ctx.Audio.appVolumeMode;
            Wh_Log(L"[Volume] Target: %s", g_Ctx.Audio.appVolumeMode ? L"App-Specific" : L"System-Wide");
        })},
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
        {L"ACTION_FORCE_DOCKED", Simple([]() {
            Wh_Log(L"[Test] ToggleDockedMode triggered via action");
            g_WindowManager.ToggleDockedMode();
        })},
        {L"ACTION_PALETTE_SAVE",       ArgAction(Action_PaletteSave)},
        {L"ACTION_PALETTE_CYCLE_NEXT", Simple(Action_PaletteCycleNext)},
        {L"ACTION_PALETTE_CYCLE_PREV", Simple(Action_PaletteCyclePrev)},
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

#pragma endregion  // ^ ------ Action-Dispatch-Factory ------

#pragma endregion  // ^ Action Engine

// ! ================================================================================================================================================================================

#pragma region // ^ Game-Detection

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
            // Game detection removed - no ignored apps check\n            return false;", "oldString": "            // Game detection removed - no ignored apps check\n            bool match = false;"}
        }
        CloseHandle(hP);
    }
    return (s_lPid = pid, s_lRes = match);
}

// ^ Returns the monitor rectangle for a given window or fallback rect. Handles multi-monitor safely.
RECT GetMonitorRect(HWND hwnd, const RECT* fallbackRect = nullptr) {
    HMONITOR hMon = nullptr;
    
    if (hwnd && IsWindow(hwnd)) {
        hMon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY);
    } else if (fallbackRect) {
        hMon = MonitorFromRect(fallbackRect, MONITOR_DEFAULTTOPRIMARY);
    } else {
        POINT pt = {0, 0};
        hMon = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    }

    MONITORINFO mi = { sizeof(mi) };
    if (GetMonitorInfo(hMon, &mi)) {
        return mi.rcMonitor;
    }
    
    // * Fallback to primary monitor metrics
    return {0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)};
}

// ^ Determines which screen edge a window is closest to (for smart edge animations)
// ! Uses "Vertical Bias Priority": Bottom -> Top -> Right -> Left
ScreenEdge DetermineAnimationEdge(HWND hwnd, int x, int y, int w, int h) {
    // Build target rectangle and get monitor bounds
    RECT targetRect{ x, y, x + w, y + h };
    RECT mon = GetMonitorRect(hwnd, &targetRect);
    
    // Calculate center of the window
    int centerX = x + (w / 2);
    int centerY = y + (h / 2);
    
    // Distance to each edge
    int dTop    = abs(centerY - mon.top);
    int dBottom = abs(mon.bottom - centerY);
    int dLeft   = abs(centerX - mon.left);
    int dRight  = abs(mon.right - centerX);
    int minDist = min({dTop, dBottom, dLeft, dRight});
    
    // ^ Vertical Bias Priority: Bottom -> Top -> Right -> Left
    // ! This prioritizes vertical movement (taskbars are usually top/bottom)
    if (minDist == dBottom) return ScreenEdge::BOTTOM;
    if (minDist == dTop)    return ScreenEdge::TOP;
    if (minDist == dRight)  return ScreenEdge::RIGHT;
    return ScreenEdge::LEFT;
}


// Game detection removed - going nuclear


#pragma endregion  // ^ Game-Detection

// ! ====================================================================================================================================================================================================

#pragma region // ^ Window Management

void UpdateScaleFactor() {
    UINT dpi = GetDpiForSystem();
    if (dpi == 0) dpi = 96;
    g_Ctx.Sys.scaleFactor = dpi / 96.0f;
    g_Ctx.Sys.lastSysDPI = dpi; // keep cache in sync for WM_SETTINGCHANGE
}

HWND GetMediaZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget && g_Ctx.Wnd.rainbow) ? g_Ctx.Wnd.rainbow : HWND_TOPMOST; }
HWND GetRainbowZOrderInsertAfter() { return (g_Settings.rainbowAboveWidget || !g_Ctx.Wnd.main) ? HWND_TOPMOST : g_Ctx.Wnd.main; }

// Edge position helper: computes x/y for a window placed at a screen edge.
// peek=0 → fully offscreen, peek=DOCK_PEEK_PIXELS → peek mode
static void EdgePosition(ScreenEdge edge, const RECT& mon, int w, int h, int peek, int baseX, int baseY, int& outX, int& outY) {
    outX = baseX; outY = baseY;
    switch (edge) {
        case ScreenEdge::TOP:    outY = mon.top    - h + peek; break;
        case ScreenEdge::BOTTOM: outY = mon.bottom     - peek; break;
        case ScreenEdge::LEFT:   outX = mon.left   - w + peek; break;
        case ScreenEdge::RIGHT:  outX = mon.right       - peek; break;
    }
}

// Rainbow position helper: positions rainbow window relative to main widget coords
void WindowManager::ApplyRainbowPos(int x, int y, int w, int h) {
    if (!g_Ctx.Wnd.rainbow || !g_Settings.enableRainbow) return;
    int borderOffset = Scale(g_Settings.rainbowBorderOffset);
    SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(),
                 x - borderOffset, y - borderOffset,
                 w + (borderOffset * 2), h + (borderOffset * 2),
                 SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

// Toggles between docked (peek/offscreen) and normal state, owning all slide and instant transitions.
// offScreen: true=fully hidden, false=peek or restore to normal
// targetX/Y/W/H: destination coords for show transitions (passed from SyncPositionWithTaskbar); kInvalidCoordinate = use saved normalX/Y
void WindowManager::ToggleDockedMode(bool offScreen, int targetX, int targetY, int targetW, int targetH) {
    if (!g_Ctx.Wnd.main) return;
    
    int scaledW = (targetW > 0) ? targetW : EffectiveW();
    int scaledH = (targetH > 0) ? targetH : EffectiveH();
    
    if (g_Ctx.Vis.dockedMode == 0) {
        // NORMAL → DOCKED (peek or off-screen)
        RECT rcMe;
        GetWindowRect(g_Ctx.Wnd.main, &rcMe);
        g_Ctx.Vis.normalX = rcMe.left;
        g_Ctx.Vis.normalY = rcMe.top;
        g_Ctx.Vis.dockedMode = offScreen ? 2 : 1;  // 1=peek, 2=off-screen
        
        ScreenEdge edge = DetermineAnimationEdge(g_Ctx.Wnd.main, rcMe.left, rcMe.top, scaledW, scaledH);
        RECT mon = GetMonitorRect(g_Ctx.Wnd.main);
        g_Ctx.Vis.animEdge = edge;
        
        if (g_Settings.enableSlide) {
            // Start slide-HIDE: animate from current position toward screen edge
            g_Ctx.Vis.currentAnimX = rcMe.left;
            g_Ctx.Vis.currentAnimY = rcMe.top;
            g_Ctx.Vis.animState = 1;    // 1=Hiding
            // Master Tick handles animation
            if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                RECT rcRainbow; GetWindowRect(g_Ctx.Wnd.rainbow, &rcRainbow);
                g_Ctx.Rainbow.currentAnimY = rcRainbow.top;
                g_Ctx.Rainbow.animState = 1;
            }
        } else {
            int peek = offScreen ? 0 : DOCK_PEEK_PIXELS;
            int dockX, dockY;
            EdgePosition(edge, mon, scaledW, scaledH, peek, rcMe.left, rcMe.top, dockX, dockY);
            if (offScreen) {
                Wh_Log(L"[Dock] -> OFF-SCREEN at (%d,%d)", dockX, dockY);
                ShowWindow(g_Ctx.Wnd.main, SW_HIDE);
                if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
            } else {
                Wh_Log(L"[Dock] -> PEEK at (%d,%d)", dockX, dockY);
            }
            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), dockX, dockY, scaledW, scaledH,
                         SWP_NOACTIVATE | SWP_SHOWWINDOW);
            ApplyRainbowPos(dockX, dockY, scaledW, scaledH);
        }
    }
    else {
        // DOCKED → NORMAL
        int restoreX = (targetX != kInvalidCoordinate) ? targetX : g_Ctx.Vis.normalX;
        int restoreY = (targetY != kInvalidCoordinate) ? targetY : g_Ctx.Vis.normalY;
        Wh_Log(L"[Dock] <- RESTORING to (%d,%d)", restoreX, restoreY);
        g_Ctx.Vis.dockedMode = 0;
        
        if (g_Settings.enableSlide) {
            if (targetX != kInvalidCoordinate && (!IsWindowVisible(g_Ctx.Wnd.main) || g_Ctx.Vis.animState == 3)) {
                // Window was hidden - place at off-screen start before animating in
                RECT targetRect{ restoreX, restoreY, restoreX + scaledW, restoreY + scaledH };
                RECT mon = GetMonitorRect(g_Ctx.Wnd.main, &targetRect);
                ScreenEdge edge = DetermineAnimationEdge(g_Ctx.Wnd.main, restoreX, restoreY, scaledW, scaledH);
                EdgePosition(edge, mon, scaledW, scaledH, 0, restoreX, restoreY, g_Ctx.Vis.currentAnimX, g_Ctx.Vis.currentAnimY);
                g_Ctx.Vis.animEdge = edge;
                Wh_Log(L"[Anim] SHOW start: from offscreen (%d,%d) -> target (%d,%d) edge=%s",
                       g_Ctx.Vis.currentAnimX, g_Ctx.Vis.currentAnimY, restoreX, restoreY,
                       edge == ScreenEdge::TOP ? L"TOP" : edge == ScreenEdge::BOTTOM ? L"BOTTOM" :
                       edge == ScreenEdge::LEFT ? L"LEFT" : L"RIGHT");
                SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(),
                             g_Ctx.Vis.currentAnimX, g_Ctx.Vis.currentAnimY, scaledW, scaledH,
                             SWP_NOACTIVATE | SWP_SHOWWINDOW);
                ApplyRainbowPos(g_Ctx.Vis.currentAnimX, g_Ctx.Vis.currentAnimY, scaledW, scaledH);
                g_Ctx.Rainbow.animState = 2;
            } else {
                // Window visible at peek/dock - animate from current position toward normalX/Y
                RECT rcMe; GetWindowRect(g_Ctx.Wnd.main, &rcMe);
                g_Ctx.Vis.currentAnimX = rcMe.left;
                g_Ctx.Vis.currentAnimY = rcMe.top;
            }
            g_Ctx.Vis.animState = 2;
            if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) g_Ctx.Rainbow.animState = 2;
            // Master Tick handles animation
        } else {
            ShowWindow(g_Ctx.Wnd.main, SW_SHOW);
            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), restoreX, restoreY, scaledW, scaledH,
                         SWP_NOACTIVATE | SWP_SHOWWINDOW);
            ApplyRainbowPos(restoreX, restoreY, scaledW, scaledH);
            g_Ctx.Rainbow.animState = 0;
            g_Ctx.Vis.animState = 0;
        }
    }
}

// Handles syncing the media window position with the taskbar, including visibility and animation decisions
void WindowManager::SyncPositionWithTaskbar() {
    if (!g_Ctx.Wnd.main || g_Ctx.Sys.isShutdown) return;

    // Startup / Crash Recovery
    if (!GetTaskbar()) {
        if (g_Ctx.Vis.animState != 3) ToggleDockedMode();
        return;
    }

    BOOL isTaskbarVisible = IsWindowVisible(g_Ctx.Wnd.taskbar);

    // Visibility reason tracking (log only on change)
    static int s_lastReasonCode = -1;
    int reasonCode = !isTaskbarVisible ? 1 : (g_Ctx.Vis.isHiddenByIdle ? 2 : 0);
    if (reasonCode != s_lastReasonCode) {
        static const wchar_t* reasons[] = {L"Visible", L"TaskbarHidden", L"IdleTimeout"};
        Wh_Log(L"[Sync] Visibility reason: %s", reasons[reasonCode]);
        s_lastReasonCode = reasonCode;
    }

    if (g_Ctx.Vis.animState == 1 || g_Ctx.Vis.animState == 2) return;

    // Resolve target position once for all cases below
    int scaledW = EffectiveW();
    int scaledH = EffectiveH();
    int x = EffectiveX();
    int y = EffectiveY();

                                                                        // .. CASE: HIDE
    if (!isTaskbarVisible || ShouldWindowBeHidden()) {
        if (g_Ctx.Vis.animState != 1 && g_Ctx.Vis.animState != 3)
            ToggleDockedMode(true);
        return;
    }

                                                                        // .. CASE: SHOW (from hidden/docked state)
    if (g_Ctx.Vis.animState == 3 || !IsWindowVisible(g_Ctx.Wnd.main)) {
        if (g_Ctx.Vis.dockedMode == 1) return;                    // user-docked: stay docked, don't restore
        if (g_Ctx.Vis.dockedMode == 0) g_Ctx.Vis.dockedMode = 2; // startup: arm restore path in ToggleDockedMode
        ToggleDockedMode(false, x, y, scaledW, scaledH);
        return;
    }

    // ^ Steady-state: taskbar visible, widget visible, not animating
    if (g_Ctx.Vis.animState == 0) {
        RECT rc;
        if (GetWindowRect(g_Ctx.Wnd.taskbar, &rc)) {
            if ((rc.bottom - rc.top) <= 0) return;

            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), x, y, scaledW, scaledH, SWP_NOACTIVATE | SWP_SHOWWINDOW);
            SaveWindowState(x, y, scaledW, scaledH);

            ApplyRainbowPos(x, y, scaledW, scaledH);
            if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow)
                g_Ctx.Rainbow.animState = 0;
            else if (g_Ctx.Wnd.rainbow)
                ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
        }
    }
}





// Windows Event listener for taskbar changes (position, autohide, etc.) - triggers a sync and game detection check
void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime) {
    // Only respond to taskbar changes
    if (hwnd == g_Ctx.Wnd.taskbar && idObject == OBJID_WINDOW) {
        Wh_Log( L"[WinEvent] Detected taskbar event: %s ", DecodeEventType(event));
        g_WindowManager.SyncPositionWithTaskbar();
        return;
    }
}

// --- Timer Management Helpers ---
void SetupMediaWindowTimers() {
    if (!g_Ctx.Wnd.main || !IsWindow(g_Ctx.Wnd.main)) return;
    
    // Game Detection Timer
    // Game detection removed

    // Idle/Polling Timer - only start if media state already initialized
    if (g_Settings.idleTimeout > 0) {
        if (g_Ctx.Vis.mediaStateInitialized) {
            SetTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA, 1000, NULL);
            Wh_Log(L"[Timer] Idle timeout timer set (interval: 1000ms, timeout: %ds)", g_Settings.idleTimeout);
        } else {
            Wh_Log(L"[Timer] Deferring idle timeout timer - waiting for initial GSMTC state");
        }
    } else {
        Wh_Log(L"[Timer] Idle timeout disabled, no polling timer");
    }
}

// Centralized layout settings change detection and invalidation
// Layout = position (offsets) + dimensions (width/height)
// ! DEAD CODE! - DEAD CODE! - DEAD CODE!    - Now this resides in the func: WhTool_ModSettingsChanged
void InvalidatePersistedStateIfLayoutChanged() {
    bool layoutChanged = (
        g_Ctx.Persisted.lastSettingsW != g_Settings.width ||
        g_Ctx.Persisted.lastSettingsH != g_Settings.height ||
        g_Ctx.Persisted.lastOffsetX != g_Settings.offsetX ||
        g_Ctx.Persisted.lastOffsetY != g_Settings.offsetY
    );
    
    if (layoutChanged) {
        Wh_Log(L"[STATE] Layout settings changed - using default layout calculations");
        // Clear persisted position to force recalculation with new layout settings
        g_Ctx.Persisted.lastX = kInvalidCoordinate;
        g_Ctx.Persisted.lastY = kInvalidCoordinate;
        g_Ctx.Persisted.lastW = 0;
        g_Ctx.Persisted.lastH = 0;
        // Clear snapshot values
        g_Ctx.Persisted.lastSettingsW = 0;
        g_Ctx.Persisted.lastSettingsH = 0;
        g_Ctx.Persisted.lastOffsetX = 0;
        g_Ctx.Persisted.lastOffsetY = 0;
        // Clean up registry
        Wh_DeleteValue(L"LastX");
        Wh_DeleteValue(L"LastY");
        Wh_DeleteValue(L"LastW");
        Wh_DeleteValue(L"LastH");
        Wh_DeleteValue(L"LastSettingsW");
        Wh_DeleteValue(L"LastSettingsH");
        Wh_DeleteValue(L"LastOffsetX");
        Wh_DeleteValue(L"LastOffsetY");
    }
}

#pragma endregion  // ^ Window Management

// ! ====================================================================================================================================================================================================

#pragma region // ^ Settings Handling

void LoadPersistentState() {
    g_Ctx.Persisted.lastX = Wh_GetIntValue(L"LastX", kInvalidCoordinate);
    g_Ctx.Persisted.lastY = Wh_GetIntValue(L"LastY", kInvalidCoordinate);
    g_Ctx.Persisted.lastW = Wh_GetIntValue(L"LastW", 0);
    g_Ctx.Persisted.lastH = Wh_GetIntValue(L"LastH", 0);
    g_Ctx.Persisted.lastSettingsW = Wh_GetIntValue(L"LastSettingsW", 0);
    g_Ctx.Persisted.lastSettingsH = Wh_GetIntValue(L"LastSettingsH", 0);
    g_Ctx.Persisted.lastOffsetX = Wh_GetIntValue(L"LastOffsetX", 0);
    g_Ctx.Persisted.lastOffsetY = Wh_GetIntValue(L"LastOffsetY", 0);

    g_Ctx.Persisted.lastOpacity = Wh_GetIntValue(L"LastOpacity", 255);
    if (g_Ctx.Persisted.lastOpacity <= 0) {
        Wh_Log(L"[STATE] WARNING: Detected invalid persisted opacity (%d). Resetting to default.", g_Ctx.Persisted.lastOpacity);
        g_Ctx.Persisted.lastOpacity = 255;
        Wh_SetIntValue(L"LastOpacity", 255);
    }
    g_Settings.currentOpacity = g_Ctx.Persisted.lastOpacity;
    g_Ctx.Vis.currentOpacity  = g_Ctx.Persisted.lastOpacity;

    wchar_t buffer[256] = {0};
    size_t len = Wh_GetStringValue(L"LastTitle", buffer, ARRAYSIZE(buffer));
    g_Ctx.Persisted.lastTitle = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    std::fill(std::begin(buffer), std::end(buffer), 0);
    len = Wh_GetStringValue(L"LastArtist", buffer, ARRAYSIZE(buffer));
    g_Ctx.Persisted.lastArtist = (len > 0) ? std::wstring(buffer, len) : std::wstring();

    Wh_Log(L"[STATE] Loaded persisted window state (%d,%d,%d,%d)",
           g_Ctx.Persisted.lastX, g_Ctx.Persisted.lastY,
           g_Ctx.Persisted.lastW, g_Ctx.Persisted.lastH);

    // VALIDATION: If coordinates are garbage (e.g. INT_MIN from a previous crash/shutdown), discard them.
    if (g_Ctx.Persisted.lastX <= -10000 || g_Ctx.Persisted.lastY <= -10000) {
        Wh_Log(L"[STATE] WARNING: Detected invalid persisted coordinates (%d,%d). Discarding to force position recalculation.",
               g_Ctx.Persisted.lastX, g_Ctx.Persisted.lastY);
        g_Ctx.Persisted.lastX = kInvalidCoordinate;
        g_Ctx.Persisted.lastY = kInvalidCoordinate;
        // Optionally clear W/H too if they look suspicious, but usually X/Y is the offender
    }

    // Load saved palettes into memory
    PaletteStorage::LoadPalettesFromRegistry();
}

void SaveWindowState(int x, int y, int w, int h, bool saveOpacity) {
    if (g_Ctx.Vis.animState != 0 || g_Ctx.Sys.isShutdown) return;

    // Snapshot Opacity separately
    if (saveOpacity && g_Ctx.Persisted.lastOpacity != g_Settings.currentOpacity) {
        if (g_Ctx.Vis.currentOpacity <= 0) {
            Wh_Log(L"[STATE] WARNING: Attempted to save invalid opacity (%d). Ignoring.", g_Ctx.Vis.currentOpacity);
            // skip saving opacity, do NOT return
        } else {
            Wh_Log(L"[STATE] Saving opacity...");
            Wh_SetIntValue(L"LastOpacity", g_Settings.currentOpacity);
            g_Ctx.Persisted.lastOpacity = g_Settings.currentOpacity;
            Wh_Log(L"[STATE] Saved opacity: %d", g_Settings.currentOpacity);
        }
    }

    // VALIDATION: Never save garbage coordinates to registry
    if (x == kInvalidCoordinate || y == kInvalidCoordinate) return; // opacity-only call
    if (x <= -10000 || y <= -10000) {
        Wh_Log(L"[STATE] WARNING: Attempted to save invalid coordinates (%d,%d). Ignoring.", x, y);
        return;
    }

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
        Wh_SetIntValue(L"LastSettingsW", g_Settings.width);
        Wh_SetIntValue(L"LastSettingsH", g_Settings.height);
        Wh_SetIntValue(L"LastOffsetX", g_Settings.offsetX);
        Wh_SetIntValue(L"LastOffsetY", g_Settings.offsetY);
        g_Ctx.Persisted.lastSettingsW = g_Settings.width;
        g_Ctx.Persisted.lastSettingsH = g_Settings.height;
        g_Ctx.Persisted.lastOffsetX = g_Settings.offsetX;
        g_Ctx.Persisted.lastOffsetY = g_Settings.offsetY;
        Wh_Log(L"[STATE] Saved window state (%d,%d,%dx%d) with offsets (%d,%d)",
               x, y, w, h, g_Settings.offsetX, g_Settings.offsetY);
    }
}


void SaveLastMediaInfo(const std::wstring& title, const std::wstring& artist) {
    // Only log and save if values actually changed
    if (g_Ctx.Persisted.lastTitle != title || g_Ctx.Persisted.lastArtist != artist) {
        Wh_SetStringValue(L"LastTitle", title.c_str());
        Wh_SetStringValue(L"LastArtist", artist.c_str());
        g_Ctx.Persisted.lastTitle = title;
        g_Ctx.Persisted.lastArtist = artist;
        Wh_Log(L"[STATE] Saved media info: '%s' by '%s'", 
               title.empty() ? L"<empty>" : title.c_str(),
               artist.empty() ? L"<empty>" : artist.c_str());
    }
}

void LoadSettings() {
    #define LOAD_INT(var, name) g_Settings.var = Wh_GetIntSetting(name)
    #define LOAD_STR(var, name) g_Settings.var = Wh_GetStringSetting(name)
    #define LOAD_BOOL(var, name) g_Settings.var = Wh_GetIntSetting(name) != 0
    #define LOAD_CLAMP(var, name, min, max) g_Settings.var = GetClampedSetting(name, min, max)
    // Screen size in logical pixels (pre-Scale) so clamp max matches the coordinate space Scale() expects
    float dpiScale = GetDpiForSystem() / 96.0f;
    int primarymonitorWidth (GetSystemMetrics(SM_CXSCREEN) / dpiScale);
    int primarymonitorHeight (GetSystemMetrics(SM_CYSCREEN) / dpiScale);

    LOAD_CLAMP(width, L"PanelWidth", 10, primarymonitorWidth);
    LOAD_CLAMP(height, L"PanelHeight", 10, primarymonitorHeight);
    LOAD_CLAMP(maxArtSize, L"MaxArtSize", 10, 1000);
    LOAD_CLAMP(buttonSize, L"ButtonSize", 10, 120);
    LOAD_CLAMP(textScale, L"TextScale", 5, 200);
    LOAD_INT(offsetX, L"OffsetX");
    LOAD_INT(offsetY, L"OffsetY");
    
    // .. ColorTheme (string dropdown → enum)
    auto strColorTheme = WindhawkUtils::StringSetting(Wh_GetStringSetting(L"ColorTheme"));
    if (0 == wcscmp(strColorTheme, L"system")) g_Settings.colorTheme = ColorTheme::System;
    else if (0 == wcscmp(strColorTheme, L"custom")) g_Settings.colorTheme = ColorTheme::Custom;
    else if (0 == wcscmp(strColorTheme, L"artwork")) g_Settings.colorTheme = ColorTheme::Artwork;
    else g_Settings.colorTheme = ColorTheme::System; // Fallback
    
    LOAD_BOOL(invertColors, L"InvertColors");

    // .. Colors
    auto loadColor = [](const wchar_t* name, DWORD& target, DWORD def, bool isBg) {
        auto s = WindhawkUtils::StringSetting::make(name);
        int r, g, b, a;
        if (s.get() && s.get()[0] && ParseColorComponents(s.get(), r, g, b, a)) {
            // BgColor: 0,0,0,0 is the ONLY "Do Not Override" trigger
            if (isBg && r==0 && g==0 && b==0 && a==0) target = 0;
            else if (isBg) target = ((DWORD)a << 24) | ((DWORD)b << 16) | ((DWORD)g << 8) | (DWORD)r; // BGR for DWM
            else target = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b; // RGB for text
        } else target = def;
    };
    loadColor(L"TextColor", g_Settings.interfaceColor, 0xFFFFFFFF, false);
    loadColor(L"BgColor", g_Settings.manualBgColorRGB, 0, true);

    // Game detection removed
    LOAD_CLAMP(idleTimeout, L"IdleTimeout", 0, 3600);

    LOAD_BOOL(EnableTextScroll, L"EnableTextScroll");
    LOAD_CLAMP(scaleEasing, L"ScaleEasing", -5, 50);
    LOAD_BOOL(enableSlide, L"EnableSlide");
    // Game detection removed
    
    // Game detection removed

    LOAD_BOOL(enableRainbow, L"EnableRainbow");
    
    bool newRainbowAbove = Wh_GetIntSetting(L"RainbowAboveWidget") != 0;
    
    // Only apply the rainbow z-order setting on load if we're not running yet (initial load) or if the setting changed (user update) - prevents unnecessary SetWindowPos calls on every settings reload
    if (!g_Ctx.Sys.isRunning || newRainbowAbove != g_Settings.storedRainbowAboveWidget) {
        g_Settings.rainbowAboveWidget = g_Settings.storedRainbowAboveWidget = newRainbowAbove;
    }

    LOAD_CLAMP(rainbowSpeed, L"RainbowSpeed", 1, 10);
    LOAD_CLAMP(rainbowBrightness, L"RainbowBrightness", 0, 100);
    LOAD_CLAMP(rainbowThickness, L"RainbowThickness", 1, 100);
    LOAD_CLAMP(rainbowBorderOffset, L"RainbowBorderOffset", 0, 7);
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

    // Audio Hue Reactive Mode (string dropdown → int)
    auto rawHueMode = Wh_GetStringSetting(L"kAudioHueReactiveMode");  // match your YAML key exactly
    std::wstring strHueMode = rawHueMode ? rawHueMode : L"pulse";
    if (rawHueMode) Wh_FreeStringSetting(rawHueMode);

    if      (strHueMode == L"off")              g_Settings.audioHueReactiveMode = 0;
    else if (strHueMode == L"speedboost")       g_Settings.audioHueReactiveMode = 1;
    else if (strHueMode == L"pulse")            g_Settings.audioHueReactiveMode = 2;
    else if (strHueMode == L"bounce")           g_Settings.audioHueReactiveMode = 3;
    else if (strHueMode == L"speedboost_pulse") g_Settings.audioHueReactiveMode = 4;
    else if (strHueMode == L"speedboost_bounce")g_Settings.audioHueReactiveMode = 5;
    else if (strHueMode == L"pulse_bounce")     g_Settings.audioHueReactiveMode = 6;
    else if (strHueMode == L"all")              g_Settings.audioHueReactiveMode = 7;
    else                                        g_Settings.audioHueReactiveMode = 2; // default: pulse

    LoadPersistentState();

    // ^ Invalidate persisted state if any layout settings changed
    
    bool changedDims    = (g_Ctx.Persisted.lastW > 0 && g_Ctx.Persisted.lastH > 0
                            && g_Ctx.Persisted.lastSettingsW > 0 && g_Ctx.Persisted.lastSettingsH > 0
                            && (g_Settings.width != g_Ctx.Persisted.lastSettingsW || g_Settings.height != g_Ctx.Persisted.lastSettingsH));
    bool changedOffsets = (g_Ctx.Persisted.lastX != kInvalidCoordinate && g_Ctx.Persisted.lastY != kInvalidCoordinate
                            && (g_Settings.offsetX != g_Ctx.Persisted.lastOffsetX || g_Settings.offsetY != g_Ctx.Persisted.lastOffsetY));

    if (changedDims || changedOffsets) {
        Wh_Log(L"[STATE] Layout settings changed (dims:%d offsets:%d) - clearing affected persisted state",
                changedDims, changedOffsets);
        if (changedDims) {
            g_Ctx.Persisted.lastW = 0; g_Ctx.Persisted.lastH = 0;
            Wh_DeleteValue(L"LastW");         Wh_DeleteValue(L"LastH");
            Wh_DeleteValue(L"LastSettingsW"); Wh_DeleteValue(L"LastSettingsH");
        }
        if (changedOffsets) {
            g_Ctx.Persisted.lastX = kInvalidCoordinate; g_Ctx.Persisted.lastY = kInvalidCoordinate;
            Wh_DeleteValue(L"LastX");       Wh_DeleteValue(L"LastY");
            Wh_DeleteValue(L"LastOffsetX"); Wh_DeleteValue(L"LastOffsetY");
        }
    } else {
        Wh_Log(L"[STATE] Layout settings unchanged - keeping persisted state");
    }
    

    // ApplyPersistedMediaFallback(); // REMOVED: Do not reset media state on settings load.
    // This allows the live media state to persist across settings reloads, preventing "No Media" flash.
    // Startup state is handled by ModContext::Reset() which defaults to "No Media".

    if (g_Settings.audioHueReactiveMode > 0 && g_audioCOM.IsInitialized()) g_audioCOM.InitMeter();

    g_Ctx.Reset(RESET_AUDIO);
    g_Ctx.Audio.runtimeEnabled = true;
    g_Ctx.Rainbow.directionReverse = false;
    // Don't reset idle state during settings reload - preserve current status
    // g_Ctx.Vis.idleSecondsCounter = 0;
    // g_Ctx.Vis.isHiddenByIdle = false;

    // Triggers
    g_ActionDispatcher.triggers.clear();
    for (int i = 0; i < 50; i++) {
        auto type = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].TriggerType", i).get());
        if (type.empty()) type = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].MouseTrigger", i).get());
        if (type.empty()) continue;

        ConfiguredTrigger ct;
        ct.mouseTriggerName = type;
        ct.expectedModifiers = 0;

        // Game detection removed - load keyboard modifiers for all triggers
        for (int j = 0; j < 8; j++) {
            auto m = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].KeyboardTriggers[%d]", i, j).get());
            if (!m.empty() && m != L"none") {
                KeyModifier km = GetKeyModifierFromName(m);
                if (km != KEY_MODIFIER_INVALID) SetBit(ct.expectedModifiers, km);
            }
        }

        for (int k = 0; k < 20; k++) {
            auto act = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].Actions[%d].Action", i, k).get());
            if (act.empty()) break;
            auto args = std::wstring(WindhawkUtils::StringSetting::make(L"Triggers[%d].Actions[%d].AdditionalArgs", i, k).get());
            auto parsed = ParseAction(act, args);
            if (parsed) ct.actions.push_back({act, parsed});
        }
        if (!ct.actions.empty()) g_ActionDispatcher.triggers.push_back(ct);
    }

    #undef LOAD_INT
    #undef LOAD_BOOL
    #undef LOAD_CLAMP
}

#pragma endregion  // ^ Settings Handling

#pragma region // ^ --- WinRT / GSMTC ---

GlobalSystemMediaTransportControlsSessionManager g_SessionManager = nullptr;
GlobalSystemMediaTransportControlsSession g_CachedSession = nullptr;

// Event tokens for proper unsubscription (prevents use-after-free in callbacks)
winrt::event_token g_sessionChangedToken{};
winrt::event_token g_playbackInfoToken{};
winrt::event_token g_mediaPropertiesToken{};

// Custom message for media updates (message-passing)
#define APP_WM_MEDIA_UPDATED (WM_APP + 100)

// Payload struct for media updates
struct MediaUpdatePayload {
    std::wstring title;
    std::wstring artist;
    std::wstring sourceId;
    bool isPlaying = false;
    bool hasMedia = false;
    BitmapPtr albumArt;
};

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

// | Async fire-and-forget media info update - does NOT block UI thread
void UpdateMediaInfoAsync() {
    // No debounce - Windows GSMTC handles event coalescing
    static std::atomic<int> s_NoSessionRetryCount{ 0 };


    // Early exit if no session available
    if (!g_CachedSession) {
        // Grace Period: Don't clear immediately to allow for transient session loss
        bool hadMedia = g_Ctx.Media.hasMedia;
        if (hadMedia && s_NoSessionRetryCount < 8) {
            s_NoSessionRetryCount++;
            return;
        }
        s_NoSessionRetryCount = 0;
        // Post message to clear media state
        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
            auto* payload = new MediaUpdatePayload();
            payload->hasMedia = false;
            payload->title = L"No Media";
            payload->artist = L"";
            payload->sourceId = L"";
            PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
        }
        return;
    }

    s_NoSessionRetryCount = 0;


    // Message-passing: heap-allocate payload and post to window
    auto updateState = [](wstring title, wstring artist, wstring sourceId, bool isPlaying, bool hasMedia, BitmapPtr albumArt) {
        if (!g_Ctx.Wnd.main || !IsWindow(g_Ctx.Wnd.main)) return;
        auto* payload = new MediaUpdatePayload();
        payload->title = std::move(title);
        payload->artist = std::move(artist);
        payload->sourceId = std::move(sourceId);
        payload->isPlaying = isPlaying;
        payload->hasMedia = hasMedia;
        payload->albumArt = std::move(albumArt);
        PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
    };
    
    try {
        // Get source ID and playback state synchronously (fast operations)
        wstring sourceId = g_CachedSession.SourceAppUserModelId().c_str();

        // Treat empty SourceID as invalid/ghost session
        if (sourceId.empty()) {
            if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
                auto* payload = new MediaUpdatePayload();
                payload->hasMedia = false;
                payload->title = L"No Media";
                payload->artist = L"";
                payload->sourceId = L"";
                PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
            }
            return;
        }

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
        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
            auto* payload = new MediaUpdatePayload();
            payload->hasMedia = false;
            payload->title = L"No Media";
            payload->artist = L"";
            payload->sourceId = L"";
            PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
        }
    } catch (const std::exception&) {
        Wh_Log(L"[ERROR] [WinRT] STL exception in UpdateMediaInfoAsync");
        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
            auto* payload = new MediaUpdatePayload();
            payload->hasMedia = false;
            payload->title = L"No Media";
            payload->artist = L"";
            payload->sourceId = L"";
            PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
        }
    } catch (...) {
        Wh_Log(L"[ERROR] [WinRT] Unknown exception in UpdateMediaInfoAsync");
        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
            auto* payload = new MediaUpdatePayload();
            payload->hasMedia = false;
            payload->title = L"No Media";
            payload->artist = L"";
            payload->sourceId = L"";
            PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
        }
    }
}

void SendMediaCommand(int cmd) {
    try {
        // Use cached session - no blocking GetCurrentSession() call
        if (!g_CachedSession) {
            Wh_Log(L"INFO: No cached media session for command");
            return;
        }
        
        // OPTIMIZATION: Optimistic UI update for play/pause - instant visual feedback
        if (cmd == 2) {
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

#pragma endregion // ^ --- WinRT / GSMTC ---

// --- Visuals ---
bool IsSystemLightMode() {
    DWORD value = 0; DWORD size = sizeof(value);
    if (RegGetValueW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"SystemUsesLightTheme", RRF_RT_DWORD, nullptr, &value, &size) == ERROR_SUCCESS) {
        return value != 0;
    }
    return false;
}

DWORD GetCurrentTextColor() {
    DWORD color;
    if (g_Settings.colorTheme == ColorTheme::System) {
        color = IsSystemLightMode() ? 0xFF000000 : 0xFFFFFFFF;
    } else {
        color = g_Settings.interfaceColor;
    }
    
    // Apply color inversion if enabled (flip RGB: 255-R, 255-G, 255-B)
    if (g_Settings.invertColors) {
        BYTE a = (color >> 24) & 0xFF;
        BYTE r = (color >> 16) & 0xFF;
        BYTE g = (color >> 8) & 0xFF;
        BYTE b = color & 0xFF;
        color = ((DWORD)a << 24) | ((DWORD)(255 - r) << 16) | ((DWORD)(255 - g) << 8) | (255 - b);
    }
    
    return color;
}

// | Set window opacity using layered window attributes
void SetWindowOpacity(HWND hwnd, BYTE opacity) {
    if (!hwnd || !IsWindow(hwnd)) return;
    
    // Add WS_EX_LAYERED flag if not present
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    if (!(exStyle & WS_EX_LAYERED)) {
        SetWindowLong(hwnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED);
    }
    
    // Set opacity (0 = fully transparent, 255 = fully opaque)
    SetLayeredWindowAttributes(hwnd, 0, opacity, LWA_ALPHA);
}

// | Apply DWM corner preference to window
void ApplyCornerPreference(HWND hwnd, bool enableRounded) {
    DWM_WINDOW_CORNER_PREFERENCE preference = enableRounded ? DWMWCP_ROUND : DWMWCP_DONOTROUND;
    DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(preference));
}

// | Apply acrylic blur and tint using composition attributes
// Automatically switches to simpler blur for large windows to improve performance
void ApplyAcrylicTint(HWND hwnd) {
    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (!hUser) return;
    
    auto SetComp = (pSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
    if (!SetComp) return;
    
    DWORD tint = 0;
    DWORD manual = g_Settings.manualBgColorRGB;
    
// 1. Determine Alpha
    BYTE baseAlpha = 0x14; // Default: 20
    if (manual != 0) {
        baseAlpha = (manual >> 24) & 0xFF;
    }
    
    // Scale the acrylic tint using the Background Opacity (0.0 to 1.0 ratio)
    float bgRatio = (float)g_Ctx.Vis.currentOpacity / 255.0f;
    BYTE alpha = (BYTE)(baseAlpha * bgRatio);

    // 2. Determine Color (RGB)
    DWORD rgb = 0;
    
    // ColorTheme::System takes priority over manual RGB (acts as a bypass)
    bool useManualRGB = (manual != 0) && ((manual & 0xFFFFFF) != 0) && (g_Settings.colorTheme != ColorTheme::System) && (g_Settings.colorTheme != ColorTheme::Artwork);

    if (useManualRGB) {
        rgb = manual & 0xFFFFFF;
    } else {
        // Fallback: System theme or manual 0,0,0 (Do Not Override)
        bool systemLight = IsSystemLightMode();
        rgb = systemLight ? 0xFFFFFF : 0x000000;
    }
    
    // Apply color inversion if enabled (flip RGB: 255-R, 255-G, 255-B)
    if (g_Settings.invertColors) {
        BYTE r = (rgb >> 16) & 0xFF;
        BYTE g = (rgb >> 8) & 0xFF;
        BYTE b = rgb & 0xFF;
        rgb = ((DWORD)(255 - r) << 16) | ((DWORD)(255 - g) << 8) | (255 - b);
    }

    tint = ((DWORD)alpha << 24) | rgb;
    
    // 3. Adaptive Blur: Switch to simpler blur for large windows to improve DWM performance
    // Acrylic blur (state 4) is GPU-intensive and scales poorly with window area
    // Simple blur (state 3) maintains visual effect with significantly better performance
    ACCENT_STATE blurState = ACCENT_ENABLE_ACRYLICBLURBEHIND;
    
    RECT rc;
    if (GetClientRect(hwnd, &rc)) {
        int logicalW = rc.right;
        int logicalH = rc.bottom;
        
        // Convert to logical pixels if DPI scaling is active
        if (g_Ctx.Sys.scaleFactor > 0.0f && g_Ctx.Sys.scaleFactor != 1.0f) {
            logicalW = (int)(logicalW / g_Ctx.Sys.scaleFactor);
            logicalH = (int)(logicalH / g_Ctx.Sys.scaleFactor);
        }
        
        // Threshold: 700px width triggers simple blur mode
        // This provides ~3-5x performance improvement for DWM compositor
        const int ADAPTIVE_BLUR_THRESHOLD = 700;
        if (logicalW >= ADAPTIVE_BLUR_THRESHOLD) {
            blurState = ACCENT_ENABLE_BLURBEHIND;
        }
    }
    
    ACCENT_POLICY policy = { blurState, 0, tint, 0 };
    WINDOWCOMPOSITIONATTRIBDATA data = { WCA_ACCENT_POLICY, &policy, sizeof(ACCENT_POLICY) };
    SetComp(hwnd, &data);
}

// | Update all appearance attributes for a window
void WindowManager::UpdateAppearance(HWND hwnd) {
    ApplyCornerPreference(hwnd, g_Settings.enableRoundedCorners);
    ApplyAcrylicTint(hwnd);
}

// Check if palette is mostly uniform (low variance)
bool IsPaletteUniform(const std::vector<Gdiplus::Color>& palette, float threshold = 20.0f) {
    if (palette.empty()) return true;
    float sumR = 0, sumG = 0, sumB = 0;
    for (const auto& c : palette) {
        sumR += c.GetR(); sumG += c.GetG(); sumB += c.GetB();
    }
    float meanR = sumR / palette.size(), meanG = sumG / palette.size(), meanB = sumB / palette.size();
    float varR = 0, varG = 0, varB = 0;
    for (const auto& c : palette) {
        varR += (c.GetR() - meanR) * (c.GetR() - meanR);
        varG += (c.GetG() - meanG) * (c.GetG() - meanG);
        varB += (c.GetB() - meanB) * (c.GetB() - meanB);
    }
    varR /= palette.size(); varG /= palette.size(); varB /= palette.size();
    float totalVar = (varR + varG + varB) / 3.0f;
    return totalVar < threshold;
}

// Generate palette from bitmap, optionally cropped to center area
void GeneratePaletteFromBitmap(Gdiplus::Bitmap* artClone, int physW, int physH, std::vector<Gdiplus::Color>& palette, const RECT* cropRect = nullptr) {
    UINT srcW = artClone->GetWidth();
    UINT srcH = artClone->GetHeight();
    UINT offsetX = 0, offsetY = 0;
    if (cropRect) {
        offsetX = cropRect->left;
        offsetY = cropRect->top;
        srcW = cropRect->right - cropRect->left;
        srcH = cropRect->bottom - cropRect->top;
    }

    // Match DrawRainbowBorder's segmentCount — use logical dims for segment math
    int logicalW = (g_Ctx.Sys.scaleFactor > 0.0f) ? (int)(physW / g_Ctx.Sys.scaleFactor) : physW;
    int logicalH = (g_Ctx.Sys.scaleFactor > 0.0f) ? (int)(physH / g_Ctx.Sys.scaleFactor) : physH;
    int stepSize     = std::max(2, g_Settings.rainbowSpeed / 2);
    int segmentCount = std::min(360 / stepSize, (logicalW + logicalH) * 2);

    palette.clear();
    palette.reserve(segmentCount);

    // Walk perimeter of art image: top → right → bottom (reversed) → left (reversed)
    UINT perimeter = 2 * (srcW + srcH);
    for (int s = 0; s < segmentCount; s++) {
        UINT pos = (UINT)((float)s / segmentCount * perimeter);
        UINT x, y;
        if (pos < srcW) {
            x = pos;          y = 0;          // Top edge: left → right
        } else if (pos < srcW + srcH) {
            x = srcW - 1;     y = pos - srcW; // Right edge: top → bottom
        } else if (pos < 2 * srcW + srcH) {
            x = srcW - 1 - (pos - srcW - srcH); y = srcH - 1; // Bottom edge: right → left
        } else {
            x = 0;            y = srcH - 1 - (pos - 2 * srcW - srcH); // Left edge: bottom → top
        }
        x = std::min(x + offsetX, artClone->GetWidth() - 1);
        y = std::min(y + offsetY, artClone->GetHeight() - 1);

        Gdiplus::Color px;
        artClone->GetPixel(x, y, &px);
        palette.push_back(px);
    }

    // Fallback: should never be empty, but guard anyway
    if (palette.empty()) {
        palette.emplace_back(255, 255, 255);
    }
}

// Regenerate ArtCache: reads albumArt and writes ArtCache — MediaThread only.
// Called from IDT_ART_FADE timer (never from WM_PAINT).
void RegenerateArtworkCache(int physW, int physH) {
    // --- Clone art ---
    std::unique_ptr<Gdiplus::Bitmap> artClone;
    if (!g_Ctx.Media.albumArt) {
        g_Ctx.ArtCache.dirty = false;
        return;
    }
    artClone.reset(g_Ctx.Media.albumArt->Clone(
        0, 0,
        g_Ctx.Media.albumArt->GetWidth(),
        g_Ctx.Media.albumArt->GetHeight(),
        PixelFormat32bppARGB));

    if (!artClone || artClone->GetLastStatus() != Gdiplus::Ok) {
        g_Ctx.ArtCache.dirty = false;
        return;
    }

    // --- Build background bitmap: viewport into the square art ---
    // Art is rendered at its natural aspect ratio scaled to fill the window WIDTH.
    // For square album art this means drawH >= physH, so it overflows vertically.
    // We center it vertically so only the middle slice is visible — the rest is
    // clipped naturally because the bitmap is only physW x physH.
    BitmapPtr bgBmp(new Gdiplus::Bitmap(physW, physH, PixelFormat32bppARGB));
    {
        int srcW = (int)artClone->GetWidth();
        int srcH = (int)artClone->GetHeight();

        // Scale to fill full width, maintain aspect ratio
        float scale = (srcW > 0) ? (float)physW / srcW : 1.0f;  // if srcW=0 (shouldn't happen) → skip scaling to avoid div-by-zero
        int drawW = physW;
        int drawH = (int)(srcH * scale);           // >= physH for square art in wide window
        int drawX = 0;
        int drawY = (physH - drawH) / 2;           // Center vertically; negative = clips top/bottom

        Gdiplus::Graphics gfx(bgBmp.get());
        gfx.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
        gfx.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
        gfx.Clear(Gdiplus::Color(0, 0, 0, 0));

        // No ColorMatrix — draw at full original colors
        gfx.DrawImage(artClone.get(),
            Gdiplus::Rect(drawX, drawY, drawW, drawH),
            0, 0, srcW, srcH,
            Gdiplus::UnitPixel);
    }

    // --- Extract palette: one sample per rainbow segment, walked around the art perimeter ---
    // This gives a 1:1 color correspondence: segment s → palette[s] (no nearest-search needed)
    std::vector<Gdiplus::Color> palette;
    GeneratePaletteFromBitmap(artClone.get(), physW, physH, palette);

    // Check if palette is mostly uniform; if so, resample from center area to avoid border dominance
    if (IsPaletteUniform(palette)) {
        Wh_Log(L"Info: Palette is uniform (low variance) - resampling from center area to improve color diversity");
        UINT fullW = artClone->GetWidth();
        UINT fullH = artClone->GetHeight();
        RECT crop = { (LONG)(fullW * 0.25f), (LONG)(fullH * 0.25f), (LONG)(fullW * 0.75f), (LONG)(fullH * 0.75f) };
        GeneratePaletteFromBitmap(artClone.get(), physW, physH, palette, &crop);
    }

    // Smooth the palette to eliminate per-pixel noise and JPEG artifacts.
    // This makes artwork palette borders look as seamless as rainbow.
    SmoothPalette(palette, 4);  // radius 4 → 9-sample circular kernel

    // --- Store results ---
    g_Ctx.ArtCache.bgBitmap = std::move(bgBmp);
    g_Ctx.ArtCache.palette  = std::move(palette);
    g_Ctx.ArtCache.dirty = false;
    Wh_Log(L"[ARTWORK] Cache regenerated (PhysicalPx: %dx%d, %d palette colors)", physW, physH, (int)g_Ctx.ArtCache.palette.size());
}

static void DrawBitmapWithOpacity(Graphics& gfx, Gdiplus::Bitmap* bmp, int x, int y, int w, int h, BYTE alpha);

// ..     --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------
// ^      --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------
// ~      --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------

void DrawRainbowBorder(HDC hdc, int width, int height) {    // Called from WM_PAINT, runs on UI thread, must be efficient to avoid paint lag    // .. (LIVE)
    // static UINT count = 0;
    // count++;
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias8x8);
    graphics.Clear(Color(0, 0, 0, 0));
    graphics.ScaleTransform(g_Ctx.Sys.scaleFactor, g_Ctx.Sys.scaleFactor);
    
    int logicalW = (int)(width / g_Ctx.Sys.scaleFactor);
    int logicalH = (int)(height / g_Ctx.Sys.scaleFactor);
    
    float baseHue = g_Ctx.Rainbow.hue;
    float brightness = g_Settings.rainbowBrightness / 100.0f;
    float thickness = (float)g_Settings.rainbowThickness;
    
    // Apply audio reactivity if enabled and running
    if (g_Settings.audioHueReactiveMode > 0 && g_Ctx.Audio.runtimeEnabled) {
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
            // if (count % 30 == 0) { // Log every 30 frames to avoid spamming - Roughly every second at 30 FPS        // !DEBUG
            //     Wh_Log(L" -- Audio Reactive Update -- PeakLevel: %.5f, Brightness: %.3f, Thickness: %.3f", (float)g_Ctx.Audio.peakLevel, brightness, thickness);
            // }
            // else if (count >= 1000) { // Reset count to avoid overflow
            //     count = 0;
            // }
    }
    
    // Create 4 corner gradients with offset hues
    for (int corner = 0; corner < 4; corner++) {
        float cornerHue = fmodf(baseHue + (corner * 90.0f), 360.0f);    // | This is for non-artwork themes: it creates a pure rainbow effect by offsetting each corner's hue by 90°.
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
        
        //& Only draw gradients in non-artwork mode - artwork mode uses pre-rendered background instead
        if (g_Settings.colorTheme != ColorTheme::Artwork) {
            LinearGradientBrush gradBrush(pt1, pt2, cornerColor, Color(0, r, g, b));
            graphics.FillRectangle(&gradBrush, gradRect);
        }
    }

    // Artwork mode: draw pre-rendered background with cross-fade between previous/current
    if (g_Settings.colorTheme == ColorTheme::Artwork) {
        float t = std::clamp(g_Ctx.ArtCache.transitionProgress.load(), 0.0f, 1.0f);
        Bitmap* curr = g_Ctx.ArtCache.bgBitmap.get();
        Bitmap* prev = g_Ctx.ArtCache.previousBgBitmap.get();

        BYTE alphaCurr = 255;
        if (prev || t < 1.0f) {
            alphaCurr = (BYTE)(t * 255.0f);
        }
        BYTE alphaPrev = prev ? (BYTE)((1.0f - t) * 255.0f) : 0;

        Gdiplus::Graphics rawGfx(hdc);
        rawGfx.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBilinear); // High-quality smoothing for pre-rendered bitmaps

        if (prev && alphaPrev) {
            DrawBitmapWithOpacity(rawGfx, prev, 0, 0, width, height, alphaPrev);
        }
        if (curr && alphaCurr) {
            DrawBitmapWithOpacity(rawGfx, curr, 0, 0, width, height, alphaCurr);
        }
    }
    
    // --- THE FIX: Distance-Mapped Rectangular Path ---
    // We trace a sharp rectangle so the paint completely fills the physical corners (burying the background).
    // Then Windows 11 DWM naturally chops it into its perfect native squircle.
    // Because we map colors by PERIMETER DISTANCE, the flow remains flawless and unstretched.

    float inset = thickness / 2.0f;
    float pathW = std::max(1.0f, logicalW - thickness);
    float pathH = std::max(1.0f, logicalH - thickness);

    float TotalP = (pathW + pathH) * 2.0f;

    // Maps a fractional value t in[0, 1) to a physical PointF on the rectangular perimeter
    auto GetPathPoint = [&](float t) -> PointF {
        t = fmodf(t, 1.0f);
        if (t < 0) t += 1.0f;
        float d = t * TotalP;

        // Top edge (Left to Right)
        if (d <= pathW) return PointF(inset + d, inset);
        d -= pathW;
        
        // Right edge (Top to Bottom)
        if (d <= pathH) return PointF(inset + pathW, inset + d);
        d -= pathH;
        
        // Bottom edge (Right to Left)
        if (d <= pathW) return PointF(inset + pathW - d, inset + pathH);
        d -= pathW;
        
        // Left edge (Bottom to Top)
        return PointF(inset, inset + pathH - d);
    };

    int stepSize = std::max(2, g_Settings.rainbowSpeed / 2); // Faster = fewer segments needed
    int segmentCount = std::max(360 / stepSize, (int)((logicalW + logicalH) * 2));
    segmentCount = std::min(segmentCount, 1500); // Sanity cap

    float angleStep = 360.0f / segmentCount;

    // Copy palette state into locals for consistent reads across all segments this frame
    std::vector<Gdiplus::Color> framePalette;
    std::vector<Gdiplus::Color> framePrevPalette;
    float frameTp = 0.0f;
    if (g_Settings.colorTheme == ColorTheme::Artwork) {
        // PaletteEngine: use saved palette if one is active, else live art palette
        if (g_Ctx.PaletteEngine.activeMode == -1 || g_Ctx.PaletteEngine.savedPalettes.empty()) {
            framePalette = g_Ctx.ArtCache.palette;
        } else if (g_Ctx.PaletteEngine.activeMode > 0) {  // 0=rainbow: leave framePalette empty → falls through to HSV
            int safeIdx = Clamp(g_Ctx.PaletteEngine.activeMode - 1, 0, (int)g_Ctx.PaletteEngine.savedPalettes.size() - 1);
            framePalette = g_Ctx.PaletteEngine.savedPalettes[safeIdx];
        }
        framePrevPalette = g_Ctx.ArtCache.previousPalette;
        frameTp = g_Ctx.ArtCache.transitionProgress.load();
    }

    // Computes the blended color for segment index `seg`.
    auto computeSegColor = [&](int seg) -> Gdiplus::Color {
        float ang    = seg * angleStep;
        float segHue = fmodf(baseHue + ang, 360.0f);
        BYTE r, g, b;
        HSVtoRGB(segHue, 1.0f, brightness, r, g, b);

        if (g_Settings.colorTheme == ColorTheme::Artwork && !framePalette.empty()) {
            int frameSize = (int)framePalette.size();
            float hueOffset  = baseHue / 360.0f * frameSize;
            
            // Decouple rendering segments from palette size for uniform stretching
            float mappedSeg = ((float)seg / segmentCount) * frameSize;
            float palettePos = fmodf(mappedSeg + hueOffset, (float)frameSize);
            if (palettePos < 0) palettePos += frameSize;

            Gdiplus::Color target = SamplePaletteSmooth(framePalette, palettePos);

            Gdiplus::Color result;
            if (frameTp >= 1.0f) {
                result = target;
            } else if (!framePrevPalette.empty()) {
                int prevSize = (int)framePrevPalette.size();
                float prevMappedSeg = ((float)seg / segmentCount) * prevSize;
                float prevPos = fmodf(prevMappedSeg + hueOffset, (float)prevSize);
                if (prevPos < 0) prevPos += prevSize;
                Gdiplus::Color prev = SamplePaletteSmooth(framePrevPalette, prevPos);
                result = TransitionToTargetColor(prev.GetR(), prev.GetG(), prev.GetB(), target, frameTp);
            } else {
                BYTE fadeAlpha = (BYTE)(frameTp * 255.0f);
                result = Gdiplus::Color(fadeAlpha, target.GetR(), target.GetG(), target.GetB());
            }

            // Apply brightness to palette-derived color, same as HSV path
            return Gdiplus::Color(result.GetA(),
                (BYTE)(result.GetR() * brightness),
                (BYTE)(result.GetG() * brightness),
                (BYTE)(result.GetB() * brightness));
        }
        return Gdiplus::Color(g_Ctx.Vis.currentOpacity, r, g, b);
    };

    // Overlap each segment slightly to eliminate sub-pixel gaps from float rounding
    float tOverlap = 1.0f / TotalP;

    // Flash alert — compute once per frame; 0=none, peaks at 1=full red wash
    float flashIntensity = 0.0f;
    {
        float fp = g_Ctx.Rainbow.flashProgress.load();
        if (fp > 0.0f) {
            float phase = fmodf(fp * 2.0f, 1.0f);      // two pulses across[0,1]
            flashIntensity = sinf(phase * 3.14159f);    // smooth 0→1→0 each pulse
        }
    }

    for (int s = 0; s < segmentCount; ++s) {
        float t1 = (float)s / segmentCount;
        float t2 = t1 + (1.0f / segmentCount) + tOverlap;

        // Gradient from this segment's color to the next
        Gdiplus::Color col1 = computeSegColor(s);
        Gdiplus::Color col2 = computeSegColor((s + 1) % segmentCount);

        // Blend toward red when error flash is active
        if (flashIntensity > 0.0f) {
            auto flashBlend = [&](Gdiplus::Color c) -> Gdiplus::Color {
                return Gdiplus::Color(c.GetA(),
                    (BYTE)Lerp((float)c.GetR(), 255.0f, flashIntensity),
                    (BYTE)Lerp((float)c.GetG(),   0.0f, flashIntensity),
                    (BYTE)Lerp((float)c.GetB(),   0.0f, flashIntensity));
            };
            col1 = flashBlend(col1);
            col2 = flashBlend(col2);
        }

        PointF p1 = GetPathPoint(t1);
        PointF p2 = GetPathPoint(t2);

        // Skip drawing if the segment is practically zero-length
        if (fabsf(p2.X - p1.X) < 0.1f && fabsf(p2.Y - p1.Y) < 0.1f) continue;

        LinearGradientBrush brush(p1, p2, col1, col2);
        Pen pen(&brush, thickness);
        
        // CRITICAL: LineCapSquare ensures the thick segments blast completely into the sharp 90-degree corners, 
        // covering the background so DWM has a solid block of color to clip perfectly.
        pen.SetLineCap(LineCapSquare, LineCapSquare, DashCapFlat); 

        graphics.DrawLine(&pen, p1, p2);
    }
}

// ..     --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------
// ^      --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------
// ~      --------------------------------------------------------------------------------------     RAINBOW BORDER     --------------------------------------------------------------------------------------


// Dynamic layout — all sizes derived from actual window dimensions
struct LayoutMetrics {
    int W, H;
    int sharedCenterY;
    float controlScale;
    int autoFontSize;

    // Dimensions
    int artSize;
    int controlGap;
    int controlSpacing;
    int iconW, iconH, barW;
    int hoverOffsetX, hoverOffsetY, hoverSize;
    int playBarW, playBarH, playBarYOffset;
    int playTriW, playTriH;
    int textPadding, textRightPadding;

    // Grouping
    int totalContentWidth;
    int startX;

    // Computed Positions
    int artX, artY;
    int startControlX;
    int controlY;
    int textX;
    int textMaxW;
};

#pragma endregion  // ^ Settings Handling

// ! ====================================================================================================================================================================================================

#pragma region // ^ Rendering

// Main layout function - computes all positions/sizes based on current window dimensions and settings
LayoutMetrics GetLayout() {
    // 1. Actual client dimensions (must match OnPaint coordinate space)
    int W = g_Settings.width, H = g_Settings.height;
    RECT rc;
    if (g_Ctx.Wnd.main && GetClientRect(g_Ctx.Wnd.main, &rc)) {
        int clientW = rc.right - rc.left;
        int clientH = rc.bottom - rc.top;
        float sf = (g_Ctx.Sys.scaleFactor > 0.0f) ? g_Ctx.Sys.scaleFactor : 1.0f;
        W = std::max(1, (int)std::lround((double)clientW / sf));
        H = std::max(1, (int)std::lround((double)clientH / sf));
    }

    // 2. Aspect Ratio Soft Cap
    float aspectRatio = (H > 0) ? (float)W / H : 1.0f;
    const float kMinLandscapeRatio = 3.5f; 
    int layoutH = H;
    if (aspectRatio < kMinLandscapeRatio) {
        layoutH = (int)(W / kMinLandscapeRatio);
    }

    LayoutMetrics L = {};
    L.W = W;
    L.H = H;
    L.sharedCenterY = H / 2;

    // 3. Art size & Baseline scales
    int padding = std::max(4, layoutH / 6);
    L.artSize = std::min(layoutH - padding, g_Settings.maxArtSize);
    L.artSize = std::max(L.artSize, 10);

    float kScaleEasing = (float)g_Settings.scaleEasing / 10.0f;
    float buttonSizeRaw = static_cast<float>(g_Settings.buttonSize);
    float targetSize = L.artSize * (buttonSizeRaw / 100.0f);

    float determinedButtonSize = Lerp(24.0f, targetSize, kScaleEasing);
    L.controlScale = determinedButtonSize / 24.0f;
    auto ScaleVal = [&](float v) { return std::max(1, (int)(v * L.controlScale + 0.5f)); };

    // 4. Compute all unified element metrics ONE TIME
    L.controlGap = ScaleVal(12);
    L.controlSpacing = ScaleVal(28);
    L.iconW = ScaleVal(8); L.iconH = ScaleVal(6); L.barW = ScaleVal(2);
    L.hoverOffsetX = ScaleVal(8); L.hoverOffsetY = ScaleVal(12); L.hoverSize = ScaleVal(24);
    L.playBarW = ScaleVal(3); L.playBarH = ScaleVal(14); L.playBarYOffset = ScaleVal(7);
    L.playTriW = ScaleVal(10); L.playTriH = ScaleVal(8);
    L.textPadding = ScaleVal(20); L.textRightPadding = ScaleVal(20);

    // Font calculation
    float baseScale = 0.5f;
    float userScale = g_Settings.textScale / 100.0f;
    L.autoFontSize = std::max(8, (int)ceilf(L.artSize * baseScale * userScale));

    // 5. Calculate Group Bounding Box
    int margin = std::max(2, padding / 2);
    int contentWidthWithoutText = L.artSize + L.controlGap + (L.controlSpacing * 2 + L.hoverSize - L.hoverOffsetX) + L.textPadding;

    // Clamp active text width so a massive scrolling string doesn't push the art off the left edge
    int maxAllowedTextW = std::max(0, W - contentWidthWithoutText - L.textRightPadding);
    int activeTextWidth = std::min(g_Ctx.Text.textWidth, maxAllowedTextW);

    L.totalContentWidth = contentWidthWithoutText + activeTextWidth;

    // 6. Flow anchor (text centering is handled at draw-time for non-scrolling text only)
    L.startX = margin;

    // 7. Flow Left-To-Right
    L.artX = L.startX;
    L.artY = L.sharedCenterY - (L.artSize / 2);

    L.startControlX = L.artX + L.artSize + L.controlGap;
    L.controlY = L.sharedCenterY;

    int lastButtonRight = L.startControlX + (L.controlSpacing * 2) + L.hoverSize - L.hoverOffsetX;
    L.textX = lastButtonRight + L.textPadding;
    L.textMaxW = std::max(0, W - L.textX - L.textRightPadding);

    return L;
}

// Draw a bitmap with per-call opacity using a color matrix
static void DrawBitmapWithOpacity(Graphics& gfx, Gdiplus::Bitmap* bmp, int x, int y, int w, int h, BYTE alpha) {
    if (!bmp || alpha == 0) return;

    ImageAttributes attrs;
    ColorMatrix cm = {};
    cm.m[0][0] = 1.0f; cm.m[0][1] = 0.0f; cm.m[0][2] = 0.0f; cm.m[0][3] = 0.0f; cm.m[0][4] = 0.0f;
    cm.m[1][0] = 0.0f; cm.m[1][1] = 1.0f; cm.m[1][2] = 0.0f; cm.m[1][3] = 0.0f; cm.m[1][4] = 0.0f;
    cm.m[2][0] = 0.0f; cm.m[2][1] = 0.0f; cm.m[2][2] = 1.0f; cm.m[2][3] = 0.0f; cm.m[2][4] = 0.0f;
    cm.m[3][0] = 0.0f; cm.m[3][1] = 0.0f; cm.m[3][2] = 0.0f; cm.m[3][3] = alpha / 255.0f; cm.m[3][4] = 0.0f;
    cm.m[4][0] = 0.0f; cm.m[4][1] = 0.0f; cm.m[4][2] = 0.0f; cm.m[4][3] = 0.0f; cm.m[4][4] = 1.0f;
    attrs.SetColorMatrix(&cm, ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);
    gfx.DrawImage(bmp, Rect(x, y, w, h), 0, 0, bmp->GetWidth(), bmp->GetHeight(), UnitPixel, &attrs);
}

void WindowManager::DrawMediaPanel(Graphics& graphics) {
    Color mainColor{GetCurrentTextColor()};
    auto L = GetLayout();

    BYTE elemAlpha = GetElementAlpha();

    // Album art with cross-fade between previous/current
    {
        float t = std::clamp(g_Ctx.ArtCache.transitionProgress.load(), 0.0f, 1.0f);

        Gdiplus::Bitmap* curr = (g_Ctx.Media.albumArt && g_Ctx.Media.albumArt->GetLastStatus() == Ok)
            ? g_Ctx.Media.albumArt.get() : nullptr;
        Gdiplus::Bitmap* prev = (g_Ctx.ArtCache.previousAlbumArt && g_Ctx.ArtCache.previousAlbumArt->GetLastStatus() == Ok)
            ? g_Ctx.ArtCache.previousAlbumArt.get() : nullptr;

        BYTE alphaPrev = prev ? (BYTE)((1.0f - t) * 255.0f) : 0;
        BYTE alphaCurr = 255;
        if (prev || (g_Settings.colorTheme == ColorTheme::Artwork && t < 1.0f)) {
            alphaCurr = (BYTE)(t * 255.0f);
        }

        alphaPrev = (BYTE)(alphaPrev * elemAlpha / 255);
        alphaCurr = (BYTE)(alphaCurr * elemAlpha / 255);

        if (prev && alphaPrev) {
            DrawBitmapWithOpacity(graphics, prev, L.artX, L.artY, L.artSize, L.artSize, alphaPrev);
        }
        if (curr && alphaCurr) {
            DrawBitmapWithOpacity(graphics, curr, L.artX, L.artY, L.artSize, L.artSize, alphaCurr);
        }

        if (!curr) {
            BYTE placeholderAlpha = prev ? alphaCurr : (BYTE)(40 * elemAlpha / 255);
            if (placeholderAlpha) {
                SolidBrush placeBrush{Color(placeholderAlpha, 128, 128, 128)};
                graphics.FillRectangle(&placeBrush, L.artX, L.artY, L.artSize, L.artSize);
            }
        }
    }

    wstring title = g_Ctx.Media.hasMedia ? g_Ctx.Media.title : L"No Media";
    wstring artist = g_Ctx.Media.hasMedia ? g_Ctx.Media.artist : L"";
    bool isPlaying = g_Ctx.Media.isPlaying;

    SolidBrush iconBrush{Color(elemAlpha, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};
    SolidBrush hoverBrush{Color(elemAlpha, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};
    SolidBrush activeBg{Color((BYTE)(40 * elemAlpha / 255), mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};

    // Prev button
    int pX = L.startControlX;
    if (g_Ctx.Vis.hoverState == 1) graphics.FillEllipse(&activeBg, pX - L.hoverOffsetX, L.controlY - L.hoverOffsetY, L.hoverSize, L.hoverSize);
    Point prevPts[3] = { Point(pX + L.iconW, L.controlY - L.iconH), Point(pX + L.iconW, L.controlY + L.iconH), Point(pX, L.controlY) };
    graphics.FillPolygon(g_Ctx.Vis.hoverState == 1 ? &hoverBrush : &iconBrush, prevPts, 3);
    graphics.FillRectangle(g_Ctx.Vis.hoverState == 1 ? &hoverBrush : &iconBrush, pX, L.controlY - L.iconH, L.barW, L.iconH * 2);

    // Play/Pause button
    int plX = L.startControlX + L.controlSpacing;
    if (g_Ctx.Vis.hoverState == 2) graphics.FillEllipse(&activeBg, plX - L.hoverOffsetX, L.controlY - L.hoverOffsetY, L.hoverSize, L.hoverSize);
    if (isPlaying) {
        graphics.FillRectangle(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, plX, L.controlY - L.playBarYOffset, L.playBarW, L.playBarH);
        graphics.FillRectangle(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, plX + L.playBarW * 2, L.controlY - L.playBarYOffset, L.playBarW, L.playBarH);
    } else {
        Point playPts[3] = { Point(plX, L.controlY - L.playTriH), Point(plX, L.controlY + L.playTriH), Point(plX + L.playTriW, L.controlY) };
        graphics.FillPolygon(g_Ctx.Vis.hoverState == 2 ? &hoverBrush : &iconBrush, playPts, 3);
    }

    // Next button
    int nX = L.startControlX + (L.controlSpacing * 2);
    if (g_Ctx.Vis.hoverState == 3) graphics.FillEllipse(&activeBg, nX - L.hoverOffsetX, L.controlY - L.hoverOffsetY, L.hoverSize, L.hoverSize);
    Point nextPts[3] = { Point(nX, L.controlY - L.iconH), Point(nX, L.controlY + L.iconH), Point(nX + L.iconW, L.controlY) };
    graphics.FillPolygon(g_Ctx.Vis.hoverState == 3 ? &hoverBrush : &iconBrush, nextPts, 3);
    graphics.FillRectangle(g_Ctx.Vis.hoverState == 3 ? &hoverBrush : &iconBrush, nX + L.iconW, L.controlY - L.iconH, L.barW, L.iconH * 2);

    // Text & Bounds
    wstring fullText = title;
    if (!artist.empty()) fullText += L" • " + artist;

    FontFamily fontFamily(kFontName, nullptr);
    Font font(&fontFamily, (REAL)L.autoFontSize, FontStyleBold, UnitPixel);
    SolidBrush textBrush{Color(elemAlpha, mainColor.GetRed(), mainColor.GetGreen(), mainColor.GetBlue())};

    TextRenderingHint oldTextHint = graphics.GetTextRenderingHint();
    graphics.SetTextRenderingHint(TextRenderingHintSingleBitPerPixelGridFit);

    int clipX = std::max(0, L.textX);
    int clipW = std::max(0, std::min(L.textMaxW, L.W - clipX));
    Region textClip(Rect(clipX, 0, clipW, L.H));
    graphics.SetClip(&textClip);

    StringFormat textFormat;
    textFormat.SetAlignment(StringAlignmentNear);
    textFormat.SetLineAlignment(StringAlignmentCenter);
    textFormat.SetFormatFlags(StringFormatFlagsNoWrap);
    textFormat.SetTrimming(StringTrimmingNone);

    bool canUseStrip = g_Ctx.Text.stripBitmap && g_Ctx.Text.stripBitmap->GetLastStatus() == Ok &&
                       g_Ctx.Text.textWidth > 0 && g_Ctx.Text.stripHeight > 0;

    if (canUseStrip) {
        int drawY = L.artY + ((L.artSize - g_Ctx.Text.stripHeight) / 2);
        int stripW = std::max(1, g_Ctx.Text.textWidth + 4);

        if (g_Ctx.Text.isScrolling && g_Settings.EnableTextScroll) {
            int drawX = L.textX - g_Ctx.Text.offset;
            graphics.DrawImage(g_Ctx.Text.stripBitmap.get(), drawX, drawY, stripW, g_Ctx.Text.stripHeight);
            if (drawX + g_Ctx.Text.textWidth < L.W) {
                graphics.DrawImage(g_Ctx.Text.stripBitmap.get(), drawX + g_Ctx.Text.textWidth + 40, drawY, stripW, g_Ctx.Text.stripHeight);
            }
        } else {
            int drawX = L.textX;
            if (g_Settings.centered) {
                int nextButtonX = L.startControlX + (L.controlSpacing * 2);
                int regionW = std::max(0, L.W - nextButtonX);
                int centeredX = nextButtonX;
                if (regionW > g_Ctx.Text.textWidth) {
                    centeredX = nextButtonX + ((regionW - g_Ctx.Text.textWidth) / 2);
                }
                drawX = std::max(L.textX, centeredX);
            }
            graphics.DrawImage(g_Ctx.Text.stripBitmap.get(), drawX, drawY, stripW, g_Ctx.Text.stripHeight);
        }
    } else {
        if (g_Ctx.Text.isScrolling && g_Settings.EnableTextScroll) {
            float drawX = (float)L.textX - g_Ctx.Text.offset;
            RectF textRect(drawX, (REAL)L.artY, (REAL)std::max(clipW, g_Ctx.Text.textWidth + 4), (REAL)L.artSize);
            graphics.DrawString(fullText.c_str(), -1, &font, textRect, &textFormat, &textBrush);
            if (drawX + g_Ctx.Text.textWidth < L.W) {
                RectF textRect2(drawX + g_Ctx.Text.textWidth + 40.0f, (REAL)L.artY, (REAL)std::max(clipW, g_Ctx.Text.textWidth + 4), (REAL)L.artSize);
                graphics.DrawString(fullText.c_str(), -1, &font, textRect2, &textFormat, &textBrush);
            }
        } else {
            float drawX = (float)L.textX;
            if (g_Settings.centered) {
                int nextButtonX = L.startControlX + (L.controlSpacing * 2);
                int regionW = std::max(0, L.W - nextButtonX);
                int centeredX = nextButtonX;
                if (regionW > g_Ctx.Text.textWidth) {
                    centeredX = nextButtonX + ((regionW - g_Ctx.Text.textWidth) / 2);
                }
                drawX = (float)std::max(L.textX, centeredX);
            }
            RectF textRect(drawX, (REAL)L.artY, (REAL)std::max(0, L.W - (int)drawX), (REAL)L.artSize);
            graphics.DrawString(fullText.c_str(), -1, &font, textRect, &textFormat, &textBrush);
        }
    }

    graphics.ResetClip();
    graphics.SetTextRenderingHint(oldTextHint);
}

#pragma region // * Audio Processing

// | Calculate smoothed audio peak level with optional dynamic range processing
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

#pragma endregion   // ^ Audio Processing

#pragma endregion  // ^ Rendering

// ! ===================================================================================================================================================================================================

#pragma region // ^ ----- Window Procedures -----

// | Check if click is on album art or buttons (returns true if on background/text area)
bool IsClickOnBackground(LPARAM lParam) {
    POINT pt = { (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam) };
    if (s_PhysicalToLogical && g_Ctx.Wnd.main)
        s_PhysicalToLogical(g_Ctx.Wnd.main, &pt);
    else { pt.x = (int)(pt.x / g_Ctx.Sys.scaleFactor); pt.y = (int)(pt.y / g_Ctx.Sys.scaleFactor); }
    int x = pt.x;
    int y = pt.y;

    auto L = GetLayout();

    // Album art region
    if (x >= L.artX && x <= L.artX + L.artSize && y >= L.artY && y <= L.artY + L.artSize)
        return false;

    // Button region
    int prevLeft = L.startControlX - L.hoverOffsetX;
    int nextRight = (L.startControlX + L.controlSpacing * 2) - L.hoverOffsetX + L.hoverSize;
    int top = L.controlY - L.hoverOffsetY;
    int bottom = top + L.hoverSize;

    if (y >= top && y <= bottom && x >= prevLeft && x < nextRight)
        return false;

    return true;
}

// | Game Detection/Idle Timeout Logic: Determines if the widget should hide based on fullscreen apps or idle state
// TODO: SHOULD recieve event msgs maybe? | Re-add Game Detection
bool WindowManager::ShouldWindowBeHidden() {
    return g_Ctx.Vis.isHiddenByIdle;
}

void WindowManager::OnTimer(HWND hwnd, UINT_PTR timerId) {
    if (timerId == IDT_POLL_MEDIA) {
        // Idle timeout logic
        if (g_Ctx.Media.isPlaying) {
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
    else if (timerId == IDT_MASTER_TICK) {
        OnMasterTick(hwnd);
    }
}

void WindowManager::OnMasterTick(HWND hwnd) {
    bool repaintMain = false;       // Flag to indicate if main window needs repaint (e.g. for text scroll or other dynamic elements)
    bool repaintRainbow = false;    // Flag to indicate if rainbow needs repaint (e.g. for color changes or animations)
    bool LiveAudioDebug = false;   // Set to true to enable real-time audio peak level display in logs for debugging

    // 1. Process Delayed Actions
    g_ActionDispatcher.ProcessDelayedActions();

    // 2. Audio Peak Sampling
    if (g_Settings.audioHueReactiveMode > 0 && g_Ctx.Audio.runtimeEnabled) {
        float peak = g_audioCOM.GetPeakLevel();
        g_Ctx.Audio.peakLevel = CalculateAudioPeak(peak);
    }

    // .. 3. Rainbow Animation & Artwork Palette Sync
    // ^ 1 Speedboost | Rainbow animates faster when audio is louder.
    // ^ 2 Pulse | Rainbow colors jump when audio exceeds threshold.
    // ^ 3 Bounce | Rainbow direction reverses when audio exceeds threshold.
    // ^ 4 Speedboost + Pulse | Combines both effects for maximum audio reactivity.
    // ^ 5 Speedboost + Bounce | Combines Speedboost and Bounce effects.
    // ^ 6 PulseBounce | Combines Pulse and Bounce effects.
    // ^ 7 All Effects | Combines all available audio reactive effects.

    if (g_Settings.enableRainbow || g_Settings.colorTheme == ColorTheme::Artwork) {

        float baseRainbowSpeed = g_Settings.rainbowSpeed * 0.075f; // Base speed for all modes (can be modified by effects)
        if (g_Settings.audioHueReactiveMode > 0 && g_Settings.enableRainbow && g_Ctx.Audio.runtimeEnabled) {
            // * Speed boost (modes 1, 4, 5, 7)          Speedboost | Speedboost + Pulse | Speedboost + Bounce | All Effects
            if (g_Settings.audioHueReactiveMode == 1 || g_Settings.audioHueReactiveMode == 4 || 
                g_Settings.audioHueReactiveMode == 5 || g_Settings.audioHueReactiveMode == 7) {

                float speedMult = 1.0f + (g_Ctx.Audio.peakLevel * kAudioSensitivity * kAudioHueSpeedBoost);
                g_Ctx.Rainbow.hue += (baseRainbowSpeed * speedMult);
            }
            else {
                g_Ctx.Rainbow.hue += (baseRainbowSpeed);  // | Base rotation for non-speed-boost modes (also applies when audio reactive but speed boost disabled)
            }

            // * Pulse effect (modes 2, 4, 6, 7)         Pulse | Speedboost + Pulse | Pulse + Bounce | All Effects
            if (g_Settings.audioHueReactiveMode == 2 || g_Settings.audioHueReactiveMode == 4 || 
                g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                // g_Ctx.Rainbow.hue += (g_Ctx.Audio.peakLevel * kAudioHuePulseAmount * 0.1f);
                float pulseMult = 1.0f + (g_Ctx.Audio.peakLevel * kAudioHuePulseAmount);
                g_Ctx.Rainbow.hue += (baseRainbowSpeed * pulseMult);
            }

            // * Bounce effect (modes 3, 5, 6, 7)        Bounce | Speedboost + Bounce | Pulse + Bounce | All Effects
            if (g_Settings.audioHueReactiveMode == 3 || g_Settings.audioHueReactiveMode == 5 || 
                g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) {
                if (g_Ctx.Audio.peakLevel > kAudioHueBounceThreshold && !g_Ctx.Rainbow.directionReverse) g_Ctx.Rainbow.directionReverse = true;
                else if (g_Ctx.Audio.peakLevel <= kAudioHueBounceThreshold && g_Ctx.Rainbow.directionReverse) g_Ctx.Rainbow.directionReverse = false;
                if (g_Ctx.Rainbow.directionReverse) g_Ctx.Rainbow.hue -= 1 * baseRainbowSpeed * 0.5f;
            }

        } else {    // .. Base rainbow animation when not audio-reactive or audio disabled
            float speedMult = 1.0f;
            if (g_Settings.audioHueReactiveMode > 0 && g_Ctx.Audio.runtimeEnabled && (kAudioReactiveMode == 0 || kAudioReactiveMode == 3))
                speedMult = 1.0f + (g_Ctx.Audio.peakLevel * kAudioSensitivity * 2.0f);
            g_Ctx.Rainbow.hue += (baseRainbowSpeed * speedMult);
        }

        // | Keep hue in [0, 360) range for consistency
        if (g_Ctx.Rainbow.hue >= 360.0f) g_Ctx.Rainbow.hue -= 360.0f;
        if (g_Ctx.Rainbow.hue < 0.0f) g_Ctx.Rainbow.hue += 360.0f;

        // .. Regenerate artwork palette if theme is Artwork and art has changed (also triggers rainbow repaint since it depends on palette)
        // TODO: When switching color palettes, It should ONLY repaint the ARTWORK if the mode is -1 else theres no reason to repaint!
        if (g_Settings.colorTheme == ColorTheme::Artwork && g_Ctx.ArtCache.dirty.load()) {
            RECT rcC; GetClientRect(hwnd, &rcC);
            if (LiveAudioDebug) {
                Wh_Log(L"[LIVE RAINBOW DEBUG] ARTWORK DIRTY | Running RegenerateArtworkCache with dimensions: %d x %d", (rcC.right > 0) ? rcC.right : Scale(g_Settings.width), (rcC.bottom > 0) ? rcC.bottom : Scale(g_Settings.height));
            }
                RegenerateArtworkCache((rcC.right > 0) ? rcC.right : Scale(g_Settings.width), (rcC.bottom > 0) ? rcC.bottom : Scale(g_Settings.height));
        }
            // if (LiveAudioDebug && g_Ctx.ArtCache.dirty.load() == false) {
            //     Wh_Log(L"[LIVE RAINBOW DEBUG] Mode: %d | Speed Mult: %0.2f | Pulse Mult: %0.2f | Hue: %0.5f | Current Peak lvl: %0.5f ", g_Settings.audioHueReactiveMode, (1.0f + (g_Ctx.Audio.peakLevel * kAudioSensitivity * kAudioHueSpeedBoost)), (1.0f + (g_Ctx.Audio.peakLevel * kAudioHuePulseAmount)), g_Ctx.Rainbow.hue.load(), g_Ctx.Audio.peakLevel.load());
            // }
                // Wh_Log(L"[LIVE RAINBOW DEBUG] Direction Reverse: %s | Speed Mult: %0.5f | Pulse Mult: %0.5f", g_Ctx.Rainbow.directionReverse.load() ? L"true" : L"false", 
                //     (g_Settings.audioHueReactiveMode > 0 && g_Ctx.Audio.runtimeEnabled) ? (1.0f + (g_Ctx.Audio.peakLevel.load() * kAudioSensitivity * kAudioHueSpeedBoost)) : 1.0f,
                //     (g_Settings.audioHueReactiveMode == 2 || g_Settings.audioHueReactiveMode == 4 || g_Settings.audioHueReactiveMode == 6 || g_Settings.audioHueReactiveMode == 7) ? (1.0f + (g_Ctx.Audio.peakLevel.load() * kAudioHuePulseAmount)) : 1.0f);
        repaintRainbow = true;
    }

    // .. 4. Artwork Cross-Fade
    float tp = g_Ctx.ArtCache.transitionProgress.load();
    if (tp < 1.0f) {
        tp = std::min(1.0f, tp + 0.008f);   // .. Increment transition progress  (LIVE)
        g_Ctx.ArtCache.transitionProgress = tp;
        repaintMain = true;
        if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) repaintRainbow = true;
        if (tp >= 1.0f) {
            g_Ctx.ArtCache.previousBgBitmap.reset();
            g_Ctx.ArtCache.previousAlbumArt.reset();
            g_Ctx.ArtCache.previousPalette.clear();
        }
    }

    // .. 5. Text Cache + Scroll State Machine (EXCLUSIVE WRITE OWNER)
    auto L = GetLayout(); // Grab layout to know max width boundaries

    wstring title = g_Ctx.Media.hasMedia ? g_Ctx.Media.title : L"No Media";
    wstring artist = g_Ctx.Media.hasMedia ? g_Ctx.Media.artist : L"";
    wstring fullText = title;
    if (!artist.empty()) fullText += L" • " + artist;

    Color currentTextColor = GetCurrentTextColor();
    BYTE currentElemAlpha = GetElementAlpha();

    unsigned long long newFontSig =
        ((unsigned long long)(unsigned int)L.autoFontSize << 32) ^
        (unsigned long long)(unsigned int)(g_Ctx.Sys.scaleFactor * 1000.0f);
    unsigned long long newColorSig =
        ((unsigned long long)currentElemAlpha << 24) |
        ((unsigned long long)currentTextColor.GetRed() << 16) |
        ((unsigned long long)currentTextColor.GetGreen() << 8) |
        (unsigned long long)currentTextColor.GetBlue();

    bool cacheChanged = g_Ctx.Text.dirty ||
                        (g_Ctx.Text.textSignature != fullText) ||
                        (g_Ctx.Text.fontSignature != newFontSig) ||
                        (g_Ctx.Text.colorSignature != newColorSig) ||
                        !g_Ctx.Text.stripBitmap;

    if (cacheChanged) {
        g_Ctx.Text.textSignature = fullText;
        g_Ctx.Text.fontSignature = newFontSig;
        g_Ctx.Text.colorSignature = newColorSig;

        FontFamily fontFamily(kFontName, nullptr);
        Font font(&fontFamily, (REAL)L.autoFontSize, FontStyleBold, UnitPixel);

        HDC screenDC = GetDC(NULL);
        if (screenDC) {
            HDC memDC = CreateCompatibleDC(screenDC);
            if (memDC) {
                Graphics measureGraphics(memDC);
                RectF measureRect(0, 0, 2000, 100), boundRect;
                measureGraphics.MeasureString(fullText.c_str(), -1, &font, measureRect, &boundRect);

                int measuredW = std::max(0, (int)std::ceil(boundRect.Width));
                int measuredH = std::max(1, L.artSize);
                g_Ctx.Text.textWidth = measuredW;
                g_Ctx.Text.stripHeight = measuredH;

                int stripW = std::max(1, measuredW + 4);
                g_Ctx.Text.stripBitmap.reset(new Gdiplus::Bitmap(stripW, measuredH, PixelFormat32bppARGB));

                if (g_Ctx.Text.stripBitmap && g_Ctx.Text.stripBitmap->GetLastStatus() == Ok) {
                    Graphics stripG(g_Ctx.Text.stripBitmap.get());
                    stripG.SetCompositingMode(CompositingModeSourceOver);
                    stripG.SetTextRenderingHint(TextRenderingHintSingleBitPerPixelGridFit);

                    SolidBrush clearBrush(Color(0, 0, 0, 0));
                    stripG.FillRectangle(&clearBrush, 0, 0, stripW, measuredH);

                    SolidBrush stripTextBrush{Color(currentElemAlpha, currentTextColor.GetRed(), currentTextColor.GetGreen(), currentTextColor.GetBlue())};
                    StringFormat stripFormat;
                    stripFormat.SetAlignment(StringAlignmentNear);
                    stripFormat.SetLineAlignment(StringAlignmentCenter);
                    stripFormat.SetFormatFlags(StringFormatFlagsNoWrap);
                    stripFormat.SetTrimming(StringTrimmingNone);

                    RectF stripRect(0.0f, 0.0f, (REAL)stripW, (REAL)measuredH);
                    stripG.DrawString(fullText.c_str(), -1, &font, stripRect, &stripFormat, &stripTextBrush);
                } else {
                    g_Ctx.Text.stripBitmap.reset();
                }

                DeleteDC(memDC);
            }
            ReleaseDC(NULL, screenDC);
        }

        g_Ctx.Text.dirty = false;
        g_Ctx.Text.offset = 0;
        g_Ctx.Text.waitCounter = 60;
        repaintMain = true;
    }

    bool shouldScroll = (g_Ctx.Text.textWidth > L.textMaxW && g_Settings.EnableTextScroll);

    // Detect state change
    if (shouldScroll != g_Ctx.Text.isScrolling) {
        g_Ctx.Text.isScrolling = shouldScroll;
        if (shouldScroll) {
            g_Ctx.Text.waitCounter = 60;
        } else {
            g_Ctx.Text.offset = 0;
            repaintMain = true; // Force redraw to reset position immediately
        }
    }

    // Advance scroll tick
    if (g_Ctx.Text.isScrolling) {
        if (g_Ctx.Text.waitCounter > 0) {
            g_Ctx.Text.waitCounter--;
        } else {
            g_Ctx.Text.offset++;
            if (g_Ctx.Text.offset > g_Ctx.Text.textWidth + 40) {
                g_Ctx.Text.offset = 0;
                g_Ctx.Text.waitCounter = 60;
            }
            repaintMain = true;
        }
    }

    // .. 6. Vis/Slide Animation
    if (g_Ctx.Vis.animState == 1 || g_Ctx.Vis.animState == 2) {
        int scaledW = EffectiveW();
        int scaledH = EffectiveH();
        bool hasRainbow = g_Ctx.Wnd.rainbow && g_Settings.enableRainbow && IsWindow(g_Ctx.Wnd.rainbow);
        const float smoothFactor = 0.5f;

        int currX = g_Ctx.Vis.currentAnimX;
        int currY = g_Ctx.Vis.currentAnimY;
        int targetX = currX, targetY = currY;

        if (g_Ctx.Vis.animState == 1) {         //& Hiding
            if (!g_Ctx.Sys.isShutdown && !ShouldWindowBeHidden() && g_Ctx.Vis.dockedMode != 1) { 
                g_Ctx.Vis.animState = 2; 
                if (hasRainbow) g_Ctx.Rainbow.animState = 2;
                return;
            }
            RECT mon = GetMonitorRect(hwnd);
            int peekPx = (g_Ctx.Vis.dockedMode == 1) ? DOCK_PEEK_PIXELS : 0;
            switch (g_Ctx.Vis.animEdge) {
                case ScreenEdge::TOP:    targetY = mon.top - scaledH + peekPx; break;
                case ScreenEdge::BOTTOM: targetY = mon.bottom - peekPx; break;
                case ScreenEdge::LEFT:   targetX = mon.left - scaledW + peekPx; break;
                case ScreenEdge::RIGHT:  targetX = mon.right - peekPx; break;
            }
        } else {                                // .. Showing
            if (ShouldWindowBeHidden() && !g_Ctx.Sys.isShutdown) { 
                g_Ctx.Vis.animState = 1; 
                if (hasRainbow) g_Ctx.Rainbow.animState = 1;
                return; 
            }
            targetX = (g_Ctx.Vis.normalX != 0 || g_Ctx.Vis.normalY != 0) ? g_Ctx.Vis.normalX : EffectiveX();
            targetY = (g_Ctx.Vis.normalX != 0 || g_Ctx.Vis.normalY != 0) ? g_Ctx.Vis.normalY : EffectiveY();
            ShowWindow(hwnd, SW_SHOWNOACTIVATE);
        }

        bool xDone = (abs(currX - targetX) <= 1);
        bool yDone = (abs(currY - targetY) <= 1);

        g_Ctx.Vis.currentAnimX = xDone ? targetX : (int)Lerp((float)currX, (float)targetX, smoothFactor);
        g_Ctx.Vis.currentAnimY = yDone ? targetY : (int)Lerp((float)currY, (float)targetY, smoothFactor);

        SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), g_Ctx.Vis.currentAnimX, g_Ctx.Vis.currentAnimY, scaledW, scaledH, SWP_NOACTIVATE | (g_Ctx.Vis.animState == 2 ? SWP_SHOWWINDOW : 0));
        
        if (hasRainbow) {
            int bo = Scale(g_Settings.rainbowBorderOffset);
            SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), g_Ctx.Vis.currentAnimX - bo, g_Ctx.Vis.currentAnimY - bo, scaledW + bo * 2, scaledH + bo * 2, SWP_NOACTIVATE | (g_Ctx.Vis.animState == 2 ? SWP_SHOWWINDOW : 0));
        }

        if (xDone && yDone) {
            if (g_Ctx.Vis.animState == 1) { // Done Hiding
                if (g_Ctx.Sys.isShutdown) {
                    if (hasRainbow) DestroyWindow(g_Ctx.Wnd.rainbow);
                    DestroyWindow(hwnd);
                } else if (g_Ctx.Vis.dockedMode != 1) {
                    if (hasRainbow) ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
                    ShowWindow(hwnd, SW_HIDE);
                }
                g_Ctx.Vis.animState = 3;
            } else { // Done Showing
                SaveWindowState(targetX, targetY, scaledW, scaledH, true);
                g_Ctx.Vis.animState = 0;
                g_Ctx.Vis.dockedMode = 0;
                if (hasRainbow) g_Ctx.Rainbow.animState = 0;
            }
        }
    }

    // ^ Flash alert tick — independent of rainbow enabled state
    {
        float fp = g_Ctx.Rainbow.flashProgress.load();
        if (fp > 0.0f) {
            fp += 0.014f;  // ~1.2 seconds for full double-pulse at 60fps
            g_Ctx.Rainbow.flashProgress = (fp >= 1.0f) ? 0.0f : fp;
            repaintRainbow = true;
        }
    }

    // 7. Fire consolidated Invalidates
    if (repaintMain) {
        InvalidateRect(hwnd, NULL, FALSE);
    }
    if (repaintRainbow && g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
        InvalidateRect(g_Ctx.Wnd.rainbow, NULL, FALSE);
    }
}

void WindowManager::OnMouseWheel(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    short zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    bool handled = false;
    
    POINT pt;
        pt.x = (int)(short)LOWORD(lParam);
        pt.y = (int)(short)HIWORD(lParam);
        ScreenToClient(hwnd, &pt);
        if (s_PhysicalToLogical && hwnd) s_PhysicalToLogical(hwnd, &pt);
        else { pt.x = (int)(pt.x / g_Ctx.Sys.scaleFactor); pt.y = (int)(pt.y / g_Ctx.Sys.scaleFactor); }
        LPARAM clientLParam = MAKELPARAM(pt.x, pt.y);

    bool isOnBackground = IsClickOnBackground(clientLParam);

    if (isOnBackground) {
        Wh_Log(L"[INPUT] WM_MOUSEWHEEL at client coords (%d, %d), Delta: %+d", pt.x, pt.y, zDelta);

        if (zDelta > 0) {
            Wh_Log(L"[INPUT] ScrollUp on background - triggering action");
            handled = OnTriggerEvent(L"ScrollUp", zDelta);
        } else {
            Wh_Log(L"[INPUT] ScrollDown on background - triggering action");
            handled = OnTriggerEvent(L"ScrollDown", zDelta);
        }
    } else {
        Wh_Log(L"[INPUT] Scroll BLOCKED - not on background");
    }
    
    if (!handled && isOnBackground) {
        Wh_Log(L"[INPUT] Sending volume command, Delta: %+d", zDelta);
        SendMessage(hwnd, WM_APPCOMMAND, 0, zDelta > 0 ? APPCOMMAND_VOLUME_UP << 16 : APPCOMMAND_VOLUME_DOWN << 16);
    }
}

// |-- Rainbow Window procedure
LRESULT CALLBACK RainbowWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            Wh_Log(L" -- WM_CREATE received - initializing RainbowWndProc");
            // Make window transparent to mouse events
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
            // Apply corner rounding to match main window
            ApplyCornerPreference(hwnd, g_Settings.enableRoundedCorners);
            Wh_Log(L" Window corner rounding: %s", g_Settings.enableRoundedCorners ? L"enabled" : L"disabled");
            return 0;
        }
        case WM_ERASEBKGND: return 1;
        case APP_WM_CLOSE:
            Wh_Log(L"[SHUTDOWN] -- RainbowWndProc WM_CLOSE received, destroying window");
            DestroyWindow(hwnd); return 0;
        case WM_DESTROY:
            Wh_Log(L"[SHUTDOWN] -- RainbowWndProc WM_DESTROY");
            return 0;
        case WM_TIMER:
            return 0; // Handled strictly by Master Tick on Main Window now
        case WM_PAINT: {
            RECT rc;
            GetClientRect(hwnd, &rc);
            int w = rc.right, h = rc.bottom;

            // 32-bit DIB for per-pixel alpha compositing
            BITMAPINFO bmi = {};
            bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
            bmi.bmiHeader.biWidth       = w;
            bmi.bmiHeader.biHeight      = -h; // top-down
            bmi.bmiHeader.biPlanes      = 1;
            bmi.bmiHeader.biBitCount    = 32;
            bmi.bmiHeader.biCompression = BI_RGB;

            HDC screenDC = GetDC(NULL);
            void* bits = nullptr;
            HBITMAP dib = CreateDIBSection(screenDC, &bmi, DIB_RGB_COLORS, &bits, NULL, 0);
            HDC memDC = CreateCompatibleDC(screenDC);
            HBITMAP oldBmp = (HBITMAP)SelectObject(memDC, dib);

            DrawRainbowBorder(memDC, w, h);

            // Composite with per-pixel alpha — background pixels stay transparent
            POINT ptDst = { rc.left, rc.top };
            SIZE  szWnd = { w, h };
            POINT ptSrc = { 0, 0 };
            BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE)g_Ctx.Vis.currentOpacity, AC_SRC_ALPHA };
            ClientToScreen(hwnd, &ptDst);
            UpdateLayeredWindow(hwnd, screenDC, &ptDst, &szWnd, memDC, &ptSrc, 0, &blend, ULW_ALPHA);

            SelectObject(memDC, oldBmp);
            DeleteObject(dib);
            DeleteDC(memDC);
            ReleaseDC(NULL, screenDC);
            ValidateRect(hwnd, NULL);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// |-- Media Window procedure
LRESULT CALLBACK MediaWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case APP_WM_MEDIA_UPDATED: {
            auto* payload = reinterpret_cast<MediaUpdatePayload*>(lParam);
            if (payload) {
                // Guard: reject metadata downgrades (e.g., Firefox generic fallback)
                if (payload->hasMedia && payload->artist.empty()
                    && g_Ctx.Media.hasMedia && !g_Ctx.Media.artist.empty()) {
                    Wh_Log(L"[MEDIA] INFO: Rejected metadata downgrade: '%s' (no artist) — keeping '%s' by '%s'",
                           payload->title.c_str(), g_Ctx.Media.title.c_str(), g_Ctx.Media.artist.c_str());
                    delete payload;
                    return 0;
                }

                // Evaluate transition BEFORE overwriting state (std::move invalidates source)
                bool oldHasArt = (g_Ctx.Media.albumArt && g_Ctx.Media.albumArt->GetLastStatus() == Ok);
                bool newHasArt = (payload->albumArt && payload->albumArt->GetLastStatus() == Ok);
                bool mediaIdentityChanged =
                    (g_Ctx.Media.hasMedia != payload->hasMedia) ||
                    (g_Ctx.Media.sourceId != payload->sourceId) ||
                    (g_Ctx.Media.title != payload->title) ||
                    (g_Ctx.Media.artist != payload->artist);
                bool shouldTransition = (g_Settings.colorTheme == ColorTheme::Artwork) &&
                    (mediaIdentityChanged || oldHasArt != newHasArt);

                // Block 1: snapshot previous art for crossfade (only when previous art exists)
                if (shouldTransition && oldHasArt) {
                    float currentTp = g_Ctx.ArtCache.transitionProgress.load();
                    if (currentTp >= 1.0f || g_Ctx.ArtCache.previousPalette.empty()) {
                        SnapshotPalette(g_Ctx.ArtCache.previousPalette, g_Ctx.ArtCache.palette);
                        if (g_Ctx.ArtCache.bgBitmap) {
                            g_Ctx.ArtCache.previousBgBitmap.reset(g_Ctx.ArtCache.bgBitmap->Clone(
                                0, 0, g_Ctx.ArtCache.bgBitmap->GetWidth(),
                                g_Ctx.ArtCache.bgBitmap->GetHeight(), PixelFormat32bppARGB));
                        }
                        g_Ctx.ArtCache.previousAlbumArt.reset(g_Ctx.Media.albumArt->Clone(
                            0, 0, g_Ctx.Media.albumArt->GetWidth(),
                            g_Ctx.Media.albumArt->GetHeight(), PixelFormat32bppARGB));
                        // Hold at 0 so the painter shows old art while waiting for new art to arrive
                        // (WinRT fires two events: metadata first with no art, then art arrives separately)
                        g_Ctx.ArtCache.transitionProgress = 0.0f;
                    }
                }

                // Block 2: kick off regen whenever new art is arriving (fixes first-load: oldHasArt was false)
                if (shouldTransition && newHasArt) {
                    g_Ctx.ArtCache.transitionProgress = 0.0f;
                    g_Ctx.ArtCache.dirty = true;
                    // The Master Tick will instantly pick this up!
                }

                // Apply state updates after transition decision
                g_Ctx.Media.title = std::move(payload->title);
                g_Ctx.Media.artist = std::move(payload->artist);
                g_Ctx.Media.sourceId = std::move(payload->sourceId);
                if (!g_Ctx.Media.sourceId.empty())
                    g_Ctx.Media.lastValidSourceId = g_Ctx.Media.sourceId;
                g_Ctx.Media.isPlaying = payload->isPlaying;
                g_Ctx.Media.hasMedia = payload->hasMedia;
                g_Ctx.Media.albumArt = std::move(payload->albumArt);

                g_Ctx.Text.offset = 0;
                g_Ctx.Text.waitCounter = 60;
                g_Ctx.Text.isScrolling = false;
                g_Ctx.Text.dirty = true;

                SaveLastMediaInfo(g_Ctx.Media.title, g_Ctx.Media.artist);
                Wh_Log(L"[MEDIA] Updated: '%s' by '%s' (playing=%d)",
                       g_Ctx.Media.title.c_str(), g_Ctx.Media.artist.c_str(), g_Ctx.Media.isPlaying);

                if (!g_Ctx.Vis.mediaStateInitialized.exchange(true)) {
                    Wh_Log(L"[INIT] First GSMTC media state received");
                    if (g_Settings.idleTimeout > 0 && IsWindow(hwnd))
                        SetTimer(hwnd, IDT_POLL_MEDIA, 1000, NULL);
                }

                delete payload;
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
        }
        case APP_WM_REFRESH_MEDIA: {
            Wh_Log(L"[SETTINGS] Forced media refresh requested - restoring live state");
            UpdateMediaInfoAsync();
            return 0;
        }
        case WM_CREATE: {
            Wh_Log(L"-- WM_CREATE received - initializing MediaWndProc");
            g_WindowManager.UpdateAppearance(hwnd);
            SetupMediaWindowTimers();
            SetTimer(hwnd, IDT_MASTER_TICK, TIMER_ANIMATION_MS, NULL); // START MASTER TICK
            return 0;
        }

        case WM_APPCOMMAND: { return DefWindowProc(hwnd, msg, wParam, lParam); }

        case WM_ERASEBKGND: { return 1; }

        case APP_WM_CLOSE: {
            if (g_Ctx.Sys.isShutdown && g_Settings.enableSlide) {
                Wh_Log(L"[SHUTDOWN] Starting smart edge slide-out animation...");
                RECT rcMe; GetWindowRect(hwnd, &rcMe);
                int w = rcMe.right - rcMe.left;
                int h = rcMe.bottom - rcMe.top;
                
                // ^ Seed animation start position
                g_Ctx.Vis.currentAnimX = rcMe.left;
                g_Ctx.Vis.currentAnimY = rcMe.top;
                
                // ^ Detect which edge to animate toward
                ScreenEdge edge = DetermineAnimationEdge(hwnd, rcMe.left, rcMe.top, w, h);
                g_Ctx.Vis.animEdge = edge;
                
                Wh_Log(L"[SHUTDOWN] Animating toward edge: %s", 
                       edge == ScreenEdge::TOP ? L"TOP" : edge == ScreenEdge::BOTTOM ? L"BOTTOM" : 
                       edge == ScreenEdge::LEFT ? L"LEFT" : L"RIGHT");
                g_Ctx.Vis.animState = 1; // STATE 1 = HIDING
                // Master Tick handles animation

                if (g_Ctx.Wnd.rainbow && g_Settings.enableRainbow) {
                    RECT rcRainbow; GetWindowRect(g_Ctx.Wnd.rainbow, &rcRainbow);
                    g_Ctx.Rainbow.currentAnimY = rcRainbow.top;
                    g_Ctx.Rainbow.animState = 1;
                }
            } else {
                if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
                DestroyWindow(hwnd);
            }
            return 0;
        }

        case WM_DESTROY: {
            Wh_Log(L"[SHUTDOWN] -- MediaWndProc WM_DESTROY");

            MSG queueMsg;
            while (PeekMessage(&queueMsg, hwnd, APP_WM_MEDIA_UPDATED, APP_WM_MEDIA_UPDATED, PM_REMOVE)) {
                auto* leakedPayload = reinterpret_cast<MediaUpdatePayload*>(queueMsg.lParam);
                if (leakedPayload) delete leakedPayload;
            }

            KillTimer(hwnd, IDT_MASTER_TICK);
            KillTimer(hwnd, IDT_POLL_MEDIA);
            Wh_Log(L"[SHUTDOWN] --All timers killed-- ");
            if (g_Ctx.Sys.isShutdown) {
                PostQuitMessage(0);
            }
            return 0;
        }

        case WM_WINDOWPOSCHANGED: {
            if (g_Ctx.Vis.animState != 0 || g_Ctx.Sys.isShutdown || g_Ctx.Vis.dockedMode != 0) break;
            RECT rc; GetWindowRect(hwnd, &rc);
            if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
                int bo = Scale(g_Settings.rainbowBorderOffset);
                SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(),
                             rc.left - bo, rc.top - bo,
                             (rc.right - rc.left) + bo * 2, (rc.bottom - rc.top) + bo * 2,
                             SWP_NOACTIVATE);
            }
            SaveWindowState(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
            InvalidateRect(hwnd, NULL, FALSE);
            break;
        }

        case WM_SETTINGCHANGE: {
            // | Log lParam as string if available, otherwise indicate NULL (helps identify which setting changed)
            Wh_Log(L"[SYSTEM] WM_SETTINGCHANGE received. lParam: %s", lParam ? (LPCWSTR)lParam : L"NULL"); // ! sDEBUG

            // DPI may have changed via global settings slider. compare to last cached value.
            UINT currentDpi = GetDpiForSystem();
            if (currentDpi == 0) currentDpi = 96;
            if (currentDpi != g_Ctx.Sys.lastSysDPI) {
                Wh_Log(L"[SYSTEM] DPI change detected: %u -> %u (via SETTINGCHANGE)", g_Ctx.Sys.lastSysDPI, currentDpi);
                UpdateScaleFactor(); // updates scaleFactor and lastSysDPI
                g_WindowManager.UpdateAppearance(hwnd);
                g_WindowManager.SyncPositionWithTaskbar();
                g_Ctx.Text.dirty = true;
                InvalidateRect(hwnd, NULL, TRUE);
            } else if (lParam && wcscmp((LPCWSTR)lParam, L"ImmersiveColorSet") == 0) {
                // theme/colour broadcast only
                g_WindowManager.UpdateAppearance(hwnd);
                g_Ctx.Text.dirty = true;
                InvalidateRect(hwnd, NULL, TRUE);
            }
            return 0;
        }

        case WM_DPICHANGED: { // todo: make work!
            UpdateScaleFactor();
            Wh_Log(L"WM_DPICHANGED: Scale factor updated to %.2f", g_Ctx.Sys.scaleFactor); // ! sDEBUG

            RECT* prcNew = reinterpret_cast<RECT*>(lParam);
            if (prcNew) {
                SetWindowPos(hwnd, GetMediaZOrderInsertAfter(), prcNew->left, prcNew->top,
                             prcNew->right - prcNew->left, prcNew->bottom - prcNew->top,
                             SWP_NOACTIVATE);
            }

            g_WindowManager.SyncPositionWithTaskbar();
            g_WindowManager.UpdateAppearance(hwnd);
            g_Ctx.Text.dirty = true;
            InvalidateRect(hwnd, NULL, TRUE);

            if (g_Ctx.Wnd.rainbow && IsWindow(g_Ctx.Wnd.rainbow)) {
                int scaledW = EffectiveW();
                int scaledH = EffectiveH();
                int borderOffset = Scale(g_Settings.rainbowBorderOffset);
                SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0, 0,
                             scaledW + (borderOffset * 2),
                             scaledH + (borderOffset * 2),
                             SWP_NOMOVE | SWP_NOACTIVATE);
                InvalidateRect(g_Ctx.Wnd.rainbow, NULL, TRUE);
            }
            return 0;
        }
        
        case WM_QUERYENDSESSION: {
            g_Ctx.Sys.isShutdown = true;
            return TRUE;
        }

        case WM_SETCURSOR: {
            POINT pt; GetCursorPos(&pt);
            ScreenToClient(hwnd, &pt);
            if (s_PhysicalToLogical && hwnd) {
                s_PhysicalToLogical(hwnd, &pt);
            } else {
                pt.x = (int)(pt.x / g_Ctx.Sys.scaleFactor);
                pt.y = (int)(pt.y / g_Ctx.Sys.scaleFactor);
            }
            auto L = GetLayout();
            int artRightEdge = L.artX + L.artSize + 5;
            SetCursor(LoadCursor(NULL, (pt.x < artRightEdge) ? IDC_ARROW : IDC_HAND));
            return TRUE;
        }

        case WM_USER + 101: {
            // Game detection removed
            Wh_Log(L"[ActionEngine] Game detection removed - no fullscreen triggers");
            return 0;
        }

        case WM_TIMER: {
            g_WindowManager.OnTimer(hwnd, wParam);
            return 0;
        }

        case WM_MOUSEMOVE: {
            int x = (int)(LOWORD(lParam) / g_Ctx.Sys.scaleFactor);
            int y = (int)(HIWORD(lParam) / g_Ctx.Sys.scaleFactor);

            auto L = GetLayout();

            int prevLeft = L.startControlX - L.hoverOffsetX, prevRight = prevLeft + L.hoverSize;
            int playLeft = (L.startControlX + L.controlSpacing) - L.hoverOffsetX, playRight = playLeft + L.hoverSize;
            int nextLeft = (L.startControlX + L.controlSpacing * 2) - L.hoverOffsetX, nextRight = nextLeft + L.hoverSize;
            int top = L.controlY - L.hoverOffsetY, bottom = top + L.hoverSize;

            int newState = 0;
            if (y >= top && y <= bottom) {
                if (x >= prevLeft && x < prevRight) newState = 1;
                else if (x >= playLeft && x < playRight) newState = 2;
                else if (x >= nextLeft && x < nextRight) newState = 3;
            }
            if (newState != g_Ctx.Vis.hoverState) {
                g_Ctx.Vis.hoverState = newState;
                InvalidateRect(hwnd, NULL, FALSE);
            }
            TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT), TME_LEAVE, hwnd, 0 };
            TrackMouseEvent(&tme);
            return 0;
        }
        case WM_MOUSELEAVE: { g_Ctx.Vis.hoverState = 0; InvalidateRect(hwnd, NULL, FALSE); break; }
        
        case WM_LBUTTONUP: {        // Left Button
            Wh_Log(L"[INPUT] WM_LBUTTONUP received | Sending to background click check with lParam: (%d, %d)", LOWORD(lParam), HIWORD(lParam));
            if (g_Ctx.Vis.hoverState >= 1 && g_Ctx.Vis.hoverState <= 3) {
                Wh_Log(L"[INPUT] WM_LBUTTONUP Clicked button state: %d", g_Ctx.Vis.hoverState);
                SendMediaCommand(g_Ctx.Vis.hoverState);
            } else if (IsClickOnBackground(lParam)) {
                OnTriggerEvent(L"Left");
            }
            return 0;
        }
        case WM_RBUTTONUP: {        // Right Button
            Wh_Log(L"[INPUT] WM_RBUTTONUP received | Sending to background click check with lParam: (%d, %d)", LOWORD(lParam), HIWORD(lParam));
            if (IsClickOnBackground(lParam)) {
                OnTriggerEvent(L"Right");
            }
            return 0;
        }
        case WM_MBUTTONUP: {        // Middle Button
            Wh_Log(L"[INPUT] WM_MBUTTONUP received | Sending to background click check with lParam: (%d, %d)", LOWORD(lParam), HIWORD(lParam));
            if (IsClickOnBackground(lParam)) {
                OnTriggerEvent(L"Middle");
            }
            return 0;
        }
        case WM_LBUTTONDBLCLK: {    // Left Button Double Click
            Wh_Log(L"[INPUT] WM_LBUTTONDBLCLK received | Sending to background click check with lParam: (%d, %d)", LOWORD(lParam), HIWORD(lParam));
            if (IsClickOnBackground(lParam)) {
                OnTriggerEvent(L"Double");
            }
            return 0;
        }
        case WM_MOUSEWHEEL: {       // Mouse Wheel
            Wh_Log(L"[INPUT] WM_MOUSEWHEEL received | Sending to background click check with lParam: (%d, %d)", LOWORD(lParam), HIWORD(lParam));
            g_WindowManager.OnMouseWheel(hwnd, wParam, lParam);
            return 0;
        }
            
        case WM_PAINT: {
            g_WindowManager.OnPaint(hwnd);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// ..        ------------------ End of Window Procedures ------------------        ..\\

// |-- Create Mod windows 
void CreateModWindows() {
    Wh_Log(L"[INIT] Creating mod windows...");
    
    // CRITICAL: Update DPI scaling BEFORE calculating window sizes
    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
        if (hUser32) {
            s_LogicalToPhysical = (pLogicalToPhysical)GetProcAddress(hUser32, "LogicalToPhysicalPointForPerMonitorDPI");
            s_PhysicalToLogical = (pPhysicalToLogical)GetProcAddress(hUser32, "PhysicalToLogicalPointForPerMonitorDPI");
        }
    
    UpdateScaleFactor();
    Wh_Log(L"[INIT] Scale factor ensured: %.2f", g_Ctx.Sys.scaleFactor);
    
    // Ensure taskbar handle
    g_WindowManager.GetTaskbar();

    int scaledW = Scale(g_Settings.width);
    int scaledH = Scale(g_Settings.height);
    int borderOffset = Scale(g_Settings.rainbowBorderOffset);
    
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // * ----------------------------------------Create Media Window----------------------------------------
    if (s_CreateWindowInBand) {
        g_Ctx.Wnd.main = s_CreateWindowInBand(      // .. MEDIA WINDOW
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
            TEXT("WindhawkMusicLounge_GSMTC"),
            TEXT("MusicLounge"),
            WS_POPUP,
            0, 0, scaledW, scaledH,
            NULL, NULL, hInstance, NULL,
            ZBID_IMMERSIVE_NOTIFICATION);
        
        if (!g_Ctx.Wnd.main) {
            Wh_Log(L"[INIT] CreateWindowInBand failed, falling back to CreateWindowEx");
        }
    }
    
    if (!g_Ctx.Wnd.main) {  // ! Fallback: either CreateWindowInBand unavailable OR it failed
        g_Ctx.Wnd.main = CreateWindowEx(    // | FALLBACK Meida Window
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
            TEXT("WindhawkMusicLounge_GSMTC"),
            TEXT("MusicLounge"),
            WS_POPUP,
            0, 0,
            scaledW,
            scaledH,
            NULL, NULL, hInstance, NULL);
    }

    if (g_Ctx.Wnd.main) {
        Wh_Log(L"[INIT] ================== Media window created: 0x%p", g_Ctx.Wnd.main);
    }

    // * ----------------------------------------Create Rainbow Window----------------------------------------
    int rainbowW = scaledW + (borderOffset * 2);
    int rainbowH = scaledH + (borderOffset * 2);

    if (s_CreateWindowInBand) {
        g_Ctx.Wnd.rainbow = s_CreateWindowInBand(       // ..RAINBOW WINDOW
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            TEXT("WindhawkMusicLounge_Rainbow"),
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            rainbowW,
            rainbowH,
            NULL, NULL, hInstance, NULL,
            ZBID_IMMERSIVE_NOTIFICATION);
    }
    
    if (!g_Ctx.Wnd.rainbow) {  // ! Fallback: either CreateWindowInBand unavailable OR it failed
        g_Ctx.Wnd.rainbow = CreateWindowEx(    // | FALLBACK Rainbow Window
            WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
            TEXT("WindhawkMusicLounge_Rainbow"),
            TEXT("MusicLoungeRainbow"),
            WS_POPUP,
            0, 0,
            rainbowW,
            rainbowH,
            NULL, NULL, hInstance, NULL);
    }
    
    if (g_Ctx.Wnd.rainbow) {
        Wh_Log(L"[INIT] ================== Rainbow window created: 0x%p", g_Ctx.Wnd.rainbow);
    }

    // Apply Attributes
    SetLayeredWindowAttributes(g_Ctx.Wnd.main, 0, static_cast<BYTE>(EffectiveOpacity()), LWA_ALPHA);
    
    // Rainbow uses UpdateLayeredWindow (per-pixel alpha) — SetLayeredWindowAttributes is incompatible and must NOT be called on it.
    
    g_WindowManager.UpdateAppearance(g_Ctx.Wnd.main);

    // Initial Position (Hidden - will show during first sync)
    g_Ctx.Vis.animState = 3; 
    g_WindowManager.SyncPositionWithTaskbar();

    // Windows remain hidden - SyncPositionWithTaskbar will show them
    // after position/scale calculations complete

    // Install Hook for visibility changes (e.g. fullscreen apps) - needs to be after window creation to avoid race condition where hook fires before main window handle is set
    if (!g_Ctx.Wnd.visibilityHook) {
        g_Ctx.Wnd.visibilityHook = SetWinEventHook(EVENT_OBJECT_LOCATIONCHANGE, EVENT_OBJECT_LOCATIONCHANGE, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);  // 
        if (g_Ctx.Wnd.visibilityHook) {
            Wh_Log(L"[INIT] WinEvent hook installed");
        }
    }
}

#pragma endregion  // ^ ----- Window Procedures -----

// ! ====================================================================================================================================================================================================

#pragma region // ^ MediaThread Cleanup

void CleanupMediaThread(const WNDCLASS& wc, const WNDCLASS& wcRainbow, bool winrtInitialized) {
    g_Ctx.Sys.eventHandlersActive = false;

    Wh_Log(L"[CLEANUP] Stopping registry auto-hide listener...");
    g_RegistryManager.StopAutoHideListener();

    if (g_Ctx.Wnd.visibilityHook) {
        UnhookWinEvent(g_Ctx.Wnd.visibilityHook);
        Wh_Log(L"[CLEANUP] WinEvent hook unhooked");
        g_Ctx.Wnd.visibilityHook = NULL;
    }
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    Wh_Log(L"[CLEANUP] Media window class unregistered");
    UnregisterClass(wcRainbow.lpszClassName, wcRainbow.hInstance);
    Wh_Log(L"[CLEANUP] Rainbow window class unregistered");
    // CRITICAL: Delete ALL GDI+ Bitmap objects BEFORE GdiplusShutdown
    // Deleting GDI+ objects after GdiplusShutdown hangs indefinitely
    {
        try {
            if (g_Ctx.Media.albumArt) {
                g_Ctx.Media.albumArt.reset();
                Wh_Log(L"[CLEANUP] Album art bitmap freed");
            }
        } catch (...) {
            Wh_Log(L"[WARNING] Exception freeing album art bitmap during cleanup");
        }
    }
    {
        try {
            if (g_Ctx.ArtCache.bgBitmap) {
                g_Ctx.ArtCache.bgBitmap.reset();
                Wh_Log(L"[CLEANUP] ArtCache bitmap freed");
            }
            if (g_Ctx.ArtCache.previousBgBitmap) {
                g_Ctx.ArtCache.previousBgBitmap.reset();
                Wh_Log(L"[CLEANUP] Previous ArtCache bitmap freed");
            }
            if (g_Ctx.ArtCache.previousAlbumArt) {
                g_Ctx.ArtCache.previousAlbumArt.reset();
                Wh_Log(L"[CLEANUP] Previous album art freed");
            }
            g_Ctx.ArtCache.palette.clear();
            g_Ctx.ArtCache.previousPalette.clear();
        } catch (...) {
            Wh_Log(L"[WARNING] Exception freeing ArtCache bitmap during cleanup");
        }
    }
    {
        try {
            if (g_Ctx.Text.stripBitmap) {
                g_Ctx.Text.stripBitmap.reset();
                Wh_Log(L"[CLEANUP] Text cache bitmap freed");
            }
        } catch (...) {
            Wh_Log(L"[WARNING] Exception freeing text cache bitmap during cleanup");
        }
    }
    if (g_Ctx.Sys.gdiplusToken) {
        GdiplusShutdown(g_Ctx.Sys.gdiplusToken);
        Wh_Log(L"[CLEANUP] GDI+ shutdown completed");
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

    if (g_audioCOM.IsInitialized()) {
        Wh_Log(L"[CLEANUP] Shutting down audio COM...");
        g_audioCOM.Uninit();
    }

    if (winrtInitialized) {
        winrt::uninit_apartment();
        Wh_Log(L"[CLEANUP] WinRT apartment uninitialized");
    }
    Wh_Log(L"[CLEANUP] MediaThread exiting");
}

#pragma endregion // MediaThread Cleanup

// ! ===================================================================================================================================================================================================

#pragma region // ^ Media Thread
// | Media widget thread - runs in dedicated process via tool mod and manages the media window's lifecycle, including creation, message loop, and destruction. This separation allows for more robust handling of media-related resources and ensures that the media widget remains responsive even if the main process encounters issues.
void MediaThread() {
    Wh_Log(L"[MEDIA] ------ Media Thread Initiated -----   [ThreadID: %u]", GetCurrentThreadId());

    if (FAILED(SetCurrentProcessExplicitAppUserModelID(L"taskbar-music-lounge-fork"))) {
        Wh_Log(L"[WARNING] SetCurrentProcessExplicitAppUserModelID failed (non-critical)");
    }



    // --- DPI Awareness ---
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    Wh_Log(L"[INIT] DPI awareness set");

    // --- WinRT Initialization (required for GSMTC media control) ---
    bool winrtInitialized = false;
    try {
        winrt::init_apartment();
        winrtInitialized = true;
        Wh_Log(L"[INIT] WinRT apartment initialized");
    } catch (...) {
        Wh_Log(L"[ERROR] Failed to initialize WinRT apartment");
        return;
    }

    // Initialize Audio COM first so settings can enable meter at startup
    const bool audioComOk = g_audioCOM.Init();
    if (!audioComOk) {
        Wh_Log(L"[WARNING] Audio COM initialization failed (audio reactive disabled)");
    } else {
        Wh_Log(L"[AUDIO] Audio COM initialized");
    }

    Wh_Log(L"[INIT] Loading Settings...");
    LoadSettings();
    Wh_Log(L"[INIT] Settings loaded");

    if (!audioComOk) {
        g_Settings.audioHueReactiveMode = 0;
    } else if (g_Settings.audioHueReactiveMode > 0 && !g_audioCOM.InitMeter()) {
        Wh_Log(L"[WARNING] Audio meter initialization failed (audio reactive disabled)");
        g_Settings.audioHueReactiveMode = 0;
    }

    // CRITICAL: Initialize DPI scaling FIRST (independent of taskbar)
    UpdateScaleFactor();
    if (g_Ctx.Sys.scaleFactor <= 0.0f) {
        Wh_Log(L"[ERROR] Failed to initialize DPI scale factor");
        if (g_audioCOM.IsInitialized()) {
            g_audioCOM.Uninit();
        }
        if (winrtInitialized) {
            winrt::uninit_apartment();
            Wh_Log(L"WinRT apartment uninitialized");
        }
        return;
    }
    Wh_Log(L"[INIT] Scale factor initialized to %.2f", g_Ctx.Sys.scaleFactor);

    // --- Registry Auto-Hide Listener ---
    g_RegistryManager.StartAutoHideListener([]() {
        // Game detection removed
        g_WindowManager.SyncPositionWithTaskbar();
    });

    // --- GDI+ Initialization (required for rendering) ---
    GdiplusStartupInput gdiplusStartupInput;
    if (GdiplusStartup(&g_Ctx.Sys.gdiplusToken, &gdiplusStartupInput, NULL) != Ok) {
        Wh_Log(L"[ERROR] GDI+ initialization failed");
        g_RegistryManager.StopAutoHideListener();
        if (g_audioCOM.IsInitialized()) {
            g_audioCOM.Uninit();
        }
        if (winrtInitialized) {
            winrt::uninit_apartment();
            Wh_Log(L"[CLEANUP] WinRT apartment uninitialized");
        }
        return;
    }
    Wh_Log(L"[GDI+] GDI+ initialized");
    
    // WAITING FOR TASKBAR (Fix for Startup Race Condition)
    // Explorer might be slow to start, so we must wait for Shell_TrayWnd
    Wh_Log(L"[INIT] Waiting for Taskbar...");
    int waitRetries = 0;
    const int maxRetries = 50; // 5 seconds max wait
    while (!FindWindow(L"Shell_TrayWnd", NULL) && waitRetries < maxRetries && g_Ctx.Sys.isRunning) {
        Sleep(100);
        waitRetries++;
    }

    if (waitRetries >= maxRetries) {
        Wh_Log(L"[WARNING] Taskbar not found after 5 seconds - proceeding anyway (may fail to dock)");
    } else {
        Wh_Log(L"[INIT] Taskbar found after %d ms", waitRetries * 100);
    }
    
    // ENSURE TASKBAR HANDLE is available
    g_WindowManager.GetTaskbar();
    Wh_Log(L"[INIT] Taskbar handle ensured");
    WNDCLASS wc = {0};
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = MediaWndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("WindhawkMusicLounge_GSMTC");
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    RegisterClass(&wc);
    Wh_Log(L"[INIT] Media window class registered");

    // Register rainbow window class
    WNDCLASS wcRainbow = {0};
    wcRainbow.lpfnWndProc = RainbowWndProc;
    wcRainbow.hInstance = GetModuleHandle(NULL);
    wcRainbow.lpszClassName = TEXT("WindhawkMusicLounge_Rainbow");
    wcRainbow.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wcRainbow);
    Wh_Log(L"[INIT] Rainbow window class registered");

    // Grab CreateWindowInBand if available (Windows 11 22H2+) - it ensures proper z-ordering with the taskbar | Used by: CreateModWindow
    HMODULE hUser32 = GetModuleHandle(L"user32.dll");
    s_CreateWindowInBand = (pCreateWindowInBand)GetProcAddress(hUser32, "CreateWindowInBand");
    if (s_CreateWindowInBand) {
        Wh_Log(L"[INIT] -- CreateWindowInBand");
    } else {
        Wh_Log(L"[INIT] -- CreateWindowInBand API not available, will use CreateWindowEx fallback  (NOTE: Because of this you'll have Taskbar Z-Order fighting!)");
    }

    CreateModWindows(); // Use consolidated window creation helper

    // Enable event handlers BEFORE GSMTC init so initial fetch works
    g_Ctx.Sys.eventHandlersActive = true;
    Wh_Log(L"[INIT] Event handlers activated - media updates now event-driven");

    // Initialize GSMTC session manager and cache current session
    try {
        g_SessionManager = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
        if (g_SessionManager) {
            Wh_Log(L"[GSMTC] Session manager acquired");
            
            // Cache initial session
            g_CachedSession = g_SessionManager.GetCurrentSession();
            if (g_CachedSession) {
                Wh_Log(L"[GSMTC] Initial session cached");
            } else {
                Wh_Log(L"[GSMTC] No initial session available");
            }
            
            // Register session change event handler and store token for unsubscription
            g_sessionChangedToken = g_SessionManager.CurrentSessionChanged([](auto&&, auto&&) {
                if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                
try {
                auto oldSession = g_CachedSession;
                g_CachedSession = g_SessionManager.GetCurrentSession();

                if (g_CachedSession) {
                    Wh_Log(L"[MusicLounge] Session changed - new session cached");

                    // Unsubscribe old handlers before registering new ones
                    if (oldSession) {
                        try {
                            if (g_playbackInfoToken) oldSession.PlaybackInfoChanged(g_playbackInfoToken);
                            if (g_mediaPropertiesToken) oldSession.MediaPropertiesChanged(g_mediaPropertiesToken);
                        } catch (...) { }
                    }
                    g_playbackInfoToken = winrt::event_token{};
                    g_mediaPropertiesToken = winrt::event_token{};
                        
                        // Re-register event handlers for the new session and store tokens
                        g_playbackInfoToken = g_CachedSession.PlaybackInfoChanged([](auto&&, auto&&) {
                            if (!g_Ctx.Sys.eventHandlersActive.load()) return;
                            HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                            if (!localWindow || !IsWindow(localWindow)) return;
                            Wh_Log(L"[GSMTC] PlaybackInfoChanged event fired");
                            UpdateMediaInfoAsync();
                            InvalidateRect(localWindow, NULL, FALSE);
                        });
                        
                        g_mediaPropertiesToken = g_CachedSession.MediaPropertiesChanged([](auto&&, auto&&) {
                            if (!g_Ctx.Sys.eventHandlersActive.load()) return;
                            HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                            if (!localWindow || !IsWindow(localWindow)) return;
                            Wh_Log(L"[GSMTC] MediaPropertiesChanged event fired");
                            UpdateMediaInfoAsync();
                            InvalidateRect(localWindow, NULL, FALSE);
                        });
                        
                        Wh_Log(L"[INFO] Event handlers re-registered for new session");
                    } else {
                        Wh_Log(L"[MusicLounge] Session gone - clearing media state");
                        // Post clear to MediaThread via message-passing
                        if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
                            auto* payload = new MediaUpdatePayload();
                            payload->hasMedia = false;
                            payload->title = L"No Media";
                            payload->artist = L"";
                            payload->sourceId = L"";
                            PostMessage(g_Ctx.Wnd.main, APP_WM_MEDIA_UPDATED, 0, reinterpret_cast<LPARAM>(payload));
                        }
                    }
                    
                    HWND localWindow = g_Ctx.Wnd.main;
                    if (localWindow && IsWindow(localWindow)) {
                        if (g_CachedSession) {
                            UpdateMediaInfoAsync();
                        }
                        InvalidateRect(localWindow, NULL, FALSE);
                    }
                } catch (...) {
                    Wh_Log(L"[ERROR] Exception in session change handler");
                }
            });
            Wh_Log(L"[GSMTC] Session change event handler registered");
            
            // Register event handlers for instant state updates and store tokens
            if (g_CachedSession) {
                // Playback state changes (play/pause/position) - store token
                g_playbackInfoToken = g_CachedSession.PlaybackInfoChanged([](auto&&, auto&&) {
                    if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                    HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot (safe even if window destroyed mid-check)
                    if (!localWindow || !IsWindow(localWindow)) return;
                    
                    Wh_Log(L"[GSMTC] PlaybackInfoChanged event fired");
                    UpdateMediaInfoAsync();
                    InvalidateRect(localWindow, NULL, FALSE);
                });
                Wh_Log(L"[GSMTC] PlaybackInfoChanged event handler registered");
                
                // Media properties changes (title/artist/artwork) - store token
                g_mediaPropertiesToken = g_CachedSession.MediaPropertiesChanged([](auto&&, auto&&) {
                    if (!g_Ctx.Sys.eventHandlersActive.load()) return;  // Fast exit if shutting down
                    HWND localWindow = g_Ctx.Wnd.main;  // Atomic snapshot
                    if (!localWindow || !IsWindow(localWindow)) return;
                    
                    Wh_Log(L"[GSMTC] MediaPropertiesChanged event fired");
                    UpdateMediaInfoAsync();
                    InvalidateRect(localWindow, NULL, FALSE);
                });
                Wh_Log(L"[GSMTC] Media properties change event handler registered");
                
                // Fetch initial state now that handlers are ready
                Wh_Log(L"[GSMTC] Fetching initial media state...");
                UpdateMediaInfoAsync();
            }
        } else {
            Wh_Log(L"[GSMTC] WARNING: Failed to acquire GSMTC session manager");
        }
    } catch (const std::exception& e) {
        Wh_Log(L"[GSMTC] ERROR: Exception during GSMTC initialization");
    } catch (...) {
        Wh_Log(L"[GSMTC] ERROR: Unknown exception during GSMTC initialization");
    }

    Wh_Log(L"[MEDIA] MediaThread entering message loop");

    // [DIAGNOSTIC] Log thread start to persistent file
    // {
    //     wchar_t tempPath[MAX_PATH];
    //     GetTempPathW(MAX_PATH, tempPath);
    //     std::wstring fullPath = std::wstring(tempPath) + L"MusicLounge_Boot.log";
        
    //     std::wofstream logFile(fullPath.c_str(), std::ios::app);
    //     if (logFile.is_open()) {
    //          SYSTEMTIME st; GetLocalTime(&st);
    //          logFile << L"[" << st.wHour << L":" << st.wMinute << L":" << st.wSecond << L"." << st.wMilliseconds << L"] " 
    //                  << L"MediaThread ENTERING MESSAGE LOOP [ThreadID: " << GetCurrentThreadId() << L"]" << std::endl;
    //     }
    // }

    // ALL 
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    Wh_Log(L"[CLEANUP] --MediaThread exiting message loop--");
    CleanupMediaThread(wc, wcRainbow, winrtInitialized);
}

std::thread* g_pMediaThread = nullptr;

#pragma endregion  // ^ Media Thread

// ! ===================================================================================================================================================================================================

#pragma region // ^ Windhawk Callbacks

BOOL WhTool_ModInit() {
    Wh_Log(L" ------ START ------   [ThreadID: %u]", GetCurrentThreadId());
    Wh_Log(L" Init " WH_MOD_ID L" version " WH_MOD_VERSION);

    g_Ctx.Reset(RESET_ALL);
    
    if (!g_pMediaThread) {
        try {
            g_pMediaThread = new std::thread(MediaThread);
        } catch (const std::exception&) {
            Wh_Log(L"[ERROR] Failed to create media thread");
            g_pMediaThread = nullptr;
            return FALSE;
        }
    } else {
        Wh_Log(L"[WARNING] Media thread already exists");
    }
    
    // --- [DIAGNOSTIC TEST] Persistent Log ---
    // This logs to user temp to survive reboot visibility gap.
    // auto LogToFile = [](const wchar_t* msg) {
    //     wchar_t tempPath[MAX_PATH];
    //     GetTempPathW(MAX_PATH, tempPath);
    //     std::wstring fullPath = std::wstring(tempPath) + L"MusicLounge_Boot.log";

    //     std::wofstream logFile(fullPath.c_str(), std::ios::app);
    //     if (logFile.is_open()) {
    //         SYSTEMTIME st; GetLocalTime(&st);
    //         logFile << L"[" << st.wHour << L":" << st.wMinute << L":" << st.wSecond << L"." << st.wMilliseconds << L"] " 
    //                 << msg << L" [ThreadID: " << GetCurrentThreadId() << L"]" << std::endl;
    //     }
    // };
    // LogToFile(L"=== WhTool_ModInit COMPLETED ===");
    // ----------------------------------------

    // Wh_Log(L" ---Init complete");
    return TRUE;
}

void WhTool_ModUninit() {
    Wh_Log(L"[UNINIT] ----- Cleanup Inititiated -----   [ThreadID: %u]", GetCurrentThreadId());
    
    // Disable event handlers FIRST to prevent race conditions
    g_Ctx.Sys.eventHandlersActive = false;
    Wh_Log(L"[UNINIT] Event handlers deactivated");
    
    // Signal shutdown to all threads
    g_Ctx.Sys.isRunning = false;
    g_Ctx.Sys.isShutdown = true;
    
    // Post close message to media window to trigger slide-out animation
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[UNINIT] Posting APP_WM_CLOSE to media window (will animate if enabled)...");
        PostMessage(g_Ctx.Wnd.main, APP_WM_CLOSE, 0, 0);
    }
    
    // Wait for media thread to exit (it will destroy its own windows)
    if (g_pMediaThread) {
        Wh_Log(L"[UNINIT] Waiting for media thread to exit...");
        if (g_pMediaThread->joinable()) {
            g_pMediaThread->join();
        }
        delete g_pMediaThread;
        g_pMediaThread = nullptr;
        Wh_Log(L"[UNINIT] Media thread joined");
    }
    
    // Reset all context state (bitmaps already freed by CleanupMediaThread)
    g_Ctx.Reset(RESET_ALL);
    g_Ctx.Audio.runtimeEnabled = true;
    g_Ctx.Sys.gdiplusToken = 0;
    
    // Clear action dispatcher state
    g_ActionDispatcher.ClearPendingActions();
    g_ActionDispatcher.triggers.clear();
    
    Wh_Log(L"[UNINIT] Cleanup complete, exiting");
    Wh_Log(L" ------ END ------   [ThreadID: %u]", GetCurrentThreadId());
}

void WhTool_ModSettingsChanged() {
    Wh_Log(L"[SETTINGS] --- CHANGE EVENT TRIGGERED ---  [ThreadID: %u]", GetCurrentThreadId());
    // UINT testdpi = GetDpiForSystem();
    Wh_Log(L"Testing GetDpiForSystem(): %.2f", g_Ctx.Sys.scaleFactor);  // !sDEBUG


    // Persist current window rect before reload
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        RECT rc; GetWindowRect(g_Ctx.Wnd.main, &rc);
        SaveWindowState(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
    }
    
    // CRITICAL: Pause any live animation timers
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[SETTINGS] Killing media window timers...");
        KillTimer(g_Ctx.Wnd.main, IDT_POLL_MEDIA);
        // ! Note: We DO NOT kill IDT_MASTER_TICK. It must survive settings changes.    // ^ test
        Wh_Log(L"[SETTINGS] Media window timers killed");
        
        // RESET STATES to prevent lockups or stuck timers
        g_Ctx.Text.isScrolling = false;
        g_Ctx.Text.dirty = true;
        // Preserve docked state: only reset animState if not user-docked
        if (g_Ctx.Vis.dockedMode == 0) {
            g_Ctx.Vis.animState = 0;      // Forces SyncPositionWithTaskbar to act
        }
    }
    
    g_Ctx.Rainbow.animState = 0;
    
    // Reload settings
    Wh_Log(L"[SETTINGS] Loading settings...");
    LoadSettings();
    Wh_Log(L"[SETTINGS] Settings loaded");
    g_Ctx.Text.dirty = true;
    
    // did the user change anything that affects our layout?
    bool widthChanged  = g_Ctx.Persisted.lastSettingsW != g_Settings.width;
    bool heightChanged = g_Ctx.Persisted.lastSettingsH != g_Settings.height;
    bool offsetXChanged = g_Ctx.Persisted.lastOffsetX != g_Settings.offsetX;
    bool offsetYChanged = g_Ctx.Persisted.lastOffsetY != g_Settings.offsetY;

    if (widthChanged || heightChanged || offsetXChanged || offsetYChanged) {
        Wh_Log(L"[SETTINGS] Layout change detected (w=%d h=%d ox=%d oy=%d)",
               widthChanged, heightChanged, offsetXChanged, offsetYChanged);

        // size‑related values – drop stored size so SyncPosition can re‑compute
        if (widthChanged) {
            Wh_DeleteValue(L"LastW");
            Wh_DeleteValue(L"LastSettingsW");
        }
        if (heightChanged) {
            Wh_DeleteValue(L"LastH");
            Wh_DeleteValue(L"LastSettingsH");
            // panel height tweak invalidates any previously‑saved Y offset
            Wh_DeleteValue(L"LastOffsetY");
        }

        // maintain horizontal offset unless it was explicitly changed
        if (offsetXChanged) {
            Wh_DeleteValue(L"LastOffsetX");
        }
        // if Y offset was altered by the user (and not already cleared above) clear it
        if (offsetYChanged && !heightChanged) {
            Wh_DeleteValue(L"LastOffsetY");
        }

        // whenever the widget’s size changes, also forget its absolute position –
        // it will be re‑docked by SyncPositionWithTaskbar after reload.
        if (widthChanged || heightChanged) {
            Wh_DeleteValue(L"LastX");
            Wh_DeleteValue(L"LastY");
        }
    }
    
    // Refresh DPI scaling in case system DPI changed
    UpdateScaleFactor();
    Wh_Log(L"[SETTINGS] Scale factor updated to %.2f", g_Ctx.Sys.scaleFactor);
    
    // Reapply appearance
    if (g_Ctx.Wnd.main && IsWindow(g_Ctx.Wnd.main)) {
        Wh_Log(L"[SETTINGS] Updating media window appearance...");
        g_WindowManager.UpdateAppearance(g_Ctx.Wnd.main);

        // Update timers (game detect, idle poll)
        SetupMediaWindowTimers();

        // If idle timeout was just enabled and music is paused, apply immediately  
        // But only if media state has been initialized (avoids race condition)
        if (g_Settings.idleTimeout > 0 && g_Ctx.Vis.mediaStateInitialized && !g_Ctx.Media.isPlaying) {
            g_Ctx.Vis.isHiddenByIdle = true;
            Wh_Log(L"[SETTINGS] Music already paused - applying idle timeout immediately");
        } else if (g_Settings.idleTimeout == 0) {
            // Idle timeout disabled - clear idle state
            g_Ctx.Vis.isHiddenByIdle = false;
            g_Ctx.Vis.idleSecondsCounter = 0;
            Wh_Log(L"[SETTINGS] Idle timeout disabled - clearing idle state");
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
        ApplyCornerPreference(g_Ctx.Wnd.rainbow, g_Settings.enableRoundedCorners);

        if (g_Ctx.Wnd.main && g_Settings.enableRainbow) {
            SetWindowPos(g_Ctx.Wnd.rainbow, GetRainbowZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            SetWindowPos(g_Ctx.Wnd.main, GetMediaZOrderInsertAfter(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
            Wh_Log(L"[SETTINGS] Z-order adjusted");
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
            ShowWindow(g_Ctx.Wnd.rainbow, SW_SHOWNOACTIVATE);
            Wh_Log(L"[SETTINGS] Rainbow window shown");
        } else {
            ShowWindow(g_Ctx.Wnd.rainbow, SW_HIDE);
            Wh_Log(L"[SETTINGS] Rainbow disabled, window hidden");
        }
    }
    
    Wh_Log(L"[SETTINGS] Settings reload complete");
}

// ! ====================================================================

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
    Wh_Log(L" --- Tool Mod Inititiated ---   [ThreadID: %u]", GetCurrentThreadId());

    ExitThread(0);
}

BOOL Wh_ModInit() {
    bool isExcluded = false;
    bool isToolModProcess = false;
    bool isCurrentToolModProcess = false;
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
    if (!argv) {
        Wh_Log(L"CommandLineToArgvW failed");
        return FALSE;
    }

    for (int i = 1; i < argc; i++) {
        if (wcscmp(argv[i], L"-service") == 0 ||
            wcscmp(argv[i], L"-service-start") == 0 ||
            wcscmp(argv[i], L"-service-stop") == 0) {
            isExcluded = true;
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

    if (isExcluded) {
        return FALSE;
    }

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex =
            CreateMutex(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex) {
            Wh_Log(L"[CreateMutex] ERROR: Failed to create mutex for tool mod process (%s): %u", WH_MOD_ID, GetLastError());
            ExitProcess(1);
        }

        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            Wh_Log(L"[CreateMutex] INFO: Tool mod already running (%s)", WH_MOD_ID);
            ExitProcess(1);
        }
        else if (GetLastError() != 0 && GetLastError() != ERROR_ALREADY_EXISTS) {     // ! DEBUG | Check for unexpected errors (besides already exists) to improve reliability and debugging
            Wh_Log(L"[CreateMutex] ERROR: %u", GetLastError());
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
            Wh_Log(L" [GetModuleFileName] ERROR: Failed to get module file name: %u", GetLastError());
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
            Wh_Log(L" [GetModuleHandle] ERROR: No kernelbase.dll/kernel32.dll");
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
        Wh_Log(L" [GetProcAddress] ERROR: No CreateProcessInternalW");
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
        Wh_Log(L" [CreateProcessInternalW] ERROR: CreateProcess failed: %u", GetLastError());
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

#pragma endregion // ^ Windhawk Callbacks