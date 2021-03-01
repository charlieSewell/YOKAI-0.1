//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_OPENGL_HPP
#define ICT397_GAME_ENGINE_OPENGL_HPP
#include "Renderer.hpp"
#include <glm/glm.hpp>
#include <glad/glad.h>

#include "View/Renderer/Shader.hpp"
#include "View/Renderer/DataTypes.hpp"
#include <vector>
#include <iostream>

class OpenGL : public Renderer {
  public:
    OpenGL() = default;
    void Init() override;
    void Draw() override;
    void AddToQueue(drawObject objToAdd);



    static void SetupMesh(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO,
                          std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
    static unsigned int TextureFromFile(const char *path, const std::string &inputDirectory);

    static void DrawModel(Shader& shader, unsigned int &VAO, const std::vector<Texture> &textures, const std::vector<unsigned int> &indices);

  private:
    std::vector<drawObject> drawQueue;
};


#endif // ICT397_GAME_ENGINE_OPENGL_HPP
