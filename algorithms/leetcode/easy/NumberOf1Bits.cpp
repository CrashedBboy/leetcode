#include <cstdint>
#include <iostream>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;

        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) {
                count += 1;
            }

            n = n >> 1;
        }

        return count;
    }
};


int main() {

    uint32_t input = 0b11111111111111111111111111111101;

    Solution sol;

    cout << sol.hammingWeight(input) << endl;

    return 0;
}