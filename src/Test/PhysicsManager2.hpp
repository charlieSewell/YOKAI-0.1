#pragma once

#include <reactphysics3d/reactphysics3d.h>
#include "Model/Player.hpp"		// player will not be here - just for testing
#include "Controller/Factory/TerrainFactory.hpp"
#include "YourEventListener.hpp"
class PhysicsManager2
{
  public:
    PhysicsManager2();
    ~PhysicsManager2();

    void update(std::shared_ptr<GameObject> player);

	//these wont be here
	void test(std::shared_ptr<GameObject> player);
	void addPlayer(std::shared_ptr<GameObject> player);
	void addTerrain();

  private:
    reactphysics3d::PhysicsCommon physicsCommon;
    reactphysics3d::PhysicsWorld *physicsWorld;
    reactphysics3d::decimal timeStep;

    reactphysics3d::CollisionBody *playerCollision;
    reactphysics3d::CollisionBody *terrainCollision;
    reactphysics3d::Collider *terrainCollider;
    reactphysics3d::Collider *playerCollider;
    reactphysics3d::Collider* colider;
    rp3d::CapsuleShape *capsule;
    reactphysics3d::Transform transform;
    reactphysics3d::HeightFieldShape *heightField;

	float *heightFieldArray;
    YourEventListener listener;
	//std::vector<float> heightFieldArray;
};
