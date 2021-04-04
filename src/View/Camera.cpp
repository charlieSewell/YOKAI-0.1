#include "Camera.hpp"

Camera::Camera() {}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_frontDirection, m_upDirection);
}