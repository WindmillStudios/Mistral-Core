target_sources(${PROJECT_NAME} PRIVATE
		Color.h
		Component.h
		DefaultRenderPipeline.h
		ImGuiConfigCustom.h
		IRenderPipeline.h
		Matrix.h
		Mistral.h
		Quaternion.h
		Random.h
		Resources.h
		Spatial.h
		Vector.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})