//-------------------------------------------------------------------------------------------------------------------
//!
//! testAll reads fileName and tries solveQuadratic on them. 
//! The file should look like this:
//! <number_of_tests>
//! <a> <b> <c> <number_of_roots> <roots> // write the amount of roots that exist. if there are infinte roots
//!                                                                                write -1
//!
//-------------------------------------------------------------------------------------------------------------------

#ifndef TESTER_H
#define TESTER_H

int testAll(const char* fileName);

#endif
