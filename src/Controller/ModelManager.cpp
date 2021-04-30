//
// Created by Charlie Sewell on 23/02/2021.
//

#include "ModelManager.hpp"

ModelManager &ModelManager::getInstance() 
{
    static ModelManager instance;
    return instance;
}

ModelManager::ModelManager() 
{
    modelShader = new Shader("content/Shaders/vertexShader.vert", "content/Shaders/fragmentShader.frag");
    models.resize(100);
}

auto ModelManager::GetModelID(std::string filename) -> size_t 
{
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

void ModelManager::loadAnimation(std::string filename)
{
	animatedModel = modelLoader.loadAnimatedModel(filename);
}

Model* ModelManager::GetModel(size_t modelID) 
{

    return &models[modelID];
}

void ModelManager::DrawModel(size_t id, glm::mat4 transform) 
{
    models[id].Draw(*modelShader, transform);
}

void ModelManager::DrawAnimatedModel(glm::mat4 transform, bool isWalking)
{
	if(frameCount == animatedModel.size())
		frameCount = 0;


	//dirty way of halving the framerate
	animatedModel[frameCount].Draw(*modelShader, transform);

	if(update && !(!isWalking && (frameCount == 30 || frameCount == 10)))
	{
		++frameCount;
		update = false;
	}
	else
		update = true;
}
