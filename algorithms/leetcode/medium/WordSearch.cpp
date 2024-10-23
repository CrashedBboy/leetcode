// idea:
// iterate the board from left to right, from top to bottom
// while it encounters the first letter of target word, start searching

// searching:
// use DFS, starting from the first letter's position, 
// iterately looking for next matched among its neighbors


#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        // iterate the board to find the starting letter of word
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {
                    // start DFS
                    if (dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

public:
    bool dfs(vector<vector<char>>& board, int row, int col, string word, int wordIdx) {

        if (wordIdx == word.size()) {
            return true;
        }

        // boundry & target letter check
        if (row >= board.size() || col >= board[0].size() || board[row][col] != word[wordIdx]) {
            return false;
        }

        // check passed, now search for the next letter on neighborhood

        // mark the current grid as '#' to prevent being visited again
        char original = board[row][col];
        board[row][col] = '#';

        // do the next DFS
        bool res = false;
        res = dfs(board, row + 1, col, word, wordIdx + 1)
            || dfs(board, row - 1, col, word, wordIdx + 1)
            || dfs(board, row, col + 1, word, wordIdx + 1)
            || dfs(board, row, col - 1, word, wordIdx + 1);

        // restore the original value for the grid
        board[row][col] = original;

        return res;
    }
};


int main() {

    vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'} };
    // string word = "ABCCED";
    // string word = "ASADFBCCEESE";
    string word = "ABFZ";

    Solution sol;

    cout << sol.exist(board, word) << endl;

    return 0;
}