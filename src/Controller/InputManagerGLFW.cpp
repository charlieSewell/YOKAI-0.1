//InputManagerGLFW.cpp

#include "InputManagerGLFW.hpp"

InputManagerGLFW& InputManagerGLFW::getInstance()
{
	static InputManagerGLFW instance;
	return instance;
}

void InputManagerGLFW::processKeyboard(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        EMS::getInstance().fire(NoReturnEvent::closePressed);
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_RELEASE)
        EMS::getInstance().fire(NoReturnEvent::closeReleased);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::moveForward);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::moveBackward);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::moveLeft);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::moveRight);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        EMS::getInstance().fire(NoReturnEvent::jump);
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::moveDown);

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::togglePhysicsPressed);
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
		EMS::getInstance().fire(NoReturnEvent::togglePhysicsReleased);

	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::toggleWireFramePressed);
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
		EMS::getInstance().fire(NoReturnEvent::toggleWireFrameReleased);

    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        EMS::getInstance().fire(NoReturnEvent::toggleMenuPressed);
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_RELEASE)
        EMS::getInstance().fire(NoReturnEvent::toggleMenuReleased);
	//not implemented yet
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		EMS::getInstance().fire(NoReturnEvent::increaseSpeed);

	//UI TESTING
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        EMS::getInstance().fire(NoReturnEvent::uiPressed);
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_RELEASE)
        EMS::getInstance().fire(NoReturnEvent::uiReleased);
	//

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
        EMS::getInstance().fire(NoReturnEvent::mouseClicked);

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
        EMS::getInstance().fire(NoReturnEvent::mouseReleased);

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

	EMS::getInstance().fire(NoReturnEvent::xyLook, xoffset, yoffset);

	lastX = xpos;
	lastY = ypos;
}