#pragma once
#include <glm/glm.hpp>
#include "GameObject.hpp"
#include "Controller/ModelManager.hpp"
#include "View/Renderer/Shader.hpp"
#include <iostream>

class StaticObject : public GameObject 
{
  public:
    StaticObject(std::string modelName);
    void draw(Shader &shader);
    glm::mat4 getViewMatrix();
    glm::vec3 getPos();

  private:
    int modelID;
    glm::mat4 one;
    glm::vec3 two;
};