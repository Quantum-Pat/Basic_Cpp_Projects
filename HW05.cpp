#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

// EXERCISE 1: //

/*Create a function, named “NoSnow”, that takes a const reference to a vector of strings. 
It should return a vector of strings. This new vector should have every string from the argument vector 
that doesn’t have the string “snow” in it (as a word or substring). */

/*


vector<string> NoSnow(const vector<string> & v){
    vector<string> nsnow = {};
    for (auto i = v.begin(); i != v.end(); ++i){
        if (*i != "snow"){
            string temp = *i;
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (temp.find("snow") == string::npos){
                nsnow.push_back(*i);
            }
        }
    }
    if (nsnow.size() != 0){
        return nsnow;
    }
    return v;
}

int main(){
    //vector<string> v{"snow", "lit", "snow", "bit", "snow", "kit with snow"};
    vector<string> v{"Summer", "Sun", "Hot", "Beaches"};
    vector<string> nn = NoSnow(v);
    for (string word:nn){
        cout << word << " ";
    }
    return 0;
}
*/

// EXERCISE 2: //

/*Create a function, named “SumByPosition” that takes a 2D vector of ints and returns a vector of ints. 
Each element of the resulting vector should contain the sum of elements from each sub-vector by indexed 
position in the given 2D vector argument. (In other words, sum each column.) Please see the test cases 
and examples below for expected inputs/outputs. Note that your function must also be able handle ragged-edge
2D Vectors (i.e., 2D vectors containing sub-vectors with different sizes).*/

/*
#include <vector>

std::vector<int> SumByPosition(std::vector<std::vector<int>> const & input) {
    // define functionality of SumByPosition here
    vector<int> output;
    int large = 0;
    for (int i = 0; i != static_cast<int>(input.size()); ++i) {
        if (large < static_cast<int>(input[i].size())){
            large = input[i].size();
        }
    }
    for (int i = 0; i < large; ++i) {
        int sum = 0;
        for (vector<int> subvec:input) {
            if (i < static_cast<int>(subvec.size())){
                sum += subvec[i];
            }
        }
        output.push_back(sum);
    }
    return output;
}

int main(){
    //std::vector<std::vector<int>> v = {{3, 5, 7}, {21, 34, 57}, {-100, 0, -14}};
    std::vector<std::vector<int>> v = {{0,0,0,0}, {21, 34, 57}, {-100, 0, -14}};
    for (int n:SumByPosition(v)){
        cout << n << endl;
    }
return 0;
}
*/

// EXERCISE 3: //

/*Create a void function, named “FilterOutMultiplesOf7” with two arguments: a reference to an istringstream 
and a reference to an ostringstream. The istringstream has whitespace-separated integers in its buffer. Your
function should move each of those integers to the ostringstream, and separate each integer by commas instead.
Please include a trailing comma. Also, any integer that is a multiple of 7 should not be pushed to the ostringstream.*/

/*
void FilterOutMultiplesOf7(std::istringstream & iss, std::ostringstream & oss) {
    // define functionality of FilterOutMultiplesOf7 here
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(words));
    for (string str:words){
        if (static_cast<int>(std::stoi(str)) % 7 != 0){
            oss << str <<',';
        }
    }

}

int main(){
    std::ostringstream oss;
    std::istringstream iss("10 25 6 80 24");
    FilterOutMultiplesOf7(iss,oss);
    cout << oss.str();
    return 0;
}
*/

// EXERCISE 4: //

/*Create a function, named SafeMod, that takes two int arguments and returns the result of ‘mod’ing the first value with
the second. However, if the second argument is 0, throw an invalid_argument exception with the message “0 isn’t allowed 
in the second argument”. For this problem, be sure to include both a header and implementation file in main.h and main.cpp.*/

