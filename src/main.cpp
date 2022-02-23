#include <iostream>
#include <glad/glad.h>
#include "core/graphics/Buffers.hpp"
#include "core/graphics/Shader/Shader.hpp"
#include "core/Window.hpp"
#include "spdlog/spdlog.h"
#include "util/FileIO.hpp"
#include <memory>
#include <string>
#include <vector>

#include <glm/vec3.hpp>

#include "core/Log.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int main()
{
	Log::Init(LOG_LEVEL_INFO);

	std::shared_ptr<Platform::Window> window = std::make_shared<Platform::Window>();

	std::vector<double> data = {
		0.0, 0.5, 0.0, 				1.0, 0.0, 0.0,
		0.5, -0.5, 0.0, 			0.0, 1.0, 0.0,
		-0.5, -0.5, 0.0, 			0.0, 0.0, 1.0
	};

	// std::vector<double> data = {
	// 	0.0, 0.5, 0.0,
	// 	0.5, -0.5, 0.0,
	// 	-0.5, -0.5, 0.0
	// };

	std::vector<double> vertices = {
		// Vertex          // Colors      // TexCoords
     0.5,  0.5, 0.0,  1.0, 0.0, 0.0, 	1.0, 1.0,
     0.5, -0.5, 0.0,  0.0, 1.0, 0.0,  1.0, 0.0,
    -0.5, -0.5, 0.0,  0.0, 0.0, 1.0,  0.0, 0.0,
    -0.5,  0.5, 0.0,  0.5, 0.5, 0.5,  0.0, 1.0
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
	
	int width, height, channelNum;
	unsigned char* imageData = stbi_load("Assets/textures/wall.jpg", &width, &height, &channelNum, 0);

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(imageData);

  vao->spec(0, 3, GL_DOUBLE, 8* sizeof(double), 0);
	vao->spec(1, 3, GL_DOUBLE, 8* sizeof(double), 3*sizeof(double));
	vao->spec(2, 2, GL_DOUBLE, 8* sizeof(double), 6*sizeof(double));

	double i{0.0};
	while(!window->isClosed())
	{
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// Graphics::Uniform::setUniform(basic.getProgram(), "ourColor", glm::vec4(0.0, sin(i/10), 0.0, 1.0));
		basic.setVec3("lol", glm::vec3(sin(i/10)));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		window->prepareFrame();	
		i++;
	}

	return 0;
}
