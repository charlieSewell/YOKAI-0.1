//
// Created by charl on 6/04/2021.
//

#ifndef ICT397_GAME_ENGINE_WINDOW_HPP
#define ICT397_GAME_ENGINE_WINDOW_HPP
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
/**
 * @class Window
 * @brief Creates a window for rendering
 */
class Window {
  public:
    /**
     * @brief Default Constructor for window
     */
    Window();
    /**
     * @brief Initialises the window
     * @return bool
     */
    bool Init();
    /**
     * @brief Destroys the window
     */
    void DeInit();
    /**
     * @brief Returns a pointer to the window
     * @return GLFWwindow*
     */
    GLFWwindow* getWindow();
    /**
     * @brief Ends a frame and processes callbacks
     */
    void endFrame();
  private:
    GLFWwindow* window;
};

#endif // ICT397_GAME_ENGINE_WINDOW_HPP
