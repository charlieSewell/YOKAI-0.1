//InputManagerGLFW.cpp

#include "InputManagerGLFW.hpp"

InputManagerGLFW& InputManagerGLFW::getInstance()
{
	static InputManagerGLFW instance;
	return instance;
}

void InputManagerGLFW::processKeyboard(GLFWwindow* window)
{
    if (//glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS ||
		glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        EMS::getInstance().fire(InputEvent::closePressed);

    if (//glfwGetKey(window, GLFW_KEY_X) == GLFW_RELEASE || 
		glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE)
        EMS::getInstance().fire(InputEvent::closeReleased);

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::jump);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveForward);

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveBackward);

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveLeft);

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveRight);

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::moveDown);

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::zombieRotateLeft);

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::zombieRotateRight);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::zombieMoveForward);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE)
		EMS::getInstance().fire(InputEvent::zombieStopped);

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::togglePhysicsPressed);

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
		EMS::getInstance().fire(InputEvent::togglePhysicsReleased);

	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		EMS::getInstance().fire(InputEvent::toggleWireFramePressed);

	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
		EMS::getInstance().fire(InputEvent::toggleWireFrameReleased);

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        EMS::getInstance().fire(InputEvent::toggleMenuPressed);

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_RELEASE)
        EMS::getInstance().fire(InputEvent::toggleMenuReleased);
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

void InputManagerGLFW::processMouse(GLFWwindow* window)
{
    if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        EMS::getInstance().fire(InputEvent::mouseClicked);
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (!mouseInit)
	{
		lastX = xpos;
		lastY = ypos;
		mouseInit = true;
	}

	double xoffset = xpos - lastX;
	double yoffset = ypos - lastY;

	EMS::getInstance().fire(InputEvent::xyLook, xoffset, yoffset);

	lastX = xpos;
	lastY = ypos;
}