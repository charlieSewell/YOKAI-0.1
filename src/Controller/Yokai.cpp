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
    {
        return;
    }
    renderer.Init();
    //Add layers to layer stack
    layers.push_back(std::shared_ptr<Layer>(new DemoScene()));
    TerrainFactory::getInstance().Init();
    for(auto& layer: layers)
    {
        layer->Init();
    }
    GameObjectManager::init();
    endScreen = new SplashScreen("content/Textures/exit_screen.png");


}
void Yokai::Run()
{
	const double frameRate = 1.0f / 300;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;

    ModelLoader modelLoader;
    Model test = modelLoader.loadModel("content/Models/Zombie/ZombieSmooth.gltf");
    Model test1 = modelLoader.loadModel("content/Models/Zombie/ZombieSmooth.gltf");
    Model test2 = modelLoader.loadModel("content/Models/Zombie/ZombieSmooth.gltf");
    Model test3 = modelLoader.loadModel("content/Models/Zombie/ZombieSmooth.gltf");

    Shader testShader = Shader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");

    Animator animator(std::make_shared<Model>(test));
    Animator animator1(std::make_shared<Model>(test1));
    Animator animator2(std::make_shared<Model>(test2));
    Animator animator3(std::make_shared<Model>(test3));
    animator.setAnimation("ZombieBite");
    animator1.setAnimation("ZombieIdle");
    animator2.setAnimation("ZombieAttack");
    animator3.setAnimation("ZombieRun");

    while(isRunning)
	{
		double currentTime = glfwGetTime();
        double frameTime = currentTime - lastTime;
        lastTime = currentTime;


		if((currentTime - lastFrame) >= frameRate)
		{
            glm::mat4 model(1.0);
            model = glm::translate(model,glm::vec3(500,20,500));
            glm::mat4 model1(1.0);
            model1 = glm::translate(model1,glm::vec3(480,20,500));
            glm::mat4 model2(1.0);
            model2 = glm::translate(model2,glm::vec3(490,20,500));
            glm::mat4 model3(1.0);
            model3 = glm::translate(model3,glm::vec3(510,20,500));

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
            animator1.BoneTransform(frameRate);
            animator2.BoneTransform(frameRate);
            animator3.BoneTransform(frameRate);

            testShader.useShader();
            testShader.setBool("isAnimated",true);
            testShader.setVecMat4("boneTrans",animator.finalTransforms);
            test.Draw(testShader,model);

            testShader.useShader();
            testShader.setBool("isAnimated",true);
            testShader.setVecMat4("boneTrans",animator1.finalTransforms);
            test1.Draw(testShader,model1);

            testShader.useShader();
            testShader.setBool("isAnimated",true);
            testShader.setVecMat4("boneTrans",animator2.finalTransforms);
            test2.Draw(testShader,model2);

            testShader.useShader();
            testShader.setBool("isAnimated",true);
            testShader.setVecMat4("boneTrans",animator3.finalTransforms);
            test3.Draw(testShader,model3);
            if(endScreen->isActive())
            {
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