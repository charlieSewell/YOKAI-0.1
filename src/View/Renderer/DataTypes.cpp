//
// Created by Charlie Sewell on 9/03/2021.
//
#include "DataTypes.hpp"
#include "View/Renderer/OpenGL/OpenGLDataTypes.hpp"

std::shared_ptr<VertexBuffer> VertexBuffer::Create(std::vector<Vertex> vertices) {
    return std::shared_ptr<VertexBuffer>(new OpenGLVertexBuffer(vertices));
}
std::shared_ptr<IndexBuffer> IndexBuffer::Create(std::vector<unsigned int> indices) {
    return std::shared_ptr<IndexBuffer>(new OpenGLIndexBuffer(indices));
}
std::shared_ptr<VertexArrayBuffer> VertexArrayBuffer::Create(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    return std::shared_ptr<VertexArrayBuffer>(new OpenGLVertexArrayBuffer(vertices,indices));
}
std::shared_ptr<Texture> Texture::Create(std::string fileName) {
    return std::shared_ptr<Texture>(new OpenGLTexture(fileName));
}
