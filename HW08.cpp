// EXERCISE 1 //

/*Create a class, named Penultimate with a constructor that takes a string argument 
(note: this should not be a reference to a string). Your Penultimate class should also 
include a member function (method), named push_back, that takes a string as an argument 
and returns a string (note: these should not be references to strings). The string 
returned by push_back should be the string that was provided to push_back in the most 
recent call of the method (or the string provided to the constructor if this is the 
first call to push_back. (See the example below.)

Note: your Penultimate class should be declared in the main.h file. Your Penultimate 
class constructor and member functions should be defined in the main.cpp file.*/

/*
#include <iostream>
#include <string>
#include "main.h"
using std::string; using std::cout;

// TO DO: define Penultimate class constructor and methods here.
Penultimate::Penultimate(string str_){
    str = str_;
}
string Penultimate::push_back(string word){
    str += " " + word;
    auto pos2 = str.rfind(' ');
    auto pos1 = str.rfind(' ', pos2-1);
    return str.substr(pos1+1, pos2-pos1-1);
}
int main() {
    Penultimate p("first");
    std::string s = p.push_back("second"); // s is "first"
    cout << s << endl;
    cout << p.push_back("Third") << endl; // returns "second"
    cout << p.push_back("last") << endl; // returns "Third"
    return 0;
}*/

// EXERCISE 2 //

/*Create a class, named ForgetfulVector, that acts like a vector in that it supports the size, at, and 
push_back methods. It should have a converting constructor that takes a vector of ints as an argument. 
Your ForgetfulVector class only needs to support the storage of int values (templated classes will be taught later). 
The one strange thing is that your ForgetfulVector should “forget” the first time it encounters a value, such that 
it doesn’t present that value or give it an index. */

/*
#include <iostream>
#include "main.h"
using std::vector; using std::cout; using std::endl;

// TO DO: define ForgetfulVector class constructor and methods here.
ForgetfulVector::ForgetfulVector(vector<int> v_){
    for (int i:v_){
        push_back(i);
    }
}

int ForgetfulVector::size(){
    return v.size();
}
int& ForgetfulVector::at(int n){
    return v.at(n);
}
void ForgetfulVector::push_back(int n){
    auto p = s.insert(n);
    bool success = p.second;
    if (!success){
        v.push_back(n);
    }
}

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 3, 4, 5, 4};
    ForgetfulVector fv(vec);
    cout << fv.size() << "should be" << 3 << endl;
    cout << fv.at(0) << "should be" << 2 << endl;
    cout << fv.at(1) << "should be" << 3 << endl;
    cout << fv.at(2) << "should be" << 4 << endl;
    return 0;
}*/

// EXERCISE 3 //
/*Create a class, named Temperature, with a constructor that takes two arguments. The first argument should be a double, 
representing a temperature. The second argument should be a char, denoting if the unit is C, F, R, K. This class should 
also include four methods: AsCelsius, AsFahrenheit, AsKelvin, and AsRankine. Each of these methods should take no arguments 
and return the temperature value in the corresponding unit (as a double). */

/*
#include <iostream>
#include "main.h"

// TO DO: define Temperature class constructor and methods here.
Temperature::Temperature(double temp_, char unit_){
    if (unit_ == 'F'){
        temp = (temp_ - 32)/1.8; 
    }
    else if (unit_ == 'R'){
        temp = (temp_ - 491.67)/ 1.8;
    }
    else if (unit_ == 'K'){
        temp = temp_ - 273.15;
    }
    else if (unit_ == 'C'){
        temp = temp_;
    }
}
double Temperature::AsCelsius(){
    return temp;
}
double Temperature::AsFahrenheit(){
    return (temp * 1.8 + 32);
}
double Temperature::AsRankine(){
    return (temp * 1.8 + 491.67);
}
double Temperature::AsKelvin(){
    return (temp + 273.15);
}

int main() {
    Temperature t(13, 'C');
    cout << t.AsCelsius() <<"close to " << 13 << endl;
    cout << t.AsKelvin() << "close to" << 286.15 << endl;
    cout << t.AsRankine() << "close to" << 515.07 << endl;
    Temperature t2(45.6, 'R');
    cout << t2.AsFahrenheit() << "close to" << -414.07 << endl;
    // Be sure to test all combinations!
    return 0;
}
*/

// EXERCISE 5 //
/*Create a class, named Counter, with a constructor that takes an int argument. The purpose of your Counter class is to count 
down from this initial int value. Your Counter class should include a method called value  that takes no arguments. Your value 
method should return the current int value of your Counter object, starting with the initial value passed to its constructor. 
Each time the value method is called, it should decrement (subtract one from) the current value of your Counter object. Be sure 
the constructor and the value getter method are the only public members of the class.*/

/*
#include <iostream>
#include "main.h"

Counter::Counter(int n_){
    n = n_;
}
int Counter::value(){
    int x = n--;
    return x;
}

int main(){
    Counter num = 5;
    cout << num.value() << " " << num.value() << " " << num.value();
    return 0;
}
*/

