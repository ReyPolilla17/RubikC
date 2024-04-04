#include "cube.h"

/**
 * Program created by Polilla
 * This is a virtual Rubik's cube created for the only purpose of learning an playing with some C characteristics
*/
int main(void)
{
  // array of functions
  void (*printCube[2])(int cube[][3][3]) = { printC, print3D };

  // the main cube
  Rubik_Cube cube;

  // perspective
  int p = 1;

  // repeat
  int r = 1;

  // initializing functions
  srand(time(NULL));
  initialize(&cube, 1);

  system("clear");

  // while r is not 0
  while(r)
  {
    // print the cube with the specified perspective as well as all the movements if cube is not solved
    (*printCube[p])(cube.matrix);
    printM(&cube);
    
    // reads user input
    readIns(&cube.str);
    system("clear");

    // if user inputs an instruction
    if(cube.str[0] == 'i' && cube.str[1] == ':')
    {
      // gets user instruction 
      switch(getIns(cube.str))
      {
        // ends the program
        case 1:
        {
          r = 0;
          break;
        }
        // prints help message
        case 2:
        {
          printHelp();
          break;
        }
        // mixes the cube
        case 3:
        {
          mix(&cube);
          break;
        }
        // solves the cube
        case 4:
        {
          initialize(&cube, 0);
          break;
        }
        // finds a solution to the cube (not done yet)
        case 5:
        {
          printf("solution\n\n");
          break;
        }
        // changes cube perspective
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
        // unknown instruction
        default:
        {
          printf("Unknown instruction, use 'i:help' to see the aviable instructions...\n\n");
          break;
        }
      }
    }
    else
    {
      // gets parenthesis pairs to create a set of instructions
      getPairs(&cube.str, &cube.par_start);
      createSet(&cube, 1, 0, 1);

      // frees parenthesis pairs
      freeStruct((void **)&cube.par_start);
    }
    
    // frees dynamic string if needed
    if(cube.str != NULL)
    {
      free(cube.str);
      cube.str = NULL;
    }
  }
  
  // frees every structure in the cube
  initialize(&cube, 0);

  return 0;
}