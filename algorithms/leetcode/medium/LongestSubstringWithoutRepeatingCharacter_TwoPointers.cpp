#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.empty()) {
            return 0;
        }

        int start = 0, end = 0;
        unordered_map<char, int> charPosition;
        for (auto& c : s) {
            charPosition[c] = -1;
        }

        int maxLength = 1;
        for (start = 0, end = 0; end < s.size(); end++) {

            // early stop
            if ((s.size()-start) < maxLength) {
                break;
            }

            if (charPosition[s[end]] != -1) {

                start = max(start, charPosition[s[end]] + 1); // pointer 'start' cannot go backward, forward only
            }

            maxLength = max((end - start + 1), maxLength);
            charPosition[s[end]] = end;
        }

        return maxLength;
    }
};

int main () {

    string input = "pwwkew";

    Solution sol;

    cout << sol.lengthOfLongestSubstring(input) << endl;

    return 0;
}