//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"

Yokai &Yokai::getInstance() {
    static Yokai instance;
    return instance;
}
void Yokai::Init() {
    Renderer::Init();
}
