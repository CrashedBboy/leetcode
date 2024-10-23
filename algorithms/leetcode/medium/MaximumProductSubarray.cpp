#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.empty()) {
            return 0;
        }

        int ans = nums[0];

        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] < 0) {
                swap(currentMax, currentMin);
            }

            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);

            if (currentMax > ans) {
                ans = currentMax;
            }
        }

        return ans;
    }
};

int main () {

    vector<int> nums = {2, 3, -2, 4};

    Solution sol;

    cout << sol.maxProduct(nums) << endl;

    return 0;
}