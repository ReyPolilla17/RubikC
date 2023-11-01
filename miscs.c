#include "cube.h"

// changes all the colors to it's starting position
void solve(int cube[][3][3], int *size)
{
  int i, j, k;

  FILE *movesFile;

  movesFile = fopen("moves.txt", "w");
  fclose(movesFile);

  for(i = 0; i < 6; i++)
  {
    for(j = 0; j < 3; j++)
    {
      for(k = 0; k < 3; k++)
      {
        cube[i][j][k] = i + 1;
      }
    }
  }

  *size = 0;
  return;
}

// generates 50 random numbers from 0 to 35 and takes every number as an action
// it also prints every move that has been made to scramble the cube
void mix(int cube[][3][3], int *size)
{
  int move = 0;
  int i = 0;

  srand(time(NULL));

  for(i = 0; i <= 50; i++)
  {
    move = rand() % 36;

    switch(move)
    {
      case 0:
      {
        U(cube);
        addM(size, "U");
        break;
      }
      case 1:
      {
        Up(cube);
        addM(size, "U'");
        break;
      }
      case 2:
      {
        u(cube);
        addM(size, "u");
        break;
      }
      case 3:
      {
        up(cube);
        addM(size, "u'");
        break;
      }

      case 4:
      {
        D(cube);
        addM(size, "D");
        break;
      }
      case 5:
      {
        Dp(cube);
        addM(size, "D'");
        break;
      }
      case 6:
      {
        d(cube);
        addM(size, "d");
        break;
      }
      case 7:
      {
        dp(cube);
        addM(size, "d'");
        break;
      }

      case 8:
      {
        F(cube);
        addM(size, "F");
        break;
      }
      case 9:
      {
        Fp(cube);
        addM(size, "F'");
        break;
      }
      case 10:
      {
        f(cube);
        addM(size, "f");
        break;
      }
      case 11:
      {
        fp(cube);
        addM(size, "f'");
        break;
      }

      case 12:
      {
        B(cube);
        addM(size, "B");
        break;
      }
      case 13:
      {
        Bp(cube);
        addM(size, "B'");
        break;
      }
      case 14:
      {
        b(cube);
        addM(size, "b");
        break;
      }
      case 15:
      {
        bp(cube);
        addM(size, "b'");
        break;
      }

      case 16:
      {
        L(cube);
        addM(size, "L");
        break;
      }
      case 17:
      {
        Lp(cube);
        addM(size, "L'");
        break;
      }
      case 18:
      {
        l(cube);
        addM(size, "l");
        break;
      }
      case 19:
      {
        lp(cube);
        addM(size, "l'");
        break;
      }

      case 20:
      {
        R(cube);
        addM(size, "R");
        break;
      }
      case 21:
      {
        Rp(cube);
        addM(size, "R'");
        break;
      }
      case 22:
      {
        r(cube);
        addM(size, "r");
        break;
      }
      case 23:
      {
        rp(cube);
        addM(size, "r'");
        break;
      }

      case 24:
      {
        m(cube);
        addM(size, "m");
        break;
      }
      case 25:
      {
        mp(cube);
        addM(size, "m'");
        break;
      }
      case 26:
      {
        e(cube);
        addM(size, "e");
        break;
      }
      case 27:
      {
        ep(cube);
        addM(size, "e'");
        break;
      }
      case 28:
      {
        s(cube);
        addM(size, "s");
        break;
      }
      case 29:
      {
        sp(cube);
        addM(size, "s'");
        break;
      }

      case 30:
      {
        x(cube);
        addM(size, "x");
        break;
      }
      case 31:
      {
        xp(cube);
        addM(size, "x'");
        break;
      }
      case 32:
      {
        y(cube);
        addM(size, "y");
        break;
      }
      case 33:
      {
        yp(cube);
        addM(size, "y'");
        break;
      }
      case 34:
      {
        z(cube);
        addM(size, "z");
        break;
      }
      case 35:
      {
        zp(cube);
        addM(size, "z'");
        break;
      }
    }
  }

  return;
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