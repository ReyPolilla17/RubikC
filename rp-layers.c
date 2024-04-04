#include "cube.h"

/**
 * moves the m layer in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void mp(int cube[][3][3])
{
  // tree times the original function
  m(cube);
  m(cube);
  m(cube);

  return;
}

/**
 * moves the e layer in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void ep(int cube[][3][3])
{
  // tree times the original function
  e(cube);
  e(cube);
  e(cube);

  return;
}

/**
 * moves the s layer in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void sp(int cube[][3][3])
{
  // tree times the original function
  s(cube);
  s(cube);
  s(cube);

  return;
}

/**
 * moves the upper face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Up(int cube[][3][3])
{
  // tree times the original function
  U(cube);
  U(cube);
  U(cube);

  return;
}

/**
 * moves the down face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Dp(int cube[][3][3])
{
  // tree times the original function
  D(cube);
  D(cube);
  D(cube);

  return;
}

/**
 * moves the right face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Rp(int cube[][3][3])
{
  // tree times the original function
  R(cube);
  R(cube);
  R(cube);

  return;
}

/**
 * moves the left face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Lp(int cube[][3][3])
{
  // tree times the original function
  L(cube);
  L(cube);
  L(cube);

  return;
}

/**
 * moves the front face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Fp(int cube[][3][3])
{
  // tree times the original function
  F(cube);
  F(cube);
  F(cube);

  return;
}

/**
 * moves the back face in a counter-clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void Bp(int cube[][3][3])
{
  // tree times the original function
  B(cube);
  B(cube);
  B(cube);

  return;
}