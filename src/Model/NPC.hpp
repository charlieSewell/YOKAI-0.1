#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "View/Renderer/Shader.hpp"

class NPC : public GameObject {
  public:
    NPC(std::string modelName);
    void draw(Shader &shader);
    glm::mat4 getViewMatrix();
    glm::vec3 getPosition();

  private:
    int modelID;
    glm::mat4 one;
    glm::vec3 two;
};