#include "Input.h"

namespace Input
{

InputManager* InputManager::instance = nullptr;


InputManager::InputManager()
{
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

} // namespace Input