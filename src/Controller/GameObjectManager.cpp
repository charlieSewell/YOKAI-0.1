#include "GameObjectManager.hpp"

GameObjectManager& GameObjectManager::getInstance() 
{
    static GameObjectManager instance;
    return instance;
}

GameObjectManager::GameObjectManager() 
{
    objectCount = 0;
}

void GameObjectManager::init() 
{

}

int GameObjectManager::add(std::shared_ptr<GameObject>& gameObject) 
{
    objectCount++;
    gameObjects[objectCount] = gameObject;

    return objectCount - 1;
}

std::shared_ptr<GameObject> GameObjectManager::getObject(int id) 
{
    return gameObjects.at(id);
}