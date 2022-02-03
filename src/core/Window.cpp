#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"

namespace Platform {

Window::Window()
{
	glfwInit();
	this->m_rawWindow = glfwCreateWindow(800, 600, "Cube Game", nullptr, nullptr);
	glfwMakeContextCurrent(this->m_rawWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(this->m_rawWindow);
}

void Window::prepareFrame()
{
	glfwSwapBuffers(this->m_rawWindow);
	glfwPollEvents();
}

}


