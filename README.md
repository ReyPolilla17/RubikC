# RubikC
**This is a bidimentional representation of a Rubik's Cube:**

- It obeys every cube notation.
- It registers every movement that has been made in the scramble and by the user.
- It can get scrambled using i:mix.
- It can be solved using i:solve.
- To finish the program use i:exit.
- Get a help message using i:help (pending).
- Find the shortest solution to the mix using i:solution (pending).

## Funftionality
To use it just write algorithms and press enter, if it doesn't recognize the movement, it will execute the rest of the algorithm without the unknown instruction.

To use instructions, start the line with the i: notation followed by the instruction you want, it will only consider the first word and ignore the rest.

## Contents
On every .c file there are stored different kinds of functions to make it easier to debug:
1. [logic.c](./logic.c) Includes functions to manage the cube status
2. [movements.c](./movements.c) Includes the functions to read and execute instructions.
4. [prints.c](./prints.c) Includes all the cube and algorithms printing functions.
3. [rotation.c](./rotation.c) Includes the basic rotation functions.
5. [r-blocks.c](./r-blocks.c) Includes the clockwhise movements that move more than one layer.
6. [r-layers.c](./r-layers.c) Includes every clockwhise movement by layer.
7. [rp-blocks.c](./rp-blocks.c) Includes the counter-clockwhise movements that move more than one layer.
8. [rp-layers.c](./r-layers.c) Includes every counter-clockwhise movement by layer (you will notice they only call they alternate function trice).

> [cube.h](./cube.h) Is a local library to link every .c file to the main file.
> 
> [Makefile](./Makefile) Compiles and chains every file into the executable.

## Scripts
This scripts are included in [Makefile](./Makefile)
- ``make`` - Compiles the full project and chains it into a .out executable.
- ``make clear`` - Removes .o and .out files from the directory.
- ``make push m="[arg]"`` - Creates a commit and pushes it into Github.

## To do:
- **Help command** - (i:help) to display all the commands aviable.
- **Solution command** - (i:solution) to display the shortest solution (if this works, maybe add a function to coppy a real life cube).

## Notations
https://jperm.net/images/notation.png
