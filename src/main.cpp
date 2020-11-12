

#include <glad/glad.h>
#include <glfw/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <glm/glm.hpp>
void error_callback(int error, const char* description)
{
    std::cout << "Error: %s\n"<< std::endl;
}


int main() {
    if (!glfwInit())
    {
        return -1;
    }

    glfwSetErrorCallback(error_callback);


    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGL())
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    while (!glfwWindowShouldClose(window))
    {


    }
    glfwDestroyWindow(window);
    return 0;
}