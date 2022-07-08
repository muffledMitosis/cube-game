#include "../Input/Input.h"
#include "InputCapture.h"

InputCapture::InputCapture(){}
InputCapture::~InputCapture(){}

InputCapture::InputCapture(const int& key, const Input::InputCB& cb)
{
	this->attachCB(key, cb);
}

void InputCapture::attachCB(const int& key, const Input::InputCB& cb)
{
	Input::InputManager::getInstance()->attachFunction(key, cb);
}

void InputCapture::attachMouseFunction(const Input::MouseCB& cb)
{
	Input::InputManager::mouseFunctions.push_back(cb);
}
