#include <iostream>
#include <glad/glad.h>
#include "core/graphics/Buffers.hpp"
#include "core/graphics/Shader.hpp"
#include "core/Window.hpp"
#include "spdlog/spdlog.h"
#include "util/FileIO.hpp"
#include <memory>
#include <string>
#include <vector>

#include <glm/vec3.hpp>

#include "core/Log.h"

int main()
{
	Log::Init(LOG_LEVEL_INFO);

	std::shared_ptr<Platform::Window> window = std::make_shared<Platform::Window>();

	std::vector<double> data = {
		0.0, 0.5, 0.0,
		0.5, -0.5, 0.0,
		-0.5, -0.5, 0.0
	};

	std::vector<double> vertices = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
	};

	std::vector<unsigned int> indices = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
	};

	Graphics::VAO* vao = new Graphics::VAO();

  Graphics::VBO* vbo = new Graphics::VBO();
  vbo->BufferData(vertices, GL_STATIC_DRAW);

	Graphics::EBO* ebo = new Graphics::EBO();
	ebo->BufferData(indices, GL_STATIC_DRAW);

	Graphics::Shader basic("./Assets/basic.vert", "./Assets/basic.frag");

  vao->spec(0, 3, GL_DOUBLE, 3* sizeof(double), (void*)0);

	int vertexColorLocation = glGetUniformLocation(basic.getProgram(), "ourColor");

	double i{0.0};
	while(!window->isClosed())
	{
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		glUniform4f(vertexColorLocation, 0.0f, sin(i/10), 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		window->prepareFrame();	
		i++;
	}

	return 0;
}
