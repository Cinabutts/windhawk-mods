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
    [string]$FileName
)

$ErrorActionPreference = "Stop"
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path

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

# Validate it's a .wh.cpp file
if ($FileName -notmatch '^(.+)\.wh\.cpp$') {
    Write-Host "Error: Not a .wh.cpp file: $FileName" -ForegroundColor Red
    exit 1
}

$modId = $Matches[1]
$relativeFilePath = "mods/$FileName"

# Convert mod-id to nice title (e.g., "desktop-icons-toggle" -> "Desktop Icons Toggle")
$modTitle = (($modId -replace '-', ' ' -replace '_', ' ').Split(' ') | ForEach-Object { 
    if ($_.Length -gt 0) {
        $_.Substring(0,1).ToUpper() + $_.Substring(1).ToLower() 
    }
} | Where-Object { $_ }) -join ' '

$branchName = $modId

# Get current version from Testing branch
$currentVersion = Get-ModVersion $FilePath
if (-not $currentVersion) {
    Write-Host "Error: Could not detect version from mod file" -ForegroundColor Red
    exit 1
}

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
Write-Host "Version: $currentVersion" -ForegroundColor White
Write-Host "========================================`n" -ForegroundColor Cyan

$confirm = Read-Host "Ready to proceed? (type 'yes' to continue)"
if ($confirm -ne "yes" -and $confirm -ne "y" -and $confirm -ne "Y" -and $confirm -ne "YES") {
    Write-Host "Aborted." -ForegroundColor Yellow
    exit 0
}

# Check for pending changes in Testing branch
$pendingChanges = git status --porcelain
if (-not [string]::IsNullOrWhiteSpace($pendingChanges)) {
    Write-Host "Aborted: Testing has pending changes. Please commit or stash them, then rerun." -ForegroundColor Yellow
    Write-Host "`nPending changes:" -ForegroundColor Yellow
    Write-Host $pendingChanges
    exit 0
}

# Check current branch
$currentBranch = git branch --show-current
Write-Host "Current branch: $currentBranch" -ForegroundColor White

if ($currentBranch -ne "Testing") {
    Write-Host "Error: Must be on Testing branch. Current: $currentBranch" -ForegroundColor Red
    Write-Host "Switch to Testing branch first." -ForegroundColor Yellow
    exit 1
}

# Check if file exists in Testing
if (-not (Test-Path $relativeFilePath)) {
    Write-Host "Error: File not found: $relativeFilePath" -ForegroundColor Red
    exit 1
}

Write-Host "File validated in Testing branch" -ForegroundColor Green

# Check if branch exists (locally or remotely)
$branchExists = $false
$previousVersion = $null

$localBranch = git branch --list $branchName
$remoteBranch = git ls-remote --heads origin $branchName 2>$null

if ($localBranch -or $remoteBranch) {
    $branchExists = $true
    Write-Host "`nBranch '$branchName' already exists - this is an UPDATE" -ForegroundColor Yellow
    
    # Try to get previous version from the branch
    $currentBranchBackup = git branch --show-current
    
    # Fetch latest from origin if remote branch exists
    if ($remoteBranch) {
        git fetch origin $branchName 2>&1 | Out-Null
    }
    
    # Checkout or create local tracking branch
    if ($localBranch) {
        git checkout $branchName 2>&1 | Out-Null
    } else {
        git checkout -b $branchName origin/$branchName 2>&1 | Out-Null
    }
    
    if (Test-Path $relativeFilePath) {
        $previousVersion = Get-ModVersion $relativeFilePath
    }
    
    # Go back to Testing
    git checkout Testing 2>&1 | Out-Null
    
    if ($previousVersion) {
        Write-Host "Detected version change: $previousVersion → $currentVersion" -ForegroundColor Cyan
    }
} else {
    Write-Host "`nBranch '$branchName' does not exist - this is a NEW MOD" -ForegroundColor Green
}


