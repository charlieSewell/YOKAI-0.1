//
// Created by charl on 4/03/2021.
//

#include "Chunk.hpp"
#include "View/Renderer/OpenGL.hpp"
Chunk::Chunk(){

}
void Chunk::SetupChunk(const std::vector<Vertex>& vertices, const std::vector<unsigned int> &indices) {
    OpenGL::SetupTerrainMesh(VAO, VBO, EBO, vertices, indices);
    EBO_Size = indices.size();
}
void Chunk::DrawChunk(Shader &shader) {
    OpenGL::DrawChunk(shader,VAO, textures, EBO_Size);
}