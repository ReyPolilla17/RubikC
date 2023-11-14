# RubikC
**This is a bidimentional representation of a Rubik's Cube:**

- It obeys every cube notation.
- It can get scrambled using the S command.
- It can be solved using the S' command.
- It registers every movement that has been made in the scramble and by the user.
- To finish the program use the Q command.

## Contents
On every .c file there are stored different kinds of functions to make it easier to debug;
1. [miscs.c](./miscs.c) Includes the solving and mixing functions.
2. [prints.c](./prints.c) Includes all the cube and algorithms printing functions.
3. [r-blocks.c](./r-blocks.c) Includes the clockwhise movements that move more than one layer.
4. [r-layers.c](./r-layers.c) Includes every clockwhise movement by layer.
5. [rp-blocks.c](./rp-blocks.c) Includes the counter-clockwhise movements that move more than one layer.
6. [rp-layers.c](./r-layers.c) Includes every counter-clockwhise movement by layer (you will notice they only call they alternate function trice).

> [cube.h](./cube.h) Is a local library to link every .c file to the main file.
> 
> [Makefile](./Makefile) Compiles and chains every file into the executable.

## Scripts
This scripts are included in [Makefile](./Makefile)
- ``make`` - Compiles the full project and chains it into a .out executable.
- ``make clear`` - Removes .o, .out and .txt files from the directory.
- ``make push m="[arg]"`` - Creates a commit and pushes it into Github.

## To do:
- **A timer:** - When you use de mixing command (S) a timer starts and when you solve the cube using the command (S') or by yourself, it displays the time it took you.
- **Help command** - (H) to display all the commands aviable.

## Notations
https://jperm.net/images/notation.png
