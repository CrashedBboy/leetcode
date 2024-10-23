#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // build graph
        buildDirectedGraph(numCourses, prerequisites);

        queue<int> bfsQueue;
        int visited = 0;

        // first push node with indegree = 0 into queue
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                bfsQueue.push(i);
            }
        }

        // start BFS
        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            visited += 1;

            for (int j = 0; j < numCourses; j++) {
                if (courseGraph[current][j]) {
                    indegrees[j] -= 1;
                    if (indegrees[j] == 0) {
                        bfsQueue.push(j);
                    }
                }
            }

            bfsQueue.pop();
        }

        if (visited == numCourses) {
            return true;
        }
        else {
            return false;
        }
    }

private:

    typedef vector<vector<bool>> graph;
    
    graph courseGraph;
    vector<int> indegrees;

    void buildDirectedGraph (int numCourses, vector<vector<int>>& prerequisites) {

        // init
        courseGraph = graph (numCourses, vector<bool> (numCourses, false));
        indegrees = vector<int> (numCourses, 0);

        for (auto& p : prerequisites) {
            int from = p[1];
            int to = p[0];

            courseGraph[from][to] = true;
            indegrees[to] += 1;
        }
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