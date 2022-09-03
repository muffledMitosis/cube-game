#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <functional>

namespace Input
{
	class InputManager
	{
	private:
	 static InputManager* instance;
	 std::unordered_map<int, std::vector<std::function<void(GLFWwindow*)>>> keyFunctionTable;
	InputManager();
		
	public:
	 static InputManager* getInstance();
	 void attachFunction();
		~InputManager();
	};
} // namespace Input
