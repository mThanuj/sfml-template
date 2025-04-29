#!/bin/bash
set -e

# Set default build type to Debug if no argument is passed
BUILD_TYPE="${1:-debug}"

# Check if the provided build type is valid
if [[ "$BUILD_TYPE" != "debug" && "$BUILD_TYPE" != "release" ]]; then
  echo "Invalid build type. Use 'debug' or 'release'."
  exit 1
fi

# Configure CMake with the appropriate build type
cmake -S . -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE

# Build the project
cmake --build build

# Run the executable
./build/bin/CMakeSFMLProject
