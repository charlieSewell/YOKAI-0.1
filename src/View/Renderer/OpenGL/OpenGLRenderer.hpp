//
// Created by charl on 1/03/2021.
//
#pragma once
#ifndef ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
#define ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "View/Renderer/Renderer.hpp"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "View/Renderer/DataTypes.hpp"

#include "View/Renderer/Shader.hpp"

class OpenGLRenderer : public Renderer {
  public:
    OpenGLRenderer() = default;
    void Init() override;
    void DeInit() override;
    void ToggleWireFrame() override;


    static void SetupMesh(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO,
                          std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
    static void SetupTerrainMesh(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO,
                          const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    static unsigned int TextureFromFile(const char *path, const std::string &inputDirectory);

    static void DrawModel(Shader& shader, unsigned int &VAO, const std::vector<Texture> &textures, const std::vector<unsigned int> &indices);
    static void DrawChunk(Shader& shader, unsigned int &VAO, const std::vector<Texture> &textures, const unsigned int indicesSize);
    GLFWwindow* window;
  private:
    bool isWireFrame = false;
};


#endif // ICT397_GAME_ENGINE_OPENGLRENDERER_HPP
