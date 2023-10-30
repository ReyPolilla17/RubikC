#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// colors: https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c

//Each block of functions is used for different purposes

// printing the cube
void color(int value);
void printC(int arr[][3][3]);

// rotating a face
void rot(int cube[][3][3], int layer);
void rot_p(int cube[][3][3], int layer);

// complete actions
void mix(int cube[][3][3]);
void solve(int cube[][3][3]);

// up
void U(int cube[][3][3]);
void Up(int cube[][3][3]);
void u(int cube[][3][3]);
void up(int cube[][3][3]);

// down
void D(int cube[][3][3]);
void Dp(int cube[][3][3]);
void d(int cube[][3][3]);
void dp(int cube[][3][3]);

// front
void F(int cube[][3][3]);
void Fp(int cube[][3][3]);
void f(int cube[][3][3]);
void fp(int cube[][3][3]);

// back
void B(int cube[][3][3]);
void Bp(int cube[][3][3]);
void b(int cube[][3][3]);
void bp(int cube[][3][3]);

// left
void L(int cube[][3][3]);
void Lp(int cube[][3][3]);
void l(int cube[][3][3]);
void lp(int cube[][3][3]);

// right
void R(int cube[][3][3]);
void Rp(int cube[][3][3]);
void r(int cube[][3][3]);
void rp(int cube[][3][3]);

// inbetween layers
void m(int cube[][3][3]);
void mp(int cube[][3][3]);
void e(int cube[][3][3]);
void ep(int cube[][3][3]);
void s(int cube[][3][3]);
void sp(int cube[][3][3]);

// rotating the cube
void x(int cube[][3][3]);
void xp(int cube[][3][3]);
void y(int cube[][3][3]);
void yp(int cube[][3][3]);
void z(int cube[][3][3]);
void zp(int cube[][3][3]);

int main(void)
{
  // the cube works with numbers instead of colors
  int cube[6][3][3] = {{{1,1,1},{1,1,1},{1,1,1}}, {{2,2,2},{2,2,2},{2,2,2}}, {{3,3,3},{3,3,3},{3,3,3}}, {{4,4,4},{4,4,4},{4,4,4}}, {{5,5,5},{5,5,5},{5,5,5}}, {{6,6,6},{6,6,6},{6,6,6}}};

  // action is a string of 2 chars to make it possible to use the '
  char a[2];

  // Q will be the stopper
  while(a[0] != 'Q')
  {
    // every action will clear the terminal and print the resulting cube
    printC(cube);
    printf("Choose an action: ");
    scanf("%[^\n]", a);
    system("clear");
    getchar();

    // every letter makes the action of the cube notation (U = up, D = down, etc)
    // S will mix the cube and S' will solve it
    switch(a[0])
    {
      case 'U':
      {
        if(a[1] == '\0')
        {
          U(cube);
        }
        else if(a[1] == '\'')
        {
          Up(cube);
        }
        break;
      }
      case 'u':
      {
        if(a[1] == '\0')
        {
          u(cube);
        }
        else if(a[1] == '\'')
        {
          up(cube);
        }
        break;
      }
      case 'D':
      {
        if(a[1] == '\0')
        {
          D(cube);
        }
        else if(a[1] == '\'')
        {
          Dp(cube);
        }
        break;
      }
      case 'd':
      {
        if(a[1] == '\0')
        {
          d(cube);
        }
        else if(a[1] == '\'')
        {
          dp(cube);
        }
        break;
      }
      case 'R':
      {
        if(a[1] == '\0')
        {
          R(cube);
        }
        else if(a[1] == '\'')
        {
          Rp(cube);
        }
        break;
      }
      case 'r':
      {
        if(a[1] == '\0')
        {
          r(cube);
        }
        else if(a[1] == '\'')
        {
          rp(cube);
        }
        break;
      }
      case 'L':
      {
        if(a[1] == '\0')
        {
          L(cube);
        }
        else if(a[1] == '\'')
        {
          Lp(cube);
        }
        break;
      }
      case 'l':
      {
        if(a[1] == '\0')
        {
          l(cube);
        }
        else if(a[1] == '\'')
        {
          lp(cube);
        }
        break;
      }
      case 'F':
      {
        if(a[1] == '\0')
        {
          F(cube);
        }
        else if(a[1] == '\'')
        {
          Fp(cube);
        }
        break;
      }
      case 'f':
      {
        if(a[1] == '\0')
        {
          f(cube);
        }
        else if(a[1] == '\'')
        {
          fp(cube);
        }
        break;
      }
      case 'B':
      {
        if(a[1] == '\0')
        {
          B(cube);
        }
        else if(a[1] == '\'')
        {
          Bp(cube);
        }
        break;
      }
      case 'b':
      {
        if(a[1] == '\0')
        {
          b(cube);
        }
        else if(a[1] == '\'')
        {
          bp(cube);
        }
        break;
      }
      case 'm':
      {
        if(a[1] == '\0')
        {
          m(cube);
        }
        else if(a[1] == '\'')
        {
          mp(cube);
        }
        break;
      }
      case 'e':
      {
        if(a[1] == '\0')
        {
          e(cube);
        }
        else if(a[1] == '\'')
        {
          ep(cube);
        }
        break;
      }
      case 'S':
      {
        if(a[1] == '\0')
        {
          mix(cube);
        }
        else if(a[1] == '\'')
        {
          solve(cube);
        }
        break;
      }
      case 's':
      {
        if(a[1] == '\0')
        {
          s(cube);
        }
        else if(a[1] == '\'')
        {
          sp(cube);
        }
        break;
      }
      case 'x':
      {
        if(a[1] == '\0')
        {
          x(cube);
        }
        else if(a[1] == '\'')
        {
          xp(cube);
        }
        break;
      }
      case 'y':
      {
        if(a[1] == '\0')
        {
          y(cube);
        }
        else if(a[1] == '\'')
        {
          yp(cube);
        }
        break;
      }
      case 'z':
      {
        if(a[1] == '\0')
        {
          z(cube);
        }
        else if(a[1] == '\'')
        {
          zp(cube);
        }
        break;
      }
      case 'Q':
      {
        break;
      }
      default:
      {
        printf("Unknown action...\n");
        break;
      }
    }
  }

  return 0;
}

