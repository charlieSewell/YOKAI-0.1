#include "GameAssetFactory.hpp"

GameObject GameAssetFactory::Create(GameObjectType type) 
{
    if (type == GameObjectType::staticObject) 
    {
        return StaticObject("content/Models/pine.fbx");
    } 
}
