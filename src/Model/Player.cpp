//player.cpp

#pragma once

#include "Player.hpp"

Player::Player()
{
	m_movementSpeed = 0.2f;
	m_lookSensitivity = 0.05f;
	m_jumpHeight = 8.0f;
	m_jumpSpeed = 0.15f;
	m_mass = 0.125f;
	registerAllMovement(m_position, m_frontDirection, m_upDirection);
	
	registerAABB(&m_position, 4, 4, 4);
	m_resolvingCollision = false;
}

Player::~Player() {}

void Player::draw() {}

void Player::update()
{
	m_canJump = m_onGround;
	updatePhysics(m_colliderID, m_movementSpeed, m_jumpSpeed);
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
