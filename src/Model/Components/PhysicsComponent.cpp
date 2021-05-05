//PhysicsComponent.cpp - manages physics

#include "PhysicsComponent.hpp"

void PhysicsComponent::updatePhysics(float &movementSpeed, float jumpSpeed)
{
	updateGravity(jumpSpeed);
	resolveCollisions(movementSpeed);
}

void PhysicsComponent::resolveCollisions(float &movementSpeed)
{
	AABB* otherCollider = nullptr;
	otherCollider = PhysicsManager::getInstance().checkCollisions(m_collider);
	m_collisionDetected = (otherCollider != nullptr);

	if(m_collisionDetected)
	{
		if(m_collider->getPosition()-> y > otherCollider->getAABBPoints().ymax)		//on top of hit box
		{
			m_onGround = true;
			m_mass = 0;
		}
		else
		{
			m_collider->getPosition()->x += (m_collider->getPosition()->x - otherCollider->getPosition()->x) * movementSpeed;
			m_collider->getPosition()->z += (m_collider->getPosition()->z - otherCollider->getPosition()->z) * movementSpeed;
		}
	}
	else
		m_mass = 0.125f;		//TODO unhardcode this cuntc
}

void PhysicsComponent::registerPhysicsToggle()
{
	auto togglePhysicsReleased = [&]()
	{	
		if(m_physicsTogglePressed)
			m_physicsTogglePressed = false;
	};
	EMS::getInstance().add(NoReturnEvent::togglePhysicsReleased, togglePhysicsReleased);

	auto togglePhysicsPressed = [&]()
	{
		if(!m_physicsTogglePressed)
		{
			m_physicsActive = !m_physicsActive;
			m_physicsTogglePressed = true;
		}
	};
	EMS::getInstance().add(NoReturnEvent::togglePhysicsPressed, togglePhysicsPressed);
}

//easy to implement if needed
/*void PhysicsComponent::registerBoundingSphere(glm::vec3 *position, double radius)
{
	m_colliderID = PhysicsManager::getInstance().addBoundingSphere(position, radius);
}*/

void PhysicsComponent::registerAABB(glm::vec3* position, float width, float length, float height)
{
	m_collider = PhysicsManager::getInstance().addAABB(position, width, length, height);
}

void PhysicsComponent::updateGravity(float jumpSpeed)
{
	float distanceFromGround = PhysicsManager::getInstance().checkTerrainCollision(m_collider);

	if(distanceFromGround < m_collider->getHeight()/2)
		m_collider->getPosition()->y += jumpSpeed;	// move up with the terrain
	else
	{
		if(distanceFromGround > m_collider->getHeight() / 2 + 1)		//+1 buffer
		{
			m_collider->getPosition()->y -= m_mass;	//apply gravity
			m_onGround = false;
		}
		else
			m_onGround = true;
	}
}