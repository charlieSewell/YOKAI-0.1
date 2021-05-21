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
        exit(0);
    }
    renderer.Init();
    if(!window.ImguiInit())
    {
        exit(0);
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

    const float timeStep = 1.0f / 60;

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
		InputManagerGLFW::getInstance().processGamepad();

		while (accumulator >= timeStep) {
            PhysicsSystem::getInstance().update(timeStep);

            accumulator -= timeStep;
        }
        if (!isPaused)
        {
            layers[activeLayer]->Update(static_cast<float>(deltaTime));
        }
        layers[activeLayer]->Draw();

        renderer.DrawGui();
        window.endFrame();
	}
    GameObjectManager::getInstance().DeInit();
    PhysicsSystem::getInstance().DeInit();
    renderer.DeInit();
    window.DeInit();
}

void Yokai::registerClose() {
    static bool isPressed = false;
    auto pauseRelease     = [&]() { isPressed = false; };
    EMS::getInstance().add(NoReturnEvent::pauseReleased, pauseRelease);

    auto pausePress = [&]() {
        if (!isPressed) {
            isPaused = !isPaused;
            if (isPaused) {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            } else {
                glfwSetInputMode(window.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }
            isPressed = true;
        }
    };
    EMS::getInstance().add(NoReturnEvent::pausePressed, pausePress);
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

bool Yokai::getIsPaused() const
{
    return isPaused;
}