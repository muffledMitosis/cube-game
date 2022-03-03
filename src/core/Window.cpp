#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"

namespace Platform {

Window::Window(unsigned int width, unsigned int height)
{
	glfwInit();
	this->m_rawWindow = glfwCreateWindow(width, height, "Cube Game", nullptr, nullptr);
	glfwMakeContextCurrent(this->m_rawWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	this->dimensions = glm::vec2(width, height);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(this->m_rawWindow);
}

glm::vec2 Window::getDimensions()
{
	return this->dimensions;
}

void Window::prepareFrame()
{
	glfwSwapBuffers(this->m_rawWindow);
	glfwPollEvents();
}

}


