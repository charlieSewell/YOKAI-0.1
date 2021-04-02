//Entity.hpp

#pragma once
#include <glm/glm.hpp>

enum class GameObjectType
{
	player
};

class GameObject
{
public:
	GameObject();
	virtual glm::vec3 getPosition() const;
	virtual void setPosition(glm::vec3 position);

	virtual void update();

protected:
	GameObjectType m_EntityType;
	glm::vec3 m_position;
};
