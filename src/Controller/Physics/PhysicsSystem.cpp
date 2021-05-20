//PhysicsSystem.cpp - manages physics

#include "PhysicsSystem.hpp"
#include "Controller/GameObjectManager.hpp"
#include <glm/gtx/string_cast.hpp>
void PhysicsSystem::Init()
{
    // Create the world settings
    reactphysics3d::PhysicsWorld::WorldSettings settings;
    //settings.defaultVelocitySolverNbIterations = 20;
    //settings.isSleepingEnabled = false;
    settings.gravity = reactphysics3d::Vector3(0, -9.81, 0);

    physicsWorld = physicsCommon.createPhysicsWorld(settings);
    physicsWorld->setEventListener(&listener);
    timeStep = 1.0f / 30.0f;
}
PhysicsSystem::~PhysicsSystem()
{
    for(auto& collider : m_colliders)
    {
        collider.second.DeleteBody(physicsWorld,physicsCommon);
    }
    physicsCommon.destroyPhysicsWorld(physicsWorld);
}


PhysicsSystem& PhysicsSystem::getInstance()
{
    static PhysicsSystem instance;
    return instance;
}

void PhysicsSystem::update(float dt)
{
    physicsWorld->update(timeStep);

}

int PhysicsSystem::addSphere(Transform *transform, float radius)
{
    RigidBody object;
    ReactSphereShape sphere;
    object.CreateBody(physicsWorld,transform->getPosition(),transform->getRotation());
    sphere.CreateSphereShape(radius,physicsCommon);
    object.AddCollisionShape(sphere);
    m_colliders.emplace(object.getColliderID(),object);
    return object.getColliderID();
}


int PhysicsSystem::addAABB(Transform* transform, float width, float height, float length)
{
    RigidBody object;
    ReactBoxShape box;
    glm::vec3 newPos = glm::vec3(transform->getPosition().x,transform->getPosition().y,transform->getPosition().z);
    object.CreateBody(physicsWorld,newPos,transform->getRotation());
    box.CreateBoxShape(glm::vec3(width,height,length),physicsCommon);
    object.AddCollisionShape(box);
    m_colliders.emplace(object.getColliderID(),object);

    return object.getColliderID();
}

RigidBody * PhysicsSystem::getRigidBody(int colliderID)
{
    return &m_colliders.at(colliderID);
}




void PhysicsSystem::addTerrain()
{
    RigidBody terrain;
    ReactTerrainShape terrShape;
    glm::vec3 position(TerrainFactory::getInstance().getTerrainSize()/2, 128, TerrainFactory::getInstance().getTerrainSize()/2);
    glm::quat orientation = glm::identity<glm::quat>();
    terrain.CreateBody(physicsWorld,position,orientation);
    terrShape.CreateTerrainShape(physicsCommon);
    terrain.AddCollisionShape(terrShape);
    terrain.SetBounciness(0.0);
    terrain.SetRollingResistance(1.0);
    terrain.SetBodyType(rp3d::BodyType::STATIC);
    m_colliders.emplace(terrain.getColliderID(),terrain);
}


