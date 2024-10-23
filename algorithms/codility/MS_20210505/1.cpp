// Question
/*
Write a function that, given a string S consisting of N characters,
return the alphabetically smallest string that can be obtained by removing exactly on letter from S.

Example:
1. S = "acb", return "ab"
2. S = "hot", return "ho"

Constraints:
N in the range [2 ... 100,000]
S consists only lowercase letters (a-z)
*/

#include <iostream>
#include <string>

int smaller(string& str, int skipAt1, int skipAt2) {

    int idx1 = 0, idx2 = 0;
    while (idx1 < str.size() && idx2 < str.size()) {

        if (idx1 == skipAt1) idx1++;
        if (idx2 == skipAt2) idx2++;

        if (str[idx1] < str[idx2]) {
            return 1;
        }
        else if(str[idx1] > str[idx2]) {
            return 2;
        }
        else if (str[idx1] == str[idx2]) {
            idx1 += 1; idx2 += 1;
        }
    }

    return 1;
}

string solution(string &S) {
    
    // Idea:
    // try removing i-th letter, where i goes from 0 to N
    // then compare these results and determine the alphabetically smallest
    // So. the time complexity should be O(SN)

    int smallestRemoveAt = 0;
    for (int i = 1; i < S.size(); i++) {
        if (smaller(S, smallestRemoveAt, i) == 2) {
            smallestRemoveAt = i;
        }
    }

    S.erase(S.begin() + smallestRemoveAt);

    return S;
}
