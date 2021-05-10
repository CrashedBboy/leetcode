#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> valueIndex;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (valueIndex[complement] != 0) {
                vector<int> ans = { i, valueIndex[complement] - 1 };
                return ans;
            }

            valueIndex[nums[i]] = (i + 1);
        }

        return vector<int>();
    }
};

int main() {

    vector<int> nums = { 3,3 };
    int target = 6;

    Solution sol;

    vector<int> ans = sol.twoSum(nums, target);

    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}