#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int shortest = grid.size();

        // mark the first island by -1, the second island by -2
        int islandId = -1;
        stack<int> dfsStackR;
        stack<int> dfsStackC;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid.size(); c++) {
                if (grid[r][c] == 1) {
                    dfsStackR.push(r);
                    dfsStackC.push(c);

                    while (!dfsStackR.empty()) {
                        int row = dfsStackR.top(); dfsStackR.pop();
                        int col = dfsStackC.top(); dfsStackC.pop();

                        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;

                        if (grid[row][col] != 1) continue;

                        grid[row][col] = islandId;
                        dfsStackR.push(row+1); dfsStackC.push(col);
                        dfsStackR.push(row-1); dfsStackC.push(col);
                        dfsStackR.push(row); dfsStackC.push(col+1);
                        dfsStackR.push(row); dfsStackC.push(col-1);
                    }

                    islandId += 1;
                }
            }
        }

        // then do BFS to find the shortest way to another island

        return shortest;
    }
};