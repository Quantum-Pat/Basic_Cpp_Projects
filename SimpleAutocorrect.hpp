#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string NextWord(std::string& sentence);
bool CompareWords(const std::string& word1, const std::string& word2);
std::string AutoCorrectWord(const std::vector<std::string>& vocabulary, const std::string& word);