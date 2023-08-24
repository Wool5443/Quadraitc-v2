#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "solve_quadratic.h"
#include "utils.h"

int solveQuadratic(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);
    for (int i = 0; i < NUMBER_OF_COEFFICIENTS; i++)
        myAssert(isfinite(equation->coefficients[i]), ERROR_BAD_NUMBER);

    double a = equation->coefficients[0];
    double b = equation->coefficients[1];
    double c = equation->coefficients[2];

    if (isEqual(a, 0))
        solveLinear(equation);
    else
    {
        double discr = b * b - 4 * a * c;

        if (isEqual(discr, 0))
            *equation = { .roots = {-b / (2 * a), NAN},
                          .numberOfRoots = ONE_ROOT };
        else if (discr < 0)
            *equation = { .roots = {NAN, NAN},
                          .numberOfRoots = ZERO_ROOTS };
        else
        {
            double sqrtDiscr = sqrt(discr);
            *equation = { .roots = {(-b - sqrtDiscr) / (2 * a),
                                    (-b + sqrtDiscr) / (2 * a)},
                          .numberOfRoots = TWO_ROOTS };
        }
    }

    return EVERYTHING_FINE;
}

int solveLinear(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);
    for (int i = NUMBER_OF_COEFFICIENTS - COEFF_SHIFT_FOR_LINEAR; i < NUMBER_OF_COEFFICIENTS; i++)
        myAssert(isfinite(equation->coefficients[i]), ERROR_BAD_NUMBER);

    double b = equation->coefficients[1];
    double c = equation->coefficients[2];

    if (isEqual(b, 0))
        if (isEqual(c, 0))
        {
            *equation = { .roots = {NAN, NAN},
                          .numberOfRoots = INFINITE_ROOTS };
        }
        else
        {
            *equation = { .roots = {NAN, NAN},
                          .numberOfRoots = ZERO_ROOTS };
        }
    else
    {
        *equation = { .roots = {-c / b, NAN},
                      .numberOfRoots = ONE_ROOT };
    }

    return EVERYTHING_FINE;
}

int inputEquation(Equation* equation)
{
    myAssert(equation, ERROR_NULLPTR);

    printf("Input the coefficients of the equation: ");

    while (scanf("%lf %lf %lf", equation->coefficients, equation->coefficients + 1, equation->coefficients + 2) != 3
        || getchar() != '\n')
    {
        printf("Invalid input, try again: ");
        clearBuffer();
    }

    return EVERYTHING_FINE;
}

int printAnswer(const Equation* equation)
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

    return EVERYTHING_FINE;
}
