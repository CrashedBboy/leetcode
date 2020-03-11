// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : CrashedBboy
// Date   : 2020-03-11

// Questions
/********************************************************************************** 
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

**********************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // sort the list first, let all the element arranged in order.
        // then iterate the list from begin to the end, compare each element to its previous neighbor to find the single.

        // sorting: time complexity is O(nlogn)
        std::sort(nums.begin(), nums.end());

        // iterate the list to find the single one
        int accmulated_singles = 0; // how many visited element has not been matched
        double last_single_value = std::numeric_limits<double>::max(); // last single element's value in the iteration
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {

            if (accmulated_singles == 0) {
                accmulated_singles += 1;
            } else if (last_single_value == *it) {
                accmulated_singles = 0;
            } else {
                return last_single_value;
            }

            last_single_value = *it;
        }

        // the single one might be in the end of list
        return last_single_value;
    }
};