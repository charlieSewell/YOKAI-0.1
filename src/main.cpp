

#include <glad/glad.h>
#include <glfw/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <glm/glm.hpp>
void error_callback(int error, const char* description)
{
    std::cout << "Error:"<< error << " "<< description<<  std::endl;
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
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }
    glfwDestroyWindow(window);
    return 0;
}