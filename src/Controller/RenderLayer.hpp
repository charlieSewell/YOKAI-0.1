//
// Created by charl on 22/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_RENDERLAYER_H
#define ICT397_GAME_ENGINE_RENDERLAYER_H

#include "Controller/Layer.hpp"
#include "View/Renderer/Shader.hpp"
#include "Model/Chunk.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderLayer : public Layer
{
  public:
    void Init() override;
    void Update() override;

  private:
    Shader testShader,modelShader;
    Chunk testChunk;
    Player player;
};

#endif // ICT397_GAME_ENGINE_RENDERLAYER_H
