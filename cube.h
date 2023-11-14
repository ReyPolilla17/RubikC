#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Each block of functions is used for different purposes

// printing the cube
void color(int value, char rep[], int m);
void printC(int arr[][3][3]);
void print3D(int cube[][3][3]);
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