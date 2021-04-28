//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"
#include "DemoScene.hpp"
#include "Animator.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

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

    renderer.Init();
    //Add layers to layer stack
    layers.push_back(std::shared_ptr<Layer>(new DemoScene()));
    for(auto& layer: layers)
        layer->Init();

    GameObjectManager::init();
    endScreen = new SplashScreen("content/Textures/exit_screen.png");


}
void Yokai::Run()
{
	const double frameRate = 1.0f / 300;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;

    ModelLoader modelLoader;
    Model test = modelLoader.loadModel("content/Models/Mike.gltf");
    Shader testShader = Shader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");

    Animator animator(std::make_shared<Model>(test));
    animator.setAnimation("Run");
    while(isRunning)
	{
		double currentTime = glfwGetTime();
        double frameTime = currentTime - lastTime;
        lastTime = currentTime;


		if((currentTime - lastFrame) >= frameRate)
		{
            glm::mat4 model(1.0);
            model = glm::translate(model,glm::vec3(500,20,500));
			renderer.Clear();
			InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
			InputManagerGLFW::getInstance().processMouse(window.getWindow());

            for(auto& layer: layers)
            {
                layer->Update(frameTime);

            }
            for(auto& layer: layers)
            {
                layer->Draw();
            }

            animator.BoneTransform(frameRate);

            testShader.useShader();
            testShader.setBool("isAnimated",true);
            testShader.setVecMat4("boneTrans",animator.finalTransforms);

            test.Draw(testShader,model);
            if(endScreen->isActive()){
                endScreen->draw();
            }

			window.endFrame();
			lastFrame = currentTime;
		}
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
}