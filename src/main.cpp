#include "eternion/eternion.h"

int main(void)
{
    Quat rotX = et_genQuaternion(et_dToR(90.0f), 1, 0, 0);

    Quat vector = {0, 3, 4, 5};

    Quat rotated = et_rotateQuaternion(vector, rotX);

    et_printQuaternion(vector);
    et_printQuaternion(rotated);
    return 0;
}