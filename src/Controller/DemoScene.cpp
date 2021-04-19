//
// Created by charl on 5/04/2021.
//

#include "DemoScene.hpp"

void DemoScene::Init() 
{
    terrainManager.Init();
    controlsScreen = new SplashScreen("content/Textures/help_menu.png");
    registerMenuButtons();

	test = GameObjectManager::CreateObject(GameObjectType::staticObject, "content/Models/tris.md2");
	GameObjectManager::getObject(test)->setPosition(glm::vec3(510, 30, 510));
	GameObjectManager::getObject(test)->setScale(glm::vec3(0.1,0.1,0.1));
}

void DemoScene::Update()
{
    GameObjectManager::update();
}
void DemoScene::Draw()
{
    GameObjectManager::draw();
    terrainManager.Draw(GameObjectManager::getPlayer()->getPosition());
    if(controlsScreen->isActive())
	{
        controlsScreen->draw();
    }
}
void DemoScene::Enable()
{
    isEnabled = true;
}
void DemoScene::Disable()
{
    isEnabled = false;
}
void DemoScene::registerMenuButtons()
{
    static bool isPressed;
    auto menuButtonReleased = [&]()
    {
        isPressed = false;

    };
    EMS::getInstance().add(InputEvent::toggleMenuReleased, menuButtonReleased);

    auto toggleMenuPressed = [&]()
    {
        if (!isPressed){
            if (controlsScreen->isActive())
            {
                controlsScreen->setInactive();
                isPressed = true;
            }
            else{
                controlsScreen->setActive();
                isPressed = true;
            }
        }
    };
    EMS::getInstance().add(InputEvent::toggleMenuPressed, toggleMenuPressed);
}