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

        int maxLength = 1;
        for (int start = 0; start < s.size(); s++) {
            if ((s.size() - start) < maxLength) {
                break;
            }

            unordered_map<char, bool> charExist;
            int length = 0;
            for (int i = start; i < s.size(); i++) {
                if (charExist[s[i]] == false) {
                    charExist[s[i]] = true;
                    length += 1;
                }
                else {
                    break;
                }
            }

            maxLength = max(maxLength, length);
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