#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>

#include <glm/gtc/type_ptr.hpp>

#include "Controller/Yokai.hpp"
#include "Model/ObjectLoading/Model.hpp"

#include "Model/Chunk.hpp"
#include "Controller/Factory/TerrainFactory.hpp"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
int main() {
    auto &engine = Yokai::getInstance();
    engine.renderer.Init();

    Shader testShader("content/Shaders/vertexShader.vert","content/Shaders/testShader.frag");
    Model testModel("content/Models/pine.fbx");
    Chunk testChunk;
    TerrainFactory::getInstance().SetupChunk(testChunk,100);
    engine.renderer.ToggleWireFrame();




    //THIS IS ALL TEST CODE AND SUBJECT TO CHANGE DO NOT ADD RENDERING FUNCTIONS HERE




    while (!glfwWindowShouldClose(engine.renderer.window))
    {
        processInput(engine.renderer.window);

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        testShader.useShader();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(
            glm::vec3(0,20,0),
            glm::vec3(30,10,30),
            glm::vec3(0,1,0)
            );
        testShader.setMat4("projection", projection);
        testShader.setMat4("view", view);
        testShader.setVec3("objectColor", glm::vec3(0.0f, 1.0f, 0.31f));
        testShader.setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        //model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f)); // translate it down so it's at the center of the scene
        //model = glm::rotate(model,glm::radians(-90.0f),glm::vec3(1.0f,0.0f,0.0f));
        //model = glm::rotate(model,glm::radians(-90.0f),glm::vec3(0.0f,0.0f,1.0f));
        //model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
        testShader.setMat4("model", model);
        //testModel.Draw(testShader);
        testChunk.DrawChunk(testShader);
        glfwSwapBuffers(engine.renderer.window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(engine.renderer.window);
    glfwTerminate();
    return 0;
}
