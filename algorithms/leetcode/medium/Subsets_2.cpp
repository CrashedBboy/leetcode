// Source : https://leetcode.com/problems/subsets/
// Author : CrashedBboy
// Date   : 2020-04-221

// Questions
/********************************************************************************** 
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

**********************************************************************************/

// [idea]
// recursion & backtracking (top-down)

class Solution {

private:

    void generate_subsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& results) {

        if (index == nums.size()) {

            results.push_back(subset);
            return;
        }

        // without adding nums[index]
        generate_subsets(nums, index + 1, subset, results);

        // adding nums[index]
        subset.push_back(nums[index]);
        generate_subsets(nums, index + 1, subset, results);
        subset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> results;

        vector<int> subset;

        generate_subsets(nums, 0, subset, results);

        return results;
    }
};