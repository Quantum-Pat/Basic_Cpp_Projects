#include "main.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using std::cout; using std:: endl; using std:: cin; using std::string; using std::vector; using std::set;

// EXERCISE 1 //

/*Create a function named MaxVectors that takes two const references to vectors of ints. 
It should return a new vector of ints. Each element of the resulting vector should be the 
larger of the two corresponding elements of the given vector arguments. For example, if 
the two vector arguments are {1, -13, 4} and {3, -4, 2, 7}, then the resulting vector 
should be {3, -4, 4, 7}. 

Note: the two input vectors may not be the same length (as in this example).*/

/*
vector<int> MaxVectors(const vector<int> &v1, const vector<int> &v2){
     vector<int> large;
     vector<int> small;
    if (v2.size() > v1.size()){
        large = v2;
        small = v1;
    }
    else if (v1.size() > v2.size()){
        large = v1;
        small = v2;
    }
   else if (v1.size() == v2.size()){
        std::vector<int> result = {};
        std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(result), [](const int& left, const int& right){
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
            return 0;
      }
  );
  return result;
    }
    // Let's pad vec2 to be the same size as vec1 by appending any excess in vec1 to the end of vec2
    std::vector<int> v2_extended = {};
    // this std::copy simply copies vec2 into the back of vec2_extended
    std::copy(small.begin(), small.end(), std::back_inserter(v2_extended));
    // this std::copy copies all elements in vec1 beyond the size of vec2 into the back of vec2_extended
    std::copy(large.begin() + small.size(), large.end(), std::back_inserter(v2_extended));
    // vec3_extended = {1, 2, 3, 4, 5}
    // let's use the std::transform function on both vec1 and vec2_extended
    // the result of our lambda function will be back_inserted into the result vector

    std::vector<int> result = {};
    std::transform(large.begin(), large.end(), v2_extended.begin(), std::back_inserter(result), [](const int& left, const int& right){
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
        return 0;
      }
  );
  return result;
  }

int main() {
    std::vector<int> vec1 = {1, -13, 4};
    std::vector<int> vec2 = {3, -4, 2};
    vector<int> v = MaxVectors(vec1, vec2);
    for (int i:v){
        cout<<i<<endl;
    }

}
*/
 
 // EXERCISE 2 //
 
 /*
int main() {
    std::vector<char> vec1 = {'a', 'b', 'f', 'v', 'd', 'e'};
    std::vector<char> vec2 = {'z', 'c', 'd'};
    vector<char> v = MaxVector(vec1, vec2);
    for (char i:v){
        cout<<i<<endl;
    }
}
*/

// EXERCISE 3 //

/*Create a function named ReplacementCensor, that takes three arguments. The first argument 
should be the filename of an input text file to be processed. The second argument should be 
the file name for an output file to put the processed text. The last argument should be a 
map of strings to strings where the key is a string that needs to be replaced in the contexts 
of the input text file. This function should return a set containing the words that were 
replaced. Please note that the keys should be matched in a case insensitive way and that 
text to replace may not be white space delimited (meaning they may be sub-strings contained 
in longer words).*/

/*
set<string> ReplacementCensor(string filenamein, string filenameout, std::map<string, string> mapp){
    string str;
    std::ifstream filein(filenamein);
    std::ostringstream oss("");
    oss << filein.rdbuf();
    std::string input_string = oss.str();
    std::ofstream fileout(filenameout);
    set<string> s;
    filein.close();
    string temp = input_string;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    for (char chr:temp){
        for (auto i = mapp.begin(); i != mapp.end(); ++i){
            if (temp.find(i->first) != string::npos){
                s.insert(input_string.substr(temp.find(i->first), i->first.length()));
                input_string.replace(temp.find(i->first), i->first.length(), i->second);
                temp.replace(temp.find(i->first), i->first.length(), i->second);
                break;
            }
        }
    }

    std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    for (char chr:temp){
        for (auto i = mapp.begin(); i != mapp.end(); ++i){
            if (temp.find(i->first) != string::npos){
                s.insert(input_string.substr(temp.find(i->first), i->first.length()));
                input_string.replace(temp.find(i->first), i->first.length(), i->second);
                temp.replace(temp.find(i->first), i->first.length(), i->second);
                break;
            }
        }
    }
    fileout << input_string;
    return s;
}

int main() {
    std::map<std::string, std::string> mapp = {{"wolverine", "wolverwimps"}, {"um", "urmom"}, {"CSE", "best major"}};
    string filenamein = "mytext.txt";
    string filenameout = "myout.txt";
    set<string> s = ReplacementCensor(filenamein, filenameout, mapp);

    for (auto i = s.begin(); i != s.end(); ++i){
        cout << *i << endl;
    }

    return 0;
}*/

// EXERCISE 4 //

/*We have provided a function named Func that is perfectly correct. However, you need to remove 
all uses of the algorithm and numeric and libraries from it. You must replace any use of the 
std::iota, std::reverse, std::transform, and std::count_if functions with alternative code that 
uses functions from the string, vector, and iterator libraries instead (with for/while loops and 
if statements). In other words, you must re-implement the behavior of the code below using simple 
string, vector, and iterator operations and traditional loops and if-statements.

Note: all test cases are hidden, but once the algorithm and numeric functions are replaced with 
functionally equivalent code, all the test cases should pass.*/

/*
#include <algorithm> // Remove me
#include <numeric> // Remove me
#include <string>
#include <vector>
#include <iterator>

int Func(int a) 
{   
    std::vector<int> b(a);
    for (int i:b){
        cout << i<< " ";
    }
    cout << endl;
    //std::iota(b.begin(), b.end(), 12);
    b[0] = 12;
    cout << b[0]<< " ";
    int temp = b[0];
    for (int i = 1; i != static_cast<int>(b.size()); ++i){
        temp += 1;
        b[i] = temp;
        cout << b[i] << " ";
    }
    cout << endl;

    std::vector<int> c(b);
    for (int i:c){
        cout << i << " ";
    }
    cout << endl;

    //std::reverse(c.begin(), c.end());
    int i = 0;
    vector<int> v;
    for (auto iter = c.rbegin(); iter != c.rend(); ++iter){
        v.push_back(*iter);
        cout << v[i] << " ";
        ++i;
    }
    c = v;
    cout << endl;

    //std::transform(b.begin(), b.end(), c.begin(), b.begin(), 
    //    [](auto c, auto d){return 2 * c + d;}
    //);
    for (int i:c){
        cout << i<< " ";
    }
    cout << endl;
    for (int i = 0; i != static_cast<int>(b.size());++i){
        b[i] = 2*b[i]+c[i];
        cout << b[i]<< " ";
    }
    cout << endl;
    //return std::count_if(b.begin() + 2, b.end() - 2, 
    //    [](auto d){return std::to_string(d).find("2") != std::string::npos;}
    //);
    int count = 0;
    for (auto i = b.begin()+2; i != b.end() - 2; ++i){
        string var = std::to_string(*i);
        if (var.find("2") != std::string::npos){
            ++count;
        }
    }
    return count;
}

int main(){
    cout << Func(23) << endl;
return 0;
}*/
