#pragma once

#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#include <stdio.h>

typedef struct s_Quaternion
{
    float w;
    float i;
    float j;
    float k;
} Quat;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Prints a quaternion to stdout
 * 
 * @param q Quaternion to be printed
*/
void et_printQuaternion(Quat q);

/**
 * @brief Turns degrees into radians
 * 
 * @param a Angle in degrees
 * 
 * @return The angle measure in radians
*/
float et_dToR(float a);

/**
 * @brief Generates a quaternion based on a vector of rotation and rotation angle
 * 
 * @param a The rotation angle in radians
 * @param x The x portion of the vector of rotation
 * @param y The y portion of the vector of rotation
 * @param z The z portion of the vector of rotation
 * 
 * @return Quaternion representing the specified rotation
*/
Quat et_genQuaternion(float a, float x, float y, float z);

/**
 * @brief Multiplies 2 quaternions together and returns the resulting quaternion
 * 
 * @param q The right quaternion
 * @param r The left quaternion
 * 
 * @return q * r
*/
Quat et_mulQuaternion(Quat q, Quat r);

/**
 * @brief Generates and returns the conjugate quaternion of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return q*
*/
Quat et_conjugateQuaternion(Quat q);

/**
 * @brief Generates and returns the norm of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return ||q||
*/
float et_norm(Quat q);

/**
 * @brief Generates the normalized quaternion of the specified quaternion and returns it
 * 
 * @param q The specifcied quaternion
 * 
 * @return The normalized quaternion
*/
Quat et_normalizeQuaternion(Quat q);

/**
 * @brief Generates and returns the inverse quaternion of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return q inverse 
*/
Quat et_inverseQuaternion(Quat q);

/**
 * @brief Applies a quaternion to another quaternion
 * 
 * @param q The quaternion to be rotated
 * @param r The rotation quaternion
 * 
 * @return q rotated by r
*/
Quat et_rotateQuaternion(Quat q, Quat r);

#ifdef __cplusplus
}
#endif