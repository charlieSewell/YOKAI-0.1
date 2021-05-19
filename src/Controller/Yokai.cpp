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
    registerUI();

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
    GameObjectManager::init();
    endScreen = new SplashScreen("content/Textures/exit_screen.png");

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

    gun.setMaxAmmo(30);
    gun.setMaxReserveAmmo(150);

    // END OF AMMO TESTING

    keyframe = new KeyframeAnimation();

    inGame = true;
    isPaused = false;
}
void Yokai::Run()
{
	const double frameRate = 1.0f / 300;	// 120 fps

	double lastFrame = 0;
    double lastTime = 0;

    //KEYFRAME TESTING
    
    keyframe->readFile("content/Models/guntest.txt");
    keyframe->setTPS(20);
    keyframe->addAnimation("fire", 1, 7);
    keyframe->addAnimation("reload", 7, 55);
    keyframe->addAnimation("emptyreload", 55, 108);
    keyframe->addAnimation("idle", 142, 164);
    keyframe->setAnimation("idle");
    

    while(isRunning)
	{
        double currentTime = glfwGetTime();
        double frameTime = currentTime - lastTime;
        lastTime = currentTime;

        /*
        if (isPaused) 
        {
            currentTime = currentTime * 0;
        } 
        else 
        {
            currentTime = currentTime * 1;
        }
        */

		if((currentTime - lastFrame) >= frameRate)
		{
            renderer.Clear();
            window.startFrame();
            glm::mat4 model(1.0);
            model = glm::translate(model,glm::vec3(500,20,500));
            glm::mat4 model1(1.0);
            model1 = glm::translate(model1,glm::vec3(480,20,500));
            glm::mat4 model2(1.0);
            model2 = glm::translate(model2,glm::vec3(490,20,500));
            glm::mat4 model3(1.0);
            model3 = glm::translate(model3,glm::vec3(510,20,500));


			InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
			InputManagerGLFW::getInstance().processMouse(window.getWindow());

            glm::mat4 transform(1.0);
            transform = glm::translate(transform, glm::vec3(512, 25, 512));
            transform = glm::scale(transform, glm::vec3(0.03, 0.03, 0.03));
            
            // KEYFRAME TESTING
            //keyframe->setCurrentFrame(frameTime);
            //keyframe->draw();

            // AMMO TESTING
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
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
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////

            if (inGame == true) 
            {
                if (isPaused == false) 
                {
                    for (auto &layer : layers) 
                    {
                        layer->Update(frameTime);
                    }

                    keyframe->setCurrentFrame(frameTime);
                }
                for (auto &layer : layers) 
                {
                    layer->Draw();
                }
                keyframe->draw();
            }

            if(endScreen->isActive())
            {
                endScreen->draw();
            }

            healthUI->draw();
            shieldUI->draw();
            ammoMainUI->draw();
            ammoMainUI2->draw();
            if (gun.getReserveAmmo() >= 100) 
            {
                ammoReserveUI->draw();
            }
            ammoReserveUI2->draw();
            ammoReserveUI3->draw();

			lastFrame = currentTime;
            
            ImGui::Begin("Main Menu");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("Main Menu");               // Display some text (you can use a format strings too)
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            if(ImGui::Button("Start Game",ImVec2(500,100)))
            {
                std::cout << "Starting Game" <<std::endl;
                inGame = true;
            }
            if(ImGui::Button("Settings",ImVec2(500,100)))
            {
                std::cout << "Entering Settings" <<std::endl;
            }
            if (ImGui::Button("Pause", ImVec2(500, 100))) 
            {
                std::cout << "Paused" << std::endl;
                isPaused = !isPaused;
            }
            if(ImGui::Button("Quit",ImVec2(500,100)))
            {
                std::cout << "Quitting" <<std::endl;
                isRunning = false;
            }

            ImGui::End();
            renderer.DrawGui();
            window.endFrame();
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
            if(healthbar > 50) 
            {
                healthbar -= 65;
            }

            healthUI->setupPanel(glm::vec3(50, 950, 1), glm::vec3(healthbar, 950, 1), glm::vec3(50, 1000, 1), glm::vec3(healthbar, 1000, 1));
            isPressed = true;
        }
    };

    EMS::getInstance().add(NoReturnEvent::uiPressed, uiPressed);
}