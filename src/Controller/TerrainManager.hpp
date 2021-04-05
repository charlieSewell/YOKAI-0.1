//
// Created by charl on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_TERRAINMANAGER_HPP
#define ICT397_GAME_ENGINE_TERRAINMANAGER_HPP

#include <vector>
#include <map>
#include "Model/Chunk.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
class TerrainManager {
  public:
    void Init();
    void Draw(glm::vec3 viewpos);

  private:
    void CreateTerrain();
    void LoadChunk();
    int chunkSize,maxKey;
    std::shared_ptr<Shader> terrainShader;
    std::map<std::pair<int,int>,Chunk> chunks;
};

#endif // ICT397_GAME_ENGINE_TERRAINMANAGER_HPP
