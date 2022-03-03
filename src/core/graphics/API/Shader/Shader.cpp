#include "Shader.hpp"
#include "glad/glad.h"
#include "../../../../util/FileIO.hpp"
#include "../../../../util/StringUtils.hpp"
#include "../../../Log.h"

#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Graphics {

	void Shader::initializeShaderInfo(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
	{
		this->vertex.id = glCreateShader(GL_VERTEX_SHADER);
		this->fragment.id = glCreateShader(GL_FRAGMENT_SHADER);
		this->vertex.sourcePath = vertexFile;
		this->fragment.sourcePath = fragmentFile;
		this->vertex.source = Utils::fileToString(this->vertex.sourcePath.string());
		this->fragment.source = Utils::fileToString(this->fragment.sourcePath.string());
	}

	void compileShader(Graphics::ShaderInfo &shaderInfo)
	{
		const char* src = shaderInfo.source.c_str();
		glShaderSource(shaderInfo.id, 1, &src, NULL);
		glCompileShader(shaderInfo.id);
	}

	Shader::Shader(std::filesystem::path vertexFile, std::filesystem::path fragmentFile)
	{
		initializeShaderInfo(vertexFile, fragmentFile);
		Graphics::compileShader(this->vertex);
		Graphics::compileShader(this->fragment);

		Shader::checkShaderCompilation(this->vertex.id, "VERTEX");
		Shader::checkShaderCompilation(this->fragment.id, "FRAGMENT");

		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertex.id);
		glAttachShader(this->program, this->fragment.id);
		glLinkProgram(this->program);
		glUseProgram(this->program);

		this->getUniformLocations();
	}

	void Shader::getUniformLocations()
	{
		std::vector<std::string> tokens;

		Utils::tokenize(this->vertex.source, tokens);
		Utils::tokenize(this->fragment.source, tokens);

		for(int i=0; i<tokens.size(); i++)
		{
			if((tokens[i] == "uniform") && (tokens[i+1].find("sampler") == std::string::npos))
			{
				this->uniformMap[tokens[i+2]] = glGetUniformLocation(this->program,
																														 tokens[i+2].c_str());
			}
		}
	}

	void Shader::setVec3(const std::string& var, const glm::vec3& data)
	{
		glUniform3f(this->uniformMap[var], data.x, data.y, data.z);
	}

	void Shader::setMat4(const std::string& var, const glm::mat4& data)
	{
		// glUniform3f(this->uniformMap[var], data.x, data.y, data.z);
		glUniformMatrix4fv(this->uniformMap[var], 1, GL_FALSE, glm::value_ptr(data));
	}

	Graphics::ShaderProgram Shader::getProgram()
	{
		return this->program;
	}
}
