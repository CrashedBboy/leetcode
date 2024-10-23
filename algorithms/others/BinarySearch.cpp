#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch(vector<int>& nums, int x) {

    int left = 0, right = nums.size()-1;

    while (left <= right) {

        cout << "left: " << left << ", right: " << right << endl;

        int mid = left + (right-left) / 2;

        if (nums[mid] == x) {
            return true;
        }
        else if (nums[mid] > x) {
            right = mid - 1;
        }
        else if (nums[mid] < x) {
            left = mid + 1;
        }
    }

    return false;
}

int main () {

    vector<int> inputs = {22, 33, 34, 35, 47, 56, 73, 123};

    cout << BinarySearch(inputs, 22);

    return 0;
}