//
// Created by Charlie Sewell on 12/01/2021.
//

#ifndef ICT397_GAME_ENGINE_MESH_HPP
#define ICT397_GAME_ENGINE_MESH_HPP

#include <glm/glm.hpp>
#include <glad/glad.h>

#include <iostream>
#include <vector>
#include <string>
#include "Shader.hpp"
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoords;
    glm::vec3 tangent;
    glm::vec3 biTangent;
};
struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};
class Mesh{
  public:
    Mesh(){}
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<Texture> &textures);
    std::vector<Vertex> getVertices(){return vertices;}
    std::vector<unsigned int> getIndices(){return indices;}
    std::vector<Texture> getTextures(){return textures;}
    const void Draw(Shader &shader);
  private:
    unsigned int VAO, VBO, EBO;
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;

    void setupMesh();

};
#endif // ICT397_GAME_ENGINE_MESH_HPP
