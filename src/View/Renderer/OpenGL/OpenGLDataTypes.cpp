//
// Created by Charlie Sewell on 9/03/2021.
//
#include "OpenGLDataTypes.hpp"
#include "View/Renderer/OpenGL/FileIO.hpp"
OpenGLTexture::OpenGLTexture(std::string path) {
    std::string filename = std::string(path);
    glGenTextures(1, &textureID);
    int width, height, nrComponents;
    unsigned char *data = TextureFromFile(filename,width,height,nrComponents);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D,0);
        FreeTextureData(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        FreeTextureData(data);
    }
}
OpenGLTexture::~OpenGLTexture(){
    glDeleteTextures(1,&textureID);
}
void OpenGLTexture::Bind(size_t slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, textureID);

}
void OpenGLTexture::UnBind() {
    glBindTexture(GL_TEXTURE_2D,0);
}


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
    vertexBuffer = std::shared_ptr<OpenGLVertexBuffer>(new OpenGLVertexBuffer(vertices));
    indexBuffer = std::shared_ptr<OpenGLIndexBuffer>(new OpenGLIndexBuffer(indices));

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
    glBindVertexArray(bufferID);
}
void OpenGLVertexArrayBuffer::UnBind() {
    glBindVertexArray(0);
}