//InputManagerGLFW.hpp

#pragma once

#include <GLFW/glfw3.h>
#include  "../View/Camera.hpp"
#include "EventManager.h"

class InputManagerGLFW
{
  public:
	  static InputManagerGLFW& getInstance();
	  InputManagerGLFW(InputManagerGLFW const&) = delete;
	  void operator=(InputManagerGLFW const&) = delete;

	  static void processKeyboard(GLFWwindow * window);

  private:
	  InputManagerGLFW() {}
};