//-------------------------------------------------------------------------------------------------------------------
//!
//! myAssert is a more sophisticated version of common assert which shows error's file, function and line and
//! writes it in red to stderr
//!
//! isEqual tells whether two double are very close to each other. Its ABSOLUTE_TOLERANCE is set to 1e-5
//!
//! copyArray copies length elements from source to destination starting at 0
//!
//! clearBuffer clears stdin
//!
//! setConsoleColor sets color in either stderr or stdout
//!
//-------------------------------------------------------------------------------------------------------------------

#ifndef UTILS_H
#define UTILS_H

enum Color { RED, GREEN, WHITE };

enum ErrorCode { EVERYTHING_FINE = 0, ERROR_NULLPTR = 100, ERROR_BAD_NUMBER, ERROR_BAD_FILE };

const int TRUE = 1, FALSE = 0;

#define myAssert(STATEMENT, ERR_CODE)                                                                         \
if (!(STATEMENT))                                                                                             \
{                                                                                                             \
    setConsoleColor(stderr, RED);                                                                             \
    fprintf(stderr, "ERROR %d in %s in %s in line: %d\n", ERR_CODE, __FILE__, __PRETTY_FUNCTION__, __LINE__); \
    setConsoleColor(stderr, WHITE);                                                                           \
    return ERR_CODE;                                                                                          \
}

#define max(x, y)                         \
({                                        \
    typeof(x) _tx = x; typeof(y) _ty = y; \
    _tx > _ty ? _tx : _ty;                \
})

bool isEqual(const double x1, const double x2);

int copyArray(double destination[], double source[], int length);

int clearBuffer(void);

int setConsoleColor(FILE* place, enum Color color);

#endif