#include <iostream>
#include <vector>

using namespace std;

// idea: Dynamic programming

class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums);

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[nums.size() - 1];
    }
};

int main () {

    vector<int> inputs = {1,2,3,1};

    Solution sol;

    cout << sol.rob(inputs) << endl;

    return 0;
}