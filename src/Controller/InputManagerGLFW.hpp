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

	  void processKeyboard(GLFWwindow * window);
	  void processMouse(GLFWwindow* window);

  private:
	  InputManagerGLFW() : mouseInit(0) {}

	  bool mouseInit;
	  double lastX, lastY;
};