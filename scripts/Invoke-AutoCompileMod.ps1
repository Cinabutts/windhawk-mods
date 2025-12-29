param(
    [Parameter(Mandatory = $true)]
    [string]$FileName,

    [Parameter(Mandatory = $true)]
    [string]$ModName
)

if (-not $FileName.EndsWith('.wh.cpp')) {
    Write-Host 'Error: Not a .wh.cpp file' -ForegroundColor Red
    exit 1
}

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ahkPath = Join-Path $scriptDir 'Auto-Compile-Mod.ahk'

if (-not (Test-Path $ahkPath)) {
    Write-Host ('Error: Auto-Compile-Mod.ahk not found at ' + $ahkPath) -ForegroundColor Red
    exit 1
}

Start-Process -FilePath $ahkPath -ArgumentList $ModName
