//Player.hpp

#pragma once
#include "Model/Components/Camera.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/PlayerControlledMotion.hpp"
#include "Model/GameObjects/GameObject.hpp"
#include "Model/Components/Weapon.hpp"
#include "Controller/LuaManager.hpp"
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
    PlayerControlledMotion m_movement;
    PhysicsComponent m_physics;
    bool onBox = false;
  private:
	Camera m_camera;
	
    Weapon gun;
    RayCaster rayCaster;

	void registerPosition();
	void registerColliderID();

    int health;

    int shields;

	glm::vec3 feelerRight;
	glm::vec3 feelerLeft;
};
