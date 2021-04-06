//
// Created by charl on 3/03/2021.
//

#include "AssimpMaths.hpp"

glm::mat4 Maths::ai4x4ToGLM(const aiMatrix4x4 &src)
{
    glm::mat4 dest;
    dest[0][0] = src.a1; dest[1][0] = src.a2; dest[2][0] = src.a3; dest[3][0] = src.a4;
    dest[0][1] = src.b1; dest[1][1] = src.b2; dest[2][1] = src.b3; dest[3][1] = src.b4;
    dest[0][2] = src.c1; dest[1][2] = src.c2; dest[2][2] = src.c3; dest[3][2] = src.c4;
    dest[0][3] = src.d1; dest[1][3] = src.d2; dest[2][3] = src.d3; dest[3][3] = src.d4;
    return dest;
}