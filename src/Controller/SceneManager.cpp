#include "SceneManager.hpp"

SceneManager &SceneManager::getInstance() 
{
    static SceneManager instance;
    return instance;
}

SceneManager::SceneManager() {}

int SceneManager::addScene(std::shared_ptr<Layer> &scene) {
    scenes[sceneCount] = scene;
    sceneCount++;
    return sceneCount - 1;
}

std::shared_ptr<Layer> SceneManager::getScene(int id) {
    if (scenes[id] != nullptr) 
    {
        return scenes[id];
    }
    return nullptr;
}

void SceneManager::update() 
{

}

void SceneManager::draw() 
{

}