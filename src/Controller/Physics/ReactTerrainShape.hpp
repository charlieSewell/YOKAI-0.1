//
// Created by Charlie Sewell on 13/05/2021.
//
#pragma once
#include "Controller/Factory/TerrainFactory.hpp"
#include "Controller/Physics/ReactShape.hpp"

class ReactTerrainShape : public ReactShape{
  public:
    ReactTerrainShape();
    ~ReactTerrainShape();
    void CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon, reactphysics3d::PhysicsWorld *physicsWorld);
    rp3d::HeightFieldShape * getShape(){return terrainCollider;}
    void DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld);
  private:
    reactphysics3d::HeightFieldShape* terrainCollider;
    float *heightFieldArray;
};
