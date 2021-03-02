//
// Created by charl on 2/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_UNNAMEDENGINE_HPP
#define ICT397_GAME_ENGINE_UNNAMEDENGINE_HPP

#include "View/Renderer/OpenGL.hpp"


class unnamedEngine {
  public:
    static unnamedEngine& getInstance();
    static void Init();
    OpenGL renderer = {};

  private:
    //Singleton pattern requires that all constructors,destructors and copy constructors be private
    unnamedEngine();
    ~unnamedEngine();
    unnamedEngine(const unnamedEngine &);
    unnamedEngine &operator =(const unnamedEngine &);

};

#endif // ICT397_GAME_ENGINE_UNNAMEDENGINE_HPP
