//
// Created by charl on 22/03/2021.
//

#include "RenderLayer.hpp"
void RenderLayer::Init() {
    TerrainFactory::getInstance().Init();
    TerrainFactory::getInstance().SetupChunk(testChunk,0,0,100);
    testShader = Shader("content/Shaders/vertexShader.vert","content/Shaders/testShader.frag");
    modelShader = Shader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");

}
void RenderLayer::Update() {
    Renderer::Clear();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
    glm::mat4 view = player.getViewMatrix();

    testShader.useShader();
    testShader.setMat4("projection", projection);
    testShader.setMat4("view", view);
    glm::mat4 model = glm::mat4(1.0f);
    testShader.setMat4("model", model);


    testShader.setVec3("objectColor", glm::vec3(0.0f, 1.0f, 0.31f));
    testShader.setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));

    modelShader.useShader();
    modelShader.setMat4("projection", projection);
    modelShader.setMat4("view", view);
    modelShader.setMat4("model", model);
    // render the loaded model

    Renderer::ToggleWireFrame();
    testChunk.DrawChunk(testShader);
    Renderer::ToggleWireFrame();


    /* Poll for and process events  NEEDS TO BE ABSTRACTED*/
    glfwSwapBuffers(window);
    glfwPollEvents();
}