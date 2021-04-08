//
// Created by Charlie Sewell on 4/03/2021.
//
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "TerrainFactory.hpp"
TerrainFactory &TerrainFactory::getInstance()
{
    static TerrainFactory instance;
    return instance;
}

void TerrainFactory::Init()
{
    luabridge::getGlobalNamespace(LuaManager::getInstance().getState())
            .beginNamespace("TerrainSettings")
                .addProperty("terrainSize",&terrainSize)
                .addProperty("mapPath",&mapPath)
                .addProperty("useHeightMap",&useHeightMap)
                .addProperty("sandTexture",&sandTexture)
                .addProperty("snowTexture",&snowTexture)
                .addProperty("grassTexture",&grassTexture)
                .addProperty("detailTexture",&detailTexture)
                .addProperty("sandHeight",&sandHeight)
                .addProperty("snowHeight",&snowHeight)
                .addProperty("grassHeight",&grassHeight)
            .endNamespace()
            .beginClass<TerrainFactory>("TerrainFactory")
                .addStaticFunction("getInstance",&TerrainFactory::getInstance)
                .addFunction("getHeight",&TerrainFactory::heightAt)
            .endClass();
    LuaManager::getInstance().runScript("content/Scripts/terrainConfig.lua");
    if(useHeightMap)
    {
        LoadHeightMap(mapPath);
    }
    else
    {
        terrainSize += 1;
        GeneratePerlinMap(terrainSize,terrainSize);
    }
    terrainTextures.push_back(Texture::Create(grassTexture));
    terrainTextures.push_back(Texture::Create(sandTexture));
    terrainTextures.push_back(Texture::Create(snowTexture));
    terrainTextures.push_back(Texture::Create(detailTexture));

}

Chunk TerrainFactory::SetupChunk(unsigned int xStart,unsigned int zStart,int size)
{
    Chunk chunk(terrainTextures.at(0),terrainTextures.at(1),terrainTextures.at(2),terrainTextures.at(3),sandHeight,grassHeight,snowHeight);
    size+=1;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    GenerateFlatMap(vertices,xStart,zStart,size,size);
    GenerateTerrainIndices(indices,size,size);
    //TODO: Come Up with better solution as currently just stretching over terrain
    GenerateTexCoords(vertices,size,size);
    int x = xStart;
    int z = zStart;
    for(auto& vert: vertices)
    {
        if(vert.position.x != x)
        {
            x ++;
            z=zStart;
        }
        vert.position.y = heightVals.at(x).at(z);
        z++;
    }
    GenerateNormals(vertices,indices);
    //TODO: Discuss better location for this
    PhysicsManager::getInstance().setTerrainCollider(heightVals);
    chunk.SetupChunk(vertices,indices);
    return chunk;
}

void TerrainFactory::GenerateFlatMap(std::vector<Vertex> &terrain,unsigned int xStart,unsigned int zStart, int xSize, int zSize) 
{
    Vertex vertex;
    for (unsigned x = xStart; x < xSize+xStart; x ++)
    {
        for (unsigned z = zStart ; z < zSize+zStart; z ++)
        {
            vertex.position.x = x;
            vertex.position.z = z;
            terrain.push_back(vertex);
            vertex = {};
        }
    }
}

void TerrainFactory::GenerateTerrainIndices(std::vector<unsigned int> &terrain, int xSize, int zSize)
{
    for(int x =0; x < xSize-1; x++)
    {
        for(int z =0; z < zSize-1; z++)
        {
            // Generates Terrain Indices for 2 triangles sharing one edge with the corners 0,1,2,3
            int pos = x * xSize + z;
            terrain.push_back(pos);             //Corner 0
            terrain.push_back(pos + 1);         //Corner 1
            terrain.push_back(pos + xSize);     //Corner 2
            terrain.push_back(pos + 1);         //Corner 1
            terrain.push_back(pos + 1 + xSize); //Corner 3
            terrain.push_back(pos + xSize);     //Corner 2

        }
    }
}

