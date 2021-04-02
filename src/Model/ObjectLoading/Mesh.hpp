//
// Created by Charlie Sewell on 12/01/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_MESH_HPP
#define ICT397_GAME_ENGINE_MESH_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "View/Renderer/DataTypes.hpp"
#include "View/Renderer/Shader.hpp"
#include "View/Renderer/Renderer.hpp"

class Mesh{
  public:
    Mesh(){}
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<ModelTexture> &textures,glm::mat4 &transform);
    std::vector<Vertex> getVertices(){return vertices;}
    std::vector<unsigned int> getIndices(){return indices;}
    std::vector<ModelTexture> getTextures(){return textures;}
    glm::mat4 getTransform(){return transform;}
    const void Draw(Shader &shader);
    void SetupMesh();
  private:
    std::shared_ptr<VertexArrayBuffer> VAO;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<ModelTexture> textures;
    glm::mat4 transform;


};
#endif // ICT397_GAME_ENGINE_MESH_HPP
