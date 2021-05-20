//Player.hpp

#pragma once
#include "Model/Components/Camera.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/PlayerControlledMotion.hpp"
#include "Model/GameObjects/GameObject.hpp"
#include "Model/Components/Weapon.hpp"
#include "Model/Components/RayCaster.hpp"
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

	static void registerClass();

private:
	Camera m_camera;
	PlayerControlledMotion m_movement;
	PhysicsComponent m_physics;
    RayCaster rayCaster;
    //Weapon gun;
	void registerPosition();
	void registerColliderID();

    int health;

    int shields;

	glm::vec3 feelerRight;
	glm::vec3 feelerLeft;
};
