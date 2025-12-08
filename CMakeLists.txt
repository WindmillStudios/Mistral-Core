cmake_minimum_required(VERSION 3.16)
project(mistral VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Colors.cmake)
message_color(${BoldCyan} "================ Configuring ${PROJECT_NAME} CMake project ================")
message_color(${BoldYellow} "Adding source files to ${PROJECT_NAME}")

add_library(${PROJECT_NAME} STATIC)
add_subdirectory(include)
add_subdirectory(src)
include(cmake/Dependencies.cmake)
message("")