//
// Created by Charlie Sewell on 1/04/2021.
//

#pragma once
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glm/gtc/type_ptr.hpp>

#include "Model/Mesh.hpp"
#include "View/Renderer/AssimpMaths.hpp"

class ModelLoader {
  public:
    std::vector<Mesh> loadModel(std::string filename);
  private:
    std::string directory;
    void processNode(std::vector<Mesh> &meshes,aiNode *node, const aiScene *scene,glm::mat4 transform);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene,glm::mat4 transform);
    std::vector<ModelTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    std::vector<ModelTexture> textures_loaded;
};
