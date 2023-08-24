#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/utils.h"

#define max(x, y)                                             \
					({                                        \
						typeof(x) _tx = x; typeof(y) _ty = y; \
						(_tx > _ty ? _tx : _ty);              \
					})

const double ABSOLUTE_TOLERANCE = 1e-5;

bool isEqual(const double x1, const double x2) // make it return enum LESS, EQUAL, MORE
{
	return fabs(x1 - x2) < ABSOLUTE_TOLERANCE;
}

void copyArray(double destination[], double source[], int length)
{
	for (int i = 0; i < length; i++)
		destination[i] = source[i];
}

void myAssert(bool statement, ErrorCode err)
{
	if (!statement)
	{
		fprintf(stderr, "RUNTIME ERROR!!! ERROR CODE IS %d\n", (int)err);
		assert(statement);
	}
}

void clearBuffer(void)
{
	while (getchar() != '\n') { ; }
}

void setConsoleColor(enum Color color)
{
	switch (color)
	{
	case RED:
		printf("\033[0;31m");
		break;
	case GREEN:
		printf("\033[0;32m");
		break;
	case WHITE:
		printf("\033[0;37m");
		break;
	default: //set the color to white
		printf("\033[0;37m");
		break;
	}
}
