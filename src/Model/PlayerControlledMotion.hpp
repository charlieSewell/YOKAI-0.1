//PlayerControlledMotion.hpp - Abstract class
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Controller/EventManager.h"

class PlayerControlledMotion
{
	void setMovementSpeed(float movementSpeed);
	float getMovementSpeed() const;

protected:
	PlayerControlledMotion() {}
	virtual ~PlayerControlledMotion() {}

	void registerAllMovement(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);

	void registerMoveForward(glm::vec3& position, glm::vec3& frontDirection);
	void registerMoveBackward(glm::vec3& position, glm::vec3& frontDirection);
	void registerMoveLeft(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
	void registerMoveRight(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection);
	void registerMoveUp(glm::vec3& position, glm::vec3& upDirection);
	void registerMoveDown(glm::vec3& position, glm::vec3& upDirection);

	float m_movementSpeed;
};