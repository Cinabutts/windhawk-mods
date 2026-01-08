param(
    [Parameter(Mandatory = $true)]
    [string]$Command,

    [string]$WorkingDirectory = (Get-Location).Path
)

function Test-IsAdmin {
    try {
        $current = [Security.Principal.WindowsIdentity]::GetCurrent()
        $principal = New-Object Security.Principal.WindowsPrincipal($current)
        return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
    } catch {
        return $false
    }
}

if (-not (Test-IsAdmin)) {
    # Relaunch elevated with the same parameters
    $escapedCommand = $Command.Replace('`', '``').Replace('"', '\"')
    $escapedWd = $WorkingDirectory.Replace('`', '``').Replace('"', '\"')

    Start-Process -FilePath "powershell.exe" -Verb RunAs -ArgumentList @(
        "-NoProfile",
        "-ExecutionPolicy", "Bypass",
        "-File", "`"$PSCommandPath`"",
        "-Command", "`"$escapedCommand`"",
        "-WorkingDirectory", "`"$escapedWd`""
    ) | Out-Null
    exit 0
}

# Already elevated
Set-Location $WorkingDirectory

try {
    Invoke-Expression $Command
    $exitCode = $LASTEXITCODE
} catch {
    Write-Error $_
    $exitCode = 1
}

exit $exitCode
