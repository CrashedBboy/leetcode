// Source : https://leetcode.com/problems/combination-sum/
// Author : CrashedBboy
// Date   : 2020-04-25

// Questions
/********************************************************************************** 
Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
**********************************************************************************/

// [idea]
// use heap sort

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        bool useMaxHeap = k <= nums.size();
        int target = useMaxHeap? k : nums.size() - k + 1;

        auto cmp = useMaxHeap? [](int a, int b) { return a < b; } : [](int a, int b) { return a > b; };

        priority_queue<int, vector<int>, decltype(cmp)> heap(nums.begin(), nums.end(), cmp);

        int result;
        
        for (int i = 0; i < target; i++) {
            result = heap.top();
            heap.pop();
        }

        return result;
    }
};