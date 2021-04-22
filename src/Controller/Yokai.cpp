//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"
#include "DemoScene.hpp"
#include "Animator.hpp"
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
	const double frameRate = 1.0f / 120;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;
	ModelLoader modelLoader;
	Model test = modelLoader.loadModel("content/Models/test/AnimatedHuman.gltf");
	Animator animator;
	Shader testShader = Shader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");
	animator.attachModel(std::make_shared<Model>(test));
	glm::mat4 transform(1.0);
    transform = glm::translate(transform,glm::vec3(500,30,500));
    testShader.useShader();
    
    while(isRunning)
	{

		double currentTime = glfwGetTime();
        double frameTime = currentTime - lastTime;
          lastTime = currentTime;
		if((currentTime - lastFrame) >= frameRate)
		{
			renderer.Clear();
			InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
			InputManagerGLFW::getInstance().processMouse(window.getWindow());

            for(auto& layer: layers)
				layer->Update();

            for(auto& layer: layers)
				layer->Draw();

            if(endScreen->isActive()){
                endScreen->draw();
            }
            animator.BoneTransform(frameTime);
            testShader.useShader();
            testShader.setMat4("projection", EMS::getInstance().fire(RenderEvent::getPerspective));
            testShader.setMat4("view", EMS::getInstance().fire(RenderEvent::getViewMatrix));
            testShader.setBool("isAnimated", true);
            testShader.setVecMat4("boneMatrices",animator.finalTransforms);

            test.Draw(testShader,transform);
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
};
