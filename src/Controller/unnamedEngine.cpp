//
// Created by charl on 2/03/2021.
//

#include "unnamedEngine.hpp"
unnamedEngine::unnamedEngine(){
}
unnamedEngine::~unnamedEngine() {

}
unnamedEngine & unnamedEngine::getInstance() {
    static unnamedEngine instance;
    return instance;
}

