//
// Created by charl on 19/05/2021.
//

#include "ReactSphereShape.hpp"
void ReactSphereShape::CreateSphereShape(float radius, reactphysics3d::PhysicsCommon &physicsCommon,
                                         reactphysics3d::PhysicsWorld *physicsWorld) {

}
void ReactSphereShape::DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon) {
    physicsCommon.destroySphereShape(static_cast<rp3d::SphereShape*>(shape));
}