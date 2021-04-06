//
// Created by Charlie Sewell on 25/02/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_RENDERER_HPP
#define ICT397_GAME_ENGINE_RENDERER_HPP

#include "View/Renderer/RenderAPI.hpp"
#include "View/Renderer/DataTypes.hpp"
#include "Controller/EventManager.hpp"

#include <memory>

class Renderer 
{
  public:
    static void Init();
    static void DeInit();
    static void registerToggleWireframe();
    static void Draw(Shader &shader,VertexArrayBuffer& VAO,size_t indiceSize);
    static void Clear();

  private:
    static std::shared_ptr<RenderAPI> renderApi;
};

#endif // ICT397_GAME_ENGINE_RENDERER_HPP