/*
// main.h : int SafeMod(int lhs, int rhs); //
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "main.h"

// TO DO: Define this SafeMod function.
int SafeMod(int lhs, int rhs){
    if (rhs == 0){
        throw std::invalid_argument("0 isnt allowed in the second argument");
    }

    return static_cast<int>(lhs%rhs);
}

// NOTE: This main function implements test cases for your convenience.
//       When you execute this program, this main function will run each
//       test case to report which test cases pass/fail.
// YOU ARE NOT REQUIRED TO USE OR CHANGE THIS MAIN FUNCTION.
int main() {
  int lhs;
  int rhs;
  int result;
  int expected;

  // TEST CASE 01
  std::cout << "TEST CASE 01" << std::endl;
  lhs = 10;
  rhs = 3;
  result = SafeMod(lhs, rhs);
  expected = 1;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  std::cout << "   result = " << result << std::endl;
  std::cout << "   expected = " << expected << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  lhs = -32;
  rhs = 4;
  result = SafeMod(lhs, rhs);
  expected = 0;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  std::cout << "   result = " << result << std::endl;
  std::cout << "   expected = " << expected << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  lhs = -34;
  rhs = 5;
  result = SafeMod(lhs, rhs);
  expected = -4;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  std::cout << "   result = " << result << std::endl;
  std::cout << "   expected = " << expected << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  lhs = 0;
  rhs = 4;
  result = SafeMod(lhs, rhs);
  expected = 0;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  std::cout << "   result = " << result << std::endl;
  std::cout << "   expected = " << expected << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  lhs = 0;
  rhs = 0;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  try {
    result = SafeMod(lhs, rhs);
    std::cout << "   (exception thrown)? fails" << std::endl;
  } catch (std::invalid_argument&) {
    std::cout << "   (exception thrown)? passes" << std::endl;
  }
  lhs = 100;
  rhs = 0;
  std::cout << "   SafeMod(" << lhs << "," << rhs << ")" << std::endl;
  try {
    result = SafeMod(lhs, rhs);
    std::cout << "   (exception thrown)? fails" << std::endl;
  } catch (std::invalid_argument&) {
    std::cout << "   (exception thrown)? passes" << std::endl;
  }

  return 0;
}
*/

// EXERCISE 5: //

/* I’m trying to sneak super secret information out of an evil company. They have a list of names of their informants and 
spies that my virus can access, but their security is checking for the information transfer of things like vectors and strings.
However, their programmers have forgotten about stringstreams. Create a pair of functions, named “Send” and “Receive”, that
turn a vector of strings representing the names to sneak out into a stringstream (Send) and back again to a vector of strings 
(Receive). You can assume that the names consist solely of alphabetic characters and whitespace. Be sure to include the header 
file for these functions (main.h) that I’ve provided.

Hint: you may wish to use the std::getline function for this exercise.*/

/*
void Send(const std::vector<std::string>& input, std::stringstream& output){
    for (string word:input){
       output << word << ',';
    }
}

void Receive(std::stringstream& input, std::vector<std::string>& output){
    string word;
    while (getline(input, word)){
        int i = 0;
        string temp = "";
        for (char chr:word){
            temp += chr;
            if (chr == ','){
                temp.pop_back();
                output.push_back(temp);
                temp = "";
            }
        }
    }
    for (string i:output){
        cout << i<< endl;
    }
}

int main() {
    std::stringstream buffer;
    std::vector<std::string> const input_names = {"Josh Allen", "Rich Smith", "Charles Rogers"};
    Send(input_names, buffer);
    std::vector<std::string> output_names;
    Receive(buffer, output_names);
    std::cout << "Hello, World!";
    return 0;
}
*/

// EXERCISE 6: //

/*This problem only has hidden test cases. You are expected to create your own test cases to check that your code is working.
Create a function, named “SumOfPairs” that takes a const reference to a vector of ints and returns a vector of ints. The return
vector should be half as long at the original vector and consist of the sum of the first two elements, then the sum of the next
two elements, and so on.  No header file is needed for this problem.

Note: for clarification, if I give the SumOfPairs function the following input_vector, it should output the following output_vector.*/

