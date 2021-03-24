#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // start from largest numbers
        int idx1 = m-1;
        int idx2 = n-1;
        int idx = m+n-1;

        while (idx1 >= 0 && idx2 >= 0) {
            cout << idx1 << "," << idx2 << "," << idx << endl;
            if (nums1[idx1] >= nums2[idx2]) {
                nums1[idx] = nums1[idx1];
                idx1 -= 1;
            }
            else {
                nums1[idx] = nums2[idx2];
                idx2 -= 1;
            }

            idx -= 1;
        }

        while (idx1 >= 0) {
            nums1[idx] = nums1[idx1];
            idx -= 1;
            idx1 -= 1;
        }

        while (idx2 >= 0) {
            nums1[idx] = nums2[idx2];
            idx -= 1;
            idx2 -= 1;
        }
    }
};



int main () {

    vector<int> nums1 = {1,2,3,0,0,0}; int m = 3;
    vector<int> nums2 = {2,5,6}; int n = 3;

    Solution sol;

    sol.merge(nums1, m, nums2, n);

    for (auto& n : nums1) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}