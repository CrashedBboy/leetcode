#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answers;
        backtrack(answers, 0, nums);
        return answers;
    }

private:
    void backtrack(vector<vector<int>>& answers, int i, vector<int>& nums) {
        if (i == nums.size()) {
            answers.push_back(nums);
        }
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                backtrack(answers, i + 1, nums);
                swap(nums[j], nums[i]);
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<vector<int>> answers = sol.permute(nums);
    for (auto& ans : answers) {
        for (auto& i : ans) {
            cout << i << ",";
        }
        cout << endl;
    }
    return 0;
}