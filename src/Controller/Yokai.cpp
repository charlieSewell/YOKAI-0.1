//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"

#include "Animator.hpp"
#include "DemoScene.hpp"
#include "MainMenuScene.hpp"

Yokai &Yokai::getInstance() 
{
    static Yokai instance;
    return instance;
}

void Yokai::Init() 
{
    registerClose();
    //registerUI();

    if(!window.Init())
    {
        return;
    }
    renderer.Init();
    if(!window.ImguiInit())
    {
        return;
    }

    //Add layers to layer stack
    activeLayer = 0;
    //layers.push_back(std::shared_ptr<Layer>(new DemoScene()));
    layers.push_back(std::shared_ptr<Layer>(new MainMenuScene()));
    layers.push_back(std::shared_ptr<Layer>(new DemoScene()));
    TerrainFactory::getInstance().Init();
    PhysicsSystem::getInstance().Init();
    for(auto& layer: layers)
    {
        layer->Init();
    }


    //GameObjectManager::init();

    endScreen = new SplashScreen("content/Textures/exit_screen.png");
    
    /*
    healthbar = 700;
    healthUI = new SplashScreen("content/Textures/health.jpg");
    healthUI->setupPanel(glm::vec3(50, 950, 1), glm::vec3(700, 950, 1), glm::vec3(50, 1000, 1), glm::vec3(700, 1000, 1));
    healthUI->setActive();

    shieldUI = new SplashScreen("content/Textures/shield.png");
    shieldUI->setupPanel(glm::vec3(50, 875, 1), glm::vec3(700, 875, 1), glm::vec3(50, 925, 1), glm::vec3(700, 925, 1));
    shieldUI->setActive();

    // AMMO TESTING
    ammoMainUI = new SplashScreen("content/Textures/3.png");
    ammoMainUI->setupPanel(glm::vec3(1700, 800, 1), glm::vec3(1750, 800, 1),
                              glm::vec3(1700, 900, 1), glm::vec3(1750, 900, 1));
    ammoMainUI->setActive();

    ammoMainUI2 = new SplashScreen("content/Textures/0.png");
    ammoMainUI2->setupPanel(glm::vec3(1750, 800, 1), glm::vec3(1800, 800, 1),
                               glm::vec3(1750, 900, 1), glm::vec3(1800, 900, 1));
    ammoMainUI2->setActive();
    
    ammoReserveUI = new SplashScreen("content/Textures/1.png");
    ammoReserveUI->setupPanel(glm::vec3(1750, 900, 1), glm::vec3(1800, 900, 1),
                           glm::vec3(1750, 1000, 1), glm::vec3(1800, 1000, 1));
    ammoReserveUI->setActive();

    ammoReserveUI2 = new SplashScreen("content/Textures/0.png");
    ammoReserveUI2->setupPanel(glm::vec3(1800, 900, 1), glm::vec3(1850, 900, 1),
                           glm::vec3(1800, 1000, 1), glm::vec3(1850, 1000, 1));
    ammoReserveUI2->setActive();

    ammoReserveUI3 = new SplashScreen("content/Textures/0.png");
    ammoReserveUI3->setupPanel(glm::vec3(1850, 900, 1), glm::vec3(1900, 900, 1),
                               glm::vec3(1850, 1000, 1), glm::vec3(1900, 1000, 1));
    ammoReserveUI3->setActive();

    ammoNumbers.push_back("content/Textures/0.png");
    ammoNumbers.push_back("content/Textures/1.png");
    ammoNumbers.push_back("content/Textures/2.png");
    ammoNumbers.push_back("content/Textures/3.png");
    ammoNumbers.push_back("content/Textures/4.png");
    ammoNumbers.push_back("content/Textures/5.png");
    ammoNumbers.push_back("content/Textures/6.png");
    ammoNumbers.push_back("content/Textures/7.png");
    ammoNumbers.push_back("content/Textures/8.png");
    ammoNumbers.push_back("content/Textures/9.png");
    */
    // END OF AMMO TESTING

    isPaused = false;
}
void Yokai::Run()
{
    PhysicsSystem::getInstance().addTerrain();

    const float timeStep = 1.0f / 60;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;
    double accumulator = 0;

    while(isRunning)
	{
		double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        accumulator += deltaTime;

        renderer.Clear();
        window.startFrame();
        InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
		InputManagerGLFW::getInstance().processMouse(window.getWindow());

		while (accumulator >= timeStep) {
            PhysicsSystem::getInstance().update(timeStep);
            if (isPaused == false)
            {
                layers[activeLayer]->Update(timeStep);
            }
            accumulator -= timeStep;
        }
        layers[activeLayer]->Draw();

        if(endScreen->isActive())
        {
            endScreen->draw();
        }
        if (glfwGetKey(window.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            isPaused = !isPaused;

            if (isPaused) {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            } else {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }
        }
        renderer.DrawGui();
        window.endFrame();
	}
    GameObjectManager::getInstance().DeInit();
    PhysicsSystem::getInstance().DeInit();
    renderer.DeInit();
    window.DeInit();
}
// AMMO TESTING
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
if (gun.getReserveAmmo() >= 0)
{
    int remainder = gun.getAmmo() % 10;
    ammoMainUI->setTexture(ammoNumbers[(gun.getAmmo() - remainder) / 10]);
    ammoMainUI2->setTexture(ammoNumbers[remainder]);

    int rRemainder = gun.getReserveAmmo() % 10;

    if (gun.getReserveAmmo() >= 100)
    {
        ammoReserveUI->setTexture(ammoNumbers[1]);
        ammoReserveUI2->setTexture(ammoNumbers[(gun.getReserveAmmo() - 100 - rRemainder) / 10]);
    }
    else
    {
        ammoReserveUI->setTexture(ammoNumbers[0]);
        ammoReserveUI2->setTexture(ammoNumbers[(gun.getReserveAmmo() - rRemainder) / 10]);
    }

    ammoReserveUI3->setTexture(ammoNumbers[rRemainder]);
}
else
{
    ammoMainUI->setTexture(ammoNumbers[0]);
    ammoMainUI2->setTexture(ammoNumbers[0]);

    ammoReserveUI->setTexture(ammoNumbers[0]);
    ammoReserveUI2->setTexture(ammoNumbers[0]);
    ammoReserveUI3->setTexture(ammoNumbers[0]);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GUN ANIMATION LOGIC
if (gun.getAmmo() == 0 && gun.getReserveAmmo() == 0)
{
    keyframe->setTPS(20);
    keyframe->setAnimation("idle");
}
else if (gun.getAmmo() == 0)
{
    keyframe->setTPS(30);
    keyframe->setAnimation("emptyreload");
    gun.reload();
}

if (glfwGetKey(window.getWindow(), GLFW_KEY_R) == GLFW_PRESS)
{
    if (gun.getAmmo() != 0 && (gun.getAmmo() != gun.getMaxAmmo()) && gun.getReserveAmmo() != 0)
    {
        keyframe->setTPS(30);
        keyframe->setAnimation("reload");
        gun.reload();
    }
}

if (glfwGetKey(window.getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
{
    gun.decrementAmmo();
}

if (glfwGetKey(window.getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
{
    keyframe->setTPS(20);
    keyframe->setAnimation("idle");
}

if (glfwGetMouseButton(window.getWindow(), GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
{
    if (gun.getAmmo() != 0)
    {
        if (keyframe->getCurrentAnimation() == "idle")
        {
            keyframe->setTPS(30);
            keyframe->setAnimation("fire");
            gun.decrementAmmo();
        }
        else if (keyframe->getAnimationFinished())
        {
            keyframe->setTPS(30);
            keyframe->setAnimation("fire");
            gun.decrementAmmo();
        }
    }
}

if (glfwGetKey(window.getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
{
    gun.incrementAmmo();
}

if (keyframe->getAnimationFinished())
{
    keyframe->setTPS(20);
    keyframe->setAnimation("idle");
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//healthUI->draw();
//shieldUI->draw();
/*
ammoMainUI->draw();
ammoMainUI2->draw();
if (gun.getReserveAmmo() >= 100)
{
    ammoReserveUI->draw();
}
ammoReserveUI2->draw();
ammoReserveUI3->draw();
*/
// UI
/////////////////////////////////////////////////////////////////////////////////////////////////////
///

void Yokai::registerClose()
{
    static bool isPressed = false;
    auto closeReleased = [&]()
    {
        isPressed = false;
    };
    EMS::getInstance().add(NoReturnEvent::closeReleased, closeReleased);

    auto closePressed = [&]()
    {
      if (!isPressed){
          if (endScreen->isActive())
          {
              endScreen->setInactive();
              isPressed = true;
          }
          else{
              endScreen->setActive();
              isPressed = true;
          }
      }
    };
    EMS::getInstance().add(NoReturnEvent::closePressed, closePressed);

    auto close = [&]() {
        if(endScreen->isActive())
        {
            isRunning = false;
        }

    };
    EMS::getInstance().add(NoReturnEvent::mouseClicked, close);
}


void Yokai::registerUI() 
{
    static bool isPressed = false;
    
    auto uiReleased    = [&]() 
    { 
        isPressed = false;
    };

    EMS::getInstance().add(NoReturnEvent::uiReleased, uiReleased);

    auto uiPressed = [&]() 
    {
        if (!isPressed) 
        {
            //if(healthbar > 50) 
            //{
            //    healthbar -= 65;
            //}

            //healthUI->setupPanel(glm::vec3(50, 950, 1), glm::vec3(healthbar, 950, 1), glm::vec3(50, 1000, 1), glm::vec3(healthbar, 1000, 1));
            isPressed = true;
        }
    };

    EMS::getInstance().add(NoReturnEvent::uiPressed, uiPressed);
}

void Yokai::setIsRunning(bool s) 
{
    isRunning = s;
}

std::vector<std::shared_ptr<Layer>> Yokai::getLayer() 
{
    return layers;
}

void Yokai::setActiveLayer(int a) 
{
    activeLayer = a;
}

void Yokai::setIsPaused(bool p) 
{
    isPaused = p;
}

bool Yokai::getIsPaused() 
{
    return isPaused;
}