#pragma once

#include "Controller/TerrainManager.hpp"
#include "View/Renderer/Renderer.hpp"
#include "View/Window.hpp"
#include "Model/SplashScreen.hpp"
//#include "Controller/KeyframeAnimation.hpp"
//#include "Model/Components/Weapon.hpp"
//workaround to allow vector of layer pointers
class Layer;
/**
 * @class Yokai
 * @brief A class which ties together all game engine components
 */
class Yokai
{
  public:
    /**
     * @brief Returns an instance of the engine
     * @return Yokai&
     */
    static Yokai & getInstance();
    /**
     * @brief Initialises the engine
     */
    void Init();
    /**
     * @brief Runs the engine loop
     */
    void Run();
    ///renderer used by engine
    Renderer renderer = {};
    ///window used by the engine
    Window window = {};

    void setIsRunning(bool s);

    std::vector<std::shared_ptr<Layer>> getLayer();

    void setActiveLayer(int a);

    void setIsPaused(bool p);
    bool getIsPaused();

  private:
    //Singleton pattern requires that all constructors,destructors and copy constructors be private
    /**
     * @brief Registers Engine close event with EMS
     */
    void registerClose();

    void registerUI();
    /**
     * @brief Privatised Default Constructor
     */
    Yokai() = default;
    /**
     * @brief Privatised Default Destructor
     */
    ~Yokai() = default;
    /**
     * @brief Deleted Copy Constructor
     */
    Yokai(const Yokai &) = delete;
    /**
     * @brief Privatised assign operator
     */
    Yokai &operator =(const Yokai &);
    ///Is engine Running
    bool isRunning = true;
    ///Vector of Scene layers
    std::vector<std::shared_ptr<Layer>> layers;

    SplashScreen* endScreen;

    //SplashScreen* healthUI;

    //SplashScreen *shieldUI;

    //SplashScreen *ammoMainUI;
    //SplashScreen *ammoMainUI2;
    //SplashScreen *ammoReserveUI;
    //SplashScreen *ammoReserveUI2;
    //SplashScreen *ammoReserveUI3;

    //KeyframeAnimation *keyframe;

    //TESTING
    //int healthbar;
    bool isPaused;
    //Weapon gun;
    //std::vector<std::string> ammoNumbers;

    int activeLayer;
};