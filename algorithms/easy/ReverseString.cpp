#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [idea]: use 2 pointer -> head & tail -> swap


class Solution {
public:
    void reverseString(vector<char>& s) {

        if (s.size() == 0) {
            return;
        }
        
        int head = 0;
        int tail = s.size() - 1;

        while (head <= tail) {
            swap(s[head], s[tail]);
            head += 1;
            tail -= 1;
        }
    }
};


int main () {


    vector<char> inputs = {'A', 'B', 'C', 'D', 'E'};

    Solution s;
    s.reverseString(inputs);

    for (auto& c : inputs) {
        cout << c << ", ";
    }

    return 0;
}