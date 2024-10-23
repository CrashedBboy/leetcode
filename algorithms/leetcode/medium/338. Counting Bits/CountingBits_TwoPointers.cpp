#include <iostream>
#include <vector>

using namespace std;

// This uses the hint from the description about using ranges.
// Basically, the numbers in one range are equal to 1 plus all of the numbers in the ranges before it.
// If you write out the binary numbers, you can see that numbers 8-15 have the same pattern as 0-7 but with a 1 at the front.

// My logic was to copy the previous values (starting at 0) until a power of 2 was hit (new range),
// at which point we just reset the t pointer back to 0 to begin the new range.

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp(num + 1);
        dp[0] = 0;

        for (int i = 1, t = 0, e = 2; i <= num; i++, t++) {
            if (i == e) {
                e = e*2;
                t = 0;
            }

            dp[i] = dp[t] + 1; // +1 --> the leading 1
        }

        return dp;
    }
};