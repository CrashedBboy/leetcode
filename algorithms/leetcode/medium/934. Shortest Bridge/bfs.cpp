#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int shortest = grid.size();

        // mark one of the island by 2
        stack<int> dfsStackR;
        stack<int> dfsStackC;
        bool labeled = false;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid.size(); c++) {
                if (grid[r][c] == 1 && !labeled) {
                    dfsStackR.push(r);
                    dfsStackC.push(c);

                    while (!dfsStackR.empty()) {
                        int row = dfsStackR.top(); dfsStackR.pop();
                        int col = dfsStackC.top(); dfsStackC.pop();

                        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;

                        if (grid[row][col] != 1) continue;

                        grid[row][col] = 2;

                        dfsStackR.push(row+1); dfsStackC.push(col);
                        dfsStackR.push(row-1); dfsStackC.push(col);
                        dfsStackR.push(row); dfsStackC.push(col+1);
                        dfsStackR.push(row); dfsStackC.push(col-1);
                    }

                    labeled = true;
                }
            }
        }

        // then do BFS to find the shortest way to another island
        // keep expand the 2nd island untill it reaches the 1st island

        for (int i = 2; ; i++) {
            for (int r = 0; r < grid.size(); r++) {
                for (int c = 0; c < grid[0].size(); c++) {
                    if (grid[r][c] == i) {
                        // expand
                        if (expandOrReach(grid, i+1, r+1, c) || expandOrReach(grid, i+1, r-1, c)
                                || expandOrReach(grid, i+1, r, c+1) || expandOrReach(grid, i+1, r, c-1)) {

                            return (i - 2);
                        }
                    }
                }
            }
        }
        

        return shortest;
    }

private:
    bool expandOrReach(vector<vector<int>>& grid, int i, int r, int c) {

        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        }

        if (grid[r][c] == 1) {
            return true;
        }

        if (grid[r][c] == 0) {
            grid[r][c] = i;
        }
        return false;
    }
};