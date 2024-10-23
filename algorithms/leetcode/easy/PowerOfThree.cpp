#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n < 1) {
            return false;
        }

        int tmp = n;
        while (tmp % 3 == 0) {
            tmp /= 3;
        }

        return (tmp == 1);
    }
};

int main() {

    int input = 45*3*27;

    Solution sol;
    cout << sol.isPowerOfThree(input) << endl;

    return 0;
}