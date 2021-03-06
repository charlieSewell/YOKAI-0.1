//
// Created by charl on 22/01/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE__CAMERA_HPP
#define ICT397_GAME_ENGINE__CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
  public:
    Camera();
    /*Camera(float x,float y, float z){
        cameraPos = glm::vec3(x,y,z);
        fov = 45.0f;
        cameraUp = glm::vec3(0,1,0);
    }
    glm:: mat4 getViewMatrix();
  //private:
    /*glm::vec3 cameraPos;
    glm::vec3 cameraUp;
    glm::vec3 cameraFront;
    float fov;*/

    glm::mat4 getViewMatrix();

    glm::vec3 m_position = glm::vec3(0.0f, 20.0f, 90.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);


    /*new
    glm::vec3 cameraPos       = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);       // camera direction pointing in the reverse direction of what it's targeting
    glm::vec3 up              = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight     = glm::normalize(glm::cross(up, cameraDirection));
    glm::vec3 cameraUp        = glm::cross(cameraDirection, cameraRight);
    */

};

#endif // ICT397_GAME_ENGINE__CAMERA_HPP
