//
// Created by charl on 1/03/2021.
//

#ifndef ICT397_GAME_ENGINE_OPENGL_HPP
#define ICT397_GAME_ENGINE_OPENGL_HPP
#include "Renderer.hpp"
class OpenGL : public Renderer{
  public:
    void Init();
    void Draw();
    void toggleWireframe();
    void AddToQueue();

  private:
    std::vector<drawObject>drawQueue;
};

#endif // ICT397_GAME_ENGINE_OPENGL_HPP
