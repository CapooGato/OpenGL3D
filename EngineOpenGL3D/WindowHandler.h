#pragma once
// Klasa do zarz¹dzania oknem, przydatne bo MakeWindow ma tez obsluge b³êdów i nie trzeba tego
// robiæ rêcznie przy ka¿dym tworzeniu okna, etc. 

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

#include"LibrariesHandler.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
const char WINDOW_NAME[50] = "3D Engine";

class WindowHandler
{
public:
	GLFWwindow* window = nullptr; // ¯eby nie by³o wisz¹cego wskaŸnika

	GLFWwindow* Make_window(); 
	// Przeci¹¿ona metoda 
	GLFWwindow* Make_window(int width, int height, const char winName[50]);
	void Destroy_window();

};