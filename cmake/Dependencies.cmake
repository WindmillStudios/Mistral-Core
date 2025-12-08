include(FetchContent)
include(cmake/Colors.cmake)
message_color(${BoldCyan} "---------------- Downloading ${PROJECT_NAME} dependencies -----------------")

# raylib
if (NOT TARGET raylib)
	message_color(${BoldYellow} "Downlaoding Raylib")
	FetchContent_Declare(
			raylib
			GIT_REPOSITORY https://github.com/raysan5/raylib.git
			GIT_TAG 5.5
			GIT_SHALLOW 1
	)
	FetchContent_MakeAvailable(raylib)
endif ()

# imgui
if (NOT TARGET imgui)
	message_color(${BoldYellow} "Downlaoding ImGui")
	FetchContent_Declare(
			imgui
			GIT_REPOSITORY https://github.com/ocornut/imgui.git
			GIT_TAG v1.92.4-docking
	)
	FetchContent_MakeAvailable(imgui)
endif ()

add_library(imgui STATIC
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# raylib-imgui bridge
if (NOT TARGET raylib_imgui)
	message_color(${BoldYellow} "Downlaoding Raylib-ImGui bridge")
	FetchContent_Declare(
			raylib_imgui
			GIT_REPOSITORY https://github.com/raylib-extras/imgui.git
			GIT_TAG main
	)
	FetchContent_MakeAvailable(raylib_imgui)
endif ()

add_library(raylib_imgui STATIC ${raylib_imgui_SOURCE_DIR}/rlImGui.cpp)
target_include_directories(raylib_imgui PUBLIC ${raylib_imgui_SOURCE_DIR})
target_link_libraries(raylib_imgui PUBLIC imgui raylib)

# Get .clang-format from Coding-Style repo
set(STYLE_URL "https://raw.githubusercontent.com/WindmillStudios/Coding-Style/refs/heads/main/.clang-format")
set(LOCAL_STYLE_FILE "${CMAKE_CURRENT_LIST_DIR}/../.clang-format") # Find an alternative for relative path
file(DOWNLOAD "${STYLE_URL}" "${LOCAL_STYLE_FILE}")
message_color(${BoldYellow} "Downloading .clang-format")

# Link the libraries into the engine
message_color(${BoldYellow} "Linking libraries intro ${PROJECT_NAME}")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_imgui)
target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_USER_CONFIG="ImGuiConfigCustom.h")

# Hide external dependencies
set_target_properties(raylib PROPERTIES FOLDER "Dependencies")
set_target_properties(imgui PROPERTIES FOLDER "Dependencies")
set_target_properties(raylib_imgui PROPERTIES FOLDER "Dependencies")
set_target_properties(glfw PROPERTIES FOLDER "Dependencies")
set_target_properties(update_mappings PROPERTIES FOLDER "Dependencies")