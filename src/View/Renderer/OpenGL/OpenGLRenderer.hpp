
#pragma once

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "View/Renderer/RenderAPI.hpp"
#include <glm/glm.hpp>
#include "View/Renderer/DataTypes.hpp"
/**
 * @class OpenGLRenderer
 * @brief OpenGL rendering api implementation
 */
class OpenGLRenderer : public RenderAPI 
{
  public:
    /**
     * @brief Constructor for OpenGLRenderer
     */
    OpenGLRenderer();
    /**
     * @brief Destructor for OpenGLRenderer
     */
    ~OpenGLRenderer() override;
    /**
     * @brief Initialises OpenGL
     */
    virtual void Init() override;
    /**
     * @brief Deinitialises OpenGL
     */
    virtual void DeInit() override;
    /**
     * @brief Toggles Wireframe
     */
    virtual void ToggleWireFrame() override;
    /**
     * @brief Draws a mesh
     * @param VertexArrayBuffer& - VAO
     * @param size_t - indiceSize
     */
    virtual void Draw(VertexArrayBuffer& VAO,size_t indiceSize) override;
    /**
     * @brief Clears the Screen after Rendering
     */
    virtual void Clear() override;

  private:
    ///Boolean to check whether it is in wireframe
    bool isWireFrame = false;
};
