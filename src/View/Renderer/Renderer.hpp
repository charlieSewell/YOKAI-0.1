//
// Created by Charlie Sewell on 25/02/2021.
//
#pragma once

#include "View/Renderer/RenderAPI.hpp"
#include "View/Renderer/DataTypes.hpp"
#include "Controller/EventManager.hpp"

#include <memory>
/**
 * @class Renderer
 * @brief renders objects to the screen
 */
class Renderer 
{
  public:
    /**
     * @brief Initialises the Renderer
     */
    static void Init();
    /**
     * @brief Deinitialises the renderer
     */
    static void DeInit();
    /**
     * @brief Toggles Wireframe
     */
    static void ToggleWireFrame();
    /**
     * @brief Draws a mesh to the screen
     * @param VertexArrayBuffer& - VAO
     * @param size_t - indiceSize
     */
    static void Draw(VertexArrayBuffer& VAO,size_t indiceSize);
    /**
     * @brief Clears the screen
     */
    static void Clear();

  private:
    /**
     * @brief Registers button to wireframe toggle
     */
    static void registerToggleWireframe();
    ///Pointer to chosen RenderAPI
    static std::shared_ptr<RenderAPI> renderApi;
};

