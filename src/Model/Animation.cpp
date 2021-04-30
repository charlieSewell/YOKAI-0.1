//
// Created by charl on 22/04/2021.
//

#include "Animation.hpp"

#include <utility>
Animation::Animation() {

}
Animation::Animation(std::string name, std::map<std::string,Frame> frames, float duration, float TPS) 
{
    this->frames = std::move(frames);
    this->duration = duration;
    this->TPS = TPS;
    this->name = std::move(name);
}

unsigned int Animation::FindPosition(double currTime,const Frame* frame)
{
    for (unsigned int i = 0 ; i < frame->numPositions; i++)
    {
        if (currTime < frame->posKey[i + 1].first) 
        {
            return i;
        }
    }
    return(0);
}
unsigned int Animation::FindRotation(double currTime,const Frame* frame)
{
    for (unsigned int i = 0 ; i < frame->numRotations; i++)
    {
        if (currTime < frame->rotKey[i + 1].first) 
        {
            return i;
        }
    }
    return(0);
}
Frame* Animation::findFrame(const std::string& frameName)
{
    if (frames.count(frameName)) 
    {
        return &frames.at(frameName);
    }
    return nullptr;
}
