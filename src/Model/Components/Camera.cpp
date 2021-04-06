#include "Camera.hpp"

#include "Controller/EventManager.hpp"

Camera::Camera() 
{
    registerViewMatrix();
    registerPerspective();
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
void Camera::registerPerspective()
{
    auto perspective = [&]()
    {
        return m_perspective;
    };

    EMS::getInstance().add(RenderEvent::getPerspective, perspective);
}