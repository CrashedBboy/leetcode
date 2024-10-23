#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int N = max(n, 2);

        vector<int> dp (N, 0);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n-1];
    }
};

int main () {

    Solution sol;

    int n = 3;

    cout << sol.climbStairs(n) << endl;

    return 0;
}