
// [idea]
// array: cumulative adding
// difference b/t elements A,B in array is the sum of subarray(start=A, end=B)

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;

        // do cumulative sum
        vector<int> cumulativeSum (nums.size() + 1);
        cumulativeSum[0] = 0;
        for (int i = 1; i < cumulativeSum.size(); i++) {
            cumulativeSum[i] = cumulativeSum[i-1] + nums[i-1];
        }

        for (int start = 0; start < cumulativeSum.size(); start++) {
            for (int end = start + 1; end < cumulativeSum.size(); end++) {

                if ((cumulativeSum[end] - cumulativeSum[start]) == k) {
                    count += 1;
                }
            }
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