//PlayerControlledMotion.cpp

#include <iostream>
#include "PlayerControlledMotion.hpp"

void PlayerControlledMotion::setMovementSpeed(float movementSpeed)
{
	m_movementSpeed = movementSpeed;
}

float PlayerControlledMotion::getMovementSpeed() const
{
	return m_movementSpeed;
}

void PlayerControlledMotion::setJumpHeight(float jumpHeight)
{
	m_jumpHeight = jumpHeight;
}

void PlayerControlledMotion::registerAllMovement(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection)
{
	registerMoveForward(position, frontDirection);
	registerMoveBackward(position, frontDirection);
	registerMoveLeft(position, frontDirection, upDirection);
	registerMoveRight(position, frontDirection, upDirection);
	registerJump(position, upDirection);
	registerMoveDown(position, upDirection);
	registerXYLook(frontDirection);
}

void PlayerControlledMotion::registerMoveForward(glm::vec3& position, glm::vec3& frontDirection)
{
	auto moveForward = [&]()
	{
		position.x += m_movementSpeed * frontDirection.x; 
		position.z += m_movementSpeed * frontDirection.z;
	};
	EMS::getInstance().add(InputEvent::moveForward, moveForward);
};

void PlayerControlledMotion::registerMoveBackward(glm::vec3& position, glm::vec3& frontDirection)
{
	auto moveBackward = [&]()
	{
		position.x -= m_movementSpeed * frontDirection.x;
		position.z -= m_movementSpeed * frontDirection.z;
	};
	EMS::getInstance().add(InputEvent::moveBackward, moveBackward);
};

void PlayerControlledMotion::registerMoveLeft(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection)
{
	auto moveLeft = [&]() {position -= glm::normalize(glm::cross(frontDirection, upDirection)) * m_movementSpeed; };
	EMS::getInstance().add(InputEvent::moveLeft, moveLeft);
};

void PlayerControlledMotion::registerMoveRight(glm::vec3& position, glm::vec3& frontDirection, glm::vec3& upDirection)
{
	auto moveRight = [&]() {position += glm::normalize(glm::cross(frontDirection, upDirection)) * m_movementSpeed; };
	EMS::getInstance().add(InputEvent::moveRight, moveRight);
};

void PlayerControlledMotion::registerJump(glm::vec3& position, glm::vec3& upDirection)
{
	auto jump = [&]()
	{
		if(m_canJump)
		{
			m_jumpTarget = position.y + m_jumpHeight;
			m_jump = true;
			m_canJump = false;
		}
	};
	EMS::getInstance().add(InputEvent::jump, jump);
}

void PlayerControlledMotion::updateJump(glm::vec3& position, glm::vec3& upDirection)
{
	m_jumpDecay = (m_jumpTarget - position.y)*m_jumpSpeed;
	if(m_jump)
	{
		if(position.y < m_jumpTarget)
			position += (m_jumpSpeed + m_jumpDecay/3) * upDirection;
		else
			m_jump = false;
	}
}

void PlayerControlledMotion::registerMoveDown(glm::vec3& position, glm::vec3& upDirection)
{
	auto moveDown = [&]() {position -= m_movementSpeed * upDirection; };
	EMS::getInstance().add(InputEvent::moveDown, moveDown);
}

void PlayerControlledMotion::registerXYLook(glm::vec3& frontDirection)
{
	static double yaw = -90.0f;
	static double pitch = 0.0f;

	auto xyLook = [&](double xoffset, double yoffset) 
	{
		xoffset *= m_lookSensitivity;
		yoffset *= m_lookSensitivity;

		yaw += xoffset;
		pitch -= yoffset;

		// stops bad weird camera movement
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		frontDirection = glm::normalize(direction);
	};

	EMS::getInstance().add(InputEvent::xyLook, xyLook);
}