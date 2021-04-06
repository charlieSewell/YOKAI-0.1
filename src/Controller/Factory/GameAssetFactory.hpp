#include <iostream>

#include "Controller/ModelManager.hpp"
#include "Model/GameObjects/GameObject.hpp"
#include "Model/GameObjects/NPC.hpp"
#include "Model/GameObjects/StaticObject.hpp"
#include "Model/Player.hpp"

class GameAssetFactory
{
  public:
    static std::shared_ptr<GameObject> Create(GameObjectType type, std::string modelName);
	static std::shared_ptr<GameObject> Create(GameObjectType type);
	//std::shared_ptr<GameObject> GameAssetFactory::Create(GameObjectType type, std::string modelName, glm::vec3 position);
};
