#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "../headers/solve_quadratic.h"
#include "../headers/utils.h"

void solveQuadratic(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);
    for (int i = 0; i < NUMBER_OF_COEFFICIENTS; i++)
        myAssert(isfinite(equation->coefficients[i]), ERROR_BAD_NUMBER);

    double a = equation->coefficients[0], b = equation->coefficients[1], c = equation->coefficients[2];

    if (realCompare(a, 0) == EQUAL)
        solveLinear(equation);
    else
    {
        double discr = b * b - 4 * a * c;

        if (realCompare(discr, 0) == EQUAL)
        {
            equation->roots[0] = -b / (2 * a);
            equation->roots[1] = NAN;
            equation->numberOfRoots = ONE_ROOT;
        }
        else if (discr < 0)
        {
            equation->roots[0] = NAN;
            equation->roots[1] = NAN;
            equation->numberOfRoots = ZERO_ROOTS;
        }
        else
        {
            double sqrtDiscr = sqrt(discr);
            equation->roots[0] = (-b - sqrtDiscr) / (2 * a);
            equation->roots[1] = (-b + sqrtDiscr) / (2 * a);
            equation->numberOfRoots = TWO_ROOTS;
        }
    }
}

void solveLinear(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);
    for (int i = 1; i < NUMBER_OF_COEFFICIENTS; i++)
        assert(isfinite(equation->coefficients[i]));

    double b = equation->coefficients[1], c = equation->coefficients[2];

    if (realCompare(b, 0) == EQUAL)
        if (realCompare(c, 0) == EQUAL)
        {
            equation->roots[0] = NAN;
            equation->roots[1] = NAN;
            equation->numberOfRoots = INFINITE_ROOTS;
        }
        else
        {
            equation->roots[0] = NAN;
            equation->roots[1] = NAN;
            equation->numberOfRoots = ZERO_ROOTS;
        }
    else
    {
        equation->roots[0] = -c / b;
        equation->roots[1] = NAN;
        equation->numberOfRoots = ONE_ROOT;
    }
}

void inputEquation(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);

    printf("Input the coefficients of the equation: ");

    while (scanf("%lf %lf %lf", equation->coefficients, equation->coefficients + 1, equation->coefficients + 2) != 3
        || getchar() != '\n')
    {
        printf("Invalid input, try again: ");
        clearBuffer();
    }
}

void printAnswer(const Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);

    switch (equation->numberOfRoots)
    {
    case INFINITE_ROOTS:
        printf("The solutions are all real numbers\n");
        break;
    case TWO_ROOTS:
        printf("The solutions are %g and %g\n", equation->roots[0], equation->roots[1]);
        break;
    case ONE_ROOT:
        printf("The solution is %g\n", equation->roots[0]);
        break;
    case ZERO_ROOTS:
        printf("There are no solutions\n");
        break;
    default:
        printf("ERROR!!! Wrong number of roots: %d\n", equation->numberOfRoots);
        break;
    }
}
