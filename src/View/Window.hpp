#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
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
    bool ImguiInit();
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

