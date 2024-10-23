#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Sudoku;

bool valid(Sudoku& inputs, int row, int col) {
    // check on its row
    for (int c = 0; c < 9; c++) {
        if (c != col && inputs[row][c] == inputs[row][col]) {
            return false;
        }
    }

    // check on its rol
    for (int r = 0; r < 9; r++) {
        if (r != row && inputs[r][col] == inputs[row][col]) {
            return false;
        }
    }

    // check on its square
    int squareRow = row / 3;
    int squareCol = col / 3;

    for (int r = 0; r < 3; r ++) {
        for (int c = 0; c < 3; c++) {
            int gridRow = 3*squareRow + r;
            int gridCol = 3*squareCol + c;
            if (gridRow != row && gridCol != col && inputs[gridRow][gridCol] == inputs[row][col]) {
                return false;
            }
        }
    } 

    return true;
}

bool solve(Sudoku& inputs, int row, int col) {

    // boundry: if we reach the end of row
    if (row < 9 && col == 9) {
        return solve(inputs, row + 1, 0); // switch to new row
    }

    // boundry: if we reach the end of the whole
    if (row == 9) {
        return true;
    }

    if (inputs[row][col] > 0) {
        return solve(inputs, row, col + 1);
    }

    // make decision -> validate it with constraints -> (if false) undo and make another choice
    // all decision we can make: number 1 - 9
    for (int i = 1; i <= 9; i++) {

        // try to make a decision
        inputs[row][col] = i;

        if (valid(inputs, row, col)) {
            // if the choice matches the constraint, keep doing the next choice

            if (solve(inputs, row, col+1) == true) {
                return true;
            }
        }
    }

    // if all tries does not match the constraint, undo it, return false
    inputs[row][col] = 0;
    return false;
}

int main () {

    Sudoku inputs = {{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};

    bool res = solve(inputs, 0, 0);

    if (res) {
        for (auto& row : inputs) {
            for (auto& item : row) {
                cout << item << ",";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution available." << endl;
    }

    return 0;
}