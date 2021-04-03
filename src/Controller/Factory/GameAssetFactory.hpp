#include <iostream>
#include "Model/Player.hpp"
#include "Model/GameObject.hpp"
#include "Model/StaticObject.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
#include "Controller/ModelManager.hpp"

class GameAssetFactory 
{
  public:
    GameObject Create(GameObjectType type);
};