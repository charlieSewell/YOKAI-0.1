//
// Created by Charlie Sewell on 9/03/2021.
//
#include "OpenGLDataTypes.hpp"
OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<Vertex> vertices) {
    glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER,bufferID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
}
OpenGLVertexBuffer::~OpenGLVertexBuffer(){
    glDeleteBuffers(1,&bufferID);
}
void OpenGLVertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER,bufferID);
}
void OpenGLVertexBuffer::UnBind() {
    glBindBuffer(GL_ARRAY_BUFFER,0);
}



OpenGLIndexBuffer::OpenGLIndexBuffer(std::vector<unsigned int> indices) {
    glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}
OpenGLIndexBuffer::~OpenGLIndexBuffer(){
    glDeleteBuffers(1,&bufferID);
}
void OpenGLIndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,bufferID);
}
void OpenGLIndexBuffer::UnBind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

}
OpenGLVertexArrayBuffer::OpenGLVertexArrayBuffer(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
    glGenVertexArrays(1,&bufferID);
    glBindVertexArray(bufferID);
    vertexBuffer = new OpenGLVertexBuffer(vertices);
    indexBuffer = new OpenGLIndexBuffer(indices);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals pointer setup
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));
    // vertex coords pointer setup
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, textureCoords));

    glBindVertexArray(0);

}
OpenGLVertexArrayBuffer::~OpenGLVertexArrayBuffer(){
    glDeleteBuffers(1,&bufferID);
}
void OpenGLVertexArrayBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,bufferID);
}
void OpenGLVertexArrayBuffer::UnBind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}