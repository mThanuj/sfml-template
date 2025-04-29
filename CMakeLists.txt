cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Output binaries to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use FetchContent to get SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

# Automatically find all .cpp files in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create the executable with project name
add_executable(${PROJECT_NAME} ${SOURCES})

# Set C++ standard
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Include project headers if needed
target_include_directories(${PROJECT_NAME} PRIVATE src/)

# Link against SFML (Graphics includes Window and System)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)
