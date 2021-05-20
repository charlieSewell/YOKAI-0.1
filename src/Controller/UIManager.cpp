#include "Controller/UIManager.hpp"

UIManager &UIManager::getInstance() 
{
    static UIManager instance;
    return instance;
}

UIManager::UIManager() {}

void UIManager::init() 
{

    /*
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("ObjectManager")
        .addFunction("Create", GameObjectManager::CreateObject)
        .addFunction("GetObject", GameObjectManager::luaGet)
        .addFunction("GetPlayer", GameObjectManager::getPlayer)
        .addFunction("GetNPC", GameObjectManager::getNPC)
        .addFunction("Update", GameObjectManager::update)
        .endNamespace();

    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginNamespace("Types")
        .addFunction("npc", LuaTypes::getNPCType)
        .addFunction("player", LuaTypes::getPlayerType)
        .addFunction("static", LuaTypes::getStaticType)
        .endNamespace();

    LuaManager::getInstance().runScript("content/Scripts/createObjects.lua");
    std::cout << "Game Object Manager Initialised" << std::endl;
    */
}

int UIManager::add(std::shared_ptr<SplashScreen> &gameObject) 
{
    uiObjects[objectCount] = gameObject;
    objectCount++;
    return objectCount - 1;
}

void UIManager::update(float dt) 
{
    for (auto &gameObject : uiObjects) 
    {
        //gameObject.second->update(dt);
    }
}
void UIManager::draw() 
{
    for (auto &gameObject : uiObjects) 
    {
        gameObject.second->draw();
    }
}

std::shared_ptr<SplashScreen> UIManager::getObject(int id) 
{

    if (uiObjects[id] != nullptr) 
    {
        return uiObjects[id];
    }
    return nullptr;
}

// static declaration of member variables
int UIManager::objectCount = 0;
std::map<int, std::shared_ptr<SplashScreen>> UIManager::uiObjects = std::map<int, std::shared_ptr<SplashScreen>>();