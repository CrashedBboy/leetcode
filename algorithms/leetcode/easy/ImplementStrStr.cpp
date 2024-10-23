#include <iostream>
#include <string>

using namespace std;

// O(MN)

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == "") {
            return 0;
        }

        if (needle.size() > haystack.size()) {
            return -1;
        }

        for (int i = 0; i <= (haystack.size() - needle.size()); i++) {

            bool identical = true;
            for (int j = 0; j < needle.size(); j++) {

                if (haystack[i + j] != needle[j]) {
                    identical = false;
                    break;
                }
            }

            if (identical) {
                return i;
            }
        }

        return -1;
    }
};


int main () {


    string haystack = "hello";
    string needle = "ll";

    Solution sol;

    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}