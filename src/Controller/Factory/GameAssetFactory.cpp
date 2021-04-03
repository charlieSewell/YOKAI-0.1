#include "GameAssetFactory.hpp"

 std::shared_ptr<GameObject> GameAssetFactory::Create(GameObjectType type) {
    if (type == GameObjectType::staticObject) 
    {
        return std::shared_ptr<GameObject>(new StaticObject("content/Models/pine.fbx"));
    } 
}