// used for the printing of the cube, I use # because it's easier to undestand
void color(int value)
{
  switch(value)
  {
    // red
    case 2:
    {
      printf("\x1b[31m#\x1b[0m");
      break;
    }
    // blue
    case 3:
    {
      printf("\x1b[1m\x1b[34m#\x1b[0m");
      break;
    }
    // magenta
    case 4:
    {
      printf("\x1b[1m\x1b[35m#\x1b[0m");
      break;
    }
    // Green
    case 5:
    {
      printf("\x1b[1m\x1b[32m#\x1b[0m");
      break;
    }
    // Yellow
    case 6:
    {
      printf("\x1b[1m\x1b[33m#\x1b[0m");
      break;
    }
    // white
    default:
    {
      printf("\x1b[1m#\x1b[0m");
      break;
    }
  }
  return;
}

// prints the cube in a specific order
void printC(int arr[][3][3])
{
  int i = 0;
  int j = 0;
  int k = 0;

  // first the upper face
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      color(arr[0][i][j]);
    }
    printf("\n");
  }

  // then the lateral faces
  for(i = 0; i < 3; i++)
  {
    for(j = 1; j < 5; j++)
    {
      for(k = 0; k < 3; k++)
      {
        color(arr[j][i][k]);
      }
      printf(" ");
    }
    printf("\n");
  }

  // and the bottom face
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      color(arr[5][i][j]);
    }
    printf("\n");
  }

    return;
}

// changes all the colors to it's starting position
void solve(int cube[][3][3])
{
  int i, j, k;

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

  return;
}

