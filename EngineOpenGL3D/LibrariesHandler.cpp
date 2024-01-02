#include"LibrariesHandler.h" 

void Libraries::InitGLFW(){

	if (!glfwInit()) {
		std::cerr << "\nError loading glfw\n";
		glfwTerminate();
		return;
	}else
		std::cout << "\nSuccesfully loaded glfw\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Libraries::InitGlad(){

	if (!gladLoadGL()) {
		std::cerr << "\nError loading glad\n";
		glfwTerminate();
		return;
	}else 
		std::cout << "\nSuccesfully loaded glad\n";
}

void Libraries::TerminateAll() {

	glfwTerminate();
}