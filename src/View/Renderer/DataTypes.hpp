//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_DATATYPES_HPP
#define ICT397_GAME_ENGINE_DATATYPES_HPP
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>

struct Vertex
{
    glm::vec3 position = {};
    glm::vec3 normal = {};
    glm::vec2 textureCoords = {};
    glm::vec3 tangent = {};
    glm::vec3 biTangent = {};
};

class Texture
{
  public:
    virtual ~Texture() = default;
    virtual void Bind(size_t slot) = 0;
    virtual void UnBind() =0;
    virtual int getID()=0;

    static std::shared_ptr<Texture> Create(std::string fileName);
};

struct ModelTexture 
{
    std::shared_ptr<Texture> texture;
    std::string type = {};
    std::string path = {};
};

class VertexBuffer
{
  public:
    virtual ~VertexBuffer() = default;
    virtual void Bind() = 0;
    virtual void UnBind() =0;

    static std::shared_ptr<VertexBuffer> Create(std::vector<Vertex> vertices);
};

class IndexBuffer
{
  public:
    virtual ~IndexBuffer() = default;
    virtual void Bind() = 0;
    virtual void UnBind() =0;

    static std::shared_ptr<IndexBuffer> Create(std::vector<unsigned int> indices);
};

class VertexArrayBuffer
{
  public:
    virtual ~VertexArrayBuffer() =default;
    virtual void Bind() = 0;
    virtual void UnBind() =0;

    static std::shared_ptr<VertexArrayBuffer> Create(std::vector<Vertex> vertices,std::vector<unsigned int> indices);
};
#endif // ICT397_GAME_ENGINE_DATATYPES_HPP
