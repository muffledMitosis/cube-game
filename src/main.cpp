#include <iostream>
#include <glad/glad.h>
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

	std::string vertSrc = Utils::fileToString("./Assets/basic.vert");
	std::cout << vertSrc << std::endl;

	unsigned int vertShader;
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	const char* cvsrc = vertSrc.c_str();
	glShaderSource(vertShader, 1, &cvsrc, NULL);
	glCompileShader(vertShader);



	std::string fragSrc = Utils::fileToString("./Assets/basic.frag");
	std::cout << fragSrc << std::endl;

	unsigned int fragShader;
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* cfsrc = fragSrc.c_str();
	glShaderSource(fragShader, 1, &cfsrc, NULL);
	glCompileShader(fragShader);


	unsigned int shaderProg;
	shaderProg = glCreateProgram();
	glAttachShader(shaderProg, vertShader);
	glAttachShader(shaderProg, fragShader);
	glLinkProgram(shaderProg);

	glUseProgram(shaderProg);

	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
	glEnableVertexAttribArray(0);

	

	while(!window->isClosed())
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		window->prepareFrame();	
	}

	return 0;
}
