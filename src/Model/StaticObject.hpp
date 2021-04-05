#pragma once
#include <glm/glm.hpp>
#include "GameObject.hpp"
#include "Controller/ModelManager.hpp"
#include "View/Renderer/Shader.hpp"
#include "Controller/Physics/PhysicsComponent.hpp"
#include <iostream>

class StaticObject : public GameObject, public PhysicsComponent
{
  public:
    StaticObject(std::string modelName);
    void draw(Shader &shader);
    glm::mat4 getViewMatrix();
    glm::vec3 getPosition();

	void setCollider(float width, float length, float height);

  private:
    int modelID;
    glm::mat4 one;
    glm::vec3 two;
};