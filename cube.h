#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct def_generic
{
  void *next;
} Generic;

typedef struct def_stack
{
  struct def_stack *next;
  int pos;
} Stack;

typedef struct def_parentesis
{
  struct def_parentesis *next;
  int start;
  int end;
} Parentesis;

typedef struct def_character
{
  struct def_character *next;
  char cur;
} Character;

typedef struct def_instruction
{
  struct def_instruction *next;
  char wd[3];
} Instruction;

typedef struct def_rubik_cube
{
  Parentesis *par_start;
  Instruction *inst_start;
  char *str;
  int matrix[6][3][3];
} Rubik_Cube;

/* Colors:
    Text decoration:         Text color:             Background color:

    Reset:     \x1b[0m       Black:   \x1b[30m       Black:   \x1b[40m
    Bold:      \x1b[1m       Red:     \x1b[31m       Red:     \x1b[41m
    Faint:     \x1b[2m       Green:   \x1b[32m       Green:   \x1b[42m
    Italic:    \x1b[3m       Yellow:  \x1b[33m       Yellow:  \x1b[43m
    Underline: \x1b[4m       Blue:    \x1b[34m       Blue:    \x1b[44m
    Blink:     \x1b[5m       Magenta: \x1b[35m       Magenta: \x1b[45m
    Inverse:   \x1b[7m       Cyan:    \x1b[36m       Cyan:    \x1b[46m
    Hidden:    \x1b[8m       White:   \x1b[37m       White:   \x1b[47m
    Strikeout: \x1b[9m
*/


//Each block of functions is used for different purposes

// creating a movement set
void readIns(char **str);
void getPairs(char **inst, Parentesis **start);
void createSet(Rubik_Cube *cube, int mainS, int spos, int sum);
void addM(Instruction **start, char move[]);
void getRep(char inst[], int *i, int *rep, int *sgn, int mSgn);
int getSpace(Parentesis *start, int pos);
int getIns(char *str);

// data manadgement
void initialize(Rubik_Cube *cube, int s);
void freeStruct(void **start);
void moveCube(int cube[][3][3], char move[]);
void mix(Rubik_Cube *cube);
int solved(int cube[][3][3]);

// printing functions
void printM(Rubik_Cube *cube);
void printC(int cube[][3][3]);
void print3D(int cube[][3][3]);
void printHelp(void);

// rotating a face
void rot(int cube[][3][3], int layer);

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