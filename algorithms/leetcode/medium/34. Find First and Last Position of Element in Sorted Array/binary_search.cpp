// great solution:
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = -1;
        int last = -1;

        if (nums.empty()) {
            return {first, last};
        }

        if (nums.size() == 1) {
            if (nums[0] == target) {
                first = last = 0;
            }
            return {first, last};
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // find first
        while (left <= right) {
            if (nums[left] == target) {
                first = left;
                break;
            }
            else {
                mid = left + (right-left)/2;

                if (nums[mid] > target) {
                    right = mid-1;
                }
                else if (nums[mid] == target) {
                    right = mid;
                }
                else if (nums[mid] < target) {
                    left = mid+1;
                }
            }
        }

        left = 0; right = nums.size() - 1;
        // find last
        while (left <= right) {
            if (nums[right] == target) {
                last = right;
                break;
            }
            else {
                mid = left + (int)ceil(((float)(right-left))/2);

                if (nums[mid] > target) {
                    right = mid-1;
                }
                else if (nums[mid] == target) {
                    left = mid;
                }
                else if (nums[mid] < target) {
                    left = mid+1;
                }
            }
        }

        return {first, last};
    }
};

int main () {

    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;

    Solution s;

    vector<int> ans = s.searchRange(nums, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}