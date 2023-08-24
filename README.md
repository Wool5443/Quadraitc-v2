# Quadraitc-v2
Improved in many ways version of Quadratic-equation

## Instalation

Clone the repo and use make. You can also use src and headers in your own program by including them and compiling all the files together.

```bash

git clonde Quadrativ-v2
cd Quadratic-v2
make

```

## Usage

```c++
#include "solve_quadratic.h"

// Creates an equation
Equation eq = {};

// Lets the user input coefficients of the equation
InputEquation(&eq); // Input the coefficients of the equation: <a> <b> <c><return>

// Solves the equation
SolveEquation(&eq); // The roots are stored in eq.roots

// Prints the roots to stdout
PrintAnswer(&eq);
```
