#pragma once
#include <string>
#include <filesystem>
#include "../Log.h"
#include "glad/glad.h"

namespace Graphics {

struct ShaderInfo
{
	std::filesystem::path sourcePath;
	std::string source;
	unsigned int id;
};

using ShaderProgram = unsigned int;

class Shader
{
private:
	Graphics::ShaderProgram program;
	Graphics::ShaderInfo vertex, fragment;
	void initializeShaderInfo(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);
	void compileShader(Graphics::ShaderInfo &shaderInfo);

public:
//	Shader(std::string vertexSource, std::string fragmentSource);
	Shader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);

	static void checkShaderCompilation(unsigned int shaderID, std::string type)
	{
		int success;
		char infoLog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			LOG_ERROR("SHADER::{1}::COMPILATION::FAIL \n{0}" SEP infoLog SEP type);
		}
	}

	Graphics::ShaderProgram getProgram();
};

}
