//Entity.hpp

#pragma once
#include <glm/glm.hpp>

#include "View/Renderer/Shader.hpp"
#include "Controller/LuaManager.hpp"
enum class GameObjectType
{
	player, staticObject, npc
};

class GameObject
{
public:
    static void registerClass();
    virtual glm::vec3 getPosition() const;
	virtual void setPosition(glm::vec3 position);

	virtual void setCollider(float width, float length, float height) = 0;

	virtual void update();
    virtual void draw() = 0;

protected:
	GameObjectType m_EntityType;
	glm::vec3 m_position;
};
