#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0;
        int right = x;

        int mid;
        while (left != right) {
            mid = left + (right-left)/2;

            if (mid*mid <= x) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        return left;
    }
};