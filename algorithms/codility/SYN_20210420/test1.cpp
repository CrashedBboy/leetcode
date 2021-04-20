/*
QUESTION:

Given an implementation of a function.

Its params are non-empty array A of N non-negative int and non-empty array B of M non-negative int.
The function return the min value that occurs in both arrays. If there's no such value, return -1

There're some bug existing in the given implementation, correct it.
*/

#include <vector>
#include <algorithm>

int solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for (int k = 0; k < n; k++) {
        while (i < m - 1 && B[i] < A[k])
            i++;
        if (A[k] == B[i])
            return A[k];
    }
    return -1;
}


// the original
#include <vector>
#include <algorithm>

int solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for (int k = 0; k < n; k++) {
        if (i < m - 1 && B[i] < A[k])
            i++;
        if (A[k] == B[i])
            return A[k];
    }
    return -1;
}
