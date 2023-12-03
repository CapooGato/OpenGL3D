#include "MainLoop.h"
#include "LibrariesHandler.h"
#include "WindowHandler.h"

void MainLoop::Run()
{
	Libraries::InitAll();

	WindowHandler window1, w2;
	window1.Make_window();
	w2.Make_window(300, 300, "chuj");

	
	while (!glfwWindowShouldClose(window1.window))
	{
		glfwPollEvents();

	}

	window1.Destroy_window();
	Libraries::TerminateAll();
}