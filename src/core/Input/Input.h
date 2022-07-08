#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>
#include "../Window.hpp"
#include <functional>
#include <vector>

namespace Input
{
	using InputCB = std::function<void()>;
	using MouseCB = std::function<void(GLFWwindow* window, double xpos, double ypos)>;
	class InputManager
	{
	private:
	 static InputManager* instance;
	 std::unordered_map<int, std::vector<InputCB>> keyFunctionTable;
	InputManager();
		
	public:
	 static InputManager* getInstance();
	 static void mouse_cb(GLFWwindow* window, double xpos, double ypos);
	 static std::vector<MouseCB> mouseFunctions;
	 void attachFunction(const int& key, const Input::InputCB& cb);
	 void PollInputs(Platform::Window* window);
		~InputManager();
	};
} // namespace Input
