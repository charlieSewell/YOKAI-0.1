#pragma once
#include "View/Renderer/DataTypes.hpp"
#include <iostream>
#include <map>
class TextureManager{
public:
    static TextureManager &getInstance();
    unsigned int loadTexture(const std::string& textureName);
    std::shared_ptr<Texture> getTexture(unsigned int textureID);
    void unBindTexture(unsigned int textureID);
    void replaceTexture(size_t slot,const std::string& newTexturePath);
private:
    TextureManager();
    std::map<unsigned int,std::pair<std::string,std::shared_ptr<Texture>>> textures;
    unsigned int textureCount;
};
