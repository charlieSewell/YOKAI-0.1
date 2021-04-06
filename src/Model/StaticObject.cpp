#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}

void StaticObject::draw()
{
    ModelManager::getInstance().DrawModel(modelID,m_transform);
}

glm::vec3 StaticObject::getPosition()
{
    return two;
}

void StaticObject::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}
