#include <iostream>
#include "Model/Player.hpp"
#include "Model/GameObject.hpp"
#include "Model/StaticObject.hpp"
#include "Model/NPC.hpp"
#include "Controller/ModelManager.hpp"

class GameAssetFactory 
{
  public:
   static std::shared_ptr<GameObject> Create(GameObjectType type, std::string modelName);
};