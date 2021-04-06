//PhysicsComponemt.hpp

#pragma once

#include "PhysicsManager.hpp"
#include "Controller/EventManager.h"

class PhysicsComponent
{
public:
	void updatePhysics(float &movementSpeed, float jumpSpeed);

protected:
	PhysicsComponent() {}
	virtual ~PhysicsComponent() {}

	//void registerBoundingSphere(glm::vec3 *position, double radius);
	void registerAABB(glm::vec3* position, float width, float length, float height);
	void registerPhysicsToggle(bool &physicsActive);

	AABB* m_collider;
	float m_mass;

	bool m_onGround;
	bool m_collisionDetected;
	bool m_resolvingCollision;
	bool m_physicsActive;

private:
	void updateGravity(float jumpSpeed);
	void resolveCollisions(float &movementSpeed);
	bool m_physicsTogglePressed;
};