#include <stdio.h>
#include "tester.h"
#include "solve_quadratic.h"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        testAll(*(argv + 1));
    }
    else
    {
        Equation equation = {};
        inputEquation(&equation);
        solveQuadratic(&equation);
        printAnswer(&equation);
    }

    return 0;
}
