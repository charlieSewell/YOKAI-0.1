#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>

#include "Controller/EventManager.h"


#include "Controller/Yokai.hpp"
#include "View/Camera.hpp"
#include "Controller/InputManagerGLFW.hpp"
#include "Model/Player.hpp"


void error_callback(int error, const char* description)
{
    std::cout << "Error:"<< error << " "<< description<<  std::endl;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int main() {
    auto &engine = Yokai::getInstance();
    engine.Init();
    engine.Run();
    GLFWwindow* window;
    if (!glfwInit()){
        return 0;
    }
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);
    if (!window){
        return 0;
    }
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //THIS IS ALL TEST CODE AND SUBJECT TO CHANGE DO NOT ADD RENDERING FUNCTIONS HERE
    while (!glfwWindowShouldClose(window))
    {
        //will be moved to input engine later
		InputManagerGLFW::getInstance().processKeyboard(window);
		InputManagerGLFW::getInstance().processMouse(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}