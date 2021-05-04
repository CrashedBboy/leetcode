// Source : https://leetcode.com/problems/two-sum/
// Author : CrashedBboy
// Date   : 2020-03-31

// Questions
/********************************************************************************** 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

**********************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // iterate the array and convert it into a hash table
        // search if there exists a match(target - nums[i]) in hash table while iterating (because each input would have exactly one solution)
        
        vector<int> answer;

        int size = nums.size();
        if (size == 0) {
            return answer;
        }

        map<int, int> numberTable;

        for (int i = 0; i < size; i++) {
            if (numberTable.count(target - nums[i]) > 0) {

                // the order of push indices matters, elements in returned array are orderd
                answer.push_back(numberTable[target - nums[i]]);
                answer.push_back(i);
                return answer;
            } else {
                numberTable[nums[i]] = i;
            }
        }

        return answer;
    }
};