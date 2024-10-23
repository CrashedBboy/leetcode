#include <vector>
#include <iostream>

using namespace std;

// [idea]
// phase 1:
// go from right (largest side) to find max unordered element
// go from left (smallest side) to find min unordered element
// phase 2:
// go from right again to find the first element which is smaller than max unordered element
// go from left again to find the first element which is smaller than min unordered element

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int maxUnordered = INT_MIN;
        int minUnordered = INT_MAX;

        bool unordered = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                unordered = true;
            }

            if (unordered) {
                maxUnordered = max(maxUnordered, nums[i]);
            }
        }

        unordered = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                unordered = true;
            }

            if (unordered) {
                minUnordered = min(minUnordered, nums[i]);
            }
        }

        int right;
        int left;
        for (right = nums.size() - 1; right >= 0; right--) {
            if (nums[right] < maxUnordered) {
                break;
            }
        }

        for (left = 0; left < nums.size(); left++) {
            if (nums[left] > minUnordered) {
                break;
            }
        }

        return max((right-left+1), 0);
    }
};

int main() {

    vector<int> inputs = { 1,2,3,4, 200, 100, 150, 120, 1000, 2000};

    Solution sol;

    cout << sol.findUnsortedSubarray(inputs) << endl;

    return 0;
}