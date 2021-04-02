//
// Created by Charlie Sewell on 23/02/2021.
//
#pragma once

#ifndef ICT397_GAME_ENGINE_MODELMANAGER_HPP
#define ICT397_GAME_ENGINE_MODELMANAGER_HPP

#    include <array>
#    include <map>

#    include "Model/Model.hpp"
#include "Model/ObjectLoading/ModelLoader.hpp"
class ModelManager {
  public:
    ModelManager();
    auto GetModelID(std::string filename) -> size_t;
    Model* GetModel(size_t modelID);
    void DrawModel(size_t id,Shader &shader);
  private:
    size_t modelCount = 0;
    std::map<std::string,size_t>modelIDtoName;
    std::vector<Model> models;
    ModelLoader loader;

};

#endif // ICT397_GAME_ENGINE_MODELMANAGER_HPP
