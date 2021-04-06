//
// Created by charl on 1/03/2021.
//
#pragma once
#include "OpenGLRenderer.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "Controller/EventManager.hpp"

OpenGLRenderer::OpenGLRenderer() 
{
}

OpenGLRenderer::~OpenGLRenderer()
{
}

void OpenGLRenderer::Init() 
{
    if (!gladLoadGL()) 
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glEnable(GL_DEPTH_TEST);
    std::cout << "Renderer Initialised: Using OpenGL" << std::endl;

}

void OpenGLRenderer::DeInit() 
{
}

void OpenGLRenderer::Clear() 
{
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::ToggleWireFrame() 
{
    if(isWireFrame)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        isWireFrame = false;
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        isWireFrame = true;
    }
}

void OpenGLRenderer::Draw(Shader& shader,VertexArrayBuffer& VAO, size_t indicesSize) 
{
    VAO.Bind();
    glDrawElements(GL_TRIANGLES, indicesSize, GL_UNSIGNED_INT, 0);

}
