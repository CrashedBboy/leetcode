
// [idea]
// iterate all start position
// add from start to end
// count (sum==k?) while adding

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;

        for (int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for (int i = start; i < nums.size(); i++) {
                sum += nums[i];

                if (sum == k) {
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