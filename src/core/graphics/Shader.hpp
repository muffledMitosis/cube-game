#pragma once
#include <string>
#include <filesystem>

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
};

}
