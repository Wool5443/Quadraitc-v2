#include <stdio.h>
#include <math.h>
#include "tester.h"
#include "solve_quadratic.h"
#include "utils.h"

bool checkSolution(Equation* solution, Equation* testData);

int testAll(const char* testFile)
{
	FILE* file = fopen(testFile, "r");
	myAssert(file, ERROR_BAD_FILE);

	int numberOfPassedTests = 0, numberOfAllTests = 0;

	fscanf(file, "%d", &numberOfAllTests);

	for (int i = 0; i < numberOfAllTests; i++)
	{
		Equation equation = {};
		Equation testData = {};

		fscanf(file, "%lf %lf %lf %d",
			testData.coefficients,
			testData.coefficients + 1,
			testData.coefficients + 2,
			(int*)&testData.numberOfRoots);

		switch (testData.numberOfRoots)
		{
		case INFINITE_ROOTS:
		case ZERO_ROOTS:
			break;
		case ONE_ROOT:
			fscanf(file, "%lf", testData.roots);
			break;
		case TWO_ROOTS:
			fscanf(file, "%lf %lf", testData.roots, testData.roots + 1);
			break;
		default:
			fprintf(stderr, "BAD TEST %d!!!\n", i + 1);
			break;
		}

		copyArray(equation.coefficients, testData.coefficients, NUMBER_OF_COEFFICIENTS);
		solveQuadratic(&equation);

		if (checkSolution(&equation, &testData) == 1)
		{
			setConsoleColor(stdout, GREEN);
			printf("Test number %d is successful! %.2f%% of tests have been run!\n", i + 1,
				(double)(i + 1) / numberOfAllTests * 100);
			setConsoleColor(stdout, WHITE);
			numberOfPassedTests++;
		}
		else
		{
			setConsoleColor(stdout, RED);
			printf("Test number %d failed!!!!!!!! %.2f%% of tests have been run!\n", i + 1,
				(double)(i + 1) / numberOfAllTests * 100);
			setConsoleColor(stdout, WHITE);
		}
	}

	fclose(file);

	if (numberOfPassedTests == numberOfAllTests)
	{
		setConsoleColor(stdout, GREEN);
		printf("ALL TESTS ARE WORKING PURRRFECTLY!!!\n");
		setConsoleColor(stdout, WHITE);
	}
	else
	{
		setConsoleColor(stdout, RED);
		printf("ONLY %.0f%% OF TESTS PASSED!!!\n", (double)numberOfPassedTests / numberOfAllTests * 100);
		setConsoleColor(stdout, WHITE);
	}

	return EVERYTHING_FINE;
}

bool checkSolution(Equation* solution, Equation* testData)
{
	myAssert(solution, ERROR_NULLPTR);
	myAssert(testData, ERROR_NULLPTR);

	if (solution->numberOfRoots != testData->numberOfRoots)
		return false;
	for (int i = 0; i < testData->numberOfRoots; i++)
		if (!isEqual(solution->roots[i], testData->roots[i]))
			return false;
	return true;
}
