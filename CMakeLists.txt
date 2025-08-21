cmake_minimum_required(VERSION 3.15)
project(RRE VERSION 1.0 LANGUAGES C CXX)

# --- Source Files ---
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# --- External Dependencies ---
include(FetchContent)

# raylib
find_package(raylib CONFIG)
if (NOT raylib_FOUND)
    message(STATUS "raylib not found. Fetching via FetchContent.")
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
    )
    FetchContent_MakeAvailable(raylib)
endif()

# box2d
find_package(box2d CONFIG)
if (NOT box2d_FOUND)
    message(STATUS "Box2D not found. Fetching via FetchContent")
    FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v3.1.1
    )
    FetchContent_MakeAvailable(box2d)
endif()

# --- Library ---
add_library(RRE SHARED ${SRC_FILES})

target_include_directories(RRE PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(RRE PUBLIC 
    raylib
    box2d
)

# --- Examples (optional) ---
option(BUILD_EXAMPLES "Build example programs" OFF)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
