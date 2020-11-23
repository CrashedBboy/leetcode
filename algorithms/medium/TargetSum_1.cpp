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

idea:

direction: dynamic programming


*/


class Solution {

private:

    int solutionCount = 0;

    void _findTargetSumWays(vector<int>& nums, int currentIndex, int currentSum, int S) {

        // boundary return
        if (currentIndex == nums.size()) {

            if (currentSum == S) {
                solutionCount += 1;
                return;
            } else {
                return;
            }
        }

        // DP
        _findTargetSumWays(nums, currentIndex + 1, currentSum+nums[currentIndex], S);
        _findTargetSumWays(nums, currentIndex + 1, currentSum-nums[currentIndex], S);
    }

public:

    int findTargetSumWays(vector<int>& nums, int S) {
        
        _findTargetSumWays(nums, 0, 0, S);

        return solutionCount;
    }
};