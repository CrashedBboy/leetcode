// https://app.codility.com/c/feedback/6XB4QJ-AQ6/

/*******************************************************************************************
You are given an implementation of a function:

    bool solution(vector<int>& A, int K);

This function, given a non-empty array A of N integers (sorted in non-decreasing order) and 
integer K, checks whether A contains 1, 2, ..., K (every number from 1 to K at least once) and
no other numbers.

Example:

1. given the following array A, and K = 3:
A = [1, 1, 2, 3, 3]
The function should return true

2. For the following array A, and K = 2:
A = [1, 1, 3]
The function should return false.

The attached code is still incorrect for some inputs. Despite the errors, the code may produce a
correct answer for the example test cases. The goal of the exercise is to find and fix the bugs(s)
in the implementation.

You can modify at most two lines.

Assume that:
* N and K are integers within the range [1 .. 300,000]
* each element of array A is an integer within the range [0 .. 1,000,000,000]
* array A is sorted in non-decreasing order

In your solution, focus on correctness, The performance of your solution will not be the focus of
assessment.
*******************************************************************************************/

bool solution(vector<int> &A, int K) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        if (A[i] + 1 < A[i + 1]) // ----------------> if ( A[i] > A[i + 1] || (A[i + 1] - A[i]) > 1)
            return false;
    }
    if (A[0] != 1 && A[n - 1] != K) // ----------------> if (A[0] != 1 || A[n - 1] != K)
        return false;
    else
        return true;
}

/*
Compilation successful.

Example test:   ([1, 1, 2, 3, 3], 3)
OK

Example test:   ([1, 1, 3], 2)
OK

Your test case: [[1, 1, 3], 2]
Returned value: False

Your test case: [[1, 1, 1, 1, 2, 2, 2, 2, 4], 4]
Returned value: False

Your test case: [[1, 1, 1, 1, 2, 2, 2, 2, 4], 3]
Returned value: False

Your test case: [[1, 2, 1], 2]
Returned value: False
*/