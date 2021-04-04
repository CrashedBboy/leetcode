#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if (x == 1 || x == 0) {
            return x;
        }

        int front = 1, back = x;
        int middle;
        while (true) {

            if (front == x/front) {
                return front;
            }
            else if (back == x/back) {
                return back;
            }

            middle = front + (back - front) / 2;

            if (middle >= x/middle) {
                if (middle == back) {
                    break;
                }
                back = middle;
            }
            else {
                if (middle == front) {
                    break;
                }
                front = middle;
            }
        }

        return front;
    }
};

int main() {

    int input = 2147395599;

    Solution sol;

    cout << sol.mySqrt(input) << endl;

    return 0;
}