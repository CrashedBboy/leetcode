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
