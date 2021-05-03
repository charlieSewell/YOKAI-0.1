#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "View/Renderer/Shader.hpp"

/**
 * @class StaticObject
 * @brief Child of GameObject for all static objects within the game. Inherits physics component.
 */
class StaticObject : public GameObject, public PhysicsComponent
{
  public:
    /*!
     * @brief Constructor
     * @param string - modelName
     */
    StaticObject(std::string modelName);

    /*!
     * @brief Draw call for the staticObject model
     */
    void draw() override;

    /*!
     * @brief Getter for the position of the staticObject
     * @return position
     */
    glm::vec3 getPosition();

    /*!
     * @brief Setter for the staticObject collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	void setCollider(float width, float length, float height) override;

  private:
    /// Stores associated model id of the staticObject
    int modelID;

    /// Position of the staticObject
    glm::vec3 position;
};