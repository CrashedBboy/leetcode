#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int theSingle = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            theSingle = theSingle ^ nums[i];
        }

        return theSingle;
    }
};

int main() {

    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}