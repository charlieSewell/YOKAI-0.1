//
// Created by Charlie Sewell on 25/02/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_RENDERER_HPP
#define ICT397_GAME_ENGINE_RENDERER_HPP
#include "View/Renderer/RenderAPI.hpp"
#include "View/Renderer/DataTypes.hpp"
#include <GLFW/glfw3.h>
class Renderer {
  public:
    GLFWwindow* window;
    static void Init();
    static void DeInit();
    static void ToggleWireFrame();
    static void Draw(VertexArrayBuffer& VAO,size_t indiceSize);
    static void Clear();
  private:
        static RenderAPI* renderApi;

};

#endif // ICT397_GAME_ENGINE_RENDERER_HPP
