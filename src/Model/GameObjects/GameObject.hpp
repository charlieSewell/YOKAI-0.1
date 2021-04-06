//GameObject.hpp

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
    virtual glm::mat4 getTransform() const;
	virtual void setPosition(glm::vec3 position);
    virtual void setLuaPosition(float x,float y,float z);
    virtual void setLuaScale(float x,float y,float z);
    virtual void setScale(glm::vec3 scale);
	virtual void setCollider(float width, float length, float height) = 0;
	virtual void update();
    virtual void draw() = 0;

protected:
	GameObjectType m_EntityType;
	glm::vec3 m_scale;
    glm::vec3 m_position;
    glm::mat4 m_transform;
};
