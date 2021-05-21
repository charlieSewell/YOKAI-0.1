#include "Controller/UIManager.hpp"

UIManager &UIManager::getInstance() 
{
    static UIManager instance;
    return instance;
}

UIManager::UIManager() {}

void UIManager::init() 
{
    registerClass();
}

std::shared_ptr<SplashScreen> UIManager::create(std::string texturePath) 
{
    return std::shared_ptr<SplashScreen>(new SplashScreen(texturePath));
}

std::string UIManager::add(std::string name, std::string texturePath) 
{
    //uiObjects[name] = gameObject;
    uiObjects[name] = std::shared_ptr<SplashScreen>(new SplashScreen(texturePath));
    //std::cout << "ADD" << std::endl;
    //objectCount++;
    return name;
}

void UIManager::update(float dt) 
{
    //for (auto &gameObject : uiObjects) 
    //{
        //gameObject.second->update(dt);
    //}
    LuaManager::getInstance().runScript("content/Scripts/uiLogic.lua");
}
void UIManager::draw() 
{
    for (auto &gameObject : uiObjects) 
    {
        if (gameObject.second->getActive()) 
        {
            gameObject.second->draw();
        }
    }
}

std::shared_ptr<SplashScreen> UIManager::getObject(std::string name) 
{
    //std::cout << "GET" << std::endl;
    if (uiObjects[name] != nullptr) 
    {
        return uiObjects[name];
    }
    return nullptr;
}

void UIManager::luaSetUpPanel(std::string name, float left, float right, float top, float bottom) 
{
    getObject(name)->setupPanel(left, right, top, bottom);
}

void UIManager::luaSetTexture(std::string name, std::string texturePath) 
{
    getObject(name)->setTexture(texturePath);
}

void UIManager::luaSetActive(std::string name, bool a) 
{
    getObject(name)->setActive(a);
}

void UIManager::registerClass() 
{
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginClass<UIManager>("UIManager")
        .addStaticFunction("getInstance", &UIManager::getInstance)
        .addFunction("add", &UIManager::add)
        .addFunction("getObject", &UIManager::getObject)
        .addFunction("update", &UIManager::update)
        .addFunction("setUpPanel", &UIManager::luaSetUpPanel)
        .addFunction("setTexture", &UIManager::luaSetTexture)
        .addFunction("setActive", &UIManager::luaSetActive)
        .endClass();

    LuaManager::getInstance().runScript("content/Scripts/createUI.lua");
    
    std::cout << "UI Manager Initialised" << std::endl;
}