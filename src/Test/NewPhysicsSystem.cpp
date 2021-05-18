
#include "NewPhysicsSystem.hpp"

NewPhysicsSystem::NewPhysicsSystem()
{
    physicsWorld = physicsCommon.createPhysicsWorld();
    physicsWorld->setEventListener(&listener);
	timeStep = 1.0f / 120.0f;
}

NewPhysicsSystem::~NewPhysicsSystem()
{
    std::cout <<"GoodBye";
	physicsWorld->destroyCollisionBody(playerCollision);
    physicsCommon.destroyPhysicsWorld(physicsWorld);
}

void NewPhysicsSystem::update(std::shared_ptr<GameObject> player)
{
	rp3d::Vector3 position(player->getTransform().getPosition().x, player->getTransform().getPosition().y - 2, player->getTransform().getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(position, orientation);


	playerCollision->setTransform(transform);

    physicsWorld->update(timeStep);

}

void NewPhysicsSystem::test(std::shared_ptr<GameObject> player)
{
    addPlayer(player);
    addTerrain();


}

void NewPhysicsSystem::addPlayer(std::shared_ptr<GameObject> player)
{
	rp3d::Vector3 position(player->getTransform().getPosition().x, player->getTransform().getPosition().y - 2, player->getTransform().getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(position, orientation);
	playerCollision = physicsWorld->createCollisionBody(transform);

    capsule = physicsCommon.createCapsuleShape(1.0, 2.0);
	//rp3d::Collider *collider;
	playerCollision->addCollider(capsule, rp3d::Transform::identity());

}


void NewPhysicsSystem::addTerrain()
{
    terrain.CreateTerrainShape(physicsCommon,physicsWorld);
}




// Register your event listener class
