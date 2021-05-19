//ReactBoxShape.cpp - Axis Aligned Bounding Box

#include "Controller/Physics/ReactBoxShape.hpp"
void ReactBoxShape::CreateBoxShape(glm::vec3 bounds, reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld)
{
    rp3d::Vector3 position(objTransform.getPosition().x,objTransform.getPosition().y,objTransform.getPosition().z);
    rp3d::Quaternion orientation = rp3d::Quaternion::identity();
    reactphysics3d::Transform transform = reactphysics3d::Transform(position, orientation);
    body = physicsWorld->createCollisionBody(transform);
    shapeID = body->getEntity().id;
    reactphysics3d::Vector3 extent(bounds.x,bounds.y,bounds.z);
    shape = physicsCommon.createBoxShape(extent);
    body->addCollider(boxCollider, rp3d::Transform::identity());
}
void ReactBoxShape::DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon){
    physicsCommon.destroyBoxShape(static_cast<rp3d::BoxShape>(shape));
}