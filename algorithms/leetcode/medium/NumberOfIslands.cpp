// Source : https://leetcode.com/problems/number-of-islands/
// Author : CrashedBboy
// Date   : 2020-12-02

// Questions
/********************************************************************************** 
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally 
or vertically. You may assume all four edges of the grid are all surrounded by water. 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 300
* grid[i][j] is '0' or '1'.


**********************************************************************************/

// Idea
/********************************************************************************** 

Total m rows x n columns.

Using BFS and a matrix 'visited'

loop rows:
  loop columns:
    if not visited & not zero:
      BFS

BFS:
  if current node is not zero:
    add four directions' neighbors into queue

**********************************************************************************/
#include <vector>
#include <utility>
#include <queue>

class Solution {

private:
    int islandCount = 0;
    vector<vector<bool>> visited;

    bool checkBoundary(vector<vector<char>>& grid, int row, int col) {

        if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) {
            return false;
        } else {
            return true;
        }
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {

        queue<pair<int, int>> bfsQueue;

        visited[row][col] = true;
        bfsQueue.push(pair<int, int>(row, col));

        while (!bfsQueue.empty()) {
            pair<int, int> currentNode = bfsQueue.front();

            int r = currentNode.first;
            int c = currentNode.second;

            if (grid[r][c] != '0') {

                if (checkBoundary(grid, r + 1, c) && !visited[r + 1][c]) {
                    visited[r + 1][c] = true;
                    bfsQueue.push(pair<int, int>(r + 1, c));
                }

                if (checkBoundary(grid, r - 1, c) && !visited[r - 1][c]) {
                    visited[r - 1][c] = true;
                    bfsQueue.push(pair<int, int>(r - 1, c));
                }

                if (checkBoundary(grid, r, c + 1) && !visited[r][c + 1]) {
                    visited[r][c + 1] = true;
                    bfsQueue.push(pair<int, int>(r, c + 1));
                }

                if (checkBoundary(grid, r, c - 1) && !visited[r][c - 1]) {
                    visited[r][c - 1] = true;
                    bfsQueue.push(pair<int, int>(r, c - 1));
                }
            }

            bfsQueue.pop();
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.size() == 0) {
            return 0;
        }

        // initialize visited matrix
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] != '0' && visited[row][col] == false) {
                    islandCount += 1;

                    // do BFS
                    bfs(grid, row, col);
                }
            }
        }

        return islandCount;
    }
};

