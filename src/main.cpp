#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>

#include "Controller/EventManager.h"


#include "Controller/Yokai.hpp"
#include "View/Camera.hpp"
#include "Controller/InputManagerGLFW.hpp"
#include "Model/Player.hpp"


void error_callback(int error, const char* description)
{
    std::cout << "Error:"<< error << " "<< description<<  std::endl;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int main() {
    auto &engine = Yokai::getInstance();
    engine.Init();
    engine.Run();
    GLFWwindow* window;
    if (!glfwInit()){
        return 0;
    }
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);
    if (!window){
        return 0;
    }
    glfwMakeContextCurrent(window);

    auto &engine = Yokai::getInstance();
    engine.Init();

    //Shader testShader("content/Shaders/vertexShader.vert","content/Shaders/testShader.frag");
    Shader testShader("content/Shaders/terrainVertex.vert","content/Shaders/terrainFragment.frag");
    Shader modelShader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //glfwSetCursorPosCallback(window, InputManagerGLFW::processMouse);     // move to input engine
    Model testModel("content/Models/pine.fbx");
    Chunk testChunk;
    Chunk testChunk2;
    TerrainFactory::getInstance().Init();
    TerrainFactory::getInstance().SetupChunk(testChunk,0,0,512);
    TerrainFactory::getInstance().SetupChunk(testChunk2,0,100,100);

    //THIS IS ALL TEST CODE AND SUBJECT TO CHANGE DO NOT ADD RENDERING FUNCTIONS HERE
    while (!glfwWindowShouldClose(window))
    {
        //will be moved to input engine later
		    InputManagerGLFW::getInstance().processKeyboard(window);
		    InputManagerGLFW::getInstance().processMouse(window);
        Renderer::Clear();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
        glm::mat4 view = player.getViewMatrix();

        testShader.useShader();
        testShader.setMat4("projection", projection);
        testShader.setMat4("view", view);
        glm::mat4 model = glm::mat4(1.0f);
        testShader.setMat4("model", model);
        testShader.setVec3("viewPos", player.getPos());


        //testShader.setVec3("objectColor", glm::vec3(0.0f, 1.0f, 0.31f));
        //testShader.setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));

        modelShader.useShader();
        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);
        modelShader.setMat4("model", model);
        // render the loaded model

        testModel.Draw(modelShader);
        //Renderer::ToggleWireFrame();
        testChunk.DrawChunk(testShader);
        //testChunk2.DrawChunk(testShader);
        //Renderer::ToggleWireFrame();


        /* Poll for and process events  NEEDS TO BE ABSTRACTED*/
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}