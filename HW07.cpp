/*Project Description:
For this project, your task is to create a program to calculate final grades for this course from raw assignment scores. 
There are a number of different functions that our test cases will call, however, you should also create additional helper 
functions to aid in clarity and to encapsulate shared functionality (thus reducing duplicated code).

Note: 5 (out of 80) points of this project are only available if you avoid using looping statements (for, while, for_each) 
and instead utilize the STL provided algorithms. Using other approaches (like recursion) will result in the loss of these 
points. We recommend using an algorithm first approach: for each problem you encounter, think first about what algorithm 
could be useful, instead of trying a traditional loop and refactoring it later.

Your project should be separated into only two files, “main.h” and “main.cpp”. Please write legible code, as we will be 
grading more severely than on Project 1.

Required Functions:

Your GetExamTotalForStudent function should return an int representing the number of total points earned for all exams. 
It takes a map of strings to strings (info) as an argument. Each map key is the name of an assignment 
(e.g., “HW 01”, “HW 02”, “Midterm Exam”, “Final Exam”, etc.) and each value is the corresponding score earned. The map 
also contains other data that is not relevant to this function (e.g., “Notes”, etc.). This function should determine the 
total number of points earned for all exams contained in the given info map.

Your GetTopNHomeworkTotalForStudent function should return an int representing the total points earned for the top-N 
(i.e., highest-scoring) homework assignments. This function takes 2 parameters, the first being the same type of map 
(info) as in the previous function. The second parameter (n) represents the number of homework assignments to tally up. 
Remember that only the top n homework scores contribute to the tally.

Your GetPointTotalForStudent function should return the total number of points earned by a student for all types of 
assignments (i.e., both homework and exams). For this exercise, assume that the total points earned should only factor 
in the top 9 homework scores (i.e., n = 9). 

Your GetIDToInfoFromCSV function should take a single parameter denoting a filename for a CSV formatted file. This 
function should return a map of strings (the student IDs) to  info maps (as described previously) for each student. 
The map value returned by this function will be called id_to_info henceforth. 

Your GetIDToGrade function should take a id_to_info map and return a map of strings (student IDs) to doubles 
(each student’s calculated grades). */

#include "HW07.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <algorithm>
using std::string; using std::endl; using std::cout; using std::cin; using std::vector;

int GetExamTotalForStudent(std::map<std::string, std::string> const & info){
    //iterate through all pairs of info map to see if first value has "Exam"
    vector<int> exam;
    std::transform(info.begin(), info.end(), back_inserter(exam), [] (const auto &p){
        if (p.first.find("Exam") != std::string::npos){
            try{
                return std::stoi(p.second); // adds exam score as int to vector<int> exam
            }
            catch(std::invalid_argument const& invalid){
                return 0; // adds zero to vector<int> exam if score is not an integer
            }
        }
        return 0; // adds zero to vector<int> exam if the key is not an exam
        });
    // summing exam points
    int ExamTotal = std::accumulate(exam.begin(), exam.end(), 0);
    return ExamTotal;
}

int GetTopNHomeworkTotalForStudent(std::map<std::string, std::string> const & info, int n){
    // adding HW points to vector HW
    vector<int> HW;
    // iterating through all pairs of info map to see if first value has "HW"
    std::transform(info.begin(), info.end(), back_inserter(HW), [] (const auto &p){
        if (p.first.find("HW") != std::string::npos){
            try{
                return std::stoi(p.second); // adds HW score as int to vector<int> HW
            }
            catch(std::invalid_argument const& invalid){
                return static_cast<int>(0); // adds zero to vector<int> HW if score is not an integer
            }
        }
        return static_cast<int>(0); // adds zero to vector<int> HW if the key is not a HW
        });
    // sorting the elements of HW in descending order
    std::sort(HW.begin(), HW.end(), [] (auto &a, auto &b){
        return a>b;
    });
    // if the number of elements in HW is less than n return the sum of all elements in HW
    if (static_cast<int>(HW.size()) < n){
        return std::accumulate(HW.begin(), HW.end(), 0);
    }
    // summing highest n HWs in HW
    int HWPointTotal = std::accumulate(HW.begin(), HW.begin() + n, 0);
    return HWPointTotal;
}

int GetPointTotalForStudent(std::map<std::string, std::string> const & info){
    int PointTotal = GetExamTotalForStudent(info) + GetTopNHomeworkTotalForStudent(info, 9);
    return PointTotal;
}

