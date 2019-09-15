#ifndef __MATH__H
#define __MATH__H

float sigmoid(float r) {
    return 1/(exp(r) + 1);
}

vector sigmoid(vector r) {
    return vector (
        sigmoid(r[0]),
        sigmoid(r[1]),
        sigmoid(r[2])
    );
}

matrix matrix_from_euler (vector euler) {
    float cosx, sinx, cosy, siny, cosz, sinz;
    sincos(euler[0], sinx, cosx);
    sincos(euler[1], siny, cosy);
    sincos(euler[2], sinz, cosz);
    return matrix(
        cosy*cosz,  -cosx*sinz-sinx*siny*cosz,  sinx*sinz-cosx*siny*cosz,   0,
        cosy*sinz,  cosx*cosz-sinx*siny*sinz,   -cosx*siny*sinz-sinx*cosz,  0,
        siny,       sinx*cosy,                  cosx*cosy,                  0,
        0,          0,                          0,                          1
    );
}
#endif
