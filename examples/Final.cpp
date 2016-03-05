//
//  Final.cpp
//  UaR_OpenGL
//
//  Created by Christopher Aytona on 2016-03-04.
//
//

#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"

static int size = 900;

int main(int argc, char** argv)
{
#pragma region Create Context
    
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window;
    window = glfwCreateWindow(size, size, "OpenGL Tutorial", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
#pragma endregion Create Context
    
#pragma region Initialize GLEW
    
    glewExperimental = true;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        std::cout << "Glew init error" << std::endl << glewGetErrorString(glewError) << std::endl;
    }
    
#pragma region Support Checker
    
    if (!GLEW_VERSION_2_1)
    {
        std::cout << "OpenGL 2.1 not supported!" << std::endl;
        return false;
    }
    if (GLEW_ARB_vertex_array_object)
    {
        std::cout << "genVertexArrays supported" << std::endl;
    }
    if (GLEW_APPLE_vertex_array_object)
    {
        std::cout << "genVertextArrayApple supported" << std::endl;
    }
    
#pragma endregion Support Checker
    
#pragma endregion Initialize GLEW
    
#pragma region Main Loop
    
    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0, size, size);
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
#pragma endregion Main Loop
    
#pragma region Termination
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
#pragma endregion Termination
    
#pragma region Version
    
    const GLubyte* p = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << p << std::endl;
    
#pragma endregion Version
    return 0;
}