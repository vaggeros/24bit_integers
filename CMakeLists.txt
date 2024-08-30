cmake_minimum_required(VERSION 3.16)

project(linked_lists_implementation LANGUAGES C)

add_library(HEADER-ONLY INTERFACE)
target_include_directories(HEADER-ONLY INTERFACE ${CMAKE_SOURCE_DIR}/inc)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.c  
    ${CMAKE_SOURCE_DIR}/src/byte_conversion_utils.c       
)
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE HEADER-ONLY)