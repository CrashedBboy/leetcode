#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int titleNumber = 0;

        int base = (int)('Z' - 'A' + 1);

        for (int i = 0; i < columnTitle.size(); i++) {

            int digit = (int)(columnTitle[i] - 'A' + 1);
            int exponent = columnTitle.size() - i - 1;

            titleNumber += digit * pow(base, exponent);
        }

        return titleNumber;
    }
};


int main () {

    string columnTitle = "FXSHRXW";

    Solution sol;

    cout << sol.titleToNumber(columnTitle) << endl;

    return 0;
}