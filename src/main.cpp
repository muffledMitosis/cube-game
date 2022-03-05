#include <iostream>
#include <glad/glad.h>
#include "core/graphics/API/Buffers.hpp"
#include "core/graphics/API/Shader/Shader.hpp"
#include "core/Window.hpp"
#include "spdlog/spdlog.h"
#include "util/FileIO.hpp"
#include <memory>
#include <string>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "core/Log.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
// #include <imgui_stdlib.h>

int main()
{
	Log::Init(LOG_LEVEL_INFO);

	std::shared_ptr<Platform::Window> window = std::make_shared<Platform::Window>(800, 600);

	// std::vector<double> data = {
	// 	0.0, 0.5, 0.0, 				1.0, 0.0, 0.0,
	// 	0.5, -0.5, 0.0, 			0.0, 1.0, 0.0,
	// 	-0.5, -0.5, 0.0, 			0.0, 0.0, 1.0
	// };

	// std::vector<double> data = {
	// 	0.0, 0.5, 0.0,
	// 	0.5, -0.5, 0.0,
	// 	-0.5, -0.5, 0.0
	// };

	// std::vector<double> vertices = {
	// 	// Vertex          // Colors      // TexCoords
  //    0.5,  0.5, 0.0,  1.0, 0.0, 0.0, 	1.0, 1.0,
  //    0.5, -0.5, 0.0,  0.0, 1.0, 0.0,  1.0, 0.0,
  //   -0.5, -0.5, 0.0,  0.0, 0.0, 1.0,  0.0, 0.0,
  //   -0.5,  0.5, 0.0,  0.5, 0.5, 0.5,  0.0, 1.0
	// };

	// std::vector<unsigned int> indices = {  // note that we start from 0!
  //   0, 1, 3,   // first triangle
  //   1, 2, 3    // second triangle
	// };

	std::vector<double> cube_vertices = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

	Graphics::VAO* vao = new Graphics::VAO();

  Graphics::VBO* vbo = new Graphics::VBO();
  vbo->BufferData(cube_vertices, GL_STATIC_DRAW);

	// Graphics::EBO* ebo = new Graphics::EBO();
	// ebo->BufferData(indices, GL_STATIC_DRAW);

	Graphics::Shader basic("./Assets/basic.vert", "./Assets/basic.frag");
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Graphics::Texture* texture2 = new Graphics::Texture("Assets/textures/awesomeface.png", "texture2");
	Graphics::Texture* texture1 = new Graphics::Texture("Assets/textures/wall.jpg", "texture1");

  // vao->spec(0, 3, GL_DOUBLE, 8* sizeof(double), 0);
	// vao->spec(1, 3, GL_DOUBLE, 8* sizeof(double), 3*sizeof(double));
	// vao->spec(2, 2, GL_DOUBLE, 8* sizeof(double), 6*sizeof(double));

	vao->spec(0, 3, GL_DOUBLE, 5*sizeof(double), 0);
	vao->spec(1, 2, GL_DOUBLE, 5*sizeof(double), 3*sizeof(double));

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	// glm::mat4 view = glm::mat4(1.0f);
	// view = glm::translate(view, glm::vec3(0.0f, -0.05f, -0.17f));

	// glm::mat4 proj = glm::mat4(1.0);
	glm::mat4 proj;
	proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


	double i{0.0};
	float trans[] = {0.0f, -0.05f, -0.17f};
	float rot[] = {0.0f, 0.0f, 0.0f};

	glEnable(GL_DEPTH_TEST);

	ImGui::CreateContext();

	ImGuiIO &io = ImGui::GetIO();
	// io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui_ImplGlfw_InitForOpenGL(window->getRawWindow(), true);
	ImGui_ImplOpenGL3_Init();

	while(!window->isClosed())
	{


		// basic.setVec3("lol", glm::vec3(sin(i/1000)));
		basic.setVec3("lol", glm::vec3(1));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(trans[0], trans[1], trans[2]));

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(rot[0]), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rot[1]), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rot[2]), glm::vec3(0.0f, 0.0f, 1.0f));

		basic.setMat4("model", model);
		basic.setMat4("view", view);
		basic.setMat4("projection", proj);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

		{
			ImGui::SliderFloat3("Trans", trans, -5.0f, 5.0f);
			ImGui::SliderFloat3("Rot", rot, 0.0, 360.0);
		}
		

		ImGui::Render();

		GLFWwindow* backup_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_context);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		// ImGui::EndFrame();


		window->prepareFrame();	
		i++;
	}

	return 0;
}