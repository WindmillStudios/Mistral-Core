#include "Mistral.h"

#include "DefaultRenderPipeline.h"

namespace
{
	Camera3D* activeCamera;
}

void Mistral::StartApplication(const std::string& applicationName, std::unique_ptr<IRenderPipeline> renderPipeline)
{
	SetTraceLogLevel(LOG_NONE);
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(1280.f * 2.f, 720.f * 2.f, applicationName.c_str());
	SetTargetFPS(165);
	rlImGuiSetup(true);
	SetExitKey(KEY_NULL);

	if (!renderPipeline)
	{
		renderPipeline = std::make_unique<DefaultRenderPipeline>();
	}

	renderPipeline->Initialize();

	while (!WindowShouldClose())
	{
		ComponentCreateEventCallback();

		ComponentDestroyEventCallback();

		ComponentUpdateEventCallback();

		renderPipeline->RenderEvent();
	}

	rlImGuiShutdown();
	CloseWindow();
}

Camera3D* Mistral::GetActiveCamera()
{
	return activeCamera;
}

void Mistral::SetActiveCamera(Camera3D* camera)
{
	activeCamera = camera;
}