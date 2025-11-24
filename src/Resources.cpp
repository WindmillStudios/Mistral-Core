#include "Resources.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#define NOGDI
	#define NOUSER
	#include <libloaderapi.h>
	#include <windows.h>
#elif defined(__linux__)
	#include <limits.h>
	#include <unistd.h>
#endif

namespace
{
	std::map<std::filesystem::path, Mistral::Resource, std::less<>> resources;
} // namespace

static bool FileIsSupported(const std::filesystem::path& path,
							const std::vector<std::string>& extensions)
{
	return std::ranges::any_of(extensions, [path](const std::string& extension) {
		return path.extension() == extension;
	});
}

bool Mistral::ResourceLoad(const std::filesystem::path& path)
{
	if (!std::filesystem::exists(path))
	{
		std::cerr << "[Error] Resource not found: " << path << std::endl;
		return false;
	}

	Resource resource;
	if (FileIsSupported(path, {".png", ".bmp", ".tga", ".jpg", ".gif", ".qoi", ".psd",
							   ".dds", ".hdr", ".ktx", ".astc", ".pkm", ".pvr"}))
	{
		resource.type = ResourceType::Texture;
		resource.texture = LoadTexture(path.string().c_str());
	}
	else if (FileIsSupported(path,
							 {".wav", ".ogg", ".mp3", ".flac", ".xm", ".mod", ".qoa"}))
	{
		resource.type = ResourceType::Sound;
		resource.sound = LoadSound(path.string().c_str());
	}
	else if (FileIsSupported(path, {".obj", ".iqm", ".gltf", ".vox", ".m3d", ".glb"}))
	{
		resource.type = ResourceType::Model;
		resource.model = LoadModel(path.string().c_str());
	}
	else if (FileIsSupported(path, {".ttf", ".otf"}))
	{
		resource.type = ResourceType::Font;
		resource.font = LoadFont(path.string().c_str());
	}

	resources.emplace(path, resource);
	return true;
}

bool Mistral::ResourceUnload(const std::filesystem::path& path)
{
	if (resources.contains(path))
	{
		auto& res = resources.at(path);

		switch (res.type)
		{
			case ResourceType::Texture:
				UnloadTexture(res.texture);
				break;
			case ResourceType::Sound:
				UnloadSound(res.sound);
				break;
			case ResourceType::Model:
				UnloadModel(res.model);
				break;
			case ResourceType::Font:
				UnloadFont(res.font);
				break;
			default:
				break;
		}

		resources.erase(path);
		return true;
	}
	return false;
}

Mistral::Resource& Mistral::ResourceGet(const std::filesystem::path& path)
{
	if (!resources.contains(path))
	{
		if (!ResourceLoad(path))
		{
			std::cout << "Could not get the resource: " << path.filename() << std::endl;
			static Resource dummy;
			return dummy;
		}
	}

	return resources.at(path);
}

Texture& Mistral::GetTexture(const std::filesystem::path& path)
{
	return ResourceGet(path).texture;
}

Sound& Mistral::GetSound(const std::filesystem::path& path)
{
	return ResourceGet(path).sound;
}

Model& Mistral::GetModel(const std::filesystem::path& path)
{
	return ResourceGet(path).model;
}

Font& Mistral::GetFont(const std::filesystem::path& path)
{
	return ResourceGet(path).font;
}

const std::filesystem::path& Mistral::GetExecutablePath()
{
	static std::filesystem::path executablePath;

	if (executablePath.empty())
	{
#if defined(_WIN32)
		char buffer[MAX_PATH];
		GetModuleFileNameA(nullptr, buffer, MAX_PATH);
		executablePath = std::filesystem::path(buffer);
#elif defined(__linux__)
		char buffer[PATH_MAX];
		ssize_t count = readlink("/proc/self/exe", buffer, PATH_MAX);
		if (count != -1)
		{
			executablePath =
				std::filesystem::path(std::string(buffer, (count > 0) ? count : 0));
		}
#endif
		executablePath = executablePath.parent_path();
	}

	return executablePath;
}

const std::filesystem::path& Mistral::GetResourcesPath()
{
	static std::filesystem::path resourcesPath;
	if (resourcesPath.empty())
	{
		resourcesPath = GetExecutablePath() / "game_resources";
	}
	return resourcesPath;
}

const std::filesystem::path& Mistral::GetEditorResourcesPath()
{
	static std::filesystem::path editorResourcesPath;
	if (editorResourcesPath.empty())
	{
		editorResourcesPath = GetExecutablePath() / "editor_resources";
	}
	return editorResourcesPath;
}
