#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class BitMask {
public:
    BitMask(): mask(0) {}
    void set(int bit) {
        assert (bit > 0);
        this->mask = this->mask | (1 << bit);
    }
    void clear(int bit) {
        assert (bit > 0);
        this->mask = this->mask & (~(1 << bit));
    }
    bool get(int bit) {
        assert (bit > 0);
        return ( this->mask & (1 << bit) );
    }
private:
    uint16_t mask;
};

class Sudoku {
public:
    static bool solve(vector<vector<int>>& board) {
        // for each row/column/subgrid, it has a bitmask tracking what numbers have been used
        vector<BitMask> rowNumbers (9, BitMask());
        vector<BitMask> colNumbers (9, BitMask());
        vector<BitMask> subgridNumbers (9, BitMask());

        // initialize: scan the board first to know what numbers each row/col/subgrid has now
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != 0) {
                    int n = board[r][c];
                    rowNumbers[r].set(n);
                    colNumbers[c].set(n);
                    subgridNumbers[getGrid(r,c)].set(n);
                }
            }
        }

        bool solved = _solve(board, rowNumbers, colNumbers, subgridNumbers);
        if (solved) {
            cout << "solved:" << endl;
            printBoard(board);
        }
        return solved;
    }
    static void printBoard(vector<vector<int>>& board) {
        for (auto& row : board) {
            for (auto& number : row) {
                cout << number << ",";
            }
            cout << endl;
        }
    }
    static bool validateBoard(vector<vector<int>>& board) {
        // validate each rows
        for (int r = 0; r < 9; r++) {
            BitMask numbers;
            for (int c = 0; c < 9; c++) {
                int n = board[r][c];
                if (n != 0) {
                    if (n < 0 || n > 9 || numbers.get(n)) {
                        cout << n << endl;
                        return false;
                    }
                    numbers.set(n);
                }   
            }
        }

        // validate each cols
        for (int c = 0; c < 9; c++) {
            BitMask numbers;
            for (int r = 0; r < 9; r++) {
                int n = board[r][c];
                if (n != 0) {
                    if (n < 0 || n > 9 || numbers.get(n)) {
                        cout << n << endl;
                        return false;
                    }
                    numbers.set(n);
                }
            }
        }

        // validate each subgrids
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                BitMask numbers;
                for (int rr = r; rr < r+3; rr++) {
                    for (int cc = c; cc < c+3; cc++) {
                        int n = board[rr][cc];
                        if (n != 0) {
                            if (n < 0 || n > 9 || numbers.get(n)) {
                                cout << n << endl;
                                return false;
                            }
                            numbers.set(n);
                        }
                    }
                }
            }
        }

        return true;
    }
private:
    static int getGrid(int row, int col) {
        int r = row / 3;
        int c = col / 3;
        return r * 3 + c;
    }
    static bool isValidMove(int row, int col, int val, vector<BitMask>& rowN, vector<BitMask>& colN, vector<BitMask>& gridN) {
        if (rowN[row].get(val)) return false;
        if (colN[col].get(val)) return false;
        if (gridN[getGrid(row,col)].get(val)) return false;
        return true;
    }

    static bool _solve(vector<vector<int>>& board, vector<BitMask>& rowN, vector<BitMask>& colN, vector<BitMask>& gridN) {
        assert(board.size() == 9 && board[0].size() == 9);
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == 0) {
                    for (int i = 1; i <= 9; i++) {
                        if (isValidMove(r, c, i, rowN, colN, gridN)) {
                            // set
                            board[r][c] = i;
                            // if (!validateBoard(board)) {
                            //     cout << "error" << endl;
                            // }
                            rowN[r].set(i); colN[c].set(i); gridN[getGrid(r,c)].set(i);

                            if (_solve(board, rowN, colN, gridN)) { // try
                                return true;
                            }
                            else {
                                // reset (backtrack)
                                board[r][c] = 0;
                                rowN[r].clear(i); colN[c].clear(i); gridN[getGrid(r,c)].clear(i);
                            }
                        }
                    }
                    return false;
                }   
            }
        }
        return true;
    }


};

int main(void) {

    std::vector<std::vector<int>> board = {
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

    if (Sudoku::validateBoard(board)) {
        bool solved = Sudoku::solve(board);
    }
    else {
        cout << "Input data is invalid" << endl;
    }
    

    return 0;
}

/*

rows\cols   0 1 2 3 4 5 6 7 8
            1
            2
            3
            4
            5
            6
            7
            8

blocks
            0 1 2
            3 4 5
            6 7 8

*/