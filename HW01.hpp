#include <iostream>
#include <cctype>

void nextLetter(void);
void pidType(void);
/*
The Collatz conjecture states that all paths eventually lead to 1.
The Collatz conjecture[a] is one of the most famous unsolved problems in mathematics.
The conjecture asks whether repeating two simple arithmetic operations will eventually
transform every positive integer into 1.
*/
void collatzConjecture(void);
bool IsVowel(char letter);
// PROBLEM 5: TYPE MODIFIERS //
// ADD QuadrupleNumber FUNCTION HERE
void QuadrupleNumber (int& value){ value = value*4; };
// ADD SumOfPointers FUNCTION HERE
int SumOfPointers(int *point1, int *point2, int *point3);
void MakeOrdered(int *point1, int *point2);