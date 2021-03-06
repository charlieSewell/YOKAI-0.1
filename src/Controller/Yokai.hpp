//
// Created by charl on 2/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_YOKAI_HPP
#define ICT397_GAME_ENGINE_YOKAI_HPP

#include "View/Renderer/OpenGL.hpp"
#include "Controller/TerrainManager.hpp"

class Yokai {
  public:
    static Yokai & getInstance();
    static void Init();
    OpenGL renderer = {};
    //TerrainManager terrainManager = {};

  private:
    //Singleton pattern requires that all constructors,destructors and copy constructors be private
    Yokai() = default;
    ~Yokai() = default;
    Yokai(const Yokai &) = delete;
    Yokai &operator =(const Yokai &);

};

#endif // ICT397_GAME_ENGINE_YOKAI_HPP
