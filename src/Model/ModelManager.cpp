//
// Created by Charlie Sewell on 23/02/2021.
//

#include "ModelManager.hpp"
auto ModelManager::GetModelID(std::string filename) -> size_t {
    auto id = modelIDtoName.find(filename);
    if(id == modelIDtoName.end()){
        //import model
    }
    return(id->second);
}