#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void insertionSort(vector<int>& nums) {

    int orderedEnd = 0;

    for (int i = 1; i < nums.size(); i++) {
        int current = i;
        while ((current-1) >= 0 && nums[current-1] > nums[current]) {
            swap(nums[current], nums[current-1]);
            current -= 1;
        }
    }
}

int main() {

    vector<int> nums = {56, 12, 33, 44, 1, -4, -84};

    insertionSort(nums);

    for (auto& n : nums) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}