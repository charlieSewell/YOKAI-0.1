//PhysicsComponemt.hpp

#pragma once

#include "PhysicsManager.hpp"

class PhysicsComponent
{
public:
	void updatePhysics(glm::vec3* position, float movementSpeed);

protected:
	PhysicsComponent() {}
	virtual ~PhysicsComponent() {}

	void registerBoundingSphere(glm::vec3 *position, double radius);

	int m_colliderID;
	float m_gravityValue;

	bool m_onGround;
	bool m_physicsActive;

private:
	void updateGravity(glm::vec3 *position, float movementSpeed);
};