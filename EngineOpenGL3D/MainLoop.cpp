#include "MainLoop.h"
#include "LibrariesHandler.h"
#include "WindowHandler.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
void MainLoop::Run()
{
	Libraries::InitGLFW();
	
	// Tworzymy okno
	WindowHandler window1;
	window1.Make_window(650, 700, "Capoo Capoo");

	glfwMakeContextCurrent(window1.window);
	
	Libraries::InitGlad(); // Koniecznie Po glfwMakeContextCurrent, nie przed

	// chuj wie wsm ale od 0, 0 do szerekosc, wysokosc
	glViewport(0, 0, window1.width, window1.height); // Musi byc po zaladowaniu glad 
	
	// kolor malowania tla
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// czyszczenie koloru
	glClear(GL_COLOR_BUFFER_BIT);
	// swapowanie buforow kolorw
	glfwSwapBuffers(window1.window);

	while (!glfwWindowShouldClose(window1.window))
	{
		glfwPollEvents();

	}

	window1.Destroy_window();
	Libraries::TerminateAll();
}