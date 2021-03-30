//
// Created by charl on 4/03/2021.
//

#include "Chunk.hpp"

#include "View/Renderer/OpenGL/OpenGLRenderer.hpp"
Chunk::Chunk(){

}
void Chunk::SetupChunk(const std::vector<Vertex>& vertices, const std::vector<unsigned int> &indices) {
    VAO = VertexArrayBuffer::Create(vertices,indices);
    textures.push_back(Texture::Create("content/Textures/grass.jpg"));
    textures.push_back(Texture::Create("content/Textures/sand.jpg"));
    textures.push_back(Texture::Create("content/Textures/snow.jpg"));
    textures.push_back(Texture::Create("content/Textures/detail.jpg"));
    indicesSize = indices.size();
}
void Chunk::DrawChunk(Shader &shader) {

    shader.useShader();
    shader.setInt("grassTexture",0);
    shader.setInt("sandTexture",1);
    shader.setInt("snowTexture",2);
    shader.setInt("detailMap",3);

    shader.setFloat("sandHeight",10);
    shader.setFloat("grassHeight",20);
    shader.setFloat("snowHeight",100);


    textures[0]->Bind(0);
    textures[1]->Bind(1);
    textures[2]->Bind(2);
    textures[3]->Bind(3);
    Renderer::Draw(*VAO,indicesSize);
}