#include <stdio.h>
#include "tester.hpp"
#include "solve_quadratic.hpp"

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        TestAll(*(argv + 1));
    }
    else
    {
        Equation equation = {};
        InputEquation(&equation);
        SolveEquation(&equation);
        PrintAnswer(&equation);
    }
    return 0;
}
