#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        int sum = numbers[left] + numbers[right];
        while (sum != target) {
            if (sum > target) {
                right -= 1;
            }
            else if (sum < target) {
                left += 1;
            }
            sum = numbers[left] + numbers[right];
        }

        vector<int> ans = { left + 1, right + 1 };

        return ans;
    }
};

int main() {

    vector<int> input = { 2,7,11,15 };
    int target = 9;

    Solution s;

    vector<int> ans = s.twoSum(input, target);

    return 0;
}