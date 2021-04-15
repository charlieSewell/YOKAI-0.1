
#include "Model.hpp"
Model::Model(std::vector<Mesh> meshes)
{
    this->meshes = meshes;

}
Model::Model(std::vector<Mesh> meshes,std::vector<Bone> bones,Joint rootJoint)
{
    this->meshes = meshes;
    this->bones = bones;
    this->rootJoint = rootJoint;
}
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


