//Entity.hpp

#pragma once
#include <glm/glm.hpp>

#include "View/Renderer/Shader.hpp"

enum class GameObjectType
{
	player, staticObject
};

class GameObject
{
public:
	glm::vec3 getPosition() const;

	virtual void update();
    //virtual void draw(Shader shader); 

protected:
	GameObjectType m_EntityType;
	glm::vec3 m_position;
};
