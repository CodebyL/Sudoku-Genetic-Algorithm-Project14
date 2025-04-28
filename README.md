# 🎯 Sudoku Genetic Algorithm Solver
**Project 14**

**Course:** **420 Artificial Intelligence** 
**Date:** **4/28/25**

---

## 📖 **Project Description**
This project uses a **Genetic Algorithm (GA)** to solve Sudoku puzzles.

The program starts with a given puzzle, fills in empty cells randomly, and applies genetic operations such as **selection**, **crossover**, and **mutation** to improve the solution over generations.

The goal is to reduce conflicts (duplicate numbers) in columns and 3x3 boxes until a valid Sudoku board is found or a maximum number of generations is reached.

---

## ⚙️ **How It Works**
- **Language:** C++
- **Algorithm:** Genetic Algorithm
- **Key Steps:**
  1. **Initialize Population:** Fill empty cells randomly.
  2. **Fitness Function:** Count duplicates in columns and boxes.
  3. **Crossover:** Swap a random row between boards.
  4. **Mutation:** Randomly change a number in non-fixed cells.
  5. Repeat for **1000 generations** or until solved.

---

## 🚀 **How to Compile and Run**
1. Compile code:
```bash
g++ -std=c++11 main.cpp SudokuGA.cpp -o SudokuSolver
```
2. Run the program:
```bash
./SudokuSolver
```
3. Test the program! (make sure you save, compile code, then run for every test changed).
---

## 🧪 **Test Runs**

### **Test 1**
```cpp
std::vector<std::vector<int>> puzzle = {
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
```

**Output (Best Solution Found):**
```bash
5 3 1 2 7 6 4 9 8 
6 2 7 1 9 5 3 2 1 
4 9 8 3 5 4 5 6 7 
8 9 1 5 6 7 9 5 3 
4 8 3 8 1 3 8 7 1 
7 5 2 9 2 8 1 4 6 
8 6 5 6 3 2 2 8 4 
3 4 6 4 1 9 6 1 5 
2 1 9 7 8 5 3 7 9 
```

### **Test 2**
```cpp
std::vector<std::vector<int>> puzzle = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
};
```

**Output (Best Solution Found):**
```bash
4 3 2 2 6 6 7 1 1 
6 8 5 5 7 1 4 9 9 
1 9 7 9 3 4 5 6 3 
8 2 8 1 8 5 1 4 7 
3 1 4 6 9 2 9 5 2 
6 5 9 4 7 3 3 2 8 
2 7 9 3 2 7 8 7 4 
8 4 1 4 5 9 9 3 6 
7 6 3 7 1 8 2 8 5
```

## 🔧 Additional Test Runs

### **Test 3**
```cpp
std::vector<std::vector<int>> puzzle = {
    {0, 2, 0, 6, 0, 8, 0, 0, 0},
    {5, 8, 0, 0, 0, 9, 7, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0},
    {3, 7, 0, 0, 0, 0, 5, 0, 0},
    {6, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 8, 0, 0, 0, 0, 1, 3},
    {0, 0, 0, 0, 2, 0, 0, 0, 0},
    {0, 0, 9, 8, 0, 0, 0, 3, 6},
    {0, 0, 0, 3, 0, 6, 0, 9, 0}
};
```

**Output (Best Solution Found):**
```bash
8 2 4 6 5 8 8 5 9 
5 8 3 7 1 9 7 4 1 
7 9 1 4 4 2 3 6 8 
3 7 2 6 8 2 5 2 7 
6 4 6 5 3 7 6 5 4 
9 5 8 9 4 1 9 1 3 
5 3 8 1 2 4 2 8 2 
4 6 9 8 9 5 4 3 6 
1 2 7 3 7 6 1 9 5 
```

### **Test 4**
```cpp
std::vector<std::vector<int>> puzzle = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};
```

**Output (Best Solution Found):**
```bash
1 2 5 3 8 4 9 4 4 
8 4 8 5 3 6 6 2 8 
6 7 9 9 1 2 5 7 3 
4 5 7 4 6 5 3 9 1 
8 1 2 1 7 3 8 2 6 
2 9 3 2 9 7 5 8 7 
8 6 1 5 4 8 4 1 9 
7 9 4 6 5 3 1 3 2 
5 3 6 7 2 9 7 5 6 
```

### **Test 5**
```cpp
std::vector<std::vector<int>> puzzle = {
    {1, 0, 0, 4, 8, 9, 0, 0, 6},
    {7, 3, 0, 0, 0, 0, 0, 4, 0},
    {0, 0, 0, 0, 0, 1, 2, 9, 5},
    {0, 9, 0, 0, 0, 4, 0, 7, 0},
    {0, 0, 6, 0, 0, 0, 5, 0, 0},
    {0, 1, 0, 9, 0, 0, 0, 8, 0},
    {8, 2, 3, 6, 0, 0, 0, 0, 0},
    {0, 4, 0, 0, 0, 0, 0, 3, 7},
    {6, 0, 0, 5, 1, 2, 0, 0, 4}
};
```

**Output (Best Solution Found):**
```bash
1 6 5 4 8 9 1 1 6 
7 3 4 2 6 7 3 4 8 
2 7 8 3 4 1 2 9 5 
5 9 7 1 5 4 9 7 4 
2 8 6 7 2 8 5 2 3 
4 1 9 9 3 5 6 8 1 
8 2 3 6 9 6 8 6 1 
5 4 7 8 7 3 9 3 7 
6 9 2 5 1 2 2 5 4
```

## 💾 **Data Structures & Functions**
- **Sudoku Board:**  
  The board is represented using `std::vector<std::vector<int>>` which creates a 9x9 grid.

- **Main Functions:**
  - `initializeBoard()` – Randomly fills empty cells in the puzzle.
  - `fitness()` – Counts duplicate numbers in columns and 3x3 boxes to measure how close the board is to a valid solution.
  - `crossover()` – Swaps a random row from two boards to simulate genetic mixing.
  - `mutate()` – Randomly changes a number in a non-fixed cell to introduce variation.
  - `solve()` – Runs the Genetic Algorithm loop for 1000 generations or until a valid solution is found.

---

## 📂 **Files Included**
- `main.cpp` — Contains the main function to run the program.
- `SudokuGA.cpp` — Implements the Genetic Algorithm logic.
- `SudokuGA.h` — Header file defining the SudokuGA class and its functions.
- `README.md` — This file, explaining how the project works.
- `SudokuSolver` — The compiled executable after running the g++ command.
