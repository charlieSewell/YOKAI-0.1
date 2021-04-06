//PlayerControlledMotion.hpp - Abstract class
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Controller/EventManager.hpp"

class PlayerControlledMotion
{
public:
	void setMovementSpeed(float movementSpeed);
	float getMovementSpeed() const;
	void setJumpHeight(float jumpHeight);;

protected:
	PlayerControlledMotion() {}
	virtual ~PlayerControlledMotion() {}

	void registerAllMovement(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);

	void registerMoveForward(glm::vec3& position, glm::vec3& frontDirection);
	void registerMoveBackward(glm::vec3& position, glm::vec3& frontDirection);
	void registerMoveLeft(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
	void registerMoveRight(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
	void registerJump(glm::vec3& position, glm::vec3& upDirection);
	void registerMoveDown(glm::vec3& position, glm::vec3& upDirection);
	void registerXYLook(glm::vec3& frontDirection);

	void updateJump(glm::vec3& position, glm::vec3& upDirection);

	float m_movementSpeed;
	float m_lookSensitivity;
	float m_jumpHeight;
	bool m_canJump;
	bool m_jump;
	float m_jumpSpeed;

private:
	float m_jumpTarget;
	float m_jumpDecay;
};