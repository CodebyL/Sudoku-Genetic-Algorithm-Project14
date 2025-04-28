#ifndef SUDOKUGA_H
#define SUDOKUGA_H

#include <vector>

// This class handles the Genetic Algorithm for solving Sudoku
class SudokuGA {
public:
    // Constructor takes the starting puzzle
    SudokuGA(std::vector<std::vector<int>> puzzle);

    // Main function to run the solver
    void solve();

private:
    std::vector<std::vector<int>> fixedCells;   // Stores the original puzzle (fixed numbers)
    std::vector<std::vector<int>> bestBoard;    // Stores the best solution found

    // Functions for different parts of the Genetic Algorithm
    void initializeBoard();    // Create a starting board by filling empty cells
    int fitness(const std::vector<std::vector<int>>& board);  // Check how good the board is
    std::vector<std::vector<int>> crossover(const std::vector<std::vector<int>>& parent1, const std::vector<std::vector<int>>& parent2);  // Mix boards
    void mutate(std::vector<std::vector<int>>& board);  // Randomly change a number
    void printBoard(const std::vector<std::vector<int>>& board);  // Show the board
};

#endif