//
// Created by Charlie Sewell on 13/01/2021.
//

#include "Shader.hpp"

void Shader::useShader(){
    glUseProgram(shaderID);
}

void Shader::setBool(const std::string &name, bool value) const{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const{
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const{
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}