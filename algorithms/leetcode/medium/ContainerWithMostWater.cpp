// Source : https://leetcode.com/problems/container-with-most-water/
// Author : CrashedBboy
// Date   : 2020-05-02

// Questions
/********************************************************************************** 

Given n non-negative integers a1, a2, ..., an , where each represents a point at 
coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container 
contains the most water.

Note: You may not slant the container and n is at least 2.

[figure]: https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

**********************************************************************************/

// [idea]
// use two pointers, start & end, to indicate two side of container
// set initial locations of start and end to edges of array: start = 0, end = N - 1

// [iteration]
// because the volume is determined by the shorter side,
// move the shorter side toward the another by one step
// during the iteration, keep update variable 'maxVolume'


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start = 0;

        int end = height.size() - 1;

        int maxVolume = 0;

        while (start != end) {

            if (height[start] > height[end]) {

                maxVolume = max(maxVolume, (end - start) * height[end]);

                end -= 1;
            
            } else {

                maxVolume = max(maxVolume, (end - start) * height[start] );

                start += 1;
            }
        }

        return maxVolume;
    }
};