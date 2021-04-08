//
// Created by Charlie Sewell on 7/04/2021.
//

#pragma once

#include "View/Renderer/Renderer.hpp"

class SplashScreen{
  public:
    SplashScreen(std::string texturePath);
    void draw();
    void setTexture(std::string texturePath);
  private:
    Shader* splashShader;
    std::shared_ptr<VertexArrayBuffer> vao;
    std::shared_ptr<Texture> texture;
    void setupShader();
    void setupPanel();
};

