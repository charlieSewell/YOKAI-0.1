//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
#define ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "View/Renderer/RenderAPI.hpp"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "View/Renderer/DataTypes.hpp"
#include "View/Renderer/Shader.hpp"

class OpenGLRenderer : public RenderAPI 
{
  public:
    OpenGLRenderer();
    ~OpenGLRenderer() override;
    virtual void Init() override;
    virtual void DeInit() override;
    virtual void ToggleWireFrame() override;
    virtual void Draw(VertexArrayBuffer& VAO,size_t indiceSize) override;
    virtual void Clear() override;

  private:
    bool isWireFrame = false;
};

#endif // ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
