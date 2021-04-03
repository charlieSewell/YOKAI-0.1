#include "StaticObject.hpp"

StaticObject::StaticObject(std::string modelName) 
{
    modelID = modelManager.GetModelID(modelName);

}

    
void StaticObject::draw(Shader &shader) 
{
    modelManager.DrawModel(modelID, shader);
}
