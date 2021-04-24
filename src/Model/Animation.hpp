//
// Created by charl on 22/04/2021.
//
#pragma once
#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <map>
struct BoneAnimation {
    int numPositions = 0;
    int numRotations = 0;
    std::vector<std::pair<double, glm::vec3>> posKey = {};
    std::vector<std::pair<double, glm::quat>> rotKey = {};
};
class Animation {
    public:
        Animation();
        Animation(std::string name,std::map<std::string,BoneAnimation> animations,float duration,float TPS);
        unsigned int FindRotation(double currTime, const BoneAnimation* boneAnimation);
        unsigned int FindPosition(double currTime, const BoneAnimation* boneAnimation);
        BoneAnimation* findBoneAnimation(std::string name);
        double getTPS(){return TPS;}
        double getDuration(){return duration;}
        std::string getName(){return name;}
    private:
        std::map<std::string,BoneAnimation> animations;
        double duration;
        double TPS;
        std::string name;

};
