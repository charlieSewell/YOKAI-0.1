//
// Created by charl on 5/04/2021.
//

#include "DemoScene.hpp"

void DemoScene::Init() 
{
    terrainManager.Init();
    controlsScreen = new SplashScreen("content/Textures/help_menu.png");
    registerMenuButtons();
	zombieInit();
}

void DemoScene::Update()
{
    GameObjectManager::update();
}

void DemoScene::Draw()
{
    GameObjectManager::draw();
    terrainManager.Draw(GameObjectManager::getPlayer()->getPosition());
    if(controlsScreen->isActive())
	{
        controlsScreen->draw();
    }

	zombieUpdate();
}

void DemoScene::Enable()
{
    isEnabled = true;
}
void DemoScene::Disable()
{
    isEnabled = false;
}
void DemoScene::registerMenuButtons()
{
    static bool isPressed;
    auto menuButtonReleased = [&]()
    {
        isPressed = false;

    };
    EMS::getInstance().add(InputEvent::toggleMenuReleased, menuButtonReleased);

    auto toggleMenuPressed = [&]()
    {
        if (!isPressed){
            if (controlsScreen->isActive())
            {
                controlsScreen->setInactive();
                isPressed = true;
            }
            else{
                controlsScreen->setActive();
                isPressed = true;
            }
        }
    };
    EMS::getInstance().add(InputEvent::toggleMenuPressed, toggleMenuPressed);
}

void DemoScene::zombieInit()
{
	ModelManager::getInstance().loadAnimation("content/Models/animatedZombie/keyframes.txt");
	zombieAngle = 0.0f;
	zombieRotationSpeed = 0.1f;
	zombieHeading = glm::vec3(0,0,0);
	zombieMovementSpeed = 0.25f;
	zombieTransform = glm::mat4(1.0);
	zombieTransform = glm::translate(zombieTransform, glm::vec3(510, 20, 510));
	zombieTransform = glm::scale(zombieTransform, glm::vec3(0.2, 0.2, 0.2));

	auto zombieRotateLeft = [&]()
	{
		zombieAngle += zombieRotationSpeed;
		zombieTransform = glm::rotate(zombieTransform, zombieRotationSpeed, glm::vec3(0, 1, 0));
	};

	auto zombieRotateRight = [&]()
	{
		zombieAngle -= zombieRotationSpeed;
		zombieTransform = glm::rotate(zombieTransform, -zombieRotationSpeed, glm::vec3(0, 1, 0));
	};

	auto zombieMoveForward = [&]()
	{
		glm::vec3 position = glm::vec3(zombieTransform[3]);

		if(position.y - 0.5 < TerrainFactory::getInstance().heightVals[int(position.x)][int(position.z)])
			zombieHeading.y = 0.5;
		else
			zombieHeading.y = -0.5;

		zombieTransform = glm::translate(zombieTransform, zombieHeading * zombieMovementSpeed);

		isWalking = true;
	};

	auto zombieStopped = [&]() { isWalking = false; };

	EMS::getInstance().add(InputEvent::zombieRotateLeft, zombieRotateLeft);
	EMS::getInstance().add(InputEvent::zombieRotateRight, zombieRotateRight);
	EMS::getInstance().add(InputEvent::zombieMoveForward, zombieMoveForward);
	EMS::getInstance().add(InputEvent::zombieStopped, zombieStopped);
}

void DemoScene::zombieUpdate()
{
	if (zombieAngle > glm::pi<float>())
		zombieAngle = -glm::pi<float>();
	if (zombieAngle < -glm::pi<float>())
		zombieAngle = glm::pi<float>();

	zombieHeading = glm::normalize(glm::vec3(sin(glm::radians(zombieAngle)), 0, cos(glm::radians(zombieAngle))));
	

	ModelManager::getInstance().DrawAnimatedModel(zombieTransform, isWalking);
}
