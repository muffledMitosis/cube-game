#include "Shader.hpp"
#include "glad/glad.h"
#include "../../../util/FileIO.hpp"

#include <vector>
#include <sstream>
#include <string>
#include <iostream>

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

		this->getUniformLocations();

		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertex.id);
		glAttachShader(this->program, this->fragment.id);
		glLinkProgram(this->program);
		glUseProgram(this->program);
	}

	void Shader::getUniformLocations()
	{
		std::vector<std::string> tokens;

		std::string delim = " ";
		std::string token;
		size_t pos =0;

		std::cout<<this->vertex.source << std::endl;

		while((pos = this->vertex.source.find(delim)) != std::string::npos)
		{
			token = this->vertex.source.substr(0, pos);
			std::cout<<token<<std::endl;
			tokens.push_back(token);
			this->vertex.source.erase(0, pos + delim.length());
		}

		// ss = std::stringstream(this->fragment.source);
		// while(getline(ss, inter, " "))
		// {
		// 	tokens.push_back(inter);
		// }

		// std::vector<std::string> uniformNames;
		//
		// for(int i=0; i<tokens.size(); i++)
		// {
		// 	if(tokens[i] == "uniform")
		// 	{
		// 		uniformNames.push_back(tokens[i+2]);
		// 	}
		// }
		//
		// for(std::string uniform : uniformNames)
		// {
		// 	std::cout<<uniform<<std::endl;
		// }

	}

	Graphics::ShaderProgram Shader::getProgram()
	{
		return this->program;
	}
}
