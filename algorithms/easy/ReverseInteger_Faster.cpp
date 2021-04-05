#include <iostream>
#include <stack>
#include <cmath>
#include <limits>

using namespace std;


class Solution {
public:
    int reverse(int x) {

        bool negative = x >= 0 ? false : true;

        stack<int> digits;


        while (x != 0) {
            int d = abs(x % 10);
            digits.push(d);

            x = x / 10;
        }

        int reversed = 0;
        int exp = 0;
        while (!digits.empty()) {

            int d = digits.top();

            // check for overflow:
            // if A + B*10^n > LIMIT
            // then A/10 + B*10^(n-1) > LIMIT/10
            if ((reversed / 10 + d * pow(10, exp-1)) > (numeric_limits<int>::max() / 10)) {
                return 0;
            }
            else {
                reversed += d * pow(10, exp);
                digits.pop();
                exp += 1;
            }
        }

        if (negative) {
            reversed = reversed * (-1);
        }

        return reversed;
    }
};




int main() {

    int input = -2147483412;

    Solution sol;
    cout << sol.reverse(input) << endl;

    return 0;
}