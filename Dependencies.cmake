include(FetchContent)

# .clang-format

# raylib
FetchContent_Declare(
		raylib
		GIT_REPOSITORY https://github.com/raysan5/raylib.git
		GIT_TAG 5.5
		GIT_SHALLOW 1
)
FetchContent_MakeAvailable(raylib)

# imgui
FetchContent_Declare(
		imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui.git
		GIT_TAG v1.92.4-docking
)
FetchContent_MakeAvailable(imgui)

# raylib-imgui bridge
FetchContent_Declare(
		raylib_imgui
		GIT_REPOSITORY https://github.com/raylib-extras/imgui.git
		GIT_TAG main
)
FetchContent_MakeAvailable(raylib_imgui)

# Create imgui static lib manually
add_library(imgui STATIC
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# Create raylib-imgui static lib manually
add_library(raylib_imgui STATIC ${raylib_imgui_SOURCE_DIR}/rlImGui.cpp)

target_include_directories(raylib_imgui PUBLIC ${raylib_imgui_SOURCE_DIR})

target_link_libraries(raylib_imgui PUBLIC imgui raylib)

# Finally link the libraries into the engine
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_imgui)
target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_USER_CONFIG="ImGuiConfigCustom.h")