#include "SimpleAutocorrect.hpp"
using std::cout; using std::cin; using std::endl; using std::string;

// TO DO: implement this NextWord function.
// The NextWord Function below takes in a string reference as an input and outputs the first word in that string
std::string NextWord(std::string& sentence){
    int i = 0;
    for (char chr:sentence){
        // This if statement executes if the character in "sentence" is " " and the following character is not " "
        if (chr == ' ' && sentence[i+1] != ' '){
            string first_word = sentence.substr(0, i);
            sentence.erase(0, i+1);
            return first_word;
        }
        // This if statment executes for the last word in the sentence, when no whitespace preceeds the last character
        else if (i == sentence.size()-1) {
            string first_word = sentence.substr(0,i+1);
            sentence.erase(0,i+1);
            return first_word;
        }
        ++i;
    }
    return "";
}

// TO DO: implement this CompareWords function.
/* The CompareWords Function below takes in two const string references and tests to see if adding or removing a letter to one of the
   references results in the other reference */
bool CompareWords(const std::string& word1, const std::string& word2){
    string temp_word1 = word1, temp_word2 = word2;
    if (word1.size() == word2.size()){
        if (word1 == word2){
            return true;
        }
        else {
            return false;
        }
    }
    else if (word1.size() > word2.size()){
        // deleting each letter in word1 one at a time and checking to see if word1 == word2
        for (int i = 0; i < word1.size(); ++i){
            string temp_word1 = word1, temp_word2 = word2;
            temp_word1.erase(i,1);
            if (temp_word1 == temp_word2){
                return true;
            }
        }
    }
    else {
        // iterating over each letter in word1
        for (int i = 0; i <= word1.size(); ++i){
            // adding a letter one at a time in every position to word1 and checking to see if word1 == word2
            for (char letter = 'a'; letter <= 'z'; ++letter){
                string temp_word1 = word1, temp_word2 = word2;
                temp_word1.insert(i, 1, letter);
                if (temp_word1 == temp_word2){
                    return true;
                }
            }
        }
    }
    return false;
}

// TO DO: implement this AutoCorrectWord function.
/* AutoCorrectWord Function below takes a const reference vector of strings as input and a const reference word and uses the  
   CompareWords function see if adding or removing a letter to the const reference word will result in one of the strings contained in
   the reference vector vocabulary*/
std::string AutoCorrectWord(const std::vector<std::string>& vocabulary, const std::string& word){
    for (int i = 0; i < vocabulary.size(); ++i){
        if (CompareWords(vocabulary[i], word) == true){
            return vocabulary[i];
        }
    }
    return word;
}

int main() {
  // list of vocabulary words
  const std::vector<std::string> vocabulary = {
      "apple",      "apricot",    "banana",      "blackberry", "blueberry",
      "cantaloupe", "cherry",     "clementine",  "cranberry",  "date",
      "durian",     "elderberry", "fig",         "gooseberry", "grapefruit",
      "grape",      "guava",      "honeydew",    "jackfruit",  "kiwifruit",
      "kumquat",    "lemon",      "lime",        "loquat",     "lychee",
      "mango",      "melon",      "mulberry",    "nectarine",  "orange",
      "papaya",     "peach",      "pear",        "persimmon",  "pineapple",
      "plantain",   "plum",       "pomegranate", "raspberry",  "rhubarb",
      "soursop",    "strawberry", "tamarind",    "tangerine",  "watermelon"};

  // repeatedly process sentences from the user
  std::string sentence;
  while (std::getline(std::cin, sentence)) {
    // iterate through each word in the sentence and auto-correct
    std::cout << "Corrected sentence: ";
    std::string word = NextWord(sentence);
    while (word != "") {
      // auto-correct the current word using our vocabulary
      std::string correction = AutoCorrectWord(vocabulary, word);
      std::cout << correction << " ";

      // get next word in sentence
      word = NextWord(sentence);
    }
    std::cout << std::endl;
  }

  return 0;
}