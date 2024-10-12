#include "HW01.hpp"

// PROBLEM 1: NEXT LETTER //
void nextLetter(void){
    // Input Letter
    char int_letter = '\0';
    std::cout << "Enter Any Letter: " << std::endl;
    std::cin >> int_letter;
    // Print Next Letter
    std::cout << ++int_letter;
}

// PROBLEM 2: TYPE OF CHARACTER //
void pidType(void) 
{
    // ADD CODE TO READ SEQUENCE OF PIDS AND PRINT OUTPUT FOR EACH TYPE OF PID
    for (int i = 0; i < 5; i++){
        std::string PID = "";
        std::cout << "Enter Leading Letter of PID Number: ";
        std::cin >> PID;
        if (PID[0] == 'A'){
            std::cout << PID << " has student status" << std::endl;
        }
        else if (PID[0] == 'Z'){
            std::cout << PID <<" has faculty status" << std::endl;
        }
        else if (PID[0] == 'F'){
            std::cout << PID <<" has guest status" << std::endl;
        }
        else {
            std::cout << PID << " has unknown status" << std::endl;
        }
    }
}

// PROBLEM 3: COLLATZ CONJECTURE //
void collatzConjecture(void) {
    // ADD CODE TO READ SEQUENCE OF NUMBERS AND APPLY COLLATZ
    int num = 0;
    std::cout << "Input Number to Apply COLLATZ Conjecture: ";
    while (std::cin >> num){
        int initial = num;
        int i = 0;
        for (i = 0; num != 0 && num != 1 && num != -1 && num != -5 && num != -17; i++){
            if (num % 2 == 0){
                num = num / 2;
            }
            else {
                num = 3 * num + 1;
            } 
        }
        std::cout << initial <<" took " << i << " iterations to converge to " << num << std::endl; 
        std::cout << "Input Number to Apply COLLATZ Conjecture: ";
    }
    // CONJECTURE TO EACH INPUT NUMBER UNTIL CONVERGENCE.
}

// PROBLEM 4: YOUR FIRST C++ FUNCTION //
bool IsVowel(char letter) {
    // returns true for vowels
    switch(letter) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }
    return false;
}

// PROBLEM 7: SORTING POINTERS //
// ADD MakeOrdered FUNCTION HERE
void MakeOrdered(int *point1, int *point2){
    if (*point2 > *point1) {
        int smaller = *point1;
        *point1 = *point2;
        *point2 = smaller;
    }
}

int main() {
    // read sequence of letters as input
    nextLetter();
    pidType();
    collatzConjecture();
    char letter = '\0';
    int value = 6;
    while (std::cin >> letter) {
        // check if current letter input is a vowel (or not)
        if (IsVowel(letter)) {
            std::cout << letter << " is a vowel." << std::endl;
        } else {
            std::cout << letter << " is not a vowel." << std::endl;
        }
    }
    int x = 14;
    int y = 28;
    MakeOrdered(&x, &y);
    std::cout << x << " should be 28" << std::endl;
    std::cout << y << " should be 14" << std::endl;
    return 0;
}