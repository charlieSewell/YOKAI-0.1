//
// Created by charl on 4/03/2021.
//

#ifndef ICT397_GAME_ENGINE_CHUNK_HPP
#define ICT397_GAME_ENGINE_CHUNK_HPP

#include <vector>
#include "View/Renderer/DataTypes.hpp"
#include "View/Renderer/Shader.hpp"
#include "Controller/Yokai.hpp"

class Chunk {
  public:
    Chunk();
    void SetupChunk(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    void DrawChunk(Shader &shader);
    //void SetShader(Shader shader){this->shader = shader;}
    unsigned int GetID(){return chunkID;}
  private:
    unsigned int VBO = 0, VAO = 0, EBO = 0, EBO_Size = 0;
    glm::vec3 location;
    std::vector<Texture> textures;
    unsigned int chunkID;


};

#endif // ICT397_GAME_ENGINE_CHUNKDATA_HPP
