//
// Created by charl on 22/01/2021.
//

#include "Camera.hpp"
glm::mat4 Camera::getViewMatrix(){
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}