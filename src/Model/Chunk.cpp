//
// Created by charl on 4/03/2021.
//

#include "Chunk.hpp"

#include "View/Renderer/OpenGL/OpenGLRenderer.hpp"
Chunk::Chunk(std::shared_ptr<Texture> &grass, std::shared_ptr<Texture> &sand, std::shared_ptr<Texture> &snow, std::shared_ptr<Texture> &detail,int sandHeight,int grassHeight,int snowHeight){
    textures.push_back(grass);
    textures.push_back(sand);
    textures.push_back(snow);
    textures.push_back(detail);
    this->grassHeight = grassHeight;
    this->sandHeight = sandHeight;
    this->snowHeight = snowHeight;
}
void Chunk::SetupChunk(const std::vector<Vertex>& vertices, const std::vector<unsigned int> &indices) {
    VAO = VertexArrayBuffer::Create(vertices,indices);
    indicesSize = indices.size();
}
void Chunk::DrawChunk(Shader &shader) {

    shader.useShader();
    shader.setInt("grassTexture",0);
    shader.setInt("sandTexture",1);
    shader.setInt("snowTexture",2);
    shader.setInt("detailMap",3);

    shader.setFloat("sandHeight",sandHeight);
    shader.setFloat("grassHeight",grassHeight);
    shader.setFloat("snowHeight",snowHeight);


    textures[0]->Bind(0);
    textures[1]->Bind(1);
    textures[2]->Bind(2);
    textures[3]->Bind(3);
    Renderer::Draw(shader,*VAO,indicesSize);
}