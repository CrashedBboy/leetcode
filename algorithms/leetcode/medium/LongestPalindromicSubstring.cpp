#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int maxLength = 0;
        string theLongest;

        // use each digits as center
        for (int i = 0; i < s.size(); i++) {

            int j = i - 1;
            int k = i + 1;
            int length = 1;
            while (j >= 0 && k < s.size()) {
                if (s[j] != s[k]) {
                    break;
                }
                length += 2;
                j -= 1;
                k += 1;
            }

            if (length > maxLength) {
                maxLength = length;
                theLongest = string(s, j + 1, length);
            }
        }


        // use each digit-intervals as center
        for (int i = 0; i < s.size(); i++) {

            int j = i;
            int k = i + 1;
            int length = 0;

            while (j >= 0 && k < s.size()) {
                if (s[j] != s[k]) {
                    break;
                }
                length += 2;
                j -= 1;
                k += 1;
            }

            if (length > maxLength) {
                maxLength = length;
                theLongest = string(s, j + 1, length);
            }
        }

        return theLongest;
    }
};


int main() {

    string input = "bbbb";

    Solution sol;

    cout << sol.longestPalindrome(input) << endl;

    return 0;
}