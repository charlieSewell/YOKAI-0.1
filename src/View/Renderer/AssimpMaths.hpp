//
// Created by charl on 3/03/2021.
//

#ifndef ICT397_GAME_ENGINE_ASSIMPMATHS_HPP
#define ICT397_GAME_ENGINE_ASSIMPMATHS_HPP

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

#include <glm/glm.hpp>

class Maths {
  public:
    static glm::mat4 ai4x4ToGLM(const aiMatrix4x4 &src);
};

#endif // ICT397_GAME_ENGINE_ASSIMPMATHS_HPP
