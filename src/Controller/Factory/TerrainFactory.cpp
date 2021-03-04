//
// Created by Charlie Sewell on 4/03/2021.
//

#include "TerrainFactory.hpp"
TerrainFactory &TerrainFactory::getInstance() {
    static TerrainFactory instance;
    return instance;
}