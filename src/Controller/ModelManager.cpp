//
// Created by Charlie Sewell on 23/02/2021.
//

#include "ModelManager.hpp"

ModelManager &ModelManager::getInstance() {
    static ModelManager instance;
    return instance;
}

ModelManager::ModelManager() {
    modelShader = new Shader("content/Shaders/vertexShader.vert", "content/Shaders/fragmentShader.frag");
    models.resize(100);
}
auto ModelManager::GetModelID(std::string filename) -> size_t {
    auto id = modelIDtoName.find(filename);
    //stops files being loaded more then once
    if(id == modelIDtoName.end()){
        models[modelCount] = Model(modelLoader.loadModel(filename));
        modelIDtoName.emplace(filename,modelCount);
        modelCount++;
        return modelCount-1;
    }
    return(id->second);
}
Model* ModelManager::GetModel(size_t modelID) {
    return &models[modelID];
}
void ModelManager::DrawModel(size_t id, glm::vec3 position) {
    models[id].Draw(*modelShader, position);
}
