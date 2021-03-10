//
// Created by Charlie Sewell on 10/03/2021.
//
#include "View/Renderer/OpenGL/OpenGLRenderer.hpp"
#include "RenderAPI.hpp"
RenderAPI * RenderAPI::Create() {
    return new OpenGLRenderer();
}