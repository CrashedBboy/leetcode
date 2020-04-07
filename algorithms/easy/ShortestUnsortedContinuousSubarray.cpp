// Source : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Author : CrashedBboy
// Date   : 2020-04-07

// Questions
/********************************************************************************** 
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
1. Then length of the input array is in range [1, 10,000].
2. The input array may contain duplicates, so ascending order here means <=.

**********************************************************************************/

// [idea]
// sort the list first, then compare the two lists at each position


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> sortedNums;
        for (int i = 0; i < nums.size(); i++) {
            sortedNums.push_back(nums[i]);
        }

        std::sort(sortedNums.begin(), sortedNums.end());

        int idxMin = -1;
        int idxMax = -2;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != sortedNums[i]) {

                if (idxMin == -1 && idxMax == -2) {
                    idxMin = idxMax = i;
                
                } else {

                    idxMax = i;
                }
            }
        }

        return (idxMax - idxMin) + 1;
    }
};