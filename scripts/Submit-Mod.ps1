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
    [int]$DebugLevel = 0  # 0=off, 1=phase level, 2=every step
)

$ErrorActionPreference = "Stop"
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
# - Check if in main branch
# - Validate it's a .wh.cpp file
# - Extract mod metadata (ID, title)
# - Show workflow preview and get user confirmation

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

# Convert mod-id to nice title (e.g., "desktop-icons-toggle" -> "Desktop Icons Toggle")
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



if ($localBranch -or $remoteBranch) {
    $branchExists = $true
    Write-Host "`nBranch '$branchName' already exists - this is an UPDATE" -ForegroundColor Yellow
    Write-Debug-Step "PR branch exists - mode: UPDATE"
    
    # Try to get previous version from the branch
    $currentBranchBackup = git branch --show-current
    
    # Fetch latest from origin if remote branch exists
    if ($remoteBranch) {
        Write-Debug-Step "Fetching latest from origin/$branchName..."
        git fetch origin $branchName 2>&1 | Out-Null
        Write-Debug-Step "Fetch complete"
    }
    
    # Checkout or create local tracking branch
    if ($localBranch) {
        Write-Debug-Step "Checking out existing local branch..."
        git checkout $branchName 2>&1 | Out-Null
    } else {
        Write-Debug-Step "Creating tracking branch from origin/$branchName..."
        git checkout -b $branchName origin/$branchName 2>&1 | Out-Null
    }
    Write-Debug-Step "Branch checkout complete"
    
    if (Test-Path $relativeFilePath) {
        Write-Debug-Step "Extracting previous version from branch..."
        $previousVersion = Get-ModVersion $relativeFilePath
        Write-Debug-Step "Previous version: $previousVersion"
    } else {
        Write-Debug-Step "Mod file not found on branch"
    }
    
    # Go back to Testing
    Write-Debug-Step "Returning to Testing branch..."
    git checkout Testing 2>&1 | Out-Null
    Write-Debug-Step "Back on Testing branch"
    
    # Now extract current version for updates
    Write-Debug-Step "Extracting current version from Testing branch..."
    $currentVersion = Get-ModVersion $FilePath
    if (-not $currentVersion) {
        Write-Host "Error: Could not detect version from mod file" -ForegroundColor Red
        exit 1
    }
    Write-Debug-Step "Current version: $currentVersion"
    
    if ($previousVersion) {
        Write-Host "Detected version change: $previousVersion → $currentVersion" -ForegroundColor Cyan
    }
    Write-Debug-Phase "Phase 2 complete - UPDATE mode"
} else {
    Write-Host "`nBranch '$branchName' does not exist - this is a NEW MOD" -ForegroundColor Green
    Write-Debug-Step "PR branch does not exist - mode: NEW MOD"
    Write-Debug-Phase "Phase 2 complete - NEW MOD mode"
}

# ============================================================================
# PHASE 3: VALIDATE TESTING BRANCH AND CHECK UNCOMMITTED CHANGES
# ============================================================================
# - Ensure on Testing branch
# - Check for uncommitted changes to mod files (abort if found)
# - Check for uncommitted changes to other files (warn, stash if continues)

Write-Debug-Phase "Starting Phase 3: Testing branch validation and change detection"

# Check current branch is Testing
Write-Debug-Step "Verifying on Testing branch..."
Write-Host "Current branch: $currentBranch" -ForegroundColor White

if ($currentBranch -ne "Testing") {
    Write-Host "Error: Must be on Testing branch. Current: $currentBranch" -ForegroundColor Red
    Write-Host "Switch to Testing branch first." -ForegroundColor Yellow
    exit 1
}
Write-Debug-Step "On Testing branch confirmed"

# Check if file exists in Testing
Write-Debug-Step "Checking if mod file exists in Testing: $relativeFilePath"
if (-not (Test-Path $relativeFilePath)) {
    Write-Host "Error: File not found: $relativeFilePath" -ForegroundColor Red
    exit 1
}
Write-Debug-Step "Mod file verified in Testing branch"
Write-Host "File validated in Testing branch" -ForegroundColor Green

# Check for pending changes in Testing branch
Write-Debug-Step "Running git status to check for uncommitted changes..."
$pendingChanges = git status --porcelain
$statusMessage = if ($pendingChanges) { "Changes found" } else { "No changes" }
Write-Debug-Step "Git status result: $statusMessage"
$hasStashedChanges = $false

