#include "cube.h"

/**
 * rotates the full cube in it's x axis on a clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void x(int cube[][3][3])
{
  // rotates the right face, the middle layer and counter-clockwise the left face
  r(cube);
  Lp(cube);

  return;
}

/**
 * rotates the full cube in it's y axis on a clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void y(int cube[][3][3])
{
  // rotates the upper face, the middle layer and counter-clockwise the down face
  u(cube);
  Dp(cube);

  return;
}

/**
 * rotates the full cube in it's z axis on a clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void z(int cube[][3][3])
{
  // rotates the front face, the middle layer and counter-clockwise the back face
  f(cube);
  Bp(cube);

  return;
}

/**
 * rotates the upper face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void u(int cube[][3][3])
{
  U(cube);
  ep(cube);

  return;
}

/**
 * rotates the down face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void d(int cube[][3][3])
{
  D(cube);
  e(cube);

  return;
}

/**
 * rotates the right face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void r(int cube[][3][3])
{
  R(cube);
  mp(cube);

  return;
}

/**
 * rotates the left face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void l(int cube[][3][3])
{
  L(cube);
  m(cube);

  return;
}

/**
 * rotates the front face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void f(int cube[][3][3])
{
  F(cube);
  s(cube);

  return;
}


/**
 * rotates the back face and the middle face clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void b(int cube[][3][3])
{
  B(cube);
  sp(cube);

  return;
}