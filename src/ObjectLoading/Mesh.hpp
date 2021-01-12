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
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoords;
};
struct Texture {
    unsigned int id;
    std::string type;
};
class Mesh{
  public:
    Mesh(){}
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    std::vector<Vertex> getVertices(){return vertices;}
    std::vector<unsigned int> getIndices(){return indices;}
    std::vector<Texture> getTextures(){return textures;}
    void Draw();
  private:
    unsigned int VAO, VBO, EBO;
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;

    void setupMesh();

};
#endif // ICT397_GAME_ENGINE_MESH_HPP