if (-not [string]::IsNullOrWhiteSpace($pendingChanges)) {
    Write-Debug-Step "Processing uncommitted changes..."
    $changedFiles = $pendingChanges -split "`n" | ForEach-Object { $_.Substring(3) }
    Write-Debug-Step "Changed files count: $($changedFiles.Count)"
    
    # Check for mod files (.wh.cpp)
    Write-Debug-Step "Checking for .wh.cpp mod file changes..."
    $modChanges = $changedFiles | Where-Object { $_ -match '\.wh\.cpp$' }
    if ($modChanges) {
        Write-Host "Aborted: You have pending changes to mod files (.wh.cpp). Please commit or stash them first." -ForegroundColor Red
        Write-Host "`nPending mod changes:" -ForegroundColor Yellow
        $modChanges | ForEach-Object { Write-Host "  $_" }
        exit 1
    }
    Write-Debug-Step "No .wh.cpp changes found - OK"

    # Check for other files (excluding excluded files)
    Write-Debug-Step "Checking for other non-excluded file changes..."
    $otherChanges = $changedFiles | Where-Object { $_ -notmatch '\.wh\.cpp$' -and $_ -notmatch '^(windhawk-mods\.code-workspace|Commit-Desc|scripts/Submit-Mod\.ps1)$' }
    if ($otherChanges) {
        Write-Debug-Step "Other changes detected: $($otherChanges.Count) files"
        Write-Host "Warning: You have pending changes to non-mod files:" -ForegroundColor Yellow
        $otherChanges | ForEach-Object { Write-Host "  $_" }
        $continue = Read-Host "Do you want to continue anyway? (y/n)"
        if ($continue -ne "y" -and $continue -ne "Y" -and $continue -ne "yes" -and $continue -ne "YES") {
            Write-Host "Aborted." -ForegroundColor Yellow
            exit 0
        }
        
        Write-Debug-Step "User chose to continue - executing git stash..."
        git stash 2>&1 | Out-Null
        if ($LASTEXITCODE -ne 0) {
            Write-Host "Error: Failed to stash changes" -ForegroundColor Red
            exit 1
        }
        $hasStashedChanges = $true
        Write-Debug-Step "Changes stashed successfully - will restore after returning to Testing"
        Write-Host "Changes stashed. They will be restored when returning to Testing." -ForegroundColor Green
    } else {
        Write-Debug-Step "No other non-excluded changes found"
    }
} else {
    Write-Debug-Step "No uncommitted changes detected - clean working directory"
}
Write-Debug-Phase "Phase 3 complete"

# ============================================================================
# PHASE 4: DETERMINE COMMIT MESSAGE
# ============================================================================
# - Generate or get custom commit title
# - Get commit description from Commit-Desc file

Write-Debug-Phase "Starting Phase 4: Commit message preparation"

# Determine commit title
Write-Debug-Step "Determining commit title..."
$autoTitle = ""
if ($branchExists -and $previousVersion) {
    Write-Debug-Step "Mode: UPDATE with version change detected"
    $autoTitle = "Update: $modTitle $previousVersion - $currentVersion"
    Write-Host "`nAuto-detected mod update from $previousVersion → $currentVersion`n" -ForegroundColor Cyan
    Write-Debug-Step "Generated title: $autoTitle"
} else {
    Write-Debug-Step "Mode: NEW MOD - no previous version"
    $autoTitle = "Add: $modTitle"
    Write-Host "`nThis is your first mod submission`n" -ForegroundColor Cyan
    Write-Debug-Step "Generated title: $autoTitle"
}

