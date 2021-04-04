//PhysicsManager.hpp - manages physics

#pragma once

#include <vector>
#include <map>

#include <glm/glm.hpp>

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
	double checkTerrainCollision(int colliderID);

	//will be map soon 
	int addBoundingSphere(glm::vec3 *position, double radius);


private:
	PhysicsManager();

	std::vector<std::vector<float>> m_terrain;

	int m_mapCount;
	std::map<int, BoundingSphere> m_boundingSpheres;
};