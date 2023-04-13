# Eternion
A basic quaternion based 3D transformation library

## Installation
Compile the c code in src/eternion into a library and link with it, or just compile the source files along with your project. Either way you will also need to include eternion.h from src/eternion as well. It is not recommended to use the precompiled library as it was compiled on arch linux, meaning that the version of glibc it was compiled with is probably higher than what you have on your system.

## Documentaion
Checkout the wiki tab of the repo for docs on the different parts of the library, and feel free to scour the source code all you want!

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
