//
// Created by Charlie Sewell on 9/03/2021.
//
#include "DataTypes.hpp"
#include "View/Renderer/OpenGL/OpenGLDataTypes.hpp"
VertexBuffer * VertexBuffer::Create(std::vector<Vertex> vertices) {
    return new OpenGLVertexBuffer(vertices);
}
IndexBuffer * IndexBuffer::Create(std::vector<unsigned int> indices) {
    return new OpenGLIndexBuffer(indices);
}
VertexArrayBuffer * VertexArrayBuffer::Create(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    return new OpenGLVertexArrayBuffer(vertices,indices);
}