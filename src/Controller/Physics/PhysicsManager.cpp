//PhysicsManager.cpp - manages physics

#include "PhysicsManager.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
PhysicsManager::PhysicsManager()
	: m_mapCount(0) {}


PhysicsManager& PhysicsManager::getInstance()
{
    static PhysicsManager instance;
    return instance;
}

/*int PhysicsManager::addBoundingSphere(glm::vec3 *position, double radius)
{
	++m_mapCount;
	m_colliders[m_mapCount] = BoundingSphere(position, radius);
	return m_mapCount;
}*/

AABB* PhysicsManager::addAABB(glm::vec3* position, float width, float length, float height)
{
	++m_mapCount;
	m_colliders[m_mapCount] = AABB(position, width, length, height);
	return &m_colliders[m_mapCount];
}

AABB PhysicsManager::getCollider(int colliderID)
{
	return m_colliders[colliderID];
}

// returns distance from collider to terrain
float PhysicsManager::checkTerrainCollision(AABB* collider)
{
	float colliderX = collider->getPosition()->x;
	float colliderY = collider->getPosition()->y;
	float colliderZ = collider->getPosition()->z;

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