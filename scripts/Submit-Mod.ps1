# Submit Mod - Prepares a single mod for PR submission
# This script will:
#   1. Create or update a submission branch
#   2. Handle both new mods and updates
#   3. Commit with proper message format
#   4. Push to your fork for PR creation
# 
# Your main branch stays clean (synced with upstream)
# Your Testing branch is unchanged
# A feature branch is created/updated with your mod
#
# You must be in the Testing branch when running this task.

param(
    [Parameter(Mandatory=$true)]
    [string]$FilePath,
    
    [Parameter(Mandatory=$true)]
    [string]$FileName,
    
    [Parameter(Mandatory=$false)]
    [int]$DebugLevel = 2  # 0=off, 1=phase level, 2=every step
)

# Allow external programs (git) to write to stderr without crashing PowerShell
$ErrorActionPreference = "Stop"
if ($PSVersionTable.PSVersion.Major -ge 7) {
    $PSNativeCommandUseErrorActionPreference = $false
}

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path

# DEBUG: Helper function for phase-level debug messages (Debug level 1+)
function Write-Debug-Phase {
    param([string]$Message)
    if ($DebugLevel -ge 1) {
        Write-Host "[DEBUG-PHASE] $Message" -ForegroundColor Gray
    }
}

# DEBUG: Helper function for step-level debug messages (Debug level 2 only)
function Write-Debug-Step {
    param([string]$Message)
    if ($DebugLevel -eq 2) {
        Write-Host "[DEBUG-STEP] $Message" -ForegroundColor DarkGray
    }
}

# Helper function to extract version from mod file
function Get-ModVersion {
    param([string]$FilePath)
    
    $content = Get-Content $FilePath -Raw
    if ($content -match '@version\s+(\d+\.\d+\.\d+)') {
        return $Matches[1]
    }
    return $null
}

# Helper function to center text
function Get-CenteredText {
    param([string]$Text, [int]$Width = 80)
    
    $padding = [Math]::Max(0, ($Width - $Text.Length) / 2)
    return (' ' * $padding) + $Text
}

# ============================================================================
# PHASE 1: INITIAL VALIDATION
# ============================================================================
Write-Debug-Phase "Starting Phase 1: Initial Validation"

# Check if we're in main branch - abort if so
Write-Debug-Step "Checking current branch..."
$currentBranch = git branch --show-current
Write-Debug-Step "Current branch: $currentBranch"

if ($currentBranch -eq "main") {
    Write-Host "Error: Cannot run from main branch. Switch to a different branch first." -ForegroundColor Red
    exit 1
}
Write-Debug-Step "Not in main branch - OK"

# Validate it's a .wh.cpp file
Write-Debug-Step "Validating filename format: $FileName"
if ($FileName -notmatch '^(.+)\.wh\.cpp$') {
    Write-Host "Error: Not a .wh.cpp file: $FileName" -ForegroundColor Red
    exit 1
}
Write-Debug-Step "Filename validation passed"

$modId = $Matches[1]
$relativeFilePath = "mods/$FileName"
Write-Debug-Step "ModId extracted: $modId"
Write-Debug-Step "Relative file path: $relativeFilePath"

# Convert mod-id to nice title
Write-Debug-Step "Converting mod ID to title format"
$modTitle = (($modId -replace '-', ' ' -replace '_', ' ').Split(' ') | ForEach-Object { 
    if ($_.Length -gt 0) {
        $_.Substring(0,1).ToUpper() + $_.Substring(1).ToLower() 
    }
} | Where-Object { $_ }) -join ' '
Write-Debug-Step "Mod title: $modTitle"

$branchName = $modId

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "MOD SUBMISSION WORKFLOW" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "`nThis task will:" -ForegroundColor Yellow
Write-Host "  1. Update your main branch from upstream/main" -ForegroundColor White
Write-Host "  2. Create/update submission branch: '$branchName'" -ForegroundColor White
Write-Host "  3. Copy your mod file to the branch" -ForegroundColor White
Write-Host "  4. Ask for commit title and description" -ForegroundColor White
Write-Host "  5. Commit and push to your fork" -ForegroundColor White
Write-Host "  6. Return you to Testing branch" -ForegroundColor White
Write-Host "`nResult:" -ForegroundColor Yellow
Write-Host "  - Your main branch: UNCHANGED (clean, synced with upstream)" -ForegroundColor Green
Write-Host "  - Your Testing branch: UNCHANGED (still has all your work)" -ForegroundColor Green
Write-Host "  - Branch created/updated: '$branchName' (ready for PR)" -ForegroundColor Green
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "Mod: $modTitle" -ForegroundColor White
Write-Host "File: $relativeFilePath" -ForegroundColor White
Write-Host "========================================`n" -ForegroundColor Cyan

