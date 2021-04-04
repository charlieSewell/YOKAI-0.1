//player.cpp

#pragma once

#include "Player.hpp"

Player::Player()
{
	m_movementSpeed = 0.15f;
	m_lookSensitivity = 0.05f;
	m_jumpHeight = 8.0f;
	m_gravityValue = 0.125f;
	registerAllMovement(m_position, m_frontDirection, m_upDirection);
	
	registerBoundingSphere(&m_position, 1.0);
}

Player::~Player() {}

void Player::draw(Shader &shader) {}

glm::mat4 Player::getViewMatrix() 
{
    return Camera::getViewMatrix();
}

void Player::update()
{
	m_canJump = m_onGround;
	updatePhysics(&m_position, m_movementSpeed);
	updateJump(m_position, m_upDirection);
}

glm::vec3 Player::getPosition() const
{
	return m_position;
}

void Player::setPosition(glm::vec3 position)
{
	m_position = position;
}