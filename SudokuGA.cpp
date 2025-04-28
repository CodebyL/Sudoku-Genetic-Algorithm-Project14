#include "SudokuGA.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Save the puzzle and set random seed
SudokuGA::SudokuGA(std::vector<std::vector<int>> puzzle) {
    fixedCells = puzzle;
    srand(time(0));  // Set random seed
}

// Main function to solve Sudoku
void SudokuGA::solve() {
    initializeBoard();  // Fill empty cells randomly

    // Repeat for 1000 generations (tries)
    for (int generation = 0; generation < 1000; generation++) {
        // Create a new board by mixing (crossover)
        std::vector<std::vector<int>> newBoard = crossover(bestBoard, bestBoard);

        // Apply random change (mutation)
        mutate(newBoard);

        // If new board is better, keep it
        if (fitness(newBoard) < fitness(bestBoard)) {
            bestBoard = newBoard;
        }

        // If fitness is 0, puzzle is solved
        if (fitness(bestBoard) == 0) {
            break;
        }
    }

    // Print the best board found
    std::cout << "Best Solution Found:" << std::endl;
    printBoard(bestBoard);
}

// Fill empty cells with random numbers 1-9
void SudokuGA::initializeBoard() {
    bestBoard = fixedCells;  // Start with original puzzle
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (bestBoard[row][col] == 0) {
                bestBoard[row][col] = (rand() % 9) + 1;  // Random number 1-9
            }
        }
    }
}

// Calculate fitness: count how many duplicate numbers there are
int SudokuGA::fitness(const std::vector<std::vector<int>>& board) {
    int score = 0;

    // Check columns for duplicates
    for (int col = 0; col < 9; col++) {
        int count[10] = {0};
        for (int row = 0; row < 9; row++) {
            count[board[row][col]]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (count[i] > 1) score += (count[i] - 1);  // Add penalty for duplicates
        }
    }

    // Check 3x3 boxes for duplicates
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            int count[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    count[board[boxRow + i][boxCol + j]]++;
                }
            }
            for (int i = 1; i <= 9; i++) {
                if (count[i] > 1) score += (count[i] - 1);  // Add penalty for duplicates
            }
        }
    }

    return score;  // Lower score = better board
}

// Crossover: swap a random row between parents
std::vector<std::vector<int>> SudokuGA::crossover(const std::vector<std::vector<int>>& parent1, const std::vector<std::vector<int>>& parent2) {
    std::vector<std::vector<int>> child = parent1;
    int row = rand() % 9;  // Pick a random row
    child[row] = parent2[row];  // Swap the row
    return child;
}

// Mutation: randomly change a number in a non-fixed cell
void SudokuGA::mutate(std::vector<std::vector<int>>& board) {
    int row = rand() % 9;
    int col = rand() % 9;

    // Only mutate if it's not a fixed number
    if (fixedCells[row][col] == 0) {
        board[row][col] = (rand() % 9) + 1;
    }
}

// Print the Sudoku board
void SudokuGA::printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}