#pragma once

#include "IRenderPipeline.h"

namespace Mistral
{
	class DefaultRenderPipeline final : public IRenderPipeline
	{
	  public:

		~DefaultRenderPipeline() override = default;

		void Initialize() override;

		void RenderEvent() override;
	};
}