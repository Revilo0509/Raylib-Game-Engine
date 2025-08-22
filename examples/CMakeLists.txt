# Only define executables if BUILD_EXAMPLES is ON
if(NOT BUILD_EXAMPLES)
    return()
endif()

# Output directory for example binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")

# Find all example source files
file(GLOB EXAMPLE_SOURCES "*.cpp")

# Create an executable for each example
foreach(EXAMPLE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})

    # Link with RRE
    target_link_libraries(${EXAMPLE_NAME} PRIVATE RRE)

    # Include directories
    target_include_directories(${EXAMPLE_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../libs"
    )
endforeach()

# Copy resources to the output directory
set(EXAMPLE_RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/resources")
if(EXISTS ${EXAMPLE_RESOURCES})
    add_custom_command(TARGET ${EXAMPLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${EXAMPLE_RESOURCES}"
        "$<TARGET_FILE_DIR:${EXAMPLE_NAME}>/resources"
    )
endif()
