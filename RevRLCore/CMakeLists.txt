# --- Source Files ---
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

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

# --- Library ---
add_library(RevRLCore SHARED ${SRC_FILES})

target_include_directories(RevRLCore PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs"
)

target_link_libraries(RevRLCore PUBLIC
    raylib
)
