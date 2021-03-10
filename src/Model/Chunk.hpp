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

class Chunk {
  public:
    Chunk();
    void SetupChunk(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    void DrawChunk(Shader &shader);
    //void SetShader(Shader shader){this->shader = shader;}
    unsigned int GetID(){return chunkID;}
  private:
    std::shared_ptr<VertexArrayBuffer> VAO;
    size_t indicesSize;
    std::vector<Texture> textures;
    unsigned int chunkID;


};

#endif // ICT397_GAME_ENGINE_CHUNKDATA_HPP
