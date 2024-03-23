#include "cube.h"

void initialize(Rubik_Cube *cube, int s)
{
  int i = 0;
  int j = 0;
  int k = 0;

  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 3; k++)
      {
        switch (i)
        {
          case 0:
          {
            cube->matrix[i][j][k] = 7;
            break;
          }
          case 1:
          {
            cube->matrix[i][j][k] = i;
            break;
          }
          case 2:
          case 3:
          {
            cube->matrix[i][j][k] = i + 2;
            break;
          }
          case 4:
          case 5:
          {
            cube->matrix[i][j][k] = i - 2;
            break;
          }
        }
      }
    }
  }

  if(s)
  {
    cube->par_start = NULL;
    cube->inst_start = NULL;
    cube->str = NULL;
  }
  else
  {
    freeStruct((void**) &cube->par_start);
    freeStruct((void**) &cube->inst_start);

    if(cube->str != NULL)
    {
      free(cube->str);
    }
  }

  return;
}

void moveCube(int cube[][3][3], char move[])
{
  void (*movement[36])(int cube[][3][3]) = {
    U, u, D, d, F, f, B, b, L, l, R, r, m, e, s, x, y, z, 
    Up, up, Dp, dp, Fp, fp, Bp, bp, Lp, lp, Rp, rp, mp, ep, sp, xp, yp, zp
  };

  int op = 0;

  switch(move[0])
  {
    case 'U':
    {
      op = 0;
      break;
    }
    case 'u':
    {
      op = 1;
      break;
    }
    case 'D':
    {
      op = 2;
      break;
    }
    case 'd':
    {
      op = 3;
      break;
    }
    case 'F':
    {
      op = 4;
      break;
    }
    case 'f':
    {
      op = 5;
      break;
    }
    case 'B':
    {
      op = 6;
      break;
    }
    case 'b':
    {
      op = 7;
      break;
    }
    case 'L':
    {
      op = 8;
      break;
    }
    case 'l':
    {
      op = 9;
      break;
    }
    case 'R':
    {
      op = 10;
      break;
    }
    case 'r':
    {
      op = 11;
      break;
    }
    case 'm':
    {
      op = 12;
      break;
    }
    case 'e':
    {
      op = 13;
      break;
    }
    case 's':
    {
      op = 14;
      break;
    }
    case 'x':
    {
      op = 15;
      break;
    }
    case 'y':
    {
      op = 16;
      break;
    }
    case 'z':
    {
      op = 17;
      break;
    }
  }

  if(move[1] == '\'')
  {
    op += 18;
  }

  (*movement[op])(cube);
}

// generates 50 random numbers from 0 to 35 and takes every number as an action
// it also prints every move that has been made to scramble the cube
void mix(Rubik_Cube *cube)
{
  void (*movement[36])(int cube[][3][3]) = {
    U, u, D, d, F, f, B, b, L, l, R, r, m, e, s, x, y, z, 
    Up, up, Dp, dp, Fp, fp, Bp, bp, Lp, lp, Rp, rp, mp, ep, sp, xp, yp, zp
  };

  char instructions[36][3] = { 
    "U\0", "u\0", "D\0", "d\0", "F\0", "f\0", "B\0", "b\0", "L\0", "l\0", "R\0", "r\0", "m\0", "e\0", "s\0", "x\0", "y\0", "z\0", 
    "U'\0", "u'\0", "D'\0", "d'\0", "F'\0", "f'\0", "B'\0", "b'\0", "L'\0", "l'\0", "R'\0", "r'\0", "m'\0", "e'\0", "s'\0", "x'\0", "y'\0", "z'\0"
  };

  int move = 0;
  int i = 0;
  int ms = (rand() % 30) + 20;

  initialize(cube, 0);

  for(i = 0; i < ms; i++)
  {
    move = rand() % 36;

    (*movement[move])(cube->matrix);
    addM(&cube->inst_start, instructions[move]);
  }

  return;
}

int solved(int cube[][3][3])
{
  int col = 0;
  int i = 0;
  int j = 0;
  int k = 0;

  for (i = 0; i < 6; i++)
  {
    col = cube[i][0][0];

    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 3; k++)
      {
        if (cube[i][j][k] != col)
        {
          return 0;
        }
      }
    }
  }

  return 1;
}

void freeStruct(void **start)
{
  Generic *temp;

  while (*start != NULL)
  {
    temp = *start;
    *start = temp->next;

    free(temp);
  }

  return;
}