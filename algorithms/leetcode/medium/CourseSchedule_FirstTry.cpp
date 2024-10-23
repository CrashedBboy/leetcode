#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // build directed graph from prerequisities
        vector<vector<bool>> courseGraph (numCourses, vector<bool>(numCourses, false) );

        if (prerequisites.size() == 0) {
            return true;
        }
        else {
            for (auto& p : prerequisites) {
                int to = p[0];
                int from = p[1];
                courseGraph[from][to] = true;
            }
        }

        // check for cycle
        // for each node, strat from it and perform DFS to check whether the traversal path will direct to itself
        vector<int> visited (numCourses, false);
        for (int i = 0; i < numCourses; i++) {

            queue<int> bfsQueue;
            bfsQueue.push(i);

            while (!bfsQueue.empty()) {
                int current = bfsQueue.front();
                visited[current] = true;

                // if the node has link to the source, cycle exists!
                if (courseGraph[current][i] == true) {
                    return false;
                }
                else {
                    // keep adding un-visited neighbor into bfs queue
                    for (int j = 0; j < numCourses; j++) {
                        if (courseGraph[current][j] && !visited[j]) {
                            bfsQueue.push(j);
                        }
                    }
                }

                bfsQueue.pop();
            }

            // reset visited
            for (int j = 0; j < visited.size(); j++) {
                visited[j] = false;
            }
        }

        return true;
    }
};

int main () {

    int numCourses = 2;

    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

    Solution s;
    bool res = s.canFinish(numCourses, prerequisites);

    cout << "Can finished?" << res << endl;

    return 0;
}