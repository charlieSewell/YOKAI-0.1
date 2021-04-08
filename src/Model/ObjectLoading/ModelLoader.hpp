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
/** @class ModelLoader
 *  @brief Class that loads models
 */
class ModelLoader 
{
  public:
    /**
     * @brief Loads a model and returns a vector of meshes
     * @param string - filename
     * @return vector<Mesh>
     */
    std::vector<Mesh> loadModel(std::string filename);

  private:
    ///string that stores the directory
    std::string directory;
    /**
     * @brief processes and indivudial node in the scene
     * @param vector<Mesh> - meshes
     * @param aiNode* - node
     * @param const aiScene* - scene
     * @param mat4 - transform
     */
    void processNode(std::vector<Mesh> &meshes,aiNode *node, const aiScene *scene,glm::mat4 transform);
    /**
     * @brief Processes a singular mesh of a model
     * @param aiMesh* - mesh
     * @param const aiScene* - scene
     * @param mat4 - transform
     * @return Mesh
     */
    Mesh processMesh(aiMesh *mesh, const aiScene *scene,glm::mat4 transform);
    /**
     * @brief Loads the Textures for a model
     * @param aiMaterial* - mat
     * @param aiTextureType - type
     * @param string - typeName
     * @return vector<ModelTexture>
     */
    std::vector<ModelTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    ///List of textures currently loaded for a model
    std::vector<ModelTexture> textures_loaded;
};
