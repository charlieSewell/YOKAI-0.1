//
// Created by charl on 5/04/2021.
//

#ifndef ICT397_GAME_ENGINE_DEMOSCENE_HPP
#define ICT397_GAME_ENGINE_DEMOSCENE_HPP

#include "Controller/Layer.hpp"

class DemoScene : public Layer
{
  public:
    void Init() override;
    void Update() override;
    void Draw() override;
    void Enable() override;
    void Disable() override;
  private:
    TerrainManager terrainManager = {};
    bool isEnabled = true;
};

#endif // ICT397_GAME_ENGINE_DEMOSCENE_HPP
