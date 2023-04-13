#include "eternion/eternion.h"

int main(void)
{
    et_Quat rotX = et_genQuaternion(et_dToR(90.0f), et_genVec3f(1, 0, 0));

    et_Vec3f vector = et_genVec3f(3, 4, 5);

    et_Vec3f rotated = et_rotateVec3f(vector, rotX);

    et_printVec3f(vector);
    et_printVec3f(rotated);
    return 0;
}