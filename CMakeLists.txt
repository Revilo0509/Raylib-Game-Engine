cmake_minimum_required(VERSION 3.15)
project(RRE VERSION 1.0 LANGUAGES CXX)

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

# --- Library ---
add_library(RRE SHARED ${SRC_FILES})

target_include_directories(RRE PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(RRE PUBLIC raylib)

# --- Export & Install ---
include(GNUInstallDirs)

install(TARGETS RRE
    EXPORT RRETargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT RRETargets
    FILE RRETargets.cmake
    NAMESPACE RRE::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RRE
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/RREConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/RREConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/RREConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RRE
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/RREConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/RREConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RRE
)
