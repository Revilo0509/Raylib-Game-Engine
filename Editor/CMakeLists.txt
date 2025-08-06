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

# --- Executable ---
add_executable(${PROJECT_NAME} ${SRC_FILES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Editor/resources"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
)

# Copy RevRLCore.dll to editor output dir
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:RRE>
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    raylib
    RRE
)