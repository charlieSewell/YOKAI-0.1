//PlayerControlledMotion.hpp - Abstract class
#pragma once

#include "Model/Components/Transform.hpp"
#include "Controller/EventManager.hpp"
#include "Controller/LuaManager.hpp"

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
	void setMovementSpeed(float newMovementSpeed);
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

//protected:
  /**
   * @brief Constructor for Player Controlled Motion
   */
	PlayerControlledMotion() {}

	/**
	* @brief Constructor for Player Controlled Motion
	* @param vec3* - positionPtr
	*/
	PlayerControlledMotion(Transform &transform);
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
	void registerAllMovement(glm::vec3& frontDirection, glm::vec3& upDirection);
    /**
     * @brief Registers Forwared movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     */
	void registerMoveForward(glm::vec3& frontDirection);
    /**
     * @brief Registers Backwards movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     */
	void registerMoveBackward(glm::vec3& frontDirection);
    /**
     * @brief Registers Left movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     * @param vec3& - upDirection
     */
	void registerMoveLeft(glm::vec3& frontDirection, glm::vec3& upDirection);
    /**
     * @brief Registers Right movement with EMS
     * @param vec3& - position
     * @param vec3& - frontDirection
     * @param vec3& - upDirection
     */
	void registerMoveRight(glm::vec3& frontDirection, glm::vec3& upDirection);
	/**
	 * @brief Registers jump with EMS
	 * @param vec3& - position
	 * @param vec3& - upDirection
	 */
    void registerJump();
    /**
     * @brief Registers downward movement with EMS
     * @param vec3& - position
     * @param vec3& - upDirection
     */
	void registerMoveDown(glm::vec3& upDirection);
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

	static void registerClass();

	void updateJump(glm::vec3 position, glm::vec3& upDirection);
    ///Movement speed
	float movementSpeed;
    ///Mouse sensitivity
	float lookSensitivity;
    ///Jump Height
	float jumpHeight;
    ///bool to check if player can jump
	bool canJump;
    ///bool to say whether player is in jump
	bool jumping = false;
    ///player jump speed
	float jumpSpeed;

private:
    ///Jump height target
	float m_jumpTarget;
    ///Current jump decay
	float m_jumpDecay;

	Transform* m_transformPtr;
};
