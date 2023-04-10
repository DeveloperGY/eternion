#include "eternion.h"

void et_printQuaternion(Quat q)
{
    printf("q: %f + %fi + %fj + %fk\n", q.w, q.i, q.j, q.k);
    return;
}

float et_dToR(float a)
{
    return a * (M_PI/180.0f);
}

Quat et_genQuaternion(float a, float x, float y, float z)
{
    // Half of angle measure because of quaternion magic doubling the angle when applied
    float ha = a/2.0f;

    // precomputation
    float sinha = sinf(ha);
    float cosha = cosf(ha);

    Quat q;

    q.w = cosha;
    q.i = sinha * x;
    q.j = sinha * y;
    q.k = sinha * z;

    return q;
}

Quat et_mulQuaternion(Quat q, Quat r)
{
    Quat result;

    // derived from distributive property and simplifying

    result.w = (q.w*r.w) - (q.i*r.i) - (q.j*r.j) - (q.k*r.k);
    result.i = (q.w*r.i) + (q.i*r.w) + (q.j*r.k) - (q.k*r.j);
    result.j = (q.w*r.j) - (q.i*r.k) + (q.j*r.w) + (q.k*r.i);
    result.k = (q.w*r.k) + (q.i*r.j) - (q.j*r.i) + (q.k*r.w);

    return result;
}

Quat et_conjugateQuaternion(Quat q)
{
    Quat result = {q.w, -q.i, -q.j, -q.k};

    return result;
}

float et_norm(Quat q)
{
    return sqrtf(powf(q.w, 2.0f) + powf(q.i, 2.0f) + powf(q.j, 2.0f) + powf(q.k, 2.0f));
}

Quat et_normalizeQuaternion(Quat q)
{
    float norm = et_norm(q);

    Quat result;

    result.w = q.w/norm;
    result.i = q.i/norm;
    result.j = q.j/norm;
    result.k = q.k/norm;

    return result;
}

Quat et_inverseQuaternion(Quat q)
{
    float norm = et_norm(q);
    float norm_sq = powf(norm, 2.0f);
    Quat conj = et_conjugateQuaternion(q);

    Quat result;

    result.w = conj.w/norm_sq;
    result.i = conj.i/norm_sq;
    result.j = conj.j/norm_sq;
    result.k = conj.k/norm_sq;

    return result;
}

Quat et_rotateQuaternion(Quat q, Quat r)
{
    // first step
    Quat first = et_mulQuaternion(r, q);

    // second step
    Quat result = et_mulQuaternion(first, et_inverseQuaternion(r));

    return result;
}