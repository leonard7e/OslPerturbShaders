#ifndef VEC2_H
#define VEC2_H

// Two dimensional vectors
struct vec2 {
  float arr[2];
}

vec2 __operator__add__ (vec2 a, vec2 b)
{
  float arr[2] = {
    a.arr[0] + b.arr[0],
    a.arr[1] + b.arr[1]
  }
  return vec2 { arr };
}

vec2 __operator__sub__ (vec2 a, vec2 b)
{
  float arr[2] = {
    a.arr[0] - b.arr[0],
    a.arr[1] - b.arr[1]
  }
  return vec2 { arr };
}

vec2 __operator__neg__ (vec2 a)
{
  float arr[2] = {
    - a.arr[0],
    - a.arr[1]
  }
  return vec2 { arr };
}

// Matrices for two dimensions

/* Indices of matrix
  0   1
  2   3
*/
struct matr2 {
  float arr[4];
}

matr2 __operator__mul__ (matr2 a, matr2 b)
{
  float arr[4] = {
    a.arr[0]*b.arr[0] + a.arr[1]*b.arr[2],
    a.arr[0]*b.arr[1] + a.arr[1]*b.arr[3],

    a.arr[2]*b.arr[0] + a.arr[3]*b.arr[2],
    a.arr[2]*b.arr[1] + a.arr[3]*b.arr[3]
  }
  return matr2 { arr };
}

vec2 transform (matr2 m, vec2 x)
{
  float arr[2] = {
    m[0]*x[0]+m[1]*x[1],
    m[2]*x[0]+m[3]*x[1]
  };
  return vec2 { arr };
}

#endif
