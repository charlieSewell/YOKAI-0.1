#include "GameAssetFactory.hpp"


 std::shared_ptr<GameObject> GameAssetFactory::Create(GameObjectType type, std::string modelName) 
 {
    if (type == GameObjectType::staticObject) 
    {
        return std::shared_ptr<GameObject>(new StaticObject(modelName));
    } 
    else if (type == GameObjectType::npc) 
    {
        return std::shared_ptr<GameObject>(new NPC(modelName));
    } 
    else if (type == GameObjectType::player) 
    {
        return std::shared_ptr<GameObject>(new Player);
    } 
 }
