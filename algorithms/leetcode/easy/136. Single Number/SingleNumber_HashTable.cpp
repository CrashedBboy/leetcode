#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> freq; // number : frequency

        for (auto& n : nums) {
            freq[n] += 1;
        }

        for (auto& p : freq) {
            if (p.second == 1) {
                return p.first;
            }
        }

        return -1;
    }
};

int main() {

    vector<int> nums = {4,1,2,1,2};

    Solution sol;
    cout << sol.singleNumber(nums) << endl;

    return 0;
}