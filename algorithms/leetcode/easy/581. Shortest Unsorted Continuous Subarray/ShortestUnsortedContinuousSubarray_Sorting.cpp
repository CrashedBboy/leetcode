#include <vector>
#include <algorithm>

using namespace std;

// [idea]
// sorting: then compare sorted & unsorted lists

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int left = 0;
        for (; left < nums.size(); left++) {
            if (sorted[left] != nums[left]) {
                break;
            }
        }

        int right = nums.size() -1;
        for (; right >= 0; right--) {
            if (sorted[right] != nums[right]) {
                break;
            }
        }

        return max((right-left+1), 0);
    }
};