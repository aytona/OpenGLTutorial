//
//  GL_Version.cpp
//  UaR_OpenGL
//
//  Created by Christopher Aytona on 2016-03-02.
//
//

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"

int main(int argc, char** argv)
{
    GLFWwindow* window;
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(900, 900, "OpenGL Version", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    const GLubyte* p = glGetString(GL_VERSION);
    std::cout << "OpenGL: " << p << std::endl;
    
    return 0;
}