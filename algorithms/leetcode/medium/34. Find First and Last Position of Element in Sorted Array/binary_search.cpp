#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans (2, -1);

        if (nums.empty()) {
            return ans;
        }
        
        int li = 0; int ri = nums.size() - 1; int mi;

        while (li < ri) {
            mi = li + (ri-li)/2;

            if (nums[mi] >= target) {
                ri = mi;
            }
            else {
                li = mi + 1;
            }
        }
        if (nums[li] == target) {
            ans[0] = li;
        }

        ri = nums.size() - 1; // reset the right indicator
        while (li < ri) {
            mi = li + (ri - li)/2 + 1;

            if (nums[mi] > target) {
                ri = mi - 1;
            }
            else {
                li = mi;
            }
        }
        if (nums[ri] == target) {
            ans[1] = ri;
        }

        return ans;
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