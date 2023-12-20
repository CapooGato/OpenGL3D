#include"LibrariesHandler.h" 

void Libraries::InitGLFW(){

	if (!glfwInit()) {
		std::cerr << "\nBlad ladowania glfw\n";
		glfwTerminate();
		return;
	}else
		std::cout << "\nPomyslnie zaladowano glfw\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Libraries::InitGlad(){

	if (!gladLoadGL()) {
		std::cerr << "\nBlad ladowania glad\n";
		glfwTerminate();
		return;
	}else 
		std::cout << "\nPomyslnie zaladowano glad\n";
}

void Libraries::TerminateAll() {

	glfwTerminate();
}