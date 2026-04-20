#!/bin/bash

# ZMoag Build Script for Linux/macOS
# Usage: ./build.sh [debug|release]

set -e

# Configuration
BUILD_TYPE="${1:-debug}"
BUILD_DIR="build"
INSTALL_PREFIX="${CMAKE_INSTALL_PREFIX:-.}"

# Validate build type
if [[ "$BUILD_TYPE" != "debug" && "$BUILD_TYPE" != "release" ]]; then
    echo "Error: Invalid build type '$BUILD_TYPE'"
    echo "Usage: ./build.sh [debug|release]"
    exit 1
fi

# Convert to CMake build type
CMAKE_BUILD_TYPE="Debug"
if [[ "$BUILD_TYPE" == "release" ]]; then
    CMAKE_BUILD_TYPE="Release"
fi

echo "================================"
echo "ZMoag Build Script"
echo "================================"
echo "Build Type: $CMAKE_BUILD_TYPE"
echo "Build Directory: $BUILD_DIR"
echo ""

# Check for CMake
if ! command -v cmake &> /dev/null; then
    echo "Error: CMake is not installed"
    echo "Install it with: sudo apt-get install cmake (Linux) or brew install cmake (macOS)"
    exit 1
fi

# Check for SDL3
if ! pkg-config --exists sdl3; then
    echo "Error: SDL3 is not installed"
    echo "Install it with: sudo apt-get install libsdl3-dev (Linux) or brew install sdl3 (macOS)"
    exit 1
fi

# Check for SDL2_image
if ! pkg-config --exists sdl3-image; then
    echo "Error: SDL3_image is not installed"
    echo "Install it with: sudo apt-get install libsdl3-image-dev (Linux) or brew install sdl2_image (macOS)"
    exit 1
fi

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake
echo "Running CMake..."
cmake .. \
    -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX

# Build
echo ""
echo "Building ZMoag..."
cmake --build . --config $CMAKE_BUILD_TYPE --parallel $(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

echo ""
echo "================================"
echo "Build Complete!"
echo "================================"
echo "Executable: $(pwd)/bin/ZMoag"
echo ""
echo "To run ZMoag:"
echo "  ./bin/ZMoag"
echo ""
