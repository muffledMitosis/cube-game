#include <iostream>
#include <glad/glad.h>
#include "core/graphics/Shader.hpp"
#include "core/Window.hpp"
#include "util/FileIO.hpp"
#include <string>

int main()
{
	Platform::Window* window = new Platform::Window();

	double vertices[] = {
		0.0, 0.5, 0.0,
		0.5, -0.5, 0.0,
		-0.5, -0.5, 0.0
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Graphics::Shader basic("./Assets/basic.vert", "./Assets/basic.frag");

	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
	glEnableVertexAttribArray(0);

	

	while(!window->isClosed())
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window->prepareFrame();	
	}

	return 0;
}
