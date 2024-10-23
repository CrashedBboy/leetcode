#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp (matrix.size()+1, vector<int>(matrix[0].size()+1, 0));

        int maxSquare = 0;

        // init
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == '1') {
                    dp[row+1][col+1] = 1;

                    maxSquare = 1;
                }
            }
        }

        // dp (bottom-up)
        
        for (int row = 1; row <= matrix.size(); row++) {
            for (int col = 1; col <= matrix[0].size(); col++) {

                if (dp[row][col] > 0) {
                    if (dp[row-1][col] > 0 && dp[row][col-1] > 0 && dp[row-1][col-1] > 0) {
                        int minSquare = min(min(dp[row-1][col], dp[row][col-1]), dp[row-1][col-1]);
                        dp[row][col] = pow(sqrt((double)minSquare)+1, 2);

                        maxSquare = max(maxSquare, dp[row][col]);
                    }
                }
                
                cout << dp[row][col] << ",";
            }
            cout << endl;
        }

        return maxSquare;
    }
};

int main () {

    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
    //                                 {'1', '0', '1', '1', '1'},
    //                                 {'1', '1', '1', '1', '1'},
    //                                 {'1', '0', '0', '1', '0'}};
    // vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
    vector<vector<char>> matrix = {{'1', '1', '1', '1', '0'},
                                    {'1', '1', '1', '1', '0'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'0', '0', '1', '1', '1'}};
    
    Solution sol;
    int answer = sol.maximalSquare(matrix);

    cout << "max sqr: " << answer << endl;

    return 0;
}