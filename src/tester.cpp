#include <stdio.h>
#include <math.h>
#include "../headers/tester.h"
#include "../headers/solve_quadratic.h"
#include "../headers/utils.h"

bool checkSolution(Equation* solution, double correctRoots[], NumberOfRoots numberOfRoots);

void test(const char* testFile)
{
	FILE* file = fopen(testFile, "r");

	Equation equation = {};

	double coeffs[NUMBER_OF_COEFFICIENTS] = {}, correctRoots[MAX_NUMBER_OF_ROOTS] = {};

	int numberOfPassedTests = 0, numberOfAllTests = 0;

	NumberOfRoots numberOfRoots = ZERO_ROOTS;

	fscanf(file, "%d", &numberOfAllTests);

	for (int i = 0; i < numberOfAllTests; i++)
	{
		fscanf(file, "%lf %lf %lf %d", coeffs, coeffs + 1, coeffs + 2, (int*)&numberOfRoots);
		switch (numberOfRoots)
		{
		case -1:
		case 0:
			break;
		case 1:
			fscanf(file, "%lf", correctRoots);
			break;
		case 2:
			fscanf(file, "%lf %lf", correctRoots, correctRoots + 1);
			break;
		default:
			fprintf(stderr, "BAD TEST %d!!!\n", i + 1);
			break;
		}

		copyArray(equation.coefficients, coeffs, NUMBER_OF_COEFFICIENTS);
		solveQuadratic(&equation);

		if (checkSolution(&equation, correctRoots, numberOfRoots))
		{
			setConsoleColor(GREEN);
			printf("Test number %d is successful! %.2f%% of tests have been run!\n", i + 1,
				(double)(i + 1) / numberOfAllTests * 100);
			setConsoleColor(WHITE);
			numberOfPassedTests++;
		}
		else
		{
			setConsoleColor(RED);
			printf("Test number %d failed!!!!!!!! %.2f%% of tests have been run!\n", i + 1,
				(double)(i + 1) / numberOfAllTests * 100);
			setConsoleColor(WHITE);
		}
	}

	fclose(file);

	if (numberOfPassedTests == numberOfAllTests)
	{
		setConsoleColor(GREEN);
		printf("ALL TESTS ARE WORKING PURRRFECTLY!!!\n");
		setConsoleColor(WHITE);
	}
	else
	{
		setConsoleColor(RED);
		printf("ONLY %.0f%% OF TESTS PASSED!!!\n", (double)numberOfPassedTests / numberOfAllTests * 100);
		setConsoleColor(WHITE);
	}
}

bool checkSolution(Equation* solution, double correctRoots[], NumberOfRoots numberOfRoots)
{
	myAssert(solution, ERROR_NULLPTR);

	if (solution->numberOfRoots != numberOfRoots)
		return false;
	for (int i = 0; i < numberOfRoots; i++)
		if (realCompare(solution->roots[i], correctRoots[i]) != EQUAL)
			return false;
	return true;
}

