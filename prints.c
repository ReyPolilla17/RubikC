#include "cube.h"

// prints the cube in a specific order
void printC(int cube[][3][3])
{
  int i = 0;
  int j = 0;
  int k = 0;

  // first the upper face
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("\x1b[3%dm#\x1b[0m", cube[0][i][j]);
    }
    printf("\n");
  }

  // then the lateral faces
  for (i = 0; i < 3; i++)
  {
    for (j = 1; j < 5; j++)
    {
      for (k = 0; k < 3; k++)
      {
        printf("\x1b[3%dm#\x1b[0m", cube[j][i][k]);
      }
      printf(" ");
    }
    printf("\n");
  }

  // and the bottom face
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("\x1b[3%dm#\x1b[0m", cube[5][i][j]);
    }
    printf("\n");
  }

  return;
}

// printing in 3d the cube, really complex because why not?
void print3D(int cube[][3][3])
{
  // the amount of space before printing the upper face
  char mov[5] = "     ";

  // counters
  int i = 0;
  int j = 0;
  int k = 0;

  int a = 4;

  // print the upper layer along with the rigth top part
  for (i = 0; i < 3; i++)
  {
    for (k = 0; k < 2; k++, a--)
    {
      // spaces before printing
      printf("%s%s", mov, mov);

      // prints the color of the piece
      for (j = 0; j < 3; j++)
      {
        if (j)
        {
          printf("  ");
        }

        printf("\x1b[4%dm      \x1b[0m", cube[0][i][j]);
      }

      // prints the rigth top part
      for (j = 0; j <= 4 - a && j < 4; j++)
      {
        printf("\x1b[4%dm  \x1b[0m", cube[2][0][2 - ((4 - a - j) / 2)]);
      }

      if (4 - a == 5)
      {
        printf("  ");
        printf("\x1b[4%dm  \x1b[0m", cube[2][1][2]);
      }

      mov[a] = 0;
      printf("\n");
    }
  }

  // printfs the front face along with the right face
  for (i = 0; i < 3; i++)
  {
    for (k = 0, a = 3; k < 3; k++, a--)
    {
      // printfs the color of the piece
      for (j = 0; j < 3; j++)
      {
        if (j)
        {
          printf("  ");
        }

        printf("\x1b[4%dm      \x1b[0m", cube[1][i][j]);
      }

      // prints right face
      for (j = 0; j < a; j++)
      {
        printf("\x1b[4%dm  \x1b[0m", cube[2][i][j / 2]);
      }

      printf("  ");

      for (j = 0; j < 3 && j <= 4 - a && i != 2; j++)
      {
        printf("\x1b[4%dm  \x1b[0m", cube[2][i + 1][((((j + 1) * a) / 3) + 3) / 2]);
      }

      printf("\n");
    }

    // for empty spaces
    if (i != 2)
    {
      printf("                        ");

      for (k = 0; k < 3; k++)
      {
        printf("\x1b[4%dm  \x1b[0m", cube[2][i + 1][(k + 1) / 2]);
      }

      if (i != 1)
      {
        printf("  ");
        printf("\x1b[4%dm  \x1b[0m", cube[2][i + 1][2]);
      }
    }

    printf("\n");
  }

  return;
}

void printM(Rubik_Cube *cube)
{
  Instruction *temp;

  if(solved(cube->matrix))
  {
    freeStruct(&cube->inst_start);
  }

  if(cube->inst_start != NULL)
  {
    temp = cube->inst_start;

    while (temp != NULL)
    {
      printf("%s ", temp->wd);
      temp = temp->next;
    }

    printf("\n\n");
  }
  else
  {
    printf("Cube is solved!\n\n");
  }

  return;
}