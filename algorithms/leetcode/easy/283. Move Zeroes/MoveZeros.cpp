#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int latestNonZero = 0;
        for (auto& n : nums) {
            if (n != 0) {
                nums[latestNonZero] = n;
                latestNonZero += 1;
            }
        }
        
        for (int i = latestNonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        // two pointers

        int lastNonZero =   -1;
        int visited     =   0;

        while (visited < nums.size()) {
            if (nums[visited] != 0) {
                lastNonZero += 1;
                swap(nums[lastNonZero], nums[visited]);
            }
            visited += 1;
        }
    }
};

int main () {

    vector<int> inputs = {0, 1, 0, 3, 12};

    Solution sol;
    sol.moveZeroes(inputs);

    for (auto& n : inputs) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}