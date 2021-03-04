//
// Created by charl on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_TERRAINGENERATOR_HPP
#define ICT397_GAME_ENGINE_TERRAINGENERATOR_HPP

#include <vector>

#include <View/Renderer/DataTypes.hpp>
#include <glm/gtc/noise.hpp>
#include "Model/Chunk.hpp"

class TerrainGenerator {
  public:
    void SetupChunk(Chunk &Chunk,int size);
    void GenerateFlatMap(std::vector<Vertex> &terrain,int xSize, int zSize);
    void GenerateTerrainIndices(std::vector<unsigned int> &terrain,int xSize, int zSize);
    void GenerateTexCoords(std::vector<Vertex> &terrain,int xSize, int zSize);
    void GeneratePerlinMap(int xSize,int ySize);
  private:
    std::vector<std::vector<float>> heightVals = {};
};

#endif // ICT397_GAME_ENGINE_TERRAINGENERATOR_HPP
