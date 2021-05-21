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

        //if(endScreen->isActive())
        //{
        //    endScreen->draw();
        //}
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
          /*
          if (endScreen->isActive())
          {
              endScreen->setInactive();
              isPressed = true;
          }
          else{
              endScreen->setActive();
              isPressed = true;
          }
          */
      }
    };
    EMS::getInstance().add(NoReturnEvent::closePressed, closePressed);

    auto close = [&]() {
        /*
        if(endScreen->isActive())
        {
            isRunning = false;
        }
        */

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