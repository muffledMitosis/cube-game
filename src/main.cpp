#include <iostream>
#include <glad/glad.h>
#include "core/graphics/Buffers.hpp"
#include "core/graphics/Shader.hpp"
#include "core/Window.hpp"
#include "util/FileIO.hpp"
#include <string>
#include <vector>

int main()
{
	Platform::Window* window = new Platform::Window();

	std::vector<double> data = {
		0.0, 0.5, 0.0,
		0.5, -0.5, 0.0,
		-0.5, -0.5, 0.0
	};

  // unsigned int VAO;
  // glGenVertexArrays(1, &VAO);
  // glBindVertexArray(VAO);
	Graphics::VAO* vao = new Graphics::VAO();

  Graphics::VBO* vbo = new Graphics::VBO();
  vbo->BufferData(data, GL_STATIC_DRAW);

	Graphics::Shader basic("./Assets/basic.vert", "./Assets/basic.frag");

  vao->spec(0, 3, GL_DOUBLE, 3* sizeof(double), (void*)0);

	while(!window->isClosed())
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window->prepareFrame();	
	}

	return 0;
}
