//player.cpp

#pragma once

#include "Player.hpp"

Player::Player()
{
	m_movementSpeed = 0.15f;
	m_lookSensitivity = 0.05f;
	registerAllMovement(m_position, m_frontDirection, m_upDirection);
}

Player::~Player() {}

void Player::draw(Shader &shader) {}

glm::mat4 Player::getViewMatrix() 
{
    return Camera::getViewMatrix();
};

glm::vec3 Player::getPosition() 
{
    return m_position;
};
