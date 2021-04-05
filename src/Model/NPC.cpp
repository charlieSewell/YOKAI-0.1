#include "NPC.hpp"

NPC::NPC(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);
}

void NPC::draw() {
    ModelManager::getInstance().DrawModel(modelID, m_position);
}

glm::mat4 NPC::getViewMatrix() {
    return one;
}

glm::vec3 NPC::getPosition() {
    return two;
}

void NPC::setCollider(float width, float length, float height)
{
	registerAABB(&m_position, width, length, height);
}