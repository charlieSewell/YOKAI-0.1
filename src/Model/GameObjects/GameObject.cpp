//GameObject.cpp

#include "GameObject.hpp"
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject()
	: m_transform()
{

}

Transform GameObject::getTransform()
{
    return m_transform;
}

void GameObject::setTransform(Transform transform) 
{
    m_transform = transform;
}

glm::vec3 GameObject::getLuaPosition()
{
	return m_transform.getPosition();
}

void GameObject::setLuaPosition(float x,float y,float z)
{
	m_transform.setPosition(x, y, z);
}

void GameObject::setLuaScale(float x,float y,float z)
{
    m_transform.setScale(x, y, z);
}
void GameObject::update(float dt)
{

}

void GameObject::registerClass() 
{
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginClass<GameObject>("GameObject")
            .addFunction("update", &GameObject::update)
            .addFunction("getPosition", &GameObject::getLuaPosition)
            .addFunction("setPosition", &GameObject::setLuaPosition)
            .addFunction("setScale", &GameObject::setLuaScale)
            .addFunction("setCollider",&GameObject::setCollider)
        .endClass();
}