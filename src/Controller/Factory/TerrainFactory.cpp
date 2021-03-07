//
// Created by Charlie Sewell on 4/03/2021.
//

#include "TerrainFactory.hpp"
TerrainFactory &TerrainFactory::getInstance() {
    static TerrainFactory instance;
    return instance;
}
void TerrainFactory::Init(){
    this->terrainSize = 300;
    GeneratePerlinMap(terrainSize,terrainSize);

}
void TerrainFactory::SetupChunk(Chunk &chunk,unsigned int xStart,unsigned int zStart,int size) {
    size+=1;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    GenerateFlatMap(vertices,xStart,zStart,size,size);
    GenerateTerrainIndices(indices,size,size);
    //TODO: Come Up with better solution as currently just stretching over terrain
    GenerateTexCoords(vertices,size,size);

    //TODO: Abstract into another function
    int x =xStart;
    int z=zStart;
    for(auto& vert: vertices){
        if(vert.position.x != x){
            x ++;
            z=zStart;
        }
        vert.position.y = heightVals.at(x).at(z);
        z++;
    }
    chunk.SetupChunk(vertices,indices);
}
void TerrainFactory::GenerateFlatMap(std::vector<Vertex> &terrain,unsigned int xStart,unsigned int zStart, int xSize, int zSize) {
    Vertex vertex;
    for (unsigned x = xStart; x < xSize+xStart; x ++) {
        for (unsigned z = zStart ; z < zSize+zStart; z ++) {
            vertex.position.x = x;
            vertex.position.z = z;
            terrain.push_back(vertex);
            vertex = {};
        }
    }
}
void TerrainFactory::GenerateTerrainIndices(std::vector<unsigned int> &terrain, int xSize, int zSize) {
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
void TerrainFactory::GenerateTexCoords(std::vector<Vertex> &terrain, int xSize, int zSize) {
    for(auto& vert: terrain){
        vert.textureCoords = glm::vec2((float)vert.position.x/xSize,(float)vert.position.z/xSize);
    }
}
void TerrainFactory::GeneratePerlinMap(int xSize,int ySize) {
    heightVals.resize(static_cast<size_t>(xSize));
    for (auto &e : heightVals) {
        e.resize(static_cast<size_t>(ySize));
    }
    float xFactor = 1.0f / (150 - 1);
    float yFactor = 1.0f / (150 - 1);
    float a       = 1.7; //Tuning variables
    float b       = 0.6;  //Tuning variables

    for( int row = 0; row < ySize; row++ ) {
        for( int col = 0 ; col < xSize; col++ ) {
            float x = xFactor * col;
            float y = yFactor * row;
            float sum = 0.0f;
            float freq = a;
            float scale = b;
            float result =0.0f;
            // Compute the sum for each octave
            for( int oct = 1; oct <= 4; oct++ ) {
                glm::vec2 p(x * freq, y * freq);
                float val = glm::simplex(p) * 1/oct;
                sum += val;     // Sum of octaves
                freq *= 2.0f;   // Double the frequency
                scale *= b;     // Next power of b
            }
            //clamping filter
            result = pow((sum + 1.0f)/ 2.0f,1.3);
            //Step filter for nodes
            //result = round(sum*32)/32;

            if(isnan(result)){
                result =0 ;
            }
            // Store in Vector of Vectors
            heightVals.at(static_cast<size_t>(row)).at(static_cast<size_t>(col)) = result*10;
        }
    }
}