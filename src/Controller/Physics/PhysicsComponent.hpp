//PhysicsComponemt.hpp

#pragma once

#include "PhysicsManager.hpp"

class PhysicsComponent
{
public:
	void updatePhysics(int colliderID, float &movementSpeed, float jumpSpeed);

protected:
	PhysicsComponent() {}
	virtual ~PhysicsComponent() {}

	//void registerBoundingSphere(glm::vec3 *position, double radius);
	void registerAABB(glm::vec3* position, float width, float length, float height);

	int m_colliderID;
	float m_mass;

	bool m_onGround;
	bool m_collisionDetected;
	bool m_resolvingCollision;
	bool m_physicsActive;

private:
	void updateGravity(int colliderID, float jumpSpeed);
	void resolveCollisions(int colliderID, float &movementSpeed);
};