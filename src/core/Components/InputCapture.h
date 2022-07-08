#pragma once

#include "../Component.hpp"
#include "../Input/Input.h"

class InputCapture : public Component
{
public:
	InputCapture();
	InputCapture(const int& key, const Input::InputCB& cb);
	~InputCapture();
	void attachCB(const int& key, const Input::InputCB& cb);
	static void attachMouseFunction(const Input::MouseCB& cb);
};

