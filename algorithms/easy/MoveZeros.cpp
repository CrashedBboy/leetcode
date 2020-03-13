// Source : https://leetcode.com/problems/move-zeroes/
// Author : CrashedBboy
// Date   : 2020-03-13

// Questions
/********************************************************************************** 

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.

**********************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;

        // iterate the list to get 0’s count and remove all the zeros
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {

            if (*it == 0) {

                zeroCount += 1;

                nums.erase(it);
                it--;
            }
        }

        // then append those removed 0 at the end of list
        for (int i = 0; i < zeroCount; i++) {
            nums.push_back(0);
        }
    }
};