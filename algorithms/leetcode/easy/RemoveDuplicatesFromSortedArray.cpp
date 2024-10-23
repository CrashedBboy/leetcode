#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }

        int previousUnique = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[previousUnique]) {
                previousUnique += 1;
                nums[previousUnique] = nums[i];
            }
        }

        return previousUnique + 1;
    }
};

int main () {

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution sol;

    int len = sol.removeDuplicates(nums);

    for (int i = 0; i < len; i++) {
        cout << nums[i] << ",";
    }
    cout << endl;

    return 0;
}


