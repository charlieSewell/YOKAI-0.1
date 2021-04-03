#include <iostream>
#include "Model/Player.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
#include "Controller/ModelManager.hpp"
#include "Asset.h"

class GameAssetFactory 
{
  public:
    Asset *Create(std::string type);
};