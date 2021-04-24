//
// Created by charl on 22/04/2021.
//

#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Model/Model.hpp"
#include <vector>
class Animator {
public:
    void BoneTransform(float TimeInSeconds);
    void ReadNodeHeirarchy(float AnimationTime, const Joint& node, const glm::mat4& ParentTransform);
    void attachModel(std::shared_ptr<Model> model){modelToAnimate = model;}
    std::vector<glm::mat4> finalTransforms;

  private:
    glm::quat CalcInterpolatedRotation(double AnimationTime, const BoneAnimation* pNodeAnim);
    glm::vec3 CalcInterpolatedPosition(double AnimationTime, const BoneAnimation* pNodeAnim);
    double currTime =0;
    bool ended = false;
    std::shared_ptr<Model> modelToAnimate;
    int count;
};
