#include <iostream>
#include <set>
#include <cmath>
using namespace std;

void solution1(int (&arr)[7]) {
    // linear probe: examine the difference between neighboring elements
    unsigned int N = sizeof(arr)/sizeof(int);
    if (N <= 2) {
        return;
    }

    for (int i = 1; i < N; i++) {
        if ((arr[i] - arr[i-1]) > 1) {
            cout << (arr[i-1]+1) << endl;
        }
    }
    return;
}

void _solution2(int (&arr)[7], unsigned int startIdx, unsigned int endIdx) {
    if ((endIdx-startIdx) == 1) {
        if ((arr[endIdx] - arr[startIdx]) > 1) {
            cout << arr[startIdx] + 1 << endl;
        }
    }
    else {
        unsigned int midIdx = (startIdx + endIdx)/2;
        float midValSupposed = (float(arr[startIdx]) + float(arr[endIdx]))/2;
        if (float(arr[midIdx]) < midValSupposed) {
            _solution2(arr, midIdx, endIdx);
        }
        else {
            _solution2(arr, startIdx, midIdx);
        }
    }
} 

void solution2(int (&arr)[7]) {
    // binary search
    // if arr[mid index] is larger than (min+max)/2 => indicates there's a skipping in the former range
    unsigned int N = sizeof(arr)/sizeof(int);
    if (N <= 2) return;

    _solution2(arr, 0, N-1);
}



void solution3(int (&arr)[7]) {
    // use ordered set
    // suitable if duplicated values exist and the list is unordered
    return;
}

void solution4(int (&arr)[7]) {
    // use expected sum
    // suitable when only one missing value
    // or suitable when min/max is known by the array is unordered.
}

int main(void) {
    int arr[7] = {1, 3, 4, 5, 6, 7, 8}; // expected output: 2
    solution4(arr);

    // int arr[7] = {1,2,2,4,4,5,5};
    // solution3(arr);
    return 0;
}

// confirm: what defines the range of the number series?
// confirm: how many numbers are missing?
// confirm: can a value shows up more than once? 
// confirm: interval between values (default: 1)