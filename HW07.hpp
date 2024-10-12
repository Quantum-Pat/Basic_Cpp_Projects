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