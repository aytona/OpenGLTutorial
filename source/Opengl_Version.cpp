//
//  Opengl_Version.cpp
//  UaR_OpenGL
//
//  Created by Christopher Aytona on 2016-03-01.
//
//

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main(int argc, char* argv[])
{
    GLFWwindow* window;
    
    if (!glfwInit())
        exit (EXIT_FAILUTRE);
    window = glfwCreateWindow(900, 900, "Version", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILUTRE);
    }
    
    const GLubyte* p = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << p << endl;
    
    
    return 0;
}