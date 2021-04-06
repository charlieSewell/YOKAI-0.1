//Camera.hpp
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
    public:
        Camera();

        glm::mat4 getViewMatrix();
        void registerViewMatrix();
        void registerPerspective();
	    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);	
        glm::vec3 m_frontDirection = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 m_upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 m_perspective = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 10000.0f);
};
