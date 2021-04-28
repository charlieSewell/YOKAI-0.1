//
// Created by Charlie Sewell on 9/03/2021.
//
#include "DataTypes.hpp"

#include <utility>
#include "View/Renderer/OpenGL/OpenGLDataTypes.hpp"

std::shared_ptr<VertexBuffer> VertexBuffer::Create(std::vector<Vertex> vertices) 
{
    return std::shared_ptr<VertexBuffer>(new OpenGLVertexBuffer(std::move(vertices)));
}

std::shared_ptr<IndexBuffer> IndexBuffer::Create(std::vector<unsigned int> indices) 
{
    return std::shared_ptr<IndexBuffer>(new OpenGLIndexBuffer(std::move(indices)));
}

std::shared_ptr<VertexArrayBuffer> VertexArrayBuffer::Create(std::vector<Vertex> vertices, std::vector<unsigned int> indices) 
{
    return std::shared_ptr<VertexArrayBuffer>(new OpenGLVertexArrayBuffer(std::move(vertices),std::move(indices)));
}

std::shared_ptr<Texture> Texture::Create(std::string fileName) 
{
    return std::shared_ptr<Texture>(new OpenGLTexture(std::move(fileName)));
}
