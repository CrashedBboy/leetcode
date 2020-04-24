// Source : https://leetcode.com/problems/combination-sum/
// Author : CrashedBboy
// Date   : 2020-04-24

// Questions
/********************************************************************************** 
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

**********************************************************************************/

// [idea]
// backtracking with recursion

// recursion: current element index(add it into set or not), current set, remained target(sum)

class Solution {

private:
    void combine(vector<int>& candidates, int index, vector<int>& currentCombination, int remainedSum, vector<vector<int>>& results) {

        // conditions of stopping
        //// index reachs the end
        //// remainedSum < 0

        if (remainedSum < 0) {
            return;
        }

        if (index == candidates.size()) {

            if (remainedSum == 0) {
                results.push_back(currentCombination);
            }

            return;
        }

        // not add candidates[index] into set
        combine(candidates, index + 1, currentCombination, remainedSum, results);

        // add candidates[index] into set
        currentCombination.push_back(candidates[index]);
        remainedSum -= candidates[index];
        combine(candidates, index, currentCombination, remainedSum, results);

        // reset
        currentCombination.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> currentCombination;

        combine(candidates, 0, currentCombination, target, results);

        return results;
    }
};