#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        bool pending = false;
        int lastNumber = -1;
        for (auto& n : nums) {
            if (pending == true) {

                if (n != lastNumber) {
                    return lastNumber;
                }
                else {
                    pending = false;
                }
            }
            else if (pending == false) {
                lastNumber = n;
                pending = true;
            }
        }

        return lastNumber;
    }
};

int main() {

    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}