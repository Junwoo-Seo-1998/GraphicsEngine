#pragma once
#include <memory>
#include <string>

struct TextureData;

class File
{
public:
	static std::string ReadFileToString(const std::string& file_name);
	static std::shared_ptr<TextureData> ReadImageToTexture(const std::string& file_name);
};
