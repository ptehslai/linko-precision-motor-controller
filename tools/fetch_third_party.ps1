# Fetch third-party dependencies
#
# Usage:
#   powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1
#   powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk
#   powershell -ExecutionPolicy Bypass -File tools/fetch_third_party.ps1 -IncludeLksSdk -IncludePeripDemo

param(
    [switch]$IncludeLksSdk,
    [switch]$IncludePeripDemo
)

$ErrorActionPreference = "Stop"
$Root = Split-Path -Parent $PSScriptRoot
$Cache = Join-Path $Root ".deps_cache"
New-Item -ItemType Directory -Force -Path $Cache | Out-Null

function Download-ZipRepo {
    param(
        [string]$Name,
        [string]$Url,
        [string]$InnerSubdir = ""
    )
    $zip = Join-Path $Cache "$Name.zip"
    Write-Host "Downloading $Name..."
    curl.exe -L -o $zip $Url
    if ($LASTEXITCODE -ne 0) { throw "curl failed for $Name" }
    $extract = Join-Path $Cache $Name
    if (Test-Path $extract) { Remove-Item $extract -Recurse -Force }
    Expand-Archive -Path $zip -DestinationPath $extract -Force
    $inner = Get-ChildItem $extract | Select-Object -First 1
    if ($InnerSubdir -ne "") {
        return Join-Path $inner.FullName $InnerSubdir
    }
    return $inner.FullName
}

# --- Libraries linked into firmware (copied into third_party/) ---
$libcanardSrc = Download-ZipRepo "libcanard" "https://github.com/OpenCyphal/libcanard/archive/refs/heads/master.zip" "libcanard"
Get-ChildItem $libcanardSrc -File | ForEach-Object {
    Copy-Item $_.FullName (Join-Path "$Root/third_party/libcanard" $_.Name) -Force
}

$o1heapSrc = Download-ZipRepo "o1heap" "https://github.com/pavel-kirienko/o1heap/archive/refs/heads/master.zip" "o1heap"
Copy-Item (Join-Path $o1heapSrc "o1heap.c") "$Root/third_party/o1heap/o1heap.c" -Force
Copy-Item (Join-Path $o1heapSrc "o1heap.h") "$Root/third_party/o1heap/o1heap.h" -Force

Write-Host "Updated third_party/libcanard and third_party/o1heap"

# --- Optional reference archives (stay in .deps_cache only) ---
@(
    @{ name = "libcrc"; url = "https://github.com/lammertb/libcrc/archive/refs/heads/master.zip" },
    @{ name = "FlashDB"; url = "https://github.com/armink/FlashDB/archive/refs/heads/master.zip" },
    @{ name = "CMSIS-DSP"; url = "https://github.com/ARM-software/CMSIS-DSP/archive/refs/heads/main.zip" },
    @{ name = "MotionGenerator"; url = "https://github.com/EmanuelFeru/MotionGenerator/archive/refs/heads/master.zip" }
) | ForEach-Object {
    Download-ZipRepo $_.name $_.url | Out-Null
    Write-Host "Cached $($_.name) under .deps_cache (reference only)"
}

# --- LKS vendor SDK ---
if ($IncludeLksSdk) {
    $lksCache = Join-Path $Cache "lks"
    $sdkDir = Join-Path $Root "third_party/lks32mc45x_sdk"
    New-Item -ItemType Directory -Force -Path $lksCache, $sdkDir | Out-Null

    $lksDownloads = @(
        @{ name = "LKS32MC45x_DevDriver_v2.46.zip"; url = "https://sjk.lksmcu.com/static/upload/file/20230113/lks32mc45x_periph_driver_v2.46.zip"; dest = "LKS32MC45x_DevDriver" },
        @{ name = "Linko.LKS45x_Keil5_v1.24.zip"; url = "https://sjk.lksmcu.com/static/upload/file/20230113/Linko.LKS45x_v1.24.zip"; dest = "Linko.LKS45x_Keil5" }
    )
    if ($IncludePeripDemo) {
        $lksDownloads += @{ name = "LKS32MC45x_PeripDemo_v3.01.zip"; url = "https://sjk.lksmcu.com/static/upload/file/20230113/lks32mc45x_demo_prj_v3.01.zip"; dest = "LKS32MC45x_PeripDemo" }
    }

    foreach ($d in $lksDownloads) {
        $zip = Join-Path $lksCache $d.name
        Write-Host "Downloading $($d.name)..."
        curl.exe -L -o $zip $d.url
        if ($LASTEXITCODE -ne 0) { throw "curl failed for $($d.name)" }
        $extract = Join-Path $lksCache ($d.dest + "_extract")
        if (Test-Path $extract) { Remove-Item $extract -Recurse -Force }
        Expand-Archive -Path $zip -DestinationPath $extract -Force
        $inner = Get-ChildItem $extract | Select-Object -First 1
        $dest = Join-Path $sdkDir $d.dest
        if (Test-Path $dest) { Remove-Item $dest -Recurse -Force }
        Copy-Item $inner.FullName $dest -Recurse -Force
        Write-Host "  Installed $dest"
    }

  # Device register headers (lks32mc45x.h, basic.h) live in the Keil pack, not DevDriver.
  $keilRoot = Join-Path $sdkDir "Linko.LKS45x_Keil5"
  $packFile = Get-ChildItem $keilRoot -Filter "*.pack" -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
  if ($packFile) {
    $packExtract = Join-Path $lksCache "keil_pack_inner"
    if (Test-Path $packExtract) { Remove-Item $packExtract -Recurse -Force }
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    [System.IO.Compression.ZipFile]::ExtractToDirectory($packFile.FullName, $packExtract)
    $deviceInc = Join-Path $packExtract "Device\Include"
    $destInc = Join-Path $sdkDir "device\Include"
    if (Test-Path $deviceInc) {
      New-Item -ItemType Directory -Force -Path $destInc | Out-Null
      Copy-Item (Join-Path $deviceInc "*") $destInc -Force
      Write-Host "  Installed device headers -> $destInc"
    } else {
      Write-Warning "Keil pack missing Device/Include — copy lks32mc45x.h manually"
    }
  } else {
    Write-Warning "Keil .pack not found under $keilRoot — device headers not installed"
  }
}

Write-Host "Done."
