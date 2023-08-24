#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "solve_quadratic.hpp"
#include "utils.hpp"

void solveQuadratic(Equation* equation);

void solveLinear(Equation* equation);

void SolveEquation(Equation* equation)
{
    myAssertHard(equation, ERROR_NULLPTR);
    for (int i = 0; i < NUMBER_OF_COEFFICIENTS; i++)
        myAssertHard(isfinite(equation->coefficients[i]), ERROR_BAD_NUMBER);

    if (IsEqual(equation->coefficients[0], 0))
        solveLinear(equation);
    else
        solveQuadratic(equation);
}

void solveQuadratic(Equation* equation)
{
    double a = equation->coefficients[0];
    double b = equation->coefficients[1];
    double c = equation->coefficients[2];

    double discr = b * b - 4 * a * c;
    if (IsEqual(discr, 0))
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

void solveLinear(Equation* equation)
{
    double b = equation->coefficients[1];
    double c = equation->coefficients[2];

    if (IsEqual(b, 0))
        if (IsEqual(c, 0))
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
}

void InputEquation(Equation* equation)
{
    myAssertHard(equation, ERROR_NULLPTR);

    printf("Input the coefficients of the equation: ");

    while (scanf("%lf %lf %lf", equation->coefficients, equation->coefficients + 1, equation->coefficients + 2) != 3
        || getchar() != '\n')
    {
        printf("Invalid input, try again: ");
        ClearBuffer();
    }
}

void PrintAnswer(const Equation* equation)
{
    myAssertHard(equation, ERROR_NULLPTR);

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
