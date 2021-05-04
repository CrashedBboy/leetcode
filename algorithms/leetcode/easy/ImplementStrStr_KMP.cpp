#include <iostream>
#include <string>
#include <vector>

using namespace std;

// O(M+N)

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == "") {
            return 0;
        }

        if (needle.size() > haystack.size()) {
            return -1;
        }

        // create longest prefix suffix: O(N)
        vector<int> lps(needle.size(), 0);
        if (needle.size() > 1) {
            int i = 0, j = 1;

            while (j < lps.size()) {
            
                if (needle[i] == needle[j]) {
                    lps[j] = i + 1;
                    i += 1;
                    j += 1;
                }
                else {

                    // This is tricky. Consider the example.
                    // AAACAAAA and j = 7. The idea is similar
                    // to search step.
                    if (i > 0) {
                        i = lps[i - 1];
                    }
                    else if (i == 0) {
                        lps[j] = 0;
                        j += 1;
                    }
                }
            }
        }

        // search: O(M)
        int i = 0, j = 0;

        while (i < haystack.size()) {
        
            if (haystack[i] == needle[j]) {
            
                if (j == needle.size() - 1) {
                    // matched!
                    return (i - j);
                }
                else {
                    i += 1; j += 1;
                }
            }
            else {

                if (j == 0) {
                    i += 1;
                }
                else {
                    j = lps[j-1];
                }
            }
        }

        return -1;
    }
};


int main() {


    string haystack = "aabaaabaaac";
    string needle = "aabaaac";

    Solution sol;

    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}