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
} et_Quat;

typedef struct s_Vec3f
{
    float x;
    float y;
    float z;
} et_Vec3f;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Prints a quaternion to stdout
 * 
 * @param q Quaternion to be printed
*/
void et_printQuaternion(et_Quat q);

/**
 * @brief Prints a vector to stdout
 * 
 * @param v Quaternion to be printed
*/
void et_printVec3f(et_Vec3f v);

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
 * @param v The vector representing the axis of rotation
 * 
 * @return Quaternion representing the specified rotation
*/
et_Quat et_genQuaternion(float a, et_Vec3f v);

/**
 * @brief Generates a vector based on x, y, and z values
 * 
 * @param x The x portion of the vector
 * @param y The y portion of the vector
 * @param z The z portion of the vector
 * 
 * @return A vector representing the specified point
*/
et_Vec3f et_genVec3f(float x, float y, float z);

/**
 * @brief Creates the quaternion form of a vector
 * 
 * @param v Vector to quaternize
 * 
 * @return Quaternion form of the specified vector
*/
et_Quat et_quaternize(et_Vec3f v);

/**
 * @brief Multiplies 2 quaternions together and returns the resulting quaternion
 * 
 * @param l The left quaternion
 * @param r The right quaternion
 * 
 * @return l * r
*/
et_Quat et_mulQuaternion(et_Quat l, et_Quat r);

/**
 * @brief Generates and returns the conjugate quaternion of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return q*
*/
et_Quat et_conjugateQuaternion(et_Quat q);

/**
 * @brief Generates and returns the norm of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return ||q||
*/
float et_normQuaternion(et_Quat q);

/**
 * @brief Generates and returns the norm of a specified vector
 * 
 * @param v The original vector
 * 
 * @return ||v||
*/
float et_normVec3f(et_Vec3f v);

/**
 * @brief Generates the normalized quaternion of the specified quaternion and returns it
 * 
 * @param q The specifcied quaternion
 * 
 * @return The normalized quaternion
*/
et_Quat et_normalizeQuaternion(et_Quat q);

/**
 * @brief Generates the normalized vector of the specified vector and returns it
 * 
 * @param v The specifcied vector
 * 
 * @return The normalized vector
*/
et_Vec3f et_normalizeVec3f(et_Vec3f v);

/**
 * @brief Generates and returns the inverse quaternion of a specified quaternion
 * 
 * @param q The original quaternion
 * 
 * @return q inverse 
*/
et_Quat et_inverseQuaternion(et_Quat q);

/**
 * @brief Applies a quaternion to a vector
 * 
 * @param v The vector to be rotated
 * @param q The quaternion defining the rotation
 * 
 * @return v rotated by q
*/
et_Vec3f et_rotateVec3f(et_Vec3f v, et_Quat q);

/**
 * @brief Translates a vector
 * 
 * @param v The vector to be translated
 * @param w The vector defining the translation
 * 
 * @return v translated by w
*/
et_Vec3f et_translateVec3f(et_Vec3f v, et_Vec3f t);

#ifdef __cplusplus
}
#endif