std::map<std::string, std::map<std::string, std::string>> GetIDToInfoFromCSV(std::string const & filename){
    // reading in csv file into single string
    std::ifstream filein(filename);
    std::stringstream buff;
    buff << filein.rdbuf();
    string str_content = buff.str();
    filein.close();
    // assigning each line of the csv file to a string element in the vector "lines"
    int num_lines = std::count(str_content.begin(), str_content.end(), '\n') + 1;
    std::vector<std::string> lines(num_lines);
    std::istringstream iss(str_content);
    std::generate(lines.begin(), lines.end(), [&iss]() {
        string str;
        std::getline(iss, str, '\n');
        return str;
        });
    // seperating each vector in "lines" into another vector denoting the comma seperated values per line
    vector<vector<string>> lines2D;
    std::transform(lines.begin(), lines.end(), back_inserter(lines2D), [] (const string &line) {
        int elements = std::count(line.begin(), line.end(), ',') + 1;
        vector<string> new_lines(elements);
        std::istringstream iss(line);
        std::generate(new_lines.begin(), new_lines.end(), [&iss]() {
            string str;
            std::getline(iss, str, ',');
            return str;
        });
        return new_lines;
    });
    // mapping each student ID number to a map of their associated information
    vector<string> keys = lines2D[0]; // header for student information
    lines2D.erase(lines2D.begin()); // student information without header
    std::map<std::string, std::map<std::string, std::string>> id_to_info;
    std::transform(lines2D.begin(), lines2D.end(), std::inserter(id_to_info, id_to_info.end()), [&keys] (vector<string> const &v){
        std::map<std::string, std::string> indv_stud;
        std::transform(keys.begin(), keys.end(), v.begin(), std::inserter(indv_stud, indv_stud.end()),
                                                                        [] (const string &key, const string &val){
            // mapping each header with its associated information value
            return std::make_pair(key,val);
        });
        // mapping each student ID with its associated information map
        return std::make_pair(indv_stud["ID"], indv_stud);
    });
    return id_to_info;
}

std::map<std::string, double> GetIDToGrade(std::map<std::string, std::map<std::string, std::string>> const & id_to_info){
    // iterating through each students information map by "ID", calculating their overall grade based on a 4.0 scale 
    std::map<std::string, double> studentgrades;
    std::transform(id_to_info.begin(), id_to_info.end(), std::inserter(studentgrades, studentgrades.end()), [] (auto const &info){
        int pointtotal = GetPointTotalForStudent(info.second);
        double FinalGrade;
        // 4.0 scale
        if (pointtotal >= static_cast<int>(864)){
            FinalGrade = 4.0;
        }
        else if (pointtotal >= static_cast<int>(816) && pointtotal <= static_cast<int>(863)){
            FinalGrade = 3.5;
        }
        else if (pointtotal >= static_cast<int>(768) && pointtotal <= static_cast<int>(815)){
            FinalGrade = 3.0;
        }
        else if (pointtotal >= static_cast<int>(720) && pointtotal <= static_cast<int>(767)){
            FinalGrade = 2.5;
        }
        else if (pointtotal >= static_cast<int>(672) && pointtotal <= static_cast<int>(719)){
            FinalGrade = 2.0;
        }
        else if (pointtotal >= static_cast<int>(624) && pointtotal <= static_cast<int>(671)){
            FinalGrade = 1.5;
        }
        else if (pointtotal >= static_cast<int>(576) && pointtotal <= static_cast<int>(623)){
            FinalGrade = 1.0;
        }
        else {
            FinalGrade = 0.0;
        }
        // mapping each students ID number with their calculated final grade
        return std::make_pair(info.first, FinalGrade);
    });
    return studentgrades;
}

int main() {
  /// read file
  std::string filename = "grades.csv";
  std::cout << "File: " << filename << std::endl;
  std::map<std::string, std::map<std::string, std::string>> id_to_info =
      GetIDToInfoFromCSV(filename);

  /// iterate through each student and calculate/display grades
  std::cout << "id_to_info:" << std::endl;
  for (const auto& x : id_to_info) /// this loop will not impact your grade
  {
    const std::string& student_id = x.first;
    const std::map<std::string, std::string>& student_info = x.second;
    std::cout << "Student " << std::right << std::setw(6);
    std::cout << student_id << " - ";
    std::cout << "Exam: " << std::right << std::setw(3);
    std::cout << GetExamTotalForStudent(student_info) << " ";
    std::cout << "HW: " << std::right << std::setw(3);
    std::cout << GetTopNHomeworkTotalForStudent(student_info, 9) << " ";
    std::cout << "Total: " << std::right << std::setw(3);
    std::cout << GetPointTotalForStudent(student_info) << " ";
    std::cout << std::endl;
  }

  /// convert id_to_info map to id_to_grade map
  std::map<std::string, double> id_to_grade = GetIDToGrade(id_to_info);

  /// iterate through and display each student's grade
  std::cout << "id_to_grade:" << std::endl;
  for (const auto& x : id_to_grade) /// this loop will not impact your grade
  {
    const std::string& student_id = x.first;
    const double& student_grade = x.second;
    std::cout << "Student " << std::right << std::setw(6);
    std::cout << student_id << " - ";
    std::cout << "GPA: " << std::right << std::fixed << std::setprecision(1);
    std::cout << student_grade << " ";
    std::cout << std::endl;
  }

  return 0;
}