//
// Created by Charlie on 12/01/2021.
//
#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "View/Renderer/Shader.hpp"
#include "Model/Mesh.hpp"
#include "Model/Animation.hpp"

/**
 * @struct Joint
 * @brief Struct to hold info about a joint
 */
struct Joint
{
    ///Transform of a joint
    glm::mat4 transform = {};
    ///Name of a joint
    std::string name;
    ///Children of that joint
    std::vector<Joint> children = {};
    ///Count of children
    int childrenCount;
};
/**
 * @struct Bone
 * @brief Struct to hold info about a bone
 */
struct Bone
{
    ///Bones offset from position of model
    glm::mat4 offset = glm::mat4(1.0f);
    ///Transform of the bone
    glm::mat4 transform = glm::mat4(1.0f);
};
/**
 * @class Model
 * @brief A class to hold model Data
 */
class Model
{
  public:
    /**
     * @brief Default constructor for a model
     */
    Model(){};
    /**
     * @brief Constructor for a model that takes in a list of meshes
     * @param vector<Mesh> - meshes
     */
    Model(std::vector<Mesh> meshes);
    /**
     * @brief Constructor for a model that is animated
     * @param vector<Mesh> - meshes
     * @param vector<Bone> - bones
     * @param map<string,unsigned int> - boneMap
     * @param Joint - rootJoint
     * @param vector<Animation> - animations
     */
    Model(std::vector<Mesh> meshes,std::vector<Bone> bones,std::map<std::string, unsigned int> boneMap,Joint rootJoint, std::vector<Animation> animations,glm::mat4 globalInverseTransform);
    /**
     * @brief Draws a mesh
     * @param Shader& - shader
     * @param mat4 - transform
     */
    void Draw(Shader &shader, glm::mat4 transform);
    Animation* getAnimation(std::string name);
    int getBonesSize(){return bones.size();}
    Joint getRootJoint();
    std::map<std::string, unsigned int>* getBoneMap(){return &boneMap;}
    std::vector<Bone>* getBones(){return &bones;}
    glm::mat4 getGlobalInverseTransform(){return globalInverseTransform;}
    ///list of models bones
    std::vector<Bone> bones;
    ///map of bone names to index
    std::map<std::string, unsigned int> boneMap;
  private:
    ///Global transform
    glm::mat4 globalInverseTransform;
    ///list of models meshes
    std::vector<Mesh> meshes;

    
    
    ///Root joint
    Joint rootJoint;
    ///Animations
    std::vector<Animation> animations;
};

