#pragma once
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/AutomatedBehaviours.hpp"

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

    /*!
     * @brief Getter for the position of the NPC
     * @return position
     */
    //glm::vec3 getPosition();

    /*!
     * @brief Setter for the NPC collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	void setCollider(float width, float length, float height);

	void test();

	static void registerClass();

private:
	AutomatedBehaviours m_behaviours;
    /// Stores associated model id of the NPC
    int modelID;
};
