//
// Created by charl on 22/04/2021.
//
#pragma once
#include <glm/gtc/quaternion.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <map>
struct Frame {
    int numPositions = 0;
    int numRotations = 0;
    std::vector<std::pair<double, glm::vec3>> posKey = {};
    std::vector<std::pair<double, glm::quat>> rotKey = {};
};
class Animation {
    public:
        Animation();
        Animation(std::string name, std::map<std::string,Frame> animations, float duration, float TPS);
        unsigned int FindRotation(double currTime, const Frame* frame);
        unsigned int FindPosition(double currTime, const Frame* frame);
        Frame* findFrame(std::string name);
        double getTPS(){return TPS;}
        double getDuration(){return duration;}
        std::string getName(){return name;}
    private:
        std::map<std::string,Frame> frames;
        double duration;
        double TPS;
        std::string name;

};
