#pragma once

#include <vector>
#include <map>
#include "Controller/Physics/RigidBody.hpp"
#include "Model/Components/Transform.hpp"
#include "CollisionEventHandler.hpp"
#include "Controller/Physics/ReactMath.hpp"
#include "Controller/Physics/ReactTerrainShape.hpp"
#include "Controller/Physics/ReactSphereShape.hpp"
#include "Controller/Physics/ReactBoxShape.hpp"
//class ReactTerrainShape;

/**
 * @class PhysicsSystem
 * @brief Singleton that Manages physics
 */
class PhysicsSystem
{
public:
    /**
     * @brief Returns this instance of Physics manager
     * @return PhysicsSystem&
     */
    static PhysicsSystem& getInstance();


    void Init();

    ///Deleted copy constructor
    PhysicsSystem(PhysicsSystem const&) = delete;

    ///Deleted = operator
    void operator=(PhysicsSystem const&) = delete;

    void update(float dt);


    // easy to implement if needed
    //int addBoundingSphere(glm::vec3 *position, double radius);
    /**
     * @brief Adds a bounding box
     * @param vec3* - position
     * @param float - width
     * @param float - length
     * @param float - height
     * @return ReactBoxShape*
     */
    int addAABB(Transform* transform, float width, float length, float height);
    /**
     * @brief Returns a collider given an ID
     * @param int - colliderID
     * @return ReactBoxShape
     */
    rp3d::RigidBody * getCollider(int colliderID);

    int addSphere(Transform* transform,float radius);

    void addTerrain();

    reactphysics3d::PhysicsCommon physicsCommon;
    reactphysics3d::PhysicsWorld* physicsWorld;
private:
    ///Privatised Constructor
    PhysicsSystem() = default;

    ///Privatised destructor
    ~PhysicsSystem();

    ///count of map
    int m_mapCount;
    ///map of colliders
    std::map<int, RigidBody> m_colliders;	//TODO: make colliders so can add spheres

    reactphysics3d::decimal timeStep;

    CollisionEventHandler listener;


};