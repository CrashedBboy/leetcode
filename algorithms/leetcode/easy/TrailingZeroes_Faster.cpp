#include <iostream>

using namespace std;

// [idea]
// an even number + a mutiple of '5' --> one trailing zero

class Solution {
public:
    int trailingZeroes(int n) {

        int zeros = 0;

        while (n > 0) {

            n = n / 5;
            zeros += n;
        }

        return zeros;
    }
};

int main() {

    int input = 25;

    Solution sol;

    cout << sol.trailingZeroes(input) << endl;

    return 0;
}