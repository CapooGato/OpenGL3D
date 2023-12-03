#include"LibrariesHandler.h" 

void Libraries::InitAll(){

	glfwInit();	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Libraries::TerminateAll() {

	glfwTerminate();
}