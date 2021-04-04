//Entity.cpp

#include "GameObject.hpp"


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