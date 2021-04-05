#include "NPC.hpp"

NPC::NPC(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);

	registerAABB(&m_position, 5, 5, 40);
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