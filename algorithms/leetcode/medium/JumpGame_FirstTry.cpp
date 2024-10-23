#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<bool> available (nums.size(), false);
        available[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            
            if (available[i]) {
                for (int j = 1; j <= nums[i]; j++) {
                    if ((i+j) >= nums.size()) {
                        return true;
                    }
                    else {
                        available[i+j] = true;
                    }
                }
            }
        }

        return available[available.size() - 1];
    }
};

int main () {

    vector<int> inputs = {0};

    Solution sol;

    cout << sol.canJump(inputs) << endl;

    return 0;
}