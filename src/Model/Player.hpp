//Player.hpp

#pragma once

#include "../View/Camera.hpp"
#include "GameObject.hpp"
#include "PlayerControlledMotion.hpp"

class Player : public GameObject, public Camera, public PlayerControlledMotion
{
	using Camera::m_position;

public:
	Player();
	~Player();

};