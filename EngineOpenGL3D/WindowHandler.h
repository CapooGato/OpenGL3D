#pragma once
// Klasa do zarz�dzania oknem, przydatne bo MakeWindow ma tez obsluge b��d�w i nie trzeba tego
// robi� r�cznie przy ka�dym tworzeniu okna, etc. 

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
	GLFWwindow* window = nullptr; // �eby nie by�o wisz�cego wska�nika

	GLFWwindow* Make_window(); 
	// Przeci��ona metoda 
	GLFWwindow* Make_window(int width, int height, const char winName[50]);
	void Destroy_window();

};