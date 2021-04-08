//
// Created by Charlie Sewell on 7/04/2021.
//

#include "SplashScreen.hpp"
#include "Controller/Yokai.hpp"
#include "Controller/EventManager.hpp"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
SplashScreen::SplashScreen(std::string texturePath)
{
    texture = Texture::Create(texturePath);
    setupPanel();
    setupShader();

}
void SplashScreen::setTexture(std::string texturePath)
{
    texture =  Texture::Create(texturePath);
}
void SplashScreen::draw()
{
    glDisable(GL_DEPTH_TEST);
    splashShader->useShader();
    texture->Bind(1);
    Renderer::Draw(*vao,6);
    glEnable(GL_DEPTH_TEST);
}
void SplashScreen::setupShader(){
    splashShader = new Shader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");
    splashShader->useShader();
    splashShader->setMat4("model",glm::mat4(1.0));
    splashShader->setMat4("view",glm::mat4(1.0));
    splashShader->setMat4("projection",glm::ortho(0.0f, (float)1920, (float)1080, 0.0f));
    splashShader->setInt("texture_diffuse1", 1);
}
void SplashScreen::setupPanel(){
    std::vector<Vertex> verts;
    verts.resize(4);
    verts[0].position= glm::vec3(400,200,1);
    verts[1].position= glm::vec3(1520,200,1);
    verts[2].position= glm::vec3(400,800,1);
    verts[3].position= glm::vec3(1520,800,1);
    verts[0].textureCoords= glm::vec2(0,0);
    verts[1].textureCoords= glm::vec2(1,0);
    verts[2].textureCoords= glm::vec2(0,1);
    verts[3].textureCoords= glm::vec2(1,1);
    std::vector<unsigned int> indices = {0,1,2,1,3,2};
    vao = VertexArrayBuffer::Create(verts,indices);
}
void SplashScreen::setActive() {
    active = true;
}
void SplashScreen::setInactive() {
    active = false;
}
bool SplashScreen::isActive() {
    return active;
}