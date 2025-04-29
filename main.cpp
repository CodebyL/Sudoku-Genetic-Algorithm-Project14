#include <iostream>
#include <vector>
using namespace std;

// 9x9 Sudoku Board
vector<vector<int>> board = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Function to check if placing num at (row,col) is valid
bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false; // Check row
        if (board[i][col] == num) return false; // Check column
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == num) return false; // Check 3x3 grid
    }
    return true;
}

// Recursive function to solve the board
bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Empty cell
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num; // Place num
                        if (solveSudoku()) return true; // Solve next
                        board[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved!
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    if (solveSudoku()) {
        cout << "Sudoku Solved Successfully!\n";
        printBoard();
    } else {
        cout << "No solution exists!\n";
    }
    return 0;
}