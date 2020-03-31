// Source : https://leetcode.com/problems/maximum-subarray/
// Author : CrashedBboy
// Date   : 2020-03-30

// Questions
/********************************************************************************** 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

**********************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // iterate through the list only once -- O(1)
        // comparing if the current iterated element N > N + local subarray sum,
        // and update the global subarray sum if the max(N, N+local sum) > global subarray sum
        
        int size = nums.size();
        if (size == 0) {
            return std::numeric_limits<int>::min();
        }

        // start from the first element
        int globalSum = nums[0];
        int localSum = nums[0];

        for (int i = 1; i < size; i++) {

            localSum = std::max(nums[i], nums[i] + localSum);

            if (localSum > globalSum) {

                globalSum = localSum;
            }
        }

        return globalSum;
    }
};