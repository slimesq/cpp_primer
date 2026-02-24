cmake_minimum_required(VERSION 3.20)
project(cpp_primer LANGUAGES CXX)

# Global C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compilation Warning
if(MSVC)
    add_compile_options(/W4 /permissive-)
    add_compile_options(/utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(WIN32)
    add_compile_definitions(ENABLE_CONSOLE_UTF8)
endif()

file(GLOB chapters RELATIVE ${CMAKE_CURRENT_LIST_DIR} *)

include(cmake/common.cmake)

add_subdirectory(ch005_statement)
add_subdirectory(ch006_function)
add_subdirectory(ch007_class)
add_subdirectory(ch008_ioLibrary)
