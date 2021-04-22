//
// Created by Charlie Sewell on 1/04/2021.
//

#pragma once
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glm/gtc/type_ptr.hpp>
#include "Model/Model.hpp"
#include "Model/Animation.hpp"
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
    Model loadModel(std::string filename);

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
    void processNode(Joint &rootJoint, std::vector<Animation> &animations, std::vector<Mesh> &meshes,
                     std::vector<Bone> &bones,
                     std::map<std::string, unsigned int> &boneMap, aiNode *node,
                     const aiScene *scene, glm::mat4 transform);
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
    void loadJoints(Joint &rootJoint, aiMesh *mesh, aiNode *root);
    void addBoneData(unsigned int BoneID, float Weight);
    void loadAnimations(std::vector<Animation> &animations, const aiScene *scene);
    void loadBones(std::vector<Mesh> &meshes, std::vector<Bone> &bones,std::map<std::string,unsigned int> &boneMap, unsigned int meshIndex, const aiMesh *mesh);
    ///List of textures currently loaded for a model
    std::vector<ModelTexture> textures_loaded;
    /// Number of bones in current model
    int numBones = 0;
};
