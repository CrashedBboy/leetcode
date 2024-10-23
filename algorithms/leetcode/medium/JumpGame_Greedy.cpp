#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int furthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= furthest) {
                furthest = max(furthest, i+ nums[i]);

                if (furthest >= nums.size()) {
                    return true;
                }
            }
        }

        return (furthest >= nums.size() - 1);
    }
};

int main () {

    vector<int> inputs = {0};

    Solution sol;

    cout << sol.canJump(inputs) << endl;

    return 0;
}