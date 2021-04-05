//PhysicsComponent.cpp - manages physics

#include "PhysicsComponent.hpp"

#include <iostream>
void PhysicsComponent::updatePhysics(int colliderID, float &movementSpeed, float jumpSpeed)
{
	updateGravity(colliderID, jumpSpeed);
	resolveCollisions(colliderID, movementSpeed);
}

void PhysicsComponent::resolveCollisions(int colliderID, float &movementSpeed)
{
	bool collision = PhysicsManager::getInstance().checkCollisions(colliderID);
	if(!m_resolvingCollision && collision)
	{
		movementSpeed = -movementSpeed*2;
		m_mass = 0;
		m_resolvingCollision = true;
	}
	else
		if(m_resolvingCollision && !collision)
		{
			movementSpeed = -movementSpeed/2;
			m_mass = 0.125f;
			m_resolvingCollision = false;
		}
		else
			if(!collision)
				m_resolvingCollision=false;
}

//easy to implement if needed
/*void PhysicsComponent::registerBoundingSphere(glm::vec3 *position, double radius)
{
	m_colliderID = PhysicsManager::getInstance().addBoundingSphere(position, radius);
}*/

void PhysicsComponent::registerAABB(glm::vec3* position, float width, float length, float height)
{
	m_colliderID = PhysicsManager::getInstance().addAABB(position, width, length, height);
}


void PhysicsComponent::updateGravity(int colliderID, float jumpSpeed)
{
	float distanceFromGround = PhysicsManager::getInstance().checkTerrainCollision(m_colliderID);

	AABB collider = PhysicsManager::getInstance().getCollider(colliderID);

	if(distanceFromGround < collider.getHeight()/2)
		collider.getPosition()->y += jumpSpeed;	// move up with the terrain
	else
	{
		if(distanceFromGround > collider.getHeight() / 2 + 1)		//+1 buffer
		{
			collider.getPosition()->y -= m_mass;	//apply gravity
			m_onGround = false;
		}
		else
			m_onGround = true;
	}
}