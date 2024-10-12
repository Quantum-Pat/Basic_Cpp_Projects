#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <istream>
#include <iterator>
#include <set>
#include <map>

std::set<std::string> only_once(const std::map<std::string, int>& word_counts);

class TwoOrLess{
    public:
        std::vector<int> v;
        TwoOrLess(std::vector<int> vec);
        TwoOrLess();
        std::pair<std::vector<int>::iterator, bool> insert(const int& element);
        int count(const int& element);
        int size();
};

// EXERCISE 7 //
// TO DO: define templated ArrayToVector function here.
#include <vector>
template <typename Type>
std::vector<Type> ArrayToVector(Type* point, Type size){
    std::vector<Type> v;
    for (auto i = point; i != point + size; ++i){
        v.push_back(*i);
    }
    delete[] point;
    return v;
}