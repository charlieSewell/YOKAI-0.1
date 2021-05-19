//PhysicsComponent.cpp - manages physics

#include "PhysicsComponent.hpp"
#include <glm/gtx/string_cast.hpp>
PhysicsComponent::PhysicsComponent(Transform &transform)
	: m_transformPtr(&transform)
{

}

void PhysicsComponent::updatePhysics(float &movementSpeed, float jumpSpeed)
{
    auto& physManager = PhysicsSystem::getInstance();

    rp3d::Vector3 position(m_transformPtr->getPosition().x,m_transformPtr->getPosition().y, m_transformPtr->getPosition().z);
    rp3d::Quaternion orientation = rp3d::Quaternion::identity();
    rp3d::Transform reactTransform(position, orientation);

	physManager.getCollider(colliderID)->setTransform(reactTransform);
    //updateGravity(jumpSpeed);
	resolveCollisions(movementSpeed);
    m_transformPtr->setPosition(physManager.getCollider(colliderID)->getTransform().getPosition().x,physManager.getCollider(colliderID)->getTransform().getPosition().y,physManager.getCollider(colliderID)->getTransform().getPosition().z);


}

void PhysicsComponent::resolveCollisions(float &movementSpeed)
{
    /*
    auto& physManager = PhysicsSystem::getInstance();
    int otherColliderID = physManager.checkCollisions(colliderID);
    bool m_collisionDetected = (otherColliderID != -1);

    if(m_collisionDetected)
    {
        if(physManager.getCollider(colliderID)->getTransform().getPosition().y > physManager.getCollider(otherColliderID)->getTransform().getPosition().y)		//on top of hit box
        {
            m_onGround = true;
            m_mass = 0;
        }
        else
        {
            float newX = physManager.getCollider(colliderID)->getTransform().getPosition().x + ((physManager.getCollider(colliderID)->getTransform().getPosition().x - physManager.getCollider(otherColliderID)->getTransform().getPosition().x) * movementSpeed);
            float newZ =  physManager.getCollider(colliderID)->getTransform().getPosition().z + ((physManager.getCollider(colliderID)->getTransform().getPosition().z - physManager.getCollider(otherColliderID)->getTransform().getPosition().z) * movementSpeed);

            rp3d::Vector3 position(newX, physManager.getCollider(colliderID)->getTransform().getPosition().y, newZ);
            rp3d::Quaternion orientation = rp3d::Quaternion::identity();
            rp3d::Transform reactTransform(position, orientation);

            physManager.getCollider(colliderID)->setTransform(reactTransform);
        }
    }
    else
    {
        m_mass = 0.125f;
    }
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
	m_colliderID = PhysicsSystem::getInstance().addBoundingSphere(position, radius);
}*/

void PhysicsComponent::registerAABB(float width, float length, float height)
{
	colliderID = PhysicsSystem::getInstance().addAABB(m_transformPtr, width, length, height);
}

void PhysicsComponent::updateGravity(float jumpSpeed)
{
    /*
	bool isColliding = PhysicsSystem::getInstance().checkTerrainCollision(colliderID);
    auto& physManager = PhysicsSystem::getInstance();
	if(isColliding)
    {
        rp3d::Vector3 position(physManager.getCollider(colliderID)->getTransform().getPosition().x, physManager.getCollider(colliderID)->getTransform().getPosition().y + jumpSpeed, physManager.getCollider(colliderID)->getTransform().getPosition().z);
        rp3d::Quaternion orientation = rp3d::Quaternion::identity();
        rp3d::Transform reactTransform(position, orientation);
        PhysicsSystem::getInstance().getCollider(colliderID)->setTransform(reactTransform);
    }
	else
	{
		if(!isColliding)
		{
            rp3d::Vector3 position(physManager.getCollider(colliderID)->getTransform().getPosition().x, physManager.getCollider(colliderID)->getTransform().getPosition().y -m_mass, physManager.getCollider(colliderID)->getTransform().getPosition().z);
            rp3d::Quaternion orientation = rp3d::Quaternion::identity();
            rp3d::Transform reactTransform(position, orientation);
            PhysicsSystem::getInstance().getCollider(colliderID)->setTransform(reactTransform);
			m_onGround = false;
		}
		else
        {
            m_onGround = true;
        }

	}
*/
}