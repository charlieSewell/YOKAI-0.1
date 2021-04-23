//
// Created by charl on 22/04/2021.
//

#include "Animator.hpp"
void Animator::BoneTransform(float TimeInSeconds)
{
    finalTransforms.resize(modelToAnimate->getBonesSize());
    glm::mat4 identity(1.0);
    double TicksPerSecond = modelToAnimate->getAnimation("Working")->getTPS();
    float TimeInTicks = TimeInSeconds * TicksPerSecond;
    float AnimationTime = fmod(TimeInTicks, modelToAnimate->getAnimation("Working")->getDuration());

    ReadNodeHeirarchy(AnimationTime, modelToAnimate->getRootJoint(), identity);
    for (unsigned i = 0; i < animatedModel->numBones; i++) {
                finalTransforms[i] = modelToAnimate->bones[i].transform;
            }
}
void Animator::ReadNodeHeirarchy(float AnimationTime, const Joint& node, const glm::mat4& parentTransform)
{

    glm::mat4 nodeTransformation(node.transform);

    const auto* pNodeAnim = modelToAnimate->getAnimation("Working")->findBoneAnimation(node.name);

    if (pNodeAnim) {

        // Interpolate rotation and generate rotation transformation matrix
        glm::mat4 rotation = glm::mat4(CalcInterpolatedRotation(AnimationTime, pNodeAnim));

        // Interpolate translation and generate translation transformation matrix
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), CalcInterpolatedPosition(AnimationTime, pNodeAnim));

        // Combine the above transformations
        nodeTransformation = translation * rotation;
    }

    glm::mat4 GlobalTransformation = parentTransform * nodeTransformation;

    if (modelToAnimate->getBoneMap()->find(node.name) != modelToAnimate->getBoneMap()->end()) {
        unsigned int BoneIndex = modelToAnimate->getBoneMap()->at(node.name);
        modelToAnimate->bones[BoneIndex].transform = modelToAnimate->getGlobalInverseTransform() * GlobalTransformation *
                                                    modelToAnimate->bones[BoneIndex].offset;
    }

    for (unsigned int i = 0 ; i < node.childrenCount ; i++) {
        ReadNodeHeirarchy(AnimationTime, node.children[i], GlobalTransformation);
    }
}
glm::quat Animator::CalcInterpolatedRotation(double AnimationTime, const BoneAnimation* pNodeAnim)
{
    glm::quat rotation;
    // we need at least two values to interpolate...
    if (pNodeAnim->numRotations == 1) {
        rotation = pNodeAnim->rotKey[0].second;
        return rotation;
    }

    unsigned int RotationIndex = modelToAnimate->getAnimation("Working")->FindRotation(AnimationTime, pNodeAnim);
    unsigned int NextRotationIndex = (RotationIndex + 1);
    assert(NextRotationIndex < pNodeAnim->numRotations);
    float DeltaTime = pNodeAnim->rotKey[NextRotationIndex].first - pNodeAnim->rotKey[RotationIndex].first;
    float Factor = (AnimationTime - (float)pNodeAnim->rotKey[RotationIndex].first) / DeltaTime;

    const glm::quat& StartRotationQ = pNodeAnim->rotKey[RotationIndex].second;
    const glm::quat& EndRotationQ = pNodeAnim->rotKey[NextRotationIndex].second;
    rotation = glm::slerp(StartRotationQ, EndRotationQ, static_cast<float>(Factor));
    rotation = glm::normalize(rotation);
    return rotation;
}
glm::vec3 Animator::CalcInterpolatedPosition(double AnimationTime, const BoneAnimation *pNodeAnim) {
    glm::vec3 result;
    if (pNodeAnim->numPositions == 1) {
        result = pNodeAnim->posKey[0].second;
        return result;
    }

    unsigned PositionIndex = modelToAnimate->getAnimation("Working")->FindPosition(AnimationTime, pNodeAnim);
    unsigned NextPositionIndex = (PositionIndex + 1);
    assert(NextPositionIndex < pNodeAnim->numPositions);

    double DeltaTime = pNodeAnim->posKey[NextPositionIndex].first - pNodeAnim->posKey[PositionIndex].first;
    double Factor = (AnimationTime - pNodeAnim->posKey[PositionIndex].first) / DeltaTime;

    const glm::vec3& Start = pNodeAnim->posKey[PositionIndex].second;
    const glm::vec3& End = pNodeAnim->posKey[NextPositionIndex].second;
    glm::vec3 Delta = End - Start;
    result = Start + static_cast<float>(Factor) * Delta;
    return result;
}
