//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"

#include "Animator.hpp"
#include "DemoScene.hpp"
Yokai &Yokai::getInstance() 
{
    static Yokai instance;
    return instance;
}

void Yokai::Init() 
{
    registerClose();
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
    layers.push_back(std::shared_ptr<Layer>(new DemoScene()));
    TerrainFactory::getInstance().Init();
    for(auto& layer: layers)
    {
        layer->Init();
    }
    PhysicsSystem::getInstance().Init();
    GameObjectManager::init();
    endScreen = new SplashScreen("content/Textures/exit_screen.png");


}
void Yokai::Run()
{
    PhysicsSystem::getInstance().addTerrain();

    const float timeStep = 1.0f / 60;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;
    double accumulator = 0;

    ModelLoader loader;
    std::shared_ptr<Model> model = std::make_shared<Model>(loader.loadModel("content/Models/Zombie/ZombieSmooth.gltf"));

    Animator animator;
    animator.addModel(model);
    animator.setAnimation("test");
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

            for (auto &layer: layers) {
                layer->Update(timeStep);
            }

            accumulator -= timeStep;
        }

        for(auto& layer: layers)
        {
            layer->Draw();
        }

        if(endScreen->isActive())
        {
            endScreen->draw();
        }

        ImGui::Begin("Menu");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("Main Menu");               // Display some text (you can use a format strings too)
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        if(ImGui::Button("Start Game",ImVec2(500,100)))
        {
            std::cout << "Starting Game" <<std::endl;
        }
        if(ImGui::Button("Settings",ImVec2(500,100)))
        {
            std::cout << "Entering Settings" <<std::endl;
        }
        if(ImGui::Button("Quit",ImVec2(500,100)))
        {
            std::cout << "Quitting" <<std::endl;
        }

        ImGui::End();
        renderer.DrawGui();
        window.endFrame();

    }
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