#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in ivec4 boneIDs;
layout (location = 4) in vec4 weights;


const int MAX_BONES = 100;
const int MAX_BONE_INFLUENCE = 4;
uniform mat4 boneMatrices[MAX_BONES];

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform bool isAnimated;
void main()
{

    mat4 BoneTransform = boneMatrices[boneIDs[0]] * weights[0];
    BoneTransform += boneMatrices[boneIDs[1]] * weights[1];
    BoneTransform += boneMatrices[boneIDs[2]] * weights[2];
    BoneTransform += boneMatrices[boneIDs[3]] * weights[3];
    vec4 PosL;
    if(isAnimated)
    {
        PosL = BoneTransform * vec4(aPos, 1.0);
    }
    else{
        PosL = vec4(aPos, 1.0);
    }

    TexCoords = aTexCoords;
    gl_Position = projection * view * model* PosL;
}