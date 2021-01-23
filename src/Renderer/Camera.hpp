//
// Created by charl on 22/01/2021.
//

#ifndef ICT397_GAME_ENGINE__CAMERA_HPP
#define ICT397_GAME_ENGINE__CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
  public:
    Camera(float x,float y, float z){
        cameraPos = glm::vec3(x,y,z);
        fov = 45.0f;
    }
    glm:: mat4 getViewMatrix(){return glm::lookAt(cameraPos, cameraPos + cameraFront,glm::vec3(0,1,0));}
  private:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    float fov;
    

};

#endif // ICT397_GAME_ENGINE__CAMERA_HPP
