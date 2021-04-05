
#include "Model.hpp"
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GLFW/glfw3.h>


void Model::Draw(Shader &shader, glm::vec3 position) {
    shader.useShader();
    for(auto& mesh: meshes){
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position); //glm::vec3(0.0f, 0.0f, -5.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.02f, 0.02f, 0.02f));	// it's a bit too big for our scene, so scale it down
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(5.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        //multiply parent by child transform
        model = model * mesh.getTransform();

        shader.setMat4("model", model);
        mesh.Draw(shader);
    }
}


