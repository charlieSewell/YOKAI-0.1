#pragma once

#include <reactphysics3d/reactphysics3d.h>
#include "Model/Player.hpp"		// player will not be here - just for testing
#include "Controller/Factory/TerrainFactory.hpp"

class PhysicsManager
{
  public:
    PhysicsManager();
    ~PhysicsManager();

    void update(Player player);

	//these wont be here
	void test(Player player);
	void addPlayer(Player player);
	void addTerrain();

  private:
    rp3d::PhysicsCommon physicsCommon;
    rp3d::PhysicsWorld *physicsWorld;
	rp3d::decimal timeStep;

	rp3d::CollisionBody *playerCollision;
	rp3d::CollisionBody *terrainCollision;
	//float* heightFieldArray = new float[512*512];
	std::vector<float> heightFieldArray;
};
