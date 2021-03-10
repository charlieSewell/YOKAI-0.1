//
// Created by charl on 4/03/2021.
//

#include "Chunk.hpp"

#include "View/Renderer/OpenGL/OpenGLRenderer.hpp"
Chunk::Chunk(){

}
void Chunk::SetupChunk(const std::vector<Vertex>& vertices, const std::vector<unsigned int> &indices) {
    VAO = VertexArrayBuffer::Create(vertices,indices);
    indicesSize = indices.size();
}
void Chunk::DrawChunk(Shader &shader) {
    shader.useShader();
    Renderer::Draw(*VAO,indicesSize);
}