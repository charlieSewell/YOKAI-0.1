//
// Created by Charlie Sewell on 10/03/2021.
//

#ifndef ICT397_GAME_ENGINE_RENDERAPI_HPP
#define ICT397_GAME_ENGINE_RENDERAPI_HPP

#include "View/Renderer/DataTypes.hpp"
#include "View/Renderer/Shader.hpp"
class RenderAPI {
  public:
    virtual ~RenderAPI()= default;
    virtual void Init()=0;
    virtual void DeInit()=0;
    virtual void ToggleWireFrame()=0;
    virtual void Draw(Shader &shader,VertexArrayBuffer& VAO,size_t indiceSize) = 0;
    virtual void Clear() =0;
    static std::shared_ptr<RenderAPI> Create();
};

#endif // ICT397_GAME_ENGINE_RENDERAPI_HPP
