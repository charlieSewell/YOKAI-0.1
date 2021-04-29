
#include "TextureManager.hpp"
TextureManager::TextureManager() {
    textureCount = 0;
}
TextureManager& TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}
std::shared_ptr<Texture> TextureManager::getTexture(unsigned int textureID)
{
    return textures.at(textureID);
}
void TextureManager::unBindTexture(unsigned int textureID)
{
    textures.at(textureID)->UnBind();
}
unsigned int TextureManager::loadTexture(const std::string &textureName)
{
    textures.emplace(textureCount,Texture::Create(textureName));
    textureCount++;
    return(textureCount -1);
}
void TextureManager::replaceTexture(size_t slot, const std::string &newTexturePath)
{
    textures.at(slot) = Texture::Create(newTexturePath);
}