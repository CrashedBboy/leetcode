// Source : https://leetcode.com/problems/sort-colors/
// Author : CrashedBboy
// Date   : 2020-12-09

// Questions
/**************************************************************************************** 
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]
Output: [1]

Follow up:

* Could you solve this problem without using the library's sort function?
* Could you come up with a one-pass algorithm using only O(1) constant space?
******************************************************************************************/

// idea:
// https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        
        int redCount = 0;
        int whiteCount = 0;
        int blueCount = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) { redCount += 1; }
            else if (nums[i] == 1) { whiteCount += 1; }
            else if (nums[i] == 2) { blueCount += 1; }
        }

        for (int i = 0; i < redCount; i++) { nums[i] = 0; }
        for (int i = redCount; i < redCount+whiteCount; i++) { nums[i] = 1; }
        for (int i = redCount+whiteCount; i < redCount+whiteCount+blueCount; i++) { nums[i] = 2; }
    }
};

class Solution2 {

public:

    void sortColors(vector<int>& nums) {

        int redIndex = -1, whiteIndex = -1, blueIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            
            // red
            if (nums[i] == 0) {
                redIndex += 1; whiteIndex += 1; blueIndex += 1;
                nums[blueIndex] = 2; nums[whiteIndex] = 1; nums[redIndex] = 0;
            }

            // white
            else if (nums[i] == 1) {
                whiteIndex += 1; blueIndex += 1;
                nums[blueIndex] = 2; nums[whiteIndex] = 1;
            }

            // blue
            else if (nums[i] == 2) {
                blueIndex += 1;
                nums[blueIndex] = 2;
            }
        }
    }
}

#include <vector>
#include <algorithm>

class Solution3 {

public:

    void sortColors(vector<int>& nums) {

        // set two pivot: 
        // redPivot: items before red pivot are all red
        // bluePivot: items after blue pivot are all blue

        int redPivot = 0;
        int bluePivot = nums.size() - 1;

        for (int i = 0; i <= bluePivot; i++) {

            if (nums[i] == 0 && i != redPivot) {
                swap(nums[i], nums[redPivot]);
                i -= 1; // re-look the new swapped element in the next iteration
                redPivot += 1;
            }
            else if (nums[i] == 2 && i != bluePivot) {
                swap(nums[i], nums[bluePivot]);
                i -= 1;
                bluePivot -= 1;
            }
        }
    }
}