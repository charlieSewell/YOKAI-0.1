#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>

#include <glm/gtc/type_ptr.hpp>
#include "Controller/Yokai.hpp"
#include "Model/ObjectLoading/Model.hpp"

#include "Model/Chunk.hpp"
#include "Controller/Factory/TerrainFactory.hpp"
#include "View/Camera.hpp"


Camera camera;
bool firstMouse = true;     // will be static memeber of input class
double lastX = 400;         //screen currently hard coded at 800, 600
double lastY = 300;
double yaw = -90.0f;
double pitch = 0.f;

//move to input class
void processKeyboard(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    float movementSpeed = 0.1f; // delete later - for testing
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        movementSpeed *= 3;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.m_position += movementSpeed * camera.m_front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.m_position -= movementSpeed * camera.m_front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.m_position -= glm::normalize(glm::cross(camera.m_front, camera.m_up)) * movementSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.m_position += glm::normalize(glm::cross(camera.m_front, camera.m_up)) * movementSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.m_position += movementSpeed * camera.m_up;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        camera.m_position -= movementSpeed * camera.m_up;
    
}

void processMouse(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse) 
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch -= yoffset;

    //stops bad weird camera movement
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera.m_front = glm::normalize(direction);

}

int main() {
    auto &engine = Yokai::getInstance();
    engine.renderer.Init();

    Shader testShader("content/Shaders/vertexShader.vert","content/Shaders/testShader.frag");
    glfwSetInputMode(engine.renderer.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(engine.renderer.window, processMouse);     // move to input engine

    Model testModel("content/Models/pine.fbx");
    Chunk testChunk;
    TerrainFactory::getInstance().Init();
    TerrainFactory::getInstance().SetupChunk(testChunk,100);
    engine.renderer.ToggleWireFrame();




    //THIS IS ALL TEST CODE AND SUBJECT TO CHANGE DO NOT ADD RENDERING FUNCTIONS HERE

    while (!glfwWindowShouldClose(engine.renderer.window))
    {
        //will be moved to input engine later
        processKeyboard(engine.renderer.window);        

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        testShader.useShader();

        // view/projection transformations

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
        glm::mat4 view = camera.getViewMatrix();
        testShader.setMat4("projection", projection);
        testShader.setMat4("view", view);
        testShader.setVec3("objectColor", glm::vec3(0.0f, 1.0f, 0.31f));
        testShader.setVec3("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
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
