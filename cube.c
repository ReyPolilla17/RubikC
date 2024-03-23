#include "cube.h"

int main(void)
{
  void (*printCube[2])(int cube[][3][3]) = { printC, print3D };

  Rubik_Cube cube;

  char inst[3];

  int p = 1;
  int r = 1;

  srand(time(NULL));

  system("clear");
  initialize(&cube, 1);

  do
  {
    (*printCube[p])(cube.matrix);
    printM(&cube);
    
    readIns(&cube.str);
    system("clear");

    sprintf(inst, "%c%c", cube.str[0], cube.str[1]);

    if(!strcmp(inst, "i:"))
    {
      switch(getIns(cube.str))
      {
        case 1:
        {
          r = 0;
          break;
        }
        case 2:
        {
          printHelp();
          break;
        }
        case 3:
        {
          mix(&cube);
          break;
        }
        case 4:
        {
          initialize(&cube, 0);
          break;
        }
        case 5:
        {
          printf("solution\n\n");
          break;
        }
        case 6:
        {
          if(p)
          {
            p--;
          }
          else
          {
            p++;
          }
          break;
        }
        default:
        {
          printf("Unknown instruction, use 'i:help' to see the aviable instructions...\n\n");
          break;
        }
      }
    }
    else
    {
      getPairs(&cube.str, &cube.par_start);
      createSet(&cube, 1, 0, 1);

      freeStruct((void **)&cube.par_start);
      free(cube.str);
    }
  } while(r);
  
  freeStruct((void **)&cube.inst_start);

  return 0;
}