//PhysicsComponemt.hpp

#pragma once

#include "Controller/Physics/PhysicsSystem.hpp"
#include "Controller/EventManager.hpp"
#include "Model/Components/Transform.hpp"

/**
 * @class PhysicsComponent
 * @brief Physics component to be attatched to object
 */
class PhysicsComponent
{
public:
  /**
   * @brief Updates Physics
   * @param float - movementSpeed
   * @param float - jumpSpeed
   */
	void updatePhysics(float &movementSpeed, float jumpSpeed);

//protected:
  /**
   * @brief Constructor For Physics Components
   */
	PhysicsComponent() {}

	/**
	* @brief Constructor For Physics Components
	* @param Transfomr - transform
	*/
	PhysicsComponent(Transform &transform);

    /**
   * @brief Destructor For Physics Components
   */
	virtual ~PhysicsComponent() {}

    /**
     * @brief Register ReactBoxShape
     * @param vec3* - position
     * @param float - width
     * @param float - length
     * @param float - height
     */
    void registerAABB(unsigned int ID, float width, float height, float length);

    RigidBody * getCollider();
    void deleteCollider();
    void registerSphere(unsigned int ID, float radius);
    /**
     * @brief Registers Physics Toggle
     */
	void registerPhysicsToggle();
    ///ReactBoxShape Collider
	//ReactBoxShape* m_collider;
    ///Objects Mass
	float m_mass;
    ///is on ground
	bool m_onGround = false;
    ///is collision detected
	bool m_collisionDetected;
    ///is collision resolved
	bool m_resolvingCollision;
    ///is physics active
	bool m_physicsActive = true;

private:
  /**
   * @brief Updates Gravity
   * @param float - jumpSpeed
   */
	void updateGravity(float jumpSpeed);
    /**
     * @brief Resolves Collisions
     * @param float - movementSpeed
     */
	void resolveCollisions(float &movementSpeed);
    ///is physics toggle pressed
	bool m_physicsTogglePressed = false;
	unsigned int colliderID = -1;
	Transform* m_transformPtr;

    void resolveCollisions(int colliderID);
};
