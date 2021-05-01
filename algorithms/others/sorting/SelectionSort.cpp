#include <vector>
#include <iostream>

using namespace std;

void selectionSort (vector<int>& nums) {

    int min;
    int minIndex;
    for (int putAt = 0; putAt < nums.size(); putAt++) {
        min = nums[putAt];
        minIndex = putAt;
        for (int i = putAt; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
                minIndex = i;
            }
        }

        if (minIndex != putAt) {
            swap(nums[minIndex], nums[putAt]);
        }
    }
}; 

int main () {

    vector<int> nums = {83, 2, 44, -1, -2, 5, 3};

    selectionSort(nums);

    for (auto& n : nums) {
        cout << n << ",";
    }
    cout << endl;

    return 0;
}