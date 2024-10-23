#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> rows;

        if (numRows <= 0) {
            return rows;
        }

        rows.push_back({1});

        for (int n = 1; n < numRows; n++) {
            vector<int> row (n+1, 1);

            vector<int> prevRow = rows[n-1];

            for (int i = 1; i < n; i++) {
                row[i] = prevRow[i-1] + prevRow[i];
            }

            rows.push_back(row);
        }

        return rows;
    }
};

int main () {

    int numRows = 2;

    Solution sol;

    vector<vector<int>> rows = sol.generate(numRows);

    for (auto& row : rows) {
        for (auto& n : row) {
            cout << n << ", ";
        }
        cout << endl;
    }

    return 0;
}