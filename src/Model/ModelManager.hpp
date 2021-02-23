//
// Created by Charlie Sewell on 23/02/2021.
//
#pragma once

#ifndef ICT397_GAME_ENGINE_MODELMANAGER_HPP
#define ICT397_GAME_ENGINE_MODELMANAGER_HPP

#include "Model/ObjectLoading/Model.hpp"
#include <map>
#include <array>
class ModelManager {
  private:
    size_t modelCount = 0;
    std::map<std::string,size_t>modelIDtoName;
    std::array<Model,1000> models;

  public:
    auto GetModelID(std::string filename) -> size_t;
};

#endif // ICT397_GAME_ENGINE_MODELMANAGER_HPP
