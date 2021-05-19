//
// Created by charl on 19/05/2021.
//

#include "RigidBody.hpp"
#include "Controller/Physics/ReactMath.hpp"
void RigidBody::CreateBody(rp3d::PhysicsWorld* physicsWorld,glm::vec3 position,glm::quat orientation)
{
    rp3d::Transform temp(ReactMath::glmVecToR3pd(position),ReactMath::glmQuatToR3pd(orientation));
    body = physicsWorld->createRigidBody(temp);
}
void RigidBody::SetPosition(glm::vec3 position){
    rp3d::Transform currTransform = body->getTransform();
    currTransform.setPosition(ReactMath::glmVecToR3pd(position));
    body->setTransform(currTransform);
}
void RigidBody::SetOrientation(glm::quat orientation)
{
    rp3d::Transform currTransform = body->getTransform();
    currTransform.setOrientation(ReactMath::glmQuatToR3pd(orientation));
    body->setTransform(currTransform);
}
glm::quat RigidBody::GetOrientation()
{
    rp3d::Quaternion temp = body->getTransform().getOrientation();
    return ReactMath::r3pdQuatToGlm(temp);
}
glm::vec3 RigidBody::GetPosition()
{
    rp3d::Vector3 temp = body->getTransform().getPosition();
    return ReactMath::r3pdVecToGlm(temp);
}

void RigidBody::ApplyForceToCentre(glm::vec3 force) {
    rp3d::Vector3 addedForce = ReactMath::glmVecToR3pd(force);
    body->applyForceToCenterOfMass(addedForce);
}
void RigidBody::AddCollisionShape(ReactTerrainShape& shape) {
    rp3d::Collider* temp = body->addCollider(shape.getShape(),rp3d::Transform::identity());
    colliderID = temp->getEntity().id;
}
void RigidBody::SetBodyType(rp3d::BodyType type) {
    switch (type) {
        case rp3d::BodyType::KINEMATIC: {
            body->setType(rp3d::BodyType::KINEMATIC);
        } break;
        case rp3d::BodyType::DYNAMIC: {
            body->setType(rp3d::BodyType::DYNAMIC);
        } break;
        case rp3d:: BodyType::STATIC: {
            body->setType(rp3d::BodyType::STATIC);
        } break;
    }
}
void RigidBody::SetFrictionCoefficient(float friction)
{
    body->getCollider(colliderID)->getMaterial().setFrictionCoefficient(friction);
}

void RigidBody::SetRollingResistance(float resistance)
{
    body->getCollider(colliderID)->getMaterial().setRollingResistance(resistance);
}
void RigidBody::SetMass(float mass)
{
    body->setMass(mass);
}
