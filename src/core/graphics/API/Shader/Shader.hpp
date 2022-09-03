#pragma once
#include <string>
#include <filesystem>
#include <unordered_map>
#include "../../../Log.h"
#include "glad/glad.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	std::unordered_map<std::string, int> uniformMap;

	Graphics::ShaderProgram program;
	Graphics::ShaderInfo vertex, fragment;
	void initializeShaderInfo(std::filesystem::path vertexFile, std::filesystem::path fragmentFile);
	void compileShader(Graphics::ShaderInfo &shaderInfo);
	void getUniformLocations();

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
	void setVec3(const std::string& var, const glm::vec3& data);
	void setMat4(const std::string& var, const glm::mat4& data);

	Graphics::ShaderProgram getProgram();
};

}
