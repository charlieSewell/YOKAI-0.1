//
// Created by charl on 19/05/2021.
//
#pragma once
#include <iostream>
#include <reactphysics3d/reactphysics3d.h>
#include "Model/Components/Transform.hpp"
class ReactShape {
    public:
    ReactShape() = default;
    virtual reactphysics3d::CollisionShape* getCollisionShape(){return shape;}
    virtual void DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon);
    unsigned int getShapeID() const{return shapeID;}

    reactphysics3d::CollisionShape *getShape();

protected:
    reactphysics3d::CollisionShape* shape;
    unsigned int shapeID;
};
