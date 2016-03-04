//
//  GLFW_Window.cpp
//  UaR_OpenGL
//
//  Created by Christopher Aytona on 2016-03-03.
//
//

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"

int main(int argc, char** argv)
{
#pragma region Initialization
    // Initializing OpenGL and creating a window
    if (!glfwInit())
        exit(EXIT_FAILURE);
    GLFWwindow* window;
    window = glfwCreateWindow(900, 900, "GLFW Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
#pragma endregion Initialization
    
#pragma region Main_Loop
    while(!glfwWindowShouldClose(window))
    {
        // OpenGL functions
        glViewport(0, 0, 900, 900);
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // GLFW functions
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
#pragma endregion Main_Loop
    
#pragma region Termination
    glfwDestroyWindow(window);
    glfwTerminate();
#pragma endregion Termination
    
    return 0;
}