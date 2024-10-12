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