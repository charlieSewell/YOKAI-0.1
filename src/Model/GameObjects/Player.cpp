#pragma once

#include "Player.hpp"

Player::Player()
	: PlayerControlledMotion(m_transform)//, PhysicsComponent(m_transform)
{
	m_movementSpeed = 0.075f;
	m_lookSensitivity = 0.05f;
	m_jumpHeight = 4.0f;
	m_jumpSpeed = 0.15f;
	//m_mass = 0.025f;
	registerPosition();
	registerAllMovement(m_frontDirection, m_upDirection);
	registerPhysicsToggle();

	m_resolvingCollision = false;
}

Player::~Player() {}

void Player::draw() {}

void Player::update()
{
	Camera::m_position = m_transform.getPosition();		//TODO: make this better
	/*if(m_physicsActive)
	{
		m_canJump = m_onGround;
		updatePhysics(m_movementSpeed, m_jumpSpeed);
	}
	else
		m_canJump = true;
	
	updateJump(m_transform.getPosition(), m_upDirection);
	*/
}

void Player::setCollider(float width, float length, float height)
{
	 //registerAABB(width, length, height);
}

void Player::registerPosition()
{
	auto getPlayerPosition = [&]()
	{
		return m_transform.getPosition();
	};

	EMS::getInstance().add(ReturnVec3Event::getPlayerPosition, getPlayerPosition);
}
