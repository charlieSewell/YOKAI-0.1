#pragma once
#include <iostream>
#include <glm/glm.hpp>

#include "Controller/ModelManager.hpp"
#include "GameObject.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "View/Renderer/Shader.hpp"

/**
 * @class Pickup
 * @brief Child of GameObject for all Pickups within the game. Inherits physics component.
 */
class Pickup : public GameObject, public PhysicsComponent
{
  public:
    /*!
     * @brief Constructor
     * @param string - modelName
     */
    Pickup(std::string modelName);

    void update();

    /*!
     * @brief Draw call for the Pickup model
     */
    void draw();

    /*!
     * @brief Getter for the position of the Pickup
     * @return position
     */
    // glm::vec3 getPosition();

    void setHealth(float h);

    float getHealth();

    void setShields(float s);

    float getShields();

    void setAlive(bool a);

    bool getAlive();

  private:
    /// Stores associated model id of the Pickup
    int modelID;
};