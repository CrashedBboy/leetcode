#include <iostream>

using namespace std;

// [idea]
// an even number + a mutiple of '5' --> one trailing zero

class Solution {
public:
    int trailingZeroes(int n) {

        int zeros = 0;
        for (int i = n; i >= 1; i--) {
            zeros += powerOfFive(i);
        }

        return zeros;
    }

private:

    int powerOfFive(int n) {

        int pow = 0;
        while (n % 5 == 0) {
            pow += 1;
            n = n / 5;
        }

        return pow;
    }
};

int main() {

    int input = 25;

    Solution sol;

    cout << sol.trailingZeroes(input) << endl;

    return 0;
}