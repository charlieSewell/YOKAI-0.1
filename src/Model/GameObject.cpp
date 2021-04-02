//Entity.cpp

#include "GameObject.hpp"

GameObject::GameObject()
	: m_position(glm::vec3(0.0f, 0.0f, 0.0f))
{

}

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