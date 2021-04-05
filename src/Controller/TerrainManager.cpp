//
// Created by charl on 4/03/2021.
//

#include "TerrainManager.hpp"

void TerrainManager::Init() {
    TerrainFactory::getInstance().Init();
    chunkSize = 100;
    maxKey = floor(TerrainFactory::getInstance().getTerrainSize()/100);
    CreateTerrain();
    terrainShader = std::shared_ptr<Shader>(new Shader("content/Shaders/terrainVertex.vert","content/Shaders/terrainFragment.frag"));
    terrainShader->setVec3("lightColor",glm::vec3(1.0,1.0,1.0));
    terrainShader->setVec3("lightPos",glm::vec3(maxKey*chunkSize/2,200.0,maxKey*chunkSize/2));
}
void TerrainManager::CreateTerrain() {
    for( int x =0; x < maxKey;x++){
        for( int y =0; y < maxKey;y++){
            std::pair<int,int> key(x,y);
            chunks.emplace(key,TerrainFactory::getInstance().SetupChunk(x*100,y*100,100));
        }
    }

}
void TerrainManager::Draw(glm::vec3 viewpos) {
    terrainShader->setVec3("viewpos",viewpos);
    for( int x =0; x < maxKey;x++) {
        for( int y =0; y < maxKey;y++){
            std::pair<int, int> key(x, y);
            chunks.at(key).DrawChunk((Shader &)terrainShader);
        }
    }
}
