param(
    [Parameter(Mandatory=$true)]
    [string]$FilePath,

    [Parameter(Mandatory=$true)]
    [string]$FileName,

    [Parameter(Mandatory=$true)]
    [string]$ModTitle,

    [string]$OutputDir = "Testing"
)

$ErrorActionPreference = "Stop"

# Ensure upstream remote exists
$hasUpstream = git remote | Select-String -Pattern '^upstream$'
if (-not $hasUpstream) {
    throw "Upstream remote 'upstream' not found. Add it: git remote add upstream https://github.com/ramensoftware/windhawk-mods.git"
}

# Verify upstream/main ref exists
$refCheck = git rev-parse --verify upstream/main 2>$null
if ($LASTEXITCODE -ne 0) {
    throw "Cannot find ref 'upstream/main'. Fetch it: git fetch upstream main"
}

$modId = $FileName -replace '\.wh\.cpp$', ''
$changelogPath = Join-Path $OutputDir "$modId-changelog.txt"

if (-not (Test-Path $OutputDir)) {
    New-Item -ItemType Directory -Path $OutputDir | Out-Null
}

# Check if the mod exists in upstream/main (determines if this is an update)
$modExists = $true
try {
    git cat-file -e "upstream/main:$FilePath" 2>$null
} catch {
    $modExists = $false
}

if (-not $modExists) {
    Write-Output ([pscustomobject]@{
        IsNew = $true
        Summary = $null
        ChangelogPath = $null
    })
    return
}

$diffStat = git diff upstream/main --stat -- $FilePath
$diffStatClean = $diffStat.Trim()
if (-not $diffStatClean) {
    $diffStatClean = "No changes detected against upstream/main (unexpected)."
}

$diffPatch = git diff upstream/main -- $FilePath

$summary = "Changelog: $diffStatClean"

$body = @"
Mod: $ModTitle
File: $FilePath
Base: upstream/main
Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss zzz')

Diffstat:
$diffStatClean

Patch:
$diffPatch
"@

Set-Content -Path $changelogPath -Value $body

Write-Output ([pscustomobject]@{
    IsNew = $false
    Summary = $summary
    ChangelogPath = (Resolve-Path $changelogPath).Path
})
