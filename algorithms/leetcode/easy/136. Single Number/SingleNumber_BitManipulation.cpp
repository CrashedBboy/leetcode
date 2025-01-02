#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (auto& n : nums) {
            single ^= n;
        }
        return single;
    }
};

int main() {

    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}