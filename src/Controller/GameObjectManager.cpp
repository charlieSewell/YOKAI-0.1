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
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("ObjectManager")
            .addFunction("Create",GameObjectManager::CreateObject)
            .addFunction("GetObject",GameObjectManager::luaGet)
            .addFunction("Update",GameObjectManager::update)
        .endNamespace();

    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("Types")
            .addFunction("npc",LuaTypes::getNPCType)
            .addFunction("player",LuaTypes::getPlayerType)
            .addFunction("static",LuaTypes::getStaticType)
        .endNamespace();
    playerID = CreateObject(GameObjectType::player,"");
    getPlayer()->setPosition(glm::vec3(10, 2.0f, 10));
    getPlayer()->setCollider(4, 4, 4.0);
    LuaManager::getInstance().runScript("content/Scripts/createObjects.lua");
}

int GameObjectManager::CreateObject(GameObjectType type,std::string model)
{
    if(type == GameObjectType::player){
        gameObjects[objectCount] = GameAssetFactory::Create(type);
    }
    else
    {
        gameObjects[objectCount] = GameAssetFactory::Create(type,model);
    }

    objectCount++;

    return objectCount - 1;
}

int GameObjectManager::add(std::shared_ptr<GameObject>& gameObject)
{
    gameObjects[objectCount] = gameObject;
    objectCount++;
    return objectCount - 1;
}

void GameObjectManager::update() 
{

    for(int i = 0; i < gameObjects.size(); i++)
    {

        gameObjects[i]->update();
    }
}
void GameObjectManager::draw()
{

    for(int i = 0; i < gameObjects.size(); i++)
    {

        gameObjects[i]->draw();
    }
}
std::shared_ptr<GameObject> GameObjectManager::getPlayer()
{
        return gameObjects[playerID];
}
std::shared_ptr<GameObject> GameObjectManager::getObject(int id) 
{

    if(gameObjects[id] != nullptr)
    {
        std::cout << "ObjReturned" <<std::endl;
        return gameObjects[id];
    }

}
GameObject* GameObjectManager::luaGet(int id)
{

    if(gameObjects[id] != nullptr)
    {
        std::cout << "ObjReturned" <<std::endl;
        return gameObjects[id].get();
    }

}
//static declaration of member variables
int GameObjectManager::objectCount = 0;
int GameObjectManager::playerID = 0;
std::map<int, std::shared_ptr<GameObject>> GameObjectManager::gameObjects = std::map<int, std::shared_ptr<GameObject>>();