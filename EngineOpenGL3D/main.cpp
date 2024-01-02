#include "LibrariesHandler.h"
#include "WindowHandler.h"
#include "Cube.cpp"
#include "Cubelmao.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>


// Vertices coordinates
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};



int main(void){
	
	// Libraries and window stuff;
	Libraries::InitGLFW();
	
	WindowHandler mainWindow;
	mainWindow.Make_window();

	glfwMakeContextCurrent(mainWindow.window);
	Libraries::InitGlad();
	glViewport(0, 0, mainWindow.width, mainWindow.height);

	//Cube cube;


	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkVBO(VBO1, 0);
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	Cube cube;

	while (!glfwWindowShouldClose(mainWindow.window)) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
	
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(mainWindow.window);

		glfwPollEvents();
	}


	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	mainWindow.Destroy_window();
	Libraries::TerminateAll();
	return 0;
}






/*
Libraries::InitGLFW();/////////////////////////////////////////////

		 Tworzymy okno
		WindowHandler window1;/////////////////////////////////////////////////
		window1.Make_window(650, 700, "Capoo Capoo");//////////////////////////

		glfwMakeContextCurrent(window1.window);////////////////////////////////////////////


Libraries::InitGlad(); // Koniecznie Po glfwMakeContextCurrent, nie przed//////////////////////////////////////

 chuj wie wsm ale od 0, 0 do szerekosc, wysokosc
glViewport(0, 0, window1.width, window1.height); // Musi byc po zaladowaniu glad ////////////////////////////////////

 kolor malowania tla
glClearColor(0.07f, 0.13f, 0.17f, 1.0f);////////////////////////////////////////////////////////
 czyszczenie koloru
glClear(GL_COLOR_BUFFER_BIT);  ////////////////////////////////////////////////////////////
 
 swapowanie buforow kolorw
glfwSwapBuffers(window1.window);//////////////////////////////////////////////////
std::cout << "alla";/////////////////////////////////////////////////////
Szescian szescianApp;	//doslownie ta klasa zajmuje sie wszytkim xd tam gdzie najebalem srednikow to bylo bez komentarzy a ja zrobilem zeby bylo 1 okno a nie 2

std::cout << "affafssfdssffssfsfsssssdsassssssassassf";


while (!glfwWindowShouldClose(szescianApp.window))////////////////////////////////////////tu bylo window1.window
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	 Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	 Pobierz macierze projekcji i widoku

	szescianApp.run();
	glfwSwapBuffers(szescianApp.window);
	glfwPollEvents();

}

window1.Destroy_window();////////////////////////////////////////////////////

		Libraries::TerminateAll();
	*/