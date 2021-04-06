#pragma once
#include <iostream>

#include <glm/glm.hpp>

#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "View/Renderer/Shader.hpp"

class NPC : public GameObject, public PhysicsComponent
{
  public:
    NPC(std::string modelName);
    void draw();
    glm::mat4 getViewMatrix();
    glm::vec3 getPosition();
	void setCollider(float width, float length, float height);

  private:
    int modelID;
    glm::mat4 one;
    glm::vec3 two;
};