//
// Created by Charlie Sewell on 25/02/2021.
//

#ifndef ICT397_GAME_ENGINE_RENDERER_HPP
#define ICT397_GAME_ENGINE_RENDERER_HPP
#include <glm/glm.hpp>
#include <vector>
struct drawObject{
    glm::vec3 pos;
};

class Renderer {
  public:
   virtual void Init() = 0;
   virtual void Draw() = 0;
   virtual void DeInit() = 0;
   virtual void ToggleWireFrame() = 0;

  private:



};

#endif // ICT397_GAME_ENGINE_RENDERER_HPP
