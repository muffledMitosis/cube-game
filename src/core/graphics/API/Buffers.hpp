#pragma once

#include <cstdint>
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace Graphics {

class VBO
{
public:
	unsigned int id;
	VBO();
	void BufferData(std::vector<double> &data, int streamType);
	void Bind();
};

class VAO
{
public:
	unsigned int id;
	VAO();
	void Bind();
	void spec(const int& index, const int& size, const int& dataType, const int& stride, const int& offset);
};

class EBO
{
public:
	unsigned int id;
	EBO();
	void Bind();
	void BufferData(std::vector<unsigned int> &data, int streamType);
};

struct ImageInfo
{
	int width, height, channelNum;
	unsigned char* image_data;
};

struct TextureInfo
{
	int location;
	unsigned long long unit;
};

class Texture
{
private:
	unsigned int id;
	Graphics::ImageInfo imageInfo;
public:
	static std::unordered_map<std::string, Graphics::TextureInfo> texturePool;
	Texture(std::filesystem::path texturePath, std::string varName);
	void Bind();
	~Texture();
};


}