void TerrainFactory::GenerateTexCoords(std::vector<Vertex> &terrain, int xSize, int zSize)
{
    for(auto& vert: terrain)
    {
        vert.textureCoords = glm::vec2((float)vert.position.x,(float)vert.position.z);
    }
}

void TerrainFactory::GenerateNormals(std::vector<Vertex> &terrain, std::vector<unsigned int> &indices) 
{
    for(int i=0; i < indices.size(); i += 3)
    {
        Vertex &vert = terrain[indices[i]];
        Vertex &vert2 = terrain[indices[i+1]];
        Vertex &vert3 = terrain[indices[i+2]];

        glm::vec3 vec1 = vert2.position - vert.position;
        glm::vec3 vec2 = vert3.position - vert.position;
        glm::vec3 normal = glm::cross(vec1, vec2);
        normal = glm::normalize(normal);

        vert.normal += normal;
        vert2.normal += normal;
        vert3.normal += normal;
    }
    for(int i=0; i < terrain.size();i++)
    {
        terrain[i].normal = glm::normalize(terrain[i].normal);
    }
}

void TerrainFactory::LoadHeightMap(std::string filename)
{
    //File Must be square to produce the map e.g. 512x512
    int width,height,nrComponents;
    float* data = stbi_loadf(filename.c_str(),&width,&height,&nrComponents,1);

    terrainSize = width;
    terrainSize = floor(terrainSize/100)*100;
    heightVals.resize(static_cast<size_t>(width)+1);
    for (auto &e : heightVals) 
    {
        e.resize(static_cast<size_t>(height)+1);
    }
    for(int x = 0; x < width; x++) 
    {
        for (int y = 0; y < height; y++) 
        {
            heightVals.at((x)).at((y)) = data[((x * width) + y)]*255;
        }
    }
    for (int x = 1; x < width-1; x++) 
    {
        for (int y = 1; y < height-1; y++) 
        {
            //Average the imediate neighbours to smooth
            float average =0;
            average += heightVals.at((x)).at((y));
            average += heightVals.at((x+1)).at((y));
            average += heightVals.at((x-1)).at((y));
            average += heightVals.at((x)).at((y+1));
            average += heightVals.at((x)).at((y-1));
            heightVals.at((x)).at((y)) = average / 5;
        }
    }
    stbi_image_free(data);
}
float TerrainFactory::heightAt(int x,int z)
{
    if(x > 0 && x < terrainSize && z > 0 && z < terrainSize)
    {
        return heightVals.at(x).at(z);
    }
}
void TerrainFactory::GeneratePerlinMap(int xSize,int ySize)
{
    heightVals.resize(static_cast<size_t>(xSize));
    for (auto &e : heightVals) {
        e.resize(static_cast<size_t>(ySize));
    }
    float xFactor = 1.0f / (250 - 1);
    float yFactor = 1.0f / (250 - 1);
    float a       = 0.3; //Tuning variables
    float b       = 0.2;  //Tuning variables

    for( int row = 0; row < ySize; row++ ) 
    {
        for( int col = 0 ; col < xSize; col++ ) 
        {
            float x = xFactor * col;
            float y = yFactor * row;
            float sum = 0.0f;
            float freq = a;
            float scale = b;
            float result =0.0f;
            // Compute the sum for each octave
            for( int oct = 1; oct <= 4; oct++ ) 
            {
                glm::vec2 p(x * freq, y * freq);
                float val = glm::simplex(p) * 1/oct;
                sum += val;     // Sum of octaves
                freq *= 2.0f;   // Double the frequency
                scale *= b;     // Next power of b
            }
            result = pow((sum + 1.0f)/ 2.0f,1.3);


            if(isnan(result))
            {
                result =0 ;
            }
            // Store in Vector of Vectors
            heightVals.at(static_cast<size_t>(row)).at(static_cast<size_t>(col)) = result*255;
        }
    }
}