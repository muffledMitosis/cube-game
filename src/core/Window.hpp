#pragma once
#include <GLFW/glfw3.h>

namespace Platform {

class Window {
public:
	Window();
	~Window();

	void prepareFrame();
	bool isClosed();
private:
	GLFWwindow* m_rawWindow;
};

}

