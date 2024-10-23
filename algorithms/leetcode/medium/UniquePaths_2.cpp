// Source : https://leetcode.com/problems/unique-paths/
// Author : CrashedBboy
// Date   : 2020-04-29

// Questions
/********************************************************************************** 

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the 
diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in 
the diagram below).

How many possible unique paths are there?

[image] https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
Above is a 7 x 3 grid. How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
 
Constraints:

* 1 <= m, n <= 100
* It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

**********************************************************************************/

// [idea]
// dynamic programming, using iteration

// the answer <= 2e9 (approximately integer limit), so we can use int to store result

class Solution {

public:
    int uniquePaths(int m, int n) {

        if (m <= 0 || n <= 0) {
            return 0;
        }

        vector<vector<int>> pathNumber (m, vector<int>(n));

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (i == 0 || j == 0) {

                    pathNumber[i][j] = 1;
                
                } else {

                    pathNumber[i][j] = pathNumber[i-1][j] + pathNumber[i][j-1];
                }
            }
        }

        return pathNumber[m-1][n-1];
    }
};