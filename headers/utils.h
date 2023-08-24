#ifndef UTILS_H
#define UTILS_H

enum Color { RED, GREEN, WHITE };

enum ErrorCode { ERROR_NULLPTR = 1, ERROR_BAD_NUMBER };

bool isEqual(const double x1, const double x2);

void copyArray(double destination[], double source[], int length);

void myAssert(bool statement, ErrorCode err);

void clearBuffer(void);

void setConsoleColor(enum Color color);

#endif