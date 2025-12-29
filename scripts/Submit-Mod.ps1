# Submit Mod - Prepares a single mod for PR submission
# This script will:
#   1. Create a clean submission branch from upstream/main
#   2. Copy ONLY your mod file to this branch
#   3. Commit with proper message format
#   4. Push to your fork for PR creation
# 
# Your main branch stays clean (synced with upstream)
# Your Testing branch is unchanged
# A new feature branch is created with just this one mod
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

# Holds changelog info for updates (null for new mods)
$changelogResult = $null

# Validate it's a .wh.cpp file
if ($FileName -notmatch '^(.+)\.wh\.cpp$') {
    Write-Host "Error: Not a .wh.cpp file: $FileName" -ForegroundColor Red
    exit 1
}

$modId = $Matches[1]
$relativeFilePath = "mods/$FileName"

# Convert mod-id to nice title (e.g., "desktop-icons-toggle" -> "Desktop Icons Toggle")
$modTitle = ($modId -replace '-', ' ' -replace '_', ' ').Split(' ') | ForEach-Object { 
    if ($_.Length -gt 0) {
        $_.Substring(0,1).ToUpper() + $_.Substring(1).ToLower() 
    }
} | Where-Object { $_ } | Join-String -Separator ' '

$branchName = "add-$modId"
$commitMessage = "Add: $modTitle"

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "MOD SUBMISSION WORKFLOW" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "`nThis task will:" -ForegroundColor Yellow
Write-Host "  1. Update your main branch from upstream/main" -ForegroundColor White
Write-Host "  2. Create submission branch: '$branchName'" -ForegroundColor White
Write-Host "  3. Copy ONLY this mod file to the branch" -ForegroundColor White
Write-Host "  4. Commit: '$commitMessage'" -ForegroundColor White
Write-Host "  5. Push to your fork" -ForegroundColor White
Write-Host "  6. Return you to Testing branch" -ForegroundColor White
Write-Host "`nResult:" -ForegroundColor Yellow
Write-Host "  - Your main branch: UNCHANGED (clean, synced with upstream)" -ForegroundColor Green
Write-Host "  - Your Testing branch: UNCHANGED (still has all your mods)" -ForegroundColor Green
Write-Host "  - New branch created: '$branchName' (ready for PR)" -ForegroundColor Green
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "Mod: $modTitle" -ForegroundColor White
Write-Host "File: $relativeFilePath" -ForegroundColor White
Write-Host "========================================`n" -ForegroundColor Cyan

$confirm = Read-Host "Ready to proceed? (type 'yes' to continue)"
if ($confirm -ne "yes") {
    Write-Host "Aborted." -ForegroundColor Yellow
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

Write-Host "[1/7] File validated in Testing branch" -ForegroundColor Green

# Prepare changelog (only when the mod already exists in upstream/main)
Write-Host "Preparing changelog (if this is an update)..." -ForegroundColor Yellow
try {
    $changelogResult = & (Join-Path $scriptDir "Create-Changelog.ps1") -FilePath $relativeFilePath -FileName $FileName -ModTitle $modTitle -OutputDir "Testing"
} catch {
    Write-Host "Error: Changelog generation failed: $_" -ForegroundColor Red
    exit 1
}

if ($changelogResult -and $changelogResult.IsNew) {
    Write-Host "Changelog skipped: new mod (no upstream version)." -ForegroundColor Yellow
} elseif ($changelogResult -and $changelogResult.Summary) {
    Write-Host "Changelog prepared for commit body." -ForegroundColor Green
} else {
    Write-Host "Changelog: no summary produced (unexpected)." -ForegroundColor Yellow
}

# Switch to main
Write-Host "[2/7] Switching to main branch..." -ForegroundColor Yellow
git checkout main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to checkout main" -ForegroundColor Red
    exit 1
}
Write-Host "[2/7] Switched to main" -ForegroundColor Green

# Pull latest from upstream
Write-Host "[3/7] Pulling latest from upstream/main..." -ForegroundColor Yellow
git pull upstream main 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to pull from upstream/main" -ForegroundColor Red
    Write-Host "Make sure upstream remote is configured:" -ForegroundColor Yellow
    Write-Host "  git remote add upstream https://github.com/ramensoftware/windhawk-mods.git" -ForegroundColor Yellow
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[3/7] Main branch updated" -ForegroundColor Green

