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
     * @param meshes
     */
    Model(std::vector<Mesh> meshes)
    {
        this->meshes = meshes;
    }
    /**
     * @brief Draws a mesh
     * @param Shader& - shader
     * @param mat4 - transform
     */
    void Draw(Shader &shader, glm::mat4 transform);

  private:
    ///list of models meshes
    std::vector<Mesh> meshes;
};