/*
vector<int> SumOfPairs(const vector<int> &v){
    vector<int> vec;
    for (int i = 0; i < static_cast<int>(v.size()); ++i){
        if (i%2 == 0){
            vec.push_back(v[i] + v[i+1]);
        }
    }
    return vec;
}

int main() {
    vector<int> v{1,2,3,4,5,6};
    vector<int> vec = SumOfPairs(v);
    cout << static_cast<int>(vec.size());
    for (int i:vec){
        cout<< i<< endl;
    }
    std::cout << "Hello, World!";
    return 0;
}
*/

// EXERCISE 7: //

/*Create a function, named “SecondNegative”, that takes a const reference to a vector of doubles, it should return a const_iterator
 to the element in the vector that is the second value that is negative. If no such element exists, have the iterator point to one 
 past the end.*/

 /*

vector<double>::const_iterator SecondNegative(const vector<double> &v){
    int first = 0;
    vector<double>::const_iterator temp;
    auto ptr = v.begin();
    for (ptr; first != 2 && ptr != v.end(); ++ptr){
        if (*ptr < 0){
            first += 1;
            temp = ptr;
        }
    }
    if (first == 2){
        return temp;
    }
    return v.end();
}
 int main() {
    vector<double> v{-2.4, 4, -5, 8};
    //vector<double> v{-1,1,3,2,5,6,7};
    cout << *SecondNegative(v) << endl;
    cout << *v.end();
    std::cout << "Hello, World!";
    return 0;
}
*/

//EXERCISE 8: //

/* Create a void function, named “SortByReverse”, that takes a reference to a vector of strings. It should modify its argument to 
be ordered lexicographically according to the reverse of each string. For example, if the input was {“apple”, “banana”, “carrot”},
the correct ordering should be {“banana“, “apple“, “carrot”} because the last “a” in banana comes before the “e” in “apple” and
the “t” in “carrot”.

Note: we are not simply trying to sort by the last letter of each string. We also want to consider situations when the last letter
of multiple words are the same. In that case, we would want to sort by the second-to-last letter and move onto the third-to-last
letter when those are the same, and so on. Instead of sorting by the last letter, we want to sort by the letters in reverse.  For 
example, {"pie", "poke", "apple", "cake"} should sort to {"apple", "poke", "cake", "pie"}.

Hint: you can use the std::reverse function to reverse a string. */

/*
void SortByReverse(vector<string> &v){
    vector<string> rev;
    //int temp = int(a);
    for (string word:v){
        std::reverse(word.begin(), word.end());
        rev.push_back(word);
        }
    sort(rev.begin(), rev.end(), [](const string& a, const string& b) -> bool{
        return a < b;
    }
    );
    int i = 0;
    for (string word:rev){
        std::reverse(word.begin(), word.end());
        v[i] = word;
        ++i;
    }
}

int main() {
    vector<string> v{"pie", "poke", "apple", "cake"};
    SortByReverse(v);
    for (string word:v){
        cout << word << endl;
    }
    std::cout << "Hello, World!";
    return 0;
}
*/

// EXERCISE 9: //

/*Create a function named “AllTogether” that takes a const reference to a vector of strings and returns a single string. This 
resulting string should have all the strings in the vector delimited by semicolons. Please see test cases for examples. However, 
your solution must not make use of any iteration statements, meaning no for loops and no while loops (including std::for_each). 
Use the STL algorithms instead. 

Note: do not include the words “for”, “while”, “goto”, or “for_each” in any of your code (including comments) or you will fail 
the test cases that checks for loops in your code.*/

