//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"
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
        return;

    Renderer::Init();
    //Add layers to layer stack
    layers.push_back(new DemoScene());
    for(int i =0;i < layers.size(); i++)
        layers[i]->Init();

    GameObjectManager::init();
    endScreen = new SplashScreen("content/Textures/exit_screen.png");

}
void Yokai::Run()
{
	const double frameRate = 1.0f / 120;	// 120 fps
	double leastUPdate = 0;
	double lastFrame = 0;

	
    while(isRunning)
	{
		double currentTime = glfwGetTime();

		if((currentTime - lastFrame) >= frameRate)
		{
			Renderer::Clear();

			InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
			InputManagerGLFW::getInstance().processMouse(window.getWindow());

			for(int i =0;i < layers.size(); i++)
				layers[i]->Update();

			for(int i =0;i < layers.size(); i++)
				layers[i]->Draw();

            if(endScreen->isActive()){
                endScreen->draw();
            }
			window.endFrame();

			lastFrame = currentTime;
		}
    }
    Renderer::DeInit();
    window.DeInit();
}

void Yokai::registerClose()
{
    static bool isPressed = false;
    auto closeReleased = [&]()
    {
        isPressed = false;
    };
    EMS::getInstance().add(InputEvent::closeReleased, closeReleased);

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
    EMS::getInstance().add(InputEvent::closePressed, closePressed);

    auto close = [&]() {
        if(endScreen->isActive())
        {
            isRunning = false;
        }

    };
    EMS::getInstance().add(InputEvent::mouseClicked, close);
};
