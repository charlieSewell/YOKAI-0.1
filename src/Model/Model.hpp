//
// Created by Charlie on 12/01/2021.
//
#pragma once
#include <iostream>
#include <vector>

#include "View/Renderer/Shader.hpp"
#include "Model/Mesh.hpp"
#include <glm/glm.hpp>
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
     * @param Joint - rootJoint
     */
    Model(std::vector<Mesh> meshes,std::vector<Bone> bones,Joint rootJoint);
    /**
     * @brief Draws a mesh
     * @param Shader& - shader
     * @param mat4 - transform
     */
    void Draw(Shader &shader, glm::mat4 transform);

  private:
    ///list of models meshes
    std::vector<Mesh> meshes;
    ///map of bone names to index
    std::map<std::string, unsigned int> boneMap;
    ///list of models bones
    std::vector<Bone> bones;
    ///Root joint
    Joint rootJoint;
};

