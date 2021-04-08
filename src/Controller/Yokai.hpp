//
// Created by charl on 2/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_YOKAI_HPP
#define ICT397_GAME_ENGINE_YOKAI_HPP

#include "Controller/TerrainManager.hpp"
#include "View/Renderer/Renderer.hpp"
#include "View/Window.hpp"
#include "Model/SplashScreen.hpp"
class Layer;
class Yokai
{
  public:
    static Yokai & getInstance();
    void Init();
    void Run();
    Renderer renderer = {};
    Window window = {};
    //TerrainManager terrainManager = {};

  private:
    //Singleton pattern requires that all constructors,destructors and copy constructors be private
    void registerClose();
    Yokai() = default;
    ~Yokai() = default;
    Yokai(const Yokai &) = delete;
    Yokai &operator =(const Yokai &);
    bool isRunning = true;
    std::vector<Layer*> layers;
    SplashScreen* splashScreen;
};

#endif // ICT397_GAME_ENGINE_YOKAI_HPP
