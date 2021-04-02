//
// Created by Charlie Sewell on 20/03/2021.
//

#ifndef ICT397_GAME_ENGINE_GAMESTACK_HPP
#define ICT397_GAME_ENGINE_GAMESTACK_HPP
#include <stack>
#include <vector>
#include "Controller/Layer.hpp"

class GameStack{
  public:
    void PushLayer(Layer* layer);
    void PopLayer(Layer* layer);

    std::vector<Layer*>::iterator begin() { return layers.begin(); }
    std::vector<Layer*>::iterator end() { return layers.end(); }
    std::vector<Layer*>::reverse_iterator rBegin() { return layers.rbegin(); }
    std::vector<Layer*>::reverse_iterator rEnd() { return layers.rend(); }
  private:
    std::vector<Layer*> layers;

};



#endif // ICT397_GAME_ENGINE_GAMESTACK_HPP
