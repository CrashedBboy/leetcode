#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        vector<int> directions = {-1, 0, 1, 0, -1};
        
        stack<pair<int, int>> s;
        queue<pair<int, int>> q;
        bool labeled = false;
        for (int r = 0; r < grid.size(); r++) {
            if (labeled) break;
            for (int c = 0; c < grid[0].size(); c++) {
                if (labeled) break;
                if (grid[r][c] == 1) {
                    s.push({r, c});

                    while (!s.empty()) {
                        auto [row, col] = s.top(); s.pop();

                        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;

                        if (grid[row][col] == 1) {
                            q.push({row, col}); // records the 2-island's positions in the meanwhile
                            grid[row][col] = 2;

                            for (int d = 0; d < 4; d++) {
                                s.push({row + directions[d], col + directions[d+1]});
                            }
                        }
                    }

                    labeled = true;
                }
            }
        }


        int level = 0;
        while (!q.empty()) {
            int num = q.size();

            while (num--) {
                auto [row, col] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int r = row + directions[d];
                    int c = col + directions[d+1];

                    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) continue;

                    if (grid[r][c] == 1) {
                        return level;
                    }
                    else if (grid[r][c] == 2) {
                        continue;
                    }
                    grid[r][c] = 2;
                    q.push({r, c});
                }
            }

            level += 1;
        }

        return -1;
    }
};