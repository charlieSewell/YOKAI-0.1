#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName)
: m_physics(m_transform)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);

}

void StaticObject::draw()
{
    ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix());
}

void StaticObject::setCollider(float width, float length, float height)
{
	m_physics.registerAABB(width, length, height);

}
