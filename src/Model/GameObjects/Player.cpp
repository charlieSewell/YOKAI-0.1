#pragma once

#include "Player.hpp"

Player::Player()
	: m_camera(Camera()), m_movement(PlayerControlledMotion(m_transform))//, PhysicsComponent(m_transform)
{
	m_movement.movementSpeed = 0.075f;
	m_movement.lookSensitivity = 0.05f;
	m_movement.jumpHeight = 4.0f;
	m_movement.jumpSpeed = 0.15f;
	//m_mass = 0.025f;
	registerPosition();
	m_movement.registerAllMovement(m_camera.m_frontDirection, m_camera.m_upDirection);
	m_physics.registerPhysicsToggle();

	m_physics.m_resolvingCollision = false;


	PhysicsManager::getInstance().addCapsule(m_transform);
	PhysicsManager::getInstance().addTerrain();
}

Player::~Player() {}

void Player::draw() {}

void Player::update(float dt)
{
	m_camera.m_position = m_transform.getPosition();		//TODO: make this better
	PhysicsManager::getInstance().update(m_transform);
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
