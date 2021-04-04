//
// Created by Charlie on 12/01/2021.
//
#pragma once
#include <iostream>
#include <vector>

#include "View/Renderer/Shader.hpp"
#include "Model/Mesh.hpp"
#include <glm/glm.hpp>

class Model {
  public:
    Model(){};
    Model(std::vector<Mesh> meshes){
        this->meshes = meshes;
    }
    void Draw(Shader &shader, glm::vec3 position);


  private:
    std::vector<Mesh> meshes;

};

