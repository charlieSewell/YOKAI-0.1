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
    
    layers.push_back(new DemoScene());
    for(int i =0;i < layers.size(); i++)
        layers[i]->Init();

    GameObjectManager::init();
    splashScreen = new SplashScreen("content/Textures/help_menu.png");

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

			window.endFrame();

			lastFrame = currentTime;
		}
    }
}

void Yokai::registerClose()
{
    auto close = [&]() {
        isRunning = false;
    };
    EMS::getInstance().add(InputEvent::close, close);
};