Write-Debug-Step "Waiting for user confirmation..."
$confirm = Read-Host "Ready to proceed? (type 'yes' to continue)"
if ($confirm -ne "yes" -and $confirm -ne "y" -and $confirm -ne "Y" -and $confirm -ne "YES") {
    Write-Host "Aborted." -ForegroundColor Yellow
    exit 0
}

# ============================================================================
# PHASE 2: CHECK BRANCH STATUS
# ============================================================================
Write-Debug-Phase "Starting Phase 2: Checking remote/local branches"

Write-Debug-Step "Checking if local branch '$branchName' exists..."
$localBranch = git branch --list $branchName
Write-Debug-Step "Local branch check: $(if($localBranch){'Found'}else{'Not found'})"

Write-Debug-Step "Checking if remote branch 'origin/$branchName' exists..."
$remoteBranch = git ls-remote --heads origin $branchName
Write-Debug-Step "Remote branch check: $(if($remoteBranch){'Found'}else{'Not found'})"

$branchExists = $false
$previousVersion = $null
$currentVersion = $null

if ($localBranch -or $remoteBranch) {
    $branchExists = $true
    Write-Host "`nBranch '$branchName' already exists - this is an UPDATE" -ForegroundColor Yellow
    Write-Debug-Step "PR branch exists - mode: UPDATE"
    
    if ($remoteBranch) {
        Write-Debug-Step "Fetching latest from origin/$branchName..."
        git fetch origin $branchName 2>&1 
        Write-Debug-Step "Fetch complete"
    }
    
    if ($localBranch) {
        Write-Debug-Step "Checking out existing local branch..."
        git checkout $branchName 2>&1
    } else {
        Write-Debug-Step "Creating tracking branch from origin/$branchName..."
        git checkout -b $branchName origin/$branchName 2>&1
    }
    Write-Debug-Step "Branch checkout complete"
    
    if (Test-Path $relativeFilePath) {
        Write-Debug-Step "Extracting previous version from branch..."
        $previousVersion = Get-ModVersion $relativeFilePath
        Write-Debug-Step "Previous version: $previousVersion"
    }
    
    Write-Debug-Step "Returning to Testing branch..."
    git checkout Testing 2>&1
    Write-Debug-Step "Back on Testing branch"
    
    Write-Debug-Step "Extracting current version from Testing branch..."
    $currentVersion = Get-ModVersion $FilePath
    if (-not $currentVersion) {
        Write-Host "Error: Could not detect version from mod file" -ForegroundColor Red
        exit 1
    }
    Write-Debug-Step "Current version: $currentVersion"
    
    if ($previousVersion) {
        Write-Host "Detected version change: $previousVersion -> $currentVersion" -ForegroundColor Cyan
    }
} else {
    Write-Host "`nBranch '$branchName' does not exist - this is a NEW MOD" -ForegroundColor Green
    Write-Debug-Step "PR branch does not exist - mode: NEW MOD"
}

# ============================================================================
# PHASE 3: VALIDATE TESTING BRANCH
# ============================================================================
Write-Debug-Phase "Starting Phase 3: Testing branch validation"

$currentBranch = git branch --show-current
if ($currentBranch -ne "Testing") {
    Write-Host "Error: Must be on Testing branch. Current: $currentBranch" -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $relativeFilePath)) {
    Write-Host "Error: File not found: $relativeFilePath" -ForegroundColor Red
    exit 1
}

$pendingChanges = git status --porcelain
$hasStashedChanges = $false

