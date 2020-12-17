// Source : https://leetcode.com/problems/perfect-squares/
// Author : CrashedBboy
// Date   : 2020-12-17

// Questions
/**************************************************************************************** 
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 

Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2

Explanation: 13 = 4 + 9.

******************************************************************************************/

#include <cmath>
#include <vector> 
#include <algorithm>

class Solution1 {

private:

    int compute(vector<int>& perfect_squares, int current_using, int remained, vector<vector<int>>& memo) {

        if (current_using == 0) {
            return remained;
        }

        if (memo[current_using][remained] != -1) {
            return memo[current_using][remained];
        }

        int min_squares = remained;

        int current_square = perfect_squares[current_using];

        for (int c = 0; c <= (int)(remained/current_square); c++) {
            min_squares = min( c + compute(perfect_squares, current_using-1, remained - c * current_square, memo), min_squares);
        }

        memo[current_using][remained] = min_squares;

        return min_squares;
    }

public:
    int numSquares(int n) {
        
        // check whether itself is a perfect square
        int root = (int)sqrt(n);

        if ((int)pow(root, 2) == n) {
            return 1;
        }

        // create list of perfect squares under n
        vector<int> perfect_squares(root, 1);

        for (int i = 1; i <= root; i++) {
            perfect_squares[i-1] = i * i;
        }

        // create memo array

        vector<vector<int>> memo(root + 1, vector<int>(n+1, -1));

        // do DP
        int squares = compute(perfect_squares, root - 1, n, memo);

        return squares;
    }
};


class Solution2 {

public:
    int numSquares(int n) {

        if (n == 0) { return 0; }

        vector<int> perfect_square_num = {0};

        for (int i = 1; i <= n; i++) {

            int square_number = INT_MAX;

            for (int c = 1; c * c <= i; c++) {

                square_number = min( square_number, perfect_square_num[i - c*c] + 1 );
            }

            perfect_square_num.push_back(square_number);
        }

        return perfect_square_num[n];
    }
};