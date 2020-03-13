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
        
        // iterate the list and using hash table to store each value’s count
        // if a value’s count exceeds n/2, return that value

        map<int, int> valueCount;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
  
            valueCount[*it] += 1;
            if (valueCount[*it] * 2 > nums.size()) {
    
                return *it;
            }
        }

        return 0;
    }
};