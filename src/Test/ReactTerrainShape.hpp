//
// Created by Charlie Sewell on 13/05/2021.
//
#pragma once
#include "Controller/Factory/TerrainFactory.hpp"
#include <reactphysics3d/reactphysics3d.h>
class NewPhysicsSystem;
class ReactTerrainShape {
  public:
    ReactTerrainShape();
    ~ReactTerrainShape();
    void CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld);
    reactphysics3d::CollisionBody* getCollisionBody(){return body;}
  private:
    reactphysics3d::CollisionBody* body;
    reactphysics3d::HeightFieldShape* terrainCollider;
    float *heightFieldArray;
};
