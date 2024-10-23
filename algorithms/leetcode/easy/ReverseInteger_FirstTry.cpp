#include <iostream>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;


class Solution {
public:
    int reverse(int x) {

        bool negative = x >= 0 ? false : true;

        int intMax = pow(2, 31) - 1;
        stack<int> maxDigits;

        while (intMax != 0) {
            int d = abs(intMax % 10);
            maxDigits.push(d);

            intMax = intMax / 10;
        }

        stack<int> digits;
        queue<int> digitsForChecking;

        while (x != 0) {
            int d = abs(x % 10);
            digits.push(d);
            digitsForChecking.push(d);

            x = x / 10;
        }

        // check for overflow
        if (digitsForChecking.size() > maxDigits.size()) {
            return 0;
        }
        else if (digitsForChecking.size() == maxDigits.size()) {

            while (!digitsForChecking.empty()) {
                int d1 = digitsForChecking.front();
                int d2 = maxDigits.top();

                if (d1 > d2) {
                    return 0;
                }
                else if (d1 < d2) {
                    break;
                }

                digitsForChecking.pop();
                maxDigits.pop();
            }
        }

        int reversed = 0;
        int exp = 0;
        while (!digits.empty()) {

            int d = digits.top();

            reversed += d * pow(10, exp);

            digits.pop();
            exp += 1;
        }

        if (negative) {
            reversed = reversed * (-1);
        }

        return reversed;
    }
};


int main() {

    int input = 2147483647;

    Solution sol;
    cout << sol.reverse(input) << endl;

    return 0;
}