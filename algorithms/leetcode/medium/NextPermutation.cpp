#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() <= 1) {
            return;
        }

        // iterate the list from right, find the first decreasing element
        int firstDecreasing = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                firstDecreasing = i;
                break;
            }
        }

        if (firstDecreasing == -1) {
            sort(nums.begin(), nums.end());
        }
        else {

            // find the smallest number which is larget than firstDecreaing
            int smallestLarger = -1;
            for (int i = nums.size() - 1; i > firstDecreasing; i--) {

                if (nums[i] > nums[firstDecreasing]) {

                    if (smallestLarger == -1) {
                        smallestLarger = i;
                    }
                    else if (nums[i] < nums[smallestLarger]) {
                        smallestLarger = i;
                    }
                }
            }


            swap(nums[firstDecreasing], nums[smallestLarger]);
            sort(nums.begin() + firstDecreasing + 1, nums.end());
        }
    }
};


int main () {

    vector<int> inputs = {1, 5, 2, 4, 3};

    Solution sol;
    sol.nextPermutation(inputs);

    for (auto& n : inputs) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}