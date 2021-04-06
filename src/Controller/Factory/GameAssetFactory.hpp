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
	static std::shared_ptr<GameObject> Create(GameObjectType type);
	//std::shared_ptr<GameObject> GameAssetFactory::Create(GameObjectType type, std::string modelName, glm::vec3 position);
};
