#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName) 
{
    modelID = modelManager.GetModelID(modelName);

}
    
void StaticObject::draw(Shader &shader, glm::vec3 position) {
    modelManager.DrawModel(modelID, shader, position);
}
