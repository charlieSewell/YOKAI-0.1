#include "Camera.hpp"
#include "Controller/EventManager.h"

Camera::Camera() 
{
    registerViewMatrix();
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_frontDirection, m_upDirection);
}

void Camera::registerViewMatrix()
{
    auto viewMatrix = [&]()
    {
      return glm::lookAt(m_position, m_position + m_frontDirection, m_upDirection);
    };

    EMS::getInstance().add(RenderEvent::getViewMatrix, viewMatrix);
}