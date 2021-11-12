
#include "Window.h"

int main()
{
  
	Window window(800, 800,"Window");
	

	window.clear(1,0,0,1);
	while (window.isOpen()) {

		glfwPollEvents();

	}


}