# Ask for custom title or use auto-generated
Write-Host "Would you like to enter a custom commit Title? (y=custom, n=auto-generated)" -ForegroundColor Yellow
if ($branchExists) {
    Write-Host (Get-CenteredText "Working title:") -ForegroundColor White
} else {
    Write-Host (Get-CenteredText "Auto-generated title:") -ForegroundColor White
}
Write-Host (Get-CenteredText "`"$autoTitle`"") -ForegroundColor Green
$useCustomTitle = Read-Host
Write-Debug-Step "User input received: custom=$($useCustomTitle -match '^y|yes$')"

$commitTitle = ""
if ($useCustomTitle -eq 'y' -or $useCustomTitle -eq 'Y' -or $useCustomTitle -eq 'yes' -or $useCustomTitle -eq 'YES') {
    Write-Host "`nEnter custom commit title:" -ForegroundColor Yellow
    $commitTitle = Read-Host
    if ([string]::IsNullOrWhiteSpace($commitTitle)) {
        Write-Host "Using auto-generated title (empty input)" -ForegroundColor Yellow
        $commitTitle = $autoTitle
        Write-Debug-Step "Custom input was empty - using auto-generated"
    } else {
        Write-Debug-Step "Using custom title: $commitTitle"
    }
} else {
    $commitTitle = $autoTitle
    Write-Debug-Step "Using auto-generated title: $autoTitle"
}

# Ask for commit description via Commit-Desc file
Write-Host "" -ForegroundColor White
$templatePath = "Commit-Desc"
Write-Debug-Step "Creating Commit-Desc file: $templatePath"
Set-Content -Path $templatePath -Value "" -Encoding UTF8
Write-Debug-Step "File created/cleared"

if ($branchExists) {
    Write-Host "Please edit Commit-Desc with your changelog (commit description)." -ForegroundColor Yellow
    Write-Host "Save the file, then press Enter here to continue. (Leave empty to skip, not advised.)" -ForegroundColor Yellow
} else {
    Write-Host "This is your first mod. Edit Commit-Desc with a commit description or leave it blank." -ForegroundColor Yellow
    Write-Host "Title: $commitTitle" -ForegroundColor White
    Write-Host "Desc: (contents of Commit-Desc)" -ForegroundColor White
}

Write-Debug-Step "Waiting for user to edit and save Commit-Desc file..."
Read-Host | Out-Null
Write-Debug-Step "User resumed script"

$commitDescription = ""
if (Test-Path $templatePath) {
    $commitDescription = Get-Content -Path $templatePath -Raw -ErrorAction SilentlyContinue
    Write-Debug-Step "Commit-Desc read: length=$($commitDescription.Length) chars, empty=$([string]::IsNullOrWhiteSpace($commitDescription))"
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "COMMIT PREVIEW" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Title: $commitTitle" -ForegroundColor White
if ([string]::IsNullOrWhiteSpace($commitDescription)) {
    Write-Host "Desc: (none)" -ForegroundColor DarkGray
} else {
    Write-Host "Desc:" -ForegroundColor White
    Write-Host $commitDescription -ForegroundColor White
}
Write-Host "========================================`n" -ForegroundColor Cyan

Write-Debug-Step "Waiting for final confirmation before switching branches..."
$confirm = Read-Host "Ready to proceed with commit and push? (type 'yes' to continue)"
if ($confirm -ne "yes" -and $confirm -ne "y" -and $confirm -ne "Y" -and $confirm -ne "YES") {
    Write-Host "Aborted." -ForegroundColor Yellow
    Write-Debug-Step "User aborted at final confirmation"
    if ($hasStashedChanges) {
        Write-Debug-Step "Restoring stashed changes before abort..."
        git stash pop 2>&1 | Out-Null
        Write-Host "Stashed changes restored." -ForegroundColor Green
        Write-Debug-Step "Stashed changes restored"
    }
    exit 0
}
Write-Debug-Step "User confirmed - proceeding to Phase 5"
Write-Debug-Phase "Phase 4 complete"

# ============================================================================
# PHASE 5: GIT OPERATIONS
# ============================================================================
# [1] Update main branch from upstream
# [2] Create or checkout PR branch
# [3] Copy workspace file if needed
# [4] Copy mod file from Testing
# [5] Commit changes
# [6] Push to origin

Write-Debug-Phase "Starting Phase 5: Git operations"

# [1] Switch to main and update
Write-Host "[1/6] Updating main branch from upstream..." -ForegroundColor Yellow
Write-Debug-Step "[1/6] Checking out main branch..."
git checkout main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to checkout main branch" -ForegroundColor Red
    Write-Debug-Step "[1/6] Failed to checkout main"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}

