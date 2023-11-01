#include "cube.h"

void m(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[3][i][1];
    level2[i] = cube[5][i][1];
    level3[i] = cube[1][i][1];
    level4[i] = cube[0][i][1];
  }

  for(i = 0; i < 3; i++)
  {
    cube[5][i][1] = level3[i];
    cube[1][i][1] = level4[i];
    cube[0][i][1] = level[2 - i];
    cube[3][i][1] = level2[2 - i];
  }

  return;
}

void e(int cube[][3][3])
{
  int level[3];
  int i = 0;

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

void s(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][1];
    level2[i] = cube[5][1][i];
    level3[i] = cube[2][i][1];
    level4[i] = cube[0][1][i];
  }

  for(i = 0; i < 3; i++)
  {
    cube[4][i][1] = level2[i];
    cube[5][1][i] = level3[2 - i];
    cube[2][i][1] = level4[i];
    cube[0][1][i] = level[2 - i];
  }

  return;
}

void U(int cube[][3][3])
{
  int level[3];
  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[1][0][i];
    cube[1][0][i] = cube[2][0][i];
    cube[2][0][i] = cube[3][0][i];
    cube[3][0][i] = cube[4][0][i];
    cube[4][0][i] = level[i];
  }

  rot(cube, 0);
  return;
}

void D(int cube[][3][3])
{
  int level[3];
  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][2][i];
    cube[4][2][i] = cube[3][2][i];
    cube[3][2][i] = cube[2][2][i];
    cube[2][2][i] = cube[1][2][i];
    cube[1][2][i] = level[i];
  }

  rot(cube, 5);
  return;
}

void R(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[0][i][2];
    level2[i] = cube[1][i][2];
    level3[i] = cube[5][i][2];
    level4[i] = cube[3][i][0];
  }

  for(i = 0; i < 3; i++)
  {
    cube[0][i][2] = level2[i];
    cube[1][i][2] = level3[i];
    cube[3][i][0] = level[2 - i];
    cube[5][i][2] = level4[2 - i];
  }

  rot(cube, 2);
  return;
}

void L(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[3][i][2];
    level2[i] = cube[5][i][0];
    level3[i] = cube[1][i][0];
    level4[i] = cube[0][i][0];
  }

  for(i = 0; i < 3; i++)
  {
    cube[5][i][0] = level3[i];
    cube[1][i][0] = level4[i];
    cube[0][i][0] = level[2 - i];
    cube[3][i][2] = level2[2 - i];
  }

  rot(cube, 4);

  return;
}

void F(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][2];
    level2[i] = cube[5][0][i];
    level3[i] = cube[2][i][0];
    level4[i] = cube[0][2][i];
  }

  for(i = 0; i < 3; i++)
  {
    cube[0][2][i] = level[2 - i];
    cube[4][i][2] = level2[i];
    cube[5][0][i] = level3[2 - i];
    cube[2][i][0] = level4[i];
  }

  rot(cube, 1);
  return;
}

void B(int cube[][3][3])
{
  int level[3];
  int level2[3];
  int level3[3];
  int level4[3];

  int i = 0;

  for(i = 0; i < 3; i++)
  {
    level[i] = cube[4][i][0];
    level2[i] = cube[5][2][i];
    level3[i] = cube[2][i][2];
    level4[i] = cube[0][0][i];
  }

  for(i = 0; i < 3; i++)
  {
    cube[0][0][i] = level3[i];
    cube[4][i][0] = level4[2 - i];
    cube[5][2][i] = level[i];
    cube[2][i][2] = level2[2 - i];
  }

  rot(cube, 3);
  return;
}