if (-not [string]::IsNullOrWhiteSpace($pendingChanges)) {
    $changedFiles = $pendingChanges -split "`n" | ForEach-Object { $_.Substring(3) }
    
    $modChanges = $changedFiles | Where-Object { $_ -match '\.wh\.cpp$' }
    if ($modChanges) {
        Write-Host "Aborted: You have pending changes to mod files." -ForegroundColor Red
        exit 1
    }

    $otherChanges = $changedFiles | Where-Object { $_ -notmatch '\.wh\.cpp$' -and $_ -notmatch '^(windhawk-mods\.code-workspace|Commit-Desc|scripts/Submit-Mod\.ps1)$' }
    if ($otherChanges) {
        Write-Host "Warning: You have pending changes to non-mod files." -ForegroundColor Yellow
        $continue = Read-Host "Do you want to continue anyway? (y/n)"
        if ($continue -ne "y") { exit 0 }
        
        Write-Debug-Step "Stashing changes..."
        git stash 2>&1
        if ($LASTEXITCODE -ne 0) { exit 1 }
        $hasStashedChanges = $true
        Write-Host "Changes stashed." -ForegroundColor Green
    }
}

# ============================================================================
# PHASE 4: DETERMINE COMMIT MESSAGE
# ============================================================================
Write-Debug-Phase "Starting Phase 4: Commit message preparation"

$autoTitle = ""
if ($branchExists -and $previousVersion) {
    $autoTitle = "Update: $modTitle $previousVersion - $currentVersion"
} else {
    $autoTitle = "Add: $modTitle"
}

