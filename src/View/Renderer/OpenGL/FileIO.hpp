//
// Created by charl on 10/03/2021.
//

#ifndef ICT397_GAME_ENGINE_FILEIO_HPP
#define ICT397_GAME_ENGINE_FILEIO_HPP
#include <iostream>

unsigned char* TextureFromFile(std::string filename, int &width,int &height, int &nrComponents);
void FreeTextureData(unsigned char* data);

#endif // ICT397_GAME_ENGINE_FILEIO_HPP
