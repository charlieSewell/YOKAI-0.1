#pragma once

#include <reactphysics3d/reactphysics3d.h>

#include "Model/GameObjects/Player.hpp" // player will not be here - just for testing
#include "YourEventListener.hpp"
#include "ReactTerrainShape.hpp"

class NewPhysicsSystem
{
  public:
    NewPhysicsSystem();
    ~NewPhysicsSystem();

    void update(std::shared_ptr<GameObject> player);
	//these wont be here
	void test(std::shared_ptr<GameObject> player);
	void addPlayer(std::shared_ptr<GameObject> player);
	void addTerrain();
    reactphysics3d::PhysicsCommon physicsCommon;
    reactphysics3d::PhysicsWorld *physicsWorld;
  private:

    reactphysics3d::decimal timeStep;

    reactphysics3d::CollisionBody *playerCollision;
    reactphysics3d::Collider *playerCollider;
    rp3d::CapsuleShape *capsule;
    ReactTerrainShape terrain;
    reactphysics3d::Transform transform;
    YourEventListener listener;

};
