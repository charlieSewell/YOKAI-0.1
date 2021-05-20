#pragma once

#include <map>
#include "Controller/LuaManager.hpp"
#include "Controller/LuaTypes.hpp"
#include "Model/SplashScreen.hpp"

/**
 * @class GameObjectManager
 * @brief Responsible for the management of all game objects created
 */
class UIManager 
{
  public:
    /*!
     * @brief Singleton Pattern for a single instance of the class
     * @return instance
     */
    static UIManager &getInstance();

    /*!
     * @brief Initialises the manager
     */
    static void init();

    /*!
     * @brief Adds a GameObject to the map of GameObjects
     * @param GameObject smart pointer - &gameObject
     * @return objectCount-1
     */
    static int add(std::shared_ptr<SplashScreen> &splashScreen);

    /*!
     * @brief Getter for a GameObject with the specified id
     * @param int - id
     * @return GameObject
     */
    static std::shared_ptr<SplashScreen> getObject(int id);

    /*!
     * @brief Calls the update function for all GameObjects
     */
    static void update(float dt);

    /*!
     * @brief Calls the draw function for all GameObjects
     */
    static void draw();

    //static NPC *getNPC(int id);

  private:
    /*!
     * @brief Constructor
     */
    UIManager();

    /// Map of GameObjects, with the key of the GameObject id, and value of the GameObject smart pointer
    static std::map<int, std::shared_ptr<SplashScreen>> uiObjects;

    /// Stores the number of GameObjects within the map
    static int objectCount;
};