Write-Host "Would you like to enter a custom commit Title? (y=custom, n=auto-generated)" -ForegroundColor Yellow
Write-Host (Get-CenteredText "`"$autoTitle`"") -ForegroundColor Green
$useCustomTitle = Read-Host

$commitTitle = $autoTitle
if ($useCustomTitle -eq 'y' -or $useCustomTitle -eq 'yes') {
    $inputTitle = Read-Host "Enter custom title"
    if (-not [string]::IsNullOrWhiteSpace($inputTitle)) {
        $commitTitle = $inputTitle
    }
}

$templatePath = "Commit-Desc"
Set-Content -Path $templatePath -Value "" -Encoding UTF8

if ($branchExists) {
    Write-Host "Please edit Commit-Desc with your changelog." -ForegroundColor Yellow
} else {
    Write-Host "This is your first mod. Edit Commit-Desc or leave blank." -ForegroundColor Yellow
}

Write-Debug-Step "Waiting for user to edit Commit-Desc..."
Read-Host "Press Enter after saving Commit-Desc to continue..."

$commitDescription = ""
if (Test-Path $templatePath) {
    $commitDescription = Get-Content -Path $templatePath -Raw -ErrorAction SilentlyContinue
}

Write-Host "`nCOMMIT PREVIEW:" -ForegroundColor Cyan
Write-Host "Title: $commitTitle" -ForegroundColor White
Write-Host "Desc: $commitDescription" -ForegroundColor White

$confirm = Read-Host "Ready to commit and push? (yes/y)"
if ($confirm -ne "yes" -and $confirm -ne "y") {
    Write-Host "Aborted." -ForegroundColor Yellow
    if ($hasStashedChanges) { git stash pop 2>&1 }
    exit 0
}

# ============================================================================
# PHASE 5: GIT OPERATIONS
# ============================================================================
Write-Debug-Phase "Starting Phase 5: Git operations"

# -------------------------------------------------------------
# DISABLE GIT HOOK TEMPORARILY
# This prevents the "SYNC CONFLICT" prompt that is killing your script.
# -------------------------------------------------------------
$gitDir = git rev-parse --git-dir
$hookPath = Join-Path $gitDir "hooks/post-checkout"
$hookBackup = "$hookPath.disabled"
$hookWasDisabled = $false

if (Test-Path $hookPath) {
    Write-Debug-Step "Temporarily disabling post-checkout hook..."
    Move-Item $hookPath $hookBackup -Force
    $hookWasDisabled = $true
}

try {
    # Remove Commit-Desc now 
    if (Test-Path "Commit-Desc") {
        Remove-Item "Commit-Desc" -Force -ErrorAction SilentlyContinue
    }

    # [1] Switch to main and update
    Write-Host "[1/6] Updating main branch..." -ForegroundColor Yellow
    
    git checkout main 2>&1
    if ($LASTEXITCODE -ne 0) { throw "Failed to checkout main" }

    git pull upstream main 2>&1
    if ($LASTEXITCODE -ne 0) { throw "Failed to pull from upstream" }
    
    Write-Host "[1/6] Main branch updated" -ForegroundColor Green

    # [2] Create or checkout PR branch
    if ($branchExists) {
        Write-Host "[2/6] Checking out existing branch: $branchName" -ForegroundColor Yellow
        if ($remoteBranch) { git fetch origin $branchName 2>&1 }
        
        if ($localBranch) {
            git checkout $branchName 2>&1
        } else {
            git checkout -b $branchName origin/$branchName 2>&1
        }
    } else {
        Write-Host "[2/6] Creating new branch: $branchName" -ForegroundColor Yellow
        git checkout -b $branchName 2>&1
    }

    if ($LASTEXITCODE -ne 0) { throw "Failed to switch to branch $branchName" }
    Write-Host "[2/6] Branch active" -ForegroundColor Green

    # [3] Refresh workspace file
    Write-Host "[3/6] Refreshing workspace file..." -ForegroundColor Yellow
    $workspaceFile = "windhawk-mods.code-workspace"
    $workspaceContent = git show Testing:$workspaceFile 2>&1
    if ($LASTEXITCODE -eq 0) {
        $workspaceContent | Set-Content -Path $workspaceFile -Encoding UTF8
        Write-Host "[3/6] Workspace file refreshed" -ForegroundColor Green
    }

    # [4] Copy mod file from Testing
    Write-Host "[4/6] Copying mod from Testing branch..." -ForegroundColor Yellow
    git checkout Testing -- $relativeFilePath 2>&1
    if ($LASTEXITCODE -ne 0) { throw "Failed to copy mod file" }
    Write-Host "[4/6] Mod file copied" -ForegroundColor Green

    # [5] Stage and commit
    Write-Host "[5/6] Staging and committing..." -ForegroundColor Yellow
    git add $relativeFilePath 2>&1

    $commitArgs = @("-m", $commitTitle)
    if (-not [string]::IsNullOrWhiteSpace($commitDescription)) {
        $commitArgs += @("-m", $commitDescription)
    }

    git commit @commitArgs 2>&1
    if ($LASTEXITCODE -ne 0) { throw "Failed to commit" }
    Write-Host "[5/6] Changes committed" -ForegroundColor Green

    # [6] Push
    Write-Host "[6/6] Pushing to origin/$branchName..." -ForegroundColor Yellow
    if ($branchExists) {
        git push origin $branchName 2>&1
    } else {
        git push -u origin $branchName 2>&1
    }

    if ($LASTEXITCODE -ne 0) { throw "Failed to push" }
    Write-Host "[6/6] Pushed to GitHub" -ForegroundColor Green

} catch {
    Write-Host "Error during Git operations: $_" -ForegroundColor Red
    
    # Attempt recovery
    Write-Host "Attempting to return to Testing branch..." -ForegroundColor Yellow
    git checkout Testing 2>&1
    if ($hasStashedChanges) { git stash pop 2>&1 }
    
    exit 1
} finally {
    # -------------------------------------------------------------
    # RESTORE GIT HOOK
    # -------------------------------------------------------------
    if ($hookWasDisabled -and (Test-Path $hookBackup)) {
        Write-Debug-Step "Restoring post-checkout hook..."
        Move-Item $hookBackup $hookPath -Force
    }
}

# ============================================================================
# PHASE 6: CLEANUP
# ============================================================================
Write-Host "`nSUCCESS! Ready for PR" -ForegroundColor Green

# Return to Testing
git checkout Testing 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-Host "Warning: Could not return to Testing branch" -ForegroundColor Yellow
} else {
    Write-Host "Returned to Testing branch" -ForegroundColor Green
}

# Restore stashed changes
if ($hasStashedChanges) {
    git stash pop 2>&1
    Write-Host "Stashed changes restored." -ForegroundColor Green
}

if (Test-Path "Commit-Desc") {
    Remove-Item "Commit-Desc" -Force -ErrorAction SilentlyContinue
}