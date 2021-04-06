//
// Created by charl on 5/04/2021.
//

#include "DemoScene.hpp"

void DemoScene::Init() 
{
    terrainManager.Init();

}

void DemoScene::Update() {

    GameObjectManager::update();
    // Draw Object
}
void DemoScene::Draw()
{
    GameObjectManager::draw();
    terrainManager.Draw(GameObjectManager::getPlayer()->getPosition());
}
void DemoScene::Enable()
{
    isEnabled = true;
}
void DemoScene::Disable()
{
    isEnabled = false;
}