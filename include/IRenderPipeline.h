#pragma once

namespace Mistral
{
	class IRenderPipeline
	{
	  public:

		virtual ~IRenderPipeline() = default;

		virtual void Initialize() = 0;

		virtual void RenderEvent() = 0;
	};
} // namespace Mistral