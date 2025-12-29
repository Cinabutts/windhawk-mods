#Requires AutoHotkey v2.0+
#SingleInstance Force
#WinActivateForce
global modName := A_Args.Length ? A_Args[1] : ""
global modName := RegExReplace(modName, "\.wh$", "")
global windhawkExe := "C:\\Program Files\\Windhawk\\windhawk.exe"
WindhawkAutoStart()

WindhawkAutoStart() {
    global ColdStart
    if !WinExist("ahk_exe VSCodium.exe") {
        if FileExist(windhawkExe) {
            Run('"' windhawkExe '" --settings')
            ColdStart := 1
        } else {
            MsgBox("Windhawk UI executable not found at: " windhawkExe, "Error", "T5")
            ExitApp
        }
    }
}
;^ - Focus on Searchbox
; Wait for Windhawk UI (VSCodium) to exist, then focus it
WinWait("ahk_exe VSCodium.exe", , 10)
if WinExist("ahk_exe VSCodium.exe") {
    ; Sleep 3000
    try {
        WinRestore()
        WinActivate()
    }
    Sleep 1500
    CBeep("C")
    ; Sleep 1250
}
SleepTab()
SleepTab()
SleepTab()
SleepTab()
SleepTab()
Sleep 500

;$ - Paste mod name into the "Mod Name" field
if (modName != "") {
    CBeep("A")
    oldClip := A_Clipboard
    A_Clipboard := modName
    ClipWait(1)
    Send "^v"
    Sleep 100
    A_Clipboard := oldClip
}

;^ - Click "Details" button
Sleep 300
SleepTab()
SleepTab()
SleepTab()
Send "{Enter}"
Sleep 500

;* - Click "Compile" button
SleepTab()
SleepTab()
Send "{Enter}"

;~=============================================================
CBeep(wSound) {
    switch wSound {
        case "A":
        {
            ; ascending scale
            SoundBeep(440, 80)   ; A4
            SoundBeep(554, 80)   ; C#5
            SoundBeep(659, 80)   ; E5
            SoundBeep(880, 150)  ; A5
        }
        case "B":
        {
            ; descending scale
            SoundBeep(880, 80)  ; A5
            SoundBeep(659, 80)   ; E5
            SoundBeep(554, 80)   ; C#5
            SoundBeep(440, 150)   ; A4
        }
        case "C":
        {
            ; 8-bit chime
            SoundBeep(523, 100)  ; C
            SoundBeep(659, 95)  ; E
            SoundBeep(784, 90)  ; G
            Sleep 10
            SoundBeep(500, 300) ; GO!
            Sleep 300
        }
    }
}

SleepTab() {
    SoundBeep(5000, 100)
    Send "{Tab}"
    Sleep 125
}
Esc:: ExitApp
CBeep("B")
ExitApp