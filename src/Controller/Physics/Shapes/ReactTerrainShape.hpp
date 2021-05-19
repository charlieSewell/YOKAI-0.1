//
// Created by Charlie Sewell on 13/05/2021.
//
#pragma once
#include "Controller/Factory/TerrainFactory.hpp"
#include "ReactShape.hpp"

class ReactTerrainShape : public ReactShape{
  public:
    ReactTerrainShape();
    ~ReactTerrainShape();
    void CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon);
    void DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon) override;
  private:
    float *heightFieldArray;
};
