//Player.hpp

#pragma once
#include "Model/Components/Camera.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/PlayerControlledMotion.hpp"
#include "Model/GameObjects/GameObject.hpp"
#include "Model/Components/Weapon.hpp"

/**
 * @class Player
 * @brief Child of GameObject for the player within the game. Inherits physics component, camera and player controlled motion
 */
class Player : public GameObject
{

public:
    /*!
     * @brief Constructor
     */
	Player();

	/*!
     * @brief Deconstructor
     */
	~Player();

    /*!
     * @brief Draw call for the player model
     */
	void draw();

    /*!
     * @brief Update call for the player
     */
	void update(float dt) override;
    void setCollider(float width, float length, float height) override;
    void setHealth(int h);
    int getHealth();

    void setShields(int s);
    int getShields();

private:
	Camera m_camera;
	PlayerControlledMotion m_movement;
	PhysicsComponent m_physics;
    //Weapon gun;
	void registerPosition();

    int health;

    int shields;
};
