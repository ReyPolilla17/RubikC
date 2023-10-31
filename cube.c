#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Colors:
Text decoration:
Reset: \x1b[0m
Bold: \x1b[1m
Faint: \x1b[2m
Italic: \x1b[3m
Underline: \x1b[4m
Blink: \x1b[5m
Inverse: \x1b[7m
Hidden: \x1b[8m
Strikeout: \x1b[9m

Text color:
Black: \x1b[30m
Red: \x1b[31m
Green: \x1b[32m
Yellow: \x1b[33m
Blue: \x1b[34m
Magenta: \x1b[35m
Cyan: \x1b[36m
White: \x1b[37m

Background color:
Black: \x1b[40m
Red: \x1b[41m
Green: \x1b[42m
Yellow: \x1b[43m
Blue: \x1b[44m
Magenta: \x1b[45m
Cyan: \x1b[46m
White: \x1b[47m
*/

//Each block of functions is used for different purposes

// printing the cube
void color(int value);
void printC(int arr[][3][3]);
void printM(int *size);
void addM(int *size, char a[]);

// rotating a face
void rot(int cube[][3][3], int layer);
void rot_p(int cube[][3][3], int layer);

// complete actions
void mix(int cube[][3][3], int *size);
void solve(int cube[][3][3], int *size);

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

  int i = 0;

  FILE *movesFile;

  movesFile = fopen("moves.txt", "w");
  fclose(movesFile);

  // Q will be the stopper
  while(a[0] != 'Q')
  {
    // every action will clear the terminal and print the resulting cube
    printM(&i);
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
          addM(&i, "U");
        }
        else if(a[1] == '\'')
        {
          Up(cube);
          addM(&i, "U'");
        }
        break;
      }
      case 'u':
      {
        if(a[1] == '\0')
        {
          u(cube);
          addM(&i, "u");
        }
        else if(a[1] == '\'')
        {
          up(cube);
          addM(&i, "u'");
        }
        break;
      }
      case 'D':
      {
        if(a[1] == '\0')
        {
          D(cube);
          addM(&i, "D");
        }
        else if(a[1] == '\'')
        {
          Dp(cube);
          addM(&i, "D'");
        }
        break;
      }
      case 'd':
      {
        if(a[1] == '\0')
        {
          d(cube);
          addM(&i, "d");
        }
        else if(a[1] == '\'')
        {
          dp(cube);
          addM(&i, "d'");
        }
        break;
      }
      case 'R':
      {
        if(a[1] == '\0')
        {
          R(cube);
          addM(&i, "R");
        }
        else if(a[1] == '\'')
        {
          Rp(cube);
          addM(&i, "R'");
        }
        break;
      }
      case 'r':
      {
        if(a[1] == '\0')
        {
          r(cube);
          addM(&i, "r");
        }
        else if(a[1] == '\'')
        {
          rp(cube);
          addM(&i, "r'");
        }
        break;
      }
      case 'L':
      {
        if(a[1] == '\0')
        {
          L(cube);
          addM(&i, "L");
        }
        else if(a[1] == '\'')
        {
          Lp(cube);
          addM(&i, "L'");
        }
        break;
      }
      case 'l':
      {
        if(a[1] == '\0')
        {
          l(cube);
          addM(&i, "l");
        }
        else if(a[1] == '\'')
        {
          lp(cube);
          addM(&i, "l'");
        }
        break;
      }
      case 'F':
      {
        if(a[1] == '\0')
        {
          F(cube);
          addM(&i, "F");
        }
        else if(a[1] == '\'')
        {
          Fp(cube);
          addM(&i, "F'");
        }
        break;
      }
      case 'f':
      {
        if(a[1] == '\0')
        {
          f(cube);
          addM(&i, "f");
        }
        else if(a[1] == '\'')
        {
          fp(cube);
          addM(&i, "f'");
        }
        break;
      }
      case 'B':
      {
        if(a[1] == '\0')
        {
          B(cube);
          addM(&i, "B");
        }
        else if(a[1] == '\'')
        {
          Bp(cube);
          addM(&i, "B'");
        }
        break;
      }
      case 'b':
      {
        if(a[1] == '\0')
        {
          b(cube);
          addM(&i, "b");
        }
        else if(a[1] == '\'')
        {
          bp(cube);
          addM(&i, "b'");
        }
        break;
      }
      case 'm':
      {
        if(a[1] == '\0')
        {
          m(cube);
          addM(&i, "m");
        }
        else if(a[1] == '\'')
        {
          mp(cube);
          addM(&i, "m'");
        }
        break;
      }
      case 'e':
      {
        if(a[1] == '\0')
        {
          e(cube);
          addM(&i, "e");
        }
        else if(a[1] == '\'')
        {
          ep(cube);
          addM(&i, "e'");
        }
        break;
      }
      case 'S':
      {
        if(a[1] == '\0')
        {
          mix(cube, &i);
        }
        else if(a[1] == '\'')
        {
          solve(cube, &i);
        }
        break;
      }
      case 's':
      {
        if(a[1] == '\0')
        {
          s(cube);
          addM(&i, "s");
        }
        else if(a[1] == '\'')
        {
          sp(cube);
          addM(&i, "s'");
        }
        break;
      }
      case 'x':
      {
        if(a[1] == '\0')
        {
          x(cube);
          addM(&i, "x");
        }
        else if(a[1] == '\'')
        {
          xp(cube);
          addM(&i, "x'");
        }
        break;
      }
      case 'y':
      {
        if(a[1] == '\0')
        {
          y(cube);
          addM(&i, "y");
        }
        else if(a[1] == '\'')
        {
          yp(cube);
          addM(&i, "y'");
        }
        break;
      }
      case 'z':
      {
        if(a[1] == '\0')
        {
          z(cube);
          addM(&i, "z");
        }
        else if(a[1] == '\'')
        {
          zp(cube);
          addM(&i, "z'");
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

void printM(int *size)
{
  char moves[*size * 2];

  FILE *movesFile;

  if(*size == 0)
  {
    return;
  }

  movesFile = fopen("moves.txt", "r");
  fscanf(movesFile, "%[^\3]", moves);
  fclose(movesFile);

  printf("%s\n", moves);

  return;
}

void addM(int *size, char a[])
{
  char moves[*size * 3];
  char move[*size][3];

  int i = 0;
  int j = 0;
  int k = 0;

  FILE *movesFile;

  movesFile = fopen("moves.txt", "a");
  fprintf(movesFile, "%s ", a);
  fclose(movesFile);

  *size += 1;

  movesFile = fopen("moves.txt", "r");
  fscanf(movesFile, "%[^\3]", moves);
  fclose(movesFile);

  for(i = 0; moves[i] != 0; i++)
  {
    if(moves[i] != ' ')
    {
      move[j][k] = moves[i];
      k++;
    }
    else
    {
      move[j][k] = '\0';
      j++;
      k = 0;
    }
  }

  if(*size - 2 >= 0)
  {
    if(strcmp(move[*size - 1], move[*size - 2]) == 0)
    {
      move[*size - 2][0] = move[*size - 1][0];
      move[*size - 2][1] = '2';
      move[*size - 2][2] = '\0';
      move[*size - 1][0] = '\0';
      
      *size -= 1;
    }
    else if(move[*size - 1][0] == move[*size - 2][0] && move[*size - 2][1] == '2')
    {
      if(move[*size - 1][1] == '\'')
      {
        move[*size - 2][0] = move[*size - 1][0];
        move[*size - 2][1] = '\0';
        move[*size - 1][0] = '\0';
      }
      else
      {
        move[*size - 2][0] = move[*size - 1][0];
        move[*size - 2][1] = '\'';
        move[*size - 1][0] = '\0';
      }
      
      *size -= 1;
    }
    else if(move[*size - 1][0] == move[*size - 2][0] && ((move[*size - 2][1] == '\'' && move[*size - 1][1] == '\0') || (move[*size - 2][1] == '\0' && move[*size - 1][1] == '\'')))
    {
      move[*size - 2][0] = '\0';
      move[*size - 1][0] = '\0';
      
      *size -= 2;
    }
  }

  movesFile = fopen("moves.txt", "w");

  for(i = 0; i < *size; i++)
  {
    if(strlen(move[i]) != 0)
    {
      fprintf(movesFile, "%s ", move[i]);
    }
  }
  
  fclose(movesFile);

  return;
}

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

// rotates a medium layer of the cube
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

// rotates a medium layer of the cube
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