#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int kth;

        for (int i = 0; i < k; i++) {
            make_heap(nums.begin(), nums.end());
            pop_heap(nums.begin(), nums.end());

            kth = nums.back();
            nums.pop_back();
        }

        return kth;
    }
};