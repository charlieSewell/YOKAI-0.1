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

int PhysicsManager::addBoundingSphere(glm::vec3 *position, double radius)
{
	++m_mapCount;
	m_boundingSpheres[m_mapCount] = BoundingSphere(position, radius);
	return m_mapCount;
}

double PhysicsManager::checkTerrainCollision(int colliderID)
{
	int colliderX = (int)m_boundingSpheres[colliderID].m_position->x;
	double colliderY = m_boundingSpheres[colliderID].m_position->y;
	int colliderZ = (int)m_boundingSpheres[colliderID].m_position->z;

	//stop the vecotr from going out of index
	if(colliderX < 0 || colliderX > m_terrain.size()-1)
		colliderX = 0;
	if(colliderZ < 0 || colliderZ > m_terrain[colliderX].size()-1)
		colliderZ = 0;


	return(colliderY - m_terrain[colliderX][colliderZ]);
}