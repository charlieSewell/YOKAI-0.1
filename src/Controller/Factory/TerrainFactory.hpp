//
// Created by Charlie Sewell on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_TERRAINFACTORY_HPP
#define ICT397_GAME_ENGINE_TERRAINFACTORY_HPP

#include <vector>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/normal.hpp>
#include <math.h>

#include "View/Renderer/DataTypes.hpp"
#include "Model/Chunk.hpp"

class TerrainFactory {
  public:
    static TerrainFactory & getInstance();
    void Init();
    void SetupChunk(Chunk &Chunk,unsigned int xStart,unsigned int zStart,int size);
	//temporary
	int terrainSize;
	std::vector<std::vector<float>> heightVals = {};

  private:
    TerrainFactory() = default;
    ~TerrainFactory() = default;
    TerrainFactory(const TerrainFactory &) = delete;
    TerrainFactory &operator =(const TerrainFactory &);
    //int terrainSize;


    void GenerateFlatMap(std::vector<Vertex> &terrain,unsigned int xStart,unsigned int zStart,int xSize, int zSize);
    void GenerateTerrainIndices(std::vector<unsigned int> &terrain,int xSize, int zSize);
    void GenerateTexCoords(std::vector<Vertex> &terrain,int xSize, int zSize);
    void GenerateNormals(std::vector<Vertex> &terrain, std::vector<unsigned int> &indices);
    void GeneratePerlinMap(int xSize,int ySize);
    void LoadHeightMap(std::string filename);
    //std::vector<std::vector<float>> heightVals = {};
};

#endif // ICT397_GAME_ENGINE_TERRAINFACTORY_HPP