// generates 50 random numbers from 0 to 35 and takes every number as an action
// it also prints every move that has been made to scramble the cube
void mix(int cube[][3][3])
{
  int combos[50];
  int i = 0;

  srand(time(NULL));

  for(i = 0; i < 50; i++)
  {
    combos[i] = rand() % 36;

    switch(combos[i])
    {
      case 0:
      {
        printf("U ");
        U(cube);
        break;
      }
      case 1:
      {
        printf("U' ");
        Up(cube);
        break;
      }
      case 2:
      {
        printf("u ");
        u(cube);
        break;
      }
      case 3:
      {
        printf("u' ");
        up(cube);
        break;
      }

      case 4:
      {
        printf("D ");
        D(cube);
        break;
      }
      case 5:
      {
        printf("D' ");
        Dp(cube);
        break;
      }
      case 6:
      {
        printf("d ");
        d(cube);
        break;
      }
      case 7:
      {
        printf("d' ");
        dp(cube);
        break;
      }

      case 8:
      {
        printf("F ");
        F(cube);
        break;
      }
      case 9:
      {
        printf("F' ");
        Fp(cube);
        break;
      }
      case 10:
      {
        printf("f ");
        f(cube);
        break;
      }
      case 11:
      {
        printf("f' ");
        fp(cube);
        break;
      }

      case 12:
      {
        printf("B ");
        B(cube);
        break;
      }
      case 13:
      {
        printf("B' ");
        Bp(cube);
        break;
      }
      case 14:
      {
        printf("b ");
        b(cube);
        break;
      }
      case 15:
      {
        printf("b' ");
        bp(cube);
        break;
      }

      case 16:
      {
        printf("L ");
        L(cube);
        break;
      }
      case 17:
      {
        printf("L' ");
        Lp(cube);
        break;
      }
      case 18:
      {
        printf("l ");
        l(cube);
        break;
      }
      case 19:
      {
        printf("l' ");
        lp(cube);
        break;
      }

      case 20:
      {
        printf("R ");
        R(cube);
        break;
      }
      case 21:
      {
        printf("R' ");
        Rp(cube);
        break;
      }
      case 22:
      {
        printf("r ");
        r(cube);
        break;
      }
      case 23:
      {
        printf("r' ");
        rp(cube);
        break;
      }

      case 24:
      {
        printf("m ");
        m(cube);
        break;
      }
      case 25:
      {
        printf("m' ");
        mp(cube);
        break;
      }
      case 26:
      {
        printf("e ");
        e(cube);
        break;
      }
      case 27:
      {
        printf("e' ");
        ep(cube);
        break;
      }
      case 28:
      {
        printf("s ");
        s(cube);
        break;
      }
      case 29:
      {
        printf("s' ");
        sp(cube);
        break;
      }

      case 30:
      {
        printf("x ");
        x(cube);
        break;
      }
      case 31:
      {
        printf("x' ");
        xp(cube);
        break;
      }
      case 32:
      {
        printf("y ");
        y(cube);
        break;
      }
      case 33:
      {
        printf("y' ");
        yp(cube);
        break;
      }
      case 34:
      {
        printf("z ");
        z(cube);
        break;
      }
      case 35:
      {
        printf("z' ");
        zp(cube);
        break;
      }
    }
  }

  printf("\n");

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

// rotate s the full cube in it's x axis
void x(int cube[][3][3])
{
  r(cube);
  Lp(cube);
  return;
}

void xp(int cube[][3][3])
{
  x(cube);
  x(cube);
  x(cube);

  return;
}

// rotate s the full cube in it's y axis
void y(int cube[][3][3])
{
  u(cube);
  Dp(cube);

  return;
}

void yp(int cube[][3][3])
{
  y(cube);
  y(cube);
  y(cube);

  return;
}

// rotates the full cube in it's z axis
void z(int cube[][3][3])
{
  f(cube);
  Bp(cube);

  return;
}

void zp(int cube[][3][3])
{
  z(cube);
  z(cube);
  z(cube);

  return;
}

// rotates a medium layer of the cube
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

void mp(int cube[][3][3])
{
  m(cube);
  m(cube);
  m(cube);

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

void ep(int cube[][3][3])
{
  e(cube);
  e(cube);
  e(cube);

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

void sp(int cube[][3][3])
{
  s(cube);
  s(cube);
  s(cube);

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

void Up(int cube[][3][3])
{
  U(cube);
  U(cube);
  U(cube);

  return;
}

void u(int cube[][3][3])
{
  U(cube);
  ep(cube);
}

void up(int cube[][3][3])
{
  Up(cube);
  e(cube);
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

void Dp(int cube[][3][3])
{
  D(cube);
  D(cube);
  D(cube);

  return;
}

void d(int cube[][3][3])
{
  D(cube);
  e(cube);
}

void dp(int cube[][3][3])
{
  Dp(cube);
  ep(cube);
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

void Rp(int cube[][3][3])
{
  R(cube);
  R(cube);
  R(cube);

  return;
}

void r(int cube[][3][3])
{
  R(cube);
  mp(cube);

  return;
}

void rp(int cube[][3][3])
{
  Rp(cube);
  m(cube);

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

void Lp(int cube[][3][3])
{
  L(cube);
  L(cube);
  L(cube);

  return;
}

void l(int cube[][3][3])
{
  L(cube);
  m(cube);

  return;
}

void lp(int cube[][3][3])
{
  Lp(cube);
  mp(cube);

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

void Fp(int cube[][3][3])
{
  F(cube);
  F(cube);
  F(cube);

  return;
}

void f(int cube[][3][3])
{
  F(cube);
  s(cube);

  return;
}

void fp(int cube[][3][3])
{
  Fp(cube);
  sp(cube);

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

void Bp(int cube[][3][3])
{
  B(cube);
  B(cube);
  B(cube);

  return;
}

void b(int cube[][3][3])
{
  B(cube);
  sp(cube);

  return;
}

void bp(int cube[][3][3])
{
  Bp(cube);
  s(cube);

  return;
}