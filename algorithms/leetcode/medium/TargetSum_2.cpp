// Source : https://leetcode.com/problems/target-sum/
// Author : CrashedBboy
// Date   : 2020-11-24

// Questions
/********************************************************************************** 
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

* The length of the given array is positive and will not exceed 20.
* The sum of elements in the given array will not exceed 1000.
* Your output answer is guaranteed to be fitted in a 32-bit integer.
**********************************************************************************/
/*

Idea: DP with memoization

Note: Because the summing result can be negative, but we cannot use negative number as vector index,
so we padding the index by adding length of nums (shift N)


*/

#include <vector>
#include <numeric>

class Solution {

private:

    int sum = 0;

    int _findTargetSumWays(vector<int>& nums, vector<vector<int>>& memo, int currentIndex, int currentSum, int S) {

        if (memo[currentIndex][currentSum + sum] != -1) {
            return memo[currentIndex][currentSum + sum];
        }

        // boundary return
        if (currentIndex == nums.size()) {

            if (currentSum == S) {
                memo[currentIndex][currentSum + sum] = 1;
            } else {
                memo[currentIndex][currentSum + sum] = 0;
            }
        
        } else {

            // DP
            int addSolutionNum = _findTargetSumWays(nums, memo, currentIndex + 1, currentSum+nums[currentIndex], S);
            int subtractSolutionNum = _findTargetSumWays(nums, memo, currentIndex + 1, currentSum-nums[currentIndex], S);

            // memoization
            memo[currentIndex][currentSum + sum] = addSolutionNum + subtractSolutionNum;
        }

        return memo[currentIndex][currentSum + sum];
    }

public:

    int findTargetSumWays(vector<int>& nums, int S) {

        sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> memo (nums.size()+1, vector<int>(sum * 2 + 1, -1));
        
        return _findTargetSumWays(nums, memo, 0, 0, S);
    }
};