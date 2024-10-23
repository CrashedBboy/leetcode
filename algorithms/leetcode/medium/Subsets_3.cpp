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
// bit manipulation

// for example:
// [1, 2, 3, 4] -> N = 4, there're 2^4 = 16 subsets

// => combinations from 0b0000 ~ 0b1111 (0b10000 - 1)
// => see every bit as element in list: 1 represents putting in subset, 0 means not putting in

class Solution {

private:

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> results;
        
        int subset_number = (int)pow(2, nums.size());
        for (int s = 0; s < subset_number; s++) {

            int subset_bits = s;
            vector<int> subset;
            for (int bit = 0; bit < nums.size(); bit++) {

                if (subset_bits & 1) {
                    subset.push_back(nums[bit]);
                }

                subset_bits = subset_bits >> 1;
            }

            results.push_back(subset);
        }

        return results;
    }
};