# Determine commit title
$autoTitle = ""
if ($branchExists -and $previousVersion) {
    $autoTitle = "Update: $modTitle $previousVersion - $currentVersion"
    Write-Host "`nAuto-detected mod update from $previousVersion → $currentVersion`n" -ForegroundColor Cyan
} else {
    $autoTitle = "Add: $modTitle"
    Write-Host "`nThis is your first mod submission`n" -ForegroundColor Cyan
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

$commitTitle = ""
if ($useCustomTitle -eq 'y' -or $useCustomTitle -eq 'Y' -or $useCustomTitle -eq 'yes' -or $useCustomTitle -eq 'YES') {
    Write-Host "`nEnter custom commit title:" -ForegroundColor Yellow
    $commitTitle = Read-Host
    if ([string]::IsNullOrWhiteSpace($commitTitle)) {
        Write-Host "Using auto-generated title (empty input)" -ForegroundColor Yellow
        $commitTitle = $autoTitle
    }
} else {
    $commitTitle = $autoTitle
}

# Ask for commit description via template file
Write-Host "" -ForegroundColor White
$templatePath = Join-Path "Testing" "Commit-Template.txt"
if (-not (Test-Path "Testing")) {
    New-Item -ItemType Directory -Path "Testing" | Out-Null
}
Set-Content -Path $templatePath -Value "" -Encoding UTF8

if ($branchExists) {
    Write-Host "Please edit Testing/Commit-Template.txt with your changelog (commit description)." -ForegroundColor Yellow
    Write-Host "Save the file, then press Enter here to continue. (Leave empty to skip, not advised.)" -ForegroundColor Yellow
} else {
    Write-Host "This is your first mod. Edit Testing/Commit-Template.txt with a commit description or leave it blank." -ForegroundColor Yellow
    Write-Host "Title: $commitTitle" -ForegroundColor White
    Write-Host "Desc: (contents of Commit-Template.txt)" -ForegroundColor White
}

Read-Host | Out-Null
$commitDescription = ""
if (Test-Path $templatePath) {
    $commitDescription = Get-Content -Path $templatePath -Raw -ErrorAction SilentlyContinue
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

$confirm = Read-Host "Ready to proceed with commit and push? (type 'yes' to continue)"
if ($confirm -ne "yes" -and $confirm -ne "y" -and $confirm -ne "Y" -and $confirm -ne "YES") {
    Write-Host "Aborted." -ForegroundColor Yellow
    exit 0
}

# Switch to main and update
Write-Host "[1/6] Updating main branch from upstream..." -ForegroundColor Yellow
git checkout main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to checkout main" -ForegroundColor Red
    git checkout Testing 2>&1 | Out-Null
    exit 1
}

git pull upstream main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to pull from upstream/main" -ForegroundColor Red
    Write-Host "Make sure upstream remote is configured:" -ForegroundColor Yellow
    Write-Host "  git remote add upstream https://github.com/ramensoftware/windhawk-mods.git" -ForegroundColor Yellow
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[1/6] Main branch updated" -ForegroundColor Green

# Create or checkout branch
if ($branchExists) {
    Write-Host "[2/6] Checking out existing branch: $branchName" -ForegroundColor Yellow
    
    # Fetch latest if remote exists
    if ($remoteBranch) {
        git fetch origin $branchName 2>&1 | Out-Null
    }
    
    # Checkout branch
    if ($localBranch) {
        git checkout $branchName 2>&1 | Out-Null
    } else {
        git checkout -b $branchName origin/$branchName 2>&1 | Out-Null
    }
    
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: Failed to checkout branch" -ForegroundColor Red
        git checkout Testing 2>&1 | Out-Null
        exit 1
    }
    Write-Host "[2/6] Checked out branch (adding new commit)" -ForegroundColor Green
} else {
    Write-Host "[2/6] Creating new branch: $branchName" -ForegroundColor Yellow
    git checkout -b $branchName 2>&1 | Out-Null
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: Failed to create branch" -ForegroundColor Red
        git checkout Testing 2>&1 | Out-Null
        exit 1
    }
    Write-Host "[2/6] Branch created" -ForegroundColor Green
}

# Check for workspace file and copy if needed
Write-Host "[3/6] Checking workspace file..." -ForegroundColor Yellow
$workspaceFile = "windhawk-mods.code-workspace"
if (-not (Test-Path $workspaceFile)) {
    Write-Host "Workspace file not found, copying from Testing..." -ForegroundColor Yellow
    git show Testing:$workspaceFile > $workspaceFile 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Workspace file copied (local only, not committed)" -ForegroundColor Green
    } else {
        Write-Host "Warning: Could not copy workspace file" -ForegroundColor Yellow
    }
}
Write-Host "[3/6] Workspace check complete" -ForegroundColor Green

# Copy mod file from Testing
Write-Host "[4/6] Copying mod from Testing branch..." -ForegroundColor Yellow
git checkout Testing -- $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to checkout file from Testing" -ForegroundColor Red
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[4/6] Mod file copied" -ForegroundColor Green

# Stage and commit
Write-Host "[5/6] Staging and committing..." -ForegroundColor Yellow
git add $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to stage file" -ForegroundColor Red
    git checkout Testing 2>&1 | Out-Null
    exit 1
}

# Show what will be committed
Write-Host "`nChanges to be committed:" -ForegroundColor Cyan
git diff --cached --stat
Write-Host ""

# Commit
$commitArgs = @("-m", $commitTitle)
if (-not [string]::IsNullOrWhiteSpace($commitDescription)) {
    $commitArgs += @("-m", $commitDescription)
}

git commit @commitArgs 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to commit" -ForegroundColor Red
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[5/6] Changes committed" -ForegroundColor Green

# Push
Write-Host "[6/6] Pushing to origin/$branchName..." -ForegroundColor Yellow
if ($branchExists) {
    git push origin $branchName 2>&1 | Out-Null
} else {
    git push -u origin $branchName 2>&1 | Out-Null
}

if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to push to origin" -ForegroundColor Red
    Write-Host "Branch created/updated locally but not pushed." -ForegroundColor Yellow
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[6/6] Pushed to GitHub" -ForegroundColor Green

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
git checkout Testing 2>&1 | Out-Null
Write-Host "Returned to Testing branch" -ForegroundColor Green

# Clear commit template file after completion
$templatePath = Join-Path "Testing" "Commit-Template.txt"
if (Test-Path $templatePath) {
    Set-Content -Path $templatePath -Value "" -Encoding UTF8 -ErrorAction SilentlyContinue
}
