//Player.hpp

#pragma once

#include "../View/Camera.hpp"
#include "GameObject.hpp"
#include "PlayerControlledMotion.hpp"

class Player : public Camera, public PlayerControlledMotion //,public GameObject
{
	using Camera::m_position;

public:
	Player();
	~Player();
    void draw(Shader shader);
};