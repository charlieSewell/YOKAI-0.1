//
// Created by charl on 6/04/2021.
//

#ifndef ICT397_GAME_ENGINE_WINDOW_HPP
#define ICT397_GAME_ENGINE_WINDOW_HPP
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
class Window {
  public:
    Window();
    bool Init();
    void DeInit();
    GLFWwindow* getWindow();
    void endFrame();
  private:
    GLFWwindow* window;
};

#endif // ICT397_GAME_ENGINE_WINDOW_HPP