Write-Debug-Step "[1/6] Pulling from upstream/main..."
git pull upstream main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to pull from upstream/main" -ForegroundColor Red
    Write-Host "Make sure upstream remote is configured:" -ForegroundColor Yellow
    Write-Host "  git remote add upstream https://github.com/ramensoftware/windhawk-mods.git" -ForegroundColor Yellow
    Write-Debug-Step "[1/6] Failed to pull from upstream"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}
Write-Host "[1/6] Main branch updated" -ForegroundColor Green
Write-Debug-Step "[1/6] Main branch successfully updated from upstream"

# [2] Create or checkout PR branch
if ($branchExists) {
    Write-Host "[2/6] Checking out existing branch: $branchName" -ForegroundColor Yellow
    Write-Debug-Step "[2/6] Mode: UPDATE - checking out existing branch"
    
    # Fetch latest if remote exists
    if ($remoteBranch) {
        Write-Debug-Step "[2/6] Fetching latest from origin/$branchName..."
        git fetch origin $branchName 2>&1 | Out-Null
    }
    
    # Checkout branch
    if ($localBranch) {
        Write-Debug-Step "[2/6] Checking out local branch..."
        git checkout $branchName 2>&1 | Out-Null
    } else {
        Write-Debug-Step "[2/6] Creating tracking branch from remote..."
        git checkout -b $branchName origin/$branchName 2>&1 | Out-Null
    }
    
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: Failed to checkout branch '$branchName'" -ForegroundColor Red
        Write-Debug-Step "[2/6] Failed to checkout branch"
        git checkout Testing 2>&1 | Out-Null
        if ($hasStashedChanges) {
            git stash pop 2>&1 | Out-Null
        }
        exit 1
    }
    Write-Host "[2/6] Checked out branch (adding new commit)" -ForegroundColor Green
    Write-Debug-Step "[2/6] Successfully checked out $branchName"
} else {
    Write-Host "[2/6] Creating new branch: $branchName" -ForegroundColor Yellow
    Write-Debug-Step "[2/6] Mode: NEW MOD - creating new branch from main"
    git checkout -b $branchName 2>&1 | Out-Null
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: Failed to create branch '$branchName'" -ForegroundColor Red
        Write-Debug-Step "[2/6] Failed to create branch"
        git checkout Testing 2>&1 | Out-Null
        if ($hasStashedChanges) {
            git stash pop 2>&1 | Out-Null
        }
        exit 1
    }
    Write-Host "[2/6] Branch created" -ForegroundColor Green
    Write-Debug-Step "[2/6] Successfully created new branch $branchName"
}

# [3] Check for workspace file and copy if needed
Write-Host "[3/6] Checking workspace file..." -ForegroundColor Yellow
Write-Debug-Step "[3/6] Checking for workspace file..."
$workspaceFile = "windhawk-mods.code-workspace"
if (-not (Test-Path $workspaceFile)) {
    Write-Host "Workspace file not found, copying from Testing..." -ForegroundColor Yellow
    Write-Debug-Step "[3/6] Workspace file missing - copying from Testing branch"
    git show Testing:$workspaceFile > $workspaceFile 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Workspace file copied (local only, not committed)" -ForegroundColor Green
        Write-Debug-Step "[3/6] Workspace file copied successfully"
    } else {
        Write-Host "Warning: Could not copy workspace file" -ForegroundColor Yellow
        Write-Debug-Step "[3/6] Warning: Failed to copy workspace file from Testing"
    }
} else {
    Write-Debug-Step "[3/6] Workspace file already exists"
}
Write-Host "[3/6] Workspace check complete" -ForegroundColor Green

# [4] Copy mod file from Testing
Write-Host "[4/6] Copying mod from Testing branch..." -ForegroundColor Yellow
Write-Debug-Step "[4/6] Copying mod file: $relativeFilePath from Testing branch"
git checkout Testing -- $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to copy mod file from Testing branch" -ForegroundColor Red
    Write-Host "File: $relativeFilePath" -ForegroundColor Yellow
    Write-Debug-Step "[4/6] Failed to copy mod file"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}
Write-Host "[4/6] Mod file copied" -ForegroundColor Green
Write-Debug-Step "[4/6] Mod file successfully copied to PR branch"

# [5] Stage and commit
Write-Host "[5/6] Staging and committing..." -ForegroundColor Yellow
Write-Debug-Step "[5/6] Staging mod file..."
git add $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to stage mod file" -ForegroundColor Red
    Write-Debug-Step "[5/6] Failed to stage file"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}

