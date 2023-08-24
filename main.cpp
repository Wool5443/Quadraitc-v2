#include <stdio.h>
#include "tester.hpp"
#include "solve_quadratic.hpp"

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
        solveEquation(&equation);
        printAnswer(&equation);
    }

    return 0;
}
