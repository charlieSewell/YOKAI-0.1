#include "NPC.hpp"

NPC::NPC(std::string modelName) {
    modelID = modelManager.GetModelID(modelName);
}

void NPC::draw(Shader &shader, glm::vec3 position) {
    modelManager.DrawModel(modelID, shader, position);
}
