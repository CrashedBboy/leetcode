#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NOT_FOUND -1

class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> firstOccur(26, NOT_FOUND);
        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            int charIdx = s[i] - 'a';

            if (firstOccur[charIdx] == NOT_FOUND) {
                firstOccur[charIdx] = i;
            }

            count[charIdx] += 1;
        }

        int minIdx = NOT_FOUND;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 1) {
                if (minIdx == NOT_FOUND) {
                    minIdx = firstOccur[i];
                }
                else {
                    minIdx = min(minIdx, firstOccur[i]);
                }
            }
        }

        return minIdx;
    }
};


int main () {

    string inputs = "leetcode";

    Solution sol;

    cout << sol.firstUniqChar(inputs) << endl;

    return 0;
}