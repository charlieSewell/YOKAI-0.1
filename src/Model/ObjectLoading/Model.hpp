//
// Created by Charlie on 12/01/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_MODEL_HPP
#define ICT397_GAME_ENGINE_MODEL_HPP

#include <iostream>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "View/Renderer/OpenGL.hpp"
#include "Model/ObjectLoading/Mesh.hpp"
#include "View/Renderer/AssimpMaths.hpp"
class Model {
  public:
    Model(const char *filename){
        loadModel(filename);
    }
    void Draw(Shader &shader);
    std::vector<Texture> textures_loaded;

  private:
    std::vector<Mesh> meshes;

    std::string directory;
    void loadModel(std::string filename);
    void processNode(aiNode *node, const aiScene *scene,glm::mat4 transform);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene,glm::mat4 transform);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

#endif // ICT397_GAME_ENGINE_MODEL_HPP
