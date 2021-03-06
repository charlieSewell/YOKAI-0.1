//
// Created by Charlie Sewell on 12/01/2021.
//
#include "Mesh.hpp"
Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<Texture> &textures, glm::mat4 &transform){
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    this->transform = transform;
}
void Mesh::SetupMesh(){
    Yokai::getInstance().renderer.SetupMesh(VAO,VBO,EBO,this->vertices,this->indices);
}
 const void Mesh::Draw(Shader &shader){
     Yokai::getInstance().renderer.DrawModel(shader,VAO, this->textures, this->indices);
}