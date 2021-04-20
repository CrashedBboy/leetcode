#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ROW_LEN 10

// convert seat character to column number
static int getColNumber(char seat) {
    unordered_map<char, int> mapping;
    mapping['A'] = 0; mapping['B'] = 1; mapping['C'] = 2; mapping['D'] = 3;
    mapping['E'] = 4; mapping['F'] = 5; mapping['G'] = 6; mapping['H'] = 7;
    mapping['J'] = 8; mapping['K'] = 9;
    return mapping[seat];
}

// given start of seat position, return whether 4-person family can fit into 
int canFit(vector<vector<bool>>& seats, int row, int col) {

    // check for occupation
    if (!seats[row][col] && !seats[row][col+1] && !seats[row][col+2] && !seats[row][col+3]) {

        // check for asile
        if (col == 1 || col == 3 || col == 5) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int solution(int N, string &S) {

    // construct 2D matrix (seat map)
    vector<vector<bool>> seats (N, vector<bool>(ROW_LEN, false));

    // parse occupied seats
    if (S.size() > 0) {
        int row = -1, col = -1; // use -1 to denote that the row/col are not parsed yet
        for (auto& c: S) {
            if (c == ' ') {
                seats[row][col] = true; // set the seat as occupied
                row = -1; col = -1; // reset
                continue;
            }
            if (row == -1) {
                row = c - '1';
            }
            else {
                col = getColNumber(c);
            }
        }
        seats[row][col] = true; // the latest parsed
    }

    // utilize dynamic programming to get maximum family counts per row
    // dp[row][col]: in this row, max number of family can be fit into col~end
    vector<vector<int>> dp (N, vector<int>(ROW_LEN, 0));

    // for every row
    for (int r = 0; r < N; r++) {

        // for column from 6 -> 0
        for (int c = (ROW_LEN-4); c >= 0; c--) {

            int available = canFit(seats, r, c); // 1 or 0

            int previousCount = (c+4) >= ROW_LEN? 0 : dp[r][c+4];

            // transition rule of bottom-up dp
            dp[r][c] = max(
                available + previousCount,
                max(max(dp[r][c+1], dp[r][c+2]), dp[r][c+3])
            );
        }
    }

    int total_family = 0;
    for (int r = 0; r < N; r++) {
        total_family += dp[r][0];
    }

    return total_family;
}
