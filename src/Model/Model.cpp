
#include "Model.hpp"

#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Controller/EventManager.hpp"
void Model::Draw(Shader &shader, glm::mat4 transform) 
{
    shader.useShader();
    shader.setMat4("projection",EMS::getInstance().fire(RenderEvent::getPerspective));
    shader.setMat4("view",EMS::getInstance().fire(RenderEvent::getViewMatrix));
    for(auto& mesh: meshes)
    {
        glm::mat4 model(1.0);
        //multiply parent by child transform
        model = transform * mesh.getTransform();

        shader.setMat4("model", model);
        mesh.Draw(shader);
    }
}


