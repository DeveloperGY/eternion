#include "eternion.h"

void et_printQuaternion(et_Quat q)
{
    printf("q: %f + %fi + %fj + %fk\n", q.w, q.i, q.j, q.k);
    return;
}

void et_printVec3f(et_Vec3f v)
{
    printf("v: (%f, %f, %f)\n", v.x, v.y, v.z);
    return;
}

float et_dToR(float a)
{
    return a * (M_PI/180.0f);
}

et_Quat et_genQuaternion(float a, et_Vec3f v)
{
    // Half of angle measure because of quaternion magic doubling the angle when applied
    float ha = a/2.0f;

    // precomputation
    float sinha = sinf(ha);
    float cosha = cosf(ha);

    et_Quat q;

    q.w = cosha;
    q.i = sinha * v.x;
    q.j = sinha * v.y;
    q.k = sinha * v.z;

    return q;
}

et_Vec3f et_genVec3f(float x, float y, float z)
{
    et_Vec3f v;

    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

et_Quat et_quaternize(et_Vec3f v)
{
    et_Quat result = {0, v.x, v.y, v.z};

    return result;
}

et_Quat et_mulQuaternion(et_Quat l, et_Quat r)
{
    et_Quat result;

    // derived from distributive property and simplifying

    result.w = (l.w*r.w) - (l.i*r.i) - (l.j*r.j) - (l.k*r.k);
    result.i = (l.w*r.i) + (l.i*r.w) + (l.j*r.k) - (l.k*r.j);
    result.j = (l.w*r.j) - (l.i*r.k) + (l.j*r.w) + (l.k*r.i);
    result.k = (l.w*r.k) + (l.i*r.j) - (l.j*r.i) + (l.k*r.w);

    return result;
}

et_Quat et_conjugateQuaternion(et_Quat q)
{
    et_Quat result = {q.w, -q.i, -q.j, -q.k};

    return result;
}

float et_normQuaternion(et_Quat q)
{
    return sqrtf(powf(q.w, 2.0f) + powf(q.i, 2.0f) + powf(q.j, 2.0f) + powf(q.k, 2.0f));
}

float et_normVec3f(et_Vec3f v)
{
    return sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f) + powf(v.z, 2.0f));
}

et_Quat et_normalizeQuaternion(et_Quat q)
{
    float norm = et_normQuaternion(q);

    et_Quat result;

    result.w = q.w/norm;
    result.i = q.i/norm;
    result.j = q.j/norm;
    result.k = q.k/norm;

    return result;
}

et_Vec3f et_normalizeVec3f(et_Vec3f v)
{
    float norm = et_normVec3f(v);

    et_Vec3f result;

    result.x = v.x/norm;
    result.y = v.y/norm;
    result.z = v.z/norm;

    return result;
}

et_Quat et_inverseQuaternion(et_Quat q)
{
    float norm = et_normQuaternion(q);
    float norm_sq = powf(norm, 2.0f);
    et_Quat conj = et_conjugateQuaternion(q);

    et_Quat result;

    result.w = conj.w/norm_sq;
    result.i = conj.i/norm_sq;
    result.j = conj.j/norm_sq;
    result.k = conj.k/norm_sq;

    return result;
}

et_Vec3f et_rotateVec3f(et_Vec3f v, et_Quat q)
{
    et_Quat q_v = et_quaternize(v); // quaternionize vector for math

    // first step
    et_Quat first = et_mulQuaternion(q, q_v);

    // second step
    et_Quat second = et_mulQuaternion(first, et_inverseQuaternion(q));

    et_Vec3f result = et_genVec3f(second.i, second.j, second.k);

    return result;
}

et_Vec3f et_translateVec3f(et_Vec3f v, et_Vec3f t)
{
    et_Vec3f result;

    result.x = v.x + t.x;
    result.y = v.y + t.y;
    result.z = v.z + t.z;

    return result;
}

et_Vec3f et_scaleVec3f(et_Vec3f v, float s)
{
    et_Vec3f result;

    result.x = v.x * s;
    result.y = v.y * s;
    result.z = v.z * s;

    return result;
}