//
// Created by Charlie on 12/01/2021.
//
#ifndef ICT397_GAME_ENGINE_MODEL_HPP
#define ICT397_GAME_ENGINE_MODEL_HPP

#include <iostream>
#include <Vector>

#include <glad/glad.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.hpp"
#include "Shader.hpp"

class Model {
  public:
    Model(char *filename){
        loadModel(filename);
    }
    void Draw(Shader &shader);
  private:
    std::vector<Mesh> meshes;
    std::vector<Texture> textures_loaded;

    std::string directory;
    void loadModel(std::string filename);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

#endif // ICT397_GAME_ENGINE_MODEL_HPP
