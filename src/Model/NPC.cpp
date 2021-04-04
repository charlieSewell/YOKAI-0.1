#include "NPC.hpp"

NPC::NPC(std::string modelName)
{
    modelID = ModelManager::getInstance().GetModelID(modelName);

	registerAABB(&m_position, 3, 3, 20);
}

void NPC::draw(Shader &shader) {
    ModelManager::getInstance().DrawModel(modelID, shader, m_position);
}

glm::mat4 NPC::getViewMatrix() {
    return one;
}

glm::vec3 NPC::getPosition() {
    return two;
}