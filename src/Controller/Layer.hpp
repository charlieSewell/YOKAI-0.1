//
// Created by charl on 20/03/2021.
//

#ifndef ICT397_GAME_ENGINE_LAYER_HPP
#define ICT397_GAME_ENGINE_LAYER_HPP

class Layer {
  public:
    virtual void Update() = 0;
    virtual void Enable() = 0;
    virtual void Disable() = 0;
  private:

};

#endif // ICT397_GAME_ENGINE_LAYER_HPP
