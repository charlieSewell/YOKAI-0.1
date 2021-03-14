//Player.hpp

#pragma once

#include "../View/Camera.hpp"
#include "Entity.hpp"
#include "PlayerControlledMotion.hpp"

class Player : public Entity, public Camera, public PlayerControlledMotion
{
	using Camera::m_position;

public:
	Player();
	~Player();

};