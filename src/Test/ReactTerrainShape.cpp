//
// Created by Charlie Sewell on 13/05/2021.
//

#include "ReactTerrainShape.hpp"
ReactTerrainShape::ReactTerrainShape()
{
    heightFieldArray = new float[512*512];
}
ReactTerrainShape::~ReactTerrainShape()
{
    delete[] heightFieldArray;
}
void ReactTerrainShape::CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld)
{
    rp3d::Vector3 position(256, 128, 256);
    rp3d::Quaternion orientation = rp3d::Quaternion::identity();
    reactphysics3d::Transform transform = reactphysics3d::Transform(position, orientation);
    body = physicsWorld->createCollisionBody(transform);
    shapeID = body->getEntity().id;
    std::cout <<shapeID <<std::endl;
    float mMaxHeight = 0;
    float mMinHeight = 512;

    for(int x=0; x<512; ++x)
    {
        for(int z=0; z<512; ++z)
        {
            heightFieldArray[x * 512 + z] = TerrainFactory::getInstance().heightAt(static_cast<float>(z),static_cast<float>(x));
            if (heightFieldArray[x * 512 + z] > mMaxHeight) mMaxHeight =    heightFieldArray[x * 512 + z] ;
            if (heightFieldArray[x * 512 + z] < mMinHeight) mMinHeight = heightFieldArray[x * 512 + z] ;
        }
    }
    terrainCollider = physicsCommon.createHeightFieldShape(512, 512, mMinHeight, mMaxHeight, heightFieldArray, rp3d::HeightFieldShape::HeightDataType::HEIGHT_FLOAT_TYPE);
    body->addCollider(terrainCollider, rp3d::Transform::identity());
}
void ReactTerrainShape::DeleteTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld){
    physicsWorld->destroyCollisionBody(body);
    physicsCommon.destroyHeightFieldShape(terrainCollider);
    delete[] heightFieldArray;
}