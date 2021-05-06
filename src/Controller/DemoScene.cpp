#include "DemoScene.hpp"

void DemoScene::Init() 
{
    auto& terrainFactory = TerrainFactory::getInstance();
    terrainManager.setTerrainTexture(terrainFactory.getTextures());
    terrainManager.setGrassHeight(terrainFactory.getGrassHeight());
    terrainManager.setSandHeight(terrainFactory.getSandHeight());
    terrainManager.setSnowHeight(terrainFactory.getSnowHeight());
    terrainManager.Init();
    controlsScreen = new SplashScreen("content/Textures/help_menu.png");
    registerMenuButtons();
}

void DemoScene::Update(double frameRate)
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
                glfwSetInputMode(Yokai::getInstance().window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                controlsScreen->setInactive();
                isPressed = true;
            }
            else
            {
                glfwSetInputMode(Yokai::getInstance().window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                controlsScreen->setActive();
                isPressed = true;
            }
        }
    };
    EMS::getInstance().add(InputEvent::toggleMenuPressed, toggleMenuPressed);
}