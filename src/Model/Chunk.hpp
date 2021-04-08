//
// Created by charl on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_CHUNK_HPP
#define ICT397_GAME_ENGINE_CHUNK_HPP

#include <vector>
#include <memory>
#include "View/Renderer/DataTypes.hpp"
#include "View/Renderer/Shader.hpp"
#include "View/Renderer/Renderer.hpp"
/**
 * @class Chunk
 * @brief A class that holds a singular chunk
 */
class Chunk 
{
  public:
    /**
     * @brief Constructs a Chunk Objects
     * @param shared_ptr<Texture> - grass
     * @param shared_ptr<Texture> - sand
     * @param shared_ptr<Texture> - snow
     * @param shared_ptr<Texture> - detail
     * @param int - sandHeight
     * @param int - grassHeight
     * @param int - snowHeight
     */
    Chunk(std::shared_ptr<Texture> &grass, std::shared_ptr<Texture> &sand, std::shared_ptr<Texture> &snow, std::shared_ptr<Texture> &detail,int sandHeight,int grassHeight,int snowHeight);
    /**
     * @brief Constructs a chunks mesh
     * @param vector<Vertex> - vertices
     * @param vector<unsigned int> - indices
     */
    void SetupChunk(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    /**
     * @brief Draws a chunk
     * @param Shader& - shader
     */
    void DrawChunk(Shader &shader);
    /**
     * @brief Gets the ID of a chunk
     * @return unsigned int - ID
     */
    unsigned int GetID(){return chunkID;}

  private:
    ///pointer to the mesh
    std::shared_ptr<VertexArrayBuffer> VAO;
    ///number of points in the mesh
    size_t indicesSize;
    ///list of textures for the mesh
    std::vector<std::shared_ptr<Texture>> textures;
    ///chunk ID
    unsigned int chunkID;
    ///heights of textures
    int sandHeight,grassHeight,snowHeight;
};

#endif // ICT397_GAME_ENGINE_CHUNKDATA_HPP
