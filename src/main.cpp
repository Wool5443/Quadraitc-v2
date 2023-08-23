#include <stdio.h>
#include "../headers/tester.h"
#include "../headers/solve_quadratic.h"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        test(*(argv + 1));
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
