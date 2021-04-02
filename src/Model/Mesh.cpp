//
// Created by Charlie Sewell on 12/01/2021.
//
#include "Mesh.hpp"
Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices, const std::vector<ModelTexture> &textures, glm::mat4 &transform){
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    this->transform = transform;
}
void Mesh::SetupMesh(){
    VAO = VertexArrayBuffer::Create(this->vertices,this->indices);
}
 const void Mesh::Draw(Shader &shader){
     unsigned int diffuseNr = 1;
     unsigned int specularNr = 1;
     for(unsigned int i = 0; i < textures.size(); i++){
         textures[i].texture->Bind(i);
         std::string number;
         std::string name = textures[i].type;
         if(name == "texture_diffuse")
             number = std::to_string(diffuseNr++);
         else if(name == "texture_specular")
             number = std::to_string(specularNr++);

         shader.setFloat(("material." + name + number).c_str(), i);
     }
     // draw mesh
     Renderer::Draw(*VAO,indices.size());
}