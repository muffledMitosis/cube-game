#include "Input.h"
#include "GLFW/glfw3.h"
#include <functional>
#include <unordered_map>
#include "../Log.h"

namespace Input
{

InputManager* InputManager::instance = nullptr;
std::vector<MouseCB> InputManager::mouseFunctions;


InputManager::InputManager()
{
	GLFWwindow* win = glfwGetCurrentContext();
	glfwSetCursorPosCallback(win, InputManager::mouse_cb);
}

	void InputManager::mouse_cb(GLFWwindow* window, double xpos, double ypos){
			for(auto& cbfunc : mouseFunctions)
			{
				cbfunc(window, xpos, ypos);
			}
		}

InputManager::~InputManager()
{
}

InputManager* InputManager::getInstance()
{
	if(instance == 0)
	{
		instance = new InputManager();
	}

	return instance;
}

void InputManager::attachFunction(const int& key, const Input::InputCB& cb)
{
	this->keyFunctionTable[key].push_back(cb);
}

void InputManager::PollInputs(Platform::Window* window)
{
	// for(int i=0; i<this->keyFunctionTable.size(); i++)
	for(auto& it : this->keyFunctionTable)
	{
		if(glfwGetKey(window->getRawWindow(), it.first) == GLFW_PRESS)
		{
			for(auto& cbfunc : this->keyFunctionTable[it.first])
			{
				cbfunc();
			}
		}
	}
}

} // namespace Input
