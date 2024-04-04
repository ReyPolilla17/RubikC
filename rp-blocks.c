#include "cube.h"

/**
 * rotates the full cube in it's x axis on a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void xp(int cube[][3][3])
{
  // tree times the original function
  x(cube);
  x(cube);
  x(cube);

  return;
}

/**
 * rotates the full cube in it's y axis on a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void yp(int cube[][3][3])
{
  // tree times the original function
  y(cube);
  y(cube);
  y(cube);

  return;
}

/**
 * rotates the full cube in it's z axis on a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to rotate
*/
void zp(int cube[][3][3])
{
  // tree times the original function
  z(cube);
  z(cube);
  z(cube);

  return;
}

/**
 * rotates the upper face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void up(int cube[][3][3])
{
  Up(cube);
  e(cube);
}

/**
 * rotates the down face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void dp(int cube[][3][3])
{
  Dp(cube);
  ep(cube);
}

/**
 * rotates the right face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void rp(int cube[][3][3])
{
  Rp(cube);
  m(cube);

  return;
}

/**
 * rotates the left face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void lp(int cube[][3][3])
{
  Lp(cube);
  mp(cube);

  return;
}

/**
 * rotates the front face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void fp(int cube[][3][3])
{
  Fp(cube);
  sp(cube);

  return;
}

/**
 * rotates the back face and the middle face counter-clockwise
 * 
 * @param cube[][3][3] the cube to rotate
*/
void bp(int cube[][3][3])
{
  Bp(cube);
  s(cube);

  return;
}