//InputManagerGLFW.cpp

#include "InputManagerGLFW.hpp"

InputManagerGLFW& InputManagerGLFW::getInstance()
{
	static InputManagerGLFW instance;
	return instance;
}

void InputManagerGLFW::processKeyboard(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveForward);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveBackward);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveLeft);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveRight);
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveUp);
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveDown);

	//not implemented yet
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::increaseSpeed);


	/*if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		if (isPressed) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			isPressed = false;
		}
		else {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			isPressed = true;
		}
	}*/
}