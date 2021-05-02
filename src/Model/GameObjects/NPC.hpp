#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "View/Renderer/Shader.hpp"
#include "Model/Components/AutomatedBehaviours.hpp"

/**
 * @class NPC
 * @brief Child of GameObject for all NPC's within the game. Inherits physics component.
 */
class NPC : public GameObject, public PhysicsComponent, public AutomatedBehaviours
{
  public:
    /*!
     * @brief Constructor
     * @param string - modelName
     */
    NPC(std::string modelName);

    /*!
     * @brief Draw call for the NPC model
     */
    void draw();

    /*!
     * @brief Getter for the position of the NPC
     * @return position
     */
    glm::vec3 getPosition();

    /*!
     * @brief Setter for the NPC collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	void setCollider(float width, float length, float height);

  private:
    /// Stores associated model id of the NPC
    int modelID;
};