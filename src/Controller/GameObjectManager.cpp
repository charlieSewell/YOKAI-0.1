#include "GameObjectManager.hpp"
GameObjectManager& GameObjectManager::getInstance() 
{
    static GameObjectManager instance;
    return instance;
}

GameObjectManager::GameObjectManager() 
{
}

void GameObjectManager::init() 
{
    GameObject::registerClass();
    std::cout << "Test" << std::endl;
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("ObjectManager")
            .addFunction("Create",GameObjectManager::CreateObject)
            .addFunction("GetObject",GameObjectManager::getObject)
            .addFunction("Update",GameObjectManager::update)
        .endNamespace();

    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("Types")
            .addFunction("npc",LuaTypes::getNPCType)
            .addFunction("player",LuaTypes::getPlayerType)
            .addFunction("static",LuaTypes::getStaticType)
        .endNamespace();


    LuaManager::getInstance().runScript("content/Scripts/assets.lua");

}
int GameObjectManager::CreateObject(GameObjectType type)
{
    gameObjects[objectCount] = GameAssetFactory::Create(type,"content/Models/pine.fbx");
    gameObjects[objectCount]->setPosition(glm::vec3(0,0,0));
    objectCount++;
    std::cout << "success" <<std::endl;
    return objectCount - 1;
}
int GameObjectManager::add(std::shared_ptr<GameObject>& gameObject)
{
    gameObjects[objectCount] = gameObject;
    objectCount++;
    return objectCount - 1;
}
void GameObjectManager::update() {
    for(int i =0; i < gameObjects.size();i++)
    {
        gameObjects[i]->update();
        gameObjects[i]->draw();
    }
}
std::shared_ptr<GameObject> GameObjectManager::getObject(int id) 
{
    return gameObjects.at(id);
}
int GameObjectManager::objectCount = 0;
std::map<int, std::shared_ptr<GameObject>> GameObjectManager::gameObjects = std::map<int, std::shared_ptr<GameObject>>();