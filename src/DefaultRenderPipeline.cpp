#include "DefaultRenderPipeline.h"

#include "Mistral.h"
#include "raylib.h"

void Mistral::DefaultRenderPipeline::Initialize()
{
}

void Mistral::DefaultRenderPipeline::RenderEvent()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (const auto camera = GetActiveCamera())
	{
		BeginMode3D(*camera);

		ComponentRender3DEventCallback();

		EndMode3D();
	}

	ComponentRender2DEventCallback();

	{ // ImGui space
		rlImGuiBegin();

		ComponentRenderGUIEventCallback();

		rlImGuiEnd();
	}

	EndDrawing();
}