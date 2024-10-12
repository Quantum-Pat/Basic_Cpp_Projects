# include <iostream>
using std::endl; using std::cout; using std::cin; using std::int64_t; using std::string;

// PROBLEM 1: LOOK AND SAY SEQUENCE //

/*
// DEFINE CountDigits FUNCTION
int64_t CountDigits(int64_t n){
    string str = std::to_string(n);
    string num = "";
    int count = 0;
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == str[i+1]){
            ++count;
        }
        else {
            ++count;
            num += std::to_string(count) + str[i];
            count = 0;
        }
    }
    int64_t new_num = std::stoll(num);
    return new_num;
}


int main() {
    // TO DO:
    // 1. Read starting number and number of iterations
    int64_t start_num; int64_t iters;
    cin >> start_num; cin >> iters;
    // 2. Loop, counting digits in previous number (beginning with starting number)
    //int64_t n = CountsDigits(start_num);
    cout << "Starting number:" << start_num << endl;
    for (int i = 1; i <= iters; ++i){
        start_num = CountDigits(start_num);
        cout << "iteration " << i << ": " << start_num << endl;
    }
    //     NOTE: each iteration must call CountDigits function

    return 0;
}

// PROBLEM 2: CENSORSHIP //

/*

# include <iostream>
#include <algorithm>
#include <string>
using std::endl; using std::cout; using std::cin; using std::int64_t; using std::string;

int main() {
    // read each line of text from standard input
    // for each line
    string str;
    while (getline(cin, str)){
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        string banger = "banger";
    for(char chr:str){
    if (str.find(banger) != string::npos){
        str.replace(str.find(banger), banger.length(), "sausage");
    }
    }
    cout << str << endl;
    }
    
    //  1. replace censored word with replacement word
    //  2. output censored text
     
    return 0;
}

*/

// PROBLEM 3: CENSOR FUNCTION //

/*

# include <iostream>
#include <algorithm>
#include <string>
using std::endl; using std::cout; using std::cin; using std::int64_t; using std::string;

// define Censor function
int Censor(std::string& text, const std::string& pattern, const std::string& replacement) {
    string temp = text;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    int changes = 0;
    cout<<temp;
    bool x = true;
    while (temp.find(pattern) != string::npos){
        if (temp.find(pattern) != string::npos){
            text.replace(temp.find(pattern), pattern.length(), replacement);
            temp.replace(temp.find(pattern), pattern.length(), replacement);
            changes += 1;
        }
    }
    return changes;
}

int main(){
    string text; string pattern; string replacement;
    getline(cin, text); cin >> pattern; cin >> replacement;
    cout << Censor(text, pattern, replacement) << endl;
    cout << text;
    return 0;

}
*/

// PROBLEM 4: MULTIPLE FILES //

/*
void increment(int &n){
    n += 1;
}
*/

// PROBLEM 5: FUNCTION OVERLOADING //

/*
#include <iostream>
#include <string>
#include "main.h"
using std::cout; using std::cin; using std::endl; using std::string;

int AddZero(int n){
    string temp = std::to_string(n);
    temp+="0";
    n = std::stoi(temp);
    return n;
}

double AddZero(double n){
    string temp = std::to_string(n);
    for (int i = 0; i <= temp.length(); ++i){
        if (temp[i] == '.'){
            temp.insert(i+1,"0");
            break;
        }
    }
    n = std::stod(temp);
    return n;
}

string AddZero(string n){
    n += " Zero";
    return n;
}


int main() {
    std::cout << "Hello, World!"<< endl;
    string n = "ten";
    cout << AddZero(n);
    return 0;
}
*/

// PROBLEM 6: TEMPLATES //

/* 
main.h file 
*/

// PROBLEM 7: SELECTSMALLER //

/*
//main.h file 
#include "main.h"

int main(){
    int x = 5;
    int y = 9;
    int const& z = SelectSmaller(x, y);
    std::cout << z << std::endl; // z should be 5

    /*float x = 5.7;
    float y = 5.3;
    float const& z = SelectSmaller(x, y);
    std::cout << z << std::endl; // z should be 5.3
    return 0;
}
*/
