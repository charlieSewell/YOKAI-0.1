//Entity.hpp

#pragma once
#include <glm/glm.hpp>

enum class EntityType
{
	player
};

class Entity
{
public:
	glm::vec3 getPosition() const;

	virtual void update();

protected:
	EntityType m_EntityType;
	glm::vec3 m_position;
};
