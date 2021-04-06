//
// Created by charl on 2/03/2021.
//

#include "Yokai.hpp"
#include "DemoScene.hpp"
#include "Controller/Layer.hpp"
Yokai &Yokai::getInstance() 
{
    static Yokai instance;
    return instance;
}

void Yokai::Init() 
{
    registerClose();
    if(!window.Init()){
        return;
    }

    //EMS::Init();
    Renderer::Init();
    
    layers.push_back(new DemoScene());
    for(int i =0;i < layers.size(); i++){
        std::cout <<"test\n";
        layers[i]->Init();
    }
    GameObjectManager::init();


}
void Yokai::Run(){
    while(isRunning){
        Renderer::Clear();
        InputManagerGLFW::getInstance().processKeyboard(window.getWindow());
        InputManagerGLFW::getInstance().processMouse(window.getWindow());

        for(int i =0;i < layers.size(); i++){
            layers[i]->Update();
        }
        for(int i =0;i < layers.size(); i++){
            layers[i]->Draw();
        }
        window.endFrame();
    }
}
void Yokai::registerClose()
{
    auto close = [&]() {
        isRunning = false;
    };
    EMS::getInstance().add(InputEvent::close, close);
};
