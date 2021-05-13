
#include "PhysicsManager2.hpp"
PhysicsManager2::PhysicsManager2()
{
    heightFieldArray = new float[512*512];
    physicsWorld = physicsCommon.createPhysicsWorld();
    physicsWorld->setEventListener(&listener);
	timeStep = 1.0f / 120.0f;
}

PhysicsManager2::~PhysicsManager2()
{
    std::cout <<"GoodBye";
	physicsWorld->destroyCollisionBody(playerCollision);
	physicsWorld->destroyCollisionBody(terrainCollision);
    physicsCommon.destroyPhysicsWorld(physicsWorld);
	delete[] heightFieldArray;
}

void PhysicsManager2::update(std::shared_ptr<GameObject> player)
{
	rp3d::Vector3 position(player->getPosition().x, player->getPosition().y, player->getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(position, orientation);
	playerCollision->setTransform(transform);

    physicsWorld->update(timeStep);
	//display the position of the body

	//if(physicsWorld->testOverlap(terrainCollision, playerCollision))
		//std::cout << "Hell yeah\n";
	//else
		//std::cout << "No collide motherfucker\n";

	//std::cout << "Body position: = " << terrainCollision->
	//std::cout << "Body position: = " << playerCollision->getTransform().getPosition().x << ", " << playerCollision->getTransform().getPosition().y << ", " << playerCollision->getTransform().getPosition().z << "\n";
	//std::cout << "Body position: = " << terrainCollision->getTransform().getPosition().x << ", " << terrainCollision->getTransform().getPosition().y << ", " << terrainCollision->getTransform().getPosition().z << "\n";
}

void PhysicsManager2::test(std::shared_ptr<GameObject> player)
{
    addTerrain();
	addPlayer(player);

}

void PhysicsManager2::addPlayer(std::shared_ptr<GameObject> player)
{
	rp3d::Vector3 position(player->getPosition().x, player->getPosition().y, player->getPosition().z);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(position, orientation);
	playerCollision = physicsWorld->createCollisionBody(transform);

    capsule = physicsCommon.createCapsuleShape(1.0, 2.0);
	//rp3d::Collider *collider;
	playerCollision->addCollider(capsule, rp3d::Transform::identity());

}


void PhysicsManager2::addTerrain()
{
	rp3d::Vector3 position(256, 128, 256);
	//rp3d::Vector3 position(256, 10, 256);
	rp3d::Quaternion orientation = rp3d::Quaternion::identity();
	this->transform = reactphysics3d::Transform(position, orientation);
	terrainCollision = physicsWorld->createCollisionBody(transform);

	/*
	rp3d::BoxShape *box = physicsCommon.createBoxShape(rp3d::Vector3(250.0, 1.0, 250.0));
	transform = rp3d::Transform::identity();
	rp3d::Collider* collider;
	collider = terrainCollision->addCollider(box, transform);
	*/
    float mMaxHeight = 256;
    float mMinHeight = 0;

	for(int x=0; x<512; ++x)
	{
		for(int z=0; z<512; ++z)
		{

			//heightFieldArray.push_back(TerrainFactory::getInstance().heightVals[z][x]);
			heightFieldArray[x * 512 + z] = TerrainFactory::getInstance().heightAt(x,z);
            if (heightFieldArray[x * 512 + z] > mMaxHeight) mMaxHeight =    heightFieldArray[x * 512 + z] ;
            if (heightFieldArray[x * 512 + z] < mMinHeight) mMinHeight = heightFieldArray[x * 512 + z] ;
			//heightFieldArray[i] = TerrainFactory::getInstance().heightVals.data()[z].data()[x];
		}
	}
    std::cout << "Gaming";

	heightField = physicsCommon.createHeightFieldShape(512, 512, mMinHeight, mMaxHeight, heightFieldArray, rp3d::HeightFieldShape::HeightDataType::HEIGHT_FLOAT_TYPE);
	colider = terrainCollision->addCollider(heightField, rp3d::Transform::identity());
	
	std::cout << heightFieldArray[511*512+511] << ", " << /*TerrainFactory::getInstance().heightVals.data()->data()[513] <<*/ ", " << TerrainFactory::getInstance().heightAt(511,511) << "\n";

}




// Register your event listener class
