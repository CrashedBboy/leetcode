#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_map<int, int> squareSumCount;
        squareSumCount[n] = 1;

        int squareSum = n;
        while (true) {

            int digitSquareSum = 0;
            while (squareSum > 0) {

                int digit = squareSum % 10;
                cout << "digit: " << digit << endl;

                digitSquareSum += (int)pow(digit, 2);

                squareSum /= 10;
            }

            cout << digitSquareSum << endl;

            if (digitSquareSum == 1) {
                return true;
            }
            else {
                if (squareSumCount[digitSquareSum] == 0) {
                    squareSum = digitSquareSum;
                    squareSumCount[digitSquareSum] = 1;
                }
                else {
                    return false;
                }
            }
        }
    }
};


int main () {

    int input = 19;

    Solution sol;

    cout << sol.isHappy(input) << endl;

    return 0;
}