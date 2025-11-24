#pragma once

#include <filesystem>

#include "Mistral.h"

namespace Mistral
{
	enum class ResourceType
	{
		None,
		Texture,
		Sound,
		Model,
		Font
	};

	struct Resource
	{
		ResourceType type = ResourceType::None;

		union
		{
			Texture texture;
			Sound sound;
			Model model;
			Font font;
		};
	};

	bool ResourceLoad(const std::filesystem::path& path);

	bool ResourceUnload(const std::filesystem::path& path);

	Resource& ResourceGet(const std::filesystem::path& path);

	Texture& GetTexture(const std::filesystem::path& path);

	Sound& GetSound(const std::filesystem::path& path);

	Model& GetModel(const std::filesystem::path& path);

	Font& GetFont(const std::filesystem::path& path);

	const std::filesystem::path& GetExecutablePath();

	const std::filesystem::path& GetResourcesPath();

	const std::filesystem::path& GetEditorResourcesPath();
} // namespace Mistral