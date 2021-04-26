//
// Created by charl on 22/04/2021.
//

#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Model/Model.hpp"
#include <utility>
#include <vector>
class Animator {
    public:
        Animator() = default;
        Animator(std::shared_ptr<Model> model);
        void BoneTransform(float TimeInSeconds);
        void ReadNodeHeirarchy(float AnimationTime, const Node& node, const glm::mat4& ParentTransform);
        void addModel(std::shared_ptr<Model> model){modelToAnimate = std::move(model);}
        void setAnimation(std::string animationToSet){this->animation = std::move(animationToSet);}
        std::vector<glm::mat4> finalTransforms;

    private:
        glm::quat CalcInterpolatedRotation(double AnimationTime, const Frame* pNodeAnim);
        glm::vec3 CalcInterpolatedPosition(double AnimationTime, const Frame* pNodeAnim);
        float currTime =0;
        bool shouldEnd = false;
        std::string animation;
        std::shared_ptr<Model> modelToAnimate;

};
