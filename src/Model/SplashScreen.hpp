//
// Created by Charlie Sewell on 7/04/2021.
//

#pragma once

#include "View/Renderer/Renderer.hpp"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

class SplashScreen{
  public:
    SplashScreen();
    void draw();
    void setTexture(std::string texturePath);
  private:
    Shader* splashShader;
    std::shared_ptr<VertexArrayBuffer> vao;
    std::shared_ptr<Texture> texture;
};

