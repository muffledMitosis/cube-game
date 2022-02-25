#include "Buffers.hpp"
#include "glad/glad.h"
#include <vector>
#include <filesystem>
#include <unordered_map>

#include <stb_image.h>
#include "../Log.h"
#include <iostream>

namespace Graphics {
	VBO::VBO()
	{
		glGenBuffers(1, &(this->id));
		this->Bind();
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}

	void VBO::BufferData(std::vector<double> &data, int streamType)
	{
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(double), &data[0], streamType);
	}

	EBO::EBO()
	{
		glGenBuffers(1, &(this->id));
		this->Bind();
	}

	void EBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	}

	void EBO::BufferData(std::vector<unsigned int> &data, int streamType)
	{
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], streamType);
	}


	VAO::VAO()
	{
		glGenVertexArrays(1, &this->id);
		this->Bind();
	}

	void VAO::Bind()
	{
		glBindVertexArray(this->id);
	}
	
	void VAO::spec(const int& index, const int& size, const int& dataType, const int& stride, const int& offset)
	{
		this->Bind();
		glVertexAttribPointer(index, size, dataType, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(index);
	}

	std::unordered_map<std::string, Graphics::TextureInfo> Texture::texturePool;

	Texture::Texture(std::filesystem::path texturePath, std::string varName)
	{
		this->imageInfo.image_data = stbi_load(texturePath.generic_string().c_str(),
																						&this->imageInfo.width,
																						&this->imageInfo.height,
																						&this->imageInfo.channelNum, 0);

		glGenTextures(1, &this->id);
		glActiveTexture(GL_TEXTURE0 + Texture::texturePool.size());
		this->Bind();
		int format = texturePath.extension()==".png" ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0,
								 GL_RGB,
								 this->imageInfo.width,
								 this->imageInfo.height, 0,
								 format,
								 GL_UNSIGNED_BYTE,
								 this->imageInfo.image_data);
		glGenerateMipmap(GL_TEXTURE_2D);

		int currentProgram;
		glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);

		Texture::texturePool[varName] = {
			glGetUniformLocation(currentProgram, varName.c_str()),
			Texture::texturePool.size()
		};
		glUniform1i(Texture::texturePool[varName].location, Texture::texturePool[varName].unit);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, this->id);
	}

	Texture::~Texture()
	{
		stbi_image_free(this->imageInfo.image_data);
	}

}