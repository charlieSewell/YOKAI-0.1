#include "GameAssetFactory.hpp"

Asset *GameAssetFactory::Create(std::string type) 
{
    if (type == "terrain") 
    {
        //return new TerrainFactory;
    } 
    else if (type == "model") 
    {
        //return new ModelManager;
    } 
    else if (type == "player") 
    {
        return new Player;
    } 
    else 
    {
        return nullptr;
    }
}
