//
// Created by Charlie Sewell on 10/03/2021.
//
#include "View/Renderer/Renderer.hpp"
//Initialises the selected runtime Render API
std::shared_ptr<RenderAPI> Renderer::renderApi = RenderAPI::Create();

void Renderer::Init() {
    renderApi->Init();

}
void Renderer::Draw(VertexArrayBuffer& VAO,size_t indiceSize){
    renderApi->Draw(VAO,indiceSize);
}
void Renderer::ToggleWireFrame() {
    renderApi->ToggleWireFrame();
}
void Renderer::Clear() {
    renderApi->Clear();
}
void Renderer::DeInit() {
    renderApi->DeInit();
}
