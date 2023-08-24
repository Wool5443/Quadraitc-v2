#include <stdio.h>
#include <math.h>
#include "tester.h"
#include "../headers/solve_quadratic.h"
#include "../headers/utils.h"

bool checkSolution(Equation* solution, Equation* testData);

void testAll(const char* testFile)
{
	FILE* file = fopen(testFile, "r");

	if (file == NULL)
	{
		puts("Test file not found :(");
		return;
	}


	int numberOfPassedTests = 0, numberOfAllTests = 0;

	fscanf(file, "%d", &numberOfAllTests);

	for (int i = 0; i < numberOfAllTests; i++)
	{
		Equation equation = {};
		Equation testData = {};

		fscanf(file, "%lf %lf %lf %d", testData.coefficients, testData.coefficients + 1, testData.coefficients + 2,
			(int*)&testData.numberOfRoots);

		switch (testData.numberOfRoots)
		{
		case -1:
		case 0:
			break;
		case 1:
			fscanf(file, "%lf", testData.roots);
			break;
		case 2:
			fscanf(file, "%lf %lf", testData.roots, testData.roots + 1);
			break;
		default:
			fprintf(stderr, "BAD TEST %d!!!\n", i + 1);
			break;
		}

		copyArray(equation.coefficients, testData.coefficients, NUMBER_OF_COEFFICIENTS);
		solveQuadratic(&equation);

		if (checkSolution(&equation, &testData))
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

bool checkSolution(Equation* solution, Equation* testData)
{
	myAssert(solution, ERROR_NULLPTR);

	if (solution->numberOfRoots != testData->numberOfRoots)
		return false;
	for (int i = 0; i < testData->numberOfRoots; i++)
		if (!isEqual(solution->roots[i], testData->roots[i]))
			return false;
	return true;
}
