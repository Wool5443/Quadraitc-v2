//-------------------------------------------------------------------------------------------------------------------
// This library can solve quadratic and linear equations in these forms: ax2 + bx + c = 0, bx + c = 0
//!
//! @param [in] equation - contains array of coefficients of the problem, array of roots and numberOfRoots of one
//! 
//! @return equation containing an array of roots
//! 
//! @note in case of infinte rules, equation.numberOfRoots contains INFINITE_ROOTS
//-------------------------------------------------------------------------------------------------------------------

#ifndef SOLVE_QUADRATIC_H
#define SOLVE_QUADRATIC_H

//COEFF_SHIFT_FOR_LINEAR dictates how much to shift from the end of Equation.coefficients to solve a linear
const int NUMBER_OF_COEFFICIENTS = 3, MAX_NUMBER_OF_ROOTS = 2, COEFF_SHIFT_FOR_LINEAR = 2;

enum NumberOfRoots { INFINITE_ROOTS = -1, ZERO_ROOTS, ONE_ROOT, TWO_ROOTS };

struct Equation
{
	double coefficients[NUMBER_OF_COEFFICIENTS];
	double roots[MAX_NUMBER_OF_ROOTS];
	NumberOfRoots numberOfRoots;
};

int solveQuadratic(Equation* equation); //solves quadratic equation ax2+bx+c=0 and outputs to ans

int solveLinear(Equation* equation); //solves linear equation bx+c=0 and outputs to ans

int inputEquation(Equation*); //takes input from user and stores it in a, b, c

int printAnswer(const Equation* equation); //prints all the roots of the equation if given an Answer

#endif