# Sudoku Solver

A C++ program to solve Sudoku puzzles.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Files](#files)

## Introduction

This project contains a C++ program that solves a given Sudoku puzzle using a backtracking algorithm. It reads the puzzle from an input file, solves it, and writes the solution to an output file.

## Features

- Efficient backtracking algorithm to solve Sudoku puzzles
- Handles standard 9x9 Sudoku puzzles
- Reads puzzles from a file
- Outputs solutions to a file

## Usage

To use the Sudoku Solver, follow these steps:

1. Clone this repository:
    ```sh
    git clone https://github.com/yourusername/sudoku-solver.git
    ```
2. Navigate to the project directory:
    ```sh
    cd sudoku-solver
    ```
3. Compile the code:
    ```sh
    g++ main.cpp -o sudoku_solver
    ```
4. Run the program with input and output files:
    ```sh
    ./sudoku_solver input.txt output.txt
    ```

## Input Format

The input file should contain a 9x9 Sudoku grid with spaces for empty cells. Each row of the grid should be on a new line. For example:

```
7    8
  9  31 
 4  257 
3     2  
 4  6  5 
9 1   8  
7   2   3
5   8 4  
  9  1  
```

## Output Format

The output file will contain the solved 9x9 Sudoku grid. For example:

```
1 2 5 7 3 6 9 4 8
4 7 6 9 5 8 3 1 2
8 9 3 4 1 2 5 7 6
3 5 8 1 9 4 2 6 7
2 4 7 8 6 3 1 5 9
9 6 1 2 7 5 8 3 4
7 1 4 5 2 9 6 8 3
5 3 2 6 8 7 4 9 1
6 8 9 3 4 1 7 2 5
```

## Files

- `main.cpp`: Contains the main Sudoku solver algorithm.
- `AlternateSolution.cpp`: An alternate implementation of the Sudoku solver.
- `input.txt`: An example input file containing a Sudoku puzzle.
- `output.txt`: An example output file containing the solved Sudoku puzzle.