#include "Controller/Layer.hpp"
//included for lab 7
#include "ModelManager.hpp"
#include "Factory/TerrainFactory.hpp"

/**
 * @class DemoScene
 * @brief A demo Scene for Assignment 1
 */
class DemoScene : public Layer
{
  public:
    /**
     * @brief Initialised the Scene
     */
    void Init() override;
    /**
     * @brief Updates the Scene
     */
    void Update() override;
    /**
     * @brief Draws the Scene
     */
    void Draw() override;
    /**
     * @brief Enables the Scene
     */
    void Enable() override;
    /**
     * @brief Disables the Scene
     */
    void Disable() override;
  private:
    ///Terrain Manager for the scene
    TerrainManager terrainManager = {};
    ///Controls SplashScreen
    SplashScreen* controlsScreen;
    ///Is this scene active
    bool isEnabled = true;
    /**
     * @brief Registers Menu Buttons
     */
    void registerMenuButtons();

	// Lab 7 Connor
	void zombieInit();
	void zombieUpdate();
	float zombieAngle;
	glm::vec3 zombieHeading;
	float zombieRotationSpeed;
	float zombieMovementSpeed;
	glm::mat4 zombieTransform;
	bool isWalking;
};
