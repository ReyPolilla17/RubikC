#include "cube.h"

/**
 * Initializes or resets the main cube struct.
 * 
 * @param *cube a pointer to the struct to modify
 * @param s whether to initialize or restart the cube
*/
void initialize(Rubik_Cube *cube, int s)
{
  int i = 0;
  int j = 0;
  int k = 0;

  // sets each color of every face of the cube as the same
  // the number rules are for making the color printing easier
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

  // if its an initialization, it just set each pointer to NULL
  if(s)
  {
    cube->par_start = NULL;
    cube->inst_start = NULL;
    cube->str = NULL;
  }
  // else frees every pointer and dynamic list
  else
  {
    freeStruct((void**) &cube->par_start);
    freeStruct((void**) &cube->inst_start);

    if(cube->str != NULL)
    {
      free(cube->str);
      cube->str = NULL;
    }
  }

  return;
}

/**
 * Moves the cube according to the move inserted
 * 
 * @param cube the cube to move
 * @param move the movement to do
*/
void moveCube(int cube[][3][3], char move[])
{
  // array of functions
  void (*movement[36])(int cube[][3][3]) = {
    U, u, D, d, F, f, B, b, L, l, R, r, m, e, s, x, y, z, 
    Up, up, Dp, dp, Fp, fp, Bp, bp, Lp, lp, Rp, rp, mp, ep, sp, xp, yp, zp
  };

  // array of instructions, it is syncronized to the array of functions
  char instructions[36][3] = { 
    "U\0", "u\0", "D\0", "d\0", "F\0", "f\0", "B\0", "b\0", "L\0", "l\0", "R\0", "r\0", "m\0", "e\0", "s\0", "x\0", "y\0", "z\0", 
    "U'\0", "u'\0", "D'\0", "d'\0", "F'\0", "f'\0", "B'\0", "b'\0", "L'\0", "l'\0", "R'\0", "r'\0", "m'\0", "e'\0", "s'\0", "x'\0", "y'\0", "z'\0"
  };

  int i = 0;

  // gets the movement to do
  // it will always find a movement since this function is called after verifying it exists
  while(strcmp(move, instructions[i]) && i < 36)
  {
    i++;
  }

  // executes the function
  (*movement[i])(cube);

  return;
}

/**
 * generates 50 random numbers from 0 to 35 and takes every number as an action
 * it also prints every move that has been made to scramble the cube
 * 
 * @param *cube the cube to mix
*/
void mix(Rubik_Cube *cube)
{
  // array of functions
  void (*movement[36])(int cube[][3][3]) = {
    U, u, D, d, F, f, B, b, L, l, R, r, m, e, s, x, y, z, 
    Up, up, Dp, dp, Fp, fp, Bp, bp, Lp, lp, Rp, rp, mp, ep, sp, xp, yp, zp
  };

  // array of instructions
  char instructions[36][3] = { 
    "U\0", "u\0", "D\0", "d\0", "F\0", "f\0", "B\0", "b\0", "L\0", "l\0", "R\0", "r\0", "m\0", "e\0", "s\0", "x\0", "y\0", "z\0", 
    "U'\0", "u'\0", "D'\0", "d'\0", "F'\0", "f'\0", "B'\0", "b'\0", "L'\0", "l'\0", "R'\0", "r'\0", "m'\0", "e'\0", "s'\0", "x'\0", "y'\0", "z'\0"
  };

  // can gnerate from 30 to 50 random movements
  int move = 0;
  int i = 0;
  int ms = (rand() % 30) + 20;

  // solves the cube 
  initialize(cube, 0);

  // does random movements to the cube
  for(i = 0; i < ms; i++)
  {
    move = rand() % 36;

    (*movement[move])(cube->matrix);
    addM(&cube->inst_start, instructions[move]);
  }

  return;
}

/**
 * Checks if the cube is solved, returns 1 if solved nd 0 if not
 * 
 * @param cube the cube to verify
 * 
 * @return int 
*/
int solved(int cube[][3][3])
{
  int col = 0;
  int i = 0;
  int j = 0;
  int k = 0;

  // checks if every color is the same in each face
  for (i = 0; i < 6; i++)
  {
    col = cube[i][0][0];

    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 3; k++)
      {
        if (cube[i][j][k] != col)
        {
          // if the color is not the same, it ends the function
          return 0;
        }
      }
    }
  }

  return 1;
}

/**
 * Frees any kind of dynamic list in this program
 * 
 * @param **start the start of the list
 * 
*/
void freeStruct(void **start)
{
  // generic structure pointer
  Generic *temp;

  // frees every point of the struct
  while(*start != NULL)
  {
    temp = *start;
    *start = temp->next;

    free(temp);
  }

  return;
}