#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int count = 0;

        stack<pair<int, int>> dfs;

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = i+1; j < isConnected[0].size(); j++) {
                if (isConnected[i][j]) {
                    // start dfs
                    count += 1;
                    dfs.push({i,j});
                    isConnected[i][j] = 0;
                    while (!dfs.empty()) {
                        auto& [from, to] = dfs.top(); dfs.pop();
                        for (int t = to+1; t < isConnected[to].size(); t++) {
                            if (isConnected[to][t]) {
                                isConnected[to][t] = 0;
                                dfs.push({to,t});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};

int main() {

    return 0;
}