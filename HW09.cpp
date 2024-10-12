#include "HW09.hpp"
using std::cout; using std::string; using std::cin; using std::endl; using std::vector;

// EXERCISE 1 //
/*For this exercise, you need to sort a list of whitespace-separated integers using three different sort algorithms: 
bubble sort, selection sort, and insertion sort. These algorithms are described here:
http://theoryapp.com/selection-insertion-and-bubble-sort/ https://en.wikipedia.org/wiki/Insertion_sort
Your program should read in a sequence of whitespace-separated integers. It should print out the order of the initial sequence 
of values and also print out the sequence of values after each swap for each of the three sorting algorithms (i.e., bubble, 
selection, and insertion). Each of your sort functions should also return a copy of the sorted vector. Sorting will be a big 
part of CSE 331, so this question is to give you an early taste of understanding general algorithms.*/

// TO DO: define these sort functions
std::vector<int> bubble_sort(std::vector<int> values){
    for (int i:values){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < static_cast<int>(values.size()) -1; ++i){
        for (int j = 0; j < static_cast<int>(values.size() - i - 1); ++j){
            if (values[j] > values[j + 1]){
                std::swap(values[j], values[j + 1]);
                for (int i:values){
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
    return values;
}

std::vector<int> selection_sort(std::vector<int> vec){
    for (int i:vec){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < static_cast<int>(vec.size()) -1; ++i){
        int min = i;
        for (int j = i + 1; j < static_cast<int>(vec.size()); ++j){
            if (vec[min] > vec[j]){
                min = j;
            }
        }
        if (min != i){
            std::swap(vec[i], vec[min]);
            for (int i:vec){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return vec;
}

std::vector<int> insertion_sort(std::vector<int> vec){
    for (int i:vec){
        cout << i << " ";
    }
    cout << endl;
    int i = 1;
    while(i < vec.size()){
        int j = i;
        while(j > 0 && vec[j-1] > vec[j]){
            std::swap(vec[j], vec[j-1]);
            j = j -1;
            for (int i:vec){
                cout << i << " ";
            }
            cout << endl;
        }
        i = i + 1;
    }
    return vec;
}

int main() {
    // read a line from std::cin
    std::string line;
    getline(std::cin, line);

    // TO DO: get whitespace-separated integers from line into an int vector
    //std::vector<int> values;
    std::istringstream iss(line);
    std::vector<int> values(std::istream_iterator<int>(iss), {});
    
    // perform bubble sort
    std::cout << "Bubble Sort" << std::endl;
    //bubble_sort(values);

    // perform selection sort
    std::cout << "Selection Sort" << std::endl;
    //selection_sort(values);

    // perform insertion sort
    std::cout << "Insertion Sort" << std::endl;
    insertion_sort(values);

    vector<int> v{1,1,1,2,2,2,3,4,5,5,6};
    TwoOrLess vec(v);
    vec.insert(7);
    cout << vec.count(7) << " " << vec.size();

    const std::map<string, int> word_counts = {
        {"josh", 2},
        {"smart", 1},
        {"cse", 8},
        {"ferret", 1},
        {"politics", 0},
        {"C++", 1},
    };
    std::set<std::string> s = only_once(word_counts);
    for (string i:s){
        cout << i << " ";
    }


    return 0;
    }

// EXERCISE 2 //
/*Create a class, named "TwoOrLess.” Declare your class in a header file (main.h) and an implement the class functions 
in your implementation file (main.cpp).  Your TwoOrLess class is expected to act like a set, except it should be able 
to hold 0, 1, or 2 duplicates of each int value. Your TwoOrLess class needs to support the following methods:*/

TwoOrLess::TwoOrLess(){
    v = {};
};

TwoOrLess::TwoOrLess(vector<int> vec){
    for (auto i = vec.begin(); i != vec.end(); ++i){
        int count = std::count(vec.begin(),vec.end(), *i);
        if (count > 2){
            while(count > 2){
                vec.erase(std::find(vec.begin(), vec.end(), *i));
                --count;
            }
        }
    }
    std::sort(vec.begin(), vec.end());
    v = vec;
};

std::pair<std::vector<int>::iterator, bool> TwoOrLess::insert(const int& element){
    std::vector<int>::iterator iter = std::find(v.begin(), v.end(), element);
    int count = std::count(v.begin(), v.end(), element);
    if (count == 0){
        v.push_back(element);
        std::sort(v.begin(), v.end());
        std::vector<int>::iterator iter = std::find(v.begin(), v.end(), element);
        std::pair<std::vector<int>::iterator, bool> pair = std::make_pair(iter,true);
        return pair;
    }
    else if (count < 2 && count != 0){
        v.push_back(element);
        std::sort(v.begin(), v.end());
        std::vector<int>::iterator iter = std::find(v.begin(), v.end(), element);
        std::pair<std::vector<int>::iterator, bool> pair = std::make_pair(iter,true);
        return pair;
    }
    std::pair<std::vector<int>::iterator, bool> pair = std::make_pair(iter,false);
    return pair;
}

int TwoOrLess::count(const int& element){
    return std::count(v.begin(), v.end(), element);
}

int TwoOrLess::size(){
    return v.size();
}

// EXERCISE 3 //
/* Suppose we have a std::map<std::string, int> that represents the number of times a word appears in a particular text.
For this exercise, we need you to define functions that transform the data in this map to a related data structure, 
described as follows.
// only_once
This function should to the word_counts map and returns a std::set<std::string> of words that only appeared once in t
he text.
std::set<std::string> only_once(const std::map<std::string, int>& word_counts);
// count_to_words
This function should take the word_counts map and return a std::multimap<int, std::string> of the counts as keys to 
the words.
std::multimap<int, std::string> count_to_words(const std::map<std::string, int>& word_counts);
// count_to_set
This function should take the word_counts map and return a std::map<int, std::set<std::string>> of the counts as keys 
to each set of words with that respective count.
std::map<int, std::setstd::string> count_to_set(const std::map<std::string, int>& word_counts); */

std::set<std::string> only_once(const std::map<std::string, int>& word_counts){
    std::set<std::string> s;
    for (auto i = word_counts.begin(); i != word_counts.end(); ++i){
        if (i->second == 1){
            s.insert(i->first);
        }
    }
    return s;
}
std::multimap<int, std::string> count_to_words(const std::map<std::string, int>& word_counts){
    std::multimap<int, std::string> mmap;
    for (auto i = word_counts.begin(); i != word_counts.end(); ++i){
        mmap.insert({i->second, i->first});
    }
    return mmap;
}
std::map<int, std::set<std::string>> count_to_set(const std::map<std::string, int>& word_counts){
    std::map<int, std::set<std::string>> map;
    for (auto i = word_counts.begin(); i != word_counts.end(); ++i){
        std::set<std::string> s;
        for (auto j = word_counts.begin(); j != word_counts.end(); ++j){
            if (i->second == j->second){
                s.insert(j->first);
            }
        }
        map.insert({i->second, s});
    }
    return map;
}

// EXERCISE 6 //

/*Create a program that leaks memory. Any program that doesn’t leak memory will fail our test cases.
Let’s try not to do this in the future.*/
// int main() {
//   int const chunk = 50;

//   for (int i = 0; i < 10; i++) {
//     int *ary = new int[chunk];
//     ary[0] = 1;
//     for (int j = 1; j < chunk; ++j){
//         ary[j] = ary[j - 1] + 1;
//     }
//   }
// }

// EXERCISE 7 //
/* Create a function, named “ArrayToVector” that takes two arguments: (1) a pointer to a dynamically allocated array 
of any type and (2) the size of that array (as an int value). Your ArrayToVector function should return a std::vector 
containing the elements of that array. Your function should also dispose of the array when it is finished with it. Be 
sure that your function can accept arrays of any type (i.e., make it a templated function, defined in your main.h file).*/

// int main(){
//     int size = 1;
//     int* arr = new int[size];
//     arr[0] = 8;
//     std::vector<int> result = ArrayToVector(arr, size);
//     for (int i:result){
//         cout << i << " ";
//     }
//     return 0;
// }