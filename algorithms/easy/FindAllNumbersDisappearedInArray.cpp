// Source : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author : CrashedBboy
// Date   : 2020-03-16

// Questions
/********************************************************************************** 

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

**********************************************************************************/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        
        if (nums.empty()){
            return nums;
        }

        vector<int> result;

        // place every element nums[i] to position “nums[i] - 1” by swapping between position nums[i]-1 and i
        for (int num : nums){
            while (nums[num - 1] != num){
                swap(num, nums[num - 1]);
            }
        }

        // then iterate and check if nums[i] == i+1, if not, push i+1 to result vector
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};