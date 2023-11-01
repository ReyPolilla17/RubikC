#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cube.h"

// in some cases, ending the program results in a stack smashing detection

/* Colors:
Text decoration:
Reset: \x1b[0m
Bold: \x1b[1m
Faint: \x1b[2mmpuuse
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

int main(void)
{
  // the cube works with numbers instead of colors
  int cube[6][3][3] = {{{1,1,1},{1,1,1},{1,1,1}}, {{2,2,2},{2,2,2},{2,2,2}}, {{3,3,3},{3,3,3},{3,3,3}}, {{4,4,4},{4,4,4},{4,4,4}}, {{5,5,5},{5,5,5},{5,5,5}}, {{6,6,6},{6,6,6},{6,6,6}}};

  // action is a string of 2 chars to make it possible to use the '
  char a[2];

  // movements that have been made
  int i = 0;

  // a file to store the movements
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
    // addM is to add the movement that has been made to the file
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