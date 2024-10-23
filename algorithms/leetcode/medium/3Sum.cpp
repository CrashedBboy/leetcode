// Source : https://leetcode.com/problems/3sum/
// Author : CrashedBboy
// Date   : 2020-05-03

// Questions
/********************************************************************************** 

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

**********************************************************************************/

// [idea]
// iterately pick an element, finding the rest two elements will be "2 sum" problem

// sort the array

// iterate the sorted array to be first element
//// if the value has already been used as first element (arr[i] == arr[i-1]), skip it
//// find the rest two elements, we use 2 pointers 'second' & 'third' pointing at i+1 & N-1
////// if arr[second] + arr[third] == target: get one solution, second++ / third-- until not duplicate
////// if arr[second] + arr[third] > target: arr[third] is too big, third --
////// if arr[second] + arr[third] < target: arr[second] is too small, seconf ++

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        if (nums.size() < 3) {

            return result;
        }
        
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size() - 2; first++) {

            if (first > 0 && nums[first] == nums[first - 1]) { continue; }

            int target = - nums[first];

            int second = first + 1;
            int third = nums.size() - 1;

            while (second < third) {

                int complement = nums[second] + nums[third];

                if (complement == target) {

                    vector<int> res = {nums[first], nums[second], nums[third]};
                    result.push_back(res);

                    second++;
                    third--;

                    while (second < nums.size() && nums[second] == nums[second - 1]) { second++; }
                    while (third >= 0 && nums[third] == nums[third + 1]) { third--; }
                
                } else if (complement > target) {

                    third --;
                
                } else if (complement < target) {

                    second ++;
                }
            }
        }

        return result;
    }
};