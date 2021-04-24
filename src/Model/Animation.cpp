//
// Created by charl on 22/04/2021.
//

#include "Animation.hpp"

#include <utility>
Animation::Animation() {

}
Animation::Animation(std::string name,std::map<std::string,BoneAnimation> animations, float duration, float TPS) {
    this->animations = std::move(animations);
    this->duration = duration;
    this->TPS = TPS;
    this->name = std::move(name);
}

unsigned int Animation::FindPosition(double currTime,const BoneAnimation* boneAnimation)
{
    for (unsigned int i = 0 ; i < boneAnimation->numPositions; i++) {
        if (currTime < boneAnimation->posKey[i + 1].first) {
            return i;
        }
    }
    return(0);
}
unsigned int Animation::FindRotation(double currTime,const BoneAnimation* boneAnimation)
{
    for (unsigned int i = 0 ; i < boneAnimation->numRotations; i++) {
        if (currTime < boneAnimation->rotKey[i + 1].first) {
            return i;
        }
    }
    return(0);
}
BoneAnimation* Animation::findBoneAnimation(std::string name)
{
    if (animations.count(name)) {
        return &animations.at(name);
    }
    return nullptr;
}