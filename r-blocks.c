#include "cube.h"

// rotate s the full cube in it's x axis
void x(int cube[][3][3])
{
  r(cube);
  Lp(cube);
  return;
}

// rotate s the full cube in it's y axis
void y(int cube[][3][3])
{
  u(cube);
  Dp(cube);

  return;
}

// rotates the full cube in it's z axis
void z(int cube[][3][3])
{
  f(cube);
  Bp(cube);

  return;
}

void u(int cube[][3][3])
{
  U(cube);
  ep(cube);
}

void d(int cube[][3][3])
{
  D(cube);
  e(cube);
}

void r(int cube[][3][3])
{
  R(cube);
  mp(cube);

  return;
}

void l(int cube[][3][3])
{
  L(cube);
  m(cube);

  return;
}

void f(int cube[][3][3])
{
  F(cube);
  s(cube);

  return;
}

void b(int cube[][3][3])
{
  B(cube);
  sp(cube);

  return;
}