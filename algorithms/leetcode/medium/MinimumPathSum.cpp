// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : CrashedBboy
// Date   : 2020-04-28

// Questions
/********************************************************************************** 

Given a m x n grid filled with non-negative numbers, find a path from top left to 
bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

Output: 7

Explanation: Because the path 1→3→1→1→1 minimizes the sum.

**********************************************************************************/

// [idea]
// using dynamic programing with memoization
// minSum(p) = min(minSum(p go right), minSum(p go down))

class Solution {

private:

    int pathSum(vector<vector<int>>& grid, int row, int column, vector<vector<int>>& memoization) {

        // memoization
        if (memoization[row][column] != -1) {
            return memoization[row][column];
        }

        int sum;

        if (row == grid.size() - 1 && column == grid[row].size() - 1) {

            sum = grid[row][column];
        
        } else if (row == grid.size() - 1) {

            sum = grid[row][column] + pathSum(grid, row, column + 1, memoization);
        
        } else if (column == grid[row].size() - 1) {

            sum = grid[row][column] + pathSum(grid, row + 1, column, memoization);
        
        } else {

            // DP
            sum = grid[row][column] + 
                min(pathSum(grid, row + 1, column, memoization), pathSum(grid, row, column + 1, memoization));
        }

        memoization[row][column] = sum;

        return sum;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {

        if (grid.empty()) {

            return 0;
        }
        
        vector<vector<int>> memoization (grid.size(), vector<int>(grid[0].size(), -1));

        return pathSum(grid, 0, 0, memoization);
    }
};