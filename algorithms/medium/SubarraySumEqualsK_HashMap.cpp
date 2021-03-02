
// [idea]
// In array of cumulative addition, difference b/t two elements A & B is the sum from A to B

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;

        // <sum, count>
        unordered_map<int, int> sumCountMap;

        sumCountMap[0] = 1;
        int cumulativeSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];

            count += sumCountMap[cumulativeSum - k];

            sumCountMap[cumulativeSum] += 1;
        }

        return count;
    }
};

int main() {

    Solution s;

    vector<int> input1 = {1, 1, 1};
    int target1 = 2;
    int answer1 = 2;

    vector<int> input2 = {1, 2, 3};
    int target2 = 3;
    int answer2 = 2;

    cout << "Test case 1: " << s.subarraySum(input1, target1) << endl;
    cout << "Test case 2: " << s.subarraySum(input2, target2) << endl;

    return 0;
}