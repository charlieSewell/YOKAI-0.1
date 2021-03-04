//
// Created by charl on 4/03/2021.
//

#include "TerrainGenerator.hpp"
void TerrainGenerator::SetupChunk(Chunk &chunk,int size) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    GenerateFlatMap(vertices,size,size);
    GenerateTerrainIndices(indices,size,size);
    //TODO: Come Up with better solution as currently just stretching over terrain
    GenerateTexCoords(vertices,size,size);
    GeneratePerlinMap(size,size);
    //TODO: Abstract into another function
    int x =0;
    int y=0;
    for(auto& vert: vertices){
        if(vert.position.x != x){
            x ++;
            y=0;
        }
        vert.position.y = heightVals.at(x).at(y);
        y++;
    }
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
void TerrainGenerator::GeneratePerlinMap(int xSize,int ySize) {
    heightVals.resize(static_cast<size_t>(xSize));
    for (auto &e : heightVals) {
        e.resize(static_cast<size_t>(ySize));
    }
    float xFactor = 1.0f / (xSize - 1);
    float yFactor = 1.0f / (ySize - 1);
    float a       = 10; //Tuning variables
    float b       = 3;  //Tuning variables

    for( int row = 0; row < ySize; row++ ) {
        for( int col = 0 ; col < xSize; col++ ) {
            float x = xFactor * col;
            float y = yFactor * row;
            float sum = 0.0f;
            float freq = a;
            float scale = b;

            // Compute the sum for each octave
            for( int oct = 0; oct < 1; oct++ ) {
                glm::vec2 p(x * freq, y * freq);
                float val = glm::perlin(p) / scale;
                sum += val;
                float result = (sum + 1.0f)/ 2.0f;

                // Store in Vector of Vectors
                 heightVals.at(static_cast<size_t>(row)).at(static_cast<size_t>(col)) = result * 30.0f;

                freq *= 2.0f;   // Double the frequency
                scale *= b;     // Next power of b
            }
        }
    }
}