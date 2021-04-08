//
// Created by charl on 6/04/2021.
//

#include "Window.hpp"
Window::Window(){

}
void error_callback(int error, const char* description)
{
    std::cout << "Error:" << error << " " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
bool Window::Init(){

    if (!glfwInit())
    {
        return false;
    }
    glfwWindowHint(GLFW_OPENGL_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_NATIVE_CONTEXT_API, GLFW_NATIVE_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#ifndef __APPLE__
    glfwWindowHint(GLFW_SAMPLES,4);
#endif
    window = glfwCreateWindow(1920, 1080, "ICT397 Game Engine", glfwGetPrimaryMonitor(), NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);

    if (!window)
    {
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return true;
}
void Window::DeInit() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
GLFWwindow* Window::getWindow(){
    return window;
}
void Window::endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}