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
    //void draw();

  private:
    ModelManager modelManager;
    int modelID;
    //glm::mat4 position;
};