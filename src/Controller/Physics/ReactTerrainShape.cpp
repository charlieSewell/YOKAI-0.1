//
// Created by Charlie Sewell on 13/05/2021.
//

#include <Model/Components/Transform.hpp>
#include "ReactTerrainShape.hpp"

ReactTerrainShape::ReactTerrainShape()
{
    heightFieldArray = new float[TerrainFactory::getInstance().getTerrainSize()*TerrainFactory::getInstance().getTerrainSize()];
}
ReactTerrainShape::~ReactTerrainShape()
{
    std::cout << "Hi" <<std::endl;
    //delete[] heightFieldArray;
}
void ReactTerrainShape::CreateTerrainShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld)
{
    int terrainSize = TerrainFactory::getInstance().getTerrainSize();
    for(int x=0; x<terrainSize; ++x)
    {
        for(int z=0; z<terrainSize; ++z)
        {
            heightFieldArray[x * terrainSize + z] = TerrainFactory::getInstance().heightAt(static_cast<float>(z),static_cast<float>(x));
        }
    }
    terrainCollider = physicsCommon.createHeightFieldShape(terrainSize, terrainSize, 0, 255, heightFieldArray, rp3d::HeightFieldShape::HeightDataType::HEIGHT_FLOAT_TYPE);

}
void ReactTerrainShape::DeleteShape(reactphysics3d::PhysicsCommon &physicsCommon,reactphysics3d::PhysicsWorld *physicsWorld){
    physicsCommon.destroyHeightFieldShape(terrainCollider);
    delete[] heightFieldArray;
}