#ifndef VEC2_H
#define VEC2_H

// Two dimensional vectors
struct Vec2 {
    float arr[2];
};

Vec2 __operator__add__ (Vec2 a, Vec2 b)
{
    float arr[2] = {
     a.arr[0] + b.arr[0],
     a.arr[1] + b.arr[1]
    };
    Vec2 res = { arr };
    return res;
    //return { arr };
}

Vec2 __operator__sub__ (Vec2 a, Vec2 b)
{
    float arr[2] = {
        a.arr[0] - b.arr[0],
        a.arr[1] - b.arr[1]
    };
    Vec2 res = { arr };
    return res;
}

Vec2 __operator__neg__ (Vec2 a)
{
    float arr[2] = {
        - a.arr[0],
        - a.arr[1]
    };
    Vec2 res = { arr };
    return res;
}

// Matrices for two dimensions

/* Indices of matrix
0   1
2   3
*/
struct Matr2 {
    float arr[4];
};

Matr2 __operator__mul__ (Matr2 a, Matr2 b)
{
    float arr[4] = {
        a.arr[0]*b.arr[0] + a.arr[1]*b.arr[2],
        a.arr[0]*b.arr[1] + a.arr[1]*b.arr[3],

        a.arr[2]*b.arr[0] + a.arr[3]*b.arr[2],
        a.arr[2]*b.arr[1] + a.arr[3]*b.arr[3]
    };
    Matr2 res = { arr };
    return res;
}

Vec2 transform (Matr2 m, Vec2 x)
{
    float arr[2] = {
        m.arr[0]*x.arr[0]+m.arr[1]*x.arr[1],
        m.arr[2]*x.arr[0]+m.arr[3]*x.arr[1]
    };
    Vec2 res = { arr };
    return res;
}

#endif
