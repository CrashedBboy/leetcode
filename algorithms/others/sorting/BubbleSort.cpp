#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort (vector<int>& nums) {

    for (int end = nums.size() - 1; end >= 1; end--) {
        for (int i = 0; i <= end-1; i++) {
            if (nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
}

int main() {

    vector<int> nums = {12, 4, 5, 2, 11, 45};

    bubbleSort(nums);

    for (auto& n : nums) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}