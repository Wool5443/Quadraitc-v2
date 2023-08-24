//! @file

#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Represents colors for @see SetConsoleColor
 */
enum Color { RED, GREEN, WHITE };

/**
 * @brief Represents possible error codes for @see myAssertHard()
 */
enum ErrorCode { EVERYTHING_FINE = 0, ERROR_NULLPTR = 100, ERROR_BAD_NUMBER, ERROR_BAD_FILE };

/**
 * @brief Hard assert which tells the file, function and line where the error occured.
 *
 * @param [in] STATEMENT - the condition to check.
 * @param [in] ERR_CODE - what can happen @see ErrorCode.
 */
#define myAssertHard(STATEMENT, ERR_CODE)                                                                     \
if (!(STATEMENT))                                                                                             \
{                                                                                                             \
    SetConsoleColor(stderr, RED);                                                                             \
    fprintf(stderr, "ERROR %d in %s in %s in line: %d\n", ERR_CODE, __FILE__, __PRETTY_FUNCTION__, __LINE__); \
    SetConsoleColor(stderr, WHITE);                                                                           \
    exit(ERR_CODE);                                                                                           \
}

 /**
  * @brief Finds max of x, y.
  */
#define max(x, y)                                                                                             \
({                                                                                                            \
    typeof(x) _tx = x; typeof(y) _ty = y;                                                                     \
    _tx > _ty ? _tx : _ty;                                                                                    \
})

  /**
  * @brief Tells if 2 doubles are equal.
  *
  * @param x1
  * @param x2
  *
  * @return true The numbers are equal.
  * @return false The numbers are not equal.
  */
bool IsEqual(const double x1, const double x2);

/**
 * @brief Copies <length> element from source to destination starting at zero index.
 *
 * @param destination
 * @param source
 * @param length
 */
void CopyArray(double destination[], double source[], int length);

/**
 * @brief Clears stdin.
 */
void ClearBuffer(void);

/**
 * @brief Check if the user input contains anything but scanned data.
 *
 * @return true Everything is clear.
 * @return false User entered something odd.
 */
bool CheckInput(void);

/**
 * @brief Set the color of either stderr or stdout
 *
 * @param place - stderr or stdout
 * @param color - @see Color
 */
void SetConsoleColor(FILE* place, enum Color color);

#endif