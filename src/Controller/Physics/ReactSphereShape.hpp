//
// Created by charl on 19/05/2021.
//
#pragma once

#include "Controller/Physics/ReactShape.hpp"

class ReactSphereShape : public ReactShape{
public:
    ReactSphereShape() =default;
    ~ReactSphereShape() = default;
    void CreateSphereShape(float radius, reactphysics3d::PhysicsCommon &physicsCommon);
    void DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon) override;
private:
};
