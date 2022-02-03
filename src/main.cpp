#include <iostream>
#include "core/Window.hpp"

int main()
{
	Platform::Window* window = new Platform::Window();

	while(!window->isClosed())
	{
		window->prepareFrame();	
	}

	return 0;
}
