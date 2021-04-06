//
// Created by charl on 20/03/2021.
//
#include "GameStack.hpp"

void GameStack::PushLayer(Layer *layer) 
{
    layers.push_back(layer);
}

void GameStack::PopLayer(Layer *layer) 
{
    auto it = std::find(layers.begin(), layers.end(), layer);

    if (it != layers.end())
    {
        layer->Disable();
        layers.erase(it);
    }
}