# Check if branch already exists
$existingBranch = git branch --list $branchName
if ($existingBranch) {
    Write-Host "Warning: Branch '$branchName' already exists" -ForegroundColor Yellow
    $response = Read-Host "Delete and recreate? (y/n)"
    if ($response -eq 'y') {
        git branch -D $branchName 2>&1 | Out-Null
        Write-Host "Deleted existing branch" -ForegroundColor Yellow
    } else {
        Write-Host "Aborted. Delete the branch manually first." -ForegroundColor Red
        git checkout Testing 2>&1 | Out-Null
        exit 1
    }
}

# Create submission branch
Write-Host "[4/7] Creating branch: $branchName" -ForegroundColor Yellow
git checkout -b $branchName 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to create branch" -ForegroundColor Red
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[4/7] Branch created (now in $branchName)" -ForegroundColor Green

# Copy mod file from Testing
Write-Host "[5/7] Copying mod from Testing branch..." -ForegroundColor Yellow
git checkout Testing -- $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to checkout file from Testing" -ForegroundColor Red
    git checkout main 2>&1 | Out-Null
    git branch -D $branchName 2>&1 | Out-Null
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[5/7] Mod file copied" -ForegroundColor Green

# Stage the file
Write-Host "[6/7] Staging file..." -ForegroundColor Yellow
git add $relativeFilePath 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to stage file" -ForegroundColor Red
    git checkout main 2>&1 | Out-Null
    git branch -D $branchName 2>&1 | Out-Null
    git checkout Testing 2>&1 | Out-Null
    exit 1
}

# Show what will be committed
Write-Host "`nChanges to be committed:" -ForegroundColor Cyan
git diff --cached --stat
Write-Host ""

# Commit
$commitArgs = @("-m", $commitMessage)
if ($changelogResult -and -not $changelogResult.IsNew -and $changelogResult.Summary) {
    $commitArgs += @("-m", $changelogResult.Summary)
}

git commit @commitArgs 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to commit" -ForegroundColor Red
    git checkout main 2>&1 | Out-Null
    git branch -D $branchName 2>&1 | Out-Null
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[6/7] Changes committed" -ForegroundColor Green

# Final confirmation before pushing
$readyToPush = Read-Host "Are you sure you're ready to submit this mod? Type 'yes' to push"
if ($readyToPush -ne "yes") {
    Write-Host "Push skipped. Branch '$branchName' contains the committed changes." -ForegroundColor Yellow
    Write-Host "You can push later with: git push -u origin $branchName" -ForegroundColor Yellow
    Write-Host "Currently on branch '$branchName'. Switch back to Testing when ready: git checkout Testing" -ForegroundColor Yellow
    exit 0
}

# Push
Write-Host "[7/7] Pushing to origin/$branchName..." -ForegroundColor Yellow
git push -u origin $branchName 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Failed to push to origin" -ForegroundColor Red
    Write-Host "Branch created locally but not pushed." -ForegroundColor Yellow
    git checkout Testing 2>&1 | Out-Null
    exit 1
}
Write-Host "[7/7] Pushed to GitHub" -ForegroundColor Green

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "SUCCESS! Ready for PR" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Branch: $branchName" -ForegroundColor White
Write-Host "Commit: $commitMessage" -ForegroundColor White
if ($changelogResult -and -not $changelogResult.IsNew -and $changelogResult.ChangelogPath) {
    Write-Host "Changelog saved (not committed): $($changelogResult.ChangelogPath)" -ForegroundColor White
}
Write-Host "`nNext steps:" -ForegroundColor Yellow
Write-Host "1. Go to GitHub: https://github.com/YOUR-USERNAME/windhawk-mods" -ForegroundColor White
Write-Host "2. Create Pull Request from '$branchName' to 'ramensoftware:main'" -ForegroundColor White
Write-Host "3. Wait for review" -ForegroundColor White
Write-Host "========================================`n" -ForegroundColor Cyan

# Return to Testing branch
git checkout Testing 2>&1 | Out-Null
Write-Host "Returned to Testing branch" -ForegroundColor Green
