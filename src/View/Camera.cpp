//
// Created by charl on 22/01/2021.
//
#include "Camera.hpp"

Camera::Camera() {}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}