//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_DATATYPES_HPP
#define ICT397_GAME_ENGINE_DATATYPES_HPP
#include <glm/glm.hpp>
#include <string>
#include <vector>
struct Vertex {
    glm::vec3 position = {};
    glm::vec3 normal = {};
    glm::vec2 textureCoords = {};
    glm::vec3 tangent = {};
    glm::vec3 biTangent = {};
};
struct Texture {
    unsigned int id = {};
    std::string type = {};
    std::string path = {};
};
class VertexBuffer{
  public:
    virtual void Bind() = 0;
    virtual void UnBind() =0;
    virtual ~VertexBuffer();
    //static VertexBuffer* Create(std::vector<Vertex> vertices);
};
class IndexBuffer{
  public:
    virtual void Bind() = 0;
    virtual void UnBind() =0;
    virtual ~IndexBuffer();
    //static IndexBuffer* Create(std::vector<unsigned int> indices);
};
#endif // ICT397_GAME_ENGINE_DATATYPES_HPP