/*
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>


// TO DO: Define this AllTogether function.
std::string AllTogether(const std::vector<std::string>& input){
    std::stringstream oss;
    std::copy(input.begin(), input.end(), std::ostream_iterator<string>(oss, ";"));
    return oss.str();
}
 
// NOTE: This main function implements test cases forr your convenience.
//       When you execute this program, this main function will run each
//       test case to report which test cases pass/fail.
// YOU ARE NOT REQUIRED TO USE OR CHANGE THIS MAIN FUNCTION.
int main() {
  std::vector<std::string> input;
  std::string result;
  std::string expected;

  // TEST CASE 01: CORRECT FUNCTIONALITY
  std::cout << "TEST CASE 01: CORRECT FUNCTIONALITY" << std::endl;
  input = {"first", "next", "last"};
  expected = "first;next;last;";
  result = AllTogether(input);
  std::cout << "   input = {";
  for (auto x : input) //?
    std::cout << "\"" << x << "\",";
  std::cout << "}" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;

  // TEST CASE 02: NO LOOPS
  std::cout << "TEST CASE 02: NO LOOPS" << std::endl;
  std::cout << "Check for loops..." << std::endl; //?
  std::ifstream code{"main.cpp"};
  std::regex r{R"~(\bfor\b|\bwhile\b|\bgoto\b|\bfor_each\b)~"};
  std::regex q{R"~(\/\/\?)~"};
  int count = 0;
  std::string line;
  while (std::getline(code, line)) { //?
      if (std::regex_search(line, r) && !std::regex_search(line, q)) {
          std::cout << "   * Loop found on this line: " << line << std::endl;
          count++;
      }
  }
  std::cout << "   (no loops)? " 
            << ((count == 0) ? "passes" : "fails") << std::endl;

  return 0;
}
*/

// EXERCISE 10: //

/*Create a void function, named “ReplaceSingleDigits“, that takes a reference to an istream (e.g. cin, istreamstream, or fstream) 
and a reference to an ostream. It should read from the istream whitespace separated words and write those words to the ostream. 
However if a word is a is a single digit word (like “four”) if should be replaced with the numeric value in parentheses, like“(4)”. 
Full credit is only possible if you avoid using loops (like in the previous question).

Note: do not include the words “for”, “while”, “goto”, or “for_each” in any of your code (including comments) or you will fail the 
test cases that checks for loops in your code.*/

/*
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>


void ReplaceSingleDigits(std::istream & is, std::ostream & os) {
    // define functionality of ReplaceSingleDigits here
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), std::back_inserter(words));
    std::transform(words.begin(), words.end(), words.begin(), 
               [](const std::string& word){
                if (word == "zero" || "one" || "two" || "three" || "four" || "five" || "six" || "seven" || "eight" || "nine"){
                    if (word == "zero"){
                        string str = "(0)";
                        return str;
                    }
                    if (word == "one"){
                        string str = "(1)";
                        return str;
                    }
                    if (word == "two"){
                        string str = "(2)";
                        return str;
                    }
                    if (word == "three"){
                        string str = "(3)";
                        return str;
                    }
                    if (word == "four"){
                        string str = "(4)";
                        return str;
                    }
                    if (word == "five"){
                        string str = "(5)";
                        return str;
                    }
                    if (word == "six"){
                        string str = "(6)";
                        return str;
                    }
                    if (word == "seven"){
                        string str = "(7)";
                        return str;
                    }
                    if (word == "eight"){
                        string str = "(8)";
                        return str;
                    }
                    if (word == "nine"){
                        string str = "(9)";
                        return str;
                    }
                }
                return word;
               });		

std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(os, " "));
}

// NOTE: This main function implements test cases forr your convenience.
//       When you execute this program, this main function will run each
//       test case to report which test cases pass/fail.
// YOU ARE NOT REQUIRED TO USE OR CHANGE THIS MAIN FUNCTION.
int main() {
  std::string input;
  std::string result;
  std::string expected;

  // TEST CASE 01: VISIBLE
  std::cout << "TEST CASE 01: VISIBLE" << std::endl;
  input = "I have four chickens. ";
  expected = "I have (4) chickens. ";
  std::istringstream iss(input);
  std::ostringstream oss;
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;

  iss.clear();
  oss.clear();
  input = "zero one two four three five six seven eight nine ten ";
  expected = "(0) (1) (2) (4) (3) (5) (6) (7) (8) (9) ten ";
  iss.str(input);
  oss.str("");
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;

  iss.clear();
  oss.clear();
  input = "one-two fourteen Three fivE nine ten ";
  expected = "one-two fourteen Three fivE (9) ten ";
  iss.str(input);
  oss.str("");
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;

  // TEST CASE 02: NO LOOPS
  std::cout << "TEST CASE 02: NO LOOPS" << std::endl;
  std::cout << "Check for loops..." << std::endl; //?
  std::ifstream code{"main.cpp"};
  std::regex r{R"~(\bfor\b|\bwhile\b|\bgoto\b|\bfor_each\b)~"};
  std::regex q{R"~(\/\/\?)~"};
  int count = 0;
  std::string line;
  while (std::getline(code, line)) { //?
      if (std::regex_search(line, r) && !std::regex_search(line, q)) {
          std::cout << "   * Loop found on this line: " << line << std::endl;
          count++;
      }
  }
  std::cout << "   (no loops)? " 
            << ((count == 0) ? "passes" : "fails") << std::endl;

  return 0;
}
*/

