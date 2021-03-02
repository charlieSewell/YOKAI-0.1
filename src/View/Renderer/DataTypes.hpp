//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_DATATYPES_HPP
#define ICT397_GAME_ENGINE_DATATYPES_HPP
#include <glm/glm.hpp>
#include <string>
struct Vertex {
    glm::vec3 position = {};
    glm::vec3 normal = {};
    glm::vec2 textureCoords = {};
    glm::vec3 tangent = {};
    glm::vec3 biTangent = {};
};
struct Texture {
    unsigned int id = {};
    std::string type = {};
    std::string path = {};
};
#endif // ICT397_GAME_ENGINE_DATATYPES_HPP
