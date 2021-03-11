#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>

#include <glm/gtc/type_ptr.hpp>
#include "Controller/Yokai.hpp"
#include "Model/ObjectLoading/Model.hpp"


#include "Controller/Factory/TerrainFactory.hpp"
#include "View/Camera.hpp"


Camera camera;
bool firstMouse = true;     // will be static memeber of input class
double lastX = 400;         //screen currently hard coded at 800, 600
double lastY = 300;
double yaw = -90.0f;
double pitch = 0.f;
bool isPressed = true;
//move to input class
void processKeyboard(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    float movementSpeed = 0.02f; // delete later - for testing
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
    if(glfwGetKey(window,GLFW_KEY_M) == GLFW_PRESS){
        if(isPressed){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            isPressed = false;
        }
        else {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            isPressed = true;
        }
    }
    
}

void error_callback(int error, const char* description)
{
    std::cout << "Error:"<< error << " "<< description<<  std::endl;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
void processMouse(GLFWwindow* window, double xpos, double ypos)
{
    if(isPressed) {
        if (firstMouse) {
            lastX      = xpos;
            lastY      = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = ypos - lastY;
        lastX         = xpos;
        lastY         = ypos;

        float sensitivity = 0.05f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch -= yoffset;

        // stops bad weird camera movement
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x    = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y    = sin(glm::radians(pitch));
        direction.z    = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        camera.m_front = glm::normalize(direction);
    }
}

int main() {
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

    Shader testShader("content/Shaders/vertexShader.vert","content/Shaders/testShader.frag");
    Shader modelShader("content/Shaders/vertexShader.vert","content/Shaders/fragmentShader.frag");
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, processMouse);     // move to input engine

    Model testModel("content/Models/pine.fbx");
    Chunk testChunk;
    Chunk testChunk2;
    TerrainFactory::getInstance().Init();
    TerrainFactory::getInstance().SetupChunk(testChunk,0,0,100);
    TerrainFactory::getInstance().SetupChunk(testChunk2,0,100,100);



    //THIS IS ALL TEST CODE AND SUBJECT TO CHANGE DO NOT ADD RENDERING FUNCTIONS HERE

    while (!glfwWindowShouldClose(window))
    {
        //will be moved to input engine later
        processKeyboard(window);
        Renderer::Clear();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10000.0f);
        glm::mat4 view = camera.getViewMatrix();

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

        testModel.Draw(modelShader);

        Renderer::ToggleWireFrame();
        testChunk.DrawChunk(testShader);
        testChunk2.DrawChunk(testShader);
        Renderer::ToggleWireFrame();


        /* Poll for and process events  NEEDS TO BE ABSTRACTED*/
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
