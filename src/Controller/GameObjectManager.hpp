#include <iostream>
#include <map>
#include "Model/GameObject.hpp"
#include "Controller/Factory/GameAssetFactory.hpp"
#include "Controller/LuaManager.hpp"
#include "Controller/LuaTypes.hpp"
class GameObjectManager 
{
  public:
    static GameObjectManager &getInstance();
    static void init();
    static int CreateObject(GameObjectType type);
    static int add(std::shared_ptr<GameObject> &gameObject);
    static std::shared_ptr<GameObject> getObject(int id);
    static void update();

  private:
    GameObjectManager();
    static std::map<int, std::shared_ptr<GameObject>> gameObjects;
    static int objectCount;
};