# Show what will be committed
Write-Host "`nChanges to be committed:" -ForegroundColor Cyan
git diff --cached --stat
Write-Host ""

# Commit
Write-Debug-Step "[5/6] Creating commit with title and description..."
$commitArgs = @("-m", $commitTitle)
if (-not [string]::IsNullOrWhiteSpace($commitDescription)) {
    $commitArgs += @("-m", $commitDescription)
}

git commit @commitArgs 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to create commit" -ForegroundColor Red
    Write-Debug-Step "[5/6] Failed to commit changes"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}
Write-Host "[5/6] Changes committed" -ForegroundColor Green
Write-Debug-Step "[5/6] Commit created successfully"

# [6] Push
Write-Host "[6/6] Pushing to origin/$branchName..." -ForegroundColor Yellow
Write-Debug-Step "[6/6] Pushing to origin..."
if ($branchExists) {
    git push origin $branchName 2>&1 | Out-Null
} else {
    git push -u origin $branchName 2>&1 | Out-Null
}

if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to push to origin" -ForegroundColor Red
    Write-Host "Branch created/updated locally but not pushed." -ForegroundColor Yellow
    Write-Debug-Step "[6/6] Failed to push to origin"
    git checkout Testing 2>&1 | Out-Null
    if ($hasStashedChanges) {
        git stash pop 2>&1 | Out-Null
    }
    exit 1
}
Write-Host "[6/6] Pushed to GitHub" -ForegroundColor Green
Write-Debug-Step "[6/6] Push to origin completed successfully"

# ============================================================================
# PHASE 6: CLEANUP AND RETURN
# ============================================================================
# - Return to Testing branch
# - Restore stashed changes if any
# - Clear Commit-Desc file

Write-Debug-Phase "Starting Phase 6: Cleanup and return to Testing"

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "SUCCESS! Ready for PR" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Branch: $branchName" -ForegroundColor White
Write-Host "Commit: $commitTitle" -ForegroundColor White
if ($branchExists) {
    Write-Host "Type: UPDATE (new commit added to existing branch)" -ForegroundColor Yellow
} else {
    Write-Host "Type: NEW MOD" -ForegroundColor Green
}
Write-Host "`nNext steps:" -ForegroundColor Yellow
if ($branchExists) {
    Write-Host "- Your existing PR will be automatically updated with this commit" -ForegroundColor White
    Write-Host "- Review the changes on GitHub" -ForegroundColor White
} else {
    Write-Host "1. Go to GitHub and create Pull Request" -ForegroundColor White
    Write-Host "   From: YOUR-FORK/$branchName" -ForegroundColor White
    Write-Host "   To: ramensoftware/windhawk-mods:main" -ForegroundColor White
}
Write-Host "========================================`n" -ForegroundColor Cyan

# Return to Testing branch
Write-Debug-Step "Returning to Testing branch..."
git checkout Testing 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Warning: Could not return to Testing branch" -ForegroundColor Yellow
    Write-Debug-Step "Failed to checkout Testing branch"
} else {
    Write-Host "Returned to Testing branch" -ForegroundColor Green
    Write-Debug-Step "Successfully returned to Testing branch"
}

# Restore stashed changes if any
if ($hasStashedChanges) {
    Write-Debug-Step "Restoring stashed changes..."
    git stash pop 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Stashed changes restored." -ForegroundColor Green
        Write-Debug-Step "Stashed changes successfully restored"
    } else {
        Write-Host "Warning: Could not restore stashed changes" -ForegroundColor Yellow
        Write-Host "Run 'git stash pop' manually to restore them" -ForegroundColor Yellow
        Write-Debug-Step "Failed to restore stashed changes"
    }
}

# Clear commit template file after completion
Write-Debug-Step "Deleting Commit-Desc file..."
$templatePath = "Commit-Desc"
if (Test-Path $templatePath) {
    Remove-Item -Path $templatePath -Force -ErrorAction SilentlyContinue
    Write-Debug-Step "Commit-Desc deleted"
}

Write-Debug-Phase "Phase 6 complete"
Write-Debug-Phase "================================"
Write-Debug-Phase "SCRIPT EXECUTION COMPLETED SUCCESSFULLY"
Write-Debug-Phase "================================"
