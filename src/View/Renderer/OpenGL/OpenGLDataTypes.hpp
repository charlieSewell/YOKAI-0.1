//
// Created by Charlie Sewell on 9/03/2021.
//

#ifndef ICT397_GAME_ENGINE_OPENGLDATATYPES_HPP
#define ICT397_GAME_ENGINE_OPENGLDATATYPES_HPP

#include <glad/glad.h>
#include "View/Renderer/DataTypes.hpp"

class OpenGLVertexBuffer : public VertexBuffer{
  public:
    virtual ~OpenGLVertexBuffer();
    OpenGLVertexBuffer(std::vector<Vertex> vertices);
    virtual void Bind() override;
    virtual void UnBind() override;


  private:
    unsigned int bufferID;
};
class OpenGLIndexBuffer : public IndexBuffer{
  public:
    virtual ~OpenGLIndexBuffer();
    OpenGLIndexBuffer(std::vector<unsigned int> indices);
    virtual void Bind() override;
    virtual void UnBind() override;

  private:
    unsigned int bufferID;
};
class OpenGLVertexArrayBuffer : public VertexArrayBuffer{
  public:
    virtual ~OpenGLVertexArrayBuffer();
    OpenGLVertexArrayBuffer(std::vector<Vertex> vertices,std::vector<unsigned int> indices);
    virtual void Bind() override;
    virtual void UnBind() override;

  private:
    unsigned int bufferID;
    OpenGLVertexBuffer* vertexBuffer;
    OpenGLIndexBuffer* indexBuffer;
};

#endif // ICT397_GAME_ENGINE_OPENGLDATATYPES_HPP
