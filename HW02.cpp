#include "HW02.hpp"

double IntegralOfXSquared(double x) 
{
    double area = pow(x,3) / 3;
    return area;
}

// ADD OnlyPrimeChars FUNCTION HERE
std::string OnlyPrimeChars(const std::string &str){
    std::string primes = "";

    for(int i = 0; i <= str.length(); ++i){
        int prime = 1;

        if (int(str[i]) == 0 || int(str[i]) == 1){
            prime = 0;
        }

        else {
            for (int j = 2; j <= int(str[i])/2; ++j){
                if (int(str[i]) % j == 0){
                    prime = 0;
                }
            }
        }
        if (prime == 1){
            primes += str[i];
        }
    }
    return primes;

}

int main() 
{
    // PROBLEM 1: INCLUSIVE INTERVALS //
    // ADD CODE TO READ INPUTS
    double input1; double input2; double input3;
    std::cin >> input1; std::cin >> input2; std::cin >> input3;
    double add = (input2 - input1)/input3;
    // ADD CODE TO OUTPUT EACH INTERVAL DENOTED BY THE GIVEN RANGE
    for (int i = 0; i < input3; ++i){
        double lower = input1;
        input1 += add;
        std::cout << std::fixed << std::setprecision(4) << "(" << lower << ", " << input1<< ")" << std::endl;

    }

    // PROBLEM 2: INTEGRAL X^2 //
    double xin;
    std::cin >> xin;
    std::cout << IntegralOfXSquared(xin);

    // PROBLEM 3: WORDLE //
    // display prompt for secret word
    std::string secret_word = "";
    std::cout << "Give me a secret word: " << std::endl;
    std::cin >> secret_word;

    // ADD REMAINDER OF PROGRAM HERE
    bool x = true;
    int guesses = 1;
    while (x == true){
        std::string word = ".....";
        guesses++;
        std::cout << "Give me a guess: " << std::endl;
        std::string guess;
        std::cin >> guess;
        if (guess == ""){
            std::cout << "You Lose.";
            x = false;
        }

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (secret_word[i] == guess[j]){
                    if (i == j){
                        word[i] = secret_word[i];
                    }
                    else if (i != j){
                        if (word[j] == '.'){
                            word[j] = '?';
                        }
                    }
            }
            }
            }
        std::cout << word << std::endl;

        if (word == secret_word){
            std::cout << "You Win!";
            x = false;
        }
        else if (guesses > 6){
            std::cout << "You Lose.";
            x = false;
        }
    }

    //PROBLEM 4: PRIME CHARACTERS (CHECKS TO SEE IF CHARACTER NUMBER IN STRING IS PRIME)//
    std::string example = "The quick brown fox liked honey";
    std::cout << OnlyPrimeChars(example) << std::endl; // Should print "eqkkee"
    return 0;
}