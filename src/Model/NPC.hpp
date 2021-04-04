#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "View/Renderer/Shader.hpp"

class NPC : public GameObject {
  public:
    NPC(std::string modelName);
    void draw(Shader &shader, glm::vec3 position);

  private:
    ModelManager modelManager;
    int modelID;
    // glm::mat4 position;
};