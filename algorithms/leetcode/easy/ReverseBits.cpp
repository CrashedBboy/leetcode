#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {

            uint32_t bit = (n & 1);

            cout << bit << ",";
            ans += ( bit << (32 - i - 1));

            n = n >> 1;
        }

        return ans;
    }
};

int main () {

    uint32_t input = 0b11111111111111111111111111111101;

    Solution sol;

    cout << sol.reverseBits(input) << endl;

    return 0;
}