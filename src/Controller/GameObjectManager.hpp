#include <iostream>
#include <map>
#include "Model/GameObject.hpp"

class GameObjectManager 
{
  public:
    static GameObjectManager &getInstance();
    void init();
    int add(std::shared_ptr<GameObject> &gameObject);
    std::shared_ptr<GameObject> getObject(int id);

  private:
    GameObjectManager();
    std::map<int, std::shared_ptr<GameObject>> gameObjects;
    int objectCount;
};