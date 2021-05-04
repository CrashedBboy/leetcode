#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (auto& number : nums) {
            sum += number;
        }

        int realSum = n * (n + 1) / 2;

        return (realSum - sum);
    }
};

int main() {

    vector<int> inputs = { 3, 0, 1 };

    Solution sol;

    int res = sol.missingNumber(inputs);

    cout << res << endl;


    return 0;
}