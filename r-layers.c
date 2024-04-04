#include "cube.h"

/**
 * moves the m layer in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void m(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // creates a coppy of the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[3][i][1];
    level2[i] = cube[5][i][1];
    level3[i] = cube[1][i][1];
    level4[i] = cube[0][i][1];
  }

  // pastes the layer in a specific otder
  for(i = 0; i < 3; i++)
  {
    cube[5][i][1] = level3[i];
    cube[1][i][1] = level4[i];
    cube[0][i][1] = level[2 - i];
    cube[3][i][1] = level2[2 - i];
  }

  return;
}

/**
 * moves the e layer in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void e(int cube[][3][3])
{
  int level[3];
  int i = 0;

  // moves the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][1][i];
    cube[4][1][i] = cube[3][1][i];
    cube[3][1][i] = cube[2][1][i];
    cube[2][1][i] = cube[1][1][i];
    cube[1][1][i] = level[i];
  }

  return;
}

/**
 * moves the s layer in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void s(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // creates a cppy of the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][1];
    level2[i] = cube[5][1][i];
    level3[i] = cube[2][i][1];
    level4[i] = cube[0][1][i];
  }

  // pastes the layer in a specific order
  for(i = 0; i < 3; i++)
  {
    cube[4][i][1] = level2[i];
    cube[5][1][i] = level3[2 - i];
    cube[2][i][1] = level4[i];
    cube[0][1][i] = level[2 - i];
  }

  return;
}

/**
 * moves the upper face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void U(int cube[][3][3])
{
  int level[3];
  int i = 0;

  // moves the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[1][0][i];
    cube[1][0][i] = cube[2][0][i];
    cube[2][0][i] = cube[3][0][i];
    cube[3][0][i] = cube[4][0][i];
    cube[4][0][i] = level[i];
  }

  // moves the face
  rot(cube, 0);
  return;
}

/**
 * moves the down face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void D(int cube[][3][3])
{
  int level[3];
  int i = 0;

  // moves the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][2][i];
    cube[4][2][i] = cube[3][2][i];
    cube[3][2][i] = cube[2][2][i];
    cube[2][2][i] = cube[1][2][i];
    cube[1][2][i] = level[i];
  }

  // moves the face
  rot(cube, 5);
  return;
}

/**
 * moves the right face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void R(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // creates a coppy of the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[0][i][2];
    level2[i] = cube[1][i][2];
    level3[i] = cube[5][i][2];
    level4[i] = cube[3][i][0];
  }

  // pastes the layer in a specific order
  for(i = 0; i < 3; i++)
  {
    cube[0][i][2] = level2[i];
    cube[1][i][2] = level3[i];
    cube[3][i][0] = level[2 - i];
    cube[5][i][2] = level4[2 - i];
  }

  // rotates the face
  rot(cube, 2);
  return;
}

/**
 * moves the left face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void L(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // coppys the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[3][i][2];
    level2[i] = cube[5][i][0];
    level3[i] = cube[1][i][0];
    level4[i] = cube[0][i][0];
  }

  // pastes the layer in a specific order
  for(i = 0; i < 3; i++)
  {
    cube[5][i][0] = level3[i];
    cube[1][i][0] = level4[i];
    cube[0][i][0] = level[2 - i];
    cube[3][i][2] = level2[2 - i];
  }

  // rotates the face
  rot(cube, 4);

  return;
}

/**
 * moves the front face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void F(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // coppys the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][2];
    level2[i] = cube[5][0][i];
    level3[i] = cube[2][i][0];
    level4[i] = cube[0][2][i];
  }

  // pastes the layer in a specific order 
  for(i = 0; i < 3; i++)
  {
    cube[0][2][i] = level[2 - i];
    cube[4][i][2] = level2[i];
    cube[5][0][i] = level3[2 - i];
    cube[2][i][0] = level4[i];
  }

  // rotates the face
  rot(cube, 1);
  return;
}

/**
 * moves the back face in a clockwise direction
 * 
 * @param cube[][3][3] the cube to move
*/
void B(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  // copys the layer
  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][0];
    level2[i] = cube[5][2][i];
    level3[i] = cube[2][i][2];
    level4[i] = cube[0][0][i];
  }

  // pastes the layer in a specific order
  for(i = 0; i < 3; i++)
  {
    cube[0][0][i] = level3[i];
    cube[4][i][0] = level4[2 - i];
    cube[5][2][i] = level[i];
    cube[2][i][2] = level2[2 - i];
  }

  // ritates the face
  rot(cube, 3);
  return;
}