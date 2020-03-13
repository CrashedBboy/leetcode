// Source : https://leetcode.com/problems/majority-element/
// Author : CrashedBboy
// Date   : 2020-03-13

// Questions
/********************************************************************************** 

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

**********************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // in-place solution:
        // sort the list first, then iterate the list to count amount each values,
        // if a value’s count is bigger than n/2, return that value.

        // sort the list
        std::sort(nums.begin(), nums.end());

        vector<int>::iterator it = nums.begin();

        int previousValue = *it/2 + 1; // make the initial value different from the first element in the list
        int valueCount = 0;

        // iterate the list to count
        for (; it != nums.end(); it++) {

            if (*it == previousValue) {
          
                valueCount += 1;

                // when criterion of 'majority element' meets
                if (valueCount * 2 > nums.size()) {
                    return *it;          
                }

            } else {
                previousValue = *it;
                valueCount = 1;
            }
        }

        return previousValue;
        
    }
};