#pragma once

//#include <reactphysics3d/reactphysics3d.h>
#include <vector>
#include <map>
#include "Controller/Physics/AABB.hpp"
#include "Model/Components/Transform.hpp"
#include "YourEventListener.hpp"
#include "ReactTerrainShape.hpp"

//class ReactTerrainShape;

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

	void update(Transform transform);

    /**
     * @brief Checks terrain Collision
     * @param AABB* - collider
     * @return float
     */
	float checkTerrainCollision(AABB* collider); 	// returns difference of object height and terrain height

	/**
	 * @brief Checks terrain height at position
	 * @param glm::vec3 - position
	 * @return float
	 */
	float checkTerrainHeight(glm::vec3);

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
	AABB* addAABB(Transform *transform, float width, float length, float height);
    /**
     * @brief Returns a collider given an ID
     * @param int - colliderID
     * @return AABB
     */
	AABB getCollider(int colliderID);

	void addCapsule(Transform transform);

	void addTerrain();

	reactphysics3d::PhysicsCommon physicsCommon;
	reactphysics3d::PhysicsWorld* physicsWorld;

private:
    ///Privatised Constructor
	PhysicsManager();

	///Privatised destructor
	~PhysicsManager();

    ///count of map
	int m_mapCount;
    ///map of colliders
	std::map<int, AABB> m_colliders;	//TODO: make colliders so can add spheres

	reactphysics3d::decimal timeStep;

	reactphysics3d::CollisionBody* playerCollision;
	reactphysics3d::Collider* playerCollider;
	reactphysics3d::CapsuleShape* capsule;
	ReactTerrainShape terrain;
	reactphysics3d::Transform transform;
	YourEventListener listener;
};