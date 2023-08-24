# Quadraitc-v2
Improve in many ways version of Quadratic-equation

## Instalation

Clone the repo and use make. You can also use src and headers in your own program by including them and compiling all the files together.

## Usage

```c++
#include "solve_quadratic.h"

// Creates an equation
Equation eq = {};

// Lets the user input coefficients of the equation
InputEquation(&eq);

// Solves the equation
SolveEquation(&eq);

// Prints the roots to stdout
PrintAnswer(&eq);
```
