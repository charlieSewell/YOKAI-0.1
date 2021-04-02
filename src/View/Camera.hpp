//Camera.hpp
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera();

    glm::mat4 getViewMatrix();
    glm::vec3 getPos();
	glm::vec3 m_position = glm::vec3(0.0f, 20.0f, 90.0f);		
    glm::vec3 m_frontDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
};
