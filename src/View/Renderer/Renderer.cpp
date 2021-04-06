//
// Created by Charlie Sewell on 10/03/2021.
//
#include "View/Renderer/Renderer.hpp"
//Initialises the selected runtime Render API
std::shared_ptr<RenderAPI> Renderer::renderApi = RenderAPI::Create();

void Renderer::Init() 
{
	registerToggleWireframe();
    renderApi->Init();
}

void Renderer::Draw(Shader &shader,VertexArrayBuffer& VAO,size_t indiceSize)
{
    renderApi->Draw(shader,VAO,indiceSize);
}

void Renderer::registerToggleWireframe()
{
	static bool wireFrameActive = false;

	auto toggleWireFrameReleased = [&]()
	{
		if (wireFrameActive)
			wireFrameActive = false;
	};
	EMS::getInstance().add(InputEvent::toggleWireFrameReleased, toggleWireFrameReleased);

	auto toggleWireFramePressed = [&]()
	{
		if (!wireFrameActive)
		{
			renderApi->ToggleWireFrame();
			wireFrameActive = true;
		}
	};
	EMS::getInstance().add(InputEvent::toggleWireFramePressed, toggleWireFramePressed);
}

void Renderer::Clear() 
{
    renderApi->Clear();
}

void Renderer::DeInit() 
{
    renderApi->DeInit();
}
