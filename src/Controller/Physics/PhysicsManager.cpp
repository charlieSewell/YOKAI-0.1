//PhysicsManager.cpp - manages physics

#include "PhysicsManager.hpp"

PhysicsManager::PhysicsManager()
	: m_mapCount(0) {}


PhysicsManager& PhysicsManager::getInstance()
{
	static PhysicsManager instance;
	return instance;
}

void PhysicsManager::setTerrainCollider(std::vector<std::vector<float>> terrain)
{
	m_terrain = terrain;
}

/*int PhysicsManager::addBoundingSphere(glm::vec3 *position, double radius)
{
	++m_mapCount;
	m_colliders[m_mapCount] = BoundingSphere(position, radius);
	return m_mapCount;
}*/

int PhysicsManager::addAABB(glm::vec3* position, float width, float length, float height)
{
	++m_mapCount;
	m_colliders[m_mapCount] = AABB(position, width, length, height);
	return m_mapCount;
}

AABB PhysicsManager::getCollider(int colliderID)
{
	return m_colliders[colliderID];
}

// returns distance from collider to terrain
float PhysicsManager::checkTerrainCollision(int colliderID)
{
	int colliderX = (int)m_colliders[colliderID].getPosition()->x;
	float colliderY = m_colliders[colliderID].getPosition()->y;
	int colliderZ = (int)m_colliders[colliderID].getPosition()->z;

	//stop the vecotr from going out of index
	if(colliderX < 0 || colliderX > m_terrain.size()-1)
		colliderX = 0;
	if(colliderZ < 0 || colliderZ > m_terrain[colliderX].size()-1)
		colliderZ = 0;


	return(colliderY - m_terrain[colliderX][colliderZ]);
}

bool PhysicsManager::checkCollisions(int colliderID)
{
	std::map<int, AABB>::iterator it;
	
	for(it = m_colliders.begin(); it != m_colliders.end(); ++it)
	{
		if(it->first != colliderID)
		{
			if(m_colliders[colliderID].checkCollision(it->second))
				return true;
		}
	}
	return false;
}