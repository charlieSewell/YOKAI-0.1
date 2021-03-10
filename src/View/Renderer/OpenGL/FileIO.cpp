//
// Created by charl on 10/03/2021.
//
#include "View/Renderer/OpenGL/FileIO.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
unsigned char* TextureFromFile(std::string filename, int &width,int &height, int &nrComponents){
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    return data;
}
void FreeTextureData(unsigned char* data){
    stbi_image_free(data);
}