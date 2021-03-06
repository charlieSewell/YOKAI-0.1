//
// Created by Charlie Sewell on 25/02/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_RENDERER_HPP
#define ICT397_GAME_ENGINE_RENDERER_HPP
#include <glm/glm.hpp>
#include <vector>


class Renderer {
  public:
   virtual void Init() = 0;
   virtual void DeInit() = 0;
   virtual void ToggleWireFrame() = 0;

  private:



};

#endif // ICT397_GAME_ENGINE_RENDERER_HPP
