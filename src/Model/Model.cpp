
#include "Model.hpp"
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GLFW/glfw3.h>


void Model::Draw(Shader &shader){
    shader.useShader();
    for(auto& mesh: meshes){
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.02f, 0.02f, 0.02f));	// it's a bit too big for our scene, so scale it down
        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(5.0f),
                            glm::vec3(0.0f, 1.0f, 0.0f));

        auto _scale       = glm::vec3{};
        auto _rotation    = glm::quat{};
        auto _translation = glm::vec3{};
        auto _skew        = glm::vec3{};
        auto _perspective = glm::vec4{};

        glm::decompose(mesh.getTransform(), _scale, _rotation, _translation, _skew, _perspective);

        model = glm::translate(model, _translation);
        model *= glm::mat4_cast(_rotation);
        model = glm::scale(model, _scale);

        shader.setMat4("model", model);
        mesh.Draw(shader);
    }
}


