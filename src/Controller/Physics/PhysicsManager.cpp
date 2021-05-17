//PhysicsManager.cpp - manages physics

#include "PhysicsManager.hpp"

PhysicsManager::PhysicsManager()
	: m_mapCount(0)
{
	physicsWorld = physicsCommon.createPhysicsWorld();
	physicsWorld->setEventListener(&listener);
	timeStep = 1.0f / 120.0f;
}

PhysicsManager::~PhysicsManager()
{
	std::cout << "GoodBye";
	physicsWorld->destroyCollisionBody(playerCollision);
	physicsCommon.destroyPhysicsWorld(physicsWorld);
}


PhysicsManager& PhysicsManager::getInstance()
{
    static PhysicsManager instance;
    return instance;
}

void PhysicsManager::update(Transform transform)
{
	rp3d::Vector3 position(transform.getPosition().x, transform.getPosition().y - 2, transform.getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform reactTransform(position, orientation);

	playerCollision->setTransform(reactTransform);

	physicsWorld->update(timeStep);
}

void PhysicsManager::addCapsule(Transform transform)
{
	rp3d::Vector3 position(transform.getPosition().x, transform.getPosition().y - 2, transform.getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform reactTransform(position, orientation);
	playerCollision = physicsWorld->createCollisionBody(reactTransform);

	capsule = physicsCommon.createCapsuleShape(1.0, 2.0);
	//rp3d::Collider *collider;
	playerCollision->addCollider(capsule, rp3d::Transform::identity());

}


AABB* PhysicsManager::addAABB(Transform* transform, float width, float length, float height)
{
	++m_mapCount;
	m_colliders[m_mapCount] = AABB(transform, width, length, height);
	return &m_colliders[m_mapCount];
}

AABB PhysicsManager::getCollider(int colliderID)
{
	return m_colliders[colliderID];
}

// returns distance from collider to terrain
float PhysicsManager::checkTerrainCollision(AABB* collider)
{
	float colliderX = collider->getPosition().x;
	float colliderY = collider->getPosition().y;
	float colliderZ = collider->getPosition().z;

	return(colliderY - TerrainFactory::getInstance().heightAt(colliderX,colliderZ));
}

// returns distance from collider to terrain
float PhysicsManager::checkTerrainHeight(glm::vec3 position)
{
	return(TerrainFactory::getInstance().heightAt(position.x, position.z));
}

AABB* PhysicsManager::checkCollisions(AABB* collider)
{
	std::map<int, AABB>::iterator it;
	
	for(it = m_colliders.begin(); it != m_colliders.end(); ++it)
	{
		if(collider->checkCollision(it->second) && &it->second != collider)		//check it's colliding and that it's not colliding with itself
			return &it->second;
	}
	return nullptr;
}

void PhysicsManager::addTerrain()
{
	terrain.CreateTerrainShape(physicsCommon, physicsWorld);
}