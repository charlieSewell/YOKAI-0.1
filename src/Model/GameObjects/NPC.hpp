#pragma once
#include <glm/glm.hpp>
#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/AutomatedBehaviours.hpp"
#include <Controller/Animator.hpp>
#include "Controller/LuaManager.hpp"
/**
 * @class NPC
 * @brief Child of GameObject for all NPC's within the game. Inherits physics component.
 */
class NPC : public GameObject
{
  public:
    /*!
     * @brief Constructor
     * @param string - modelName
     */
    NPC(std::string modelName);
    ~NPC();

    /*!
     * @brief Draw call for the NPC model
     */
    void draw();
    void update(float dt) override;
    void setCollider(float width, float height, float length) override;
	
    /*!
     * @brief Getter for the position of the NPC
     * @return position
     */
    //glm::vec3 getPosition();


	static void registerClass();

private:
	//Coponents
	AutomatedBehaviours m_behaviours;
	PhysicsComponent m_physicsComponent;
	Animator animator;

	void groupAlert();	//bad
    /// Stores associated model id of the NPC
    int modelID;

	luabridge::LuaRef luaUpdate = LuaManager::getInstance().getState();
};
