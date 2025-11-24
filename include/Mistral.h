#pragma once

#include "Component.h"
#include "imgui.h"
#include "IRenderPipeline.h"
#include "Random.h"
#include "raylib.h"
#include "Resources.h"
#include "rlImGui.h"
#include "Vector.h"

namespace Mistral
{
	void StartApplication(const std::string& applicationName, std::unique_ptr<IRenderPipeline> renderPipeline = nullptr);

	Camera3D* GetActiveCamera();

	void SetActiveCamera(Camera3D* camera);
} // namespace Mistral