#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // DP: nums[i]: max sum of subarray which ends at i-th element
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);

            if (nums[i] > maxSum) {
                maxSum = nums[i];
            }
        }

        return maxSum;
    }
};

int main() {

    // vector<int> inputs = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> inputs = { 5,4,-1,7,8 };

    Solution sol;

    cout << sol.maxSubArray(inputs) << endl;

    return 0;
}