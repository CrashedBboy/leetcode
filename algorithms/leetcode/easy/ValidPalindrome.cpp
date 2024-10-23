#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        if (s.empty()) {
            return true;
        }
        
        int start = 0, end = s.size() - 1;

        while (start <= end) {

            if (!isLetter(s[start]) && !isDigit(s[start])) {
                start += 1;
                continue;
            }

            if (!isLetter(s[end]) && !isDigit(s[end])) {
                end -= 1;
                continue;
            }

            if (!isIdentical(s[start], s[end])) {
                return false;
            }

            start += 1; end -= 1;
        }

        return true;
    }


private:

    bool isDigit(char c) {

        if (c >= '0' && c <= '9') {
            return true;
        }
        else {
            return false;
        }
    }

    bool isLetter(char a) {

        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
            return true;
        }
        return false;
    }

    bool isIdentical(char a, char b) {

        if (a != b) {

            if (isLetter(a) && isLetter(b)) {
                if (a > b) {
                
                    if ((a - ('a'-'A')) == b) {
                        return true;
                    }
                    else {
                        return false;
                    }
                } else if (b > a) {
                    if ((b - ('a'-'A')) == a ) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
};


int main () {

    string input = "A man, a plan, a canal: Panama";

    Solution sol;

    cout << sol.isPalindrome(input) << endl;

    return 0;
}