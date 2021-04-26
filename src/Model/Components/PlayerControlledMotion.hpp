//PlayerControlledMotion.hpp - Abstract class
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Controller/EventManager.hpp"
/**
 * @class PlayerControlledMotion
 * @brief Player Control component that can be attatched to game object
 */
class PlayerControlledMotion
{
public:
  /**
   * @brief Setter for Player Movement speed
   * @param float - movementSpeed
   */
	void setMovementSpeed(float movementSpeed);
    /**
     * @brief Getter for Player Movement Speed
     * @return float
     */
	float getMovementSpeed() const;
    /**
     * @brief Setter for Jump Height
     * @param float - jumpHeight
     */
	void setJumpHeight(float jumpHeight);;

protected:
  /**
   * @brief Constructor for Player Controlled Motion
   */
	PlayerControlledMotion() {}
    /**
     * @brief Destructor for player controlled motion
     */
	virtual ~PlayerControlledMotion() {}
    /**
     * @brief Registers Movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     * @param vec3& upDirection
     */
	void registerAllMovement(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
    /**
     * @brief Registers Forwared movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     */
	void registerMoveForward(glm::vec3& position, glm::vec3& frontDirection);
    /**
     * @brief Registers Backwards movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     */
	void registerMoveBackward(glm::vec3& position, glm::vec3& frontDirection);
    /**
     * @brief Registers Left movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     * @param vec3& - upDirection
     */
	void registerMoveLeft(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
    /**
     * @brief Registers Right movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     * @param vec3& - upDirection
     */
	void registerMoveRight(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
	/**
	 * @brief Registers jump with EMS
	 * @param vec3& - position
	 * @param vec3& - upDirection
	 */
    void registerJump(glm::vec3& position);
    /**
     * @brief Registers downward movement with EMS
     * @param vec3& - position
     * @param vec3& - upDirection
     */
	void registerMoveDown(glm::vec3& position, glm::vec3& upDirection);
    /**
     * Registers Mouse Movement with EMS
     * @param vec3& - frontDirection
     */
	void registerXYLook(glm::vec3& frontDirection);
    /**
     * Updates Jump
     * @param vec3& - position
     * @param vec3& - upDirection
     */
	void updateJump(glm::vec3& position, glm::vec3& upDirection);
    ///Movement speed
	float m_movementSpeed;
    ///Mouse sensitivity
	float m_lookSensitivity;
    ///Jump Height
	float m_jumpHeight;
    ///bool to check if player can jump
	bool m_canJump;
    ///bool to say whether player is in jump
	bool m_jump;
    ///player jump speed
	float m_jumpSpeed;

private:
    ///Jump height target
	float m_jumpTarget;
    ///Current jump decay
	float m_jumpDecay;
};