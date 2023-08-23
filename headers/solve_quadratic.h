//--------------------------------------------------------------------------------------------------------------
// This library can solve quadratic and lineare equations in these forms: ax2 + bx + c = 0, bx + c = 0
//! @param [in] a - a-coefficient
//! @param [in] b - b-coefficient
//! @param [in] c - c-coefficient
//! @param [out] ans - structure, containing the roots in an array and an int containing the number of roots
//! 					   if the root is not present it is set to NAN
//! 
//! @note in case of infinte rules, ans.numberOfRoots returns to be ALL_REAL_NUMBERS
//--------------------------------------------------------------------------------------------------------------

#ifndef SOLVE_QUADRATIC_H
#define SOLVE_QUADRATIC_H

const int NUMBER_OF_COEFFICIENTS = 3, MAX_NUMBER_OF_ROOTS = 2;

enum NumberOfRoots { INFINITE_ROOTS = -1, ZERO_ROOTS, ONE_ROOT, TWO_ROOTS };

struct Equation
{
	double coefficients[NUMBER_OF_COEFFICIENTS];
	double roots[MAX_NUMBER_OF_ROOTS];
	NumberOfRoots numberOfRoots;
};

void solveQuadratic(Equation* equation); //solves quadratic equation ax2+bx+c=0 and outputs to ans

void solveLinear(Equation* equation); //solves linear equation bx+c=0 and outputs to ans

void inputEquation(Equation*); //takes input from user and stores it in a, b, c

void printAnswer(const Equation* equation); //prints all the roots of the equation if given an Answer

#endif