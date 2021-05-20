#include "Pickup.hpp"

Pickup::Pickup(std::string modelName) 
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
    setPosition(glm::vec3(0, 0, 0));
    setScale(glm::vec3(0, 0, 0));
    setHealth(1);
    setShields(0);
    setAlive(true);
}

void Pickup::update() 
{

}

void Pickup::draw() 
{
    ModelManager::getInstance().DrawModel(modelID, m_transform);
}

void Pickup::setHealth(float h) 
{
    health = h;
}

float Pickup::getHealth() 
{
    return health;
}

void Pickup::setShields(float s) 
{
    shields = s;
}

float Pickup::getShields() 
{
    return shields;
}

void Pickup::setAlive(bool a) 
{
    isAlive = a;
}

bool Pickup::getAlive() 
{
    return isAlive;
}