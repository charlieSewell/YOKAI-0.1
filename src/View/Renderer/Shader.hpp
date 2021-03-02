//
// Created by Charlie Sewell on 13/01/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_SHADER_HPP
#define ICT397_GAME_ENGINE_SHADER_HPP
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader {
  public:
    ///
    /// @param vertexPath
    /// @param fragmentPath
    Shader(const char* vertexPath, const char* fragmentPath);

    void useShader();
    //set uniforms
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    //shaders ID
    unsigned int getShaderID(){return shaderID;}
  private:
    unsigned int shaderID;
};

#endif // ICT397_GAME_ENGINE_SHADER_HPP
