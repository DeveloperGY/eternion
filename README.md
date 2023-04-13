# Eternion
A basic quaternion based 3D transformation library

## Example
```c++
#include <eternion.h>
#include <stdio.h>

int main(void)
{
  et_Vec3f vec = et_genVec3f(3, 4, 5);
  
  // generates a quaternion that represents a 90 degree rotation around the x axis
  Quat rotX90 = et_genQuaternion(et_dToR(90), et_genVec3f(1, 0, 0));
  
  printf("Start: ");
  et_printVec3f(vec);
  
  vec = et_rotateVec3f(vec, rotX90); // rotate vec by the rotation specified by rotX90
  
  printf("End: ");
  et_printVec3f(vec);

  return 0;
}
```
