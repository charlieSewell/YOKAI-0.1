#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "View/Renderer/Shader.hpp"
#include "Model/Components/AutomatedBehaviours.hpp"
#include <Controller/Animator.hpp>
/**
 * @class NPC
 * @brief Child of GameObject for all NPC's within the game. Inherits physics component.
 */
class NPC : public GameObject//, public PhysicsComponent
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
    void update(float dt) override;
    void setCollider(float x, float y, float z) override;
    /*!
     * @brief Getter for the position of the NPC
     * @return position
     */
    //glm::vec3 getPosition();


private:
	AutomatedBehaviours m_behaviours;
    /// Stores associated model id of the NPC
    int modelID;
    Animator animator;
};