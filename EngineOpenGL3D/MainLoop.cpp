#include "MainLoop.h"
#include "LibrariesHandler.h"
#include "WindowHandler.h"
#include "Cube.cpp"
#include<glad/glad.h>
#include<GLFW/glfw3.h>

void MainLoop::Run()
{
	//Libraries::InitGLFW();/////////////////////////////////////////////
	
	// Tworzymy okno
	//WindowHandler window1;/////////////////////////////////////////////////
	//window1.Make_window(650, 700, "Capoo Capoo");//////////////////////////

	//glfwMakeContextCurrent(window1.window);////////////////////////////////////////////
	
	//Libraries::InitGlad(); // Koniecznie Po glfwMakeContextCurrent, nie przed//////////////////////////////////////

	// chuj wie wsm ale od 0, 0 do szerekosc, wysokosc
	//glViewport(0, 0, window1.width, window1.height); // Musi byc po zaladowaniu glad ////////////////////////////////////
	
	// kolor malowania tla
	//glClearColor(0.07f, 0.13f, 0.17f, 1.0f);////////////////////////////////////////////////////////
	// czyszczenie koloru
	//glClear(GL_COLOR_BUFFER_BIT);  ////////////////////////////////////////////////////////////
	// 
	// swapowanie buforow kolorw
	//glfwSwapBuffers(window1.window);//////////////////////////////////////////////////
	//std::cout << "alla";/////////////////////////////////////////////////////
	Szescian szescianApp;	//doslownie ta klasa zajmuje sie wszytkim xd tam gdzie najebalem srednikow to bylo bez komentarzy a ja zrobilem zeby bylo 1 okno a nie 2

	while (!glfwWindowShouldClose(szescianApp.window))////////////////////////////////////////tu bylo window1.window
	{
		szescianApp.run();
		
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();

	}

	//window1.Destroy_window();////////////////////////////////////////////////////
	Libraries::TerminateAll();
}