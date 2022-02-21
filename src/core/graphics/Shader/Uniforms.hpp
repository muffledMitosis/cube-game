#pragma once

#include "Shader.hpp"
#include <glm/glm.hpp>
#include <string>

namespace Graphics::Uniform {

void setUniform(const Graphics::ShaderProgram& program, const std::string& var, const glm::vec4& data)
{
	int location = glGetUniformLocation(program, var.c_str());
	glUniform4f(location, data.x, data.y, data.z, data.w);
}

}

