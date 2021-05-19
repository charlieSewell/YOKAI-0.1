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
    //std::cout << glm::to_string(playerTrans) << std::endl;
    //rp3d::Vector3 temp = playerCollider->getTransform().getPosition();
    //GameObjectManager::getInstance().getPlayer()->m_transform.setPosition(ReactMath::r3pdVecToGlm(temp));

}

void PhysicsSystem::addPlayer(Transform transform)
{
    RigidBody player;
    player.CreateBody(physicsWorld,transform.getPosition(),transform.getRotation());

    //capsule = physicsCommon.createSphereShape(3.0);
    //playerCollider->addCollider(capsule, rp3d::Transform::identity());
}


int PhysicsSystem::addAABB(Transform* transform, float width, float length, float height)
{
    //ReactBoxShape shape;
   // shape.CreateBoxShape(*transform,glm::vec3(width,height,length),physicsCommon,physicsWorld);
    //m_colliders.emplace(shape.getShapeID(),shape);
    return 0;
}

rp3d::RigidBody * PhysicsSystem::getCollider(int colliderID)
{
    return m_colliders.at(colliderID).getRigidBody();
}




void PhysicsSystem::addTerrain()
{
    RigidBody terrain;
    glm::vec3 position(TerrainFactory::getInstance().getTerrainSize()/2, 128, TerrainFactory::getInstance().getTerrainSize()/2);
    glm::quat orientation = glm::identity<glm::quat>();
    terrain.CreateBody(physicsWorld,position,orientation);
    terrShape.CreateTerrainShape(physicsCommon,physicsWorld);
    terrain.AddCollisionShape(terrShape);
    terrain.SetBodyType(rp3d::BodyType::STATIC);
    m_colliders.emplace(terrain.getColliderID(),terrain);
}