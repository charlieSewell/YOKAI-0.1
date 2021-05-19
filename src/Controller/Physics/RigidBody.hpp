//
// Created by charl on 19/05/2021.
//
#include <iostream>
#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>
#include "Controller/Physics/ReactTerrainShape.hpp"

class RigidBody {

public:
    void SetPosition(glm::vec3 position);
    void SetOrientation(glm::quat orientation);
    void CreateBody(rp3d::PhysicsWorld* physicsWorld,glm::vec3 position,glm::quat orientation);
    void SetPositionAndOrientation(glm::vec3 position, glm::quat orientation);
    glm::vec3 GetPosition();
    glm::quat GetOrientation();
    void ApplyForceToCentre(glm::vec3 force);
    reactphysics3d::RigidBody* getRigidBody(){return body;}
    void AddCollisionShape(ReactTerrainShape& shape);
    void SetBodyType(rp3d::BodyType type);
    void SetFrictionCoefficient(float friction);
    void SetRollingResistance(float resistance);
    void SetMass(float mass);
    unsigned int getColliderID(){return body->getEntity().id;}
private:
    reactphysics3d::RigidBody* body;
    unsigned int colliderID = -1;
};
