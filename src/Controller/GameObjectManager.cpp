#include "GameObjectManager.hpp"

GameObjectManager& GameObjectManager::getInstance() 
{
    std::cout << "Getting Instance" <<std::endl;
    static GameObjectManager instance;
    return instance;
}

GameObjectManager::GameObjectManager() 
{

}
GameObjectManager::~GameObjectManager()
{

}
void GameObjectManager::init()
{
    GameObject::registerClass();
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginClass<GameObjectManager>("ObjectManager")
            .addStaticFunction("getInstance",&GameObjectManager::getInstance)
            .addFunction("Create",&GameObjectManager::CreateObject)
            .addFunction("GetObject",&GameObjectManager::luaGet)
            .addFunction("Update",&GameObjectManager::update)
        .endClass();

    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("Types")
            .addFunction("npc",LuaTypes::getNPCType)
            .addFunction("player",LuaTypes::getPlayerType)
            .addFunction("static",LuaTypes::getStaticType)
        .endNamespace();

    LuaManager::getInstance().runScript("content/Scripts/createObjects.lua");
    std::cout << "Game Object Manager Initialised" << std::endl;
}
int GameObjectManager::CreateObject(GameObjectType type,std::string model)
{
    if(type == GameObjectType::player){
        gameObjects[objectCount] = GameAssetFactory::Create(type);
        gameObjects[objectCount]->setID(objectCount);
        playerID = objectCount;
    }
    else
    {
        gameObjects[objectCount] = GameAssetFactory::Create(type,model);
        gameObjects[objectCount]->setID(objectCount);
    }

    objectCount++;

    return objectCount - 1;
}

int GameObjectManager::add(std::shared_ptr<GameObject>& gameObject)
{
    gameObject->setID(objectCount);
    gameObjects[objectCount] = gameObject;
    objectCount++;
    return objectCount - 1;
}
void GameObjectManager::DeInit(){
    gameObjects.clear();
}
void GameObjectManager::DeleteGameObject(unsigned int id)
{
    gameObjects.erase(id);
}

void GameObjectManager::update(float dt)
{
    for(auto& gameObject :gameObjects)
    {
        gameObject.second->update(dt);
    }
}
void GameObjectManager::draw()
{
    for(auto& gameObject :gameObjects)
    {
        gameObject.second->draw();
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
        return gameObjects[id];
    }
    return nullptr;
}
GameObject* GameObjectManager::luaGet(int id)
{

    if(gameObjects[id] != nullptr)
    {
        return gameObjects[id].get();
    }
    return nullptr;
}
