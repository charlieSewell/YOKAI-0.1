#pragma once

#include "Player.hpp"

Player::Player()
	: m_camera(Camera()), m_movement(PlayerControlledMotion(m_transform)), m_physics(m_transform)
{
	m_movement.movementSpeed = 0.075f;
	m_movement.lookSensitivity = 0.05f;
	m_movement.jumpHeight = 4.0f;
	m_movement.jumpSpeed = 0.15f;
	//m_mass = 0.025f;
	registerPosition();
	m_movement.registerAllMovement(m_camera.m_frontDirection, m_camera.m_upDirection);
	m_physics.registerPhysicsToggle();

}

Player::~Player() {}

void Player::draw() {}
void Player::update()
{
	m_camera.m_position = m_transform.getPosition();		//TODO: make this better
	if(m_physics.m_physicsActive) {
        m_physics.updatePhysics(m_movement.movementSpeed, m_movement.jumpSpeed);
    }
}

void Player::setCollider(float width, float length, float height)
{
    m_physics.registerSphere(4);
}

void Player::registerPosition()
{
	auto getPlayerPosition = [&]()
	{
		return m_transform.getPosition();
	};

	EMS::getInstance().add(ReturnVec3Event::getPlayerPosition, getPlayerPosition);
}
