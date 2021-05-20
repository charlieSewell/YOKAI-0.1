#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}

void StaticObject::draw()
{
    ModelManager::getInstance().DrawModel(modelID, m_transform.getMatrix());
}