// EXERCISE 6 //

/*For this exercise, start with your working solution from the previous exercise. Now, you need to 
add additional functionality.

1.) Implement the << operator so that your  Counter can write itself to a stream. For example, it should write "Counter(9)@8" 
if Counter was initialized with the value 9 and the current value to be returned by the value method is an 8.  Another example: 
it should write “Counter(7)@3” if Counter was initialized with the value of 7 and the current value to be return by the value 
method is 3.

2.) Implement the + operator to return a new Counter object with an initial value and current values equal to the sum of the 
two added Counter's data members. 

3.) Each Counter object should have a public data member named log_, which should be a vector of strings. This vector should 
initially be empty, but each method call on your Counter object should add a string to its log_ vector. (See the test cases 
for exact formatting.)

Note: be sure the two existing functions (constructor and value method) add to the the log_ vector, too.

Example:
The constructor should log “Counter constructor called with a 7.” when it is constructed with an initial value of 7.
The value method should log “Counter::value called and returned a 6.” when it returns a value of 6.
The << operator should log “Counter::<< called.”
The + operator should log “Counter::+ called.”*/

/*
#include <iostream>
#include <sstream>
#include "main.h"
#include <string>
using std::string; using std::cout;

Counter::Counter(int n_){
    init = n = n_;
    log_.push_back("Counter constructor called with a " + std::to_string(n) + ".");
}

int Counter::value(){
    int x = n--;
    log_.push_back("Counter::value called and returned a " + std::to_string(x) + ".");
    //os << log_ << endl;
    return x;
}

std::ostream& operator<<(std::ostream& os, Counter& counter) {
    // TO DO: Update log for counter object
    // counter.log_.push_back("Counter(" + std::to_string(counter.init) + ")@" + std::to_string(counter.n));
    os << "Counter(" + std::to_string(counter.init) + ")@" + std::to_string(counter.n);
    counter.log_.push_back("Counter::<< called.");
    // TO DO: output appropriate text to os stream
    return os;
    }

Counter operator+(Counter const &c1, Counter const & c2){
    // return something where c3.init = c1.init + c2.init AND c3.n = c1.n + c2.n
    Counter c3(c1.init + c2.init);
    c3.n = c1.n + c2.n;
    c3.log_.push_back("Counter::+ called.");
    return c3;
}

int main(){
    Counter num = 5;
    cout << num.value() << " " << num.value() << " " << num.value();
    return 0;
}*/

// EXERCISE 7 //

/* Now you need to modify your Counter class from the previous exercise such that it includes a default constructor 
(setting the initial value to 0). Your Counter class should also be updated to support the “Rule of 3” functions. 
Your Counter class should also log each time one of these functions is called.

Example

When the default constructor is called, it should log “Counter default constructor called.”
When the destructor is called, it should log “Counter destructor called.”
When the copy constructor is called, it should log “Counter copy constructor called.” 
(Note: you should add the new log entry after copying the other Counter object’s log.)
When the = operator is called, it should log “Counter::= called.”
(Note: you should add the new log entry after copying the other Counter object’s log.)*/

/*
#include <iostream>
#include <sstream>
#include "main.h"
#include <string>
using std::string; using std::cout;

Counter::Counter(int n_){
    init = n = n_;
    log_.push_back("Counter constructor called with a " + std::to_string(n) + ".");
}
Counter::Counter(void){
    init = n = 0;
    log_.push_back("Counter default constructor called.");
}
Counter::~Counter(){
    log_.push_back("Counter constructor called.");
};
Counter::Counter(const Counter &c1){
    n = c1.n;
    init = c1.init;
    log_ = c1.log_;
    log_.push_back("Counter copy constructor called.");
}
Counter& Counter::operator=(const Counter &c){
    n = c.n;
    init = c.init;
    log_ = c.log_;
    log_.push_back("Counter::= called.");
    return *this;
}
int Counter::value(){
    int x = n--;
    log_.push_back("Counter::value called and returned a " + std::to_string(x) + ".");
    //os << log_ << endl;
    return x;
}

std::ostream& operator<<(std::ostream& os, Counter& counter) {
    // TO DO: Update log for counter object
    // counter.log_.push_back("Counter(" + std::to_string(counter.init) + ")@" + std::to_string(counter.n));
    os << "Counter(" + std::to_string(counter.init) + ")@" + std::to_string(counter.n);
    counter.log_.push_back("Counter::<< called.");
    // TO DO: output appropriate text to os stream
    return os;
    }

Counter operator+(Counter const &c1, Counter const & c2){
    // return something where c3.init = c1.init + c2.init AND c3.n = c1.n + c2.n
    Counter c3(c1.init + c2.init);
    c3.n = c1.n + c2.n;
    c3.log_.push_back("Counter::+ called.");
    return c3;
}

int main(){
    Counter num = 5;
    cout << num.value() << " " << num.value() << " " << num.value();
    return 0;
}
*/
