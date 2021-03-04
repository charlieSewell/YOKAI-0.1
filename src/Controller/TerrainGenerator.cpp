//
// Created by charl on 4/03/2021.
//

#include "TerrainGenerator.hpp"
void TerrainGenerator::SetupChunk(Chunk &chunk,int size) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    GenerateFlatMap(vertices,size,size);
    GenerateTerrainIndices(indices,size,size);
    GenerateTexCoords(vertices,size,size);
    chunk.SetupChunk(vertices,indices);
}
void TerrainGenerator::GenerateFlatMap(std::vector<Vertex> &terrain, int xSize, int zSize) {
    Vertex vertex;
    for (unsigned x = 0; x < xSize; x ++) {
        for (unsigned z = 0 ; z < zSize; z ++) {
            vertex.position.x = x;
            vertex.position.z = z;
            terrain.push_back(vertex);
            vertex = {};
        }
    }
}
void TerrainGenerator::GenerateTerrainIndices(std::vector<unsigned int> &terrain, int xSize, int zSize) {
    for(int x =0; x < xSize-1; x++){
        for(int z =0; z < zSize-1; z++){
            int pos = x * xSize + z;
            terrain.push_back(pos);             //0
            terrain.push_back(pos + 1);         //1
            terrain.push_back(pos + xSize);     //2
            terrain.push_back(pos + 1);         //1
            terrain.push_back(pos + 1 + xSize); //3
            terrain.push_back(pos + xSize);     //2

        }
    }
}
void TerrainGenerator::GenerateTexCoords(std::vector<Vertex> &terrain, int xSize, int zSize) {
    for(auto& vert: terrain){
        vert.textureCoords = glm::vec2((float)vert.position.x/xSize,(float)vert.position.z/xSize);
    }
}