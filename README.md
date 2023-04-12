# Eternion
A basic quaternion based 3D transformation library

## Example
```c++
#include <eternion.h>
#include <stdio.h>

int main(void)
{
  Quat vec = {0, 3, 4, 5}; // Point at (3, 4, 5)
  
  // generates a quaternion that represents a 90 degree rotation around the x axis
  Quat rotX90 = et_genQuaternion(et_dToR(90), 1, 0, 0);
  
  printf("Start: ");
  et_printQuaternion(vec);
  
  vec = et_rotateQuaternion(vec, rotX90); // rotate vec by the rotation specified by rotX90
  
  printf("End: ");
  et_printQuaternion(vec);

  return 0;
}
```
