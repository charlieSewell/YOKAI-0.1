#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName) 
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}
    
void StaticObject::draw(Shader &shader)
{
    ModelManager::getInstance().DrawModel(modelID, shader, m_position);
}


glm::mat4 StaticObject::getViewMatrix()
{
	return one;
}

glm::vec3 StaticObject::getPosition()
{
    return two;
}

void StaticObject::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}

