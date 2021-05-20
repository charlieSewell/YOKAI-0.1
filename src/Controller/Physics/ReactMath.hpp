#pragma once
#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
class ReactMath{
    public:
        static reactphysics3d::Quaternion glmQuatToR3pd(glm::quat& quat);
        static glm::quat r3pdQuatToGlm(reactphysics3d::Quaternion& quat);
        static reactphysics3d::Vector3 glmVecToR3pd(glm::vec3& vec);
        static glm::vec3 r3pdVecToGlm(reactphysics3d::Vector3& vec);
};