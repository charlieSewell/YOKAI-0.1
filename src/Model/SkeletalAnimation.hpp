#pragma once
#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <map>
struct Frame {
    unsigned int numPositions = 0;
    unsigned int numRotations = 0;
    std::vector<std::pair<double, glm::vec3>> position = {};
    std::vector<std::pair<double, glm::quat>> rotation = {};
};
class SkeletalAnimation {
    public:
        SkeletalAnimation();
        SkeletalAnimation(std::string name, std::map<std::string,Frame> animations, float duration, float TPS);
        unsigned int FindRotation(double currTime, const Frame* frame);
        unsigned int FindPosition(double currTime, const Frame* frame);
        Frame* findFrame(const std::string& frameName);
        double getTPS(){return TPS;}
        double getDuration(){return duration;}
        std::string getName(){return name;}
    private:
        std::map<std::string,Frame> frames;
        double duration;
        double TPS;
        std::string name;

};