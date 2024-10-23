#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        if (nums1.empty() || nums2.empty()) {
            return ans;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 0;
        for (int idx2 = 0; idx2 < nums2.size(); idx2 ++) {

            // because it's sorted
            while (nums1[idx1] < nums2[idx2]) {
                idx1 += 1;
            }

            if (nums1[idx1] == nums2[idx2]) {
                ans.push_back(nums2[idx2]);
                idx1 += 1;
            }
        }

        return ans;
    }
};


int main () {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2,};

    Solution sol;
    vector<int> ans = sol.intersect(nums1, nums2);

    for (auto& n : ans) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}