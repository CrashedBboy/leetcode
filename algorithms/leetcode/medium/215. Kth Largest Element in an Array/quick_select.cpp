#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int left = 0; int right = nums.size() - 1;
        int pivot = -1;
        while (pivot != k) {

            pivot = right;
            int tmp;
            for (int i = left; i < pivot; ) {
                if (nums[i] >= nums[pivot]) {
                    i += 1;
                    continue;
                }
                else {
                    tmp = nums[pivot];
                    nums[pivot] = nums[i];
                    nums[i] = nums[pivot - 1];
                    nums[pivot-1] = tmp;

                    pivot -= 1;
                }
            }

            if (pivot > k) {
                right = pivot-1;
            }
            else if (pivot < k) {
                left = pivot+1;
            }
        }

        return nums[pivot];
    }
};