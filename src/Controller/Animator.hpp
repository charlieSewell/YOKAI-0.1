#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/random.hpp>
#include "Model/Model.hpp"
#include "Controller/LuaManager.hpp"
#include <utility>
#include <vector>
class Animator{
    public:
        Animator() = default;
        Animator(std::shared_ptr<Model> model);
        void BoneTransform(float TimeInSeconds);
        void addModel(std::shared_ptr<Model> model){modelToAnimate = std::move(model);}
        void setAnimation(std::string animationToSet);
        void startAnimation(){shouldEnd = false;}
        void endAnimation(){shouldEnd = true;}
        std::vector<glm::mat4> finalTransforms;
		static void registerClass();

    private:
        void ReadNodeHeirarchy(float AnimationTime, const Node& node, const glm::mat4& ParentTransform);
        glm::quat CalcInterpolatedRotation(double AnimationTime, const Frame* pNodeAnim);
        glm::vec3 CalcInterpolatedPosition(double AnimationTime, const Frame* pNodeAnim);
        float currTime;
        bool shouldEnd = false;
        std::string animation;
        std::shared_ptr<Model> modelToAnimate;

};
