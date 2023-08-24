# Quadraitc-v2
Improved in many ways version of Quadratic-equation

## Instalation

Clone the repo and use make. You can also use src and headers in your own program by including them and compiling all the files together.

```bash
git clone https://github.com/Wool5443/Quadraitc-v2
make
```

## Usage

```c++
#include "solve_quadratic.h"

// Creates an equation
Equation eq = {};

// Lets the user input coefficients of the equation
InputEquation(&eq); // Input the coefficients of the equation: <a> <b> <c><return>

// Solves the equation and stores the roots in eq.roots
SolveEquation(&eq); //

// Prints the roots to stdout
PrintAnswer(&eq);
```

In order to run tests run main.exe with path to the tests file

```bash
main.exe testing/tests.txt
```

The test file should look lke this:
<number_of_tests>
<coeff1> <coeff2> <coeff3> <number_of_roots> <roots> // Write <number_of_roots> roots
.
.
.
