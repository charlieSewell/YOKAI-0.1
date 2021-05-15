//
// Created by Charlie Sewell on 13/05/2021.
//

#include "ReactTerrainShape.hpp"
ReactTerrainShape::ReactTerrainShape()
{
    heightFieldArray = new float[TerrainFactory::getInstance().getTerrainSize()*TerrainFactory::getInstance().getTerrainSize()];
}
ReactTerrainShape::~ReactTerrainShape()
{
    delete[] heightFieldArray;
}
void ReactTerrainShape::CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld)
{
    int terrainSize = TerrainFactory::getInstance().getTerrainSize();
    //TODO: TERRAIN Y HARDCODED AND NEEDS TO CHANGE
    rp3d::Vector3 position(terrainSize/2, 117, terrainSize/2);
    rp3d::Quaternion orientation = rp3d::Quaternion::identity();
    reactphysics3d::Transform transform = reactphysics3d::Transform(position, orientation);
    body = physicsWorld->createCollisionBody(transform);
    shapeID = body->getEntity().id;
    std::cout <<shapeID <<std::endl;
    float mMaxHeight = -300;
    float mMinHeight = 1000;



    for(int x=0; x<terrainSize; ++x)
    {
        for(int z=0; z<terrainSize; ++z)
        {
            heightFieldArray[x * terrainSize + z] = TerrainFactory::getInstance().heightAt(static_cast<float>(z),static_cast<float>(x));
            if (heightFieldArray[x * terrainSize + z] > mMaxHeight) mMaxHeight =    heightFieldArray[x * terrainSize + z] ;
            if (heightFieldArray[x * terrainSize + z] < mMinHeight) mMinHeight = heightFieldArray[x * terrainSize + z] ;
        }
    }
    terrainCollider = physicsCommon.createHeightFieldShape(terrainSize, terrainSize, mMinHeight, mMaxHeight, heightFieldArray, rp3d::HeightFieldShape::HeightDataType::HEIGHT_FLOAT_TYPE);
    body->addCollider(terrainCollider, rp3d::Transform::identity());
}
void ReactTerrainShape::DeleteTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld){
    physicsWorld->destroyCollisionBody(body);
    physicsCommon.destroyHeightFieldShape(terrainCollider);
    delete[] heightFieldArray;
}