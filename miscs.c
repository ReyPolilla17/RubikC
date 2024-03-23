#include "cube.h"

int getIns(char *str)
{
  char *inst;

  int len = 0;

  int rv = 0;
  int i = 2;

  while(str[i] != 0 && str[i] != ' ')
  {
    i++;
  }

  len = i - 1;

  inst = (char*)malloc(sizeof(char) * len);

  for(i = 0; i < len; i++)
  {
    inst[i] = str[i + 2];
  }

  if(!strcmp(inst, "exit"))
  {
    rv = 1;
  }
  else if(!strcmp(inst, "help"))
  {
    rv = 2;
  }
  else if(!strcmp(inst, "mix"))
  {
    rv = 3;
  }
  else if(!strcmp(inst, "solve"))
  {
    rv = 4;
  }
  else if(!strcmp(inst, "solution"))
  {
    rv = 5;
  }
  else if(!strcmp(inst, "perspective"))
  {
    rv = 6;
  }

  free(inst);

  return rv;
}

// rotates clockwise a face of the cube
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

// rotates counter-clockwise a face of the cube
void rot_p(int cube[][3][3], int layer)
{
  rot(cube, layer);
  rot(cube, layer);
  rot(cube, layer);

  return;
}