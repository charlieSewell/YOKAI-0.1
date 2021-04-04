//PhysicsComponent.cpp - manages physics

#include "PhysicsComponent.hpp"


void PhysicsComponent::updatePhysics(glm::vec3* position, float movementSpeed)
{
	updateGravity(position, movementSpeed);
}

void PhysicsComponent::registerBoundingSphere(glm::vec3 *position, double radius)
{
	m_colliderID = PhysicsManager::getInstance().addBoundingSphere(position, radius);
}

void PhysicsComponent::updateGravity(glm::vec3* position, float movementSpeed)
{
	double distanceFromGround = PhysicsManager::getInstance().checkTerrainCollision(m_colliderID);

	// TODO: these numbers will be the bounds of the collider
	if(distanceFromGround < 1)
		position->y += movementSpeed;	// move up with the terrain
	else
	{
		if(distanceFromGround > 2)
		{
			position->y -= m_gravityValue;	//apply gravity
			m_onGround = false;
		}
		else
			m_onGround = true;
	}
}