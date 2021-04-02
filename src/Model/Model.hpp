//
// Created by Charlie on 12/01/2021.
//
#pragma once
#include <iostream>
#include <vector>

#    include "View/Renderer/Shader.hpp"
#include "Model/Mesh.hpp"
class Model {
  public:
    Model(){};
    Model(std::vector<Mesh> meshes){
        this->meshes = meshes;
    }
    void Draw(Shader &shader);


  private:
    std::vector<Mesh> meshes;


};

