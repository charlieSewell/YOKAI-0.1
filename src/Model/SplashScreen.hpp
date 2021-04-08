//
// Created by Charlie Sewell on 7/04/2021.
//

#pragma once

#include "View/Renderer/Renderer.hpp"
/**
 * @class SplashScreen
 * @brief Class that creates Splash screens for rendering
 */
class SplashScreen {
  public:
    /**
     * @brief Constructor for SplashScreen
     * @param string - texturePath
     */
    SplashScreen(std::string texturePath);
    /**
     * @brief Draws Splash Screen
     */
     /**
      * @brief Draws splash screen
      */
    void draw();
    /**
     * @brief Sets the texture for the splash screen
     * @param string - texturePath
     */
    void setTexture(std::string texturePath);
    /**
     * @brief Sets the splash screen as active
     */
    void setActive();
    /**
     * @brief Sets the splash screen as inactive
     */
    void setInactive();
    /**
     * @brief Returns whether the splash screen is active
     * @return bool
     */
    bool isActive();
  private:
    ///Pointer to shader
    Shader *splashShader;
    ///shared_ptr to splash screen panel
    std::shared_ptr<VertexArrayBuffer> vao;
    ///shared_ptr to splash screen texture
    std::shared_ptr<Texture> texture;
    ///is splash screen active
    bool active = false;
    /**
     * @brief Sets up splash screen shader
     */
    void setupShader();
    /**
     * @brief Sets up splash screen panel mesh
     */
    void setupPanel();

};