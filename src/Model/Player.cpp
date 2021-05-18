#pragma once

#include "Player.hpp"

Player::Player()
{
    health            = 100;
    shields           = 100;
	m_movementSpeed = 0.075f;
	m_lookSensitivity = 0.05f;
	m_jumpHeight = 4.0f;
	m_jumpSpeed = 0.15f;
	m_mass = 0.025f;
	registerPosition();
	registerAllMovement(m_position, m_frontDirection, m_upDirection);
	registerPhysicsToggle();

	m_resolvingCollision = false;	
}

Player::~Player() {}

void Player::draw() {}

void Player::update()
{
	if(m_physicsActive)
	{
		m_canJump = m_onGround;
		updatePhysics(m_movementSpeed, m_jumpSpeed);
	}
	else
		m_canJump = true;
	
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

void Player::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}

void Player::registerPosition()
{
	auto getPlayerPosition = [&]()
	{
		return m_position;
	};

	EMS::getInstance().add(ReturnVec3Event::getPlayerPosition, getPlayerPosition);
}

void Player::setHealth(int h) 
{
    health = h;
}

int Player::getHealth() 
{
    return health;
}

void Player::setShields(int s) 
{
    shields = s;
}

int Player::getShields() 
{
    return shields;
}