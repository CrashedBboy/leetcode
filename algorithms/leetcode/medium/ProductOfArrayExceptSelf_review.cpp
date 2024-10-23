// Source : https://leetcode.com/problems/product-of-array-except-self/
// Author : CrashedBboy
// Date   : 2020-11-27

// Question
/*********************************************************************************************

Given an array nums of n integers where n > 1,
return an array output such that output[i] is equal to the product of all the elements of nums 
except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array 
(including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)


********************************************************************************************/

#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);

        int forwardProduct = 1;
        int backwardProduct = 1;
        for (int i = 0; i < nums.size(); i++) {

            forward[i] = forwardProduct;
            forwardProduct *= nums[i];

            backward[nums.size() - 1 - i] = backwardProduct;
            backwardProduct *= nums[nums.size() - 1 - i];
        }

        vector<int> output(nums.size());
        for (int i = 0; i < output.size(); i++) {

            output[i] = forward[i] * backward[i];
        }

        return output;
    }
};

// O(1) space complexity
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size(), 1);

        int forwardProduct = 1;
        int backwardProduct = 1;
        for (int i = 0; i < nums.size(); i++) {

            // forward
            output[i] *= forwardProduct;
            forwardProduct *= nums[i];

            // backward
            output[nums.size() - 1 - i] *= backwardProduct;
            backwardProduct *= nums[nums.size() - 1 - i];
        }

        return output;
    }
};