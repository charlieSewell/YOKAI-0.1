//Player.hpp

#pragma once
#include "Model/Components/Camera.hpp"
#include "Model/Components/PhysicsComponent.hpp"
#include "Model/Components/PlayerControlledMotion.hpp"
#include "Model/GameObjects/GameObject.hpp"

/**
 * @class Player
 * @brief Child of GameObject for the player within the game. Inherits physics component, camera and player controlled motion
 */
class Player : public GameObject, public Camera, public PlayerControlledMotion, public PhysicsComponent
{
	/// Camera position
	using Camera::m_position;

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
     * @brief Getter for the position of the player
     * @return position
     */
	glm::vec3 getPosition() const override;

    /*!
     * @brief Setter for the player position
     * @param vec3 - position
     */
	void setPosition(glm::vec3 position) override;

	/*!
     * @brief Setter for the player collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	void setCollider(float width, float length, float height) override;

    /*!
     * @brief Draw call for the player model
     */
	void draw();

    /*!
     * @brief Update call for the player
     */
	void update(float dt) override;

private:
	void registerPosition();
};
