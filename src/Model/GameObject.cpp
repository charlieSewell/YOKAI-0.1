//Entity.cpp

#include "GameObject.hpp"
#include <LuaBridge/LuaBridge.h>

glm::vec3 GameObject::getPosition() const
{
	return m_position;

}

void GameObject::setPosition(glm::vec3 position)
{
	m_position = position;
}


void GameObject::update()
{

}
void GameObject::registerClass() {
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
        .beginClass<GameObject>("GameObject")
            .addFunction("update", &GameObject::update)
            .addFunction("getposition", &GameObject::getPosition)
            .addFunction("setPosition", &GameObject::setPosition)
        .endClass();
}