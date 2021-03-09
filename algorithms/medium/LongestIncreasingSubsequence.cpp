#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }

        int lisLength = 1;

        // initial all subsequence length to 1 (only themselves)
        vector<int> dp (nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                    lisLength = max(lisLength, dp[i]);
                }
            }
        }

        return lisLength;
    }
};



int main () {

    vector<int> inputs = {7,7,7,7,7,7,7};
    Solution s;
    int lisLength = s.lengthOfLIS(inputs);

    cout << "Length of LIS: " << lisLength << endl;

    return 0;
}