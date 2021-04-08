#pragma once

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "Controller/Physics/AABB.hpp"

/**
 * @struct BoundingSphere
 * @brief Stores Data related to bounding sphere
 */
struct BoundingSphere
{
    ///position of bounding sphere
	glm::vec3 *m_position;
    ///radius of bounding sphere
	double m_radius;
    ///default constructor for bounding sphere
	BoundingSphere() {};
    /**
     * @brief Construtor for BoundingSphere
     * @param vec3 - position
     * @param double - radius
     */
	BoundingSphere(glm::vec3 *position, double radius)
		: m_position(position), m_radius(radius) {}
};
/**
 * @class PhysicsManager
 * @brief Singleton that Manages physics
 */
class PhysicsManager
{
public:
    /**
     * @brief Returns this instance of Physics manager
     * @return PhysicsManager&
     */
	static PhysicsManager& getInstance();
    ///Deleted copy constructor
	PhysicsManager(PhysicsManager const&) = delete;
    ///Deleted = operator
	void operator=(PhysicsManager const&) = delete;
    /**
     * @brief Sets the Terrain Collider
     * @param vector<float> - terrain
     */
	void setTerrainCollider(std::vector<std::vector<float>> terrain);


    /**
     * @brief Checks terrain Collision
     * @param AABB* - collider
     * @return float
     */
	float checkTerrainCollision(AABB* collider); 	// returns difference of object height and terrain height
	/**
	 * @brief Checks AABB Collisions
	 * @param AABB* collider
	 * @return AABB*
	 */
    AABB* checkCollisions(AABB* collider);

	// easy to implement if needed
	//int addBoundingSphere(glm::vec3 *position, double radius);
    /**
     * @brief Adds a bounding box
     * @param vec3* - position
     * @param float - width
     * @param float - length
     * @param float - height
     * @return AABB*
     */
	AABB* addAABB(glm::vec3 *position, float width, float length, float height);
    /**
     * @brief Returns a collider given an ID
     * @param int - colliderID
     * @return AABB
     */
	AABB getCollider(int colliderID);

private:
    ///Privatised Constructor
	PhysicsManager();
    ///Terrain Vertices
	std::vector<std::vector<float>> m_terrain;
    ///count of map
	int m_mapCount;
    ///map of colliders
	std::map<int, AABB> m_colliders;	//TODO: make colliders so can add spheres
};