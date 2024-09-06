#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check row, column, and 3x3 box for conflicts
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    // Find an empty cell
    int row, col;
    bool foundEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) {
            break;
        }
    }

    // If no empty cell found, the puzzle is solved
    if (!foundEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursively solve the puzzle with the new number placed
            if (solveSudoku(board)) {
                return true;
            }

            // If the recursive call didn't solve the puzzle, backtrack and try another number
            board[row][col] = 0;
        }
    }

    // If no number from 1 to 9 can be placed in the empty cell, the puzzle has no solution
    return false;
}

void printSudoku(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
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

    if (solveSudoku(board)) {
        cout << "Sudoku solved:\n";
        printSudoku(board);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}