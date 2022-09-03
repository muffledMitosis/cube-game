#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

namespace Platform {

class Window {
public:
	Window(unsigned int width, unsigned int height);
	~Window();

	void prepareFrame();
	glm::vec2 getDimensions();
	GLFWwindow* getRawWindow();
	bool isClosed();

	glm::vec2 dimensions;
private:
	GLFWwindow* m_rawWindow;
};

}

