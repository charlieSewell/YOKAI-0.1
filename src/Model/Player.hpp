//Player.hpp

#pragma once

#include "../View/Camera.hpp"
#include "GameObject.hpp"
#include "PlayerControlledMotion.hpp"
#include "../Controller/Factory/Asset.h"

class Player : public GameObject, public Camera, public PlayerControlledMotion, public Asset
{
	using Camera::m_position;

public:
	Player();
	~Player();
};