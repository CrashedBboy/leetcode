#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> disappeared;

        for (int i = 0; i < nums.size(); i++) {

            while (nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                disappeared.push_back(i+1);
            }
        }

        return disappeared;
    }
};



int main() {

    // vector<int> inputs = { 4,3,2,7,8,2,3,1 };
    vector<int> inputs = { 1,1 };

    Solution sol;

    vector<int> disappeared = sol.findDisappearedNumbers(inputs);
    for (auto& n : disappeared) {
        cout << n << ",";
    }

    return 0;
}