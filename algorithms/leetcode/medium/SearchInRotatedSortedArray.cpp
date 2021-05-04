#include <vector>
#include <iostream>

using namespace std;

#define NOT_FOUND -1

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (nums.size() == 0) {
            return NOT_FOUND;
        }

        // start binary search
        int left = 0, right = nums.size() - 1, middle;
        while (right >= left) {

            middle = left + (right - left) / 2;

            int leftVal = nums[left];
            int rightVal = nums[right];
            int middleVal = nums[middle];

            if (middleVal == target) {
                return middle;
            }

            if (rightVal < middleVal) {
                // left half is ordered

                if (target >= leftVal && target < middleVal) {
                    // target is in the left
                    right = middle-1;
                }
                else {
                    // target in in the right
                    left = middle+1;
                }
            }
            else {
                // right half is ordered

                if (target > middleVal && target <= rightVal) {
                    // target is in the right
                    left = middle+1;
                }
                else {
                    // target is in the left
                    right = middle-1;
                }
            }
        }

        return NOT_FOUND;
    }
};


int main() {


    // nums = [4,5,6,7,0,1,2], target = 0
    vector<int> inputs = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 1;

    Solution sol;
    int res = sol.search(inputs, target);

    cout << res << endl;

    return 0;
}