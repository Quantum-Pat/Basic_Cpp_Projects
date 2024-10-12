/*
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std:: endl; using std:: cin; using std::string; using std::vector;
*/

//HW 3//

// PROBLEM 5 //
/*
// add AddZero declarations here
int AddZero(int n);
double AddZero(double n);
string AddZero(string n);
*/

// PROBLEM 6 //
/*
// define templated Increment function here
template <typename T>
T Increment(int &n){
    n += 1;
}
*/

// PROBLEM 7 //
/*
template <typename T>
const T &SelectSmaller(const T &first, const T &second){
    if (first < second){
        return first;
    }
    else if (second < first){
        return second;
    }
}
*/

// HW 05 //

// PROBLEM 9 //
/*
#pragma once
#include <vector>
#include <string>

void RemoveNegatives(std::vector<int> & parameter);
std::vector<std::string> SortedByAge(std::vector<std::string> unsorted);
std::vector<std::string> AddDays(std::vector<std::string> const & days, std::vector<std::string> const & increments);
*/

// HW 06 //
// EXERCISE 1 //
/*#pragma once

#include <vector>

std::vector<int> MaxVector(std::vector<int> const &, std::vector<int> const &);*/

// EXERCISE 2 //
/*template <typename T> vector<T> MaxVector(const vector<T> &v1, const vector<T> &v2){
     vector <T> large;
     vector <T> small;
    if (static_cast<int>(v2.size()) > static_cast<int>(v1.size())){
        large = v2;
        small = v1;
    }
    else if (static_cast<int>(v2.size()) < static_cast<int>(v1.size())){
        large = v1;
        small = v2;
    }
   else if (static_cast<int>(v2.size()) == static_cast<int>(v1.size())){
        vector <T> result = {};
        std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(result), [](const T& left, const T& right){
            // TO DO: you'll need to figure out what should be returned here.
            if (left > right){
                return left;
            }
            else if (right > left){
                return right;
            }
            else if (right == left){
                return right;
            }
            return left;
      }
  );
  return result;
    }
    // Let's pad vec2 to be the same size as vec1 by appending any excess in vec1 to the end of vec2
    vector <T> v2_extended = {};
    // this std::copy simply copies vec2 into the back of vec2_extended
    std::copy(small.begin(), small.end(), std::back_inserter(v2_extended));
    // this std::copy copies all elements in vec1 beyond the size of vec2 into the back of vec2_extended
    std::copy(large.begin() + small.size(), large.end(), std::back_inserter(v2_extended));
    // vec3_extended = {1, 2, 3, 4, 5}
    // let's use the std::transform function on both vec1 and vec2_extended
    // the result of our lambda function will be back_inserted into the result vector

    vector <T> result = {};
    std::transform(large.begin(), large.end(), v2_extended.begin(), std::back_inserter(result), [](const T& left, const T& right){
        // TO DO: you'll need to figure out what should be returned here.
        if (left > right){
            return left;
        }
        else if (right > left){
            return right;
        }
        else if (right == left){
            return right;
        }
        return left;
      }
  );
  return result;
  };*/

// HW 07 //
/*
#pragma once
#include <vector>
#include <map>
#include <set>
#include <string>

int GetPointTotalForStudent(std::map<std::string, std::string> const & info);

int GetExamTotalForStudent(std::map<std::string, std::string> const & info);

int GetTopNHomeworkTotalForStudent(std::map<std::string, std::string> const & info, int n);

std::map<std::string, std::map<std::string, std::string>> GetIDToInfoFromCSV(std::string const & filename);

std::map<std::string, double> GetIDToGrade(std::map<std::string, std::map<std::string, std::string>> const & id_to_info);

*/
// HW 08 //

// EXERCISE 1 //
// TO DO: declare Penultimate class here.
/*
struct Penultimate {
    string str = "";
    Penultimate() = default;
    Penultimate(string str_);
    string push_back(string word);
};
*/
  
// EXERCISE 2 //
// TO DO: declare ForgetfulVector class here
/*
#include <set>
struct ForgetfulVector{
    vector<int> v;
    std::set<int> s;
    ForgetfulVector(vector<int> v_);
    int size(void);
    int& at(int n);
    void push_back(int n);
};*/

// EXERCISE 3 //
/*
struct Temperature {
    Temperature(double temp, char unit);
    double temp;
    double AsCelsius(void);
    double AsFahrenheit(void);
    double AsKelvin(void);
    double AsRankine(void);
};
*/
// EXERCISE 5 & 6 //

/*
#pragma once
#include <iostream>
#include <sstream>
#include "main.h"
#include <string>
#include <vector>
using std::string; using std::cout; using std::endl; using std::vector;
// TO DO: declare Counter class here.
class Counter{
    public:
        friend std::ostream& operator<<(std::ostream& os, Counter& counter);
        friend Counter operator+(Counter const &c1, Counter const & c2);
        Counter(int n_);
        int value();
        std::stringstream os;
        int n;
        int init;
        vector<string> log_;
};*/

// EXERCISE 7 //
/*
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::string; using std::cout; using std::endl; using std::vector;
// TO DO: declare Counter class here.
class Counter{
    public:
        friend std::ostream& operator<<(std::ostream& os, Counter& counter);
        friend Counter operator+(Counter const &c1, Counter const & c2);
        Counter(int n_);
        Counter(void);
        Counter(const Counter &c1);
        Counter& operator=(const Counter &c);
        ~Counter();
        int value();
        std::stringstream os;
        int n;
        int init;
        int n1;
        int init1;
        vector<string> log_;
};
*/

// HW 09 //

// EXERCISE 2 //
/*
#pragma once
#include <vector>
#include <set>

// TO DO: declare TwoOrLess class here.

class TwoOrLess{
    public:
        std::vector<int> v;
        TwoOrLess(std::vector<int> vec);
        TwoOrLess();
        std::pair<std::vector<int>::iterator, bool> insert(const int& element);
        int count(const int& element);
        int size();
};*/

// EXERCISE 7 //
// TO DO: define templated ArrayToVector function here.
/*
#include <vector>
template <typename Type>
std::vector<Type> ArrayToVector(Type* point, Type size){
    std::vector<Type> v;
    for (auto i = point; i != point + size; ++i){
        v.push_back(*i);
    }
    delete[] point;
    return v;
}*/

// HW10 //
#pragma once
#include <string>
#include <tuple>
#include <vector>

class SudokuGame {
 // TO DO: define your own private members/methods as needed
    private:
        std::vector<std::vector<int>> board;
    public:
        SudokuGame() = default;
        SudokuGame(std::string filename);
        // TO DO: include "rule of three": 
        //          destructor
        //          copy constructor
        //          copy assignment operator
        ~SudokuGame(); // destructor
        SudokuGame(const SudokuGame &sg); // copy constructor
        SudokuGame& operator=(const SudokuGame &sg); // copy assignment operator
        const std::vector<std::vector<int>>& grid() const;
        void print() const;
        int size() const;
        int value(int row, int column) const;
        void value(int row, int column, int newValue);
};

class SudokuPlayer {
 // TO DO: define your own private members/methods as needed

    public:
        SudokuPlayer() = default;
        bool solve(SudokuGame& game) const;
};