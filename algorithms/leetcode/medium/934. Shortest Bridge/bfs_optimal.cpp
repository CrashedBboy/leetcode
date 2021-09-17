#include <vector>
#include <utility>
#include <stack>
#include <queue>

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

        cout << "DFS" << endl;

        int level = -1;
        while (!q.empty()) {
            int num = q.size();

            while (num--) {
                auto [row, col] = q.front(); q.pop();

                if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;

                if (grid[row][col] == 1) {
                    cout << row << " " << col << endl;
                    return level;
                }
                else if (grid[row][col] == 0) {
                    q.push({row, col});
                    grid[row][col] = 2;

                    for (int d = 0; d < 4; d++) {
                        q.push({row + directions[d], col + directions[d+1]});
                    }
                }
            }

            level += 1;
        }

        return -1;
    }
};