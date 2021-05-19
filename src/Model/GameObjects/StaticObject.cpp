#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}

void StaticObject::draw()
{
    ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix());
}

void StaticObject::setCollider(float width, float length, float height)
{
	//PhysicsManager::getInstance().addCapsule(m_transform);
	//registerAABB(width, length, height);
}
