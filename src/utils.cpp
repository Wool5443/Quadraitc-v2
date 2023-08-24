#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.hpp"

const double ABSOLUTE_TOLERANCE = 1e-5;

bool isEqual(const double x1, const double x2)
{
	return fabs(x1 - x2) < ABSOLUTE_TOLERANCE;
}

void copyArray(double destination[], double source[], int length)
{
	myAssertHard(destination, ERROR_NULLPTR);
	myAssertHard(source, ERROR_NULLPTR);

	for (int i = 0; i < length; i++)
		destination[i] = source[i];
}

void clearBuffer(void)
{
	while (getchar() != '\n') { ; }
}

void setConsoleColor(FILE* place, enum Color color)
{
	switch (color)
	{
	case RED:
		fprintf(place, "\033[0;31m");
		break;
	case GREEN:
		fprintf(place, "\033[0;32m");
		break;
	case WHITE:
		fprintf(place, "\033[0;37m");
		break;
	default: //set the color to white
		fprintf(place, "\033[0;37m");
		break;
	}
}