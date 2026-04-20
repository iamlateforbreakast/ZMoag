cmake_minimum_required(VERSION 3.16)
project(ZMoag 
    VERSION 0.1.0
    DESCRIPTION "A small SDL based isometric exploration game demonstration"
    LANGUAGES CXX C
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Platform-specific settings
if(WIN32)
    add_definitions(-DWIN32)
    set(PLATFORM_LIBS Winmm)
elseif(UNIX AND NOT APPLE)
    set(PLATFORM_LIBS m)
elseif(APPLE)
    set(PLATFORM_LIBS)
endif()

# Find SDL3 and SDL3_image
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Print found packages for debugging
message(STATUS "SDL3 found: ${SDL3_FOUND}")
message(STATUS "SDL3 include dir: ${SDL3_INCLUDE_DIRS}")
message(STATUS "SDL3 libraries: ${SDL3_LIBRARIES}")
message(STATUS "SDL3_image found: ${SDL3_image_FOUND}")
message(STATUS "SDL3_image include dir: ${SDL3_image_INCLUDE_DIRS}")
message(STATUS "SDL3_image libraries: ${SDL3_image_LIBRARIES}")

# Source files
set(SOURCES
    # Main
    src/main.cpp
    
    # Application module
    src/Application/Application.cpp
    src/Application/Application.h
    src/Application/CommandLine.cpp
    src/Application/CommandLine.h
    src/Application/FileStore.cpp
    src/Application/FileStore.h
    src/Application/GameWithMMI.cpp
    src/Application/GameWithMMI.h
    src/Application/Logger.cpp
    src/Application/Logger.h
    src/Application/Object.cpp
    src/Application/Object.h
    src/Application/Options.cpp
    src/Application/Options.h
    
    # Audio module
    src/Audio/AudioPlayer.cpp
    src/Audio/AudioPlayer.h
    
    # GUI module
    src/GUI/Button.cpp
    src/GUI/Button.h
    src/GUI/FileSelection.cpp
    src/GUI/FileSelection.h
    src/GUI/MMI.cpp
    src/GUI/MMI.h
    src/GUI/MiniMap.cpp
    src/GUI/MiniMap.h
    src/GUI/SDLSurface.cpp
    src/GUI/SDLSurface.h
    src/GUI/Screen.cpp
    src/GUI/Screen.h
    src/GUI/ScreenAction.h
    src/GUI/Struct.h
    src/GUI/ToolBar.cpp
    src/GUI/ToolBar.h
    src/GUI/ViewPort.cpp
    src/GUI/ViewPort.h
    src/GUI/Widget.cpp
    src/GUI/Widget.h
    
    # GameWorld module
    src/GameWorld/Campaign.cpp
    src/GameWorld/Campaign.h
    src/GameWorld/Corporation.cpp
    src/GameWorld/Corporation.h
    src/GameWorld/GameWorld.cpp
    src/GameWorld/GameWorld.h
    src/GameWorld/GameWorldStruct.h
    src/GameWorld/Map.cpp
    src/GameWorld/Map.h
    src/GameWorld/Mission.cpp
    src/GameWorld/Mission.h
    src/GameWorld/Player.h
    
    # Renderer module
    src/Renderer/Pixmap.cpp
    src/Renderer/Pixmap.h
    src/Renderer/PixmapArray.cpp
    src/Renderer/PixmapArray.h
    src/Renderer/Renderer.cpp
    src/Renderer/Renderer.h
)

# Include directories
set(INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/Application
    ${CMAKE_SOURCE_DIR}/src/Audio
    ${CMAKE_SOURCE_DIR}/src/GUI
    ${CMAKE_SOURCE_DIR}/src/GameWorld
    ${CMAKE_SOURCE_DIR}/src/Renderer
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_image_INCLUDE_DIRS}
)

# Create executable
add_executable(ZMoag ${SOURCES})

# Link libraries
target_link_libraries(ZMoag
    PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_image_LIBRARIES}
        ${PLATFORM_LIBS}
)

# Include directories for target
target_include_directories(ZMoag
    PRIVATE
        ${INCLUDE_DIRS}
)

# Enable testing
enable_testing()

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(ZMoag PRIVATE /W4)
else()
    target_compile_options(ZMoag PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Print build information
message(STATUS "")
message(STATUS "=== ZMoag Build Configuration ===")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Executable: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}")
message(STATUS "==================================")
message(STATUS "")
