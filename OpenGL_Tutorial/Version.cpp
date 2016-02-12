#include <stdlib.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GL/glfw3.h"

int main(int argc, char** argv)
{
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(1024, 768, "glfw", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	const GLubyte* p = glGetString(GL_VERSION);
	std::cout << "OpenGL Version: " << p << std::endl;
	return 0;
}