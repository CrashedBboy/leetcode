// [idea]
// observation: if the sum of whole array is odd -> it's not possible to be partitioned
// smaller question: find an subset which has sum equal to half of total sum

// reference:
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        if (nums.size() == 1) {
            return false;
        }

        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        if (total%2 != 0) {
            return false;
        }

        int targetSum = total/2;

        // dp[position][sum]
        vector<vector<bool>> dp (nums.size()+1, vector<bool> (targetSum+1, false));

        // base cases (dp[0][___] means picking nothing)
        for (int i = 0; i < nums.size() + 1; i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j < targetSum + 1; j++) {
            dp[0][j] = false;
        }
        

        for (int position = 1; position <= nums.size(); position++) {
            for (int sum = 1; sum <= targetSum; sum++) {

                if (nums[position-1] <= sum) {
                    dp[position][sum] = dp[position-1][sum] || dp[position-1][sum - nums[position-1]];
                } else {
                    dp[position][sum] = dp[position-1][sum];
                }
            }
        }

        return dp[nums.size()][targetSum];
    }
};