//PhysicsManager.hpp - manages physics

#pragma once

#include <vector>
#include <map>
//PhysicsManager.hpp - manges physics

#include <glm/glm.hpp>
#include "Controller/Physics/AABB.hpp"

struct BoundingSphere
{
	glm::vec3 *m_position;
	double m_radius;

	BoundingSphere() {};
	BoundingSphere(glm::vec3 *position, double radius)
		: m_position(position), m_radius(radius) {}
};

class PhysicsManager
{
public:
	static PhysicsManager& getInstance();
	PhysicsManager(PhysicsManager const&) = delete;
	void operator=(PhysicsManager const&) = delete;

	void setTerrainCollider(std::vector<std::vector<float>> terrain);

	// returns difference of object height and terrain height
	float checkTerrainCollision(AABB* collider);
	AABB* checkCollisions(AABB* collider);

	// easy to implement if needed
	//int addBoundingSphere(glm::vec3 *position, double radius);
	AABB* addAABB(glm::vec3 *position, float width, float length, float height);

	AABB getCollider(int colliderID);

private:
	PhysicsManager();

	std::vector<std::vector<float>> m_terrain;

	int m_mapCount;
	std::map<int, AABB> m_colliders;	//TODO: make colliders so can add spheres
};