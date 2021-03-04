//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"
Yokai::Yokai(){
}
Yokai::~Yokai() {

}
Yokai &Yokai::getInstance() {
    static Yokai instance;
    return instance;
}

