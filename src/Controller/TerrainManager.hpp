#pragma once
#include <vector>
#include <map>
#include "Model/Chunk.hpp"
#include "Controller/Factory/TerrainFactory.hpp"

/**
 * @class TerrainManager
 * @brief Responsible for managing terrain
 */
class TerrainManager 
{
  public:
    /*!
     * @brief Initialises the manager
     */
    void Init();

    /*!
     * @brief Draws chunks of terrain
     * @param vec3 - viewPos
     */
    void Draw(glm::vec3 viewpos);

  private:
    /*!
     * @brief Creates terrain
     */
    void CreateTerrain();

    /*!
     * @brief Loads chunk
     */
    void LoadChunk();

    /// Size of chunk, maximum key value
    int chunkSize,maxKey;

    /// Shader pointer
    Shader* terrainShader;

    /// Map of chunks
    std::map<std::pair<int,int>,Chunk> chunks;
};
