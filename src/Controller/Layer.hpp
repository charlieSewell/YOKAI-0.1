//
// Created by charl on 20/03/2021.
//

#ifndef ICT397_GAME_ENGINE_LAYER_HPP
#define ICT397_GAME_ENGINE_LAYER_HPP
#include "Controller/TerrainManager.hpp"
#include "Controller/GameObjectManager.hpp"
#include "Controller/InputManagerGLFW.hpp"
#include "Yokai.hpp"
class Layer 
{
  public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Enable() = 0;
    virtual void Disable() = 0;

  private:
};

#endif // ICT397_GAME_ENGINE_LAYER_HPP
