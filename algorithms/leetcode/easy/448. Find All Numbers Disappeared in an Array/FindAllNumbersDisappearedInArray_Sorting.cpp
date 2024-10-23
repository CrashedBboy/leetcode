#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int i = 0;
        vector<int> disappeared;
        for (int n = 1; n <= nums.size(); n++) {
            while (i < nums.size() && n > nums[i]) {
                i++;
            }

            if (i >= nums.size() || n != nums[i]) {
                disappeared.push_back(n);
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