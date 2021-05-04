#include <vector>
#include <iostream>

using namespace std;

// binary search:
// if the center < target, return: right half execution result
// if the center > target, return: left half execution result
// if the center == target, return: both left and right result
// !! always return 2 numbers

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchTarget(nums, 0, nums.size() - 1, target);
    }

private:
    vector<int> searchTarget(vector<int>& nums, int start, int end, int target) {

        vector<int> indexFirstLast = {-1, -1};

        if (start > end) {
            return indexFirstLast;
        }

        // recursion boundry
        if (end == start) {
            if (nums[start] == target) {
                indexFirstLast[0] = indexFirstLast[1] = start;
            }
            return indexFirstLast;
        }

        int center = (start + end) / 2;

        vector<int> leftFirstLast = searchTarget(nums, start, center, target);
        vector<int> rightFirstLast = searchTarget(nums, center+1, end, target);

        // find min index which is not -1
        if (leftFirstLast[0] != -1) {
            indexFirstLast[0] = leftFirstLast[0];
        }
        else {
            indexFirstLast[0] = rightFirstLast[0];
        }

        // find max index which is not -1
        if (rightFirstLast[1] != -1) {
            indexFirstLast[1] = rightFirstLast[1];
        }
        else {
            indexFirstLast[1] = leftFirstLast[1];
        }

        return indexFirstLast;
    }
};

int main () {

    vector<int> nums = {5, 7, 7, 10};
    int target = 8;

    Solution sol;
    vector<int> answer = sol.searchRange(nums, target);

    cout << answer[0] << "~" << answer[1] << endl;

    return 0;
}