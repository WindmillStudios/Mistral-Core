cmake_minimum_required(VERSION 3.16)
project(mistral VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (WIN32)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
elseif (UNIX)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
endif ()

add_library(${PROJECT_NAME} STATIC)

add_subdirectory(include)
add_subdirectory(src)

include(Dependencies.cmake)

set(STYLE_URL "[https://raw.githubusercontent.com/Windmill-Studio/Windmill-Standards/main/.clang-format](https://raw.githubusercontent.com/Windmill-Studio/Windmill-Standards/main/.clang-format)")
set(LOCAL_STYLE_FILE "${CMAKE_SOURCE_DIR}/.clang-format")

file(DOWNLOAD "${STYLE_URL}" "${LOCAL_STYLE_FILE}" SHOW_PROGRESS)