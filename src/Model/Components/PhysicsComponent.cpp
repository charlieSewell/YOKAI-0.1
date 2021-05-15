//PhysicsComponent.cpp - manages physics

#include "PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent(Transform &transform)
	: m_transformPtr(&transform)
{

}

void PhysicsComponent::updatePhysics(float &movementSpeed, float jumpSpeed)
{
	//updateGravity(jumpSpeed);
	//resolveCollisions(movementSpeed);
}

void PhysicsComponent::resolveCollisions(float &movementSpeed)
{
	/*AABB* otherCollider = nullptr;
	otherCollider = PhysicsManager::getInstance().checkCollisions(m_collider);
	m_collisionDetected = (otherCollider != nullptr);

	if(m_collisionDetected)
	{
		if(m_collider->getPosition().y > otherCollider->getAABBPoints().ymax)		//on top of hit box
		{
			m_onGround = true;
			m_mass = 0;
		}
		else
		{
			m_collider->getPosition().x += (m_collider->getPosition().x - otherCollider->getPosition().x) * movementSpeed;
			m_collider->getPosition().z += (m_collider->getPosition().z - otherCollider->getPosition().z) * movementSpeed;
		}
	}
	else
		m_mass = 0.125f;		//TODO unhardcode this cuntc

	*/
}

void PhysicsComponent::registerPhysicsToggle()
{
	/*auto togglePhysicsReleased = [&]()
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
	*/
}

//easy to implement if needed
/*void PhysicsComponent::registerBoundingSphere(glm::vec3 *position, double radius)
{
	m_colliderID = PhysicsManager::getInstance().addBoundingSphere(position, radius);
}*/

void PhysicsComponent::registerAABB(float width, float length, float height)
{
	//m_collider = PhysicsManager::getInstance().addAABB(m_transformPtr, width, length, height);
}

void PhysicsComponent::updateGravity(float jumpSpeed)
{
	/*float distanceFromGround = PhysicsManager::getInstance().checkTerrainCollision(m_collider);

	if(distanceFromGround < m_collider->getHeight()/2)
		m_transformPtr->translate(0, jumpSpeed, 0);
	else
	{
		if(distanceFromGround > m_collider->getHeight() / 2 + 1)		//+1 buffer
		{
			m_transformPtr->translate(0, -m_mass, 0); //apply gravity
			m_onGround = false;
		}
		else
			m_onGround = true;
	}
	*/
}