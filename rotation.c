#include "cube.h"

/**
 * rotates clockwise a face of the cube
 * 
 * @param cube[][3][3] the cube to modify
 * @param layer the cube layer to rotate
*/
void rot(int cube[][3][3], int layer)
{
  int i, j, k;
  int face[3][3];

  // first copies the face in the new order
  for(i = 0, k = 2; i < 3; i++, k--)
  {
    for(j = 0; j < 3; j++)
    {
      face[j][k] = cube[layer][i][j];
    }
  }

  // the it changes the original face
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      cube[layer][i][j] = face[i][j];
    }
  }

  return;
}