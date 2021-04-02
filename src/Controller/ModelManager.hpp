//
// Created by Charlie Sewell on 23/02/2021.
//
#pragma once

#ifndef ICT397_GAME_ENGINE_MODELMANAGER_HPP
#define ICT397_GAME_ENGINE_MODELMANAGER_HPP

#include "Model/Model.hpp"
#include "Model/ObjectLoading/ModelLoader.hpp"
#include <map>
#include <array>
class ModelManager {
  public:
    ModelManager();
    auto GetModelID(std::string filename) -> size_t;
    Model* GetModel(size_t modelID);
    void DrawModel(size_t id,Shader &shader);
  private:
    ModelLoader modelLoader;
    size_t modelCount = 0;
    std::map<std::string,size_t>modelIDtoName;
    std::vector<Model> models;

};

#endif // ICT397_GAME_ENGINE_MODELMANAGER_HPP
