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
// dynamic programming: recursion with mormoization

class Solution {

private:

    unordered_map<int, vector<vector<int>>> appendMem;
    unordered_map<int, vector<vector<int>>> appendNoMem;

    vector<vector<int>> appendNumber(vector<int>& nums, int index, bool append) {

        if (append == true && appendMem.count(index) > 0) {
            return appendMem[index];
        }

        if (append == false && appendNoMem.count(index) > 0) {
            return appendNoMem[index];
        }

        vector<vector<int>> result;

        if (index == nums.size() - 1) {

            vector<int> list;

            if (append) {
                list.push_back(nums[index]);
            }

            result.push_back(list);

        } else {

            vector<vector<int>> appendNext = appendNumber(nums, index + 1, true);

            vector<vector<int>> appendNoNext = appendNumber(nums, index + 1, false);

            for (int i = 0; i < appendNext.size(); i++) {

                if (append) {

                    appendNext[i].push_back(nums[index]);
                    appendNoNext[i].push_back(nums[index]);
                }

                result.push_back(appendNext[i]);
                result.push_back(appendNoNext[i]);
            }
        }

        if (append) {

            appendMem[index] = result;

        } else {

            appendNoMem[index] = result;
        }

        return result;
    }

public:

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;

        if (nums.empty()) {

            vector<int> emptyList;
            result.push_back(emptyList);

            return result;

        } else {

            vector<vector<int>> appendNext = appendNumber(nums, 0, true);
            vector<vector<int>> appendNoNext = appendNumber(nums, 0, false);

            for (int i = 0; i < appendNext.size(); i++) {

                result.push_back(appendNext[i]);
                result.push_back(appendNoNext[i]);
            }
        }

        return result;
    }
};