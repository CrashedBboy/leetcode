// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : CrashedBboy
// Date   : 2020-04-20

// Questions
/********************************************************************************** 
Given an array nums of n integers where n > 1,
return an array output such that output[i] is equal to the product of all the elements 
of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of 
the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)

**********************************************************************************/

// [idea]
// iterate the list from start to end and from end to start

// when iteration reachs element K, do cumululative product A = A' * K,
// but store A' to results[K] (without itself)
// A' = cumulative product of previous numbers

// but if we iterate through one direction, we cannot get the cumulative product of numbers behind K
// so we have to iterate again from opposite direction

// when there's only one zero in array, mark the rest of elements behind zero as 0

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // initialize all results to be 1
        vector<int> results(nums.size(), 0);

        // 1st iteration
        int cumulative = 1;
        for (int i = 0; i < nums.size(); i++) {

            results[i] = cumulative;

            if (nums[i] != 0) {

                cumulative = cumulative * nums[i];
            
            } else {

                // the rest results will always be zero
                break;
            }
            
        }

        // 2nd iteration
        cumulative = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {

            results[i] = results[i] * cumulative;

            if (nums[i] != 0) {

                cumulative = cumulative * nums[i];
            
            } else {

                // the rest results will always be zero
                for (int j = i - 1; j >=0; j--) {

                    results[j] = 0;
                }

                break;
            }
        }

        return results;
    }
};