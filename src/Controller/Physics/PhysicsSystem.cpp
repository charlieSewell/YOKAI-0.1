//PhysicsSystem.cpp - manages physics

#include "PhysicsSystem.hpp"
#include "Controller/GameObjectManager.hpp"

void PhysicsSystem::Init()
{
    // Create the world settings
    reactphysics3d::PhysicsWorld::WorldSettings settings;
    settings.defaultVelocitySolverNbIterations = 20;
    settings.isSleepingEnabled = false;
    settings.gravity = reactphysics3d::Vector3(0, -9.81, 0);

    physicsWorld = physicsCommon.createPhysicsWorld(settings);
    physicsWorld->setEventListener(&listener);
    timeStep = 1.0f / 30.0f;
}
PhysicsSystem::~PhysicsSystem()
{
    std::cout << "GoodBye";
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

    sphere.CreateSphereShape(3,physicsCommon);
    object.AddCollisionShape(sphere);
    m_colliders.emplace(object.getColliderID(),object);
    return object.getColliderID();
}


int PhysicsSystem::addAABB(Transform* transform, float width, float length, float height)
{
    RigidBody object;
    ReactBoxShape box;
    object.CreateBody(physicsWorld,transform->getPosition(),transform->getRotation());

    box.CreateBoxShape(glm::vec3(width,height,length),physicsCommon);
    object.AddCollisionShape(box);
    object.SetBodyType(rp3d::BodyType::STATIC);
    m_colliders.emplace(object.getColliderID(),object);

    return object.getColliderID();
}

rp3d::RigidBody * PhysicsSystem::getCollider(int colliderID)
{
    return m_colliders.at(colliderID).getRigidBody();
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
    terrain.SetBodyType(rp3d::BodyType::STATIC);
    m_colliders.emplace(terrain.getColliderID(),terrain);
}


