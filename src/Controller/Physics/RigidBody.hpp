//
// Created by charl on 19/05/2021.
//
#include <iostream>
#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>
#include "Controller/Physics/Shapes/ReactTerrainShape.hpp"

class RigidBody {

public:
    void SetPosition(glm::vec3 position);
    void SetOrientation(glm::quat orientation);
    void CreateBody(unsigned int gameObjID,rp3d::PhysicsWorld* physicsWorld,glm::vec3 position,glm::quat orientation);
    void DeleteBody(rp3d::PhysicsWorld* physicsWorld,rp3d::PhysicsCommon &physicsCommon);
    void SetPositionAndOrientation(glm::vec3 position, glm::quat orientation);
    glm::vec3 GetPosition();
    glm::quat GetOrientation();
    void ApplyForceToCentre(glm::vec3 force);
    reactphysics3d::RigidBody* getRigidBody(){return body;}
    void AddCollisionShape(ReactShape shape);
    void SetBodyType(rp3d::BodyType type);
    void SetFrictionCoefficient(float friction);
    void SetRollingResistance(float resistance);
    void SetLinearVelocity(glm::vec3 velocity);
    void SetAngularVelocity(glm::vec3 velocity);
    void SetAngularDamping(double damping);
    void SetLinearDamping(double damping);
    glm::vec3 GetLinearVelocity();
    glm::vec3 GetAngularVelocity();
    void SetBounciness(float bounciness);
    void SetMass(float mass);
    void SetIsAllowedToSleep(bool sleepState);
    unsigned int getColliderID(){return collider->getEntity().id;}
    unsigned int getGameObjectID(){return gameObjectID;}
private:
    ReactShape shape;
    unsigned int gameObjectID = -1;
    reactphysics3d::RigidBody* body;
    reactphysics3d::Collider* collider;
};
