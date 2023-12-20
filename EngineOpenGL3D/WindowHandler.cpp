#include "WindowHandler.h"

GLFWwindow* WindowHandler::Make_window()
{
	this->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "\nBlad tworzenia okna\n";
		Libraries::TerminateAll();
		return nullptr;
	}
	else {
		this->width = WINDOW_WIDTH;
		this->height = WINDOW_HEIGHT;
		return this->window;
	}
}

GLFWwindow* WindowHandler::Make_window(int width, int height, const char winName[50])
{
	this->window = glfwCreateWindow(width, height, winName, nullptr, nullptr);
	
	if (window == nullptr)
	{
		std::cout << "\nBlad tworzenia okna\n";
		Libraries::TerminateAll();
		return nullptr;
	}
	else {
		this->width = width;
		this->height = height;
		return this->window;
	}
}

void WindowHandler::Destroy_window()
{
	glfwDestroyWindow(this->window);
}