// EXERCISE 11: //

/*Create a function, that is identical in almost all respects to the previous question. The one difference is that this is a non-void 
function. It returns a map<string, int> denoting the words that were replaced as keys and the number of replacements performed as the 
value. You are welcome to use loops if you’d like.*/

/*
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

std::map<string, int> ReplaceSingleDigits(std::istream & is, std::ostream & os) {
    // define functionality of ReplaceSingleDigits here
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), std::back_inserter(words));
    std::map<string, int> mapp;
    std::transform(words.begin(), words.end(), words.begin(), 
               [&](const std::string& word){
                int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;

                if (word == "zero" || "one" || "two" || "three" || "four" || "five" || "six" || "seven" || "eight" || "nine"){
                    if (word == "zero"){
                        ++zero;
                        mapp.insert(std::pair<string, int>("zero", zero));
                        string str = "(0)";
                        return str;
                    }
                    if (word == "one"){
                        string str = "(1)";
                        return str;
                    }
                    if (word == "two"){
                        string str = "(2)";
                        return str;
                    }
                    if (word == "three"){
                        string str = "(3)";
                        return str;
                    }
                    if (word == "four"){
                        string str = "(4)";
                        return str;
                    }
                    if (word == "five"){
                        string str = "(5)";
                        return str;
                    }
                    if (word == "six"){
                        string str = "(6)";
                        return str;
                    }
                    if (word == "seven"){
                        string str = "(7)";
                        return str;
                    }
                    if (word == "eight"){
                        string str = "(8)";
                        return str;
                    }
                    if (word == "nine"){
                        string str = "(9)";
                        return str;
                    }
                }
                return word;
               });		
std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(os, " "));
int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
for (string word: words){
        if (word == "(0)" || "(1)" || "(2)" || "(3)" || "(4)" || "(5)" || "(6)" || "(7)" || "(8)" || "(9)"){
            if (word == "(0)"){
                ++zero;
            }
            if (word == "(1)"){
                ++one;
            }
            if (word == "(2)"){
                ++two;
            }
            if (word == "(3)"){
                ++three;
            }
            if (word == "(4)"){
                ++four;
            }
            if (word == "(5)"){
                ++five;
            }
            if (word == "(6)"){
                ++six;
            }
            if (word == "(7)"){
                ++seven;
            }
            if (word == "(8)"){
                ++eight;
            }
            if (word == "(9)"){
                ++nine;
            }
        }
    }
    if (zero != 0){
        mapp.insert(std::pair<string, int>("zero", zero));
    }
    if (one != 0){
        mapp.insert(std::pair<string, int>("one", one));
    }
    if (two != 0){
        mapp.insert(std::pair<string, int>("two", two));
    }
    if (three != 0){
        mapp.insert(std::pair<string, int>("three", three));
    }
    if (four != 0){
        mapp.insert(std::pair<string, int>("four", four));
    }
    if (five != 0){
        mapp.insert(std::pair<string, int>("five", five));
    }
    if (six != 0){
        mapp.insert(std::pair<string, int>("six", six));
    }
    if (seven != 0){
        mapp.insert(std::pair<string, int>("seven", seven));
    }
    if (eight != 0){
        mapp.insert(std::pair<string, int>("eight", eight));
    }
    if (nine != 0){
        mapp.insert(std::pair<string, int>("nine", nine));
    }

return mapp;
}

// NOTE: This main function implements test cases forr your convenience.
//       When you execute this program, this main function will run each
//       test case to report which test cases pass/fail.
// YOU ARE NOT REQUIRED TO USE OR CHANGE THIS MAIN FUNCTION.
int main() {
  std::string input;
  std::string result;
  std::string expected;
  std::map<std::string, int> map_result;
  std::map<std::string, int> map_expected;

  // TEST CASE 01: OLD FUNCTIONALITY
  std::cout << "TEST CASE 01: OLD FUNCTIONALITY" << std::endl;
  input = "I have four chickens. ";
  expected = "I have (4) chickens. ";
  std::istringstream iss(input);
  std::ostringstream oss;
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  iss.clear();
  oss.clear();
  input = "zero one two four three five six seven eight nine ten ";
  expected = "(0) (1) (2) (4) (3) (5) (6) (7) (8) (9) ten ";
  iss.str(input);
  oss.str("");
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  iss.clear();
  oss.clear();
  input = "one-two fourteen Three fivE nine ten ";
  expected = "one-two fourteen Three fivE (9) ten ";
  iss.str(input);
  oss.str("");
  ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;

  // TEST CASE 02: CHECK RETURN VALUE TOO
  std::cout << "TEST CASE 02: CHECK RETURN VALUE TOO" << std::endl;
  iss.clear();
  oss.clear();
  input = "I have four chickens. ";
  expected = "I have (4) chickens. ";
  map_expected = {{"four", 1}};
  iss.str(input);
  oss.str("");
  map_result = ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  std::cout << "   (map_result == map_expected)? "
            << ((map_result == map_expected) ? "passes" : "fails") << std::endl;
  iss.clear();
  oss.clear();
  input = "zero one two four three five six seven eight nine ten ";
  expected = "(0) (1) (2) (4) (3) (5) (6) (7) (8) (9) ten ";
  map_expected = { 
      {"eight", 1}, {"five", 1}, {"four", 1}, {"nine", 1}, 
      {"one", 1}, {"seven", 1}, {"six", 1}, {"three", 1}, 
      {"two", 1}, {"zero", 1} };
  iss.str(input);
  oss.str("");
  map_result = ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  std::cout << "   (map_result == map_expected)? "
            << ((map_result == map_expected) ? "passes" : "fails") << std::endl;  
  iss.clear();
  oss.clear();
  input = "one-two fourteen Three fivE nine ten nine four nine four ";
  expected = "one-two fourteen Three fivE (9) ten (9) (4) (9) (4) ";
  map_expected = { {"four", 2}, {"nine", 3} };
  iss.str(input);
  oss.str("");
  map_result = ReplaceSingleDigits(iss, oss);
  result = oss.str();
  std::cout << "   input = \"" << input << "\"" << std::endl;
  std::cout << "   result = \"" << result << "\"" << std::endl;
  std::cout << "   expected = \"" << expected << "\"" << std::endl;
  std::cout << "   (result == expected)? "
            << ((result == expected) ? "passes" : "fails") << std::endl;
  std::cout << "   (map_result == map_expected)? "
            << ((map_result == map_expected) ? "passes" : "fails") << std::endl;
  return 0;
}
*/
