#include "SudokuSolver.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using std::cout; using std::string; using std::cin; using std::endl; using std::vector;

// Constructor converting csv file of Sudoku Game board to 2D vector
SudokuGame::SudokuGame(std::string filename){
    std::string line, word;
    std::ifstream filein(filename);
    while(getline(filein, line)){
        vector<int> v;
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            v.push_back(std::stoi(word));
        }
        board.push_back(v);
    }
    filein.close();
}

// Destructor
SudokuGame::~SudokuGame(){}

// Copy Constructor
SudokuGame::SudokuGame(const SudokuGame &sg){
    board = sg.board;
}

// Copy assignment operator
SudokuGame& SudokuGame::operator=(const SudokuGame &sg){
    board = sg.board;
    return *this;
}

// Getter function returing a const reference to the Sudoku Board
const std::vector<std::vector<int>>& SudokuGame::grid() const{
    return board;
}

// Printing out the Sudoku board into a user friendly display
void SudokuGame::print() const{
    for(int i = 0; i != static_cast<int>(board.size()); ++i){
        if (i > 0 && i%3 == 0){
            cout << "---------------------" << endl;
        }
        for (int j = 0; j != static_cast<int>(board.size()); ++j){
            if (j > 0 && j%3 == 0){
                cout << "|" << " ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Returning the size of the Sudoku board
int SudokuGame::size() const{
    return static_cast<int>(board.size());
}

// Getting the value of the Sudoku board at a given index
int SudokuGame::value(int row, int column) const{
    return board[row][column];
}

// Setting the value of the Sudoku board at a given index
void SudokuGame::value(int row, int column, int newValue){
    board[row][column] = newValue;
}

// Solving the Sudoku game (if possible)
bool SudokuPlayer::solve(SudokuGame& game) const{
    int row, col;
    bool found = false;
    // Searching for an empty cell in game
    for (int i = 0; i != static_cast<int>(game.size()); ++i){
        for (int j = 0; j != static_cast<int>(game.grid()[i].size()); ++j){
            if (game.value(i,j) == 0){
                row = i;
                col = j;
                found = true;
                break;
            }
        }
    }
    if (!found){
        return true;
    }
    // If empty cell is found in Sudoku game attempt to find solution
    if (found){
        bool test_row = false;
        bool test_block = false;
        bool test_col = false;
        for (int x = 1; x <= 9; ++x){
            // Testing to see if x isnt in the row containing the empty cell
            for (int j = 0; j != static_cast<int>(game.grid()[row].size()); ++j){
                if (game.value(row,j) == x){
                    test_row = false;
                    break;
                }
                else {
                    test_row = true;
                }
            }
            // Testing to see if x isnt in the column containing the empty cell
            for (int i = 0; i != static_cast<int>(game.size()); ++i){
                if (game.value(i,col) == x){
                    test_col = false;
                    break;
                }
                else{
                    test_col = true;
                }
            }
            // Testing to see if x isnt in the block containing the empty cell
            for (int i = static_cast<int>((row/3))*3; i < static_cast<int>(row/3)*3 + 3; ++i){
                for (int j = static_cast<int>((col/3))*3; j < static_cast<int>(col/3)*3 + 3; ++j){
                    if (game.value(i,j) == x){
                        test_block = false;
                        break;
                    }
                    else{
                        test_block = true;
                    }
                }
            }
            // If each of the above tests pass, change the empty value in Sudoku game with x, and recall SudokuPlayer::solve to
            // solve for next empty cell if possible
            if (test_row == true && test_col == true && test_block == true){
                game.value(row, col, x);
                if (SudokuPlayer::solve(game)){
                    return true;
                } 
                else {
                    game.value(row, col, 0);
                }
            }
        }
    }
    // Sudoku game cannot be solved
    return false;
}

int main() {
  SudokuGame game("sudoku_game_2.csv");
  std::cout << "Puzzle" << std::endl;
  game.print();

  SudokuPlayer player;
  bool solved = player.solve(game);
  if (solved) {
      std::cout << "Solution found!" << std::endl;
      game.print();
  } else {
      std::cout << "No solution found." << std::endl;
  }
  return 0;
}