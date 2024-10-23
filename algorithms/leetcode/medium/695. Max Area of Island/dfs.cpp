#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;
        stack<vector<int>> dfsStack;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    dfsStack.push({r,c});
                    int visited = 0;
                    while (!dfsStack.empty()) {
                        vector<int> rc = dfsStack.top(); dfsStack.pop();
                        int row = rc[0]; int col = rc[1];

                        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {continue;}

                        if (grid[row][col] == 0) { continue; }

                        grid[row][col] = 0;
                        visited += 1;

                        dfsStack.push({row-1, col});
                        dfsStack.push({row+1, col});
                        dfsStack.push({row, col-1});
                        dfsStack.push({row, col+1});
                    }

                    maxArea = visited > maxArea? visited : maxArea;
                }
            }
        }

        return maxArea;
    }
};

int main() { 
    vector<vector<int>> grid = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,0,1,1}, {0,0,0,1,1}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}